/****************************************************************************
 *
 * Copyright (c) 2022 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    ili9341.h
 * @brief   ILI9341 driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup GRAPHICS
 * @ingroup DRIVERS
 * @addtogroup ILI9341
 * @ingroup GRAPHICS
 * @{
 */

#ifndef _ILI9341_H_
#define _ILI9341_H_

#include <spi.h>
#include <gpio.h>

#include <ili9341_font.h>

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ILI9341 orientation
 * @{
 */
/** @brief Portrait */
#define ILI9341_PORTRAIT            0U
/** @brief Landscape */
#define ILI9341_LANDSCAPE           1U
/** @brief Rotate portrait */
#define ILI9341_ROTATE_PORTRAIT     2U
/** @brief Rotate landscape */
#define ILI9341_ROTATE_LANDSCAPE    3U
/** @} */


/**
 * @brief    Packs pixel in RGB665
 * @api
 * @details Packs a pixel from component colors
 *
 * @param  \_r\_   red
 * @param  \_g\_   green
 * @param  \_b\_   blue
 */
#define ILI9341_RGB565(_r_, _g_, _b_) \
  (uint16_t)((((_r_) & 0xF8U) << 8U) | (((_g_) & 0xFCU) << 3U) | ((_b_) >> 3U))


/**
 * @name    ILI9341 colors definitions (RGB565)
 * @{
 */
/** @brief Black */
#define ILI9341_COLOR_BLACK   0x00U
/** @brief Red */
#define ILI9341_COLOR_RED     ILI9341_RGB565(0xFFU, 0x00U, 0x00U)
/** @brief Green */
#define ILI9341_COLOR_GREEN   ILI9341_RGB565(0x00U, 0xFFU, 0x00U)
/** @brief Blue */
#define ILI9341_COLOR_BLUE    ILI9341_RGB565(0x00U, 0x00U, 0xFFU)
/** @brief Yellow */
#define ILI9341_COLOR_YELLOW  ILI9341_RGB565(0xFFU, 0xFFU, 0x00U)
/** @brief Cyan */
#define ILI9341_COLOR_CYAN    ILI9341_RGB565(0x00U, 0xFFU, 0xFFU)
/** @brief Magenta */
#define ILI9341_COLOR_MAGENTA ILI9341_RGB565(0xFFU, 0x00U, 0xFFU)
/** @brief White */
#define ILI9341_COLOR_WHITE   ILI9341_RGB565(0xFFU, 0xFFU, 0xFFU)
/** @} */

/**
 * @name    Pixel formats
 * @{
 */
/** @brief RGB565 */
#define PIXFMT_RGB_565     0U
/** @brief RGB888 */
#define PIXFMT_RGB_888     1U
/** @brief ARGB8888 */
#define PIXFMT_ARGB_8888   2U
/** @} */

/**
 * @brief    Swap pixels
 * @notapi
 * @details Swaps two pixels
 * @param  \_type\_   pixel type
 * @param  \_a\_      first pixel
 * @param  \_b\_      second pixel
 */
#define SWAP_VARS(_type_, _a_, _b_) \
    { \
        _type_ _t_; \
        _t_ = _a_; \
        _a_ = _b_; \
        _b_ = _t_; \
    }

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/
/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @enum ili9341_mode_t
 * ILI9341 low level access mode type.
 */
typedef enum {
  ILI9341_BITBANG = 0,  /**< Bit-bang access */
  ILI9341_SPI_LLD = 1   /**< Hardware SPI */
} ili9341_mode_t;

/** @brief ILI9341 configuration. */
typedef struct {

  ili9341_mode_t mode;  /**< Low level access mode. */

  /** @brief   Low level access device. */
  union {
    /** @brief   Hardware SPI device. */
    struct {
      spi_driver_t *spid;  /**< SPI driver instance */
    } lld;
    /** @brief   Software SPI device. */
    struct {
      gpio_io_t    cs;     /**< Chip Select pin */
      gpio_io_t    sck;    /**< Clock pin */
      gpio_io_t    miso;   /**< Master In Slave Out pin */
      gpio_io_t    mosi;   /**< Master Out Slave In pin */
    } pin;
  } dev;
  gpio_io_t        dc;     /**< Data/Command pin */
  gpio_io_t        blk;    /**< Back-light pin */
  gpio_io_t        reset;  /**< Reset pin */
} ILI9341Config;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/
/*===========================================================================*/
/* Exported functions                                                        */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Draw an Horizontal Line
 * @api
 * @par Description
 * @details Draw an Horizontal Line.
 *
 * @param      x,y   top left coordinates
 * @param      w     line width
 * @param      color RGB565 color
 *
 */
void ili9341_writeHLine(int16_t x, int16_t y, int16_t w, uint16_t color);

/**
 * @brief    Draws horizontal line
 * @api
 * @par Description
 * @details Draws horizontal line
 *
 * @param  \_x\_       x coordinate
 * @param  \_y\_       y coordinate
 * @param  \_w\_       line width (in pixels)
 * @param  \_color\_   line color
 */
#define ili9341_drawHLine(_x_, _y_, _w_, _color_) ili9341_writeHLine((_x_), (_y_), (_w_), (_color_))

/**
 * @brief   Draw a Vertical Line
 * @api
 * @par Description
 * @details Draws vertical line
 *
 * @param      x,y   top left coordinates
 * @param      h     line length
 * @param      color RGB565 color
 *
 */
void ili9341_writeVLine(int16_t x, int16_t y, int16_t h, uint16_t color);

/**
 * @brief    Draws vertical line
 * @api
 * @par Description
 * @details Draws vertical line
 *
 * @param  \_x\_       x coordinate
 * @param  \_y\_       y coordinate
 * @param  \_h\_       line height (in pixels)
 * @param  \_color\_   line color
 *
 */
#define ili9341_drawVLine(_x_, _y_, _h_, _color_) ili9341_writeVLine((_x_), (_y_), (_h_), (_color_))

/**
 * @brief   Draw a Line
 * @api
 * @par Description
 * @details Draws a line
 *
 * @param      x0,y0 start coordinates
 * @param      x1,y1 start coordinates
 * @param      color RGB565 color
 *
 */
void ili9341_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);

