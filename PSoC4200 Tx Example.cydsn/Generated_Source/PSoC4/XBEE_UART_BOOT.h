/***************************************************************************//**
* \file XBEE_UART_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_XBEE_UART_H)
#define CY_SCB_BOOT_XBEE_UART_H

#include "XBEE_UART_PVT.h"

#if (XBEE_UART_SCB_MODE_I2C_INC)
    #include "XBEE_UART_I2C.h"
#endif /* (XBEE_UART_SCB_MODE_I2C_INC) */

#if (XBEE_UART_SCB_MODE_EZI2C_INC)
    #include "XBEE_UART_EZI2C.h"
#endif /* (XBEE_UART_SCB_MODE_EZI2C_INC) */

#if (XBEE_UART_SCB_MODE_SPI_INC || XBEE_UART_SCB_MODE_UART_INC)
    #include "XBEE_UART_SPI_UART.h"
#endif /* (XBEE_UART_SCB_MODE_SPI_INC || XBEE_UART_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define XBEE_UART_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBEE_UART) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (XBEE_UART_SCB_MODE_I2C_INC)
    #define XBEE_UART_I2C_BTLDR_COMM_ENABLED     (XBEE_UART_BTLDR_COMM_ENABLED && \
                                                            (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             XBEE_UART_I2C_SLAVE_CONST))
#else
     #define XBEE_UART_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (XBEE_UART_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (XBEE_UART_SCB_MODE_EZI2C_INC)
    #define XBEE_UART_EZI2C_BTLDR_COMM_ENABLED   (XBEE_UART_BTLDR_COMM_ENABLED && \
                                                         XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define XBEE_UART_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (XBEE_UART_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (XBEE_UART_SCB_MODE_SPI_INC)
    #define XBEE_UART_SPI_BTLDR_COMM_ENABLED     (XBEE_UART_BTLDR_COMM_ENABLED && \
                                                            (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             XBEE_UART_SPI_SLAVE_CONST))
#else
        #define XBEE_UART_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (XBEE_UART_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (XBEE_UART_SCB_MODE_UART_INC)
       #define XBEE_UART_UART_BTLDR_COMM_ENABLED    (XBEE_UART_BTLDR_COMM_ENABLED && \
                                                            (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (XBEE_UART_UART_RX_DIRECTION && \
                                                              XBEE_UART_UART_TX_DIRECTION)))
#else
     #define XBEE_UART_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (XBEE_UART_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define XBEE_UART_BTLDR_COMM_MODE_ENABLED    (XBEE_UART_I2C_BTLDR_COMM_ENABLED   || \
                                                     XBEE_UART_SPI_BTLDR_COMM_ENABLED   || \
                                                     XBEE_UART_EZI2C_BTLDR_COMM_ENABLED || \
                                                     XBEE_UART_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void XBEE_UART_I2CCyBtldrCommStart(void);
    void XBEE_UART_I2CCyBtldrCommStop (void);
    void XBEE_UART_I2CCyBtldrCommReset(void);
    cystatus XBEE_UART_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus XBEE_UART_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (XBEE_UART_SCB_MODE_I2C_CONST_CFG)
        #define XBEE_UART_CyBtldrCommStart   XBEE_UART_I2CCyBtldrCommStart
        #define XBEE_UART_CyBtldrCommStop    XBEE_UART_I2CCyBtldrCommStop
        #define XBEE_UART_CyBtldrCommReset   XBEE_UART_I2CCyBtldrCommReset
        #define XBEE_UART_CyBtldrCommRead    XBEE_UART_I2CCyBtldrCommRead
        #define XBEE_UART_CyBtldrCommWrite   XBEE_UART_I2CCyBtldrCommWrite
    #endif /* (XBEE_UART_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void XBEE_UART_EzI2CCyBtldrCommStart(void);
    void XBEE_UART_EzI2CCyBtldrCommStop (void);
    void XBEE_UART_EzI2CCyBtldrCommReset(void);
    cystatus XBEE_UART_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus XBEE_UART_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (XBEE_UART_SCB_MODE_EZI2C_CONST_CFG)
        #define XBEE_UART_CyBtldrCommStart   XBEE_UART_EzI2CCyBtldrCommStart
        #define XBEE_UART_CyBtldrCommStop    XBEE_UART_EzI2CCyBtldrCommStop
        #define XBEE_UART_CyBtldrCommReset   XBEE_UART_EzI2CCyBtldrCommReset
        #define XBEE_UART_CyBtldrCommRead    XBEE_UART_EzI2CCyBtldrCommRead
        #define XBEE_UART_CyBtldrCommWrite   XBEE_UART_EzI2CCyBtldrCommWrite
    #endif /* (XBEE_UART_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void XBEE_UART_SpiCyBtldrCommStart(void);
    void XBEE_UART_SpiCyBtldrCommStop (void);
    void XBEE_UART_SpiCyBtldrCommReset(void);
    cystatus XBEE_UART_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus XBEE_UART_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (XBEE_UART_SCB_MODE_SPI_CONST_CFG)
        #define XBEE_UART_CyBtldrCommStart   XBEE_UART_SpiCyBtldrCommStart
        #define XBEE_UART_CyBtldrCommStop    XBEE_UART_SpiCyBtldrCommStop
        #define XBEE_UART_CyBtldrCommReset   XBEE_UART_SpiCyBtldrCommReset
        #define XBEE_UART_CyBtldrCommRead    XBEE_UART_SpiCyBtldrCommRead
        #define XBEE_UART_CyBtldrCommWrite   XBEE_UART_SpiCyBtldrCommWrite
    #endif /* (XBEE_UART_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void XBEE_UART_UartCyBtldrCommStart(void);
    void XBEE_UART_UartCyBtldrCommStop (void);
    void XBEE_UART_UartCyBtldrCommReset(void);
    cystatus XBEE_UART_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus XBEE_UART_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (XBEE_UART_SCB_MODE_UART_CONST_CFG)
        #define XBEE_UART_CyBtldrCommStart   XBEE_UART_UartCyBtldrCommStart
        #define XBEE_UART_CyBtldrCommStop    XBEE_UART_UartCyBtldrCommStop
        #define XBEE_UART_CyBtldrCommReset   XBEE_UART_UartCyBtldrCommReset
        #define XBEE_UART_CyBtldrCommRead    XBEE_UART_UartCyBtldrCommRead
        #define XBEE_UART_CyBtldrCommWrite   XBEE_UART_UartCyBtldrCommWrite
    #endif /* (XBEE_UART_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_BTLDR_COMM_ENABLED)
    #if (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void XBEE_UART_CyBtldrCommStart(void);
        void XBEE_UART_CyBtldrCommStop (void);
        void XBEE_UART_CyBtldrCommReset(void);
        cystatus XBEE_UART_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus XBEE_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBEE_UART)
        #define CyBtldrCommStart    XBEE_UART_CyBtldrCommStart
        #define CyBtldrCommStop     XBEE_UART_CyBtldrCommStop
        #define CyBtldrCommReset    XBEE_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    XBEE_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     XBEE_UART_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBEE_UART) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (XBEE_UART_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define XBEE_UART_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define XBEE_UART_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define XBEE_UART_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define XBEE_UART_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef XBEE_UART_SPI_BYTE_TO_BYTE
    #define XBEE_UART_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef XBEE_UART_UART_BYTE_TO_BYTE
    #define XBEE_UART_UART_BYTE_TO_BYTE  (2086u)
#endif /* XBEE_UART_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_XBEE_UART_H) */


/* [] END OF FILE */
