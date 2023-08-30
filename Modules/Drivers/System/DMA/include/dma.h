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
 * @file    dma.h
 * @brief   DMA driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup DMA
 * @ingroup SYSTEM
 * @{
 */

#ifndef _DMA_H_
#define _DMA_H_

#include <dmamux.h>
#include <clock.h>
#include <irq.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of streams among all DMA engines.
 */
#define DMA_NUM_STREAMS                 16U

/**
 * @brief   Mask of status bits passed by callback functions.
 */
#define DMA_STATUS_MASK                 0x3DUL

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a DMA callback.
 *
 * @param[in] p         parameter for the registered function
 * @param[in] sts       status flags from the ISR register
 */
typedef void (*dma_callback_t)(void *p, uint32_t sts);

/**
 * @brief   Type of a DMA descriptor.
 */
typedef struct {
    uint32_t                  stream;     /**< @brief DMA stream identifier.  */
    DMAMUX_Channel_TypeDef    *muxch;     /**< @brief DMA mux channel.        */
    DMA_TypeDef               *dma;       /**< @brief DMA registers.          */
    DMA_Stream_TypeDef        *dmast;     /**< @brief DMA stream registers.   */
    uint32_t                  ish;        /**< @brief ISR flags shift.        */
    IRQn_Type                 vector;     /**< @brief IRQ vector.             */
} dma_descriptor_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @name    Stream identifiers
 * @{
 */
#define DMA1_STREAM0_ID                 0U
#define DMA1_STREAM1_ID                 1U
#define DMA1_STREAM2_ID                 2U
#define DMA1_STREAM3_ID                 3U
#define DMA1_STREAM4_ID                 4U
#define DMA1_STREAM5_ID                 5U
#define DMA1_STREAM6_ID                 6U
#define DMA1_STREAM7_ID                 7U
#define DMA2_STREAM0_ID                 8U
#define DMA2_STREAM1_ID                 9U
#define DMA2_STREAM2_ID                 10U
#define DMA2_STREAM3_ID                 11U
#define DMA2_STREAM4_ID                 12U
#define DMA2_STREAM5_ID                 13U
#define DMA2_STREAM6_ID                 14U
#define DMA2_STREAM7_ID                 15U
#define DMA_STREAM_ID_ANY               DMA_NUM_STREAMS
#define DMA1_STREAM_ID_ANY              (DMA_NUM_STREAMS + 1U)
#define DMA2_STREAM_ID_ANY              (DMA_NUM_STREAMS + 2U)
/** @} */

/**
 * @brief   Checks if a stream identifier is valid.
 *
 * @param[in] id        DMA stream id
 * @retval              The function result.
 * @retval false        invalid DMA stream.
 * @retval true         correct DMA stream.
 */
#define DMA_IS_VALID_STREAM(id) ((uint32_t)(id) <= (DMA_NUM_STREAMS + 2U))

/**
 * @brief   Checks if a DMA priority is valid.
 *
 * @param[in] prio      DMA priority
 * @retval              The function result.
 * @retval false        invalid DMA priority.
 * @retval true         correct DMA priority.
 */
#define DMA_IS_VALID_PRIORITY(prio) ((uint32_t)(prio) <= 3U)

/**
 * @name    DMA priority helper macros
 * @{
 */
#define DMA_PRIORITY_LOW                0U
#define DMA_PRIORITY_MEDIUM             1U
#define DMA_PRIORITY_HIGH               2U
#define DMA_PRIORITY_MAX                3U
/** @} */

/**
 * @name    DMA SCR helper macros
 * @{
 */
#define DMA_CCR_DMEIE                   DMA_SxCR_DMEIE
#define DMA_CCR_TEIE                    DMA_SxCR_TEIE
#define DMA_CCR_HTIE                    DMA_SxCR_HTIE
#define DMA_CCR_TCIE                    DMA_SxCR_TCIE
#define DMA_CCR_TRBUFF                  DMA_SxCR_TRBUFF

#define DMA_CCR_DIR_P2M                 0U
#define DMA_CCR_DIR_M2P                 DMA_SxCR_DIR_0
#define DMA_CCR_DIR_M2M                 DMA_SxCR_DIR_1

#define DMA_CCR_CIRC                    DMA_SxCR_CIRC

#define DMA_CCR_PINC                    DMA_SxCR_PINC
#define DMA_CCR_MINC                    DMA_SxCR_MINC

#define DMA_CCR_PSIZE_BYTE              0U
#define DMA_CCR_PSIZE_HWORD             DMA_SxCR_PSIZE_0
#define DMA_CCR_PSIZE_WORD              DMA_SxCR_PSIZE_1

#define DMA_CCR_MSIZE_BYTE              0U
#define DMA_CCR_MSIZE_HWORD             DMA_SxCR_MSIZE_0
#define DMA_CCR_MSIZE_WORD              DMA_SxCR_MSIZE_1
#define DMA_CCR_SIZE_MASK               (DMA_SxCR_PSIZE_Msk |               \
                                         DMA_SxCR_MSIZE_Msk)
#define DMA_CCR_PL_VALUE(n)             ((n) << 16U)

#define DMA_CCR_PBURST_SINGLE           0U
#define DMA_CCR_PBURST_INCR4            DMA_SxCR_PBURST_0
#define DMA_CCR_PBURST_INCR8            DMA_SxCR_PBURST_1
#define DMA_CCR_PBURST_INCR16           (DMA_SxCR_PBURST_1 |                \
                                         DMA_SxCR_PBURST_0)

