/***************************************************************************//**
* \file XBEE_UART_SPI_UART_PVT.h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_XBEE_UART_H)
#define CY_SCB_SPI_UART_PVT_XBEE_UART_H

#include "XBEE_UART_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (XBEE_UART_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  XBEE_UART_rxBufferHead;
    extern volatile uint32  XBEE_UART_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   XBEE_UART_rxBufferOverflow;
    /** @} globals */
#endif /* (XBEE_UART_INTERNAL_RX_SW_BUFFER_CONST) */

#if (XBEE_UART_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  XBEE_UART_txBufferHead;
    extern volatile uint32  XBEE_UART_txBufferTail;
#endif /* (XBEE_UART_INTERNAL_TX_SW_BUFFER_CONST) */

#if (XBEE_UART_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 XBEE_UART_rxBufferInternal[XBEE_UART_INTERNAL_RX_BUFFER_SIZE];
#endif /* (XBEE_UART_INTERNAL_RX_SW_BUFFER) */

#if (XBEE_UART_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 XBEE_UART_txBufferInternal[XBEE_UART_TX_BUFFER_SIZE];
#endif /* (XBEE_UART_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void XBEE_UART_SpiPostEnable(void);
void XBEE_UART_SpiStop(void);

#if (XBEE_UART_SCB_MODE_SPI_CONST_CFG)
    void XBEE_UART_SpiInit(void);
#endif /* (XBEE_UART_SCB_MODE_SPI_CONST_CFG) */

#if (XBEE_UART_SPI_WAKE_ENABLE_CONST)
    void XBEE_UART_SpiSaveConfig(void);
    void XBEE_UART_SpiRestoreConfig(void);
#endif /* (XBEE_UART_SPI_WAKE_ENABLE_CONST) */

void XBEE_UART_UartPostEnable(void);
void XBEE_UART_UartStop(void);

#if (XBEE_UART_SCB_MODE_UART_CONST_CFG)
    void XBEE_UART_UartInit(void);
#endif /* (XBEE_UART_SCB_MODE_UART_CONST_CFG) */

#if (XBEE_UART_UART_WAKE_ENABLE_CONST)
    void XBEE_UART_UartSaveConfig(void);
    void XBEE_UART_UartRestoreConfig(void);
#endif /* (XBEE_UART_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in XBEE_UART_SetPins() */
#define XBEE_UART_UART_RX_PIN_ENABLE    (XBEE_UART_UART_RX)
#define XBEE_UART_UART_TX_PIN_ENABLE    (XBEE_UART_UART_TX)

/* UART RTS and CTS position to be used in  XBEE_UART_SetPins() */
#define XBEE_UART_UART_RTS_PIN_ENABLE    (0x10u)
#define XBEE_UART_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define XBEE_UART_SpiUartEnableIntRx(intSourceMask)  XBEE_UART_SetRxInterruptMode(intSourceMask)
#define XBEE_UART_SpiUartEnableIntTx(intSourceMask)  XBEE_UART_SetTxInterruptMode(intSourceMask)
uint32  XBEE_UART_SpiUartDisableIntRx(void);
uint32  XBEE_UART_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_XBEE_UART_H) */


/* [] END OF FILE */
