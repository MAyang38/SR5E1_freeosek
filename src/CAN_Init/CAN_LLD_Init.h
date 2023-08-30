#include <test_env.h>
#include <can.h>

/*===========================================================================*/
/* CAN-related.                                                              */
/*===========================================================================*/

#define CAN_DEFAULT_FILTER_ID               0x7F0UL

#define CAN_DEFAULT_RX_BUFF_NUM             4U
#define CAN_DEFAULT_TX_BUFF_NUM             4U
#define CAN_DEFAULT_RX_FIFO0_NUM            4U
#define CAN_DEFAULT_RX_FIFO1_NUM            4U
#define CAN_DEFAULT_TX_FIFOQ_NUM            4U

#define CAN_DATA_TO_SEND                    0xF0CACC1AUL
#define CAN_MESSAGE_SIZE                    8U

void CAN_LLD_Init(void);