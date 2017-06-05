    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; LED
LED__0__DM__MASK EQU 0xE00000
LED__0__DM__SHIFT EQU 21
LED__0__DR EQU CYREG_PRT0_DR
LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LED__0__HSIOM_MASK EQU 0xF0000000
LED__0__HSIOM_SHIFT EQU 28
LED__0__INTCFG EQU CYREG_PRT0_INTCFG
LED__0__INTSTAT EQU CYREG_PRT0_INTSTAT
LED__0__MASK EQU 0x80
LED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LED__0__PC EQU CYREG_PRT0_PC
LED__0__PC2 EQU CYREG_PRT0_PC2
LED__0__PORT EQU 0
LED__0__PS EQU CYREG_PRT0_PS
LED__0__SHIFT EQU 7
LED__DR EQU CYREG_PRT0_DR
LED__INTCFG EQU CYREG_PRT0_INTCFG
LED__INTSTAT EQU CYREG_PRT0_INTSTAT
LED__MASK EQU 0x80
LED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LED__PC EQU CYREG_PRT0_PC
LED__PC2 EQU CYREG_PRT0_PC2
LED__PORT EQU 0
LED__PS EQU CYREG_PRT0_PS
LED__SHIFT EQU 7

; XBEE_RESET
XBEE_RESET__0__DM__MASK EQU 0x07
XBEE_RESET__0__DM__SHIFT EQU 0
XBEE_RESET__0__DR EQU CYREG_PRT0_DR
XBEE_RESET__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
XBEE_RESET__0__HSIOM_MASK EQU 0x0000000F
XBEE_RESET__0__HSIOM_SHIFT EQU 0
XBEE_RESET__0__INTCFG EQU CYREG_PRT0_INTCFG
XBEE_RESET__0__INTSTAT EQU CYREG_PRT0_INTSTAT
XBEE_RESET__0__MASK EQU 0x01
XBEE_RESET__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
XBEE_RESET__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
XBEE_RESET__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
XBEE_RESET__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
XBEE_RESET__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
XBEE_RESET__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
XBEE_RESET__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
XBEE_RESET__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
XBEE_RESET__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
XBEE_RESET__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
XBEE_RESET__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
XBEE_RESET__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
XBEE_RESET__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
XBEE_RESET__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
XBEE_RESET__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
XBEE_RESET__0__PC EQU CYREG_PRT0_PC
XBEE_RESET__0__PC2 EQU CYREG_PRT0_PC2
XBEE_RESET__0__PORT EQU 0
XBEE_RESET__0__PS EQU CYREG_PRT0_PS
XBEE_RESET__0__SHIFT EQU 0
XBEE_RESET__DR EQU CYREG_PRT0_DR
XBEE_RESET__INTCFG EQU CYREG_PRT0_INTCFG
XBEE_RESET__INTSTAT EQU CYREG_PRT0_INTSTAT
XBEE_RESET__MASK EQU 0x01
XBEE_RESET__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
XBEE_RESET__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
XBEE_RESET__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
XBEE_RESET__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
XBEE_RESET__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
XBEE_RESET__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
XBEE_RESET__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
XBEE_RESET__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
XBEE_RESET__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
XBEE_RESET__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
XBEE_RESET__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
XBEE_RESET__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
XBEE_RESET__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
XBEE_RESET__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
XBEE_RESET__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
XBEE_RESET__PC EQU CYREG_PRT0_PC
XBEE_RESET__PC2 EQU CYREG_PRT0_PC2
XBEE_RESET__PORT EQU 0
XBEE_RESET__PS EQU CYREG_PRT0_PS
XBEE_RESET__SHIFT EQU 0

