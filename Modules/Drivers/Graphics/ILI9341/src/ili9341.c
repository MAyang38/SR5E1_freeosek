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
 * @file    ili9341.c
 * @brief   ILI9341 driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup GRAPHICS
 * @ingroup DRIVERS
 * @addtogroup ILI9341
 * @ingroup GRAPHICS
 * @{
 */

#include <string.h>
#include <stdlib.h>

#include <ili9341.h>

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/** @brief ILI9341 TFT display width */
#define ILI9341_TFTWIDTH   240U
/** @brief ILI9341 TFT display height */
#define ILI9341_TFTHEIGHT  320U

/** @brief Current display width */
static uint16_t _tft_width;
/** @brief Current display height */
static uint16_t _tft_height;
/** @brief Current display orientation */
static uint32_t _tft_orientation;

/** @brief Current display configuration */
static ILI9341Config *_tft_config;

/**
 * @name ILI9342 display control commands
 * @{
 */
/** @brief  NOP */
#define ILI9341_NOP        0x00U
/** @brief  SWRESET */
#define ILI9341_SWRESET    0x01U
/** @brief  RDDID */
#define ILI9341_RDDID      0x04U
/** @brief  RDDS */
#define ILI9341_RDDST      0x09U
/** @brief  SLPIN */
#define ILI9341_SLPIN      0x10U
/** @brief  SLPOUT */
#define ILI9341_SLPOUT     0x11U
/** @brief  PTLON */
#define ILI9341_PTLON      0x12U
/** @brief  NORON */
#define ILI9341_NORON      0x13U
/** @brief  RDMODE */
#define ILI9341_RDMODE     0x0AU
/** @brief  RDMADCTL */
#define ILI9341_RDMADCTL   0x0BU
/** @brief  RDPIXFM */
#define ILI9341_RDPIXFMT   0x0CU
/** @brief  RDIMGFMT */
#define ILI9341_RDIMGFMT   0x0DU
/** @brief  RDSELFDIAG */
#define ILI9341_RDSELFDIAG 0x0FU
/** @brief  INVOFF */
#define ILI9341_INVOFF     0x20U
/** @brief  INVON */
#define ILI9341_INVON      0x21U
/** @brief  GAMMASET */
#define ILI9341_GAMMASET   0x26U
/** @brief  DISPOFF */
#define ILI9341_DISPOFF    0x28U
/** @brief  DISPON */
#define ILI9341_DISPON     0x29U
/** @brief  CASET */
#define ILI9341_CASET      0x2AU
/** @brief  PASET */
#define ILI9341_PASET      0x2BU
/** @brief  RAMWR */
#define ILI9341_RAMWR      0x2CU
/** @brief  RAMRD */
#define ILI9341_RAMRD      0x2EU
/** @brief  PTLAR */
#define ILI9341_PTLAR      0x30U
/** @brief  MADCTL */
#define ILI9341_MADCTL     0x36U
/** @brief  VSCRSADD */
#define ILI9341_VSCRSADD   0x37U
/** @brief  PIXFMT */
#define ILI9341_PIXFMT     0x3AU
/** @brief  FRMCTR1 */
#define ILI9341_FRMCTR1    0xB1U
/** @brief  FRMCTR2 */
#define ILI9341_FRMCTR2    0xB2U
/** @brief  FRMCTR3 */
#define ILI9341_FRMCTR3    0xB3U
/** @brief  INVCTR */
#define ILI9341_INVCTR     0xB4U
/** @brief  DFUNCTR */
#define ILI9341_DFUNCTR    0xB6U
/** @brief  PWCTR1 */
#define ILI9341_PWCTR1     0xC0U
/** @brief  PWCTR2 */
#define ILI9341_PWCTR2     0xC1U
/** @brief  PWCTR3 */
#define ILI9341_PWCTR3     0xC2U
/** @brief  PWCTR4 */
#define ILI9341_PWCTR4     0xC3U
/** @brief  PWCTR5 */
#define ILI9341_PWCTR5     0xC4U
/** @brief  VMCTR1 */
#define ILI9341_VMCTR1     0xC5U
/** @brief  VMCTR2 */
#define ILI9341_VMCTR2     0xC7U
/** @brief  RDID1 */
#define ILI9341_RDID1      0xDAU
/** @brief  RDID2 */
#define ILI9341_RDID2      0xDBU
/** @brief  RDID3 */
#define ILI9341_RDID3      0xDCU
/** @brief  RDID4 */
#define ILI9341_RDID4      0xD3U
/** @brief  GMCTRP1 */
#define ILI9341_GMCTRP1    0xE0U
/** @brief  GMCTRN1 */
#define ILI9341_GMCTRN1    0xE1U
/** @} */


/**
 * @name ILI9342 display orientation control
 * @{
 */
/** @brief Bottom to top */
#define ILI9341_MADCTL_MY  0x80U  /* Bottom to top */
/** @brief Right to left */
#define ILI9341_MADCTL_MX  0x40U  /* Right to left */
/** @brief Reverse Mode */
#define ILI9341_MADCTL_MV  0x20U  /* Reverse Mode */
/** @brief LCD refresh Bottom to top */
#define ILI9341_MADCTL_ML  0x10U  /* LCD refresh Bottom to top */
/** @brief RGB pixel order */
#define ILI9341_MADCTL_RGB 0x00U  /* RGB pixel order */
/** @brief BGR pixel order */
#define ILI9341_MADCTL_BGR 0x08U  /* BGR pixel order */
/** @brief LCD refresh right to left */
#define ILI9341_MADCTL_MH  0x04U  /* LCD refresh right to left */
/** @} */


/* Forward declarations */
static void ili9341_display_spi_send_byte(uint8_t data);
static void ili9341_display_write(uint8_t cmd, uint8_t *data, uint32_t len);
static void ili9341_display_writepattern(uint8_t cmd, uint8_t *data, uint32_t len);
static void ili9341_reset(void);
static void ili9341_setaddress(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
static void ili9341_writecolor(uint16_t color, uint32_t len);

/** @brief Simple no-operation macro */
#define nop()     asm volatile ("nop " : : )

/**
 * @brief Simple delay
 * @details Implemented using a busy loop with NOP
 *
 * @param nops Number of NOP to execute
 *
 * @notapi
 */
static inline void ILIDELAY(uint32_t nops)
{
	uint32_t i = nops;
	do {
		nop();
	} while (i-- > 0U);
}

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @name    Internal Driver DISPLAY SPI PIN Configuration
 * @{
 */
/** @brief [SPI Bit-Bang] Set chip select low */
#define ILI9341_DISPLAY_SPI_CS_LOW()           gpio_clear_pin((uint32_t)_tft_config->dev.pin.cs)
/** @brief [SPI Bit-Bang] Set chip select high */
#define ILI9341_DISPLAY_SPI_CS_HIGH()          gpio_set_pin((uint32_t)_tft_config->dev.pin.cs)
/** @brief [SPI Bit-Bang] Set mosi low */
#define ILI9341_DISPLAY_SPI_MOSI_LOW()         gpio_clear_pin((uint32_t)_tft_config->dev.pin.mosi)
/** @brief [SPI Bit-Bang] Set mosi high */
#define ILI9341_DISPLAY_SPI_MOSI_HIGH()        gpio_set_pin((uint32_t)_tft_config->dev.pin.mosi)
/** @brief [SPI Bit-Bang] Set clock low */
#define ILI9341_DISPLAY_SPI_SCK_LOW()          gpio_clear_pin((uint32_t)_tft_config->dev.pin.sck)
/** @brief [SPI Bit-Bang] Set clock high */
#define ILI9341_DISPLAY_SPI_SCK_HIGH()         gpio_set_pin((uint32_t)_tft_config->dev.pin.sck)
/** @brief [SPI Bit-Bang] Delay */
#define ILI9341_DISPLAY_SPI_DELAY(_x_)
/** @} */

/**
 * @name    DISPLAY PIN Configuration
 * @{
 */
/** @brief Set data command low */
#define ILI9341_DC_LOW()           gpio_clear_pin((uint32_t)_tft_config->dc)
/** @brief Set data command high */
#define ILI9341_DC_HIGH()          gpio_set_pin((uint32_t)_tft_config->dc)
/** @brief Set backlight on */
#define ILI9341_BKL_ON()           gpio_clear_pin((uint32_t)_tft_config->blk)
/** @brief Set backlight off */
#define ILI9341_BKL_OFF()          gpio_set_pin((uint32_t)_tft_config->blk)
/** @brief Set reset low */
#define ILI9341_RESET_LOW()        gpio_clear_pin((uint32_t)_tft_config->reset)
/** @brief Set reset high */
#define ILI9341_RESET_HIGH()       gpio_set_pin((uint32_t)_tft_config->reset)
/** @} */

/** @brief  Char metrics */
typedef struct CharMetrics_s {
  uint8_t       width;     /**< The glyph's horizontal extent. */
  uint8_t       height;    /**< The glyph's vertical extent. */

  int8_t        x_offset;  /**< The horizontal distance from the glyph origin (0,0)
                                to the leftmost pixel of the glyph bitmap. */
  int8_t        y_offset;  /**< The vertical distance from the glyph origin (0,0)
                                to the topmost pixel of the glyph bitmap */

  uint16_t      x_advance; /**< The horizontal distance to increment the pen position
                                after a glyph has been rendered when processing text. */

  uint16_t      y_advance; /**< The vertical distance to increment the pen position
                                to next line. */

  const uint8_t *bitmap;   /**< The glyph bitmap */
} CharMetrics_t;


/**
 * @name  Font rendering helper macros
 * @{
 */

/**
 * @brief Font object start character index
 * @param \_font\_  Font object
 */
#define FONT_START_INDEX(_font_) ((_font_) -> start_char)

/**
 * @brief Font object stop character index
 * @param \_font\_  Font object
 */
#define FONT_STOP_INDEX(_font_) ((_font_) -> stop_char)

/**
 * @brief Font object bitmaps pointer
 * @param \_font\_  Font object
 */
#define FONT_GET_BITMAP(_font_) ((_font_) -> bitmap)

/**
 * @brief Font object Y advance
 * @param \_font\_  Font object
 */
#define FONT_GET_Y_ADVANCE(_font_) ((uint16_t)(((_font_)) -> y_advance))

/**
 * @brief Font object get glyph
 * @param \_font\_   Font object
 * @param \_index\_  Char index
 */
#define FONT_GET_GLYPH(_font_, _index_) (&(((((_font_) -> glyph) [(_index_)]))))

/**
 * @brief Get glyph width
 * @param \_glyph\_  Char glyph
 */
#define GLYPH_GET_WIDTH(_glyph_)  ((_glyph_) -> width)

/**
 * @brief Get glyph height
 * @param \_glyph\_  Char glyph
 */
#define GLYPH_GET_HEIGHT(_glyph_) ((_glyph_) -> height)

/**
 * @brief Get glyph X offset
 * @param \_glyph\_  Char glyph
 */
#define GLYPH_GET_XOFFSET(_glyph_) ((_glyph_) -> x_offset)

/**
 * @brief Get glyph Y offset
 * @param \_glyph\_  Char glyph
 */
#define GLYPH_GET_YOFFSET(_glyph_) ((_glyph_) -> y_offset)

/**
 * @brief Get glyph X advance
 * @param \_glyph\_  Char glyph
 */
#define GLYPH_GET_X_ADVANCE(_glyph_) ((_glyph_) -> x_advance)

/**
 * @brief Get glyph bitmap offset
 * @param \_glyph\_  Char glyph
 */
#define GLYPH_GET_BITMAP_OFFSET(_glyph_) ((_glyph_) -> bitmap_index)
/** @} */


/**
 * @brief   Retrieves font metrics for a specific character
 *
 * @param       font         font to use
 * @param       c            character
 * @param       char_metrics the char metrics
 *
 * @notapi
 */
static void font_get_metrics(const FontObject_t *font, uint8_t c, CharMetrics_t *char_metrics)
{
  uint8_t char_index;
  const FontMetrics_t *fm;

  char_index = c - FONT_START_INDEX(font);

  fm = FONT_GET_GLYPH(font, char_index);

  char_metrics->width = GLYPH_GET_WIDTH(fm);
  char_metrics->height = GLYPH_GET_HEIGHT(fm);
  char_metrics->x_offset = GLYPH_GET_XOFFSET(fm);
  char_metrics->y_offset = GLYPH_GET_YOFFSET(fm);

  char_metrics->x_advance = GLYPH_GET_X_ADVANCE(fm);
  char_metrics->y_advance = FONT_GET_Y_ADVANCE(font);

  char_metrics->bitmap = FONT_GET_BITMAP(font);
  char_metrics->bitmap += GLYPH_GET_BITMAP_OFFSET(fm);
}


/**
 * @brief   Send a byte using Internal SPI driver
 *
 * @param      data   Byte to send
 *
 * @notapi
 */
static void ili9341_display_spi_send_byte(uint8_t data) {
  uint8_t bit_mask;

  for (bit_mask = 0x80; bit_mask != 0U; bit_mask >>= 1) {
    if ((data & bit_mask) != 0U) {
      ILI9341_DISPLAY_SPI_MOSI_HIGH();
    }
    else {
      ILI9341_DISPLAY_SPI_MOSI_LOW();
    }
    ILI9341_DISPLAY_SPI_DELAY(10);
    ILI9341_DISPLAY_SPI_SCK_LOW();
    ILI9341_DISPLAY_SPI_DELAY(10);
    ILI9341_DISPLAY_SPI_SCK_HIGH();
    ILI9341_DISPLAY_SPI_DELAY(10);
  }
}

/**
 * @brief   Write commands to ili9341 lcd
 *
 * @param      cmd   Command to send
 * @param      data  pointer to data buffer to send
 * @param      len   number of bytes to send
 *
 * @notapi
 */
static void ili9341_display_write(uint8_t cmd, uint8_t *data, uint32_t len) {

  if (_tft_config->mode == ILI9341_BITBANG) {
    ILI9341_DISPLAY_SPI_CS_LOW();
    ILI9341_DISPLAY_SPI_DELAY(10);

    if (cmd != 0U) {
      ILI9341_DC_LOW();
      ILI9341_DISPLAY_SPI_DELAY(10);
      ili9341_display_spi_send_byte(cmd);
      ILI9341_DISPLAY_SPI_DELAY(10);
      ILI9341_DC_HIGH();
      ILI9341_DISPLAY_SPI_DELAY(10);
    }
    if (data != NULL) {
      uint32_t i;
      for (i = 0; i < len; i++) {
        ili9341_display_spi_send_byte(data[i]);
      }
    }

    ILI9341_DISPLAY_SPI_DELAY(10);
    ILI9341_DISPLAY_SPI_CS_HIGH();
  } else {
    if (cmd != 0U) {
      ILI9341_DC_LOW();
      spi_send(_tft_config->dev.lld.spid, (uint8_t *)(&cmd), 1UL);
      ILI9341_DC_HIGH();
    }
    if (data != NULL) {
      spi_send(_tft_config->dev.lld.spid, (uint8_t *)data, len);
    }
  }
}

/**
 * @brief   Write patter commands to ili9341 lcd
 *
 * @param      cmd   Command to send
 * @param      data  pointer to data buffer to send
 * @param      len   number of bytes to send
 *
 * @notapi
 */
static void ili9341_display_writepattern(uint8_t cmd, uint8_t *data, uint32_t len) {

  if (_tft_config->mode == ILI9341_BITBANG) {
    ILI9341_DISPLAY_SPI_CS_LOW();
    ILI9341_DISPLAY_SPI_DELAY(10);

    if (cmd != 0U) {
      ILI9341_DC_LOW();

      ili9341_display_spi_send_byte(cmd);
      ILI9341_DISPLAY_SPI_DELAY(10);
      ILI9341_DC_HIGH();
      ILI9341_DISPLAY_SPI_DELAY(10);
    }
    if (data != NULL) {
      uint32_t i;
      for (i = 0; i < len; i++) {
        ili9341_display_spi_send_byte(data[0]);
        ili9341_display_spi_send_byte(data[1]);
      }
    }

    ILI9341_DISPLAY_SPI_DELAY(10);
    ILI9341_DISPLAY_SPI_CS_HIGH();

  } else {
    if (cmd != 0U) {
      ILI9341_DC_LOW();
      spi_send(_tft_config->dev.lld.spid, (uint8_t *)(&cmd), 1UL);
      ILI9341_DC_HIGH();
    }
    if (data != NULL) {
      uint32_t i;
      for (i = 0; i < len; i++) {
        spi_send(_tft_config->dev.lld.spid, (uint8_t *)data, 2UL);
      }
    }
  }
}

/**
 * @brief   Reset ILI9341
 *
 * @notapi
 */
static void ili9341_reset(void) {
  ILI9341_RESET_HIGH();
  ILIDELAY(100);
  ILI9341_RESET_LOW();
  ILIDELAY(100);
  ILI9341_RESET_HIGH();
  ILIDELAY(200);
}

/**
 * @brief   Set LCD Address
 *
 * @param      x,y  start point
 * @param      w    width
 * @param      h    height
 *
 * @notapi
 */
static void ili9341_setaddress(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
  uint8_t data[4];

  uint32_t xa = ((uint32_t)x << 16) | ((uint32_t)x + (uint32_t)w - 1U);
  uint32_t ya = ((uint32_t)y << 16) | ((uint32_t)y + (uint32_t)h - 1U);

  data[3] = (uint8_t)((xa) & 0xFFU);
  data[2] = (uint8_t)((xa >> 8) & 0xFFU);
  data[1] = (uint8_t)((xa >> 16) & 0xFFU);
  data[0] = (uint8_t)((xa >> 24) & 0xFFU);
  ili9341_display_write(ILI9341_CASET, data, 4); // Column address set

  data[3] = (uint8_t)((ya) & 0xFFU);
  data[2] = (uint8_t)((ya >> 8) & 0xFFU);
  data[1] = (uint8_t)((ya >> 16) & 0xFFU);
  data[0] = (uint8_t)((ya >> 24) & 0xFFU);
  ili9341_display_write(ILI9341_PASET, data, 4); // Raw address set

  ili9341_display_write(ILI9341_RAMWR, NULL, 0);

}

/**
 * @brief   Write Color pattern on all display startin from 0,0
 *
 * @param      color  RGB565 color
 * @param      len    number of consecutive pixel to be colored
 *
 * @notapi
 */
static void ili9341_writecolor(uint16_t color, uint32_t len) {
  uint8_t hi = (uint8_t)((color >> 8) & 0xFFU);
  uint8_t lo = (uint8_t)((color) & 0xFFU);
  uint32_t i;

  for (i = len; i != 0U; i--) {
    ili9341_display_write(0, &hi, 1);
    ili9341_display_write(0, &lo, 1);
  }
}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

void ili9341_init(void) {
}


void ili9341_start(ILI9341Config *config) {
  uint8_t data[16];

  /* Save current configuration */
  _tft_config = config;

  /* reset Display */
  if (gpio_read_pin(_tft_config->reset) == GPIO_ODR_LOW) {
    ili9341_reset();
  }

  if (_tft_config->mode == ILI9341_SPI_LLD) {
    spi_start(_tft_config->dev.lld.spid);
  }

  /* Init sequence */
  data[0] = 0x03;
  data[1] = 0x80;
  data[2] = 0x02;
  ili9341_display_write(0xEF, data, 3);

  data[0] = 0x00;
  data[1] = 0xC1;
  data[2] = 0x30;
  ili9341_display_write(0xCF, data, 3);

  data[0] = 0x64;
  data[1] = 0x03;
  data[2] = 0x12;
  data[3] = 0x81;
  ili9341_display_write(0xED, data, 4);

  data[0] = 0x85;
  data[1] = 0x00;
  data[2] = 0x78;
  ili9341_display_write(0xE8, data, 3);

  data[0] = 0x39;
  data[1] = 0x2C;
  data[2] = 0x00;
  data[3] = 0x34;
  data[4] = 0x02;
  ili9341_display_write(0xCB, data, 5);

  data[0] = 0x20;
  ili9341_display_write(0xF7, data, 1);

  data[0] = 0x00;
  data[1] = 0x00;
  ili9341_display_write(0xEA, data, 2);

  /* Power Control */
  data[0] = 0x23; // VRH[5:0]
  ili9341_display_write(ILI9341_PWCTR1, data, 1);

  /* Power Control */
  data[0] = 0x10; // SAP[2:0]; BT[3:0]
  ili9341_display_write(ILI9341_PWCTR2, data, 1);

  /* VCM Control */
  data[0] = 0x3E;
  data[1] = 0x28;
  ili9341_display_write(ILI9341_VMCTR1, data, 2);

  /* VCM Control  2*/
  data[0] = 0x86;
  ili9341_display_write(ILI9341_VMCTR2, data, 1);

  /* Memory Access Control */
  data[0] = 0x48;
  ili9341_display_write(ILI9341_MADCTL, data, 1);

  /* Vertical scroll  */
  data[0] = 0x00;
  data[1] = 0x00;
  ili9341_display_write(ILI9341_VSCRSADD, data, 2);

  /* Pixel Format */
  data[0] = 0x55;
  ili9341_display_write(ILI9341_PIXFMT, data, 1);

  data[0] = 0x00;
  data[1] = 0x18;
  ili9341_display_write(ILI9341_FRMCTR1, data, 2);

  /* Display Function Control */
  data[0] = 0x08;
  data[1] = 0x82;
  data[2] = 0x27;
  ili9341_display_write(ILI9341_DFUNCTR, data, 3);

  /* Gamma Function Disable */
  data[0] = 0x00;
  ili9341_display_write(0xF2, data, 1);

  /* Gamma curve selected */
  data[0] = 0x01;
  ili9341_display_write(ILI9341_GAMMASET, data, 1);

  /* Set Gamma */
  data[0] = 0x0F;
  data[1] = 0x31;
  data[2] = 0x2B;
  data[3] = 0x0C;
  data[4] = 0x0E;
  data[5] = 0x08;
  data[6] = 0x4E;
  data[7] = 0xF1;
  data[8] = 0x37;
  data[9] = 0x07;
  data[10] = 0x10;
  data[11] = 0x03;
  data[12] = 0x0E;
  data[13] = 0x09;
  data[14] = 0x00;
  ili9341_display_write(ILI9341_GMCTRP1, data, 15);

  /* Set Gamma */
  data[0] = 0x00;
  data[1] = 0x0E;
  data[2] = 0x14;
  data[3] = 0x03;
  data[4] = 0x11;
  data[5] = 0x07;
  data[6] = 0x31;
  data[7] = 0xC1;
  data[8] = 0x48;
  data[9] = 0x08;
  data[10] = 0x0F;
  data[11] = 0x0C;
  data[12] = 0x31;
  data[13] = 0x36;
  data[14] = 0x0F;
  ili9341_display_write(ILI9341_GMCTRN1, data, 15);

  data[0] = 0x00;
  data[1] = 0x10;
  ili9341_display_write(0xB1, data, 2);

  /* Exit Sleep */
  ili9341_display_write(ILI9341_SLPOUT, NULL, 0);
  ILIDELAY(120);

  /* Display on */
  ili9341_display_write(ILI9341_DISPON, NULL, 0);
  ILIDELAY(200);

  /* Set screen size (and orientation) */
  _tft_width = ILI9341_TFTWIDTH;
  _tft_height = ILI9341_TFTHEIGHT;
  _tft_orientation = ILI9341_PORTRAIT;

  ILI9341_BKL_ON();
}


void ili9341_stop(void) {
  ILI9341_BKL_OFF();

  /* Reset Display */
  ili9341_reset();

  if (_tft_config->mode == ILI9341_SPI_LLD) {
    spi_stop(_tft_config->dev.lld.spid);
  }

  /* Reset configuration */
  _tft_config = NULL;
}


uint16_t ili9341_getScreenWidth(void) {
  if ((_tft_orientation == ILI9341_PORTRAIT) || (_tft_orientation == ILI9341_ROTATE_PORTRAIT)) {
    return (uint16_t)(ILI9341_TFTWIDTH);
  } else {
    return (uint16_t)(ILI9341_TFTHEIGHT);
  }
}


uint16_t ili9341_getScreenHeight(void) {
  if ((_tft_orientation == ILI9341_PORTRAIT) || (_tft_orientation == ILI9341_ROTATE_PORTRAIT)) {
    return (uint16_t)(ILI9341_TFTHEIGHT);
  } else {
    return (uint16_t)(ILI9341_TFTWIDTH);
  }
}


void ili9341_setOrientation(uint32_t orientation) {
  uint8_t value;

  switch (orientation) {
  case ILI9341_PORTRAIT:
    value = (uint8_t)(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
    _tft_width = ILI9341_TFTWIDTH;
    _tft_height = ILI9341_TFTHEIGHT;
    break;

  case ILI9341_LANDSCAPE:
    value = (uint8_t)(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
    _tft_width  = ILI9341_TFTHEIGHT;
    _tft_height = ILI9341_TFTWIDTH;
    break;

  case ILI9341_ROTATE_PORTRAIT:
    value = (uint8_t)(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
    _tft_width  = ILI9341_TFTWIDTH;
    _tft_height = ILI9341_TFTHEIGHT;
    break;

  case ILI9341_ROTATE_LANDSCAPE:
    value = (uint8_t)(ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
    _tft_width  = ILI9341_TFTHEIGHT;
    _tft_height = ILI9341_TFTWIDTH;
    break;

  default:
    /* Just here for Misra */
    break;
  }
  _tft_orientation = orientation;
  ili9341_display_write(ILI9341_MADCTL, &value, 1);
}


uint32_t ili9341_getOrientation(void) {
  return _tft_orientation;
}


void ili9341_clearScreen(uint16_t color) {
  ili9341_setaddress(0, 0, _tft_width, _tft_height);
  ili9341_writecolor(color, (((uint32_t)_tft_width) * ((uint32_t)_tft_height)));
}


void ili9341_cropScreen(uint16_t w, uint16_t h) {

  if ((_tft_orientation == ILI9341_PORTRAIT) || (_tft_orientation == ILI9341_ROTATE_PORTRAIT)) {
    if (w > ILI9341_TFTWIDTH) {
    	w = ILI9341_TFTWIDTH;
    }
    if (h > ILI9341_TFTHEIGHT) {
      h = ILI9341_TFTHEIGHT;
    }
  } else {
    if (w > ILI9341_TFTHEIGHT) {
    	w = ILI9341_TFTHEIGHT;
    }
    if (h > ILI9341_TFTWIDTH) {
      h = ILI9341_TFTWIDTH;
    }
  }

  _tft_width = w;
  _tft_height = h;
}


void ili9341_writeHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
  uint8_t data[2];

  if ((x >= (int16_t)(_tft_width)) || (y >= (int16_t)(_tft_height)) || (y < 0)) {
    return;
  }

  if (x < 0) {
    w += x;
    x = 0;
  }

  if ((x + w) > (int16_t)(_tft_width)) {
    w = (int16_t)(_tft_width) - x;
  }

  ili9341_setaddress((uint16_t)x, (uint16_t)y, (uint16_t)w, 1);

  data[0] = (uint8_t)((color >> 8) & 0xFFU);
  data[1] = (uint8_t)((color) & 0xFFU);
  ili9341_display_writepattern(0, data, (uint16_t)w);
}


void ili9341_writeVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
  uint8_t data[2];

  if ((x >= (int16_t)(_tft_width)) || (y >= (int16_t)(_tft_height)) || (x < 0)) {
    return;
  }

  if (y < 0) {
    h += y;
    y = 0;
  }

  if ((y + h) > (int16_t)(_tft_height)) {
    h = (int16_t)(_tft_height) - y;
  }

  ili9341_setaddress((uint16_t)x, (uint16_t)y, 1, (uint16_t)h);

  data[0] = (uint8_t)((color >> 8) & 0xFFU);
  data[1] = (uint8_t)((color) & 0xFFU);
  ili9341_display_writepattern(0, data, (uint16_t)h);
}

/**
 * @brief   Write a Line
 *
 * @param      x1,y1 start coordinates
 * @param      x2,y2 start coordinates
 * @param      color RGB565 color
 *
 * @notapi
 */
static void ili9341_writeLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
  int16_t x, y, d, s, q, a, b, k;
  int16_t dx, dy;
  int8_t swap;

  swap = 0;

  dx = x2 - x1;
  dy = y2 - y1;

  a = (int16_t)abs(dx);
  b = (int16_t)abs(dy);

  if (a < b) {
    SWAP_VARS(int16_t, dx, dy);
    swap = 1;
  }

  a = (int16_t)abs(dy);
  b = (int16_t)-abs(dx);

  x = x1;
  y = y1;

  d = (int16_t)((2 * a) + b);

  q = 1;
  s = 1;

  if (x1 > x2) {
    q = -1;
  }

  if (y1 > y2) {
    s = -1;
  }

  ili9341_drawPixel(x, y, color);
  ili9341_drawPixel(x2, y2, color);

  for (k = 0; k < -b; k++) {
    if (d > 0) {
      x = x + q;
      y = y + s;
      d += (int16_t)(2 * (a + b));
    } else {
      x = x + q;
      if (swap != 0) {
        y = y + s;
        x = x - q;
      }
      d += (int16_t)(2 * a);
    }
    ili9341_drawPixel(x, y, color);
  }
}


void ili9341_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
  if (x0 == x1) {
    if (y0 > y1) {
      SWAP_VARS(int16_t, y0, y1);
    }
    ili9341_writeVLine(x0, y0, (y1 - y0) + 1, color);
  } else if (y0 == y1) {
    if (x0 > x1) {
      SWAP_VARS(int16_t, x0, x1);
    }
    ili9341_writeHLine(x0, y0, (x1 - x0) + 1, color);
  } else {
    ili9341_writeLine(x0, y0, x1, y1, color);
  }
}


void ili9341_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  ili9341_writeHLine(x, y, w, color);
  ili9341_writeVLine(x + w, y, h, color);
  ili9341_writeVLine(x, y, h, color);
  ili9341_writeHLine(x, y + h, w, color);
}


void ili9341_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  int16_t i;
  for (i = x; i < (x + w); i++) {
    ili9341_writeVLine(i, y, h, color);
  }
}


void ili9341_drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
  int16_t x = r - 1;
  int16_t y = 0;
  int16_t dx = 1;
  int16_t dy = 1;
  int16_t err = (int16_t)(dx - (r * 2));

  if (r <= 0) {
    return;
  }

  while (x >= y) {
    ili9341_drawPixel(x0 + x, y0 + y, color);
    ili9341_drawPixel(x0 + y, y0 + x, color);
    ili9341_drawPixel(x0 - y, y0 + x, color);
    ili9341_drawPixel(x0 - x, y0 + y, color);
    ili9341_drawPixel(x0 - x, y0 - y, color);
    ili9341_drawPixel(x0 - y, y0 - x, color);
    ili9341_drawPixel(x0 + y, y0 - x, color);
    ili9341_drawPixel(x0 + x, y0 - y, color);

    if (err <= 0) {
      y++;
      err += dy;
      dy += 2;
    }

    if (err > 0) {
      x--;
      dx += 2;
      err += (int16_t)((-r * 2) + dx);
    }
  }
}


