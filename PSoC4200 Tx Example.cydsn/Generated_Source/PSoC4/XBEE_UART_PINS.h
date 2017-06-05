/***************************************************************************//**
* \file XBEE_UART_PINS.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_XBEE_UART_H)
#define CY_SCB_PINS_XBEE_UART_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define XBEE_UART_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define XBEE_UART_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define XBEE_UART_REMOVE_TX_SDA_MISO_PIN      (1u)
#define XBEE_UART_REMOVE_SCLK_PIN      (1u)
#define XBEE_UART_REMOVE_SS0_PIN      (1u)
#define XBEE_UART_REMOVE_SS1_PIN                 (1u)
#define XBEE_UART_REMOVE_SS2_PIN                 (1u)
#define XBEE_UART_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define XBEE_UART_REMOVE_I2C_PINS                (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_PINS         (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define XBEE_UART_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define XBEE_UART_REMOVE_SPI_SLAVE_PINS          (1u)
#define XBEE_UART_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define XBEE_UART_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define XBEE_UART_REMOVE_UART_TX_PIN             (0u)
#define XBEE_UART_REMOVE_UART_RX_TX_PIN          (1u)
#define XBEE_UART_REMOVE_UART_RX_PIN             (0u)
#define XBEE_UART_REMOVE_UART_RX_WAKE_PIN        (1u)
#define XBEE_UART_REMOVE_UART_RTS_PIN            (1u)
#define XBEE_UART_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define XBEE_UART_RX_WAKE_SCL_MOSI_PIN (0u == XBEE_UART_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define XBEE_UART_RX_SCL_MOSI_PIN     (0u == XBEE_UART_REMOVE_RX_SCL_MOSI_PIN)
#define XBEE_UART_TX_SDA_MISO_PIN     (0u == XBEE_UART_REMOVE_TX_SDA_MISO_PIN)
#define XBEE_UART_SCLK_PIN     (0u == XBEE_UART_REMOVE_SCLK_PIN)
#define XBEE_UART_SS0_PIN     (0u == XBEE_UART_REMOVE_SS0_PIN)
#define XBEE_UART_SS1_PIN                (0u == XBEE_UART_REMOVE_SS1_PIN)
#define XBEE_UART_SS2_PIN                (0u == XBEE_UART_REMOVE_SS2_PIN)
#define XBEE_UART_SS3_PIN                (0u == XBEE_UART_REMOVE_SS3_PIN)

/* Mode defined pins */
#define XBEE_UART_I2C_PINS               (0u == XBEE_UART_REMOVE_I2C_PINS)
#define XBEE_UART_SPI_MASTER_PINS        (0u == XBEE_UART_REMOVE_SPI_MASTER_PINS)
#define XBEE_UART_SPI_MASTER_SCLK_PIN    (0u == XBEE_UART_REMOVE_SPI_MASTER_SCLK_PIN)
#define XBEE_UART_SPI_MASTER_MOSI_PIN    (0u == XBEE_UART_REMOVE_SPI_MASTER_MOSI_PIN)
#define XBEE_UART_SPI_MASTER_MISO_PIN    (0u == XBEE_UART_REMOVE_SPI_MASTER_MISO_PIN)
#define XBEE_UART_SPI_MASTER_SS0_PIN     (0u == XBEE_UART_REMOVE_SPI_MASTER_SS0_PIN)
#define XBEE_UART_SPI_MASTER_SS1_PIN     (0u == XBEE_UART_REMOVE_SPI_MASTER_SS1_PIN)
#define XBEE_UART_SPI_MASTER_SS2_PIN     (0u == XBEE_UART_REMOVE_SPI_MASTER_SS2_PIN)
#define XBEE_UART_SPI_MASTER_SS3_PIN     (0u == XBEE_UART_REMOVE_SPI_MASTER_SS3_PIN)
#define XBEE_UART_SPI_SLAVE_PINS         (0u == XBEE_UART_REMOVE_SPI_SLAVE_PINS)
#define XBEE_UART_SPI_SLAVE_MOSI_PIN     (0u == XBEE_UART_REMOVE_SPI_SLAVE_MOSI_PIN)
#define XBEE_UART_SPI_SLAVE_MISO_PIN     (0u == XBEE_UART_REMOVE_SPI_SLAVE_MISO_PIN)
#define XBEE_UART_UART_TX_PIN            (0u == XBEE_UART_REMOVE_UART_TX_PIN)
#define XBEE_UART_UART_RX_TX_PIN         (0u == XBEE_UART_REMOVE_UART_RX_TX_PIN)
#define XBEE_UART_UART_RX_PIN            (0u == XBEE_UART_REMOVE_UART_RX_PIN)
#define XBEE_UART_UART_RX_WAKE_PIN       (0u == XBEE_UART_REMOVE_UART_RX_WAKE_PIN)
#define XBEE_UART_UART_RTS_PIN           (0u == XBEE_UART_REMOVE_UART_RTS_PIN)
#define XBEE_UART_UART_CTS_PIN           (0u == XBEE_UART_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (XBEE_UART_RX_WAKE_SCL_MOSI_PIN)
    #include "XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (XBEE_UART_RX_SCL_MOSI) */

#if (XBEE_UART_RX_SCL_MOSI_PIN)
    #include "XBEE_UART_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (XBEE_UART_RX_SCL_MOSI) */

#if (XBEE_UART_TX_SDA_MISO_PIN)
    #include "XBEE_UART_uart_tx_i2c_sda_spi_miso.h"
#endif /* (XBEE_UART_TX_SDA_MISO) */

#if (XBEE_UART_SCLK_PIN)
    #include "XBEE_UART_spi_sclk.h"
#endif /* (XBEE_UART_SCLK) */

#if (XBEE_UART_SS0_PIN)
    #include "XBEE_UART_spi_ss0.h"
#endif /* (XBEE_UART_SS0_PIN) */

#if (XBEE_UART_SS1_PIN)
    #include "XBEE_UART_spi_ss1.h"
#endif /* (XBEE_UART_SS1_PIN) */

#if (XBEE_UART_SS2_PIN)
    #include "XBEE_UART_spi_ss2.h"
