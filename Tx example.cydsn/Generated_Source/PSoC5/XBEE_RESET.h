/*******************************************************************************
* File Name: XBEE_RESET.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_XBEE_RESET_H) /* Pins XBEE_RESET_H */
#define CY_PINS_XBEE_RESET_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "XBEE_RESET_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 XBEE_RESET__PORT == 15 && ((XBEE_RESET__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    XBEE_RESET_Write(uint8 value) ;
void    XBEE_RESET_SetDriveMode(uint8 mode) ;
uint8   XBEE_RESET_ReadDataReg(void) ;
uint8   XBEE_RESET_Read(void) ;
uint8   XBEE_RESET_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define XBEE_RESET_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define XBEE_RESET_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define XBEE_RESET_DM_RES_UP          PIN_DM_RES_UP
#define XBEE_RESET_DM_RES_DWN         PIN_DM_RES_DWN
#define XBEE_RESET_DM_OD_LO           PIN_DM_OD_LO
#define XBEE_RESET_DM_OD_HI           PIN_DM_OD_HI
#define XBEE_RESET_DM_STRONG          PIN_DM_STRONG
#define XBEE_RESET_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define XBEE_RESET_MASK               XBEE_RESET__MASK
#define XBEE_RESET_SHIFT              XBEE_RESET__SHIFT
#define XBEE_RESET_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define XBEE_RESET_PS                     (* (reg8 *) XBEE_RESET__PS)
/* Data Register */
#define XBEE_RESET_DR                     (* (reg8 *) XBEE_RESET__DR)
/* Port Number */
#define XBEE_RESET_PRT_NUM                (* (reg8 *) XBEE_RESET__PRT) 
/* Connect to Analog Globals */                                                  
#define XBEE_RESET_AG                     (* (reg8 *) XBEE_RESET__AG)                       
/* Analog MUX bux enable */
#define XBEE_RESET_AMUX                   (* (reg8 *) XBEE_RESET__AMUX) 
/* Bidirectional Enable */                                                        
#define XBEE_RESET_BIE                    (* (reg8 *) XBEE_RESET__BIE)
/* Bit-mask for Aliased Register Access */
#define XBEE_RESET_BIT_MASK               (* (reg8 *) XBEE_RESET__BIT_MASK)
/* Bypass Enable */
#define XBEE_RESET_BYP                    (* (reg8 *) XBEE_RESET__BYP)
/* Port wide control signals */                                                   
#define XBEE_RESET_CTL                    (* (reg8 *) XBEE_RESET__CTL)
/* Drive Modes */
#define XBEE_RESET_DM0                    (* (reg8 *) XBEE_RESET__DM0) 
#define XBEE_RESET_DM1                    (* (reg8 *) XBEE_RESET__DM1)
#define XBEE_RESET_DM2                    (* (reg8 *) XBEE_RESET__DM2) 
/* Input Buffer Disable Override */
#define XBEE_RESET_INP_DIS                (* (reg8 *) XBEE_RESET__INP_DIS)
/* LCD Common or Segment Drive */
#define XBEE_RESET_LCD_COM_SEG            (* (reg8 *) XBEE_RESET__LCD_COM_SEG)
/* Enable Segment LCD */
#define XBEE_RESET_LCD_EN                 (* (reg8 *) XBEE_RESET__LCD_EN)
/* Slew Rate Control */
#define XBEE_RESET_SLW                    (* (reg8 *) XBEE_RESET__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define XBEE_RESET_PRTDSI__CAPS_SEL       (* (reg8 *) XBEE_RESET__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define XBEE_RESET_PRTDSI__DBL_SYNC_IN    (* (reg8 *) XBEE_RESET__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define XBEE_RESET_PRTDSI__OE_SEL0        (* (reg8 *) XBEE_RESET__PRTDSI__OE_SEL0) 
#define XBEE_RESET_PRTDSI__OE_SEL1        (* (reg8 *) XBEE_RESET__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define XBEE_RESET_PRTDSI__OUT_SEL0       (* (reg8 *) XBEE_RESET__PRTDSI__OUT_SEL0) 
#define XBEE_RESET_PRTDSI__OUT_SEL1       (* (reg8 *) XBEE_RESET__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define XBEE_RESET_PRTDSI__SYNC_OUT       (* (reg8 *) XBEE_RESET__PRTDSI__SYNC_OUT) 


#if defined(XBEE_RESET__INTSTAT)  /* Interrupt Registers */

    #define XBEE_RESET_INTSTAT                (* (reg8 *) XBEE_RESET__INTSTAT)
    #define XBEE_RESET_SNAP                   (* (reg8 *) XBEE_RESET__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_XBEE_RESET_H */


/* [] END OF FILE */
