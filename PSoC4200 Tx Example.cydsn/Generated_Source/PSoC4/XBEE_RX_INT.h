/*******************************************************************************
* File Name: XBEE_RX_INT.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_XBEE_RX_INT_H)
#define CY_ISR_XBEE_RX_INT_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void XBEE_RX_INT_Start(void);
void XBEE_RX_INT_StartEx(cyisraddress address);
void XBEE_RX_INT_Stop(void);

CY_ISR_PROTO(XBEE_RX_INT_Interrupt);

void XBEE_RX_INT_SetVector(cyisraddress address);
cyisraddress XBEE_RX_INT_GetVector(void);

void XBEE_RX_INT_SetPriority(uint8 priority);
uint8 XBEE_RX_INT_GetPriority(void);

void XBEE_RX_INT_Enable(void);
uint8 XBEE_RX_INT_GetState(void);
void XBEE_RX_INT_Disable(void);

void XBEE_RX_INT_SetPending(void);
void XBEE_RX_INT_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the XBEE_RX_INT ISR. */
#define XBEE_RX_INT_INTC_VECTOR            ((reg32 *) XBEE_RX_INT__INTC_VECT)

/* Address of the XBEE_RX_INT ISR priority. */
#define XBEE_RX_INT_INTC_PRIOR             ((reg32 *) XBEE_RX_INT__INTC_PRIOR_REG)

/* Priority of the XBEE_RX_INT interrupt. */
#define XBEE_RX_INT_INTC_PRIOR_NUMBER      XBEE_RX_INT__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable XBEE_RX_INT interrupt. */
#define XBEE_RX_INT_INTC_SET_EN            ((reg32 *) XBEE_RX_INT__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the XBEE_RX_INT interrupt. */
#define XBEE_RX_INT_INTC_CLR_EN            ((reg32 *) XBEE_RX_INT__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the XBEE_RX_INT interrupt state to pending. */
#define XBEE_RX_INT_INTC_SET_PD            ((reg32 *) XBEE_RX_INT__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the XBEE_RX_INT interrupt. */
#define XBEE_RX_INT_INTC_CLR_PD            ((reg32 *) XBEE_RX_INT__INTC_CLR_PD_REG)



#endif /* CY_ISR_XBEE_RX_INT_H */


/* [] END OF FILE */
