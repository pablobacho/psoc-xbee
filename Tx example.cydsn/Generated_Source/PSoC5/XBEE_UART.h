/*******************************************************************************
* File Name: XBEE_UART.h
* Version 2.30
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_XBEE_UART_H)
#define CY_UART_XBEE_UART_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

#define XBEE_UART_RX_ENABLED                     (1u)
#define XBEE_UART_TX_ENABLED                     (1u)
#define XBEE_UART_HD_ENABLED                     (0u)
#define XBEE_UART_RX_INTERRUPT_ENABLED           (0u)
#define XBEE_UART_TX_INTERRUPT_ENABLED           (0u)
#define XBEE_UART_INTERNAL_CLOCK_USED            (1u)
#define XBEE_UART_RXHW_ADDRESS_ENABLED           (0u)
#define XBEE_UART_OVER_SAMPLE_COUNT              (8u)
#define XBEE_UART_PARITY_TYPE                    (0u)
#define XBEE_UART_PARITY_TYPE_SW                 (0u)
#define XBEE_UART_BREAK_DETECT                   (0u)
#define XBEE_UART_BREAK_BITS_TX                  (13u)
#define XBEE_UART_BREAK_BITS_RX                  (13u)
#define XBEE_UART_TXCLKGEN_DP                    (1u)
#define XBEE_UART_USE23POLLING                   (1u)
#define XBEE_UART_FLOW_CONTROL                   (1u)
#define XBEE_UART_CLK_FREQ                       (1u)
#define XBEE_UART_TXBUFFERSIZE                   (4u)
#define XBEE_UART_RXBUFFERSIZE                   (4u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#ifdef XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define XBEE_UART_CONTROL_REG_REMOVED            (0u)
#else
    #define XBEE_UART_CONTROL_REG_REMOVED            (1u)
#endif /* End XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct XBEE_UART_backupStruct_
{
    uint8 enableState;

    #if(XBEE_UART_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End XBEE_UART_CONTROL_REG_REMOVED */
    #if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
        uint8 rx_period;
        #if (CY_UDB_V0)
            uint8 rx_mask;
            #if (XBEE_UART_RXHW_ADDRESS_ENABLED)
                uint8 rx_addr1;
                uint8 rx_addr2;
            #endif /* End XBEE_UART_RXHW_ADDRESS_ENABLED */
        #endif /* End CY_UDB_V0 */
    #endif  /* End (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED)*/

    #if(XBEE_UART_TX_ENABLED)
        #if(XBEE_UART_TXCLKGEN_DP)
            uint8 tx_clk_ctr;
            #if (CY_UDB_V0)
                uint8 tx_clk_compl;
            #endif  /* End CY_UDB_V0 */
        #else
            uint8 tx_period;
        #endif /*End XBEE_UART_TXCLKGEN_DP */
        #if (CY_UDB_V0)
            uint8 tx_mask;
        #endif  /* End CY_UDB_V0 */
    #endif /*End XBEE_UART_TX_ENABLED */
} XBEE_UART_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void XBEE_UART_Start(void) ;
void XBEE_UART_Stop(void) ;
uint8 XBEE_UART_ReadControlRegister(void) ;
void XBEE_UART_WriteControlRegister(uint8 control) ;

void XBEE_UART_Init(void) ;
void XBEE_UART_Enable(void) ;
void XBEE_UART_SaveConfig(void) ;
void XBEE_UART_RestoreConfig(void) ;
void XBEE_UART_Sleep(void) ;
void XBEE_UART_Wakeup(void) ;

