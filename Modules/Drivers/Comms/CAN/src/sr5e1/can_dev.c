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
 * @file    can_dev.c
 * @brief   CAN specific device source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup CAN
 * @ingroup COMMS
 * @{
 */

#include <can.h>
#include <can_private.h>
#include <clock.h>
#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

static uint8_t can_enabled = 0U;

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns pointer to the CAN register block.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              pointer to the CAN register block.
 *
 * @notapi
 */
FDCAN_TypeDef *can_dev_get_reg_ptr(can_driver_t *cdp) {

    FDCAN_TypeDef *can;

    if (cdp == &DRV_CAN1) {
        can = FDCAN1;
    } else if (cdp == &DRV_CAN2) {
        can = FDCAN2;
    } else if (cdp == &DRV_CAN3) {
        can = FDCAN3;
    } else {
        can = FDCAN4;
    }

    return can;
}

/**
 * @brief   Returns value of CAN clock.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              CAN clock.
 *
 * @notapi
 */
uint32_t can_dev_get_clock(can_driver_t *cdp) {

    (void)cdp;

    return CLOCK_FDCANCLK;
}

/**
 * @brief   Enables CAN clock.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 *
 * @notapi
 */
void can_dev_clock_enable(can_driver_t *cdp) {

    /* In order to use the CAN module, all CAN instances must be enabled.*/
    /* Enable clocks of all CAN instances only if no other instance has been
       already enabled.*/
    if(can_enabled == 0U) {
        clock_enable_FDCAN1(true);
        clock_enable_FDCAN2(true);
        clock_enable_FDCAN3(true);
        clock_enable_FDCAN4(true);
        clock_enable_FDCAN_MRAM(true);
    }

    /* Update the mask of enabled CAN instances.*/
    if (cdp == &DRV_CAN1) {
        can_enabled |= (1U << 0U);
    } else if (cdp == &DRV_CAN2) {
        can_enabled |= (1U << 1U);
    } else if (cdp == &DRV_CAN3) {
        can_enabled |= (1U << 2U);
    } else {
        can_enabled |= (1U << 3U);
    }

}

/**
 * @brief   Disables CAN clock.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 *
 * @notapi
 */
void can_dev_clock_disable(can_driver_t *cdp) {

    /* Update the mask of enabled CAN instances.*/
    if (cdp == &DRV_CAN1) {
        can_enabled &= ~(1U << 0U);
    } else if (cdp == &DRV_CAN2) {
        can_enabled &= ~(1U << 1U);
    } else if (cdp == &DRV_CAN3) {
        can_enabled &= ~(1U << 2U);
    } else {
        can_enabled &= ~(1U << 3U);
    }

    /* Disable clocks of all CAN instances only if no other instance is still
       enabled.*/
    if(can_enabled == 0U) {
        clock_disable_FDCAN1();
        clock_disable_FDCAN2();
        clock_disable_FDCAN3();
        clock_disable_FDCAN4();
        clock_disable_FDCAN_MRAM();
    }
}

/**
 * @brief   Returns CAN DMA TX trigger.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              DMA TX trigger.
 *
 * @notapi
 */
uint32_t can_dev_get_dma_tx_trigger(can_driver_t *cdp) {

    uint32_t dma_tx_trigger;

    if (cdp == &DRV_CAN1) {
        dma_tx_trigger = DMAMUX1_CAN_SUB_1_DMU_1_TX;
    } else if (cdp == &DRV_CAN2) {
        dma_tx_trigger = DMAMUX1_CAN_SUB_1_DMU_2_TX;
    } else if (cdp == &DRV_CAN3) {
        dma_tx_trigger = DMAMUX1_CAN_SUB_1_DMU_3_TX;
    } else {
        dma_tx_trigger = DMAMUX1_CAN_SUB_1_DMU_4_TX;
    }

    return dma_tx_trigger;
}

/**
 * @brief   Returns CAN DMA RX0 trigger.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              DMA RX0 trigger.
 *
 * @notapi
 */
uint32_t can_dev_get_dma_rx0_trigger(can_driver_t *cdp) {

    uint32_t dma_rx0_trigger;

    if (cdp == &DRV_CAN1) {
        dma_rx0_trigger = DMAMUX1_CAN_SUB_1_DMU_1_RX0;
    } else if (cdp == &DRV_CAN2) {
        dma_rx0_trigger = DMAMUX1_CAN_SUB_1_DMU_2_RX0;
    } else if (cdp == &DRV_CAN3) {
        dma_rx0_trigger = DMAMUX1_CAN_SUB_1_DMU_3_RX0;
    } else {
        dma_rx0_trigger = DMAMUX1_CAN_SUB_1_DMU_4_RX0;
    }

    return dma_rx0_trigger;
}

/**
 * @brief   Returns CAN DMA RX1 trigger.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              DMA RX1 trigger.
 *
 * @notapi
 */
uint32_t can_dev_get_dma_rx1_trigger(can_driver_t *cdp) {

    uint32_t dma_rx1_trigger;

    if (cdp == &DRV_CAN1) {
        dma_rx1_trigger = DMAMUX1_CAN_SUB_1_DMU_1_RX1;
    } else if (cdp == &DRV_CAN2) {
        dma_rx1_trigger = DMAMUX1_CAN_SUB_1_DMU_2_RX1;
    } else if (cdp == &DRV_CAN3) {
        dma_rx1_trigger = DMAMUX1_CAN_SUB_1_DMU_3_RX1;
    } else {
        dma_rx1_trigger = DMAMUX1_CAN_SUB_1_DMU_4_RX1;
    }

    return dma_rx1_trigger;
}

/**
 * @brief   Returns CAN LINE0 interrupt vector.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              CAN line0 interrupt vector
 *
 * @notapi
 */
IRQn_Type can_dev_get_line0_vector(can_driver_t *cdp) {

    IRQn_Type vector;

    if (cdp == &DRV_CAN1) {
        vector = IRQ_CAN1_LINE0_VECTOR;
    } else if (cdp == &DRV_CAN2) {
        vector = IRQ_CAN2_LINE0_VECTOR;
    } else if (cdp == &DRV_CAN3) {
        vector = IRQ_CAN3_LINE0_VECTOR;
    } else {
        vector = IRQ_CAN4_LINE0_VECTOR;
    }

    return vector;
}

/**
 * @brief   Returns CAN LINE1 interrupt vector.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              CAN line1 interrupt vector
 *
 * @notapi
 */
IRQn_Type can_dev_get_line1_vector(can_driver_t *cdp) {

    IRQn_Type vector;

    if (cdp == &DRV_CAN1) {
        vector = IRQ_CAN1_LINE1_VECTOR;
    } else if (cdp == &DRV_CAN2) {
        vector = IRQ_CAN2_LINE1_VECTOR;
    } else if (cdp == &DRV_CAN3) {
        vector = IRQ_CAN3_LINE1_VECTOR;
    } else {
        vector = IRQ_CAN4_LINE1_VECTOR;
    }

    return vector;
}

/**
 * @brief   Returns CAN DMU interrupt vector.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              CAN line1 interrupt vector
 *
 * @notapi
 */
IRQn_Type can_dev_get_dmu_vector(can_driver_t *cdp) {

    IRQn_Type vector;

    if (cdp == &DRV_CAN1) {
        vector = IRQ_CAN1_DMU_VECTOR;
    } else if (cdp == &DRV_CAN2) {
        vector = IRQ_CAN2_DMU_VECTOR;
    } else if (cdp == &DRV_CAN3) {
        vector = IRQ_CAN3_DMU_VECTOR;
    } else {
        vector = IRQ_CAN4_DMU_VECTOR;
    }

    return vector;
}

/**
 * @brief   Returns submodule shared RAM start address.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              ssubmodule shared RAM start address.
 *
 * @notapi
 */
uint32_t can_dev_get_msg_ram_address(can_driver_t *cdp) {

    (void)cdp;
    return (uint32_t)(SRAMCAN_BASE);
}

/**
 * @brief   Returns submodule shared RAM size.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              ssubmodule shared RAM size.
 *
 * @notapi
 */
uint32_t can_dev_get_msg_ram_size(can_driver_t *cdp) {

    (void)cdp;
    return (uint32_t)(CAN_SUB_SRAM_SIZE);
}

/**
 * @brief   Returns CAN shared RAM base address reserved to CAN instance.
 * @note    By default the submodule shared RAM is divided between all CAN
 *          instances within the submodule.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              shared RAM base address reserved to CAN driver.
 *
 * @notapi
 */
uint32_t can_dev_get_ram_start(can_driver_t *cdp) {

    uint32_t ram_address = can_dev_get_msg_ram_address(cdp);
    uint32_t ram_size    = can_dev_get_msg_ram_size(cdp) / 4U;

    if (cdp == &DRV_CAN1) {
        return ram_address;
    } else if (cdp == &DRV_CAN2) {
        return ram_address + ram_size;
    } else if (cdp == &DRV_CAN3) {
        return ram_address + 2U * ram_size;
    } else {
        return ram_address + 3U * ram_size;
    }
}

/**
 * @brief   Returns CAN shared RAM size reserved to CAN instance.
 * @note    By default the submodule shared RAM is divided between all CAN
 *          instances within the submodule.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @return              shared RAM base address reserved to CAN driver.
 *
 * @notapi
 */
uint32_t can_dev_get_ram_size(can_driver_t *cdp) {

    (void)cdp;
    return (can_dev_get_msg_ram_size(cdp) / 4U);
}

/**
 * @brief   FDCAN1 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN1_LINE0_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN1, CAN_IRQ_LINE0);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN1 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN1_LINE1_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN1, CAN_IRQ_LINE1);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN1 interrupt handler for DMU.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN1_DMU_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_dmu_interrupt(&DRV_CAN1);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN2 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN2_LINE0_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN2, CAN_IRQ_LINE0);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN2 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN2_LINE1_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN2, CAN_IRQ_LINE1);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN2 interrupt handler for DMU.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN2_DMU_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_dmu_interrupt(&DRV_CAN2);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN3 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN3_LINE0_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN3, CAN_IRQ_LINE0);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN3 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN3_LINE1_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN3, CAN_IRQ_LINE1);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN3 interrupt handler for DMU.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN3_DMU_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_dmu_interrupt(&DRV_CAN3);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN4 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN4_LINE0_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN4, CAN_IRQ_LINE0);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN4 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN4_LINE1_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_interrupt(&DRV_CAN4, CAN_IRQ_LINE1);

    IRQ_EPILOGUE();
}

/**
 * @brief   FDCAN4 interrupt handler for DMU.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CAN4_DMU_HANDLER)
{
    IRQ_PROLOGUE();

    __can_serve_dmu_interrupt(&DRV_CAN4);

    IRQ_EPILOGUE();
}

/** @} */
