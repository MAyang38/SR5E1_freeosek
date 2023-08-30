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
 * @file    dma.c
 * @brief   DMA driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup DMA
 * @ingroup SYSTEM
 * @{
 */

#include "dma.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

#define DMA_SCR_RESET_VALUE             0x00000000U

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/**
 * @brief   DMA stream descriptors.
 */
static const dma_descriptor_t dma_descriptors[DMA_NUM_STREAMS] = {
    {0U,  DMAMUX1_Channel0,  DMA1, DMA1_Stream0, 0U,  IRQ_DMA1_ST0_VECTOR},
    {1U,  DMAMUX1_Channel1,  DMA1, DMA1_Stream1, 6U,  IRQ_DMA1_ST1_VECTOR},
    {2U,  DMAMUX1_Channel2,  DMA1, DMA1_Stream2, 16U, IRQ_DMA1_ST2_VECTOR},
    {3U,  DMAMUX1_Channel3,  DMA1, DMA1_Stream3, 22U, IRQ_DMA1_ST3_VECTOR},
    {4U,  DMAMUX1_Channel4,  DMA1, DMA1_Stream4, 0U,  IRQ_DMA1_ST4_VECTOR},
    {5U,  DMAMUX1_Channel5,  DMA1, DMA1_Stream5, 6U,  IRQ_DMA1_ST5_VECTOR},
    {6U,  DMAMUX1_Channel6,  DMA1, DMA1_Stream6, 16U, IRQ_DMA1_ST6_VECTOR},
    {7U,  DMAMUX1_Channel7,  DMA1, DMA1_Stream7, 22U, IRQ_DMA1_ST7_VECTOR},
    {8U,  DMAMUX1_Channel8,  DMA2, DMA2_Stream0, 0U,  IRQ_DMA2_ST0_VECTOR},
    {9U,  DMAMUX1_Channel9,  DMA2, DMA2_Stream1, 6U,  IRQ_DMA2_ST1_VECTOR},
    {10U, DMAMUX1_Channel10, DMA2, DMA2_Stream2, 16U, IRQ_DMA2_ST2_VECTOR},
    {11U, DMAMUX1_Channel11, DMA2, DMA2_Stream3, 22U, IRQ_DMA2_ST3_VECTOR},
    {12U, DMAMUX1_Channel12, DMA2, DMA2_Stream4, 0U,  IRQ_DMA2_ST4_VECTOR},
    {13U, DMAMUX1_Channel13, DMA2, DMA2_Stream5, 6U,  IRQ_DMA2_ST5_VECTOR},
    {14U, DMAMUX1_Channel14, DMA2, DMA2_Stream6, 16U, IRQ_DMA2_ST6_VECTOR},
    {15U, DMAMUX1_Channel15, DMA2, DMA2_Stream7, 22U, IRQ_DMA2_ST7_VECTOR}
};

/**
 * @brief   Local DMA data instance.
 */
static struct {
    /**
     * @brief   Mask of taken streams.
     */
    uint32_t      taken;
    /**
     * @brief   Callbacks table.
     */
    struct {
        /**
         * @brief   DMA callback function.
         */
        dma_callback_t    cb;
        /**
         * @brief   DMA callback parameter.
         */
        void              *arg;
    } streams[DMA_NUM_STREAMS];
} dma;

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

IRQ_HANDLER(IRQ_DMA1_ST0_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST1_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST2_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST3_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST4_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST5_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST6_HANDLER);
IRQ_HANDLER(IRQ_DMA1_ST7_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST0_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST1_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST2_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST3_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST4_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST5_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST6_HANDLER);
IRQ_HANDLER(IRQ_DMA2_ST7_HANDLER);

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   DMA Interrupt handler.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 *
 * @notapi
 */
static void dma_serve_interrupt(const dma_descriptor_t *ddp) {

    uint32_t sts;

    if ((ddp->stream <= 3U) ||
        (ddp->stream >= 8U && ddp->stream <= 11U)) {
        sts = (ddp->dma->LISR >> ddp->ish) & DMA_STATUS_MASK;
    } else {
        sts = (ddp->dma->HISR >> ddp->ish) & DMA_STATUS_MASK;
    }
    /* Compare bits TCIFx, HTIFx, TEIFx, DMEIFx in register LISR or HISR with 
       bits TCIE, HTIE, TEIE, DMEIE in register SxCR */
    if (((sts >> 2U) & (ddp->dmast->SxCR >> 1U)) != 0U) {
        if ((ddp->stream <= 3U) ||
            (ddp->stream >= 8U && ddp->stream <= 11U)) {
            ddp->dma->LIFCR = sts << ddp->ish;
        } else {
            ddp->dma->HIFCR = sts << ddp->ish;
        }
        if (dma.streams[ddp->stream].cb != NULL) {
            dma.streams[ddp->stream].cb(dma.streams[ddp->stream].arg, sts);
        }
    }
}

/**
 * @brief   DMA1 stream 0 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST0_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM0_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 1 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST1_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM1_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 2 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST2_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM2_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 3 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST3_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM3_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 4 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST4_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM4_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 5 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST5_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM5_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 6 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST6_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM6_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 stream 7 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA1_ST7_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA1_STREAM7_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 0 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST0_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM0_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 1 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST1_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM1_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 2 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST2_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM2_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 3 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST3_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM3_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 4 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST4_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM4_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 5 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST5_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM5_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 6 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST6_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM6_ID]);

    IRQ_EPILOGUE();
}

/**
 * @brief   DMA2 stream 7 ISR.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DMA2_ST7_HANDLER) {

    IRQ_PROLOGUE();

    dma_serve_interrupt(&dma_descriptors[DMA2_STREAM7_ID]);

    IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

const dma_descriptor_t *dma_stream_take(uint32_t id, uint32_t irq_prio,
                                        dma_callback_t cb, void *arg) {
    uint32_t sid, eid;

    if (id == DMA_STREAM_ID_ANY) {
        sid = 0U;
        eid = DMA_NUM_STREAMS - 1U;
    }
    else if (id == DMA1_STREAM_ID_ANY) {
        sid = 0U;
        eid = 7U;
    }
    else if (id == DMA2_STREAM_ID_ANY) {
        sid = 8U;
        eid = 15U;
    }
    else if (id < DMA_NUM_STREAMS) {
        sid = id;
        eid = id;
    }
    else {
        return NULL;
    }

    for (unsigned i = sid; i <= eid; i++) {
        uint32_t stream_msk = (1UL << i);
        if ((dma.taken & stream_msk) == 0U) {
            const dma_descriptor_t *ddp = &dma_descriptors[i];

            /* Installs the DMA handler.*/
            dma.streams[i].cb  = cb;
            dma.streams[i].arg = arg;
            dma.taken |= stream_msk;

            /* Enabling DMA clocks.*/
            if ((0x000000FFU & stream_msk) != 0U) {
                clock_enable_DMA1(true);
            }
            if ((0x0000FF00U & stream_msk) != 0U) {
                clock_enable_DMA2(true);
            }
            if (dma.taken != 0U) {
                clock_enable_DMAMUX1(true);
            }

            /* IRQ associated to the DMA stream.*/
            irq_set_priority(ddp->vector, irq_prio);
            irq_enable(ddp->vector);

            /* Putting the stream in a known state, just in case.*/
            dma_stream_disable(ddp);
            ddp->dmast->SxCR = DMA_SCR_RESET_VALUE;

            return ddp;
        }
    }

    return NULL;
}

void dma_stream_free(const dma_descriptor_t *ddp) {

    /* Freeing the stream.*/
    dma.taken &= ~(1UL << ddp->stream);

    /* Disables the associated IRQ vector if it is no more in use.*/
    irq_disable(ddp->vector);

    /* Removes the DMA handler.*/
    dma.streams[ddp->stream].cb  = NULL;
    dma.streams[ddp->stream].arg = NULL;

    /* Shutting down clocks that are no more required, if any.*/
    if ((dma.taken & 0x000000FFU) == 0U) {
        clock_disable_DMA1();
    }
    if ((dma.taken & 0x0000FF00U) == 0U) {
        clock_disable_DMA2();
    }
    if (dma.taken == 0U) {
        clock_disable_DMAMUX1();
    }
}

/** @} */
