#include "CDD_L9388_Drv.h"

volatile CDD_L9388_Struct_tag L9388_Tx_Register;
volatile CDD_L9388_Struct_tag L9388_Rx_Register;
extern L9388_Data_tag L9388_SPI_Buffer;

void L9388_Read_CHIPID(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = CHIPID_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.CHIPID.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_GENSTATUS(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = GENSTATUS_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.GENSTATUS.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

bool CDD_L9388_GENCFG_Cfg(void)
{
    bool res = TRUE;
    L9388_SPI_Buffer.TxOut.B.Addr = GENCFG_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;

    L9388_Tx_Register.GENCFG.B.KA = GENCFG_KA;
    L9388_Tx_Register.GENCFG.B.PHOLD = GENCFG_PHOLD;
    L9388_Tx_Register.GENCFG.B.FS_VDS_TH = GENCFG_FS_VDS_TH;
    L9388_Tx_Register.GENCFG.B.FS_CMD = GENCFG_FS_CMD;
    L9388_Tx_Register.GENCFG.B.FS_EN = GENCFG_FS_EN;
    L9388_Tx_Register.GENCFG.B.PMP_EN = GENCFG_PMP_EN;
    L9388_Tx_Register.GENCFG.B.OSC_SPR_SPECT_DIS = GENCFG_OSC_SPR_SPECT_DIS;
    L9388_Tx_Register.GENCFG.B.VDD4_OVC_SD_RESTART_TIME = GENCFG_VDD4_OVC_SD_RESTART_TIME;
    L9388_Tx_Register.GENCFG.B.VDD4_OVC_FLT_TIME = GENCFG_VDD4_OVC_FLT_TIME;
    L9388_Tx_Register.GENCFG.B.VDD3_OVC_SD_RESTART_TIME = GENCFG_VDD3_OVC_SD_RESTART_TIME;
    L9388_Tx_Register.GENCFG.B.VDD3_OVC_FLT_TIME = GENCFG_VDD3_OVC_FLT_TIME;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.GENCFG.R;

    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);

    L9388_Rx_Register.GENCFG.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    if((L9388_Rx_Register.GENCFG.B.KA != GENCFG_KA)|| \
    (L9388_Rx_Register.GENCFG.B.PHOLD != GENCFG_PHOLD)|| \
    (L9388_Rx_Register.GENCFG.B.FS_VDS_TH != GENCFG_FS_VDS_TH)|| \
    (L9388_Rx_Register.GENCFG.B.FS_CMD != GENCFG_FS_CMD)|| \
    (L9388_Rx_Register.GENCFG.B.FS_EN != GENCFG_FS_EN)|| \
    (L9388_Rx_Register.GENCFG.B.PMP_EN != GENCFG_PMP_EN)|| \
    (L9388_Rx_Register.GENCFG.B.OSC_SPR_SPECT_DIS != GENCFG_OSC_SPR_SPECT_DIS)|| \
    (L9388_Rx_Register.GENCFG.B.VDD4_OVC_SD_RESTART_TIME != GENCFG_VDD4_OVC_SD_RESTART_TIME)|| \
    (L9388_Rx_Register.GENCFG.B.VDD4_OVC_FLT_TIME != GENCFG_VDD4_OVC_FLT_TIME)|| \
    (L9388_Rx_Register.GENCFG.B.VDD3_OVC_SD_RESTART_TIME != GENCFG_VDD3_OVC_SD_RESTART_TIME)|| \
    (L9388_Rx_Register.GENCFG.B.VDD3_OVC_FLT_TIME != GENCFG_VDD3_OVC_FLT_TIME))
    {
        res = FALSE;
    }
    return res;
}

bool CDD_L9388_GENCFG2_Cfg(void)
{
    bool res = TRUE;
    L9388_SPI_Buffer.TxOut.B.Addr = GENCFG2_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;

    L9388_Tx_Register.GENCFG2.B.FS_VDS_FIL = GENCFG2_FS_VDS_FIL;
    L9388_Tx_Register.GENCFG2.B.DIS_TH = GENCFG2_DIS_TH;
    L9388_Tx_Register.GENCFG2.B.WD_SW_DIS = GENCFG2_WD_SW_DIS;
    L9388_Tx_Register.GENCFG2.B.VDD2_5_AUTO_SWITCH_OFFLDO_MODE = GENCFG2_VDD2_5_AUTO_SWITCH_OFF;
    L9388_Tx_Register.GENCFG2.B.VDD1_DIODELOSS_FILT = GENCFG2_VDD1_DIODELOSS_FILT;
    L9388_Tx_Register.GENCFG2.B.WD_DIS = GENCFG2_WD_DIS;
    L9388_Tx_Register.GENCFG2.B.VDD5_DIS = GENCFG2_VDD5_DIS;
    L9388_Tx_Register.GENCFG2.B.VDD2_DIS = GENCFG2_VDD2_DIS;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.GENCFG2.R;

    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);

    L9388_Rx_Register.GENCFG2.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    if((L9388_Rx_Register.GENCFG2.B.FS_VDS_FIL != GENCFG2_FS_VDS_FIL)|| \
    (L9388_Rx_Register.GENCFG2.B.DIS_TH != GENCFG2_DIS_TH)|| \
    (L9388_Rx_Register.GENCFG2.B.WD_SW_DIS != GENCFG2_WD_SW_DIS)|| \
    (L9388_Rx_Register.GENCFG2.B.VDD2_5_AUTO_SWITCH_OFFLDO_MODE != GENCFG2_VDD2_5_AUTO_SWITCH_OFF)|| \
    (L9388_Rx_Register.GENCFG2.B.VDD1_DIODELOSS_FILT != GENCFG2_VDD1_DIODELOSS_FILT)|| \
    (L9388_Rx_Register.GENCFG2.B.WD_DIS != GENCFG2_WD_DIS)|| \
    (L9388_Rx_Register.GENCFG2.B.VDD5_DIS != GENCFG2_VDD5_DIS)|| \
    (L9388_Rx_Register.GENCFG2.B.VDD2_DIS != GENCFG2_VDD2_DIS))
    {
        res = FALSE;
    }
    return res;
}

