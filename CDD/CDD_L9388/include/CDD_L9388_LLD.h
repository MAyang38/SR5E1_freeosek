#include <test_env.h>
#include "CDD_L9388_Struct.h"
#include "SPI_LLD_Init.h"
#define L9388_SPI_BUFFER_SIZE 4

#define L9388_CRC_POLY_VALUE 0x25

extern L9388_Data_tag L9388_SPI_Buffer;

void L9388_CrcCompute(L9388_Data_tag *InputWord);
void L9388_SPI_ExchangeDataWithCRC(L9388_Data_tag *ulSPIOutNoCRC);
void L9388_SPI_WRDataWithCRC(L9388_Data_tag *ulSPIOutNoCRC);
void L9388_SPI_RDDataWithCRC(L9388_Data_tag *ulSPIOutNoCRC);
void Wrong_FCNT_Handler(L9388_Data_tag *ulSPIOutWithCRC);