/**
 * @brief   Draw a Rectangle
 * @api
 * @par Description
 * @details Draws a rectangle
 *
 * @param      x,y   top left coordinates
 * @param      h,w   rectangle dimension
 * @param      color RGB565 color
 *
 */
void ili9341_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

/**
 * @brief   Draw a filled Rectangle
 * @api
 * @par Description
 * @details Draws a filled rectangle
 *
 * @param      x,y   top left coordinates
 * @param      h,w   rectangle dimension
 * @param      color RGB color
 *
 */
void ili9341_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

/**
 * @brief   Draw a Circle
 * @api
 * @par Description
 * @details Draws a circle
 *
 * @param      x0,y0  Center Coordinates
 * @param      r      Radius
 * @param      color  Color
 *
 */
void ili9341_drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

/**
 * @brief   Fill a Cricle
 * @api
 * @par Description
 * @details Fills a circle
 *
 * @param      x0,y0  Center Coordinates
 * @param      r      Radius
 * @param      color  Fill Color
 *
 */
void ili9341_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

/**
 * @brief   Draw a Pixel
 * @api
 * @par Description
 * @details Draws a pixel
 *
 * @param      x     LCD x-axys
 * @param      y     LCD y-axys
 * @param      color RGB565 color
 *
 */
void ili9341_drawPixel(int16_t x, int16_t y, uint16_t color);

/**
 * @brief   Draw a Triangle
 * @api
 * @par Description
 * @details Draws a triangle
 *
 * @param      x0,y0   vertex A
 * @param      x1,y1   vertex B
 * @param      x2,y2   vertex C
 * @param      color   drawing color
 *
 */
void ili9341_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);

/**
 * @brief   Draw an Image
 * @api
 * @par Description
 * @details Draws an image
 *
 * @param      x,y   top left coordinates
 * @param      h,w   dimension
 * @param      image image bitmap
 * @param      pixfmt pixel format
 *
 */
void ili9341_drawImage(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *image, uint8_t pixfmt);

/**
 * @brief   Draw a Character
 * @api
 * @par Description
 * @details Draws a character
 *
 * @param      x,y   top left coordinates
 * @param      c     character to write
 * @param      color RGB color
 * @param      font  font to use
 *
 * @return next advance
 *
 */
uint8_t ili9341_drawChar(int16_t x, int16_t y, uint8_t c,  uint16_t color, const FontObject_t *font);

/**
 * @brief   Draw a string
 * @api
 * @par Description
 * @details Draws a string
 *
 * @param      x,y   top left coordinates
 * @param      s     string to print
 * @param      color RGB565 color
 * @param      font  font to use
 *
 * @return    Char horizontal advance
 *
 */
uint8_t ili9341_drawString(int16_t x, int16_t y, const char *s,  uint16_t color, const FontObject_t *font);

/**
 * @brief   Get font vertical advance
 * @api
 * @par Description
 * @details Draws a string
 *
 * @param      font  font to get advance for
 *
 * @return    font vertical advance
 *
 */
uint8_t ili9341_fontGetYAdvance(const FontObject_t *font);

/**
 * @brief   ILI9341 initialization.
 * @init
 * @par Description
 * @details Initializes the ILI9341 display
 *
 */
void ili9341_init(void);

/**
 * @brief   ILI9341 start-up.
 * @api
 * @par Description
 * @details Starts the ILI9341 driver.
 *
 * @param config Display configuration \p ILI9341Config object
 *
 */
void ili9341_start(ILI9341Config *config);

/**
 * @brief   ILI9341 stop.
 * @api
 * @par Description
 * @details Stops the ILI9341 driver.
 *
 */
void ili9341_stop(void);

/**
 * @brief   Get Screen width
 * @api
 * @par Description
 * @details Gets screen width.
 *
 * @return display width
 *
 */
uint16_t ili9341_getScreenWidth(void);

/**
 * @brief   Get Screen height
 * @api
 * @par Description
 * @details Gets screen height.
 *
 * @return display height
 *
 */
uint16_t ili9341_getScreenHeight(void);

/**
 * @brief   Set Screen orientation
 * @api
 * @par Description
 * @details Sets screen orientation.
 *
 * @param      orientation   screen orientation
 *
 */
void ili9341_setOrientation(uint32_t orientation);

/**
 * @brief   Get Screen orientation
 * @api
 * @par Description
 * @details Gets screen orientation.
 *
 * @return display orientation
 *
 */
uint32_t ili9341_getOrientation(void);

/**
 * @brief   Clear the Screen
 * @api
 * @par Description
 * @details Clears the screen.
 *
 * @param      color   color for new screen
 *
 */
void ili9341_clearScreen(uint16_t color);

/**
 * @brief   Crop the Screen
 * @api
 * @par Description
 * @details Crops the screen.
 *
 * @param      w,h   active screen width and height
 *
 */
void ili9341_cropScreen(uint16_t w, uint16_t h);

#ifdef __cplusplus
}
#endif

#endif /* _ILI9341_H_ */

/** @} */
