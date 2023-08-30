#include "CDD_L9388_LLD.h"
/*SPI-GLOBAL_DATA*/
uint8_t L9388_tx_buffer[L9388_SPI_BUFFER_SIZE] = {0x00,0x00,0x00,0x00};
uint8_t L9388_rx_buffer[L9388_SPI_BUFFER_SIZE] = {0x00,0x00,0x00,0x00};;

L9388_Data_tag L9388_SPI_Buffer;

/***************************************************
Description:
example
InputWord: 32bits data need to add 5bit lower crc
		data returned is 32bit with lower 3bit lower crc
return :5bits crc


***************************************************/
void L9388_CrcCompute(L9388_Data_tag* InputWord)
{

	/*data exchange*/
	uint32_t init_value;
	uint32_t init_value_bit0_20;
	uint32_t init_value_bit22_31;
	init_value = ((~InputWord->TxOut.R ) & 0xF8000000);
	init_value |= (InputWord->TxOut.R & 0x07FFFFFF);
	init_value_bit0_20 = (init_value & 0x001FFFFF);
	init_value_bit22_31 = (init_value & 0xFFD00000)>>22;
	init_value = (init_value_bit22_31 << 21) | init_value_bit0_20;
	init_value &= 0xFFFFFFE0;

	/*CRC-calculator*/
	uint8_t i;
	for(i=0;i<27;i++)
	{
		if((init_value & 0x80000000) != 0)
		{
			init_value ^= ((uint32_t)L9388_CRC_POLY_VALUE << 26);
			init_value <<= 1;
		}
		else
		{
			init_value <<= 1;	
		}
	}

	InputWord->TxOut.B.Tx_CRC = ((init_value >> 27) & 0x1F);

}

/***************************************************
Description:
example
InputWord: 32bits data need to add 5bit lower crc
		data returned is 32bit with lower 3bit lower crc
return :5bits crc


***************************************************/

void L9388_Fill_SPI_Tx_Buffer(L9388_Data_tag* ulSPIOutWithCRC)
{
	L9388_tx_buffer[3] = (uint8_t)(ulSPIOutWithCRC->TxOut.R&0xFF);
    L9388_tx_buffer[2] = (uint8_t)(ulSPIOutWithCRC->TxOut.R>>8&0xFF);
    L9388_tx_buffer[1] = (uint8_t)(ulSPIOutWithCRC->TxOut.R>>16&0xFF);
    L9388_tx_buffer[0] = (uint8_t)(ulSPIOutWithCRC->TxOut.R>>24&0xFF);
}

/****************************************************************************
* Name:    SPI_ExDataWithCRC
* Parameters:
*              ulSPIOutNoCRC
* Returns:
*              none
* Description:		Exchange data from register.
*
* ****************************************************************************/
void L9388_SPI_ExchangeDataWithCRC(L9388_Data_tag* ulSPIOutNoCRC){

	/*Calculate Crc*/
	L9388_CrcCompute(ulSPIOutNoCRC);
	
    /*Fill SPI Tx buffer*/
	L9388_Fill_SPI_Tx_Buffer(ulSPIOutNoCRC);

    /*SPI polled exchange*/
    spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);

    /*Fill SPI receive message*/
    ulSPIOutNoCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));

	if((ulSPIOutNoCRC->RxIn.B.ShortFrameErr)&&(ulSPIOutNoCRC->RxIn.B.DataRx=0x1000))
	{
		Wrong_FCNT_Handler(ulSPIOutNoCRC);
	}
	// else
	// {
		/*Flip FCNT*/
		ulSPIOutNoCRC->TxOut.B.FCNT ^= 1;
	// }

	/*Set R/W to Read*/
	ulSPIOutNoCRC->TxOut.B.WRn = 0;

	/*Calculate Crc with update message*/
	L9388_CrcCompute(ulSPIOutNoCRC);

    /*Fill SPI Tx buffer*/
	L9388_Fill_SPI_Tx_Buffer(ulSPIOutNoCRC);

    /*SPI polled exchange*/
	spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);

    /*Fill SPI receive message*/
    ulSPIOutNoCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));

	if((ulSPIOutNoCRC->RxIn.B.ShortFrameErr)&&(ulSPIOutNoCRC->RxIn.B.DataRx=0x1000))
	{
		Wrong_FCNT_Handler(ulSPIOutNoCRC);
	}
	// else
	// {
		/*Flip FCNT*/
		ulSPIOutNoCRC->TxOut.B.FCNT ^= 1;
	// }

}