#endif /* (XBEE_UART_SS2_PIN) */

#if (XBEE_UART_SS3_PIN)
    #include "XBEE_UART_spi_ss3.h"
#endif /* (XBEE_UART_SS3_PIN) */

#if (XBEE_UART_I2C_PINS)
    #include "XBEE_UART_scl.h"
    #include "XBEE_UART_sda.h"
#endif /* (XBEE_UART_I2C_PINS) */

#if (XBEE_UART_SPI_MASTER_PINS)
#if (XBEE_UART_SPI_MASTER_SCLK_PIN)
    #include "XBEE_UART_sclk_m.h"
#endif /* (XBEE_UART_SPI_MASTER_SCLK_PIN) */

#if (XBEE_UART_SPI_MASTER_MOSI_PIN)
    #include "XBEE_UART_mosi_m.h"
#endif /* (XBEE_UART_SPI_MASTER_MOSI_PIN) */

#if (XBEE_UART_SPI_MASTER_MISO_PIN)
    #include "XBEE_UART_miso_m.h"
#endif /*(XBEE_UART_SPI_MASTER_MISO_PIN) */
#endif /* (XBEE_UART_SPI_MASTER_PINS) */

#if (XBEE_UART_SPI_SLAVE_PINS)
    #include "XBEE_UART_sclk_s.h"
    #include "XBEE_UART_ss_s.h"

#if (XBEE_UART_SPI_SLAVE_MOSI_PIN)
    #include "XBEE_UART_mosi_s.h"
#endif /* (XBEE_UART_SPI_SLAVE_MOSI_PIN) */

#if (XBEE_UART_SPI_SLAVE_MISO_PIN)
    #include "XBEE_UART_miso_s.h"
#endif /*(XBEE_UART_SPI_SLAVE_MISO_PIN) */
#endif /* (XBEE_UART_SPI_SLAVE_PINS) */

#if (XBEE_UART_SPI_MASTER_SS0_PIN)
    #include "XBEE_UART_ss0_m.h"
#endif /* (XBEE_UART_SPI_MASTER_SS0_PIN) */

#if (XBEE_UART_SPI_MASTER_SS1_PIN)
    #include "XBEE_UART_ss1_m.h"
#endif /* (XBEE_UART_SPI_MASTER_SS1_PIN) */

#if (XBEE_UART_SPI_MASTER_SS2_PIN)
    #include "XBEE_UART_ss2_m.h"
#endif /* (XBEE_UART_SPI_MASTER_SS2_PIN) */

#if (XBEE_UART_SPI_MASTER_SS3_PIN)
    #include "XBEE_UART_ss3_m.h"
#endif /* (XBEE_UART_SPI_MASTER_SS3_PIN) */

#if (XBEE_UART_UART_TX_PIN)
    #include "XBEE_UART_tx.h"
#endif /* (XBEE_UART_UART_TX_PIN) */

#if (XBEE_UART_UART_RX_TX_PIN)
    #include "XBEE_UART_rx_tx.h"
#endif /* (XBEE_UART_UART_RX_TX_PIN) */

#if (XBEE_UART_UART_RX_PIN)
    #include "XBEE_UART_rx.h"
#endif /* (XBEE_UART_UART_RX_PIN) */

#if (XBEE_UART_UART_RX_WAKE_PIN)
    #include "XBEE_UART_rx_wake.h"
#endif /* (XBEE_UART_UART_RX_WAKE_PIN) */

#if (XBEE_UART_UART_RTS_PIN)
    #include "XBEE_UART_rts.h"
#endif /* (XBEE_UART_UART_RTS_PIN) */

#if (XBEE_UART_UART_CTS_PIN)
    #include "XBEE_UART_cts.h"
#endif /* (XBEE_UART_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (XBEE_UART_RX_SCL_MOSI_PIN)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_MASK      (XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_POS       (XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_SEL_GPIO  (XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_SEL_I2C   (XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_SEL_SPI   (XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define XBEE_UART_RX_SCL_MOSI_HSIOM_SEL_UART  (XBEE_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (XBEE_UART_RX_WAKE_SCL_MOSI_PIN)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_MASK      (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_POS       (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define XBEE_UART_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define XBEE_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) XBEE_UART_INTCFG_TYPE_MASK << \
                                                                           XBEE_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins XBEE_UART_RX_SCL_MOSI_PIN or XBEE_UART_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (XBEE_UART_RX_SCL_MOSI_PIN) */

#if (XBEE_UART_TX_SDA_MISO_PIN)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define XBEE_UART_TX_SDA_MISO_HSIOM_MASK      (XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_POS       (XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_SEL_GPIO  (XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_SEL_I2C   (XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_SEL_SPI   (XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define XBEE_UART_TX_SDA_MISO_HSIOM_SEL_UART  (XBEE_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (XBEE_UART_TX_SDA_MISO_PIN) */

#if (XBEE_UART_SCLK_PIN)
    #define XBEE_UART_SCLK_HSIOM_REG   (*(reg32 *) XBEE_UART_spi_sclk__0__HSIOM)
    #define XBEE_UART_SCLK_HSIOM_PTR   ( (reg32 *) XBEE_UART_spi_sclk__0__HSIOM)
    
    #define XBEE_UART_SCLK_HSIOM_MASK      (XBEE_UART_spi_sclk__0__HSIOM_MASK)
    #define XBEE_UART_SCLK_HSIOM_POS       (XBEE_UART_spi_sclk__0__HSIOM_SHIFT)
    #define XBEE_UART_SCLK_HSIOM_SEL_GPIO  (XBEE_UART_spi_sclk__0__HSIOM_GPIO)
    #define XBEE_UART_SCLK_HSIOM_SEL_I2C   (XBEE_UART_spi_sclk__0__HSIOM_I2C)
    #define XBEE_UART_SCLK_HSIOM_SEL_SPI   (XBEE_UART_spi_sclk__0__HSIOM_SPI)
    #define XBEE_UART_SCLK_HSIOM_SEL_UART  (XBEE_UART_spi_sclk__0__HSIOM_UART)
#endif /* (XBEE_UART_SCLK_PIN) */

