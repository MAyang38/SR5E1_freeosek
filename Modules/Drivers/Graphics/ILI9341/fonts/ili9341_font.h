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
 * @file    ili9341_font.h
 * @brief   ILI9341 driver font header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup GRAPHICS
 * @ingroup DRIVERS
 * @addtogroup ILI9341
 * @ingroup GRAPHICS
 * @{
 */

#ifndef _ILI9341_FONT_H
#define _ILI9341_FONT_H

#include <typedefs.h>

/**
 * @brief Font Metrics structure
 * @details
 * Font metrics are certain distances associated with each glyph
 * that describe how to position this glyph while creating a text layout.
 */
typedef struct FontMetrics_s {
    uint8_t  width;     /**< The glyph's horizontal extent. */
    uint8_t  height;    /**< The glyph's vertical extent. */

    int8_t   x_offset;  /**< The horizontal distance from the glyph origin (0,0)
                           to the leftmost pixel of the glyph bitmap. */
    int8_t   y_offset;  /**< The vertical distance from the glyph origin (0,0)
                           to the topmost pixel of the glyph bitmap */

    uint16_t x_advance; /**< The horizontal distance to increment the pen position
                           after a glyph has been rendered when processing text. */

    uint16_t bitmap_index; /**< Index of the bitmap descriptor for the glyph object */
} FontMetrics_t;


/**
 * @brief Font Object structure
 * @details
 * Font object describes a complete set of fonts.
 */
typedef struct FontObject_s {
    uint8_t               start_char;  /**< Font chars start range */
    uint8_t               stop_char;   /**< Font chars stop range */
    uint16_t              y_advance;   /**< Vertical distance (in pixel) for new line */

    const FontMetrics_t  *glyph;       /**< The font glyph metrics */
    const uint8_t        *bitmap;      /**< The font bitmaps */
} FontObject_t;


#ifdef __cplusplus
extern "C" {
#endif

/** @brief Font DejaVuSansMono (8 pixel) */
extern const FontObject_t DejaVuSansMono_8pt_7b;
/** @brief Font DejaVuSansMono (10) */
extern const FontObject_t DejaVuSansMono_10pt_7b;
/** @brief Font DejaVuSansMono (12) */
extern const FontObject_t DejaVuSansMono_12pt_7b;
/** @brief Font DejaVuSansMono (14) */
extern const FontObject_t DejaVuSansMono_14pt_7b;
/** @brief Font DejaVuSansMono (16) */
extern const FontObject_t DejaVuSansMono_16pt_7b;
/** @brief Font DejaVuSansMono (20) */
extern const FontObject_t DejaVuSansMono_20pt_7b;
/** @brief Font DejaVuSansMono (24) */
extern const FontObject_t DejaVuSansMono_24pt_7b;

#ifdef __cplusplus
}
#endif

#endif /* _ILI9341_FONT_H */

/** @} */