#define DMA_CCR_MBURST_SINGLE           0U
#define DMA_CCR_MBURST_INCR4            DMA_SxCR_MBURST_0
#define DMA_CCR_MBURST_INCR8            DMA_SxCR_MBURST_1
#define DMA_CCR_MBURST_INCR16           (DMA_SxCR_MBURST_1 |                \
                                         DMA_SxCR_MBURST_0)
/** @} */

/**
 * @name    DMA callback status flags
 * @{
 */
#define DMA_STS_FEIF                    DMA_LISR_FEIF0
#define DMA_STS_DMEIF                   DMA_LISR_DMEIF0
#define DMA_STS_TEIF                    DMA_LISR_TEIF0
#define DMA_STS_HTIF                    DMA_LISR_HTIF0
#define DMA_STS_TCIF                    DMA_LISR_TCIF0
/** @} */

/**
 * @name    DMA FCR helper macros
 * @{
 */
#define DMA_FCR_FTH_1_4                 0U
#define DMA_FCR_FTH_1_2                 DMA_SxFCR_FTH_0
#define DMA_FCR_FTH_3_4                 DMA_SxFCR_FTH_1
#define DMA_FCR_FTH_FULL                DMA_SxFCR_FTH

#define DMA_FCR_DMDIS_FIFO_ENABLE       DMA_SxFCR_DMDIS
#define DMA_FCR_DMDIS_FIFO_DISABLE      0U

#define DMA_FCR_FS_0_25                 0U
#define DMA_FCR_FS_25_50                DMA_SxFCR_FS_0
#define DMA_FCR_FS_50_75                DMA_SxFCR_FS_1
#define DMA_FCR_FS_75_100               (DMA_SxFCR_FS_1 |                   \
                                         DMA_SxFCR_FS_0)
#define DMA_FCR_FS_EMPTY                DMA_SxFCR_FS_2
#define DMA_FCR_FS_FULL                 (DMA_SxFCR_FS_2 |                   \
                                         DMA_SxFCR_FS_0)

#define DMA_FCR_FIFO_INT_ENABLE         DMA_SxFCR_FEIE
#define DMA_FCR_FIFO_INT_DISABLE        0U
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Allocates a DMA stream.
 *
 * @param[in] id        the absolute stream identifier
 * @param[in] irq_prio  IRQ priority to be assigned to the stream
 * @param[in] cb        stream callback function
 * @param[in] arg       stream callback argument
 * @return              Pointer to the allocated stream descriptor.
 * @retval NULL         if the specified stream is not available.
 *
 * @api
 */
const dma_descriptor_t *dma_stream_take(uint32_t id, uint32_t irq_prio,
                                        dma_callback_t cb, void *arg);

/**
 * @brief   Frees a DMA stream.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 *
 * @api
 */