void ili9341_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
  int16_t x = r - 1;
  int16_t y = 0;
  int16_t dx = 1;
  int16_t dy = 1;
  int16_t err = (int16_t)(dx - (r * 2));

  if (r <= 0) {
    return;
  }

  while (x > 0) {
    ili9341_writeHLine(x0 - x, y0 + y, (int16_t)(x * 2), color);
    ili9341_writeHLine(x0 - x, y0 - y, (int16_t)(x * 2), color);

    if (err <= 0) {
      y++;
      err += dy;
      dy += 2;
    }

    if (err > 0) {
      x--;
      dx += 2;
      err += (int16_t)((-r * 2) + dx);
    }
  }

  ili9341_writeHLine(x0 - x, y0 + y, 1, color);
  ili9341_writeHLine(x0 - x, y0 - y, 1, color);
}


void ili9341_drawPixel(int16_t x, int16_t y, uint16_t color) {
  uint8_t data[2];

  if ((x < 0) || (x >= (int16_t)(_tft_width)) || (y < 0) || (y >= (int16_t)(_tft_height))) {
    return;
  }

  ili9341_setaddress((uint16_t)x, (uint16_t)y, 1, 1);
  data[0] = (uint8_t)((color >> 8) & 0xFFU);
  data[1] = (uint8_t)((color) & 0xFFU);
  ili9341_display_write(0, data, 2);
}