#if (XBEE_UART_SS0_PIN)
    #define XBEE_UART_SS0_HSIOM_REG   (*(reg32 *) XBEE_UART_spi_ss0__0__HSIOM)
    #define XBEE_UART_SS0_HSIOM_PTR   ( (reg32 *) XBEE_UART_spi_ss0__0__HSIOM)
    
    #define XBEE_UART_SS0_HSIOM_MASK      (XBEE_UART_spi_ss0__0__HSIOM_MASK)
    #define XBEE_UART_SS0_HSIOM_POS       (XBEE_UART_spi_ss0__0__HSIOM_SHIFT)
    #define XBEE_UART_SS0_HSIOM_SEL_GPIO  (XBEE_UART_spi_ss0__0__HSIOM_GPIO)
    #define XBEE_UART_SS0_HSIOM_SEL_I2C   (XBEE_UART_spi_ss0__0__HSIOM_I2C)
    #define XBEE_UART_SS0_HSIOM_SEL_SPI   (XBEE_UART_spi_ss0__0__HSIOM_SPI)
#if !(XBEE_UART_CY_SCBIP_V0 || XBEE_UART_CY_SCBIP_V1)
    #define XBEE_UART_SS0_HSIOM_SEL_UART  (XBEE_UART_spi_ss0__0__HSIOM_UART)
#endif /* !(XBEE_UART_CY_SCBIP_V0 || XBEE_UART_CY_SCBIP_V1) */
#endif /* (XBEE_UART_SS0_PIN) */

#if (XBEE_UART_SS1_PIN)
    #define XBEE_UART_SS1_HSIOM_REG  (*(reg32 *) XBEE_UART_spi_ss1__0__HSIOM)
    #define XBEE_UART_SS1_HSIOM_PTR  ( (reg32 *) XBEE_UART_spi_ss1__0__HSIOM)
    
    #define XBEE_UART_SS1_HSIOM_MASK     (XBEE_UART_spi_ss1__0__HSIOM_MASK)
    #define XBEE_UART_SS1_HSIOM_POS      (XBEE_UART_spi_ss1__0__HSIOM_SHIFT)
    #define XBEE_UART_SS1_HSIOM_SEL_GPIO (XBEE_UART_spi_ss1__0__HSIOM_GPIO)
    #define XBEE_UART_SS1_HSIOM_SEL_I2C  (XBEE_UART_spi_ss1__0__HSIOM_I2C)
    #define XBEE_UART_SS1_HSIOM_SEL_SPI  (XBEE_UART_spi_ss1__0__HSIOM_SPI)
#endif /* (XBEE_UART_SS1_PIN) */

#if (XBEE_UART_SS2_PIN)
    #define XBEE_UART_SS2_HSIOM_REG     (*(reg32 *) XBEE_UART_spi_ss2__0__HSIOM)
    #define XBEE_UART_SS2_HSIOM_PTR     ( (reg32 *) XBEE_UART_spi_ss2__0__HSIOM)
    
    #define XBEE_UART_SS2_HSIOM_MASK     (XBEE_UART_spi_ss2__0__HSIOM_MASK)
    #define XBEE_UART_SS2_HSIOM_POS      (XBEE_UART_spi_ss2__0__HSIOM_SHIFT)
    #define XBEE_UART_SS2_HSIOM_SEL_GPIO (XBEE_UART_spi_ss2__0__HSIOM_GPIO)
    #define XBEE_UART_SS2_HSIOM_SEL_I2C  (XBEE_UART_spi_ss2__0__HSIOM_I2C)
    #define XBEE_UART_SS2_HSIOM_SEL_SPI  (XBEE_UART_spi_ss2__0__HSIOM_SPI)
#endif /* (XBEE_UART_SS2_PIN) */

#if (XBEE_UART_SS3_PIN)
    #define XBEE_UART_SS3_HSIOM_REG     (*(reg32 *) XBEE_UART_spi_ss3__0__HSIOM)
    #define XBEE_UART_SS3_HSIOM_PTR     ( (reg32 *) XBEE_UART_spi_ss3__0__HSIOM)
    
    #define XBEE_UART_SS3_HSIOM_MASK     (XBEE_UART_spi_ss3__0__HSIOM_MASK)
    #define XBEE_UART_SS3_HSIOM_POS      (XBEE_UART_spi_ss3__0__HSIOM_SHIFT)
    #define XBEE_UART_SS3_HSIOM_SEL_GPIO (XBEE_UART_spi_ss3__0__HSIOM_GPIO)
    #define XBEE_UART_SS3_HSIOM_SEL_I2C  (XBEE_UART_spi_ss3__0__HSIOM_I2C)
    #define XBEE_UART_SS3_HSIOM_SEL_SPI  (XBEE_UART_spi_ss3__0__HSIOM_SPI)
#endif /* (XBEE_UART_SS3_PIN) */

#if (XBEE_UART_I2C_PINS)
    #define XBEE_UART_SCL_HSIOM_REG  (*(reg32 *) XBEE_UART_scl__0__HSIOM)
    #define XBEE_UART_SCL_HSIOM_PTR  ( (reg32 *) XBEE_UART_scl__0__HSIOM)
    
    #define XBEE_UART_SCL_HSIOM_MASK     (XBEE_UART_scl__0__HSIOM_MASK)
    #define XBEE_UART_SCL_HSIOM_POS      (XBEE_UART_scl__0__HSIOM_SHIFT)
    #define XBEE_UART_SCL_HSIOM_SEL_GPIO (XBEE_UART_sda__0__HSIOM_GPIO)
    #define XBEE_UART_SCL_HSIOM_SEL_I2C  (XBEE_UART_sda__0__HSIOM_I2C)
    
    #define XBEE_UART_SDA_HSIOM_REG  (*(reg32 *) XBEE_UART_sda__0__HSIOM)
    #define XBEE_UART_SDA_HSIOM_PTR  ( (reg32 *) XBEE_UART_sda__0__HSIOM)
    
    #define XBEE_UART_SDA_HSIOM_MASK     (XBEE_UART_sda__0__HSIOM_MASK)
    #define XBEE_UART_SDA_HSIOM_POS      (XBEE_UART_sda__0__HSIOM_SHIFT)
    #define XBEE_UART_SDA_HSIOM_SEL_GPIO (XBEE_UART_sda__0__HSIOM_GPIO)
    #define XBEE_UART_SDA_HSIOM_SEL_I2C  (XBEE_UART_sda__0__HSIOM_I2C)
