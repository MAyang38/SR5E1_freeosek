################################################################################
# StellarESDK module makefile.
################################################################################

#
# C sources
#

MODULE_C_SRCS := \
	src/osal.c \
	src/Os.c \
	src/Os_Cfg.c \
	src/ActivateTask.c \
	src/CancelAlarm.c \
	src/ChainTask.c \
	src/ClearEvent.c \
	src/GetActiveApplicationMode.c \
	src/GetAlarm.c \
	src/GetAlarmBase.c \
	src/GetEvent.c \
	src/GetResource.c \
	src/GetTaskID.c \
	src/GetTaskState.c \
	src/Os_Arch.c \
	src/Os_Internal_Arch.c \
	src/Os_Internal_Arch_Cfg.c \
	src/Os_Internal.c \
	src/Os_Internal_Cfg.c \
	src/ReleaseResource.c \
	src/Schedule.c \
	src/SetAbsAlarm.c \
	src/SetEvent.c \
	src/SetRelAlarm.c \
	src/ShutdownOS.c \
	src/StartOs_Arch_SysTick.c \
	src/StartOs_Arch.c \
	src/StartOS.c \
	src/TerminateTask.c \
	src/WaitEvent.c \
#
# Assembly sources
#
MODULE_A_SRCS :=

#
# C include directories
#
MODULE_C_INCS := \
	include

#
# Assembly include directories
#
MODULE_A_INCS :=

#
# Linker script include directories
#
MODULE_LS_INCS :=

#
# C defines
#
MODULE_C_DEFS := \
	BUILD_OS_OSAL

#
# Assembly defines
#
MODULE_A_DEFS :=

#
# C compiler options
#
MODULE_C_OPTS :=

#
# Assembly compiler options
#
MODULE_A_OPTS := 
