/****************************************************************************
 *
 * Copyright (c) 2022 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    io.c
 * @brief   Runtime IO module source file.
 *
 * @addtogroup RUNTIME
 * @addtogroup IO
 * @ingroup RUNTIME
 * @{
 */

#include <io.h>

#include <stdio.h>
#include <errno.h>
#include <stdint.h>

#if defined(__clang__)
#include <sys/types.h>
#endif

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

#if defined(__clang__)
#define ssize_t _ssize_t
#elif defined(__ICCARM__) || defined(__ghs__)
#define ssize_t size_t
#endif

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/** @brief   Pointer to the UART driver used for IO redirection. */
static uart_driver_t *io_udp = NULL;

#if defined(__clang__)
char ** environ;
#endif

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

ssize_t _write(int fd, void *buf, size_t count);
ssize_t _read(int fd, void *buf, size_t count);
#if !defined(__ICCARM__)
void *_sbrk(intptr_t increment);
#endif
#if defined(__clang__)
ssize_t write(int fd, void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
void *sbrk(intptr_t size);
int open(const char *pathname, int flags);
int close(int fd);
void _exit (int status);
int remove (const char * pathname);
#endif
#if defined(__ICCARM__)
ssize_t __write(int fd, void *buf, size_t count);
ssize_t __read(int fd, void *buf, size_t count);
#endif
#if defined(__ghs__)
ssize_t write(int fd, void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
void *sbrk(intptr_t size);
int open(const char *pathname, int flags);
#endif

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void io_init(uart_driver_t *udp)
{
#if defined(__ghs__)
    FILE *new_stdout;
    FILE *new_stderr;
    FILE *new_stdin;

    /* Set streams to avoid bad IO file descriptor */
    new_stdout = freopen("uart", "w", stdout);
    if (new_stdout) {
        setvbuf(new_stdout, NULL, _IONBF, 0);
    }

    new_stderr = freopen("uart", "w", stderr);
    if (new_stderr) {
        setvbuf(new_stderr, NULL, _IONBF, 0);
    }

    new_stdin = freopen("uart", "r", stdin);
    if (new_stdin) {
        setvbuf(new_stdin, NULL, _IONBF, 0);
    }
#elif !defined(__ICCARM__)
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    setbuf(stdin, NULL);
#endif

    if (io_udp == NULL) {
        io_udp = udp;
    }
}

void io_start(void)
{
    if (io_udp != NULL) {
        /* Configure UART used for IO redirection in interrupt synchronous
           mode.*/
        (void)uart_set_rx_drv_mode(io_udp, UART_RX_DRV_MODE_INT_SYNC);
        (void)uart_set_tx_drv_mode(io_udp, UART_TX_DRV_MODE_INT_SYNC);

        /* Start operation on UART used for IO redirection */
        uart_start(io_udp);
    }
}

uart_driver_t* io_getptr(void) 
{
    /* Return pointer to uart_driver_t used for IO redirection or NULL if no
       UART has been selected.*/
    return io_udp;
}

void io_stop(void)
{
    if (io_udp != NULL) {
        /* Stop operation on UART used for IO redirection */
        uart_stop(io_udp);
    }
}

void io_deinit(void)
{
    if (io_udp != NULL) {
        /* Deinitialize the UART used for IO redirection */
        uart_deinit(io_udp);
    }
    io_udp = NULL;
}

/**
 * @brief   Write to IO.
 * @note    This function redirect IO write on UART.
 * @details Write up to count bytes from buffer buf to the file related to the
 *          file descriptor fd.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer from which to write
 * @param[in] count         number of bytes to be written
 * @return                  number of written bytes.
 *
 * @special
 */
ssize_t _write(int fd, void *buf, size_t count)
{
    size_t trasmitted = 0;

    (void)fd;

    if (io_udp != NULL) {
        trasmitted = uart_write(io_udp, (uint8_t *)buf, count);
    }

    return ((ssize_t)(trasmitted));
}

/**
 * @brief   Read from IO.
 * @note    This function redirect IO read on UART.
 * @details Attempt to read up to count bytes from the file related to the file
 *          descriptor fd into the buffer buf.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer in which the read data are stored
 * @param[in] count         number of bytes to be read
 * @return                  number of read bytes.
 *
 * @special
 */
ssize_t _read(int fd, void *buf, size_t count)
{
    size_t received = 0;

    (void)fd;

    if (io_udp != NULL) {
        received = uart_read(io_udp, (uint8_t *)buf, count);
    }

    return ((ssize_t)(received));
}

#if !defined(__ICCARM__)
/**
 * @brief   Increment location of program break.
 * @details This function allows to increase the program break. The result is
 *          to allocate memory to the process.
 *
 * @param[in] increment     number of bytes to increment
 * @return                  previuos program break.
 *
 * @special
 */
void *_sbrk(intptr_t increment)
{
    /*
     * Using external symbols:
     *   __heap_base__ : is placed at the beginning of the heap chunk
     *   __heap_end__  : is placed at the end of available heap chunk
     *
     * For definition of __heap_base__ and __heap_end__,
     * see linker script file.
     *
     * Limitation:
     *   multiple heap chunks not handled
     *   re-entrance (multi-threading) not handled
     */
    extern uint8_t __heap_base__;
    extern uint8_t __heap_end__;

    static uint8_t *heap_base = &__heap_base__;
    uint8_t *prev_head_base;

    prev_head_base = heap_base;
    if ((heap_base + increment) > (uint8_t*) &__heap_end__) {
        /* not enough memory, set errno and return -1 */
        errno = ENOMEM;
        return (void *) -1;
    }

    /* enough memory, increment heap base */
    heap_base += increment;

    /* return prior head base */
    return prev_head_base;
}
#endif

#if defined(__clang__)
/**
 * @brief   Write to IO.
 * @details Write up to count bytes from buffer buf to the file related to the
 *          file descriptor fd.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer from which to write
 * @param[in] count         number of bytes to be written
 * @return                  number of written bytes.
 *
 * @special
 */
ssize_t write(int fd, void *buf, size_t count)
{
    return _write(fd, buf, count);
}

/**
 * @brief   Read from IO.
 * @details Attempt to read up to count bytes from the file related to the file
 *          descriptor fd into the buffer buf.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer in which the read data are stored
 * @param[in] count         number of bytes to be read
 * @return                  number of read bytes.
 *
 * @special
 */
ssize_t read(int fd, void *buf, size_t count)
{
    return _read(fd, buf, count);
}

/**
 * @brief   Increment location of program break.
 * @details This function allows to increase the program break. The result is
 *          to allocate memory to the process.
 *
 * @param[in] increment     number of bytes to increment
 * @return                  previuos program break.
 *
 * @special
 */
void *sbrk(intptr_t size)
{
    return _sbrk(size);
}

/**
 * @brief   Open a file.
 * @details Open the file specified by pathname. 
 *
 * @param[in] pathname      pathname of file to open
 * @param[in] flags         file access mode
 * @return                  file descriptor.
 *
 * @special
 */
int open(const char *pathname, int flags)
{
    (void) (pathname);
    (void) (flags);

    /*
     * Nothing to do, just return success.
     */
    return 0;
}

/**
 * @brief   Close a file.
 *
 * @param[in] fd            file descriptor
 * @return                  0 if no error occurs, -1 otherwise
 *
 * @special
 */
int close(int fd)
{
    (void) (fd);

    /*
     * Nothing to do, just return success.
     */
    return 0;
}

/**
 * @brief   Cause normal process termination.
 *
 * @param[in] status        status returned to the parent process
 *
 * @special
 */
void _exit(int status)
{
    (void) (status);

    /*
     * Nothing to do.
     */
    while(1);
}

/**
 * @brief   Remove a file. 
 *
 * @param[in] pathname      pathname of file to remove
 * @return                  0 if no error occurs, -1 otherwise
 *
 * @special
 */
int remove(const char * pathname)
{
    (void) (pathname);

    /*
     * Nothing to do, just return success.
     */
    return 0;
}
#endif

#if defined(__ICCARM__)
/**
 * @brief   Write to IO.
 * @details Write up to count bytes from buffer buf to the file related to the
 *          file descriptor fd.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer from which to write
 * @param[in] count         number of bytes to be written
 * @return                  number of written bytes.
 *
 * @special
 */
ssize_t __write(int fd, void *buf, size_t count)
{
    return _write(fd, buf, count);
}

/**
 * @brief   Read from IO.
 * @details Attempt to read up to count bytes from the file related to the file
 *          descriptor fd into the buffer buf.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer in which the read data are stored
 * @param[in] count         number of bytes to be read
 * @return                  number of read bytes.
 *
 * @special
 */
ssize_t __read(int fd, void *buf, size_t count)
{
    return _read(fd, buf, count);
}
#endif

#if defined(__ghs__)
/**
 * @brief   Write to IO.
 * @details Write up to count bytes from buffer buf to the file related to the
 *          file descriptor fd.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer from which to write
 * @param[in] count         number of bytes to be written
 * @return                  number of written bytes.
 *
 * @special
 */
ssize_t write(int fd, void *buf, size_t count)
{
    return _write(fd, buf, count);
}

/**
 * @brief   Read from IO.
 * @details Attempt to read up to count bytes from the file related to the file
 *          descriptor fd into the buffer buf.
 *
 * @param[in] fd            file descriptor
 * @param[in] buf           buffer in which the read data are stored
 * @param[in] count         number of bytes to be read
 * @return                  number of read bytes.
 *
 * @special
 */
ssize_t read(int fd, void *buf, size_t count)
{
    return _read(fd, buf, count);
}

/**
 * @brief   Increment location of program break.
 * @details This function allows to increase the program break. The result is
 *          to allocate memory to the process.
 *
 * @param[in] increment     number of bytes to increment
 * @return                  previuos program break.
 *
 * @special
 */
void *sbrk(intptr_t size)
{
    return _sbrk(size);
}

/**
 * @brief   Open a file.
 * @details Open the file specified by pathname. 
 *
 * @param[in] pathname      pathname of file to open
 * @param[in] flags         file access mode
 * @return                  file descriptor.
 *
 * @special
 */
int open(const char *pathname, int flags)
{
    (void) (pathname);
    (void) (flags);

    /*
     * Nothing to do, just return success.
     */
    return 0;
}

#endif

/** @} */
