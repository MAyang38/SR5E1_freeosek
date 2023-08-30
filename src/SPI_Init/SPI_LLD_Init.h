#include <test_env.h>
#include <dma.h>
#include <spi.h>
#include <gpio.h>

/*===========================================================================*/
/* SPI-related.                                                              */
/*===========================================================================*/
#define SPI_BUFFER_SIZE      4U

#define SPI_NSS_GPIO_SLAVE       gpio_iopack(GPIO_PORT_E, GPIO_PIN_8)

/* Slave select gpio configuration.*/
#define SPI_NSS_GPIO_SLAVE_CFG                   \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_PULLUP |                    \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

void SPI_LLD_Init(void);