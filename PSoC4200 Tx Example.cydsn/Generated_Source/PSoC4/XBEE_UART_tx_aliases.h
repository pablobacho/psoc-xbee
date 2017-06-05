/*******************************************************************************
* File Name: XBEE_UART_tx.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_XBEE_UART_tx_ALIASES_H) /* Pins XBEE_UART_tx_ALIASES_H */
#define CY_PINS_XBEE_UART_tx_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define XBEE_UART_tx_0			(XBEE_UART_tx__0__PC)
#define XBEE_UART_tx_0_PS		(XBEE_UART_tx__0__PS)
#define XBEE_UART_tx_0_PC		(XBEE_UART_tx__0__PC)
#define XBEE_UART_tx_0_DR		(XBEE_UART_tx__0__DR)
#define XBEE_UART_tx_0_SHIFT	(XBEE_UART_tx__0__SHIFT)
#define XBEE_UART_tx_0_INTR	((uint16)((uint16)0x0003u << (XBEE_UART_tx__0__SHIFT*2u)))

#define XBEE_UART_tx_INTR_ALL	 ((uint16)(XBEE_UART_tx_0_INTR))


#endif /* End Pins XBEE_UART_tx_ALIASES_H */


/* [] END OF FILE */