void ili9341_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
  ili9341_writeLine(x0, y0, x1, y1, color);
  ili9341_writeLine(x1, y1, x2, y2, color);
  ili9341_writeLine(x2, y2, x0, y0, color);
}


void ili9341_drawImage(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *image, uint8_t pixfmt) {
  int16_t width, height;
  int16_t offset_x, offset_y;

  /* Only RGB565 is currently supported */
  if ((x >= (int16_t)(_tft_width)) || (y >= (int16_t)(_tft_height)) || (w <= 0) || (h <= 0) || (image == NULL)
      || (pixfmt != PIXFMT_RGB_565)) {
    return;
  }

  width = w;
  height = h;
  offset_x = 0;
  offset_y = 0;

  if (x < 0) {
    width += x;
    offset_x = -x;
    x = 0;
  }

  if ((x + w) > (int16_t)(_tft_width)) {
    width = (int16_t)(_tft_width) - x;
  }

  if (y < 0) {
    height += y;
    offset_y = -y;
    y = 0;
  }

  if ((y + h) > (int16_t)(_tft_height)) {
    height = (int16_t)(_tft_height) - y;
  }

  /* image rendering */
  {
    uint16_t xx, yy;

    for (yy = 0; yy < (uint16_t)height; yy++) {
      for (xx = 0; xx < (uint16_t)width; xx++) {

        uint32_t i;
        uint16_t pixel;
        uint8_t a, b;
        uint16_t row;
        uint16_t col;
        uint16_t ww;


        row = ((uint16_t)offset_y + yy);
        col = ((uint16_t)offset_x + xx);
        ww = (uint16_t)w;
        i = 2U * (((uint32_t)row * (uint32_t)ww) + col);

        a = image[i];
        b = image[i + 1U];
        pixel = b;
        pixel <<= 8U;
        pixel |= a;

        ili9341_drawPixel(x + (int16_t)xx, y + (int16_t)yy, pixel);
      }
    }
  }
}