#endif /* (XBEE_UART_I2C_PINS) */

#if (XBEE_UART_SPI_SLAVE_PINS)
    #define XBEE_UART_SCLK_S_HSIOM_REG   (*(reg32 *) XBEE_UART_sclk_s__0__HSIOM)
    #define XBEE_UART_SCLK_S_HSIOM_PTR   ( (reg32 *) XBEE_UART_sclk_s__0__HSIOM)
    
    #define XBEE_UART_SCLK_S_HSIOM_MASK      (XBEE_UART_sclk_s__0__HSIOM_MASK)
    #define XBEE_UART_SCLK_S_HSIOM_POS       (XBEE_UART_sclk_s__0__HSIOM_SHIFT)
    #define XBEE_UART_SCLK_S_HSIOM_SEL_GPIO  (XBEE_UART_sclk_s__0__HSIOM_GPIO)
    #define XBEE_UART_SCLK_S_HSIOM_SEL_SPI   (XBEE_UART_sclk_s__0__HSIOM_SPI)
    
    #define XBEE_UART_SS0_S_HSIOM_REG    (*(reg32 *) XBEE_UART_ss0_s__0__HSIOM)
    #define XBEE_UART_SS0_S_HSIOM_PTR    ( (reg32 *) XBEE_UART_ss0_s__0__HSIOM)
    
    #define XBEE_UART_SS0_S_HSIOM_MASK       (XBEE_UART_ss0_s__0__HSIOM_MASK)
    #define XBEE_UART_SS0_S_HSIOM_POS        (XBEE_UART_ss0_s__0__HSIOM_SHIFT)
    #define XBEE_UART_SS0_S_HSIOM_SEL_GPIO   (XBEE_UART_ss0_s__0__HSIOM_GPIO)  
    #define XBEE_UART_SS0_S_HSIOM_SEL_SPI    (XBEE_UART_ss0_s__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_SLAVE_PINS) */

#if (XBEE_UART_SPI_SLAVE_MOSI_PIN)
    #define XBEE_UART_MOSI_S_HSIOM_REG   (*(reg32 *) XBEE_UART_mosi_s__0__HSIOM)
    #define XBEE_UART_MOSI_S_HSIOM_PTR   ( (reg32 *) XBEE_UART_mosi_s__0__HSIOM)
    
    #define XBEE_UART_MOSI_S_HSIOM_MASK      (XBEE_UART_mosi_s__0__HSIOM_MASK)
    #define XBEE_UART_MOSI_S_HSIOM_POS       (XBEE_UART_mosi_s__0__HSIOM_SHIFT)
    #define XBEE_UART_MOSI_S_HSIOM_SEL_GPIO  (XBEE_UART_mosi_s__0__HSIOM_GPIO)
    #define XBEE_UART_MOSI_S_HSIOM_SEL_SPI   (XBEE_UART_mosi_s__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_SLAVE_MOSI_PIN) */

#if (XBEE_UART_SPI_SLAVE_MISO_PIN)
    #define XBEE_UART_MISO_S_HSIOM_REG   (*(reg32 *) XBEE_UART_miso_s__0__HSIOM)
    #define XBEE_UART_MISO_S_HSIOM_PTR   ( (reg32 *) XBEE_UART_miso_s__0__HSIOM)
    
    #define XBEE_UART_MISO_S_HSIOM_MASK      (XBEE_UART_miso_s__0__HSIOM_MASK)
    #define XBEE_UART_MISO_S_HSIOM_POS       (XBEE_UART_miso_s__0__HSIOM_SHIFT)
    #define XBEE_UART_MISO_S_HSIOM_SEL_GPIO  (XBEE_UART_miso_s__0__HSIOM_GPIO)
    #define XBEE_UART_MISO_S_HSIOM_SEL_SPI   (XBEE_UART_miso_s__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_SLAVE_MISO_PIN) */

#if (XBEE_UART_SPI_MASTER_MISO_PIN)
    #define XBEE_UART_MISO_M_HSIOM_REG   (*(reg32 *) XBEE_UART_miso_m__0__HSIOM)
    #define XBEE_UART_MISO_M_HSIOM_PTR   ( (reg32 *) XBEE_UART_miso_m__0__HSIOM)
    
    #define XBEE_UART_MISO_M_HSIOM_MASK      (XBEE_UART_miso_m__0__HSIOM_MASK)
    #define XBEE_UART_MISO_M_HSIOM_POS       (XBEE_UART_miso_m__0__HSIOM_SHIFT)
    #define XBEE_UART_MISO_M_HSIOM_SEL_GPIO  (XBEE_UART_miso_m__0__HSIOM_GPIO)
    #define XBEE_UART_MISO_M_HSIOM_SEL_SPI   (XBEE_UART_miso_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_MISO_PIN) */

#if (XBEE_UART_SPI_MASTER_MOSI_PIN)
    #define XBEE_UART_MOSI_M_HSIOM_REG   (*(reg32 *) XBEE_UART_mosi_m__0__HSIOM)
    #define XBEE_UART_MOSI_M_HSIOM_PTR   ( (reg32 *) XBEE_UART_mosi_m__0__HSIOM)
    
    #define XBEE_UART_MOSI_M_HSIOM_MASK      (XBEE_UART_mosi_m__0__HSIOM_MASK)
    #define XBEE_UART_MOSI_M_HSIOM_POS       (XBEE_UART_mosi_m__0__HSIOM_SHIFT)
    #define XBEE_UART_MOSI_M_HSIOM_SEL_GPIO  (XBEE_UART_mosi_m__0__HSIOM_GPIO)
    #define XBEE_UART_MOSI_M_HSIOM_SEL_SPI   (XBEE_UART_mosi_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_MOSI_PIN) */

