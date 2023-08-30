#include "CDD_L9388_IF.h"

extern CDD_L9388_Struct_tag L9388_Rx_Register;

/*SysRqmt_L9388_001*/
bool CDD_L9388_Init(void)
{
    L9388_Read_CHIPID();
    L9388_Read_GENSTATUS();
    if(!CDD_L9388_GENCFG_Cfg())
    {
        return FALSE;
    }
    else if(!CDD_L9388_GENCFG2_Cfg())
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

bool CDD_L9388_WDG2_Init(void)
{
    if(!CDD_L9388_WDG2STARTTMG_Cfg())
    {
        return FALSE;
    }
    else if(!CDD_L9388_WDG2DELTATMG_Cfg())
    {
        return FALSE;
    }
    else if(!CDD_L9388_WDG2TOUTTMG_Cfg())
    {
        return FALSE;
    }
    else if(!CDD_L9388_WDG2PGM_Cfg())
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/*SysRqmt_L9388_003?��005*/
uint8_t channel = 0;
uint8_t mode = SOLENDR_PWM_MODE;
void CDD_L9388_Solenoid_Drivers_Global_conf(uint8_t channel,uint8_t mode,bool target)
{
    L9388_Set_SOLSERVENA(channel,target);
    L9388_Set_SOLENDR(channel,mode);
}

/*SysRqmt_L9388_004*/
void CDD_L9388_NO_TC_Current_set(uint8_t channel,uint8_t Current_Value)
{
    L9388_Set_NO_TC_Current(Current_Value,channel);
}

/*SysRqmt_L9388_004*/
void CDD_L9388_NO_TC_PWM_set(uint8_t channel,uint16_t PWM_Value)
{
	L9388_Set_NO_TC_PWM(PWM_Value,channel);
}

/*SysRqmt_L9388_006*/
void CDD_L9388_ESV_Current_set(uint8_t channel,uint8_t Current_Value)
{
    L9388_Set_ESV_Current(Current_Value,channel);
}

/*SysRqmt_L9388_006*/
void CDD_L9388_ESV_PWM_set(uint8_t channel,uint16_t PWM_Value)
{
	L9388_Set_ESV_PWM(PWM_Value,channel);
}

/*SysRqmt_L9388_007*/
void CDD_L9388_ON_OFF_Config(uint8_t channel,bool On_Off_Switch)
{
	L9388_Set_ON_OFF(channel, On_Off_Switch);
}

/*SysRqmt_L9388_008*/
void CDD_L9388_SHLS_Conf(bool Low_High_Switch,bool On_Off_Switch)
{
	L9388_Set_SHLS(Low_High_Switch, On_Off_Switch);
}

/*SysRqmt_L9388_009*/
void CDD_L9388_Read_NO_TC_Exception(uint8_t channel)
{
	L9388_Read_NO_TC_Exception(channel);
}

/*SysRqmt_L9388_010*/
void CDD_L9388_Read_ESV_Exception(uint8_t channel)
{
	L9388_Read_ESV_Exception(channel);
}

/*SysRqmt_L9388_011*/
void CDD_L9388_Read_ON_OFF_diag(uint8_t channel)
{
	L9388_Read_ON_OFF_diag(channel);
}

/*SysRqmt_L9388_012*/
void CDD_L9388_WDG2_Mainfunction(void)
{
    CDD_L9396_WDG2_Feeding_Service();
}

void CDD_L9388_NO_Ch1_Init_demo(void)
{
    L9388_Set_NO_TC_PWM(10000,channel);
    L9388_Set_NO_TC_Current(100,channel);
    L9388_Set_SOLSERVENA(channel,1);
    L9388_Set_SOLENDR(channel,mode);
}

/*SysRqmt_L9388_013*/
uint32_t CDD_L9388_ReadADVoltage(L9388_ADCType ADC_Channel)
{   
    uint32_t ADC_Value = 0;
    ADC_Value = CDD_L9388_Read_ADC(ADC_Channel);
    return ADC_Value;
}

/*SysRqmt_L9388_014*/
void CDD_L9388_Pump_Config(bool On_Off_Switch,uint16_t Period,uint8_t Dutycycle)
{
	L9388_Set_Pump_On_Off(On_Off_Switch);
	L9388_Pump_Config(Period,Dutycycle);
}

/*SysRqmt_L9388_015*/
void CDD_L9388_WSI_Config(bool En_Disable_Flag,uint8_t WSI_Sensor_Type,uint8_t channel)
{
	L9388_WSICTRL_INIT(En_Disable_Flag);
	L9388_Config_WSI_Type(channel,WSI_Sensor_Type);
}

/*SysRqmt_L9388_Diag_001*/
bool CDD_L9388_VPWR_Diag(void)
{
	bool result = 0;
	L9388_Read_GENSTATUS();
	if((L9388_Rx_Register.GENSTATUS.B.VPWR_OV)||(L9388_Rx_Register.GENSTATUS.B.VPWR_UV))
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_002*/
bool CDD_L9388_VDD_Diag(void)
{
	bool result = 0;
	L9388_Read_VDDFLT();
	if(L9388_Rx_Register.VDDFLT.R != 0)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_003*/
bool CDD_L9388_VDD5_Diag(void)
{
	bool result = 0;
	L9388_Read_VDD5FLT();
	if(L9388_Rx_Register.VDDSTATUS.R &0xF000)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_004*/
bool CDD_L9388_Charge_Pump_Diag(void)
{
	bool result = 0;
	L9388_Read_GENSTATUS();
	if((L9388_Rx_Register.GENSTATUS.B.CP_OV)||(L9388_Rx_Register.GENSTATUS.B.CP_UV))
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_005*/
bool CDD_L9388_Oscillator_Diag(void)
{
	bool result = 0;
	L9388_Read_GENSTATUS();
	if((L9388_Rx_Register.GENSTATUS.B.OSC_FRQ_MON)||(L9388_Rx_Register.GENSTATUS.B.OSC_SELF_TEST_RESULT)||(L9388_Rx_Register.GENSTATUS.B.OSC_STUCK_MON))
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_006*/
float Die_Temperature = 0;
bool CDD_L9388_Die_Temperature_Diag(void)
{
	bool result = 0;

	L9388_Read_GENSTATUS();
	Die_Temperature = L9388_Read_Die_Temperature();
	if(L9388_Rx_Register.GENSTATUS.B.T_SD_INT)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_007*/
bool CDD_L9388_Prun_WD_Diag(void)
{
	bool result = 0;
	L9388_Read_GENSTATUS();
	if(L9388_Rx_Register.GENSTATUS.B.WDOG_TO)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_008*/
bool CDD_L9388_SPI_Diag(void)
{
	bool result = 0;
	L9388_Read_GENSTATUS();
	if(L9388_Rx_Register.COMMUNICATION_FAULTS.R)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_009*/
bool CDD_L9388_PUMPDR_Diag(void)
{
	bool result = 0;
	L9388_Read_PUMPDR();
	if(L9388_Rx_Register.PUMPDR.B.PMP_BIST_STATUS == 0x3)
	{
		result = 1;
	}

	if(L9388_Rx_Register.PUMPDR.R & 0x1FF)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_010*/
bool CDD_L9388_VSO_Diag(void)
{
	bool result = 0;
	L9388_Read_VSODR();
	if(L9388_Rx_Register.VSODR.R &0x7E)
	{
		result = 1;
	}
	return result;
}

/*SysRqmt_L9388_Diag_011*/
bool CDD_L9388_RESOUTPUT_Diag(void)
{
	bool result = 0;
	L9388_Read_RESOUTPUT();
	if(L9388_Rx_Register.RESOUTPUT.R &0x7F)
	{
		result = 1;
	}
	return result;
}

void CDD_L9388_Init_For_Test(uint8_t pwmtype)
{
	CDD_L9388_GENCFG_Cfg();
	/*VSO\SEL_OUT*/
	L9388_Set_VSOSER();
	/*Pump*/
	CDD_L9388_Pump_Config(1, 10000, 50);
	/*NO_TC*/
	uint8_t i = 0;
	for(i=0;i<6;i++)
	{
		if(pwmtype == 0)
			L9388_Set_NO_TC_PWM(10000,i);
		else
			L9388_Set_NO_TC_PWM(16368,i);
		L9388_Set_NO_TC_Current(500,i);
		L9388_Set_SOLSERVENA(i,1);
		L9388_Set_SOLENDR(i,mode);
	}
	/*ESV*/
	for(i=0;i<2;i++)
	{
		L9388_Set_ESV_PWM(4000,i);
		L9388_Set_ESV_Current(1000,i);
		L9388_Set_SOLSERVENA(i+6,1);
		L9388_Set_SOLENDR(i+6,mode);
		CDD_L9388_Read_ESV_Exception(i);
	}
	/*NC*/
	for(i=0;i<4;i++)
	{
		L9388_Set_ON_OFF(i, 1);
	}
	/*SHLS*/
	L9388_Set_SHLS(0, 1);	


}

void CDD_L9388_Read_Status_For_Test(void)
{
	L9388_Read_CHIPID();
	L9388_Read_GENSTATUS();
	L9388_Read_VDDFLT();
	L9388_Read_VDD5FLT();
	L9388_Read_PUMPDR();
	L9388_Read_VSODR();
	L9388_Read_RESOUTPUT();
	CDD_L9388_Read_ADC(0);
	uint8_t i = 0;
	for(i=0;i<6;i++)
	{
		CDD_L9388_Read_NO_TC_Exception(i);
	}
	for(i=0;i<2;i++)
	{
		CDD_L9388_Read_ESV_Exception(i);
	}
	L9388_Read_SOLSERVENA();
	L9388_Read_SOLENDR();

	

}