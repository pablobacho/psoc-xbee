/*

The MIT License (MIT)

Copyright (c) 2014 CAIMANICS (Pablo Bacho)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef _`$INSTANCE_NAME`_h_ 
#define _`$INSTANCE_NAME`_h_ 

#include "cytypes.h"
#include "cyfitter.h"
#include "string.h"
    
#include "`$UART`.h"
#if defined(CY_SCB_`$UART`_H)
    #include "`$UART`_SPI_UART.h"
#endif
#include "`$RESET`.h"
#include "`$SLEEP_RQ`.h"
#include "`$RX_INT`.h"    
    
/*
* API Identifiers
*/
#define `$INSTANCE_NAME`_APIID_AT_COMMAND                           (0x08u)
#define `$INSTANCE_NAME`_APIID_AT_COMMAND_QUEUE                     (0x09u)
#define `$INSTANCE_NAME`_APIID_ZIGBEE_TX_RQ                         (0x10u)
#define `$INSTANCE_NAME`_APIID_EXPLICIT_ADDRESSING_ZIGBEE_COMMAND   (0x11u)
#define `$INSTANCE_NAME`_APIID_REMOTE_COMMAND                       (0x17u)
#define `$INSTANCE_NAME`_APIID_CREATE_SOURCE_ROUTE                  (0x21u)
#define `$INSTANCE_NAME`_APIID_AT_COMMAND_RESPONSE                  (0x88u)
#define `$INSTANCE_NAME`_APIID_MODEM_STATUS                         (0x8Au)
#define `$INSTANCE_NAME`_APIID_ZIGBEE_TRANSMIT_STATUS               (0x8Bu)
#define `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET                     (0x90u)
#define `$INSTANCE_NAME`_APIID_ZIGBEE_EXPLICIT_RX_INDICATOR         (0x91u)
#define `$INSTANCE_NAME`_APIID_ZIGBEE_IO_DATA_SAMPLE_RX_INDICATOR   (0x92u)
#define `$INSTANCE_NAME`_APIID_XBEE_SENSOR_READ_INDICATOR           (0x94u)
#define `$INSTANCE_NAME`_APIID_NODE_IDENTIFICATION_INDICATOR        (0x95u)
#define `$INSTANCE_NAME`_APIID_REMOTE_COMMAND_RESPONSE              (0x97u)
#define `$INSTANCE_NAME`_APIID_OTA_FIRMWARE_UPDATE_STATUS           (0xA0u)
#define `$INSTANCE_NAME`_APIID_ROUTE_RECORD_INDICATOR               (0xA1u)
#define `$INSTANCE_NAME`_APIID_MANY_TO_ONE_RQ_INDICATOR             (0xA3u)

    
/*
* `$INSTANCE_NAME`_APIID_ZIGBEE_TRANSMIT_STATUS fields
*/
/* Transmit Retry Count */
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__TRANSMIT_RETRY_COUNT_OFFSET    04u
/* Delivery Status */
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS_OFFSET         05u
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__SUCCESS               (0x00u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__MAC_ACK_FAILURE       (0x01u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__CCA_FAILURE           (0x02u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__INVALID_DESTINATION_ENDPOINT  (0x15u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__NETWORK_ACK_FAILURE   (0x21u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__NOT_JOINED_TO_NETWORK (0x22u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__SELF_ADDRESSED        (0x23u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ADDRESS_NOT_FOUND     (0x24u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ROUTE_NOT_FOUND       (0x25u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__BROADCAST_RELAY_ERROR (0x26u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__INVALID_BINDING_TABLE_INDEX   (0x2Bu)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__RESOURCE_ERROR        (0x2Cu)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ATTEMPTED_BROADCAST_WITH_APS  (0x2Du)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ATTEMPTED_APS_BUT_EE0 (0x2Eu)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__RESOURCE_ERROR_2      (0x32u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__DATA_PAYLOAD_TOO_LARGE (0x74u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__INDIRECT_MESSAGE_UNREQ (0x75u)
/* Discovery Status */    
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS_OFFSET        06u
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__NO_DISCOVERY     (0x00u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__ADDRESS          (0x01u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__ROUTE            (0x02u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__ADDRESS_ROUTE    (0x03u)
#define `$INSTANCE_NAME`_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__EXTENDED_TIMEOUT (0x04u)

    
/*
* `$INSTANCE_NAME`_APIID_AT_RESPONSE fields
*/
/* Command Status */
#define `$INSTANCE_NAME`_AT_RESPONSE__COMMAND_STATUS_OFFSET             04u
#define `$INSTANCE_NAME`_AT_RESPONSE__COMMAND_STATUS__OK                (0x00u)
#define `$INSTANCE_NAME`_AT_RESPONSE__COMMAND_STATUS__ERROR             (0x01u)
#define `$INSTANCE_NAME`_AT_RESPONSE__COMMAND_STATUS__INVALID_COMMAND   (0x02u)
#define `$INSTANCE_NAME`_AT_RESPONSE__COMMAND_STATUS__INVALID_PARAMTER  (0x03u)
#define `$INSTANCE_NAME`_AT_RESPONSE__COMMAND_STATUS__TX_FAILURE        (0x04u)
    
    
/* Params */
#define `$INSTANCE_NAME`_PACKET_START                               (0x7Eu)
#define `$INSTANCE_NAME`_PACKET_PAYLOAD_MAX                         80u
#define `$INSTANCE_NAME`_RX_BUFFER_SIZE                             100u
    
    
/* `$INSTANCE_NAME`_RX_STATUS_REG bit fields */
#define `$INSTANCE_NAME`_RX_STATUS_PACKET           (0x01u)
#define `$INSTANCE_NAME`_RX_STATUS_EMPTY            (0x02u)
#define `$INSTANCE_NAME`_RX_STATUS_OVERFLOW         (0x04u)
#define `$INSTANCE_NAME`_RX_STATUS_UNDERRUN         (0x08u)
#define `$INSTANCE_NAME`_RX_STATUS_START_ERROR      (0x10u)
#define `$INSTANCE_NAME`_RX_STATUS_LENGTH_ERROR     (0x20u)
#define `$INSTANCE_NAME`_RX_STATUS_CHECKSUM_ERROR   (0x40u)
#define `$INSTANCE_NAME`_RX_STATUS_UART_ERROR       (0x80u)

    
/* `$INSTANCE_NAME`_PACKET_REG bit fields */
#define `$INSTANCE_NAME`_PACKET_STATUS_APIID_NOT_SUPPORTED  (0x01u)
#define `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD          (0x02u)
#define `$INSTANCE_NAME`_PACKET_STATUS_VALUE_ERROR          (0x04u)

    
/* `$INSTANCE_NAME`_ReadPacket() return values */    
#define `$INSTANCE_NAME`_READPACKET_OK              (0x00u)
#define `$INSTANCE_NAME`_READPACKET_EMPTY           (0x01u)
#define `$INSTANCE_NAME`_READPACKET_ERROR           (0x02u)

    
/* `$INSTANCE_NAME`_RxBufferRecycle() return values */
#define `$INSTANCE_NAME`_RECYCLE_OK         (0x00u)
#define `$INSTANCE_NAME`_RECYCLE_BUSY       (0x01u)
#define `$INSTANCE_NAME`_RECYCLE_NOROOM     (0x02u)


typedef enum {IDLE, LENH, LENL, PAYLOAD, CHECKSUM} `$INSTANCE_NAME`_rxState_t;

typedef struct `$INSTANCE_NAME`_packet_t {
    uint16_t length;
    uint8_t payload[`$INSTANCE_NAME`_PACKET_PAYLOAD_MAX];
    uint8_t checksum;
} `$INSTANCE_NAME`_packet_t;


/***************************************
* Forward declaration of variables
***************************************/

extern volatile uint8_t `$INSTANCE_NAME`_RX_STATUS_REG;
extern volatile uint8_t `$INSTANCE_NAME`_PACKET_STATUS_REG;

extern volatile `$INSTANCE_NAME`_rxState_t `$INSTANCE_NAME`_rxState;
extern volatile uint8_t `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_RX_BUFFER_SIZE];
extern volatile uint16_t `$INSTANCE_NAME`_rxBufferWrite;
extern volatile uint16_t `$INSTANCE_NAME`_rxBufferRead;
extern volatile uint16_t `$INSTANCE_NAME`_rxBufferTail;
extern volatile uint16_t `$INSTANCE_NAME`_rxBufferHead;
extern volatile uint16_t `$INSTANCE_NAME`_rxLength;
extern volatile uint8_t `$INSTANCE_NAME`_rxChecksum;
extern volatile uint8_t `$INSTANCE_NAME`_rxPacketOK;

extern uint8_t `$INSTANCE_NAME`_BROADCAST_HW_ADDRESS[];
extern uint8_t `$INSTANCE_NAME`_BROADCAST_NWK_ADDRESS[];


/***************************************
* Standard component functions
***************************************/
    
void `$INSTANCE_NAME`_Start(void);
void `$INSTANCE_NAME`_Stop(void);
void `$INSTANCE_NAME`_Init(void) ;
void `$INSTANCE_NAME`_Enable(void) ;
void `$INSTANCE_NAME`_SaveConfig(void) ;
void `$INSTANCE_NAME`_RestoreConfig(void) ;
void `$INSTANCE_NAME`_Sleep(void) ;
void `$INSTANCE_NAME`_Wakeup(void) ;


/***************************************
* TX functions
***************************************/

uint8_t `$INSTANCE_NAME`_ZigBeeTransmitRequest(`$INSTANCE_NAME`_packet_t * packet, uint8_t frameId, uint8_t * hwAddress, uint8_t * nwkAddress, uint8_t broadcastRadius, uint8_t options, uint8_t * RFData, uint8_t RFDataLen);


/***************************************
* AT functions
***************************************/

uint8_t `$INSTANCE_NAME`_ATCommand(`$INSTANCE_NAME`_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen);
uint8_t `$INSTANCE_NAME`_ATCommandQueue(`$INSTANCE_NAME`_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen);


/***************************************
* Packet functions
***************************************/

uint8_t `$INSTANCE_NAME`_Issue(`$INSTANCE_NAME`_packet_t * packet);
uint8_t `$INSTANCE_NAME`_ReadPacket(`$INSTANCE_NAME`_packet_t * packet);
uint8_t `$INSTANCE_NAME`_Checksum(`$INSTANCE_NAME`_packet_t * packet);
uint8_t `$INSTANCE_NAME`_ReadApiId(`$INSTANCE_NAME`_packet_t * packet);
uint8_t `$INSTANCE_NAME`_ReadFrameId(`$INSTANCE_NAME`_packet_t * packet);
uint8_t * `$INSTANCE_NAME`_ReadNwkSourceAddress(`$INSTANCE_NAME`_packet_t * packet);
uint8_t * `$INSTANCE_NAME`_ReadHwSourceAddress(`$INSTANCE_NAME`_packet_t * packet);
uint8_t * `$INSTANCE_NAME`_ReadRFData(`$INSTANCE_NAME`_packet_t * packet);
uint8_t `$INSTANCE_NAME`_ReadRFDataLen(`$INSTANCE_NAME`_packet_t * packet);
uint8_t `$INSTANCE_NAME`_ReadDeliveryStatus(`$INSTANCE_NAME`_packet_t * packet);


/***************************************
* RX functions
***************************************/

uint8_t `$INSTANCE_NAME`_ReadRxStatus();
uint8_t `$INSTANCE_NAME`_RxBufferRead();
uint8_t `$INSTANCE_NAME`_RxBufferPeek(uint8_t shift);
uint16_t `$INSTANCE_NAME`_RxBufferSize();
uint8_t `$INSTANCE_NAME`_RxIsIdle();
void `$INSTANCE_NAME`_RxBufferFlush();
uint8_t `$INSTANCE_NAME`_RxBufferRecycle(`$INSTANCE_NAME`_packet_t * packet);


/***************************************
* Common functions
***************************************/


CY_ISR_PROTO(`$INSTANCE_NAME`_RX_ISR);

#endif

/* [] END OF FILE */
