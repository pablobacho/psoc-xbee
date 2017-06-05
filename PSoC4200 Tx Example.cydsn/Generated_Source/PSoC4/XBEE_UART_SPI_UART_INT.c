/***************************************************************************//**
* \file XBEE_UART_SPI_UART_INT.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "XBEE_UART_PVT.h"
#include "XBEE_UART_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (XBEE_UART_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: XBEE_UART_SPI_UART_ISR
****************************************************************************//**
*
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
*******************************************************************************/
CY_ISR(XBEE_UART_SPI_UART_ISR)
{
#if (XBEE_UART_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (XBEE_UART_INTERNAL_RX_SW_BUFFER_CONST) */

#if (XBEE_UART_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (XBEE_UART_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef XBEE_UART_SPI_UART_ISR_ENTRY_CALLBACK
    XBEE_UART_SPI_UART_ISR_EntryCallback();
#endif /* XBEE_UART_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != XBEE_UART_customIntrHandler)
    {
        XBEE_UART_customIntrHandler();
    }

    #if(XBEE_UART_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        XBEE_UART_ClearSpiExtClkInterruptSource(XBEE_UART_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (XBEE_UART_CHECK_RX_SW_BUFFER)
    {
        if (XBEE_UART_CHECK_INTR_RX_MASKED(XBEE_UART_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (XBEE_UART_rxBufferHead + 1u);

                /* Adjust local head index */
                if (XBEE_UART_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == XBEE_UART_rxBufferTail)
                {
                    #if (XBEE_UART_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        XBEE_UART_INTR_RX_MASK_REG &= ~XBEE_UART_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) XBEE_UART_RX_FIFO_RD_REG;
                        XBEE_UART_rxBufferOverflow = (uint8) XBEE_UART_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    XBEE_UART_PutWordInRxBuffer(locHead, XBEE_UART_RX_FIFO_RD_REG);

                    /* Move head index */
                    XBEE_UART_rxBufferHead = locHead;
                }
            }
            while(0u != XBEE_UART_GET_RX_FIFO_ENTRIES);

            XBEE_UART_ClearRxInterruptSource(XBEE_UART_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (XBEE_UART_CHECK_TX_SW_BUFFER)
    {
        if (XBEE_UART_CHECK_INTR_TX_MASKED(XBEE_UART_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (XBEE_UART_txBufferHead != XBEE_UART_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (XBEE_UART_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (XBEE_UART_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    XBEE_UART_TX_FIFO_WR_REG = XBEE_UART_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    XBEE_UART_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    XBEE_UART_DISABLE_INTR_TX(XBEE_UART_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (XBEE_UART_SPI_UART_FIFO_SIZE != XBEE_UART_GET_TX_FIFO_ENTRIES);

            XBEE_UART_ClearTxInterruptSource(XBEE_UART_INTR_TX_NOT_FULL);
        }
    }
    #endif

#ifdef XBEE_UART_SPI_UART_ISR_EXIT_CALLBACK
    XBEE_UART_SPI_UART_ISR_ExitCallback();
#endif /* XBEE_UART_SPI_UART_ISR_EXIT_CALLBACK */

}

#endif /* (XBEE_UART_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
