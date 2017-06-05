/*******************************************************************************
* File Name: XBEE_SLEEP_RQ.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_XBEE_SLEEP_RQ_H) /* Pins XBEE_SLEEP_RQ_H */
#define CY_PINS_XBEE_SLEEP_RQ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "XBEE_SLEEP_RQ_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} XBEE_SLEEP_RQ_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   XBEE_SLEEP_RQ_Read(void);
void    XBEE_SLEEP_RQ_Write(uint8 value);
uint8   XBEE_SLEEP_RQ_ReadDataReg(void);
#if defined(XBEE_SLEEP_RQ__PC) || (CY_PSOC4_4200L) 
    void    XBEE_SLEEP_RQ_SetDriveMode(uint8 mode);
#endif
void    XBEE_SLEEP_RQ_SetInterruptMode(uint16 position, uint16 mode);
uint8   XBEE_SLEEP_RQ_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void XBEE_SLEEP_RQ_Sleep(void); 
void XBEE_SLEEP_RQ_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(XBEE_SLEEP_RQ__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define XBEE_SLEEP_RQ_DRIVE_MODE_BITS        (3)
    #define XBEE_SLEEP_RQ_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - XBEE_SLEEP_RQ_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the XBEE_SLEEP_RQ_SetDriveMode() function.
         *  @{
         */
        #define XBEE_SLEEP_RQ_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define XBEE_SLEEP_RQ_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define XBEE_SLEEP_RQ_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define XBEE_SLEEP_RQ_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define XBEE_SLEEP_RQ_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define XBEE_SLEEP_RQ_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define XBEE_SLEEP_RQ_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define XBEE_SLEEP_RQ_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define XBEE_SLEEP_RQ_MASK               XBEE_SLEEP_RQ__MASK
#define XBEE_SLEEP_RQ_SHIFT              XBEE_SLEEP_RQ__SHIFT
#define XBEE_SLEEP_RQ_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in XBEE_SLEEP_RQ_SetInterruptMode() function.
     *  @{
     */
        #define XBEE_SLEEP_RQ_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define XBEE_SLEEP_RQ_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define XBEE_SLEEP_RQ_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define XBEE_SLEEP_RQ_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(XBEE_SLEEP_RQ__SIO)
    #define XBEE_SLEEP_RQ_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(XBEE_SLEEP_RQ__PC) && (CY_PSOC4_4200L)
    #define XBEE_SLEEP_RQ_USBIO_ENABLE               ((uint32)0x80000000u)
    #define XBEE_SLEEP_RQ_USBIO_DISABLE              ((uint32)(~XBEE_SLEEP_RQ_USBIO_ENABLE))
    #define XBEE_SLEEP_RQ_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define XBEE_SLEEP_RQ_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define XBEE_SLEEP_RQ_USBIO_ENTER_SLEEP          ((uint32)((1u << XBEE_SLEEP_RQ_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << XBEE_SLEEP_RQ_USBIO_SUSPEND_DEL_SHIFT)))
    #define XBEE_SLEEP_RQ_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << XBEE_SLEEP_RQ_USBIO_SUSPEND_SHIFT)))
    #define XBEE_SLEEP_RQ_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << XBEE_SLEEP_RQ_USBIO_SUSPEND_DEL_SHIFT)))
    #define XBEE_SLEEP_RQ_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(XBEE_SLEEP_RQ__PC)
    /* Port Configuration */
    #define XBEE_SLEEP_RQ_PC                 (* (reg32 *) XBEE_SLEEP_RQ__PC)
#endif
/* Pin State */
#define XBEE_SLEEP_RQ_PS                     (* (reg32 *) XBEE_SLEEP_RQ__PS)
/* Data Register */
#define XBEE_SLEEP_RQ_DR                     (* (reg32 *) XBEE_SLEEP_RQ__DR)
/* Input Buffer Disable Override */
#define XBEE_SLEEP_RQ_INP_DIS                (* (reg32 *) XBEE_SLEEP_RQ__PC2)

/* Interrupt configuration Registers */
#define XBEE_SLEEP_RQ_INTCFG                 (* (reg32 *) XBEE_SLEEP_RQ__INTCFG)
#define XBEE_SLEEP_RQ_INTSTAT                (* (reg32 *) XBEE_SLEEP_RQ__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define XBEE_SLEEP_RQ_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(XBEE_SLEEP_RQ__SIO)
    #define XBEE_SLEEP_RQ_SIO_REG            (* (reg32 *) XBEE_SLEEP_RQ__SIO)
#endif /* (XBEE_SLEEP_RQ__SIO_CFG) */

/* USBIO registers */
#if !defined(XBEE_SLEEP_RQ__PC) && (CY_PSOC4_4200L)
    #define XBEE_SLEEP_RQ_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define XBEE_SLEEP_RQ_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define XBEE_SLEEP_RQ_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define XBEE_SLEEP_RQ_DRIVE_MODE_SHIFT       (0x00u)
#define XBEE_SLEEP_RQ_DRIVE_MODE_MASK        (0x07u << XBEE_SLEEP_RQ_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins XBEE_SLEEP_RQ_H */


/* [] END OF FILE */