; XBEE_RX_INT
XBEE_RX_INT__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
XBEE_RX_INT__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
XBEE_RX_INT__INTC_MASK EQU 0x400
XBEE_RX_INT__INTC_NUMBER EQU 10
XBEE_RX_INT__INTC_PRIOR_MASK EQU 0xC00000
XBEE_RX_INT__INTC_PRIOR_NUM EQU 3
XBEE_RX_INT__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
XBEE_RX_INT__INTC_SET_EN_REG EQU CYREG_CM0_ISER
XBEE_RX_INT__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; XBEE_SLEEP_RQ
XBEE_SLEEP_RQ__0__DM__MASK EQU 0xE00
XBEE_SLEEP_RQ__0__DM__SHIFT EQU 9
XBEE_SLEEP_RQ__0__DR EQU CYREG_PRT0_DR
XBEE_SLEEP_RQ__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
XBEE_SLEEP_RQ__0__HSIOM_MASK EQU 0x0000F000
XBEE_SLEEP_RQ__0__HSIOM_SHIFT EQU 12
XBEE_SLEEP_RQ__0__INTCFG EQU CYREG_PRT0_INTCFG
XBEE_SLEEP_RQ__0__INTSTAT EQU CYREG_PRT0_INTSTAT
XBEE_SLEEP_RQ__0__MASK EQU 0x08
XBEE_SLEEP_RQ__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
XBEE_SLEEP_RQ__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
XBEE_SLEEP_RQ__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
XBEE_SLEEP_RQ__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
XBEE_SLEEP_RQ__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
XBEE_SLEEP_RQ__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
XBEE_SLEEP_RQ__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
XBEE_SLEEP_RQ__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
XBEE_SLEEP_RQ__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
XBEE_SLEEP_RQ__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
XBEE_SLEEP_RQ__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
XBEE_SLEEP_RQ__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
XBEE_SLEEP_RQ__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
XBEE_SLEEP_RQ__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
XBEE_SLEEP_RQ__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
XBEE_SLEEP_RQ__0__PC EQU CYREG_PRT0_PC
XBEE_SLEEP_RQ__0__PC2 EQU CYREG_PRT0_PC2
XBEE_SLEEP_RQ__0__PORT EQU 0
XBEE_SLEEP_RQ__0__PS EQU CYREG_PRT0_PS
XBEE_SLEEP_RQ__0__SHIFT EQU 3
XBEE_SLEEP_RQ__DR EQU CYREG_PRT0_DR
XBEE_SLEEP_RQ__INTCFG EQU CYREG_PRT0_INTCFG
XBEE_SLEEP_RQ__INTSTAT EQU CYREG_PRT0_INTSTAT
XBEE_SLEEP_RQ__MASK EQU 0x08
XBEE_SLEEP_RQ__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
XBEE_SLEEP_RQ__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
XBEE_SLEEP_RQ__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
XBEE_SLEEP_RQ__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
XBEE_SLEEP_RQ__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
XBEE_SLEEP_RQ__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
XBEE_SLEEP_RQ__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
XBEE_SLEEP_RQ__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
XBEE_SLEEP_RQ__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
XBEE_SLEEP_RQ__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
XBEE_SLEEP_RQ__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
XBEE_SLEEP_RQ__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
XBEE_SLEEP_RQ__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
XBEE_SLEEP_RQ__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
XBEE_SLEEP_RQ__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
XBEE_SLEEP_RQ__PC EQU CYREG_PRT0_PC
XBEE_SLEEP_RQ__PC2 EQU CYREG_PRT0_PC2
XBEE_SLEEP_RQ__PORT EQU 0
XBEE_SLEEP_RQ__PS EQU CYREG_PRT0_PS
XBEE_SLEEP_RQ__SHIFT EQU 3

; XBEE_UART_rx
XBEE_UART_rx__0__DM__MASK EQU 0x07
XBEE_UART_rx__0__DM__SHIFT EQU 0
XBEE_UART_rx__0__DR EQU CYREG_PRT4_DR
XBEE_UART_rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
XBEE_UART_rx__0__HSIOM_GPIO EQU 0
XBEE_UART_rx__0__HSIOM_I2C EQU 14
XBEE_UART_rx__0__HSIOM_I2C_SCL EQU 14
XBEE_UART_rx__0__HSIOM_MASK EQU 0x0000000F
XBEE_UART_rx__0__HSIOM_SHIFT EQU 0
XBEE_UART_rx__0__HSIOM_SPI EQU 15
XBEE_UART_rx__0__HSIOM_SPI_MOSI EQU 15
XBEE_UART_rx__0__HSIOM_UART EQU 9
XBEE_UART_rx__0__HSIOM_UART_RX EQU 9
XBEE_UART_rx__0__INTCFG EQU CYREG_PRT4_INTCFG
XBEE_UART_rx__0__INTSTAT EQU CYREG_PRT4_INTSTAT
XBEE_UART_rx__0__MASK EQU 0x01
XBEE_UART_rx__0__PC EQU CYREG_PRT4_PC
XBEE_UART_rx__0__PC2 EQU CYREG_PRT4_PC2
XBEE_UART_rx__0__PORT EQU 4
XBEE_UART_rx__0__PS EQU CYREG_PRT4_PS
XBEE_UART_rx__0__SHIFT EQU 0
XBEE_UART_rx__DR EQU CYREG_PRT4_DR
XBEE_UART_rx__INTCFG EQU CYREG_PRT4_INTCFG
XBEE_UART_rx__INTSTAT EQU CYREG_PRT4_INTSTAT
XBEE_UART_rx__MASK EQU 0x01
XBEE_UART_rx__PC EQU CYREG_PRT4_PC
XBEE_UART_rx__PC2 EQU CYREG_PRT4_PC2
XBEE_UART_rx__PORT EQU 4
XBEE_UART_rx__PS EQU CYREG_PRT4_PS
XBEE_UART_rx__SHIFT EQU 0

