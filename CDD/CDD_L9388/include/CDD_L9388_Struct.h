/*SPI data format of MCU read and receive from L9388*/
typedef struct L9388_Data{
	union{
		uint32_t R;
		struct {
			uint32_t Tx_CRC :5;
            uint32_t DATATx:16;
            uint32_t FCNT:1;
            uint32_t RSVD:1;
            uint32_t Addr :8;
            uint32_t WRn :1;
		}B;
	}TxOut; /*MCU Send to L9388 through SPI bus*/
	union{
		uint32_t R;
		struct {
			uint32_t Rx_CRC :5;
            uint32_t DataRx : 16;
            uint32_t Addr_Feedback:8;
            uint32_t RSVD:2;
            uint32_t ShortFrameErr :1;
		}B;
	}RxIn;	/*MCU Read from L9388 through SPI bus*/

}L9388_Data_tag;

// typedef struct L9388_Data_tag L9388_Data_tag_t;

/*Address of L9388 register*/
#define CHIPID_ADDR                         0x00
#define GENCFG_ADDR 			            0x01
#define GENCFG2_ADDR 			            0x02
#define GENSTATUS_ADDR 			            0x03
#define TEMPSENS_ADDR 		                0x04
#define COMMUNICATION_FAULTS_ADDR 		    0x05
#define SERVTESTEN_ADDR 			        0x06
#define SERVTESTSTATUS_ADDR				    0x07
#define PUMPCFG_ADDR				        0x08
#define PUMPCFG2_ADDR				        0x09
#define PUMPDR_ADDR                         0x0A
#define VDDFLT_ADDR 			            0x0B
#define VDDSTATUS_ADDR 			            0x0C
#define ADC_DR_ADDR   			            0x0D
#define VSOSER_ADDR   		                0x0F
#define VSODR_ADDR 		                    0x10
#define WLD1_SHLS_CONFIG_ADDR 			    0x11
#define WLD1_SHLSDR_ADDR				    0x12
#define SERVFLTMSK_ADDR				        0x13
#define RESOUTPUT_ADDR				        0x14

#define SOLSERVENA_ADDR                     0x40
#define SOLENDR_ADDR                        0x41

#define WDG2SEED_ADDR                       0x48
#define WDG2STATUS_ADDR                     0x49
#define WDG2STARTTMG_ADDR                   0x4A
#define WDG2DELTATMG_ADDR                   0x4B
#define WDG2TOUTTMG_ADDR                    0x4C
#define WDG2PGM_ADDR                        0x4D
#define WDG2ANS_ADDR                        0x4E

#define FAULT_CH0_ADDR                      0x80
#define EXCEPTIONS_CH0_ADDR                 0x81
#define CONFIGURATION_CH0_ADDR              0x82
#define SETPOINT_CH0_ADDR                   0x85
#define CTRLCFG_CH0_ADDR                    0x86
#define FMODULATION_CH0_ADDR                0x87
#define KGAINS_CH0_ADDR                     0x88
#define OFFCMP_CH0_ADDR                     0x89
#define AVGCURR_CH0_ADDR                    0x8A
#define PWMSENSE_CH0_ADDR                   0x8C
#define BASE_DELTA_CURR_CH0_ADDR            0x8D
#define DELTA_CURR_CH0_ADDR                 0x8E

#define EXCEPTIONS_CH6_ADDR					0xE1
#define CONFIGURATION_CH6_ADDR				0xE2
#define SETPOINT_CH6_ADDR					0xE5
#define CTRLCFG_CH6_ADDR					0xE6
#define KGAINS_CH6_ADDR                     0xE8
#define OFFCMP_CH6_ADDR                     0xE9
#define AVGCURR_CH6_ADDR                    0xEA
#define PWMSENSE_CH6_ADDR                   0xEC

#define ON_OFF_CH_CONGIF_ADDR				0x43
#define ON_OFF_CH1_DR_ADDR					0x44

#define WSICTRL_ADDR						0x27

typedef enum
{
    WSI_SENSOR_TWO_LEVEL = 0,
	WSI_SENSOR_THREE_LEVEL = 1,
	WSI_SENSOR_TWO_EDGES,
	WSI_SENSOR_ONE_EDGE,
}L9388_WSI_Sensor_Type;