uint8_t ili9341_drawChar(int16_t x, int16_t y, uint8_t c,  uint16_t color, const FontObject_t *font)
{
  CharMetrics_t char_metrics;
  const uint8_t *bitmap;
  uint8_t  row, col;
  uint8_t  pixels, count;

  /* Get char metrics from font family */
  font_get_metrics(font, c, &char_metrics);
  bitmap = char_metrics.bitmap;

  /* load pixels */
  pixels = *bitmap++;

  /* counts the number of pixels to be drawn */
  count = 0;

  for(col = 0; col < char_metrics.height; col++) {
    for(row = 0; row < char_metrics.width; row++) {
    
      if ((pixels & 0x80U) != 0U) {
        ili9341_drawPixel((int16_t)(x + (int16_t)char_metrics.x_offset + (int16_t)row), (int16_t)(y + (int16_t)char_metrics.y_offset + (int16_t)col), color);
      }
      if ((++count & 0x07U) != 0U) {
        /* move to the next pixel */
        pixels <<= 1;
      } else {
        /* load next pixels */
        pixels = *bitmap++;
      }
    }
  }

  return (uint8_t)char_metrics.x_advance;
}


uint8_t ili9341_drawString(int16_t x, int16_t y, const char *s,  uint16_t color, const FontObject_t *font)
{
  int16_t x0, y0;

  x0 = x;
  y0 = y;

  while (*s != '\0') {
    uint8_t c = (uint8_t)(*s++);
    if (c == (uint8_t)('\n')) {
      y0 += (int16_t)FONT_GET_Y_ADVANCE(font);
    } else if (c == (uint8_t)('\r')) {
      x0 = x;
    } else if ((c >= FONT_START_INDEX(font)) && (c <= FONT_STOP_INDEX(font))) {
      x0 += (int16_t)ili9341_drawChar(x0, y0, c,  color, font);
    } else {
      /* Just here for Misra */
    }
  }

  return (uint8_t)x0;
}


uint8_t ili9341_fontGetYAdvance(const FontObject_t *font)
{
  return (uint8_t)FONT_GET_Y_ADVANCE(font);
}

/** @} */