; XBEE_UART_SCB
XBEE_UART_SCB__BIST_CONTROL EQU CYREG_SCB0_BIST_CONTROL
XBEE_UART_SCB__BIST_DATA EQU CYREG_SCB0_BIST_DATA
XBEE_UART_SCB__CTRL EQU CYREG_SCB0_CTRL
XBEE_UART_SCB__EZ_DATA00 EQU CYREG_SCB0_EZ_DATA00
XBEE_UART_SCB__EZ_DATA01 EQU CYREG_SCB0_EZ_DATA01
XBEE_UART_SCB__EZ_DATA02 EQU CYREG_SCB0_EZ_DATA02
XBEE_UART_SCB__EZ_DATA03 EQU CYREG_SCB0_EZ_DATA03
XBEE_UART_SCB__EZ_DATA04 EQU CYREG_SCB0_EZ_DATA04
XBEE_UART_SCB__EZ_DATA05 EQU CYREG_SCB0_EZ_DATA05
XBEE_UART_SCB__EZ_DATA06 EQU CYREG_SCB0_EZ_DATA06
XBEE_UART_SCB__EZ_DATA07 EQU CYREG_SCB0_EZ_DATA07
XBEE_UART_SCB__EZ_DATA08 EQU CYREG_SCB0_EZ_DATA08
XBEE_UART_SCB__EZ_DATA09 EQU CYREG_SCB0_EZ_DATA09
XBEE_UART_SCB__EZ_DATA10 EQU CYREG_SCB0_EZ_DATA10
XBEE_UART_SCB__EZ_DATA11 EQU CYREG_SCB0_EZ_DATA11
XBEE_UART_SCB__EZ_DATA12 EQU CYREG_SCB0_EZ_DATA12
XBEE_UART_SCB__EZ_DATA13 EQU CYREG_SCB0_EZ_DATA13
XBEE_UART_SCB__EZ_DATA14 EQU CYREG_SCB0_EZ_DATA14
XBEE_UART_SCB__EZ_DATA15 EQU CYREG_SCB0_EZ_DATA15
XBEE_UART_SCB__EZ_DATA16 EQU CYREG_SCB0_EZ_DATA16
XBEE_UART_SCB__EZ_DATA17 EQU CYREG_SCB0_EZ_DATA17
XBEE_UART_SCB__EZ_DATA18 EQU CYREG_SCB0_EZ_DATA18
XBEE_UART_SCB__EZ_DATA19 EQU CYREG_SCB0_EZ_DATA19
XBEE_UART_SCB__EZ_DATA20 EQU CYREG_SCB0_EZ_DATA20
XBEE_UART_SCB__EZ_DATA21 EQU CYREG_SCB0_EZ_DATA21
XBEE_UART_SCB__EZ_DATA22 EQU CYREG_SCB0_EZ_DATA22
XBEE_UART_SCB__EZ_DATA23 EQU CYREG_SCB0_EZ_DATA23
XBEE_UART_SCB__EZ_DATA24 EQU CYREG_SCB0_EZ_DATA24
XBEE_UART_SCB__EZ_DATA25 EQU CYREG_SCB0_EZ_DATA25
XBEE_UART_SCB__EZ_DATA26 EQU CYREG_SCB0_EZ_DATA26
XBEE_UART_SCB__EZ_DATA27 EQU CYREG_SCB0_EZ_DATA27
XBEE_UART_SCB__EZ_DATA28 EQU CYREG_SCB0_EZ_DATA28
XBEE_UART_SCB__EZ_DATA29 EQU CYREG_SCB0_EZ_DATA29
XBEE_UART_SCB__EZ_DATA30 EQU CYREG_SCB0_EZ_DATA30
XBEE_UART_SCB__EZ_DATA31 EQU CYREG_SCB0_EZ_DATA31
XBEE_UART_SCB__I2C_CFG EQU CYREG_SCB0_I2C_CFG
XBEE_UART_SCB__I2C_CTRL EQU CYREG_SCB0_I2C_CTRL
XBEE_UART_SCB__I2C_M_CMD EQU CYREG_SCB0_I2C_M_CMD
XBEE_UART_SCB__I2C_S_CMD EQU CYREG_SCB0_I2C_S_CMD
XBEE_UART_SCB__I2C_STATUS EQU CYREG_SCB0_I2C_STATUS
XBEE_UART_SCB__INTR_CAUSE EQU CYREG_SCB0_INTR_CAUSE
XBEE_UART_SCB__INTR_I2C_EC EQU CYREG_SCB0_INTR_I2C_EC
XBEE_UART_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB0_INTR_I2C_EC_MASK
XBEE_UART_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB0_INTR_I2C_EC_MASKED
XBEE_UART_SCB__INTR_M EQU CYREG_SCB0_INTR_M
XBEE_UART_SCB__INTR_M_MASK EQU CYREG_SCB0_INTR_M_MASK
XBEE_UART_SCB__INTR_M_MASKED EQU CYREG_SCB0_INTR_M_MASKED
XBEE_UART_SCB__INTR_M_SET EQU CYREG_SCB0_INTR_M_SET
XBEE_UART_SCB__INTR_RX EQU CYREG_SCB0_INTR_RX
XBEE_UART_SCB__INTR_RX_MASK EQU CYREG_SCB0_INTR_RX_MASK
XBEE_UART_SCB__INTR_RX_MASKED EQU CYREG_SCB0_INTR_RX_MASKED
XBEE_UART_SCB__INTR_RX_SET EQU CYREG_SCB0_INTR_RX_SET
XBEE_UART_SCB__INTR_S EQU CYREG_SCB0_INTR_S
XBEE_UART_SCB__INTR_S_MASK EQU CYREG_SCB0_INTR_S_MASK
XBEE_UART_SCB__INTR_S_MASKED EQU CYREG_SCB0_INTR_S_MASKED
XBEE_UART_SCB__INTR_S_SET EQU CYREG_SCB0_INTR_S_SET
XBEE_UART_SCB__INTR_SPI_EC EQU CYREG_SCB0_INTR_SPI_EC
XBEE_UART_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB0_INTR_SPI_EC_MASK
XBEE_UART_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB0_INTR_SPI_EC_MASKED
XBEE_UART_SCB__INTR_TX EQU CYREG_SCB0_INTR_TX
XBEE_UART_SCB__INTR_TX_MASK EQU CYREG_SCB0_INTR_TX_MASK
XBEE_UART_SCB__INTR_TX_MASKED EQU CYREG_SCB0_INTR_TX_MASKED
XBEE_UART_SCB__INTR_TX_SET EQU CYREG_SCB0_INTR_TX_SET
XBEE_UART_SCB__RX_CTRL EQU CYREG_SCB0_RX_CTRL
XBEE_UART_SCB__RX_FIFO_CTRL EQU CYREG_SCB0_RX_FIFO_CTRL
XBEE_UART_SCB__RX_FIFO_RD EQU CYREG_SCB0_RX_FIFO_RD
XBEE_UART_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB0_RX_FIFO_RD_SILENT
XBEE_UART_SCB__RX_FIFO_STATUS EQU CYREG_SCB0_RX_FIFO_STATUS
XBEE_UART_SCB__RX_MATCH EQU CYREG_SCB0_RX_MATCH
XBEE_UART_SCB__SPI_CTRL EQU CYREG_SCB0_SPI_CTRL
XBEE_UART_SCB__SPI_STATUS EQU CYREG_SCB0_SPI_STATUS
XBEE_UART_SCB__SS0_POSISTION EQU 0
XBEE_UART_SCB__SS1_POSISTION EQU 1
XBEE_UART_SCB__SS2_POSISTION EQU 2
XBEE_UART_SCB__SS3_POSISTION EQU 3
XBEE_UART_SCB__STATUS EQU CYREG_SCB0_STATUS
XBEE_UART_SCB__TX_CTRL EQU CYREG_SCB0_TX_CTRL
XBEE_UART_SCB__TX_FIFO_CTRL EQU CYREG_SCB0_TX_FIFO_CTRL
XBEE_UART_SCB__TX_FIFO_STATUS EQU CYREG_SCB0_TX_FIFO_STATUS
XBEE_UART_SCB__TX_FIFO_WR EQU CYREG_SCB0_TX_FIFO_WR
XBEE_UART_SCB__UART_CTRL EQU CYREG_SCB0_UART_CTRL
XBEE_UART_SCB__UART_RX_CTRL EQU CYREG_SCB0_UART_RX_CTRL
XBEE_UART_SCB__UART_RX_STATUS EQU CYREG_SCB0_UART_RX_STATUS
XBEE_UART_SCB__UART_TX_CTRL EQU CYREG_SCB0_UART_TX_CTRL

