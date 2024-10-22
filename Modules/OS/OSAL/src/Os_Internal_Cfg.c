/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief FreeOSEK Os Generated Internal Configuration Implementation File
 **
 ** \file Os_Internal_Cfg.c
 **
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 * JuCe         Juan Cecconi
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20141125 v0.1.3 JuCe additional stack for x86 ARCH
 * 20090719 v0.1.2 MaCe rename file to Os_
 * 20090128 v0.1.1 MaCe add OSEK_MEMMAP check
 * 20080713 v0.1.0 MaCe initial version
 */

/*==================[inclusions]=============================================*/
#include "Os_Internal.h"
#include "Os_Cfg.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
/** \brief TaskInit stack */
uint8 StackTaskTaskInit[512];
/** \brief TaskBlink stack */
uint8 StackTaskTaskBlink[512];
/** \brief TaskPeriodic stack */
uint8 StackTaskTaskPeriodic[512];
/** \brief TaskBackground stack */
uint8 StackTaskTaskBackground[512];
/** \brief TaskPeriodic stack */
uint8 StackTaskTaskPeriodic_10ms[512];
/** \brief TaskPeriodic stack */
uint8 StackTaskTaskPeriodic_1ms[512];

/** \brief TaskInit context */
TaskContextType ContextTaskTaskInit;
/** \brief TaskBlink context */
TaskContextType ContextTaskTaskBlink;
/** \brief TaskPeriodic context */
TaskContextType ContextTaskTaskPeriodic;
/** \brief TaskBackground context */
TaskContextType ContextTaskTaskBackground;
/** \brief TaskBackground context */
TaskContextType ContextTaskTaskPeriodic_10ms;
/** \brief TaskBackground context */
TaskContextType ContextTaskTaskPeriodic_1ms;

/** \brief Ready List for Priority 2 */
TaskType ReadyList2[3];

/** \brief Ready List for Priority 1 */
TaskType ReadyList1[1];

/** \brief Ready List for Priority 0 */
TaskType ReadyList0[2];

const AlarmType OSEK_ALARMLIST_HardwareCounter[4] = {
	Alarm_Periodic_100ms, /* this alarm has to be incremented with this counter */
	Alarm_Periodic_1000ms, /* this alarm has to be incremented with this counter */
	Alarm_Periodic_10ms,
	Alarm_Periodic_1ms,
};


/*==================[external data definition]===============================*/
/* FreeOSEK to configured priority table
 *
 * This table show the relationship between the user selected
 * priorities and the OpenOSE priorities:
 *
 * User P.			Osek P.
 * 10					2
 * 5					1
 * 1					0
 */
// void OSEK_TASK_TaskInit(void)
// {
// 	// printf("%d",1);
// }
// void OSEK_TASK_TaskBlink(void)
// {
// 	// printf("%d",2);
// }
// void OSEK_TASK_TaskPeriodic(void)
// {
// 	// printf("%d",3);
// }
// void OSEK_TASK_TaskBackground(void)
// {
// 	// printf("%d",4);
// }
// void OSEK_CALLBACK_AppCallback(void)
// {
// 	/* kernel panic :( */
//     // printf("OSEK_CALLBACK_AppCallback\n");
	
// }