void L9388_Set_NO_TC_PWM(uint16_t PWM_Code,uint8_t Channel)
{
    uint16_t SPI_Value;
    if(PWM_Code>16368)
    {
        SPI_Value = 959;
    }
    else if(PWM_Code<1024)
    {
        SPI_Value = 0;
    }else
    {
        SPI_Value = (PWM_Code - 1024)/16;
    }    
    L9388_Tx_Register.CTRLCFG_CHX[Channel].B.PWM_CODE = SPI_Value;
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+CTRLCFG_CH0_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.CTRLCFG_CHX[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.CTRLCFG_CHX[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_NO_TC_PWM(uint8_t Channel)
{
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+CTRLCFG_CH0_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.CTRLCFG_CHX[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.CTRLCFG_CHX[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_ESV_PWM(uint16_t PWM_Code,uint8_t Channel)
{
    uint16_t SPI_Value;
    if(PWM_Code>5040)
    {
        SPI_Value = 63;
    }
    else if(PWM_Code<2016)
    {
        SPI_Value = 0;
    }else
    {
        SPI_Value = (PWM_Code - 2016)/48;
    }
    L9388_Tx_Register.CTRLCFG_CH6_7[Channel].B.PWM_CODE = SPI_Value;
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+CTRLCFG_CH6_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.CTRLCFG_CH6_7[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.CTRLCFG_CH6_7[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_ESV_PWM(uint8_t Channel)
{
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+CTRLCFG_CH6_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.CTRLCFG_CH6_7[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.CTRLCFG_CH6_7[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_NO_TC_Current(uint16_t Set_Point,uint8_t Channel)
{
    uint16_t SPI_Value;
    if(Set_Point>3071)
    {
        SPI_Value = 2047;
    }
    else
    {
        SPI_Value = (uint16_t)(((uint32_t)Set_Point)*2047/3070);
    }
    
    L9388_Tx_Register.SETPOINT_CHX[Channel].B.SET_POINT = SPI_Value;

    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+SETPOINT_CH0_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SETPOINT_CHX[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.SETPOINT_CHX[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_NO_TC_Current(uint8_t Channel)
{
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+SETPOINT_CH0_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SETPOINT_CHX[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.SETPOINT_CHX[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_NO_TC_Exception(uint8_t Channel)
{
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+EXCEPTIONS_CH0_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.EXCEPTIONS_CHX[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.EXCEPTIONS_CHX[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_ESV_Current(uint16_t Set_Point,uint8_t Channel)
{
    uint16_t SPI_Value;
    if(Set_Point>3071)
    {
        SPI_Value = 2047;
    }
    else
    {
        SPI_Value = (uint16_t)(((uint32_t)Set_Point)*2047/3070);
    }

    L9388_Tx_Register.SETPOINT_CH6_7[Channel].B.SET_POINT = SPI_Value;

    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+SETPOINT_CH6_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SETPOINT_CH6_7[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.SETPOINT_CH6_7[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_ESV_Current(uint8_t Channel)
{
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+SETPOINT_CH6_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SETPOINT_CH6_7[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.SETPOINT_CH6_7[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_ESV_Exception(uint8_t Channel)
{
    L9388_SPI_Buffer.TxOut.B.Addr = Channel*0x10+EXCEPTIONS_CH6_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.EXCEPTIONS_CH6_7[Channel].R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.EXCEPTIONS_CH6_7[Channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_SOLSERVENA(uint8_t channel,bool target)
{
    L9388_Tx_Register.SOLSERVENA.R |= (target<<channel) ;
	L9388_SPI_Buffer.TxOut.B.Addr = SOLSERVENA_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SOLSERVENA.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.SOLSERVENA.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_SOLSERVENA(void)
{
	L9388_SPI_Buffer.TxOut.B.Addr = SOLSERVENA_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SOLSERVENA.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.SOLSERVENA.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_SOLENDR(uint8_t channel, uint8_t mode)
{
    if(mode == SOLENDR_PWM_MODE)
    {
        L9388_Tx_Register.SOLENDR.R |= (1<<(channel*2+1));
        L9388_Tx_Register.SOLENDR.R &= ~(1<<channel*2);      
    }
    else if(mode == SOLENDR_FULL_ON_MODE)
    {
        L9388_Tx_Register.SOLENDR.R |= (1<<(channel*2+1));
        L9388_Tx_Register.SOLENDR.R |= (1<<channel*2);
    }
	L9388_SPI_Buffer.TxOut.B.Addr = SOLENDR_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SOLENDR.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.SOLENDR.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_SOLENDR(void)
{
	L9388_SPI_Buffer.TxOut.B.Addr = SOLENDR_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.SOLENDR.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

/*WDG2*/
void L9388_WD2_Read_WDG2STATUS(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2STATUS_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.WDG2STATUS.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_WD2_Read_Seed(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2SEED_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.WDG2SEED.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_WD2_Write_Answer(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2ANS_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WDG2ANS.R;
    L9388_SPI_WRDataWithCRC(&L9388_SPI_Buffer);
}

uint8_t Seed_Buffer[32];
uint8_t Ans_Buffer[32];
uint8_t cnt = 0;
uint8_t WDG2_StateCtrl = WDG2_READ_SEED_State;
void CDD_L9396_WDG2_Feeding_Service(void)
{
	if(WDG2_StateCtrl == WDG2_Write_ANSW_State ){
        L9388_WD2_Write_Answer();		
        L9388_WD2_Read_WDG2STATUS();
		WDG2_StateCtrl = WDG2_READ_SEED_State;  /*change to read seed state*/
	}
	else if(WDG2_StateCtrl == WDG2_READ_SEED_State)
	{
        L9388_WD2_Read_Seed(); /*Read Seed */
        L9388_Tx_Register.WDG2ANS.B.ANSWER_HIGH = L9388_Rx_Register.WDG2SEED.B.SEED;    // ans_hi
        L9388_Tx_Register.WDG2ANS.B.ANSWER_LOW = (L9388_Rx_Register.WDG2SEED.B.SEED^0xFFU)+1; //ans_low  

		#if 1 /*Load Answs and Seeds for monitoring */
		cnt++;
		if(cnt >= 32)		cnt = 0;
		Seed_Buffer[cnt] = L9388_Rx_Register.WDG2SEED.B.SEED;
		Ans_Buffer[cnt] = L9388_Tx_Register.WDG2ANS.B.ANSWER_LOW;
		#endif

		WDG2_StateCtrl = WDG2_Write_ANSW_State; /*Next loop : Write Answ*/
	}
	else{
		/*Err*/
		WDG2_StateCtrl = WDG2_Idle_State;
	}

}

bool CDD_L9388_WDG2STARTTMG_Cfg(void)
{
    bool res = TRUE;
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2STARTTMG_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;

    L9388_Tx_Register.WDG2STARTTMG.B.VALID_ANSWER_START = WDG2STARTTMG_VALID_ANSWER_START;
    L9388_Tx_Register.WDG2STARTTMG.B.VALID_REQUEST_START = WDG2STARTTMG_VALID_REQUEST_START;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WDG2STARTTMG.R;

    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);

    L9388_Rx_Register.WDG2STARTTMG.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    if((L9388_Rx_Register.WDG2STARTTMG.B.VALID_ANSWER_START != WDG2STARTTMG_VALID_ANSWER_START)|| \
    (L9388_Rx_Register.WDG2STARTTMG.B.VALID_ANSWER_START != WDG2STARTTMG_VALID_ANSWER_START))
    {
        res = FALSE;
    }
    return res;
}

bool CDD_L9388_WDG2DELTATMG_Cfg(void)
{
    bool res = TRUE;
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2DELTATMG_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;

    L9388_Tx_Register.WDG2DELTATMG.B.REQ_CHECK_ENABLE = WDG2DELTATMG_REQ_CHECK_ENABLE;
    L9388_Tx_Register.WDG2DELTATMG.B.VALID_REQUEST_DELTA = WDG2DELTATMG_VALID_REQUEST_DELTA;
    L9388_Tx_Register.WDG2DELTATMG.B.VALID_ANSWER_DELTA = WDG2DELTATMG_VALID_ANSWER_DELTA;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WDG2DELTATMG.R;

    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);

    L9388_Rx_Register.WDG2DELTATMG.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    if((L9388_Rx_Register.WDG2DELTATMG.B.REQ_CHECK_ENABLE != WDG2DELTATMG_REQ_CHECK_ENABLE)|| \
    (L9388_Rx_Register.WDG2DELTATMG.B.VALID_REQUEST_DELTA != WDG2DELTATMG_VALID_REQUEST_DELTA)|| \
    (L9388_Rx_Register.WDG2DELTATMG.B.VALID_ANSWER_DELTA != WDG2DELTATMG_VALID_ANSWER_DELTA))
    {
        res = FALSE;
    }
    return res; 
}

bool CDD_L9388_WDG2TOUTTMG_Cfg(void)
{
    bool res = TRUE;
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2TOUTTMG_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;

    L9388_Tx_Register.WDG2TOUTTMG.B.TO_RESET_ENABLE = WDG2TOUTTMG_TO_RESET_ENABLE;
    L9388_Tx_Register.WDG2TOUTTMG.B.REQUEST_TIME_OUT_DELTA = WDG2TOUTTMG_VALID_REQUEST_DELTA;
    L9388_Tx_Register.WDG2TOUTTMG.B.ANSWER_TIME_OUT_DELTA = WDG2TOUTTMG_VALID_ANSWER_DELTA;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WDG2TOUTTMG.R;

    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);

    L9388_Rx_Register.WDG2TOUTTMG.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    if((L9388_Rx_Register.WDG2TOUTTMG.B.TO_RESET_ENABLE != WDG2TOUTTMG_TO_RESET_ENABLE)|| \
    (L9388_Rx_Register.WDG2TOUTTMG.B.REQUEST_TIME_OUT_DELTA != WDG2TOUTTMG_VALID_REQUEST_DELTA)|| \
    (L9388_Rx_Register.WDG2TOUTTMG.B.ANSWER_TIME_OUT_DELTA != WDG2TOUTTMG_VALID_ANSWER_DELTA))
    {
        res = FALSE;
    }
    return res;     
}

bool CDD_L9388_WDG2PGM_Cfg(void)
{
    bool res = TRUE;
    L9388_SPI_Buffer.TxOut.B.Addr = WDG2PGM_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;

    L9388_Tx_Register.WDG2PGM.B.RESET_ENABLE = WDG2PGM_WD_RST_EN;
    L9388_Tx_Register.WDG2PGM.B.CLOCK_DIVISION = WDG2PGM_WD_CLK_DIV;
    L9388_Tx_Register.WDG2PGM.B.LOW_TH = WDG2PGM_WD_TH_LOW;
    L9388_Tx_Register.WDG2PGM.B.HIGH_TH = WDG2PGM_WD_TH_HIGH;
    L9388_Tx_Register.WDG2PGM.B.BAD_STEPS = WDG2PGM_WD_CNT_BAD_STEP;
    L9388_Tx_Register.WDG2PGM.B.GOOD_STEPS = WDG2PGM_WD_CNT_GOOD_STEP;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WDG2PGM.R;

    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);

    L9388_Rx_Register.WDG2PGM.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    if((L9388_Rx_Register.WDG2PGM.B.RESET_ENABLE != WDG2PGM_WD_RST_EN)|| \
    (L9388_Rx_Register.WDG2PGM.B.CLOCK_DIVISION != WDG2PGM_WD_CLK_DIV)|| \
    (L9388_Rx_Register.WDG2PGM.B.LOW_TH != WDG2PGM_WD_TH_LOW)|| \
    (L9388_Rx_Register.WDG2PGM.B.HIGH_TH != WDG2PGM_WD_TH_HIGH)|| \
    (L9388_Rx_Register.WDG2PGM.B.BAD_STEPS != WDG2PGM_WD_CNT_BAD_STEP)|| \
    (L9388_Rx_Register.WDG2PGM.B.GOOD_STEPS != WDG2PGM_WD_CNT_GOOD_STEP))
    {
        res = FALSE;
    }
    return res; 
}

uint32_t CDD_L9388_Read_ADC(L9388_ADCType ADC_Channel)
{
	uint32_t temp_ADC_initial=0;
	uint32_t temp_ADC_physical=0;
    uint8_t counter = 0;
    L9388_Tx_Register.ADC_DR.R = 0;
    L9388_Tx_Register.ADC_DR.B.ADC_SEL = ADC_Channel;

    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.Addr = ADC_DR_ADDR;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.ADC_DR.R;
    
    L9388_SPI_WRDataWithCRC(&L9388_SPI_Buffer);

    do
    {
        osal_delay_millisec(1U);
        L9388_SPI_RDDataWithCRC(&L9388_SPI_Buffer);
        L9388_Rx_Register.ADC_DR.R = L9388_SPI_Buffer.RxIn.B.DataRx;
        counter++;
    }while ((!L9388_Rx_Register.ADC_DR.B.ADC_BUSY)&&(counter<10));
   
    if(counter>10)
    {
        return 0;
    }
    
	temp_ADC_initial= (uint32_t)(L9388_Rx_Register.ADC_DR.B.ADC_DATA_OUT); /*load MISO data*/

	switch(ADC_Channel)
		{
			case	ADC_ADCIN1_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*1200/1023;break;
			case	ADC_ADCIN2_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*1200/1023;break;
			case	ADC_ADCIN3_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*1200/1023;break;
			case	ADC_ADCIN4_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*1200/1023;break;
			case	ADC_WS1_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*13.2*1200/1023;break;
			case	ADC_WS2_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*13.2*1200/1023;break;
			case	ADC_WS3_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*13.2*1200/1023;break;
			case	ADC_WS4_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*13.2*1200/1023;break;
			case	ADC_VDD2_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*4.42*1200/1023;break;
			case	ADC_VDD3_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*4.42*1200/1023;break;
			case	ADC_VDD4_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*4.42*1200/1023;break;
			case	ADC_VDD5_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*4.42*1200/1023;break;
			case	ADC_VPWR_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*32*1200/1023;break;
			case	ADC_FSD_SEL_ADDR:temp_ADC_physical=temp_ADC_initial*32*1200/1023;break;
			default: break;
		}
	return temp_ADC_physical;
}

void L9388_Set_ON_OFF(uint8_t channel,bool On_Off_Switch)
{
	switch(channel)
	{
		case 0:
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH1_CMD = On_Off_Switch;
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH1_EN = On_Off_Switch;
			break;
		case 1:
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH2_CMD = On_Off_Switch;
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH2_EN = On_Off_Switch;
			break;
		case 2:
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH3_CMD = On_Off_Switch;
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH3_EN = On_Off_Switch;
			break;
		case 3:
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH4_CMD = On_Off_Switch;
			L9388_Tx_Register.ON_OFF_CH_CONFIG.B.CH4_EN = On_Off_Switch;
			break;
	}
	L9388_SPI_Buffer.TxOut.B.Addr = ON_OFF_CH_CONGIF_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.ON_OFF_CH_CONFIG.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.ON_OFF_CH_CONFIG.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_ON_OFF_diag(uint8_t channel)
{
	L9388_SPI_Buffer.TxOut.B.Addr = ON_OFF_CH1_DR_ADDR+channel;
	L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.ON_OFF_CH_DR[channel].R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.ON_OFF_CH_DR[channel].R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_SHLS(bool Low_High_Switch,bool On_Off_Switch)
{
	L9388_Tx_Register.WLD1_SHLS_CONFIG.B.SHLS_CMD = On_Off_Switch;
	L9388_Tx_Register.WLD1_SHLS_CONFIG.B.SHLS_CONFIG = Low_High_Switch;
	L9388_SPI_Buffer.TxOut.B.Addr = WLD1_SHLS_CONFIG_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WLD1_SHLS_CONFIG.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.WLD1_SHLS_CONFIG.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}
void L9388_Set_WLD(bool On_Off_Switch)
{
	L9388_Tx_Register.WLD1_SHLS_CONFIG.B.WLD_CMD = On_Off_Switch;
    L9388_Tx_Register.WLD1_SHLS_CONFIG.B.WLD_CONF = 1;
	L9388_SPI_Buffer.TxOut.B.Addr = WLD1_SHLS_CONFIG_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WLD1_SHLS_CONFIG.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.WLD1_SHLS_CONFIG.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_SERVFLTMSK(void)
{
    L9388_Tx_Register.SERVFLTMSK.B.E_PVDS_GPO = 1;
    L9388_Tx_Register.SERVFLTMSK.B.E_VDD2_5_WSx_OT_GPO = 1;
    L9388_Tx_Register.SERVFLTMSK.B.E_FBO_GPO = 1;
    L9388_Tx_Register.SERVFLTMSK.B.E_FSPI_GPO = 1;
    L9388_Tx_Register.SERVFLTMSK.B.E_EN_GPO = 1;
    L9388_Tx_Register.SERVFLTMSK.B.E_FS_VDS_GPO = 1;
	L9388_SPI_Buffer.TxOut.B.Addr = SERVFLTMSK_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SERVFLTMSK.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.SERVFLTMSK.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_SERVFLTMSK(void)
{
	L9388_SPI_Buffer.TxOut.B.Addr = SERVFLTMSK_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.SERVFLTMSK.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.SERVFLTMSK.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_Pump_On_Off(bool On_Off_Switch)
{
	L9388_Tx_Register.GENCFG.B.PMP_EN = On_Off_Switch;
	L9388_SPI_Buffer.TxOut.B.Addr = GENCFG_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.GENCFG.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.GENCFG.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

float mysqrt(float n)
{
    float a,b,temp;
    b=n/2;
    a=(b+n/b)/2.0;
    while((b-a)>0.00001)
    {
        temp = a;
        a = (a+n/a)/2.0;
        b = temp;
    }
    return a;
}

void L9388_Pump_Config(uint16_t Period,uint8_t Dutycycle)
{
	L9388_Tx_Register.PUMPCFG.B.PUMP_TCK_PWM = (uint8_t)mysqrt((((float)Period)*10/62.5-10)/0.0245);

	if(Dutycycle<100)
	{
		L9388_Tx_Register.PUMPCFG.B.PUMP_DTY_PWM = Dutycycle;
	}
	else
	{
		L9388_Tx_Register.PUMPCFG.B.PUMP_DTY_PWM = 100;
	}
	L9388_SPI_Buffer.TxOut.B.Addr = PUMPCFG_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.PUMPCFG.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.PUMPCFG.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_WSICTRL_INIT(bool En_Disable_Flag)
{
	L9388_Tx_Register.WSICTRL.B.INIT = En_Disable_Flag;
	L9388_SPI_Buffer.TxOut.B.Addr = WSICTRL_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WSICTRL.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.WSICTRL.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Config_WSI_Type(uint8_t channel,uint8_t Sensor_Type)
{
	L9388_Tx_Register.WSIRSCR[channel].B.SENSOR_TYPE_SELECTION_CH1 = Sensor_Type;
	L9388_SPI_Buffer.TxOut.B.Addr = WSICTRL_ADDR;
	L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.WSICTRL.R;
	L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
	L9388_Rx_Register.WSICTRL.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_VDDFLT(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = VDDFLT_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.VDDFLT.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_VDD5FLT(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = VDDSTATUS_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.VDDSTATUS.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

float L9388_Read_Die_Temperature(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = TEMPSENS_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.TEMPSENS.R = L9388_SPI_Buffer.RxIn.B.DataRx;

    float Die_Temperature = (((float)L9388_Rx_Register.TEMPSENS.B.DIE_TEMP_MONITOR/255)*360) - 89;

    return Die_Temperature;
}

void L9388_Read_COMMUNICATION_FAULTS(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = COMMUNICATION_FAULTS_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.COMMUNICATION_FAULTS.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_PUMPDR(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = PUMPDR_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.PUMPDR.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_VSODR(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = VSODR_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.VSODR.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_RESOUTPUT(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = RESOUTPUT_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.RESOUTPUT.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Read_WLD1_SHLSDR(void)
{
    L9388_SPI_Buffer.TxOut.B.Addr = WLD1_SHLSDR_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 0;
    L9388_SPI_Buffer.TxOut.B.DATATx = 0;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.WLD1_SHLSDR.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}

void L9388_Set_VSOSER(void)
{
    L9388_Tx_Register.VSOSER.B.SEL_OUT_CMD = 1;
    L9388_Tx_Register.VSOSER.B.SEL_CONF = 0;
    L9388_Tx_Register.VSOSER.B.VSO_CONF = 0;
    L9388_SPI_Buffer.TxOut.B.Addr = VSOSER_ADDR;
    L9388_SPI_Buffer.TxOut.B.WRn = 1;
    L9388_SPI_Buffer.TxOut.B.DATATx = L9388_Tx_Register.VSOSER.R;
    L9388_SPI_ExchangeDataWithCRC(&L9388_SPI_Buffer);
    L9388_Rx_Register.VSOSER.R = L9388_SPI_Buffer.RxIn.B.DataRx;
}
