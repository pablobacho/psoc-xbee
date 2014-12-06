/*******************************************************************************
* File Name: XBEE_SLEEP_RQ.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "XBEE_SLEEP_RQ.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 XBEE_SLEEP_RQ__PORT == 15 && ((XBEE_SLEEP_RQ__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: XBEE_SLEEP_RQ_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void XBEE_SLEEP_RQ_Write(uint8 value) 
{
    uint8 staticBits = (XBEE_SLEEP_RQ_DR & (uint8)(~XBEE_SLEEP_RQ_MASK));
    XBEE_SLEEP_RQ_DR = staticBits | ((uint8)(value << XBEE_SLEEP_RQ_SHIFT) & XBEE_SLEEP_RQ_MASK);
}


/*******************************************************************************
* Function Name: XBEE_SLEEP_RQ_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  XBEE_SLEEP_RQ_DM_STRONG     Strong Drive 
*  XBEE_SLEEP_RQ_DM_OD_HI      Open Drain, Drives High 
*  XBEE_SLEEP_RQ_DM_OD_LO      Open Drain, Drives Low 
*  XBEE_SLEEP_RQ_DM_RES_UP     Resistive Pull Up 
*  XBEE_SLEEP_RQ_DM_RES_DWN    Resistive Pull Down 
*  XBEE_SLEEP_RQ_DM_RES_UPDWN  Resistive Pull Up/Down 
*  XBEE_SLEEP_RQ_DM_DIG_HIZ    High Impedance Digital 
*  XBEE_SLEEP_RQ_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void XBEE_SLEEP_RQ_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(XBEE_SLEEP_RQ_0, mode);
}


/*******************************************************************************
* Function Name: XBEE_SLEEP_RQ_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro XBEE_SLEEP_RQ_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 XBEE_SLEEP_RQ_Read(void) 
{
    return (XBEE_SLEEP_RQ_PS & XBEE_SLEEP_RQ_MASK) >> XBEE_SLEEP_RQ_SHIFT;
}


/*******************************************************************************
* Function Name: XBEE_SLEEP_RQ_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 XBEE_SLEEP_RQ_ReadDataReg(void) 
{
    return (XBEE_SLEEP_RQ_DR & XBEE_SLEEP_RQ_MASK) >> XBEE_SLEEP_RQ_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(XBEE_SLEEP_RQ_INTSTAT) 

    /*******************************************************************************
    * Function Name: XBEE_SLEEP_RQ_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 XBEE_SLEEP_RQ_ClearInterrupt(void) 
    {
        return (XBEE_SLEEP_RQ_INTSTAT & XBEE_SLEEP_RQ_MASK) >> XBEE_SLEEP_RQ_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