const TaskConstType TasksConst[TASKS_COUNT] = {
	/* Task TaskInit */
	{
 		OSEK_TASK_TaskInit,	/* task entry point */
		&ContextTaskTaskInit, /* pointer to task context */
		StackTaskTaskInit, /* pointer stack memory */
		512, /* stack size */
		0, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			0, /* non preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	},
	/* Task TaskBlink */
	{
 		OSEK_TASK_TaskBlink,	/* task entry point */
		&ContextTaskTaskBlink, /* pointer to task context */
		StackTaskTaskBlink, /* pointer stack memory */
		512, /* stack size */
		1, /* task priority */
		1, /* task max activations */
		{
			1, /* extended task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 | evBlink , /* events mask */
		0 /* resources mask */
	},
	/* Task TaskPeriodic */
	{
 		OSEK_TASK_TaskPeriodic_100ms,	/* task entry point */
		&ContextTaskTaskPeriodic, /* pointer to task context */
		StackTaskTaskPeriodic, /* pointer stack memory */
		512, /* stack size */
		2, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	},
	/* Task TaskBackground */
	{
 		OSEK_TASK_TaskBackground,	/* task entry point */
		&ContextTaskTaskBackground, /* pointer to task context */
		StackTaskTaskBackground, /* pointer stack memory */
		512, /* stack size */
		0, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	},
	/* Task TaskPeriodic_10ms */
	{
 		OSEK_TASK_TaskPeriodic_10ms,	/* task entry point */
		&ContextTaskTaskPeriodic_10ms, /* pointer to task context */
		StackTaskTaskPeriodic_10ms, /* pointer stack memory */
		512, /* stack size */
		2, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	},
	{
 		OSEK_TASK_TaskPeriodic_1ms,	/* task entry point */
		&ContextTaskTaskPeriodic_1ms, /* pointer to task context */
		StackTaskTaskPeriodic_1ms, /* pointer stack memory */
		512, /* stack size */
		2, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	},
};

/** \brief TaskVar Array */
TaskVariableType TasksVar[TASKS_COUNT];

/** \brief List of Auto Start Tasks in Application Mode AppMode1 */
const TaskType TasksAppModeAppMode1[1]  = {
	TaskInit
};
/** \brief AutoStart Array */
const AutoStartType AutoStart[1]  = {
	/* Application Mode AppMode1 */
	{
		1, /* Total Auto Start Tasks in this Application Mode */
		(TaskRefType)TasksAppModeAppMode1 /* Pointer to the list of Auto Start Stacks on this Application Mode */
	}
};

const ReadyConstType ReadyConst[3] = { 
	{
		3, /* Length of this ready list */
		ReadyList2 /* Pointer to the Ready List */
	},
	{
		1, /* Length of this ready list */
		ReadyList1 /* Pointer to the Ready List */
	},
	{
		2, /* Length of this ready list */
		ReadyList0 /* Pointer to the Ready List */
	}
};

/** TODO replace next line with: 
 ** ReadyVarType ReadyVar[3] ; */
ReadyVarType ReadyVar[3];

/** \brief Resources Priorities */
const TaskPriorityType ResourcesPriority[0]  = {

};
/** TODO replace next line with: 
 ** AlarmVarType AlarmsVar[2]; */
AlarmVarType AlarmsVar[4];

const AlarmConstType AlarmsConst[4]  = {
	{
		OSEK_COUNTER_HardwareCounter, /* Counter */
		ACTIVATETASK, /* Alarm action */
		{
			NULL, /* no callback */
			TaskPeriodic_100ms, /* TaskID */
			0, /* no event */
			0 /* no counter */
		},
	},
	{
		OSEK_COUNTER_HardwareCounter, /* Counter */
		ALARMCALLBACK, /* Alarm action */
		{
			OSEK_CALLBACK_Task_Periodic_1000ms, /* callback */
			0, /* no taskid */
			0, /* no event */
			0 /* no counter */
		},
	},
	{
		OSEK_COUNTER_HardwareCounter, /* Counter */
		ACTIVATETASK, /* Alarm action */
		{
			NULL, /* callback */
			TaskPeriodic_10ms, /* no taskid */
			0, /* no event */
			0 /* no counter */
		},
	},
	{
		OSEK_COUNTER_HardwareCounter, /* Counter */
		ACTIVATETASK, /* Alarm action */
		{
			NULL, /* callback */
			TaskPeriodic_1ms, /* no taskid */
			0, /* no event */
			0 /* no counter */
		},
	}
};

const AutoStartAlarmType AutoStartAlarm[ALARM_AUTOSTART_COUNT] = {

};

CounterVarType CountersVar[1];

const CounterConstType CountersConst[1] = {
	{
		4, /* quantity of alarms for this counter */
		(AlarmType*)OSEK_ALARMLIST_HardwareCounter, /* alarms list */
		60000000, /* max allowed value */
		1, /* min cycle */
		1 /* ticks per base */
	}
};


/** TODO replace the next line with
 ** uint8 ApplicationMode; */
uint8 ApplicationMode;

/** TODO replace the next line with
 ** uint8 ErrorHookRunning; */
uint8 ErrorHookRunning;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