#if (XBEE_UART_SPI_MASTER_SCLK_PIN)
    #define XBEE_UART_SCLK_M_HSIOM_REG   (*(reg32 *) XBEE_UART_sclk_m__0__HSIOM)
    #define XBEE_UART_SCLK_M_HSIOM_PTR   ( (reg32 *) XBEE_UART_sclk_m__0__HSIOM)
    
    #define XBEE_UART_SCLK_M_HSIOM_MASK      (XBEE_UART_sclk_m__0__HSIOM_MASK)
    #define XBEE_UART_SCLK_M_HSIOM_POS       (XBEE_UART_sclk_m__0__HSIOM_SHIFT)
    #define XBEE_UART_SCLK_M_HSIOM_SEL_GPIO  (XBEE_UART_sclk_m__0__HSIOM_GPIO)
    #define XBEE_UART_SCLK_M_HSIOM_SEL_SPI   (XBEE_UART_sclk_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_SCLK_PIN) */

#if (XBEE_UART_SPI_MASTER_SS0_PIN)
    #define XBEE_UART_SS0_M_HSIOM_REG    (*(reg32 *) XBEE_UART_ss0_m__0__HSIOM)
    #define XBEE_UART_SS0_M_HSIOM_PTR    ( (reg32 *) XBEE_UART_ss0_m__0__HSIOM)
    
    #define XBEE_UART_SS0_M_HSIOM_MASK       (XBEE_UART_ss0_m__0__HSIOM_MASK)
    #define XBEE_UART_SS0_M_HSIOM_POS        (XBEE_UART_ss0_m__0__HSIOM_SHIFT)
    #define XBEE_UART_SS0_M_HSIOM_SEL_GPIO   (XBEE_UART_ss0_m__0__HSIOM_GPIO)
    #define XBEE_UART_SS0_M_HSIOM_SEL_SPI    (XBEE_UART_ss0_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_SS0_PIN) */

#if (XBEE_UART_SPI_MASTER_SS1_PIN)
    #define XBEE_UART_SS1_M_HSIOM_REG    (*(reg32 *) XBEE_UART_ss1_m__0__HSIOM)
    #define XBEE_UART_SS1_M_HSIOM_PTR    ( (reg32 *) XBEE_UART_ss1_m__0__HSIOM)
    
    #define XBEE_UART_SS1_M_HSIOM_MASK       (XBEE_UART_ss1_m__0__HSIOM_MASK)
    #define XBEE_UART_SS1_M_HSIOM_POS        (XBEE_UART_ss1_m__0__HSIOM_SHIFT)
    #define XBEE_UART_SS1_M_HSIOM_SEL_GPIO   (XBEE_UART_ss1_m__0__HSIOM_GPIO)
    #define XBEE_UART_SS1_M_HSIOM_SEL_SPI    (XBEE_UART_ss1_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_SS1_PIN) */

#if (XBEE_UART_SPI_MASTER_SS2_PIN)
    #define XBEE_UART_SS2_M_HSIOM_REG    (*(reg32 *) XBEE_UART_ss2_m__0__HSIOM)
    #define XBEE_UART_SS2_M_HSIOM_PTR    ( (reg32 *) XBEE_UART_ss2_m__0__HSIOM)
    
    #define XBEE_UART_SS2_M_HSIOM_MASK       (XBEE_UART_ss2_m__0__HSIOM_MASK)
    #define XBEE_UART_SS2_M_HSIOM_POS        (XBEE_UART_ss2_m__0__HSIOM_SHIFT)
    #define XBEE_UART_SS2_M_HSIOM_SEL_GPIO   (XBEE_UART_ss2_m__0__HSIOM_GPIO)
    #define XBEE_UART_SS2_M_HSIOM_SEL_SPI    (XBEE_UART_ss2_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_SS2_PIN) */

#if (XBEE_UART_SPI_MASTER_SS3_PIN)
    #define XBEE_UART_SS3_M_HSIOM_REG    (*(reg32 *) XBEE_UART_ss3_m__0__HSIOM)
    #define XBEE_UART_SS3_M_HSIOM_PTR    ( (reg32 *) XBEE_UART_ss3_m__0__HSIOM)
    
    #define XBEE_UART_SS3_M_HSIOM_MASK      (XBEE_UART_ss3_m__0__HSIOM_MASK)
    #define XBEE_UART_SS3_M_HSIOM_POS       (XBEE_UART_ss3_m__0__HSIOM_SHIFT)
    #define XBEE_UART_SS3_M_HSIOM_SEL_GPIO  (XBEE_UART_ss3_m__0__HSIOM_GPIO)
    #define XBEE_UART_SS3_M_HSIOM_SEL_SPI   (XBEE_UART_ss3_m__0__HSIOM_SPI)
#endif /* (XBEE_UART_SPI_MASTER_SS3_PIN) */

#if (XBEE_UART_UART_RX_PIN)
    #define XBEE_UART_RX_HSIOM_REG   (*(reg32 *) XBEE_UART_rx__0__HSIOM)
    #define XBEE_UART_RX_HSIOM_PTR   ( (reg32 *) XBEE_UART_rx__0__HSIOM)
    
    #define XBEE_UART_RX_HSIOM_MASK      (XBEE_UART_rx__0__HSIOM_MASK)
    #define XBEE_UART_RX_HSIOM_POS       (XBEE_UART_rx__0__HSIOM_SHIFT)
    #define XBEE_UART_RX_HSIOM_SEL_GPIO  (XBEE_UART_rx__0__HSIOM_GPIO)
    #define XBEE_UART_RX_HSIOM_SEL_UART  (XBEE_UART_rx__0__HSIOM_UART)
#endif /* (XBEE_UART_UART_RX_PIN) */