void dma_stream_free(const dma_descriptor_t *ddp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Setup of DMA stream peripheral pointer register.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @param[in] addr      peripheral data register address
 *
 * @api
 */
__STATIC_INLINE void dma_stream_set_peripheral(const dma_descriptor_t *ddp,
                                               const uint32_t addr) {

    ddp->dmast->SxPAR = (uint32_t)addr;
}

/**
 * @brief   Setup of DMA stream memory pointer register.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @param[in] addr      peripheral data register address
 *
 * @api
 */
__STATIC_INLINE void dma_stream_set_memory(const dma_descriptor_t *ddp,
                                           const uint32_t addr) {

    ddp->dmast->SxM0AR = (uint32_t)addr;
}

/**
 * @brief   Setup of DMA stream transfer counter register.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @param[in] cnt       number of transfers to be performed
 *
 * @api
 */
__STATIC_INLINE void dma_stream_set_count(const dma_descriptor_t *ddp,
                                          uint32_t cnt) {

    ddp->dmast->SxNDTR = cnt;
}

/**
 * @brief   Returns the current stream transfer count register value.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @return              The current transfer count value.
 *
 * @api
 */
__STATIC_INLINE uint32_t dma_stream_get_count(const dma_descriptor_t *ddp) {

    return ddp->dmast->SxNDTR;
}

/**
 * @brief   Setup of DMA stream transfer mode.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @param[in] mode      transfer mode flags to be programmed in @p CR register
 *
 * @api
 */
__STATIC_INLINE void dma_stream_set_transfer_mode(const dma_descriptor_t *ddp,
                                                  uint32_t mode) {

    ddp->dmast->SxCR = mode;
}

/**
 * @brief   Clears a DMA stream interrupt.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 *
 * @api
 */
__STATIC_INLINE void dma_stream_clear_interrupts(const dma_descriptor_t *ddp) {

    if ((ddp->stream <= 3U) ||
        (ddp->stream >= 8U && ddp->stream <= 11U)) {
        ddp->dma->LIFCR = DMA_STATUS_MASK << ddp->ish;
    } else {
        ddp->dma->HIFCR = DMA_STATUS_MASK << ddp->ish;
    }
}

/**
 * @brief   Returns the DMA stream enable status.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @return              The enabled status.
 * @retval false        The DMA stream is not enabled.
 * @retval true         The DMA stream is enabled.
 *
 * @api
 */
__STATIC_INLINE bool dma_stream_is_enabled(const dma_descriptor_t *ddp) {

    return (bool)((ddp->dmast->SxCR & DMA_SxCR_EN) != 0U);
}

/**
 * @brief   Enables a DMA stream.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 *
 * @api
 */
__STATIC_INLINE void dma_stream_enable(const dma_descriptor_t *ddp) {

    ddp->dmast->SxCR |= DMA_SxCR_EN;
}

/**
 * @brief   Disables a DMA stream and clears pending interrupts.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 *
 * @api
 */
__STATIC_INLINE void dma_stream_disable(const dma_descriptor_t *ddp) {

    ddp->dmast->SxCR &= ~(DMA_SxCR_TCIE | DMA_SxCR_HTIE  |
                          DMA_SxCR_TEIE | DMA_SxCR_DMEIE |
                          DMA_SxCR_EN);
    dma_stream_clear_interrupts(ddp);
}

/**
 * @brief   Polled wait for transfer complete.
 * @note    A stream in circular mode never completes.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 *
 * @api
 */
__STATIC_INLINE void dma_stream_wait_complete(const dma_descriptor_t *ddp) {

    while (dma_stream_is_enabled(ddp)) {
    }
}

/**
 * @brief   Setup of DMA fifo mode.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @param[in] mode      fifo mode flags to be programmed in @p FCR register
 *
 * @api
 */
__STATIC_INLINE void dma_stream_set_fifo_mode(const dma_descriptor_t *ddp,
                                              uint32_t mode) {

    ddp->dmast->SxFCR |= mode;
}

/**
 * @brief   Selects a trigger source for the DMA stream.
 *
 * @param[in] ddp       pointer to a @p dma_descriptor_t structure
 * @param[in] trigger   peripheral identifier for this trigger
 *
 * @api
 */
__STATIC_INLINE void dma_stream_set_trigger(const dma_descriptor_t *ddp,
                                            uint32_t trigger) {

    ddp->muxch->CCR = trigger;
}

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _DMA_H_ */

/** @} */