/****************************************************************************
* Name:    SPI_WRDataWithCRC
* Parameters:
*              ulSPIOutNoCRC
* Returns:
*              none
* Description:		Write data into register but not read back.
*
* ****************************************************************************/
void L9388_SPI_WRDataWithCRC(L9388_Data_tag* ulSPIOutNoCRC){

	/*Calculate Crc*/
	L9388_CrcCompute(ulSPIOutNoCRC);
	
    /*Fill SPI Tx buffer*/
	L9388_Fill_SPI_Tx_Buffer(ulSPIOutNoCRC);

    /*SPI polled exchange*/
    spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);

    /*Fill SPI receive message*/
    ulSPIOutNoCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));

	if((ulSPIOutNoCRC->RxIn.B.ShortFrameErr)&&(ulSPIOutNoCRC->RxIn.B.DataRx=0x1000))
	{
		Wrong_FCNT_Handler(ulSPIOutNoCRC);
	}
	// else
	// {
		ulSPIOutNoCRC->TxOut.B.FCNT ^= 1;
	// }
}

/****************************************************************************
* Name:    SPI_RDDataWithCRC
* Parameters:
*              ulSPIOutNoCRC
* Returns:
*              none
* Description:		Write data into register but not read back.
*
* ****************************************************************************/
void L9388_SPI_RDDataWithCRC(L9388_Data_tag* ulSPIOutNoCRC){

	/*Calculate Crc*/
	L9388_CrcCompute(ulSPIOutNoCRC);
	
    /*Fill SPI Tx buffer*/
	L9388_Fill_SPI_Tx_Buffer(ulSPIOutNoCRC);

    /*SPI polled exchange*/
    spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);

    /*Fill SPI receive message*/
    ulSPIOutNoCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));

	if((ulSPIOutNoCRC->RxIn.B.ShortFrameErr)&&(ulSPIOutNoCRC->RxIn.B.DataRx=0x1000))
	{
		Wrong_FCNT_Handler(ulSPIOutNoCRC);
	}
	// else
	// {
		ulSPIOutNoCRC->TxOut.B.FCNT ^= 1;
	// }

	/*Fill SPI receive message*/
    ulSPIOutNoCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));
}

void Wrong_FCNT_Handler(L9388_Data_tag* ulSPIOutWithCRC)
{

	/*Set R/W to Read*/
	ulSPIOutWithCRC->TxOut.B.WRn = 0;

	/*Calculate Crc with update message*/
	L9388_CrcCompute(ulSPIOutWithCRC);

    /*Fill SPI Tx buffer*/
	L9388_Fill_SPI_Tx_Buffer(ulSPIOutWithCRC);

    /*SPI polled exchange*/
	spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);

	/*Flip FCNT*/
	L9388_SPI_Buffer.TxOut.B.FCNT ^= 1;
	
	/*Calculate Crc with update message*/
	L9388_CrcCompute(ulSPIOutWithCRC);

    /*Fill SPI Tx buffer*/
	L9388_Fill_SPI_Tx_Buffer(ulSPIOutWithCRC);

    /*SPI polled exchange*/
	spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);
	ulSPIOutWithCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));

	while((ulSPIOutWithCRC->RxIn.B.ShortFrameErr)&&(ulSPIOutWithCRC->RxIn.B.DataRx=0x1000))
	{
		/*Flip FCNT*/
		ulSPIOutWithCRC->TxOut.B.FCNT ^= 1;
		
		/*Calculate Crc with update message*/
		L9388_CrcCompute(ulSPIOutWithCRC);

		/*Fill SPI Tx buffer*/
		L9388_Fill_SPI_Tx_Buffer(ulSPIOutWithCRC);

		/*SPI polled exchange*/
		spi_exchange(&MASTER_SPID, (uint8_t *)L9388_tx_buffer, (uint8_t *)L9388_rx_buffer, L9388_SPI_BUFFER_SIZE);

		ulSPIOutWithCRC->RxIn.R = ((L9388_rx_buffer[0]<<24)|(L9388_rx_buffer[1]<<16)|(L9388_rx_buffer[2]<<8)|(L9388_rx_buffer[3]));

	}
}