#if (XBEE_UART_UART_RX_WAKE_PIN)
    #define XBEE_UART_RX_WAKE_HSIOM_REG   (*(reg32 *) XBEE_UART_rx_wake__0__HSIOM)
    #define XBEE_UART_RX_WAKE_HSIOM_PTR   ( (reg32 *) XBEE_UART_rx_wake__0__HSIOM)
    
    #define XBEE_UART_RX_WAKE_HSIOM_MASK      (XBEE_UART_rx_wake__0__HSIOM_MASK)
    #define XBEE_UART_RX_WAKE_HSIOM_POS       (XBEE_UART_rx_wake__0__HSIOM_SHIFT)
    #define XBEE_UART_RX_WAKE_HSIOM_SEL_GPIO  (XBEE_UART_rx_wake__0__HSIOM_GPIO)
    #define XBEE_UART_RX_WAKE_HSIOM_SEL_UART  (XBEE_UART_rx_wake__0__HSIOM_UART)
#endif /* (XBEE_UART_UART_WAKE_RX_PIN) */

#if (XBEE_UART_UART_CTS_PIN)
    #define XBEE_UART_CTS_HSIOM_REG   (*(reg32 *) XBEE_UART_cts__0__HSIOM)
    #define XBEE_UART_CTS_HSIOM_PTR   ( (reg32 *) XBEE_UART_cts__0__HSIOM)
    
    #define XBEE_UART_CTS_HSIOM_MASK      (XBEE_UART_cts__0__HSIOM_MASK)
    #define XBEE_UART_CTS_HSIOM_POS       (XBEE_UART_cts__0__HSIOM_SHIFT)
    #define XBEE_UART_CTS_HSIOM_SEL_GPIO  (XBEE_UART_cts__0__HSIOM_GPIO)
    #define XBEE_UART_CTS_HSIOM_SEL_UART  (XBEE_UART_cts__0__HSIOM_UART)
#endif /* (XBEE_UART_UART_CTS_PIN) */

#if (XBEE_UART_UART_TX_PIN)
    #define XBEE_UART_TX_HSIOM_REG   (*(reg32 *) XBEE_UART_tx__0__HSIOM)
    #define XBEE_UART_TX_HSIOM_PTR   ( (reg32 *) XBEE_UART_tx__0__HSIOM)
    
    #define XBEE_UART_TX_HSIOM_MASK      (XBEE_UART_tx__0__HSIOM_MASK)
    #define XBEE_UART_TX_HSIOM_POS       (XBEE_UART_tx__0__HSIOM_SHIFT)
    #define XBEE_UART_TX_HSIOM_SEL_GPIO  (XBEE_UART_tx__0__HSIOM_GPIO)
    #define XBEE_UART_TX_HSIOM_SEL_UART  (XBEE_UART_tx__0__HSIOM_UART)
#endif /* (XBEE_UART_UART_TX_PIN) */

#if (XBEE_UART_UART_RX_TX_PIN)
    #define XBEE_UART_RX_TX_HSIOM_REG   (*(reg32 *) XBEE_UART_rx_tx__0__HSIOM)
    #define XBEE_UART_RX_TX_HSIOM_PTR   ( (reg32 *) XBEE_UART_rx_tx__0__HSIOM)
    
    #define XBEE_UART_RX_TX_HSIOM_MASK      (XBEE_UART_rx_tx__0__HSIOM_MASK)
    #define XBEE_UART_RX_TX_HSIOM_POS       (XBEE_UART_rx_tx__0__HSIOM_SHIFT)
    #define XBEE_UART_RX_TX_HSIOM_SEL_GPIO  (XBEE_UART_rx_tx__0__HSIOM_GPIO)
    #define XBEE_UART_RX_TX_HSIOM_SEL_UART  (XBEE_UART_rx_tx__0__HSIOM_UART)
#endif /* (XBEE_UART_UART_RX_TX_PIN) */

#if (XBEE_UART_UART_RTS_PIN)
    #define XBEE_UART_RTS_HSIOM_REG      (*(reg32 *) XBEE_UART_rts__0__HSIOM)
    #define XBEE_UART_RTS_HSIOM_PTR      ( (reg32 *) XBEE_UART_rts__0__HSIOM)
    
    #define XBEE_UART_RTS_HSIOM_MASK     (XBEE_UART_rts__0__HSIOM_MASK)
    #define XBEE_UART_RTS_HSIOM_POS      (XBEE_UART_rts__0__HSIOM_SHIFT)    
    #define XBEE_UART_RTS_HSIOM_SEL_GPIO (XBEE_UART_rts__0__HSIOM_GPIO)
    #define XBEE_UART_RTS_HSIOM_SEL_UART (XBEE_UART_rts__0__HSIOM_UART)    
#endif /* (XBEE_UART_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define XBEE_UART_HSIOM_DEF_SEL      (0x00u)
#define XBEE_UART_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for XBEE_UART_CY_SCBIP_V0 
* and XBEE_UART_CY_SCBIP_V1. It is not recommended to use them for 
* XBEE_UART_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define XBEE_UART_HSIOM_UART_SEL     (0x09u)
#define XBEE_UART_HSIOM_I2C_SEL      (0x0Eu)
#define XBEE_UART_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define XBEE_UART_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define XBEE_UART_RX_SCL_MOSI_PIN_INDEX       (0u)
#define XBEE_UART_TX_SDA_MISO_PIN_INDEX       (1u)
#define XBEE_UART_SCLK_PIN_INDEX       (2u)
#define XBEE_UART_SS0_PIN_INDEX       (3u)
#define XBEE_UART_SS1_PIN_INDEX                  (4u)
#define XBEE_UART_SS2_PIN_INDEX                  (5u)
#define XBEE_UART_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define XBEE_UART_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << XBEE_UART_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define XBEE_UART_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << XBEE_UART_RX_SCL_MOSI_PIN_INDEX)
#define XBEE_UART_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << XBEE_UART_TX_SDA_MISO_PIN_INDEX)
#define XBEE_UART_SCLK_PIN_MASK     ((uint32) 0x01u << XBEE_UART_SCLK_PIN_INDEX)
#define XBEE_UART_SS0_PIN_MASK     ((uint32) 0x01u << XBEE_UART_SS0_PIN_INDEX)
#define XBEE_UART_SS1_PIN_MASK                ((uint32) 0x01u << XBEE_UART_SS1_PIN_INDEX)
#define XBEE_UART_SS2_PIN_MASK                ((uint32) 0x01u << XBEE_UART_SS2_PIN_INDEX)
#define XBEE_UART_SS3_PIN_MASK                ((uint32) 0x01u << XBEE_UART_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define XBEE_UART_INTCFG_TYPE_MASK           (0x03u)
#define XBEE_UART_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define XBEE_UART_PIN_DM_ALG_HIZ  (0u)
#define XBEE_UART_PIN_DM_DIG_HIZ  (1u)
#define XBEE_UART_PIN_DM_OD_LO    (4u)
#define XBEE_UART_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define XBEE_UART_DM_MASK    (0x7u)
#define XBEE_UART_DM_SIZE    (3u)
#define XBEE_UART_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) XBEE_UART_DM_MASK << (XBEE_UART_DM_SIZE * (pos)))) >> \
                                                              (XBEE_UART_DM_SIZE * (pos)) )