/* Only if RX is enabled */
#if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )

    #if(XBEE_UART_RX_INTERRUPT_ENABLED)
        void  XBEE_UART_EnableRxInt(void) ;
        void  XBEE_UART_DisableRxInt(void) ;
        CY_ISR_PROTO(XBEE_UART_RXISR);
    #endif /* XBEE_UART_RX_INTERRUPT_ENABLED */

    void XBEE_UART_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void XBEE_UART_SetRxAddress1(uint8 address) ;
    void XBEE_UART_SetRxAddress2(uint8 address) ;

    void  XBEE_UART_SetRxInterruptMode(uint8 intSrc) ;
    uint8 XBEE_UART_ReadRxData(void) ;
    uint8 XBEE_UART_ReadRxStatus(void) ;
    uint8 XBEE_UART_GetChar(void) ;
    uint16 XBEE_UART_GetByte(void) ;
    uint8 XBEE_UART_GetRxBufferSize(void)
                                                            ;
    void XBEE_UART_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define XBEE_UART_GetRxInterruptSource   XBEE_UART_ReadRxStatus

#endif /* End (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */

/* Only if TX is enabled */
#if(XBEE_UART_TX_ENABLED || XBEE_UART_HD_ENABLED)

    #if(XBEE_UART_TX_INTERRUPT_ENABLED)
        void XBEE_UART_EnableTxInt(void) ;
        void XBEE_UART_DisableTxInt(void) ;
        CY_ISR_PROTO(XBEE_UART_TXISR);
    #endif /* XBEE_UART_TX_INTERRUPT_ENABLED */

    void XBEE_UART_SetTxInterruptMode(uint8 intSrc) ;
    void XBEE_UART_WriteTxData(uint8 txDataByte) ;
    uint8 XBEE_UART_ReadTxStatus(void) ;
    void XBEE_UART_PutChar(uint8 txDataByte) ;
    void XBEE_UART_PutString(const char8 string[]) ;
    void XBEE_UART_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void XBEE_UART_PutCRLF(uint8 txDataByte) ;
    void XBEE_UART_ClearTxBuffer(void) ;
    void XBEE_UART_SetTxAddressMode(uint8 addressMode) ;
    void XBEE_UART_SendBreak(uint8 retMode) ;
    uint8 XBEE_UART_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define XBEE_UART_PutStringConst         XBEE_UART_PutString
    #define XBEE_UART_PutArrayConst          XBEE_UART_PutArray
    #define XBEE_UART_GetTxInterruptSource   XBEE_UART_ReadTxStatus

#endif /* End XBEE_UART_TX_ENABLED || XBEE_UART_HD_ENABLED */

#if(XBEE_UART_HD_ENABLED)
    void XBEE_UART_LoadRxConfig(void) ;
    void XBEE_UART_LoadTxConfig(void) ;
#endif /* End XBEE_UART_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBEE_UART) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    XBEE_UART_CyBtldrCommStart(void) CYSMALL ;
    void    XBEE_UART_CyBtldrCommStop(void) CYSMALL ;
    void    XBEE_UART_CyBtldrCommReset(void) CYSMALL ;
    cystatus XBEE_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus XBEE_UART_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBEE_UART)
        #define CyBtldrCommStart    XBEE_UART_CyBtldrCommStart
        #define CyBtldrCommStop     XBEE_UART_CyBtldrCommStop
        #define CyBtldrCommReset    XBEE_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    XBEE_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     XBEE_UART_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBEE_UART) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define XBEE_UART_BYTE2BYTE_TIME_OUT (25u)

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define XBEE_UART_SET_SPACE                              (0x00u)
#define XBEE_UART_SET_MARK                               (0x01u)

