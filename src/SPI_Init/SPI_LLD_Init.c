#include "SPI_LLD_Init.h"

volatile uint8_t spi_master_completed = 0U;

/* This callback is invoked when SPI Master data trasferring is completed.*/
static void spi_master_data_cb(spi_driver_t *spd) {

    (void)spd;

    /* Set spi_master_completed to indicate SPI Master data transferring is
       completed.*/
    spi_master_completed = 1;
}

/* This callback is not used, it is here as an example.*/
static void spi_master_err_cb(spi_driver_t *spd) {

    (void)spd;
}


    /*===========================================================================*/
    /* SPI-Init-related.                                                              */
    /*===========================================================================*/
void SPI_LLD_Init(void)
{
    /* Configure slave select GPIOs.*/
    gpio_set_pin_mode(SPI_NSS_GPIO_SLAVE, SPI_NSS_GPIO_SLAVE_CFG);

    /* Set GPIOs used for slave selection to guarantee all slaves are init ially
            deselected.*/
    gpio_set_pin(SPI_NSS_GPIO_SLAVE);

    spi_dma_conf_t spi_master_dma_conf;

    /* Configure SPI Master DMA.*/
    spi_master_dma_conf.dma_stream_tx_id = DMA1_STREAM0_ID;
    spi_master_dma_conf.dma_stream_rx_id = DMA1_STREAM1_ID;
    spi_master_dma_conf.dma_stream_bus_prio = DMA_PRIORITY_MAX;
    spi_master_dma_conf.dma_stream_irq_prio = IRQ_PRIORITY_10;

    /* Initialize SPI Master driver instance.*/
    spi_init(&MASTER_SPID);

    /* Configure SPI Master driver instance.*/
    (void)spi_set_prio(&MASTER_SPID, IRQ_PRIORITY_10);
    (void)spi_set_drv_mode(&MASTER_SPID, SPI_DRV_MODE_DMA_SYNC);
    (void)spi_set_dma_conf(&MASTER_SPID, &spi_master_dma_conf);
    (void)spi_set_mode(&MASTER_SPID, SPI_MODE_MASTER);
    (void)spi_set_baud(&MASTER_SPID, SPI_BAUDRATE_DIV256);
    (void)spi_set_cpol(&MASTER_SPID, SPI_CPOL_0);
    (void)spi_set_cpha(&MASTER_SPID, SPI_CPHA_1);
    (void)spi_set_fformat(&MASTER_SPID, SPI_FRAMEFORMAT_MSB);
    (void)spi_set_fsize(&MASTER_SPID, SPI_FRAMESIZE_8);
    (void)spi_set_cb(&MASTER_SPID, SPI_CB_OPS_DONE, spi_master_data_cb);
    (void)spi_set_cb(&MASTER_SPID, SPI_CB_OPS_ERR, spi_master_err_cb);
    (void)spi_set_nss_mode(&MASTER_SPID, SPI_NSS_MODE_SOFTWARE);

    /* Apply SPI Master driver instance configuration.*/
    spi_start(&MASTER_SPID);

    (void)spi_set_nss_gpio(&MASTER_SPID, SPI_NSS_GPIO_SLAVE);

}
