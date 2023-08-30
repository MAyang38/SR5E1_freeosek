#include "CAN_LLD_Init.h"

/* This callback is invoked when a frame is received.*/
uint32_t rx_frame[2];
static void canrx_receive_cb(can_driver_t *cdp, can_frame_t frame, can_evt_t event) {

    (void)cdp;
    (void)frame;
    (void)event;

    static uint8_t i = 0U;
    /* Verify the received frame is equal to trasmitted frame.*/
    if ((event == CAN_CB_RX)                  &&
        (frame.TYPE == CAN_ID_STD)            &&
        (frame.ID == CAN_DEFAULT_FILTER_ID)   ) {
    	rx_frame[0] = frame.data32[0];
    	rx_frame[1] = frame.data32[1];
        i++;
    } else {
        while(1);
    }
}

/* This callback is invoked when an error occurs during reception.*/
static void canrx_error_cb(can_driver_t *cdp, uint32_t psr) {

    (void)cdp;
    (void)psr;
    // while(1);
}

/* This callback is invoked when an error occurs during transmission.*/
static void cantx_error_cb(can_driver_t *cdp, uint32_t psr) {

    (void)cdp;
    (void)psr;
    // while(1);
}

void CAN_LLD_Init(void)
{
    	/*===========================================================================*/
	/* CAN-related.                                                              */
	/*===========================================================================*/

    /* Initialize CAN RX/TX driver instances.*/
    can_init(&CANTXD);

    /* Configure CAN RX/TX.*/
    (void)can_set_irq_line(&CANTXD, CAN_IRQ_LINE0);

    (void)can_set_irq_mask(&CANTXD, CAN_IRQ_ALL_ENABLED);

    (void)can_set_loopback(&CANTXD, CAN_NO_LOOPBACK);

    (void)can_set_fd_mode(&CANTXD, false);

    (void)can_set_baudrate(&CANTXD, CAN_BAUDRATE_1MBIT);

    (void)can_set_dmu_mode(&CANTXD, false);

    (void)can_set_filter(&CANTXD, CAN_DEFAULT_FILTER_ID, 0U,
                         CAN_STD_FILTER_TYPE, CAN_FILTER_CLASSIC,
                         CAN_FEC_RX_BUF);

    can_set_buffers(&CANTXD, CAN_DEFAULT_RX_BUFF_NUM, CAN_DEFAULT_TX_BUFF_NUM,
                    CAN_DEFAULT_RX_FIFO0_NUM, CAN_DEFAULT_RX_FIFO1_NUM,
                    CAN_DEFAULT_TX_FIFOQ_NUM);

    (void)can_set_rx_polling_mode(&CANTXD, false);
    (void)can_set_tx_mode(&CANTXD, CAN_TX_MODE_DEDICATED_BUFF);

    (void)can_set_cb(&CANTXD, canrx_receive_cb);
    (void)can_set_err_cb(&CANTXD, canrx_error_cb);
    (void)can_set_err_cb(&CANTXD, cantx_error_cb);

    /* Apply CAN RX/TX configurations.*/
    can_start(&CANTXD);

}