#if (XBEE_UART_TX_SDA_MISO_PIN)
    #define XBEE_UART_CHECK_TX_SDA_MISO_PIN_USED \
                (XBEE_UART_PIN_DM_ALG_HIZ != \
                    XBEE_UART_GET_P4_PIN_DM(XBEE_UART_uart_tx_i2c_sda_spi_miso_PC, \
                                                   XBEE_UART_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (XBEE_UART_TX_SDA_MISO_PIN) */

#if (XBEE_UART_SS0_PIN)
    #define XBEE_UART_CHECK_SS0_PIN_USED \
                (XBEE_UART_PIN_DM_ALG_HIZ != \
                    XBEE_UART_GET_P4_PIN_DM(XBEE_UART_spi_ss0_PC, \
                                                   XBEE_UART_spi_ss0_SHIFT))
#endif /* (XBEE_UART_SS0_PIN) */

/* Set bits-mask in register */
#define XBEE_UART_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define XBEE_UART_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define XBEE_UART_SET_HSIOM_SEL(reg, mask, pos, sel) XBEE_UART_SET_REGISTER_BITS(reg, mask, pos, sel)
#define XBEE_UART_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        XBEE_UART_SET_REGISTER_BITS(reg, mask, pos, intType)
#define XBEE_UART_SET_INP_DIS(reg, mask, val) XBEE_UART_SET_REGISTER_BIT(reg, mask, val)

/* XBEE_UART_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  XBEE_UART_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (XBEE_UART_CY_SCBIP_V0)
#if (XBEE_UART_I2C_PINS)
    #define XBEE_UART_SET_I2C_SCL_DR(val) XBEE_UART_scl_Write(val)

    #define XBEE_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                          XBEE_UART_SET_HSIOM_SEL(XBEE_UART_SCL_HSIOM_REG,  \
                                                         XBEE_UART_SCL_HSIOM_MASK, \
                                                         XBEE_UART_SCL_HSIOM_POS,  \
                                                         (sel))
    #define XBEE_UART_WAIT_SCL_SET_HIGH  (0u == XBEE_UART_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (XBEE_UART_RX_WAKE_SCL_MOSI_PIN)
    #define XBEE_UART_SET_I2C_SCL_DR(val) \
                            XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define XBEE_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                    XBEE_UART_SET_HSIOM_SEL(XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define XBEE_UART_WAIT_SCL_SET_HIGH  (0u == XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (XBEE_UART_RX_SCL_MOSI_PIN)
    #define XBEE_UART_SET_I2C_SCL_DR(val) \
                            XBEE_UART_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define XBEE_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                            XBEE_UART_SET_HSIOM_SEL(XBEE_UART_RX_SCL_MOSI_HSIOM_REG,  \
                                                           XBEE_UART_RX_SCL_MOSI_HSIOM_MASK, \
                                                           XBEE_UART_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define XBEE_UART_WAIT_SCL_SET_HIGH  (0u == XBEE_UART_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define XBEE_UART_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define XBEE_UART_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define XBEE_UART_WAIT_SCL_SET_HIGH  (0u)
#endif /* (XBEE_UART_I2C_PINS) */

/* SCB I2C: sda signal */
#if (XBEE_UART_I2C_PINS)
    #define XBEE_UART_WAIT_SDA_SET_HIGH  (0u == XBEE_UART_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (XBEE_UART_TX_SDA_MISO_PIN)
    #define XBEE_UART_WAIT_SDA_SET_HIGH  (0u == XBEE_UART_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define XBEE_UART_WAIT_SDA_SET_HIGH  (0u)
#endif /* (XBEE_UART_MOSI_SCL_RX_PIN) */
#endif /* (XBEE_UART_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (XBEE_UART_RX_SCL_MOSI_PIN)
    #define XBEE_UART_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (XBEE_UART_RX_WAKE_SCL_MOSI_PIN)
    #define XBEE_UART_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) XBEE_UART_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(XBEE_UART_UART_RX_WAKE_PIN)
    #define XBEE_UART_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) XBEE_UART_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (XBEE_UART_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define XBEE_UART_REMOVE_MOSI_SCL_RX_WAKE_PIN    XBEE_UART_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define XBEE_UART_REMOVE_MOSI_SCL_RX_PIN         XBEE_UART_REMOVE_RX_SCL_MOSI_PIN
#define XBEE_UART_REMOVE_MISO_SDA_TX_PIN         XBEE_UART_REMOVE_TX_SDA_MISO_PIN
#ifndef XBEE_UART_REMOVE_SCLK_PIN
#define XBEE_UART_REMOVE_SCLK_PIN                XBEE_UART_REMOVE_SCLK_PIN
#endif /* XBEE_UART_REMOVE_SCLK_PIN */
#ifndef XBEE_UART_REMOVE_SS0_PIN
#define XBEE_UART_REMOVE_SS0_PIN                 XBEE_UART_REMOVE_SS0_PIN
#endif /* XBEE_UART_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define XBEE_UART_MOSI_SCL_RX_WAKE_PIN   XBEE_UART_RX_WAKE_SCL_MOSI_PIN
#define XBEE_UART_MOSI_SCL_RX_PIN        XBEE_UART_RX_SCL_MOSI_PIN
#define XBEE_UART_MISO_SDA_TX_PIN        XBEE_UART_TX_SDA_MISO_PIN
#ifndef XBEE_UART_SCLK_PIN
#define XBEE_UART_SCLK_PIN               XBEE_UART_SCLK_PIN
#endif /* XBEE_UART_SCLK_PIN */
#ifndef XBEE_UART_SS0_PIN
#define XBEE_UART_SS0_PIN                XBEE_UART_SS0_PIN
#endif /* XBEE_UART_SS0_PIN */

#if (XBEE_UART_MOSI_SCL_RX_WAKE_PIN)
    #define XBEE_UART_MOSI_SCL_RX_WAKE_HSIOM_REG     XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define XBEE_UART_MOSI_SCL_RX_WAKE_HSIOM_PTR     XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define XBEE_UART_MOSI_SCL_RX_WAKE_HSIOM_MASK    XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define XBEE_UART_MOSI_SCL_RX_WAKE_HSIOM_POS     XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define XBEE_UART_MOSI_SCL_RX_WAKE_INTCFG_REG    XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define XBEE_UART_MOSI_SCL_RX_WAKE_INTCFG_PTR    XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define XBEE_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define XBEE_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  XBEE_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (XBEE_UART_RX_WAKE_SCL_MOSI_PIN) */

#if (XBEE_UART_MOSI_SCL_RX_PIN)
    #define XBEE_UART_MOSI_SCL_RX_HSIOM_REG      XBEE_UART_RX_SCL_MOSI_HSIOM_REG
    #define XBEE_UART_MOSI_SCL_RX_HSIOM_PTR      XBEE_UART_RX_SCL_MOSI_HSIOM_PTR
    #define XBEE_UART_MOSI_SCL_RX_HSIOM_MASK     XBEE_UART_RX_SCL_MOSI_HSIOM_MASK
    #define XBEE_UART_MOSI_SCL_RX_HSIOM_POS      XBEE_UART_RX_SCL_MOSI_HSIOM_POS
#endif /* (XBEE_UART_MOSI_SCL_RX_PIN) */

#if (XBEE_UART_MISO_SDA_TX_PIN)
    #define XBEE_UART_MISO_SDA_TX_HSIOM_REG      XBEE_UART_TX_SDA_MISO_HSIOM_REG
    #define XBEE_UART_MISO_SDA_TX_HSIOM_PTR      XBEE_UART_TX_SDA_MISO_HSIOM_REG
    #define XBEE_UART_MISO_SDA_TX_HSIOM_MASK     XBEE_UART_TX_SDA_MISO_HSIOM_REG
    #define XBEE_UART_MISO_SDA_TX_HSIOM_POS      XBEE_UART_TX_SDA_MISO_HSIOM_REG
#endif /* (XBEE_UART_MISO_SDA_TX_PIN_PIN) */

#if (XBEE_UART_SCLK_PIN)
    #ifndef XBEE_UART_SCLK_HSIOM_REG
    #define XBEE_UART_SCLK_HSIOM_REG     XBEE_UART_SCLK_HSIOM_REG
    #define XBEE_UART_SCLK_HSIOM_PTR     XBEE_UART_SCLK_HSIOM_PTR
    #define XBEE_UART_SCLK_HSIOM_MASK    XBEE_UART_SCLK_HSIOM_MASK
    #define XBEE_UART_SCLK_HSIOM_POS     XBEE_UART_SCLK_HSIOM_POS
    #endif /* XBEE_UART_SCLK_HSIOM_REG */
#endif /* (XBEE_UART_SCLK_PIN) */

#if (XBEE_UART_SS0_PIN)
    #ifndef XBEE_UART_SS0_HSIOM_REG
    #define XBEE_UART_SS0_HSIOM_REG      XBEE_UART_SS0_HSIOM_REG
    #define XBEE_UART_SS0_HSIOM_PTR      XBEE_UART_SS0_HSIOM_PTR
    #define XBEE_UART_SS0_HSIOM_MASK     XBEE_UART_SS0_HSIOM_MASK
    #define XBEE_UART_SS0_HSIOM_POS      XBEE_UART_SS0_HSIOM_POS
    #endif /* XBEE_UART_SS0_HSIOM_REG */
#endif /* (XBEE_UART_SS0_PIN) */

#define XBEE_UART_MOSI_SCL_RX_WAKE_PIN_INDEX XBEE_UART_RX_WAKE_SCL_MOSI_PIN_INDEX
#define XBEE_UART_MOSI_SCL_RX_PIN_INDEX      XBEE_UART_RX_SCL_MOSI_PIN_INDEX
#define XBEE_UART_MISO_SDA_TX_PIN_INDEX      XBEE_UART_TX_SDA_MISO_PIN_INDEX
#ifndef XBEE_UART_SCLK_PIN_INDEX
#define XBEE_UART_SCLK_PIN_INDEX             XBEE_UART_SCLK_PIN_INDEX
#endif /* XBEE_UART_SCLK_PIN_INDEX */
#ifndef XBEE_UART_SS0_PIN_INDEX
#define XBEE_UART_SS0_PIN_INDEX              XBEE_UART_SS0_PIN_INDEX
#endif /* XBEE_UART_SS0_PIN_INDEX */

#define XBEE_UART_MOSI_SCL_RX_WAKE_PIN_MASK XBEE_UART_RX_WAKE_SCL_MOSI_PIN_MASK
#define XBEE_UART_MOSI_SCL_RX_PIN_MASK      XBEE_UART_RX_SCL_MOSI_PIN_MASK
#define XBEE_UART_MISO_SDA_TX_PIN_MASK      XBEE_UART_TX_SDA_MISO_PIN_MASK
#ifndef XBEE_UART_SCLK_PIN_MASK
#define XBEE_UART_SCLK_PIN_MASK             XBEE_UART_SCLK_PIN_MASK
#endif /* XBEE_UART_SCLK_PIN_MASK */
#ifndef XBEE_UART_SS0_PIN_MASK
#define XBEE_UART_SS0_PIN_MASK              XBEE_UART_SS0_PIN_MASK
#endif /* XBEE_UART_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_XBEE_UART_H) */


/* [] END OF FILE */