/* Status Register definitions */
#if( (XBEE_UART_TX_ENABLED) || (XBEE_UART_HD_ENABLED) )
    #if(XBEE_UART_TX_INTERRUPT_ENABLED)
        #define XBEE_UART_TX_VECT_NUM            (uint8)XBEE_UART_TXInternalInterrupt__INTC_NUMBER
        #define XBEE_UART_TX_PRIOR_NUM           (uint8)XBEE_UART_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* XBEE_UART_TX_INTERRUPT_ENABLED */
    #if(XBEE_UART_TX_ENABLED)
        #define XBEE_UART_TX_STS_COMPLETE_SHIFT          (0x00u)
        #define XBEE_UART_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
        #define XBEE_UART_TX_STS_FIFO_FULL_SHIFT         (0x02u)
        #define XBEE_UART_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #endif /* XBEE_UART_TX_ENABLED */
    #if(XBEE_UART_HD_ENABLED)
        #define XBEE_UART_TX_STS_COMPLETE_SHIFT          (0x00u)
        #define XBEE_UART_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
        #define XBEE_UART_TX_STS_FIFO_FULL_SHIFT         (0x05u)  /*needs MD=0*/
        #define XBEE_UART_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #endif /* XBEE_UART_HD_ENABLED */
    #define XBEE_UART_TX_STS_COMPLETE            (uint8)(0x01u << XBEE_UART_TX_STS_COMPLETE_SHIFT)
    #define XBEE_UART_TX_STS_FIFO_EMPTY          (uint8)(0x01u << XBEE_UART_TX_STS_FIFO_EMPTY_SHIFT)
    #define XBEE_UART_TX_STS_FIFO_FULL           (uint8)(0x01u << XBEE_UART_TX_STS_FIFO_FULL_SHIFT)
    #define XBEE_UART_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << XBEE_UART_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (XBEE_UART_TX_ENABLED) || (XBEE_UART_HD_ENABLED)*/

#if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
    #if(XBEE_UART_RX_INTERRUPT_ENABLED)
        #define XBEE_UART_RX_VECT_NUM            (uint8)XBEE_UART_RXInternalInterrupt__INTC_NUMBER
        #define XBEE_UART_RX_PRIOR_NUM           (uint8)XBEE_UART_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* XBEE_UART_RX_INTERRUPT_ENABLED */
    #define XBEE_UART_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define XBEE_UART_RX_STS_BREAK_SHIFT             (0x01u)
    #define XBEE_UART_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define XBEE_UART_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define XBEE_UART_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define XBEE_UART_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define XBEE_UART_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define XBEE_UART_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define XBEE_UART_RX_STS_MRKSPC           (uint8)(0x01u << XBEE_UART_RX_STS_MRKSPC_SHIFT)
    #define XBEE_UART_RX_STS_BREAK            (uint8)(0x01u << XBEE_UART_RX_STS_BREAK_SHIFT)
    #define XBEE_UART_RX_STS_PAR_ERROR        (uint8)(0x01u << XBEE_UART_RX_STS_PAR_ERROR_SHIFT)
    #define XBEE_UART_RX_STS_STOP_ERROR       (uint8)(0x01u << XBEE_UART_RX_STS_STOP_ERROR_SHIFT)
    #define XBEE_UART_RX_STS_OVERRUN          (uint8)(0x01u << XBEE_UART_RX_STS_OVERRUN_SHIFT)
    #define XBEE_UART_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << XBEE_UART_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define XBEE_UART_RX_STS_ADDR_MATCH       (uint8)(0x01u << XBEE_UART_RX_STS_ADDR_MATCH_SHIFT)
    #define XBEE_UART_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << XBEE_UART_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define XBEE_UART_RX_HW_MASK                     (0x7Fu)
#endif /* End (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */

/* Control Register definitions */
#define XBEE_UART_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define XBEE_UART_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define XBEE_UART_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define XBEE_UART_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define XBEE_UART_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define XBEE_UART_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define XBEE_UART_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define XBEE_UART_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define XBEE_UART_CTRL_HD_SEND               (uint8)(0x01u << XBEE_UART_CTRL_HD_SEND_SHIFT)
#define XBEE_UART_CTRL_HD_SEND_BREAK         (uint8)(0x01u << XBEE_UART_CTRL_HD_SEND_BREAK_SHIFT)
#define XBEE_UART_CTRL_MARK                  (uint8)(0x01u << XBEE_UART_CTRL_MARK_SHIFT)
#define XBEE_UART_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << XBEE_UART_CTRL_PARITY_TYPE0_SHIFT)
#define XBEE_UART_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << XBEE_UART_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define XBEE_UART_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define XBEE_UART_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define XBEE_UART_SEND_BREAK                         (0x00u)
#define XBEE_UART_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define XBEE_UART_REINIT                             (0x02u)
#define XBEE_UART_SEND_WAIT_REINIT                   (0x03u)

