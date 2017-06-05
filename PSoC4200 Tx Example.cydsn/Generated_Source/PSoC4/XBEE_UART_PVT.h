/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_XBEE_UART_H)
#define CY_SCB_PVT_XBEE_UART_H

#include "XBEE_UART.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define XBEE_UART_SetI2CExtClkInterruptMode(interruptMask) XBEE_UART_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define XBEE_UART_ClearI2CExtClkInterruptSource(interruptMask) XBEE_UART_CLEAR_INTR_I2C_EC(interruptMask)
#define XBEE_UART_GetI2CExtClkInterruptSource()                (XBEE_UART_INTR_I2C_EC_REG)
#define XBEE_UART_GetI2CExtClkInterruptMode()                  (XBEE_UART_INTR_I2C_EC_MASK_REG)
#define XBEE_UART_GetI2CExtClkInterruptSourceMasked()          (XBEE_UART_INTR_I2C_EC_MASKED_REG)

#if (!XBEE_UART_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define XBEE_UART_SetSpiExtClkInterruptMode(interruptMask) \
                                                                XBEE_UART_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define XBEE_UART_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                XBEE_UART_CLEAR_INTR_SPI_EC(interruptMask)
    #define XBEE_UART_GetExtSpiClkInterruptSource()                 (XBEE_UART_INTR_SPI_EC_REG)
    #define XBEE_UART_GetExtSpiClkInterruptMode()                   (XBEE_UART_INTR_SPI_EC_MASK_REG)
    #define XBEE_UART_GetExtSpiClkInterruptSourceMasked()           (XBEE_UART_INTR_SPI_EC_MASKED_REG)
#endif /* (!XBEE_UART_CY_SCBIP_V1) */

#if(XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void XBEE_UART_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (XBEE_UART_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_XBEE_UART_CUSTOM_INTR_HANDLER)
    extern cyisraddress XBEE_UART_customIntrHandler;
#endif /* !defined (CY_REMOVE_XBEE_UART_CUSTOM_INTR_HANDLER) */
#endif /* (XBEE_UART_SCB_IRQ_INTERNAL) */

extern XBEE_UART_BACKUP_STRUCT XBEE_UART_backup;

#if(XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 XBEE_UART_scbMode;
    extern uint8 XBEE_UART_scbEnableWake;
    extern uint8 XBEE_UART_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 XBEE_UART_mode;
    extern uint8 XBEE_UART_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * XBEE_UART_rxBuffer;
    extern uint8   XBEE_UART_rxDataBits;
    extern uint32  XBEE_UART_rxBufferSize;

    extern volatile uint8 * XBEE_UART_txBuffer;
    extern uint8   XBEE_UART_txDataBits;
    extern uint32  XBEE_UART_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 XBEE_UART_numberOfAddr;
    extern uint8 XBEE_UART_subAddrSize;
#endif /* (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (XBEE_UART_SCB_MODE_I2C_CONST_CFG || \
        XBEE_UART_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 XBEE_UART_IntrTxMask;
#endif /* (! (XBEE_UART_SCB_MODE_I2C_CONST_CFG || \
              XBEE_UART_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define XBEE_UART_SCB_MODE_I2C_RUNTM_CFG     (XBEE_UART_SCB_MODE_I2C      == XBEE_UART_scbMode)
    #define XBEE_UART_SCB_MODE_SPI_RUNTM_CFG     (XBEE_UART_SCB_MODE_SPI      == XBEE_UART_scbMode)
    #define XBEE_UART_SCB_MODE_UART_RUNTM_CFG    (XBEE_UART_SCB_MODE_UART     == XBEE_UART_scbMode)
    #define XBEE_UART_SCB_MODE_EZI2C_RUNTM_CFG   (XBEE_UART_SCB_MODE_EZI2C    == XBEE_UART_scbMode)
    #define XBEE_UART_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (XBEE_UART_SCB_MODE_UNCONFIG == XBEE_UART_scbMode)

    /* Defines wakeup enable */
    #define XBEE_UART_SCB_WAKE_ENABLE_CHECK       (0u != XBEE_UART_scbEnableWake)
#endif /* (XBEE_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!XBEE_UART_CY_SCBIP_V1)
    #define XBEE_UART_SCB_PINS_NUMBER    (7u)
#else
    #define XBEE_UART_SCB_PINS_NUMBER    (2u)
#endif /* (!XBEE_UART_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_XBEE_UART_H) */


/* [] END OF FILE */
