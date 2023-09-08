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
#include "osal.h"
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

/*   OS  GPIO  init */
void GPIO_LLD_init(void);
#define OS_GPIO_100 gpio_iopack(GPIO_PORT_G, GPIO_PIN_5)
#define OS_GPIO_CFG_100                           \
    (GPIO_MODE_MODER_OUTPUT |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_PULLUP |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define OS_GPIO_1000 gpio_iopack(GPIO_PORT_G, GPIO_PIN_6)
#define OS_GPIO_CFG_1000                             \
    (GPIO_MODE_MODER_OUTPUT |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_PULLUP |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)
#define OS_GPIO_10 gpio_iopack(GPIO_PORT_H, GPIO_PIN_15)
#define OS_GPIO_CFG_10                             \
    (GPIO_MODE_MODER_OUTPUT |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_PULLUP |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)
#define OS_GPIO_1 gpio_iopack(GPIO_PORT_H, GPIO_PIN_2)
#define OS_GPIO_CFG_1                             \
    (GPIO_MODE_MODER_OUTPUT |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_PULLUP |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)


int main(void) {

    /* Enable interrupts.*/
    osal_sys_unlock();
	// gpio_init();

    test_env_init((TestInit_t)
                  (TEST_INIT_CLOCK    |
                   TEST_INIT_GPIO     |
                   TEST_INIT_BOARD    |
                   TEST_INIT_IRQ      |
                   TEST_INIT_OSAL));
    
	/* LLD init.*/
	GPIO_LLD_init();
    SPI_LLD_Init();
    CAN_LLD_Init();

	/* start OS */
    StartOS(AppMode1);

	/* this shoule not be excuted*/
	while(1);
}

/*
 * This is 1ms a periodic task.
 */
TASK(TaskPeriodic_1ms)
{
	gpio_toggle_pin(OS_GPIO_1);
	/* end TaskPeriodic */
	TerminateTask();
}
/*
 * This is a 10ms periodic task.
 */
TASK(TaskPeriodic_10ms)
{
	gpio_toggle_pin(OS_GPIO_10);
	/* end TaskPeriodic */
	TerminateTask();
}
/*
 * This is a 100ms periodic task.
 */
TASK(TaskPeriodic_100ms)
{
	gpio_toggle_pin(OS_GPIO_100);
	/* end TaskPeriodic */
	TerminateTask();
}
/*
 * Alarm 1000ms Callback example.
 */

ALARMCALLBACK(Task_Periodic_1000ms)
{
	gpio_toggle_pin(OS_GPIO_1000);
	// printf("AppCallback.\n");
}



/*
 * Just a background task with an infinite loop,
 * it has to be defined with the minimum priority!!!
 */
TASK(TaskBackground)
{
	volatile int i = 0;
	// printf("TaskBackground: Running!\n");
	while(1)
	{
		i++;
		if(i == 0xFFFFF)
		{
			// printf("TaskBackground still running...\n");
			i = 0;
		}
	}
}

/*
 * This task waits for an event to be set in order
 * to continue execution.
 */
TASK(TaskBlink)
{
	
	TerminateTask();
}


TASK(TaskInit)
{

	

	/* Set 100 ms alarm for TaskPeriodic_100ms */
	SetRelAlarm(Alarm_Periodic_100ms, 0, 200);

	/* Set 1000 ms callback alarm */
	SetRelAlarm(Alarm_Periodic_1000ms, 0, 2000);

	SetRelAlarm(Alarm_Periodic_10ms, 0, 20);

	/* Set 1 ms callback alarm */
	SetRelAlarm(Alarm_Periodic_1ms, 0, 2);

	/* Activate TaskBlink */
	ActivateTask(TaskBlink);

	/* Activate TaskBackground */
	ActivateTask(TaskBackground);

	/* end InitTask */
	TerminateTask();
}


void GPIO_LLD_init()
{	gpio_set_pin_mode(OS_GPIO_1, OS_GPIO_CFG_1);
	gpio_set_pin_mode(OS_GPIO_10, OS_GPIO_CFG_10);
    gpio_set_pin_mode(OS_GPIO_100, OS_GPIO_CFG_100);
    gpio_set_pin_mode(OS_GPIO_1000, OS_GPIO_CFG_1000);
}