#define XBEE_UART_OVER_SAMPLE_8                      (8u)
#define XBEE_UART_OVER_SAMPLE_16                     (16u)

#define XBEE_UART_BIT_CENTER                         (XBEE_UART_OVER_SAMPLE_COUNT - 1u)

#define XBEE_UART_FIFO_LENGTH                        (4u)
#define XBEE_UART_NUMBER_OF_START_BIT                (1u)
#define XBEE_UART_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation*/
#define XBEE_UART_TXBITCTR_BREAKBITS8X   ((XBEE_UART_BREAK_BITS_TX * XBEE_UART_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation*/
#define XBEE_UART_TXBITCTR_BREAKBITS ((XBEE_UART_BREAK_BITS_TX * XBEE_UART_OVER_SAMPLE_COUNT) - 1u)

#define XBEE_UART_HALF_BIT_COUNT   \
                            (((XBEE_UART_OVER_SAMPLE_COUNT / 2u) + (XBEE_UART_USE23POLLING * 1u)) - 2u)
#if (XBEE_UART_OVER_SAMPLE_COUNT == XBEE_UART_OVER_SAMPLE_8)
    #define XBEE_UART_HD_TXBITCTR_INIT   (((XBEE_UART_BREAK_BITS_TX + \
                            XBEE_UART_NUMBER_OF_START_BIT) * XBEE_UART_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define XBEE_UART_RXBITCTR_INIT  ((((XBEE_UART_BREAK_BITS_RX + XBEE_UART_NUMBER_OF_START_BIT) \
                            * XBEE_UART_OVER_SAMPLE_COUNT) + XBEE_UART_HALF_BIT_COUNT) - 1u)


#else /* XBEE_UART_OVER_SAMPLE_COUNT == XBEE_UART_OVER_SAMPLE_16 */
    #define XBEE_UART_HD_TXBITCTR_INIT   ((8u * XBEE_UART_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount=16 */
    #define XBEE_UART_RXBITCTR_INIT      (((7u * XBEE_UART_OVER_SAMPLE_COUNT) - 1u) + \
                                                      XBEE_UART_HALF_BIT_COUNT)
#endif /* End XBEE_UART_OVER_SAMPLE_COUNT */
#define XBEE_UART_HD_RXBITCTR_INIT                   XBEE_UART_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 XBEE_UART_initVar;
#if( XBEE_UART_TX_ENABLED && (XBEE_UART_TXBUFFERSIZE > XBEE_UART_FIFO_LENGTH))
    extern volatile uint8 XBEE_UART_txBuffer[XBEE_UART_TXBUFFERSIZE];
    extern volatile uint8 XBEE_UART_txBufferRead;
    extern uint8 XBEE_UART_txBufferWrite;
#endif /* End XBEE_UART_TX_ENABLED */
#if( ( XBEE_UART_RX_ENABLED || XBEE_UART_HD_ENABLED ) && \
     (XBEE_UART_RXBUFFERSIZE > XBEE_UART_FIFO_LENGTH) )
    extern volatile uint8 XBEE_UART_rxBuffer[XBEE_UART_RXBUFFERSIZE];
    extern volatile uint8 XBEE_UART_rxBufferRead;
    extern volatile uint8 XBEE_UART_rxBufferWrite;
    extern volatile uint8 XBEE_UART_rxBufferLoopDetect;
    extern volatile uint8 XBEE_UART_rxBufferOverflow;
    #if (XBEE_UART_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 XBEE_UART_rxAddressMode;
        extern volatile uint8 XBEE_UART_rxAddressDetected;
    #endif /* End EnableHWAddress */
#endif /* End XBEE_UART_RX_ENABLED */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define XBEE_UART__B_UART__AM_SW_BYTE_BYTE 1
#define XBEE_UART__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define XBEE_UART__B_UART__AM_HW_BYTE_BY_BYTE 3
#define XBEE_UART__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define XBEE_UART__B_UART__AM_NONE 0

