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

#ifndef _XBEE_h_ 
#define _XBEE_h_ 

#include "cytypes.h"
#include "cyfitter.h"
#include "string.h"
    
#include "XBEE_UART.h"
#if defined(CY_SCB_XBEE_UART_H)
    #include "XBEE_UART_SPI_UART.h"
#endif
#include "XBEE_RESET.h"
#include "XBEE_SLEEP_RQ.h"
#include "XBEE_RX_INT.h"    
    
/*
* API Identifiers
*/
#define XBEE_APIID_AT_COMMAND                           (0x08u)
#define XBEE_APIID_AT_COMMAND_QUEUE                     (0x09u)
#define XBEE_APIID_ZIGBEE_TX_RQ                         (0x10u)
#define XBEE_APIID_EXPLICIT_ADDRESSING_ZIGBEE_COMMAND   (0x11u)
#define XBEE_APIID_REMOTE_COMMAND                       (0x17u)
#define XBEE_APIID_CREATE_SOURCE_ROUTE                  (0x21u)
#define XBEE_APIID_AT_COMMAND_RESPONSE                  (0x88u)
#define XBEE_APIID_MODEM_STATUS                         (0x8Au)
#define XBEE_APIID_ZIGBEE_TRANSMIT_STATUS               (0x8Bu)
#define XBEE_APIID_ZIGBEE_RX_PACKET                     (0x90u)
#define XBEE_APIID_ZIGBEE_EXPLICIT_RX_INDICATOR         (0x91u)
#define XBEE_APIID_ZIGBEE_IO_DATA_SAMPLE_RX_INDICATOR   (0x92u)
#define XBEE_APIID_XBEE_SENSOR_READ_INDICATOR           (0x94u)
#define XBEE_APIID_NODE_IDENTIFICATION_INDICATOR        (0x95u)
#define XBEE_APIID_REMOTE_COMMAND_RESPONSE              (0x97u)
#define XBEE_APIID_OTA_FIRMWARE_UPDATE_STATUS           (0xA0u)
#define XBEE_APIID_ROUTE_RECORD_INDICATOR               (0xA1u)
#define XBEE_APIID_MANY_TO_ONE_RQ_INDICATOR             (0xA3u)

    
/*
* XBEE_APIID_ZIGBEE_TRANSMIT_STATUS fields
*/
/* Transmit Retry Count */
#define XBEE_ZIGBEE_TRANSMIT_STATUS__TRANSMIT_RETRY_COUNT_OFFSET    04u
/* Delivery Status */
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS_OFFSET         05u
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__SUCCESS               (0x00u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__MAC_ACK_FAILURE       (0x01u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__CCA_FAILURE           (0x02u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__INVALID_DESTINATION_ENDPOINT  (0x15u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__NETWORK_ACK_FAILURE   (0x21u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__NOT_JOINED_TO_NETWORK (0x22u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__SELF_ADDRESSED        (0x23u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ADDRESS_NOT_FOUND     (0x24u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ROUTE_NOT_FOUND       (0x25u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__BROADCAST_RELAY_ERROR (0x26u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__INVALID_BINDING_TABLE_INDEX   (0x2Bu)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__RESOURCE_ERROR        (0x2Cu)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ATTEMPTED_BROADCAST_WITH_APS  (0x2Du)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__ATTEMPTED_APS_BUT_EE0 (0x2Eu)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__RESOURCE_ERROR_2      (0x32u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__DATA_PAYLOAD_TOO_LARGE (0x74u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DELIVERY_STATUS__INDIRECT_MESSAGE_UNREQ (0x75u)
/* Discovery Status */    
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS_OFFSET        06u
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__NO_DISCOVERY     (0x00u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__ADDRESS          (0x01u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__ROUTE            (0x02u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__ADDRESS_ROUTE    (0x03u)
#define XBEE_ZIGBEE_TRANSMIT_STATUS__DISCOVERY_STATUS__EXTENDED_TIMEOUT (0x04u)

    
/*
* XBEE_APIID_AT_RESPONSE fields
*/
/* Command Status */
#define XBEE_AT_RESPONSE__COMMAND_STATUS_OFFSET             04u
#define XBEE_AT_RESPONSE__COMMAND_STATUS__OK                (0x00u)
#define XBEE_AT_RESPONSE__COMMAND_STATUS__ERROR             (0x01u)
#define XBEE_AT_RESPONSE__COMMAND_STATUS__INVALID_COMMAND   (0x02u)
#define XBEE_AT_RESPONSE__COMMAND_STATUS__INVALID_PARAMTER  (0x03u)
#define XBEE_AT_RESPONSE__COMMAND_STATUS__TX_FAILURE        (0x04u)
    
    
/* Params */
#define XBEE_PACKET_START                               (0x7Eu)
#define XBEE_PACKET_PAYLOAD_MAX                         80u
#define XBEE_RX_BUFFER_SIZE                             100u
    
    
/* XBEE_RX_STATUS_REG bit fields */
#define XBEE_RX_STATUS_PACKET           (0x01u)
#define XBEE_RX_STATUS_EMPTY            (0x02u)
#define XBEE_RX_STATUS_OVERFLOW         (0x04u)
#define XBEE_RX_STATUS_UNDERRUN         (0x08u)
#define XBEE_RX_STATUS_START_ERROR      (0x10u)
#define XBEE_RX_STATUS_LENGTH_ERROR     (0x20u)
#define XBEE_RX_STATUS_CHECKSUM_ERROR   (0x40u)
#define XBEE_RX_STATUS_UART_ERROR       (0x80u)

    
/* XBEE_PACKET_REG bit fields */
#define XBEE_PACKET_STATUS_APIID_NOT_SUPPORTED  (0x01u)
#define XBEE_PACKET_STATUS_NOT_A_FIELD          (0x02u)
#define XBEE_PACKET_STATUS_VALUE_ERROR          (0x04u)

    
/* XBEE_ReadPacket() return values */    
#define XBEE_READPACKET_OK              (0x00u)
#define XBEE_READPACKET_EMPTY           (0x01u)
#define XBEE_READPACKET_ERROR           (0x02u)

    
/* XBEE_RxBufferRecycle() return values */
#define XBEE_RECYCLE_OK         (0x00u)
#define XBEE_RECYCLE_BUSY       (0x01u)
#define XBEE_RECYCLE_NOROOM     (0x02u)


typedef enum {IDLE, LENH, LENL, PAYLOAD, CHECKSUM} XBEE_rxState_t;

typedef struct XBEE_packet_t {
    uint16_t length;
    uint8_t payload[XBEE_PACKET_PAYLOAD_MAX];
    uint8_t checksum;
} XBEE_packet_t;


/***************************************
* Forward declaration of variables
***************************************/

extern volatile uint8_t XBEE_RX_STATUS_REG;
extern volatile uint8_t XBEE_PACKET_STATUS_REG;

extern volatile XBEE_rxState_t XBEE_rxState;
extern volatile uint8_t XBEE_rxBuffer[XBEE_RX_BUFFER_SIZE];
extern volatile uint16_t XBEE_rxBufferWrite;
extern volatile uint16_t XBEE_rxBufferRead;
extern volatile uint16_t XBEE_rxBufferTail;
extern volatile uint16_t XBEE_rxBufferHead;
extern volatile uint16_t XBEE_rxLength;
extern volatile uint8_t XBEE_rxChecksum;
extern volatile uint8_t XBEE_rxPacketOK;

extern uint8_t XBEE_BROADCAST_HW_ADDRESS[];
extern uint8_t XBEE_BROADCAST_NWK_ADDRESS[];


/***************************************
* Standard component functions
***************************************/
    
void XBEE_Start(void);
void XBEE_Stop(void);
void XBEE_Init(void) ;
void XBEE_Enable(void) ;
void XBEE_SaveConfig(void) ;
void XBEE_RestoreConfig(void) ;
void XBEE_Sleep(void) ;
void XBEE_Wakeup(void) ;


/***************************************
* TX functions
***************************************/

uint8_t XBEE_ZigBeeTransmitRequest(XBEE_packet_t * packet, uint8_t frameId, uint8_t * hwAddress, uint8_t * nwkAddress, uint8_t broadcastRadius, uint8_t options, uint8_t * RFData, uint8_t RFDataLen);


/***************************************
* AT functions
***************************************/

uint8_t XBEE_ATCommand(XBEE_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen);
uint8_t XBEE_ATCommandQueue(XBEE_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen);


/***************************************
* Packet functions
***************************************/

uint8_t XBEE_Issue(XBEE_packet_t * packet);
uint8_t XBEE_ReadPacket(XBEE_packet_t * packet);
uint8_t XBEE_Checksum(XBEE_packet_t * packet);
uint8_t XBEE_ReadApiId(XBEE_packet_t * packet);
uint8_t XBEE_ReadFrameId(XBEE_packet_t * packet);
uint8_t * XBEE_ReadNwkSourceAddress(XBEE_packet_t * packet);
uint8_t * XBEE_ReadHwSourceAddress(XBEE_packet_t * packet);
uint8_t * XBEE_ReadRFData(XBEE_packet_t * packet);
uint8_t XBEE_ReadRFDataLen(XBEE_packet_t * packet);
uint8_t XBEE_ReadDeliveryStatus(XBEE_packet_t * packet);


/***************************************
* RX functions
***************************************/

uint8_t XBEE_ReadRxStatus();
uint8_t XBEE_RxBufferRead();
uint8_t XBEE_RxBufferPeek(uint8_t shift);
uint16_t XBEE_RxBufferSize();
uint8_t XBEE_RxIsIdle();
void XBEE_RxBufferFlush();
uint8_t XBEE_RxBufferRecycle(XBEE_packet_t * packet);


/***************************************
* Common functions
***************************************/


CY_ISR_PROTO(XBEE_RX_ISR);

#endif

/* [] END OF FILE */