typedef enum
{
    ADC_ADCIN1_SEL_ADDR = 0,
    ADC_ADCIN2_SEL_ADDR = 1,
    ADC_ADCIN3_SEL_ADDR,
    ADC_ADCIN4_SEL_ADDR,
    ADC_WS1_SEL_ADDR,
    ADC_WS2_SEL_ADDR,
    ADC_WS3_SEL_ADDR,
    ADC_WS4_SEL_ADDR,
    ADC_VDD2_SEL_ADDR,
    ADC_VDD3_SEL_ADDR,
    ADC_VDD4_SEL_ADDR,
    ADC_VDD5_SEL_ADDR,
    ADC_VPWR_SEL_ADDR,
    ADC_FSD_SEL_ADDR
}L9388_ADCType;

/*Struct of L9388 SPI register*/
typedef struct CDD_L9388_Struct
{
    union
    {
        uint16_t R;
        struct
        {
            uint16_t CHIP_ID;
        }B;
    }CHIPID;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t VDD3_OVC_FLT_TIME:2;
            uint16_t VDD3_OVC_SD_RESTART_TIME:2;
            uint16_t VDD4_OVC_FLT_TIME:2;
            uint16_t VDD4_OVC_SD_RESTART_TIME:2;
            uint16_t OSC_SPR_SPECT_DIS:1;
            uint16_t PMP_EN:1;
            uint16_t FS_EN:1;
            uint16_t FS_CMD:1;
            uint16_t FS_VDS_TH:2;
            uint16_t PHOLD:1;
            uint16_t KA:1;
        }B;
    }GENCFG;
    
    union
    {
        uint16_t R;
        struct
        {
            uint16_t VDD2_DIS:1;
            uint16_t VDD5_DIS:1;
            uint16_t WD_DIS:1;
            uint16_t VDD1_DIODELOSS_FILT:1;
            uint16_t VDD2_5_AUTO_SWITCH_OFFLDO_MODE:1;
            uint16_t WD_SW_DIS:2;
            uint16_t DIS_TH:1;
            uint16_t FS_VDS_FIL:2;
            uint16_t :6;
        }B;
    }GENCFG2;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t OSC_STUCK_MON:1;
            uint16_t OSC_FRQ_MON:1;
            uint16_t OSC_SELF_TEST_RESULT:1;
            uint16_t T_SD_INT:1;
            uint16_t WDOG_TO:1;
            uint16_t CP_OV:1;
            uint16_t CP_UV:1;
            uint16_t FS_TURN_OFF_FAULT:1;
            uint16_t FS_TURN_ON_FAULT:1;
            uint16_t FS_VDS_FAULT:1;
            uint16_t FS_RVP_FAULT:1;
            uint16_t VHD_OV:1;
            uint16_t VPWR_OV:1;
            uint16_t VPWR_UV:1;
            uint16_t :2;
        }B;
    }GENSTATUS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t DIE_TEMP_MONITOR:8;
            uint16_t :8;
        }B;
    }TEMPSENS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t TOO_LONG:1;
            uint16_t TOO_SHORT:1;
            uint16_t WRONG_CRC:1;
            uint16_t WRONG_FCNT:1;
            uint16_t WRONG_ADD:1;
            uint16_t :4;
            uint16_t TOO_LONG_SPI_ERR:1;
            uint16_t TOO_SHORT_SPI_ERR:1;
            uint16_t WRONG_CRC_SPI_ERR:1;
            uint16_t :3;
        }B;
    }COMMUNICATION_FAULTS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t ANALOG_BIST_ENABLE:1;
            uint16_t CORE_BIST_ENABLE:1;
            uint16_t ANALOG_BIST2_ENABLE:1;
            uint16_t NVM_CRC_MASK:1;
            uint16_t :1;
            uint16_t NVM_DWN:1;
            uint16_t :10;
        }B;
    }SERVTESTEN;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t :4;
            uint16_t AN_TRIM_CRC_RESULT:1;
            uint16_t NVM_CRC_RESULT:1;
            uint16_t NVM_BUSY:1;
            uint16_t :9;
        }B;
    }SERVTESTSTATUS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PUMP_DTY_PWM:8;
            uint16_t PUMP_TCK_PWM:8;
        }B;
    }PUMPCFG;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PMP_VDS_TH:2;
            uint16_t PMP2_DIS:1;
            uint16_t PMP_VDS_FIL:3;
            uint16_t LDACT_DIS:1;
            uint16_t PMP1_ISINK:1;
            uint16_t PMP_DT:4;
            uint16_t PMP_TEST:1;
            uint16_t PMP_2T_CMD:1;
            uint16_t PMP_3T_CMD:1;
            uint16_t PMP_BIST_EN:1;
        }B;
    }PUMPCFG2;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PMP1_TURN_ON_FAULT:1;
            uint16_t PMP1_TURN_OFF_FAULT:1;
            uint16_t PMP2_TURN_ON_FAULT:1;
            uint16_t PMP2_TURN_OFF_FAULT:1;
            uint16_t PMP3_TURN_ON_FAULT:1;
            uint16_t PMP3_TURN_OFF_FAULT:1;
            uint16_t PMP_VDS_TURN_OFF_FAULT:1;
            uint16_t PMP1_VDS_FAULT:1;
            uint16_t PMP_FLYBACK_FAULT:1;
            uint16_t :1;
            uint16_t PMP_VDS_TEST:1;
            uint16_t :2;
            uint16_t PMP_BIST_STATUS:2;
            uint16_t :1;
        }B;
    }PUMPDR;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t VDD1_OUT_OF_REG:1;
            uint16_t VDD2_OUT_OF_REG:1;
            uint16_t VDD4_OVC:1;
            uint16_t VDD3_OVC:1;
            uint16_t VDD1_DIODELOSS_ECHO:1;
            uint16_t VDD2_REV_CURR:1;
            uint16_t VDD1_T_SD:1;
            uint16_t VDD2_T_SD:1;
            uint16_t VDD1_UV:1;
            uint16_t VDD2_UV:1;
            uint16_t VDD3_UV:1;
            uint16_t VDD4_UV:1;
            uint16_t VDD1_OV:1;
            uint16_t VDD2_OV:1;
            uint16_t VDD3_OV:1;
            uint16_t VDD4_OV:1;
        }B;
    }VDDFLT;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t VDD1_SEL_ECHO:1;
            uint16_t VDD2_SEL_ECHO:1;
            uint16_t :2;
            uint16_t VDD5_SEL_ECHO:1;
            uint16_t :7;
            uint16_t VDD5_OUT_OF_REG:1;
            uint16_t VDD5_T_SD:1;
            uint16_t VDD5_UV:1;
            uint16_t VDD5_OV:1;
        }B;
    }VDDSTATUS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t ADC_DATA_OUT:10;
            uint16_t ADC_SEL:4;
            uint16_t :1;
            uint16_t ADC_BUSY:1;
        }B;
    }ADC_DR;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t VSO_CONF:1;
            uint16_t :2;
            uint16_t SSIG_VSO:1;
            uint16_t VSO_PTEN:1;
            uint16_t VSO_OFF_DIAG_EN:1;
            uint16_t VSO_LS_CLAMP_DIS:1;
            uint16_t :1;
            uint16_t SEL_CONF:1;
            uint16_t WSO_SEL_S:2;
            uint16_t SSIG_SEL:1;
            uint16_t SEL_OUT_CMD:1;
            uint16_t SEL_OFF_DIAG_EN:1;
            uint16_t SEL_LS_CLAMP_DIS:1;
            uint16_t SEL_PTEN:1;
        }B;
    }VSOSER;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t :1;
            uint16_t VSO_T_SD:1;
            uint16_t VSO_OPENLOAD:1;
            uint16_t VSO_LVT:1;
            uint16_t VSO_VGS_LS_FAULT:1;
            uint16_t VSO_LS_CLAMP_ACT:1;
            uint16_t VSO_LS_OVC:1;
            uint16_t GND_LOSS:1;
            uint16_t :1;
            uint16_t SEL_T_SD:1;
            uint16_t SEL_OPENLOAD:1;
            uint16_t SEL_LVT:1;
            uint16_t SEL_VGS_LS_FAULT:1;
            uint16_t SEL_LS_CLAMP_ACT:1;
            uint16_t SEL_LS_OVC:1;
            uint16_t :1;
        }B;
    }VSODR;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WLD_CONF:1;
            uint16_t WLD_CMD:1;
            uint16_t WLD_DIAGOFF_EN:1;
            uint16_t WLD_LS_CLAMP_DIS:1;
            uint16_t :4;
            uint16_t SHLS_CMD:1;
            uint16_t SHLS_DIAGOFF_EN:1;
            uint16_t SHLS_CONFIG:1;
            uint16_t SHLS_LS_CLAMP_DIS:1;
            uint16_t :4;
        }B;
    }WLD1_SHLS_CONFIG;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WLD_T_SD:1;
            uint16_t WLD_OPL:1;
            uint16_t WLD_LVT:1;
            uint16_t WLD_LS_OVC:1;
            uint16_t WLD_VGS_LS_FAULT:1;
            uint16_t WLD_LS_CLAMP:1;
            uint16_t SHLS_T_SD:1;
            uint16_t SHLS_OPL:1;
            uint16_t SHLS_LVT:1;
            uint16_t SHLS_OVC:1;
            uint16_t SHLS_VGS_FAULT:1;
            uint16_t SHLS_LS_CLAMP:1;
        }B;
    }WLD1_SHLSDR;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t E_PVDS_GPO:1;
            uint16_t E_VDD2_5_WSx_OT_GPO:1;
            uint16_t E_FBO_GPO:1;
            uint16_t E_FSPI_GPO:1;
            uint16_t E_EN_GPO:1;
            uint16_t E_FS_VDS_GPO:1;
            uint16_t :10;
        }B;
    }SERVFLTMSK;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t EXT_RES1_ECHO:1;
            uint16_t VINTA_OV:1;
            uint16_t DGNDLOSS:1;
            uint16_t VINTA_UV:1;
            uint16_t PORN:1;
            uint16_t RES1_ECHO:1;
            uint16_t IGN_ECHO:1;
            uint16_t EN_DR_ECHO:1;
            uint16_t :8;
        }B;
    }RESOUTPUT;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WSO_TEST:1;
            uint16_t CONFIG_RANGE:7;
            uint16_t :8;
            
        }B;
    }WSITEST;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WSI_FIRST_THRESHOLD:8;
            uint16_t DELTA_FIRST_SEL:2;
            uint16_t :6;
        }B;
    }WSIAUXCONF;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WSI_OFFSET_THRESHOLD:8;
            uint16_t DELTA_SECOND_SEL:2;
            uint16_t :6;
        }B;
    }WSIAUXCONF2;

    struct
    {
        uint16_t R;
        struct {
            uint16_t SENSOR_TYPE_SELECTION_CH1:2;
            uint16_t READ_WSS_CURR_CH1:1;
            uint16_t FIX_TH_CH1:1;
            uint16_t SS_DIS_CH1:1;
            uint16_t PTEN_CH1:1;
            uint16_t FILTER_SELECTION_CH1:2;
            uint16_t :8;
        } B;
    }WSIRSCR[4];
    
    union {
        uint16_t R;
        struct {
            uint16_t CH1_DIS:1;
            uint16_t CH2_DIS:1;
            uint16_t CH3_DIS:1;
            uint16_t CH4_DIS:1;
            uint16_t DIAG:1;
            uint16_t INIT:1;
            uint16_t WSI_VDD4_UV:1;
            uint16_t FVPWR_ACT:1;
            uint16_t :8;
        } B;
    } WSICTRL;

    union {
        uint16_t R;
        struct {
            uint16_t WS_CNT_EN:10;
            uint16_t WS_CNT_RST:1;
            uint16_t :5;
        } B;
    } WSCOUNT[4];

    union {
        uint16_t R;
        struct {
            uint16_t WSI1_LBIST_EN:9;
            uint16_t WSI2_LBIST_EN:1;
            uint16_t WSI3_LBIST_EN:1;
            uint16_t WSI4_LBIST_EN:1;
            uint16_t WSI1_SELFTEST_RESULT:1;
            uint16_t WSI2_SELFTEST_RESULT:1;
            uint16_t WSI3_SELFTEST_RESULT:1;
            uint16_t WSI4_SELFTEST_RESULT:1;
        } B;
    } WSBIST;

    union {
        uint16_t R;
        struct {
            uint16_t LOW_THRESHOLD_CURRENT:10;
            uint16_t :6;
        } B;
    } WSIRSDR_1[4];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t HIGH_THRESHOLD_CURRENT:10;
            uint16_t :6;
        }B;
    }WSIRSDR_2[4];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WHEEL_SPEED_DECODER_DATA:12;
            uint16_t LATCH_D0:1;
            uint16_t STANDSTILL:1;
            uint16_t PTY_BIT:1;
        }B;
    }WSIRSDR_3[4];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t BASE_CURRENT_SENS_CURRENT:3;
            uint16_t LOGIC_CH_ID:3;
            uint16_t :3;
        }B;
    }WSIRSDR_4[4];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PULSE_OVERFLOW:1;
            uint16_t NODATA:1;
            uint16_t INVALID:1;
            uint16_t WSI_OT:1;
            uint16_t OPEN:1;
            uint16_t CURRENT_HI:1;
            uint16_t STB:1;
            uint16_t STG:1;
            uint16_t ON_OFF:1;
            uint16_t WSIRSDR1_4_1:1;
            uint16_t :1;
        }B;
    }WSIRSDR_5[4];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t SOLENOID_ENABLE:8;
            uint16_t :8;
        }B;
    }SOLSERVENA;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t CH0_STATUS:2;
            uint16_t CH1_STATUS:2;
            uint16_t CH2_STATUS:2;
            uint16_t CH3_STATUS:2;
            uint16_t CH4_STATUS:2;
            uint16_t CH5_STATUS:2;
            uint16_t CH6_STATUS:2;
            uint16_t CH7_STATUS:2;
        }B;
    }SOLENDR;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t CH1_DIAG_EN:1;
            uint16_t CH1_TD_BLANK:1;
            uint16_t CH2_DIAG_EN:1;
            uint16_t CH2_TD_BLANK:1;
            uint16_t CH3_DIAG_EN:1;
            uint16_t CH3_TD_BLANK:1;
            uint16_t CH4_DIAG_EN:1;
            uint16_t CH4_TD_BLANK:1;
            uint16_t CH1_EN:1;
            uint16_t CH2_EN:1;
            uint16_t CH3_EN:1;
            uint16_t CH4_EN:1;
            uint16_t CH1_CMD:1;
            uint16_t CH2_CMD:1;
            uint16_t CH3_CMD:1;
            uint16_t CH4_CMD:1;
        } B;
    } ON_OFF_CH_CONFIG;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t TH_WARN:1;
            uint16_t T_SD:1;
            uint16_t UNDER_CURR:1;
            uint16_t OPL:1;
            uint16_t LVT:1;
            uint16_t GND_LOSS:1;
            uint16_t VGS_LS_FAULT:1;
            uint16_t LS_OVC:1;
            uint16_t LS_CLAMP:1;
            uint16_t :7;
        }B;
    }ON_OFF_CH_DR[4];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t SEED:8;
            uint16_t :8;
        }B;
    }WDG2SEED;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t WD_CNT_VALUE:4;
            uint16_t WD_EARLY_ANSW:1;
            uint16_t WD_LATE_ANSW:1;
            uint16_t WD_BAD_ANSW:1;
            uint16_t WD_EARLY_REQ:1;
            uint16_t WD_LATE_REQ:1;
            uint16_t WD_RST_TO_ANSW:1;
            uint16_t WD_RST_TO_REQ:1;
            uint16_t WD_RST_CNT:1;
            uint16_t WD_RST_EVENT_VALUE:4;
        }B;
    }WDG2STATUS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t VALID_ANSWER_START:8;
            uint16_t VALID_REQUEST_START:8;
        }B;
    }WDG2STARTTMG;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t VALID_ANSWER_DELTA:6;
            uint16_t :2;
            uint16_t VALID_REQUEST_DELTA:6;
            uint16_t REQ_CHECK_ENABLE:1;
            uint16_t :1;
        }B;
    }WDG2DELTATMG;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t ANSWER_TIME_OUT_DELTA:6;
	        uint16_t :2;
            uint16_t REQUEST_TIME_OUT_DELTA:6;
            uint16_t TO_RESET_ENABLE:1;
            uint16_t :1;
        }B;
    }WDG2TOUTTMG;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t GOOD_STEPS:3;
            uint16_t BAD_STEPS:3;
            uint16_t HIGH_TH:4;
            uint16_t LOW_TH:4;
            uint16_t CLOCK_DIVISION:1;
            uint16_t RESET_ENABLE:1;
        }B;
    }WDG2PGM;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t ANSWER_LOW:8;
            uint16_t ANSWER_HIGH:8;
        }B;
    }WDG2ANS;

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PWM_FAULT:1;
            uint16_t CURR_SENSE_FAULT:1;
            uint16_t ADC_FAULT:1;
            uint16_t LOGIC_BIST_STATUS:2;
            uint16_t :9;
        }B;
    }CHX_FAULT[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t LS_CLAMP_ON:1;
            uint16_t LS_OVC:1;
            uint16_t VGS_LS_FAULT:1;
            uint16_t VGS_HS_FAULT:1;
            uint16_t HS_SHORT:1;
            uint16_t LVT:1;
            uint16_t OPEN_LOAD:1;
            uint16_t GND_LOSS:1;
            uint16_t TH_WARN:1;
            uint16_t T_SD:1;
            uint16_t :5;
        }B;
    }EXCEPTIONS_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t SR_SEL:2;
            uint16_t CALIBRATION_DIS:3;
            uint16_t OFS_CHOP_DIS:1;
            uint16_t TD_BLANK_SEL:1;
            uint16_t LS_CLAMP_DIS:1;
            uint16_t LOGIC_BIST_EN:1;
            uint16_t DIAG_BIST_EN:1;
            uint16_t ADC_BIST_EN:1;
            uint16_t OFF_DIAG_EN:1;
            uint16_t E_SOL_GPO:1;
            uint16_t E_LSCLAMP_GPO:1;
            uint16_t :2;
        }B;
    }CONFIGURATION_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t SET_POINT:11;
            uint16_t :5;
        }B;
    }SETPOINT_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PWM_CODE:10;
            uint16_t :6;
        }B;
    }CTRLCFG_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t MAX_FREQ_DELTA:8;
            uint16_t FREQ_MOD_STEP:7;
            uint16_t :1;
        }B;
    }FMODULATION_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t Kp:3;
            uint16_t Ki:3;
            uint16_t :10;
        }B;
    }KGAINS_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t INTTIME:2;
            uint16_t FILT_TIME:2;
            uint16_t CHOP_TIME:1;
            uint16_t :11;
        }B;
    }OFFCMP_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t AVG_CURRENT:12;
            uint16_t :4;
        }B;
    }AVGCURR_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PWM_CODE:13;
            uint16_t TMOUT:1;
            uint16_t :2;
        }B;
    }PWMSENSE_CHX[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t BASE_DELTA_CURENT:8;
            uint16_t :8;
        }B;
    }BASE_DELTA_CURR[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t DELTA_CURRENT:8;
            uint16_t :8;
        }B;
    }DELTA_CURR[6];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t LS_CLAMP_ON:1;
            uint16_t LS_OVC:1;
            uint16_t VGS_LS_FAULT:1;
            uint16_t VGS_HS_FAULT:1;
            uint16_t HS_SHORT:1;
            uint16_t LVT:1;
            uint16_t OPEN_LOAD:1;
            uint16_t GND_LOSS:1;
            uint16_t TH_WARN:1;
            uint16_t T_SD:1;
            uint16_t ADC_FAULT:3;
            uint16_t LOGIC_BIST_STATUS:2;
        }B;
    }EXCEPTIONS_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t SR_SEL:2;
            uint16_t CALIBRATION_DIS:3;
            uint16_t OFS_CHOP_DIS:1;
            uint16_t TD_BLANK_SEL:1;
            uint16_t LS_CLAMP_DIS:1;
            uint16_t LOGIC_BIST_EN:1;
            uint16_t DIAG_BIST_EN:1;
            uint16_t ADC_BIST_EN:1;
            uint16_t OFF_DIAG_EN:1;
            uint16_t E_SOL_GPO:1;
            uint16_t E_LSCLAMP_GPO:1;
            uint16_t :2;
        }B;
    }CONFIGURATION_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t SET_POINT:11;
            uint16_t :5;
        }B;
    }SETPOINT_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PWM_CODE:6;
            uint16_t FREQ_MOD_STEP:4;
            uint16_t MAX_FREQ_DELTA:5;
            uint16_t :1;
        }B;
    }CTRLCFG_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t Kp:3;
            uint16_t Ki:3;
            uint16_t :10;
        }B;
    }KGAINS_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t INTTIME:2;
            uint16_t FILT_TIME:2;
            uint16_t CHOP_TIME:1;
            uint16_t :11;
        }B;
    }OFFCMP_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t AVG_CURRENT:11;
            uint16_t :5;
        }B;
    }AVGCURR_CH6_7[2];

    union
    {
        uint16_t R;
        struct
        {
            uint16_t PWM_CODE:12;
            uint16_t TMOUT:1;
            uint16_t :3;
        }B;
    }PWMSENSE_CH6_7[2];

}CDD_L9388_Struct_tag;


