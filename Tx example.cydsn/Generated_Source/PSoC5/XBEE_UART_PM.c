/*******************************************************************************
* File Name: XBEE_UART_PM.c
* Version 2.30
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "XBEE_UART.h"


/***************************************
* Local data allocation
***************************************/

static XBEE_UART_BACKUP_STRUCT  XBEE_UART_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: XBEE_UART_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  XBEE_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void XBEE_UART_SaveConfig(void)
{
    #if (CY_UDB_V0)

        #if(XBEE_UART_CONTROL_REG_REMOVED == 0u)
            XBEE_UART_backup.cr = XBEE_UART_CONTROL_REG;
        #endif /* End XBEE_UART_CONTROL_REG_REMOVED */

        #if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
            XBEE_UART_backup.rx_period = XBEE_UART_RXBITCTR_PERIOD_REG;
            XBEE_UART_backup.rx_mask = XBEE_UART_RXSTATUS_MASK_REG;
            #if (XBEE_UART_RXHW_ADDRESS_ENABLED)
                XBEE_UART_backup.rx_addr1 = XBEE_UART_RXADDRESS1_REG;
                XBEE_UART_backup.rx_addr2 = XBEE_UART_RXADDRESS2_REG;
            #endif /* End XBEE_UART_RXHW_ADDRESS_ENABLED */
        #endif /* End XBEE_UART_RX_ENABLED | XBEE_UART_HD_ENABLED*/

        #if(XBEE_UART_TX_ENABLED)
            #if(XBEE_UART_TXCLKGEN_DP)
                XBEE_UART_backup.tx_clk_ctr = XBEE_UART_TXBITCLKGEN_CTR_REG;
                XBEE_UART_backup.tx_clk_compl = XBEE_UART_TXBITCLKTX_COMPLETE_REG;
            #else
                XBEE_UART_backup.tx_period = XBEE_UART_TXBITCTR_PERIOD_REG;
            #endif /*End XBEE_UART_TXCLKGEN_DP */
            XBEE_UART_backup.tx_mask = XBEE_UART_TXSTATUS_MASK_REG;
        #endif /*End XBEE_UART_TX_ENABLED */


    #else /* CY_UDB_V1 */

        #if(XBEE_UART_CONTROL_REG_REMOVED == 0u)
            XBEE_UART_backup.cr = XBEE_UART_CONTROL_REG;
        #endif /* End XBEE_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: XBEE_UART_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  XBEE_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void XBEE_UART_RestoreConfig(void)
{

    #if (CY_UDB_V0)

        #if(XBEE_UART_CONTROL_REG_REMOVED == 0u)
            XBEE_UART_CONTROL_REG = XBEE_UART_backup.cr;
        #endif /* End XBEE_UART_CONTROL_REG_REMOVED */

        #if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
            XBEE_UART_RXBITCTR_PERIOD_REG = XBEE_UART_backup.rx_period;
            XBEE_UART_RXSTATUS_MASK_REG = XBEE_UART_backup.rx_mask;
            #if (XBEE_UART_RXHW_ADDRESS_ENABLED)
                XBEE_UART_RXADDRESS1_REG = XBEE_UART_backup.rx_addr1;
                XBEE_UART_RXADDRESS2_REG = XBEE_UART_backup.rx_addr2;
            #endif /* End XBEE_UART_RXHW_ADDRESS_ENABLED */
        #endif  /* End (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */

        #if(XBEE_UART_TX_ENABLED)
            #if(XBEE_UART_TXCLKGEN_DP)
                XBEE_UART_TXBITCLKGEN_CTR_REG = XBEE_UART_backup.tx_clk_ctr;
                XBEE_UART_TXBITCLKTX_COMPLETE_REG = XBEE_UART_backup.tx_clk_compl;
            #else
                XBEE_UART_TXBITCTR_PERIOD_REG = XBEE_UART_backup.tx_period;
            #endif /*End XBEE_UART_TXCLKGEN_DP */
            XBEE_UART_TXSTATUS_MASK_REG = XBEE_UART_backup.tx_mask;
        #endif /*End XBEE_UART_TX_ENABLED */

    #else /* CY_UDB_V1 */

        #if(XBEE_UART_CONTROL_REG_REMOVED == 0u)
            XBEE_UART_CONTROL_REG = XBEE_UART_backup.cr;
        #endif /* End XBEE_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: XBEE_UART_Sleep
********************************************************************************
*
* Summary:
*  Stops and saves the user configuration. Should be called
*  just prior to entering sleep.
*
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  XBEE_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void XBEE_UART_Sleep(void)
{

    #if(XBEE_UART_RX_ENABLED || XBEE_UART_HD_ENABLED)
        if((XBEE_UART_RXSTATUS_ACTL_REG  & XBEE_UART_INT_ENABLE) != 0u)
        {
            XBEE_UART_backup.enableState = 1u;
        }
        else
        {
            XBEE_UART_backup.enableState = 0u;
        }
    #else
        if((XBEE_UART_TXSTATUS_ACTL_REG  & XBEE_UART_INT_ENABLE) !=0u)
        {
            XBEE_UART_backup.enableState = 1u;
        }
        else
        {
            XBEE_UART_backup.enableState = 0u;
        }
    #endif /* End XBEE_UART_RX_ENABLED || XBEE_UART_HD_ENABLED*/

    XBEE_UART_Stop();
    XBEE_UART_SaveConfig();
}


/*******************************************************************************
* Function Name: XBEE_UART_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  XBEE_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void XBEE_UART_Wakeup(void)
{
    XBEE_UART_RestoreConfig();
    #if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
        XBEE_UART_ClearRxBuffer();
    #endif /* End (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */
    #if(XBEE_UART_TX_ENABLED || XBEE_UART_HD_ENABLED)
        XBEE_UART_ClearTxBuffer();
    #endif /* End XBEE_UART_TX_ENABLED || XBEE_UART_HD_ENABLED */

    if(XBEE_UART_backup.enableState != 0u)
    {
        XBEE_UART_Enable();
    }
}


/* [] END OF FILE */
