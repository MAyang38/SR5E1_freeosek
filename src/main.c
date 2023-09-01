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


}


TASK(TaskInit)
{
	/* Set 500 tick alarm for TaskPeriodic */
	printf("InitTask: SetRelAlarm for TaskPeriodic.\n");
	SetRelAlarm(ActivateTaskPeriodic, 0, 500);

	/* Set 1000 tick callback alarm */
	printf("InitTask: SetRelAlarm for AppCallback.\n");
	SetRelAlarm(AppCallbackAlarm, 100, 1000);

	/* Activate TaskBlink */
	printf("InitTask: Activate TaskBlink.\n");
	ActivateTask(TaskBlink);

	/* Activate TaskBackground */
	ActivateTask(TaskBackground);

	/* end InitTask */
	printf("InitTask: TerminateTask().\n");
	TerminateTask();
}

/*
 * This task waits for an event to be set in order
 * to continue execution.
 */
TASK(TaskBlink)
{
	printf("TaskBlink: Init.\n");
	while(1)
	{
		printf("TaskBlink: Waiting for event...\n");
		WaitEvent(evBlink);
		ClearEvent(evBlink);
		printf("TaskBlink: LED Toggle.\n");

	}
	TerminateTask();
}

/*
 * This is a periodic task.
 */
TASK(TaskPeriodic)
{
	printf("TaskPeriodic: Event set.\n");
	SetEvent(TaskBlink, evBlink);

	/* end TaskPeriodic */
	TerminateTask();
}

/*
 * Just a background task with an infinite loop,
 * it has to be defined with the minimum priority!!!
 */
TASK(TaskBackground)
{
	volatile int i = 0;
	printf("TaskBackground: Running!\n");
	while(1)
	{
		i++;
		if(i == 0xFFFFF)
		{
			printf("TaskBackground still running...\n");
			i = 0;
		}
	}
}

/*
 * Alarm Callback example.
 */
ALARMCALLBACK(AppCallback)
{
	printf("AppCallback.\n");
}
