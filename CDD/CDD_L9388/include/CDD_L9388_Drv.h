#include "CDD_L9388_LLD.h"
#include "CDD_L9388_Cfg.h"

void L9388_Read_CHIPID(void);
void L9388_Read_GENSTATUS(void);
bool CDD_L9388_GENCFG_Cfg(void);
bool CDD_L9388_GENCFG2_Cfg(void);
void L9388_Set_NO_TC_PWM(uint16_t PWM_Code,uint8_t Channel);
void L9388_Read_NO_TC_PWM(uint8_t Channel);
void L9388_Set_ESV_PWM(uint16_t PWM_Code,uint8_t Channel);
void L9388_Read_ESV_PWM(uint8_t Channel);
void L9388_Set_NO_TC_Current(uint16_t Set_Point,uint8_t Channel);
void L9388_Read_NO_TC_Current(uint8_t Channel);
void L9388_Read_NO_TC_Exception(uint8_t Channel);
void L9388_Set_ESV_Current(uint16_t Set_Point,uint8_t Channel);
void L9388_Read_ESV_Current(uint8_t Channel);
void L9388_Read_ESV_Exception(uint8_t Channel);
void L9388_Set_SOLSERVENA(uint8_t channel,bool target);
void L9388_Set_SOLENDR(uint8_t channel, uint8_t mode);
void L9388_Read_SOLSERVENA(void);
void L9388_Read_SOLENDR(void);
void L9388_WD2_Read_WDG2STATUS(void);
void L9388_WD2_Read_Seed(void);
void L9388_WD2_Write_Answer(void);
bool CDD_L9388_WDG2STARTTMG_Cfg(void);
bool CDD_L9388_WDG2DELTATMG_Cfg(void);
bool CDD_L9388_WDG2TOUTTMG_Cfg(void);
bool CDD_L9388_WDG2PGM_Cfg(void);
void CDD_L9396_WDG2_Feeding_Service(void);
uint32_t CDD_L9388_Read_ADC(L9388_ADCType ADC_Channel);
void L9388_Set_ON_OFF(uint8_t channel,bool On_Off_Switch);
void L9388_Read_ON_OFF_diag(uint8_t channel);
void L9388_Set_SHLS(bool Low_High_Switch,bool On_Off_Switch);
void L9388_Set_Pump_On_Off(bool On_Off_Switch);
void L9388_Pump_Config(uint16_t Period,uint8_t Dutycycle);
void L9388_WSICTRL_INIT(bool En_Disable_Flag);
void L9388_Config_WSI_Type(uint8_t channel,uint8_t Sensor_Type);
void L9388_Read_VDDFLT(void);
void L9388_Read_VDD5FLT(void);
float L9388_Read_Die_Temperature(void);
void L9388_Read_COMMUNICATION_FAULTS(void);
void L9388_Read_PUMPDR(void);
void L9388_Read_VSODR(void);
void L9388_Read_RESOUTPUT(void);
void L9388_Set_VSOSER(void);
void L9388_Read_WLD1_SHLSDR(void);

#define WDG2_Idle_State 			0xEEU
#define WDG2_FirstSeedReq_State   0x55U
#define WDG2_Write_ANSW_State	    0x88U
#define WDG2_READ_SEED_State	    0xAAU

#define SOLENDR_PWM_MODE 0x0U
#define SOLENDR_FULL_ON_MODE 0x1U
