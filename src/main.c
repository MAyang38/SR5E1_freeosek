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

#include <test_env.h>
#include"SPI_LLD_Init.h"
#include"CAN_LLD_Init.h"
#include "CDD_L9388_IF.h"
#include "Os.h"
/*SPI-GLOBAL_DATA*/
uint8_t spi_master_tx_buffer[SPI_BUFFER_SIZE] = {0x00,0x00,0x00,0x11};
uint8_t spi_slave_rx_buffer[SPI_BUFFER_SIZE];
bool WDG2Init_res = FALSE;
bool L9388_Init_res = FALSE;
/*CAN_GLOBAL_DATA*/
bool status;
can_frame_t frame;
uint32_t test_value;
uint8_t os_counter = 0;
bool valve_change = 0;
uint32_t Test_Input = 0;
uint8_t Pwm_Type = 0;
uint32_t Time_Count = 0; 
int main(void) {

    /* Enable interrupts.*/
    osal_sys_unlock();

    test_env_init((TestInit_t)
                  (TEST_INIT_CLOCK    |
                   TEST_INIT_GPIO     |
                   TEST_INIT_BOARD    |
                   TEST_INIT_IRQ      |
                   TEST_INIT_OSAL));

    /*LLD-Init*/
    SPI_LLD_Init();
    CAN_LLD_Init();
    // printf("Starting OSEK-OS in AppMode1\n");
    StartOS(AppMode1);

    
    /* Prepare frame to transmit.*/
    // frame.TYPE = CAN_ID_STD;
    // frame.ID = CAN_DEFAULT_FILTER_ID;
    // frame.DLC = CAN_MESSAGE_SIZE;
    // frame.data32[0] = CAN_DATA_TO_SEND;
    // frame.OPERATION = CAN_OPERATION_NORMAL;

    // // L9388_Init_res = CDD_L9388_Init();
    // // WDG2Init_res = CDD_L9388_WDG2_Init();

    // // CDD_L9388_NO_Ch1_Init_demo();
    // /* Application main loop */
    //     CDD_L9388_WDG2_Mainfunction();

    // for ( ; ; ) {
    //     osal_delay_millisec(11);
        

    //     CDD_L9388_Init_For_Test(Pwm_Type);

    //     CDD_L9388_Read_Status_For_Test();


    //     // 1. ADC_DR 寄存器 ADC_SEL写入0000    读取ADC_DATA_OUT位
    //     CDD_L9388_Read_ADC(0);
    //     // 2. VSOSER 寄存器 SEL_OUT_CMD 写入1 SEL_CONF 写入1    回读VSODR寄存器 
    //     L9388_Set_VSOSER();
    //     L9388_Read_VSODR();
    //     // 3. WLD1_SHLS_CONFIG寄存器 WLD_CMD位 写入1   回读WLD1_SHLSDR寄存器
    //     L9388_Set_WLD(1);
    //     L9388_Read_WLD1_SHLSDR();
        
    //     L9388_Set_SERVFLTMSK();
    //     L9388_Read_SERVFLTMSK();
        
    // }
}