#define XBEE_UART__B_UART__NONE_REVB 0
#define XBEE_UART__B_UART__EVEN_REVB 1
#define XBEE_UART__B_UART__ODD_REVB 2
#define XBEE_UART__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define XBEE_UART_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define XBEE_UART_NUMBER_OF_STOP_BITS    (1u)

#if (XBEE_UART_RXHW_ADDRESS_ENABLED)
    #define XBEE_UART_RXADDRESSMODE      (0u)
    #define XBEE_UART_RXHWADDRESS1       (0u)
    #define XBEE_UART_RXHWADDRESS2       (0u)
    /* Backward compatible define */
    #define XBEE_UART_RXAddressMode      XBEE_UART_RXADDRESSMODE
#endif /* End EnableHWAddress */

#define XBEE_UART_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << XBEE_UART_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << XBEE_UART_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << XBEE_UART_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << XBEE_UART_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << XBEE_UART_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << XBEE_UART_RX_STS_BREAK_SHIFT) \
                                        | (0 << XBEE_UART_RX_STS_OVERRUN_SHIFT))

#define XBEE_UART_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << XBEE_UART_TX_STS_COMPLETE_SHIFT) \
                                        | (0 << XBEE_UART_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << XBEE_UART_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << XBEE_UART_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define XBEE_UART_CONTROL_REG \
                            (* (reg8 *) XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define XBEE_UART_CONTROL_PTR \
                            (  (reg8 *) XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(XBEE_UART_TX_ENABLED)
    #define XBEE_UART_TXDATA_REG          (* (reg8 *) XBEE_UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define XBEE_UART_TXDATA_PTR          (  (reg8 *) XBEE_UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define XBEE_UART_TXDATA_AUX_CTL_REG  (* (reg8 *) XBEE_UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define XBEE_UART_TXDATA_AUX_CTL_PTR  (  (reg8 *) XBEE_UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define XBEE_UART_TXSTATUS_REG        (* (reg8 *) XBEE_UART_BUART_sTX_TxSts__STATUS_REG)
    #define XBEE_UART_TXSTATUS_PTR        (  (reg8 *) XBEE_UART_BUART_sTX_TxSts__STATUS_REG)
    #define XBEE_UART_TXSTATUS_MASK_REG   (* (reg8 *) XBEE_UART_BUART_sTX_TxSts__MASK_REG)
    #define XBEE_UART_TXSTATUS_MASK_PTR   (  (reg8 *) XBEE_UART_BUART_sTX_TxSts__MASK_REG)
    #define XBEE_UART_TXSTATUS_ACTL_REG   (* (reg8 *) XBEE_UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define XBEE_UART_TXSTATUS_ACTL_PTR   (  (reg8 *) XBEE_UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(XBEE_UART_TXCLKGEN_DP)
        #define XBEE_UART_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define XBEE_UART_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define XBEE_UART_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define XBEE_UART_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define XBEE_UART_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define XBEE_UART_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define XBEE_UART_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define XBEE_UART_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define XBEE_UART_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define XBEE_UART_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) XBEE_UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* XBEE_UART_TXCLKGEN_DP */

#endif /* End XBEE_UART_TX_ENABLED */

#if(XBEE_UART_HD_ENABLED)

    #define XBEE_UART_TXDATA_REG             (* (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define XBEE_UART_TXDATA_PTR             (  (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define XBEE_UART_TXDATA_AUX_CTL_REG     (* (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define XBEE_UART_TXDATA_AUX_CTL_PTR     (  (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define XBEE_UART_TXSTATUS_REG           (* (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBEE_UART_TXSTATUS_PTR           (  (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBEE_UART_TXSTATUS_MASK_REG      (* (reg8 *) XBEE_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBEE_UART_TXSTATUS_MASK_PTR      (  (reg8 *) XBEE_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBEE_UART_TXSTATUS_ACTL_REG      (* (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define XBEE_UART_TXSTATUS_ACTL_PTR      (  (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End XBEE_UART_HD_ENABLED */

#if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
    #define XBEE_UART_RXDATA_REG             (* (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define XBEE_UART_RXDATA_PTR             (  (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define XBEE_UART_RXADDRESS1_REG         (* (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define XBEE_UART_RXADDRESS1_PTR         (  (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define XBEE_UART_RXADDRESS2_REG         (* (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define XBEE_UART_RXADDRESS2_PTR         (  (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define XBEE_UART_RXDATA_AUX_CTL_REG     (* (reg8 *) XBEE_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define XBEE_UART_RXBITCTR_PERIOD_REG    (* (reg8 *) XBEE_UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define XBEE_UART_RXBITCTR_PERIOD_PTR    (  (reg8 *) XBEE_UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define XBEE_UART_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) XBEE_UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define XBEE_UART_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) XBEE_UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define XBEE_UART_RXBITCTR_COUNTER_REG   (* (reg8 *) XBEE_UART_BUART_sRX_RxBitCounter__COUNT_REG )
    #define XBEE_UART_RXBITCTR_COUNTER_PTR   (  (reg8 *) XBEE_UART_BUART_sRX_RxBitCounter__COUNT_REG )

    #define XBEE_UART_RXSTATUS_REG           (* (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBEE_UART_RXSTATUS_PTR           (  (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBEE_UART_RXSTATUS_MASK_REG      (* (reg8 *) XBEE_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBEE_UART_RXSTATUS_MASK_PTR      (  (reg8 *) XBEE_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBEE_UART_RXSTATUS_ACTL_REG      (* (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define XBEE_UART_RXSTATUS_ACTL_PTR      (  (reg8 *) XBEE_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */

#if(XBEE_UART_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define XBEE_UART_INTCLOCK_CLKEN_REG     (* (reg8 *) XBEE_UART_IntClock__PM_ACT_CFG)
    #define XBEE_UART_INTCLOCK_CLKEN_PTR     (  (reg8 *) XBEE_UART_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define XBEE_UART_INTCLOCK_CLKEN_MASK    XBEE_UART_IntClock__PM_ACT_MSK
#endif /* End XBEE_UART_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(XBEE_UART_TX_ENABLED)
    #define XBEE_UART_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End XBEE_UART_TX_ENABLED */

#if(XBEE_UART_HD_ENABLED)
    #define XBEE_UART_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End XBEE_UART_HD_ENABLED */

#if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
    #define XBEE_UART_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */


/***************************************
* Renamed global variables or defines
* for backward compatible
***************************************/

#define XBEE_UART_initvar                    XBEE_UART_initVar

#define XBEE_UART_RX_Enabled                 XBEE_UART_RX_ENABLED
#define XBEE_UART_TX_Enabled                 XBEE_UART_TX_ENABLED
#define XBEE_UART_HD_Enabled                 XBEE_UART_HD_ENABLED
#define XBEE_UART_RX_IntInterruptEnabled     XBEE_UART_RX_INTERRUPT_ENABLED
#define XBEE_UART_TX_IntInterruptEnabled     XBEE_UART_TX_INTERRUPT_ENABLED
#define XBEE_UART_InternalClockUsed          XBEE_UART_INTERNAL_CLOCK_USED
#define XBEE_UART_RXHW_Address_Enabled       XBEE_UART_RXHW_ADDRESS_ENABLED
#define XBEE_UART_OverSampleCount            XBEE_UART_OVER_SAMPLE_COUNT
#define XBEE_UART_ParityType                 XBEE_UART_PARITY_TYPE

#if( XBEE_UART_TX_ENABLED && (XBEE_UART_TXBUFFERSIZE > XBEE_UART_FIFO_LENGTH))
    #define XBEE_UART_TXBUFFER               XBEE_UART_txBuffer
    #define XBEE_UART_TXBUFFERREAD           XBEE_UART_txBufferRead
    #define XBEE_UART_TXBUFFERWRITE          XBEE_UART_txBufferWrite
#endif /* End XBEE_UART_TX_ENABLED */
#if( ( XBEE_UART_RX_ENABLED || XBEE_UART_HD_ENABLED ) && \
     (XBEE_UART_RXBUFFERSIZE > XBEE_UART_FIFO_LENGTH) )
    #define XBEE_UART_RXBUFFER               XBEE_UART_rxBuffer
    #define XBEE_UART_RXBUFFERREAD           XBEE_UART_rxBufferRead
    #define XBEE_UART_RXBUFFERWRITE          XBEE_UART_rxBufferWrite
    #define XBEE_UART_RXBUFFERLOOPDETECT     XBEE_UART_rxBufferLoopDetect
    #define XBEE_UART_RXBUFFER_OVERFLOW      XBEE_UART_rxBufferOverflow
#endif /* End XBEE_UART_RX_ENABLED */

#ifdef XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define XBEE_UART_CONTROL                XBEE_UART_CONTROL_REG
#endif /* End XBEE_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(XBEE_UART_TX_ENABLED)
    #define XBEE_UART_TXDATA                 XBEE_UART_TXDATA_REG
    #define XBEE_UART_TXSTATUS               XBEE_UART_TXSTATUS_REG
    #define XBEE_UART_TXSTATUS_MASK          XBEE_UART_TXSTATUS_MASK_REG
    #define XBEE_UART_TXSTATUS_ACTL          XBEE_UART_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(XBEE_UART_TXCLKGEN_DP)
        #define XBEE_UART_TXBITCLKGEN_CTR        XBEE_UART_TXBITCLKGEN_CTR_REG
        #define XBEE_UART_TXBITCLKTX_COMPLETE    XBEE_UART_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define XBEE_UART_TXBITCTR_PERIOD        XBEE_UART_TXBITCTR_PERIOD_REG
        #define XBEE_UART_TXBITCTR_CONTROL       XBEE_UART_TXBITCTR_CONTROL_REG
        #define XBEE_UART_TXBITCTR_COUNTER       XBEE_UART_TXBITCTR_COUNTER_REG
    #endif /* XBEE_UART_TXCLKGEN_DP */
#endif /* End XBEE_UART_TX_ENABLED */

#if(XBEE_UART_HD_ENABLED)
    #define XBEE_UART_TXDATA                 XBEE_UART_TXDATA_REG
    #define XBEE_UART_TXSTATUS               XBEE_UART_TXSTATUS_REG
    #define XBEE_UART_TXSTATUS_MASK          XBEE_UART_TXSTATUS_MASK_REG
    #define XBEE_UART_TXSTATUS_ACTL          XBEE_UART_TXSTATUS_ACTL_REG
#endif /* End XBEE_UART_HD_ENABLED */

#if( (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) )
    #define XBEE_UART_RXDATA                 XBEE_UART_RXDATA_REG
    #define XBEE_UART_RXADDRESS1             XBEE_UART_RXADDRESS1_REG
    #define XBEE_UART_RXADDRESS2             XBEE_UART_RXADDRESS2_REG
    #define XBEE_UART_RXBITCTR_PERIOD        XBEE_UART_RXBITCTR_PERIOD_REG
    #define XBEE_UART_RXBITCTR_CONTROL       XBEE_UART_RXBITCTR_CONTROL_REG
    #define XBEE_UART_RXBITCTR_COUNTER       XBEE_UART_RXBITCTR_COUNTER_REG
    #define XBEE_UART_RXSTATUS               XBEE_UART_RXSTATUS_REG
    #define XBEE_UART_RXSTATUS_MASK          XBEE_UART_RXSTATUS_MASK_REG
    #define XBEE_UART_RXSTATUS_ACTL          XBEE_UART_RXSTATUS_ACTL_REG
#endif /* End  (XBEE_UART_RX_ENABLED) || (XBEE_UART_HD_ENABLED) */

#if(XBEE_UART_INTERNAL_CLOCK_USED)
    #define XBEE_UART_INTCLOCK_CLKEN         XBEE_UART_INTCLOCK_CLKEN_REG
#endif /* End XBEE_UART_INTERNAL_CLOCK_USED */

#define XBEE_UART_WAIT_FOR_COMLETE_REINIT    XBEE_UART_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_XBEE_UART_H */


/* [] END OF FILE */