; XBEE_UART_SCBCLK
XBEE_UART_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
XBEE_UART_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_A00
XBEE_UART_SCBCLK__ENABLE_MASK EQU 0x80000000
XBEE_UART_SCBCLK__MASK EQU 0x80000000
XBEE_UART_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_A00

; XBEE_UART_tx
XBEE_UART_tx__0__DM__MASK EQU 0x38
XBEE_UART_tx__0__DM__SHIFT EQU 3
XBEE_UART_tx__0__DR EQU CYREG_PRT4_DR
XBEE_UART_tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
XBEE_UART_tx__0__HSIOM_GPIO EQU 0
XBEE_UART_tx__0__HSIOM_I2C EQU 14
XBEE_UART_tx__0__HSIOM_I2C_SDA EQU 14
XBEE_UART_tx__0__HSIOM_MASK EQU 0x000000F0
XBEE_UART_tx__0__HSIOM_SHIFT EQU 4
XBEE_UART_tx__0__HSIOM_SPI EQU 15
XBEE_UART_tx__0__HSIOM_SPI_MISO EQU 15
XBEE_UART_tx__0__HSIOM_UART EQU 9
XBEE_UART_tx__0__HSIOM_UART_TX EQU 9
XBEE_UART_tx__0__INTCFG EQU CYREG_PRT4_INTCFG
XBEE_UART_tx__0__INTSTAT EQU CYREG_PRT4_INTSTAT
XBEE_UART_tx__0__MASK EQU 0x02
XBEE_UART_tx__0__PC EQU CYREG_PRT4_PC
XBEE_UART_tx__0__PC2 EQU CYREG_PRT4_PC2
XBEE_UART_tx__0__PORT EQU 4
XBEE_UART_tx__0__PS EQU CYREG_PRT4_PS
XBEE_UART_tx__0__SHIFT EQU 1
XBEE_UART_tx__DR EQU CYREG_PRT4_DR
XBEE_UART_tx__INTCFG EQU CYREG_PRT4_INTCFG
XBEE_UART_tx__INTSTAT EQU CYREG_PRT4_INTSTAT
XBEE_UART_tx__MASK EQU 0x02
XBEE_UART_tx__PC EQU CYREG_PRT4_PC
XBEE_UART_tx__PC2 EQU CYREG_PRT4_PC2
XBEE_UART_tx__PORT EQU 4
XBEE_UART_tx__PS EQU CYREG_PRT4_PS
XBEE_UART_tx__SHIFT EQU 1

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 32000000
CYDEV_BCLK__HFCLK__KHZ EQU 32000
CYDEV_BCLK__HFCLK__MHZ EQU 32
CYDEV_BCLK__SYSCLK__HZ EQU 32000000
CYDEV_BCLK__SYSCLK__KHZ EQU 32000
CYDEV_BCLK__SYSCLK__MHZ EQU 32
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 12
CYDEV_CHIP_DIE_PSOC5LP EQU 19
CYDEV_CHIP_DIE_PSOC5TM EQU 20
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 4
CYDEV_CHIP_FAMILY_FM3 EQU 5
CYDEV_CHIP_FAMILY_FM4 EQU 6
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 12
CYDEV_CHIP_MEMBER_4C EQU 18
CYDEV_CHIP_MEMBER_4D EQU 8
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 13
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 11
CYDEV_CHIP_MEMBER_4I EQU 17
CYDEV_CHIP_MEMBER_4J EQU 9
CYDEV_CHIP_MEMBER_4K EQU 10
CYDEV_CHIP_MEMBER_4L EQU 16
CYDEV_CHIP_MEMBER_4M EQU 15
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4P EQU 14
CYDEV_CHIP_MEMBER_4Q EQU 7
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 20
CYDEV_CHIP_MEMBER_5B EQU 19
CYDEV_CHIP_MEMBER_FM3 EQU 24
CYDEV_CHIP_MEMBER_FM4 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 21
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 22
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 23
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END