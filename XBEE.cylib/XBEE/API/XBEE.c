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

#include "`$INSTANCE_NAME`.h"

/***************************************
* Global data allocation
***************************************/

/**
* Init var.
* @see XBEE_Start()
*/
uint8 `$INSTANCE_NAME`_initVar = 0u;


/** Array containing the broadcast hardware address */
uint8_t `$INSTANCE_NAME`_BROADCAST_HW_ADDRESS[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


/** Array containing the broadcast network address */
uint8_t `$INSTANCE_NAME`_BROADCAST_NWK_ADDRESS[] = {0xFF, 0xFE};


/** RX buffer status register */
volatile uint8_t `$INSTANCE_NAME`_RX_STATUS_REG;


/** Packet parsing status register */
volatile uint8_t `$INSTANCE_NAME`_PACKET_STATUS_REG;


/** RX buffer FSM state */
volatile `$INSTANCE_NAME`_rxState_t `$INSTANCE_NAME`_rxState;


/**
* RX buffer.
*/
volatile uint8_t `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_RX_BUFFER_SIZE];


/**
* RX buffer WRITE pointer.
* This variable points to the next available space in the RX buffer.
*/
volatile uint16_t `$INSTANCE_NAME`_rxBufferWrite;


/**
* RX buffer READ pointer.
* This variable points to the next byte to be read from the RX buffer.
*/
volatile uint16_t `$INSTANCE_NAME`_rxBufferRead;


/**
* RX buffer TAIL pointer.
* This variable points to the next writeable byte after the last valid packet.
*/
volatile uint16_t `$INSTANCE_NAME`_rxBufferTail;


/**
* RX buffer HEAD pointer.
* This variable points to the first byte of the first valid packet in the buffer.
*/
volatile uint16_t `$INSTANCE_NAME`_rxBufferHead;


/**
* Current packet length.
* Temporary variable to store the length of the packet being received.
* XBEE_RX_ISR internal use only.
*/
volatile uint16_t `$INSTANCE_NAME`_rxLength;


/**
* Current packet checksum.
* Temporary variable to store the calculation of the packet being
* received. After reception, its content is checked against the
* received checksum byte. XBEE_RX_ISR internal use only.
*/
volatile uint8_t `$INSTANCE_NAME`_rxChecksum;


/**
* Valid packet received.
* When the last byte of an incoming packet is received, this variable is set to
* 1u for the ISR. XBEE_RX_ISR internal use only.
*/
volatile uint8_t `$INSTANCE_NAME`_rxPacketOK;


/**
* Initializes and enables the XBEE operation.
* This is the preferred method to begin component operation. XBEE_Start()
* starts the associated UART, sets the initVar variable, calls the XBEE_Init()
* function, and then calls the XBEE_Enable() function.
*
* @see XBEE_Init()
* @see XBEE_Enable()
*/
void `$INSTANCE_NAME`_Start(void)
{
    /* Start UART component */
    `$UART`_Start();
    
    /* If not Initialized then initialize all required hardware and software */
    if(`$INSTANCE_NAME`_initVar == 0u)
    {
        `$INSTANCE_NAME`_Init();
        `$INSTANCE_NAME`_initVar = 1u;
    }
    
    `$INSTANCE_NAME`_Enable();
}


/**
* Disables the XBEE operation.
* This is the preferred method to stop component operation. XBEE_Stop()
* stops the associated UART, and sets the XBEE module to sleep.
*/
void `$INSTANCE_NAME`_Stop(void) 
{
    `$SLEEP_RQ`_Write(1);
    `$UART`_Stop();
}


/**
* Initializes or restores the component according to the customizer Configure
* dialog settings. It is not necessary to call XBEE_Init() because the
* XBEE_Start() API calls this function and is the preferred method to begin
* component operation.
*
* @see XBEE_Start()
*/
void `$INSTANCE_NAME`_Init(void) 
{
    `$RESET`_Write(0);
    
    `$INSTANCE_NAME`_rxState = IDLE;
    `$INSTANCE_NAME`_rxBufferWrite = 0;
    `$INSTANCE_NAME`_rxBufferRead = 0;
    `$INSTANCE_NAME`_rxBufferTail = 0;
    `$INSTANCE_NAME`_rxBufferHead = 0;
    `$INSTANCE_NAME`_rxLength = 0;
    `$INSTANCE_NAME`_rxPacketOK = 0;
    
    `$INSTANCE_NAME`_RX_STATUS_REG = `$INSTANCE_NAME`_RX_STATUS_EMPTY;
    `$INSTANCE_NAME`_PACKET_STATUS_REG = 0;
    
    `$RESET`_Write(1);
}


/**
* Activates the hardware and begins component operation. It is not necessary to
* call XBEE_Enable() because the XBEE_Start() API calls this function, which is
* the preferred method to begin component operation.
*
* @see XBEE_Start()
*/
void `$INSTANCE_NAME`_Enable(void) 
{
    #if defined(CY_SCB_`$UART`_H)
        `$UART`_SetRxInterruptMode(`$UART`_INTR_RX_NOT_EMPTY);
        `$RX_INT`_StartEx(`$INSTANCE_NAME`_RX_ISR);
    #elif defined(CY_UART_`$UART`_H)
        `$UART`_SetRxInterruptMode(`$UART`_RX_STS_FIFO_NOTEMPTY);
        `$RX_INT`_StartEx(`$INSTANCE_NAME`_RX_ISR);
    #else
        #error "UART not defined"
    #endif
    
    `$SLEEP_RQ`_Write(0);
}


/**
* This function saves the component configuration and nonretention registers.
* It also saves the current component parameter values, as defined in the
* Configure dialog or as modified by appropriate APIs. This function is called
* by the XBEE_Sleep() function.
*
* @see XBEE_Sleep()
*/
void `$INSTANCE_NAME`_SaveConfig(void) 
{
    
}


/**
* Restores the user configuration of nonretention registers.
*
* @see XBEE_Wakeup()
*/
void `$INSTANCE_NAME`_RestoreConfig(void) 
{
    
}


/**
* This is the preferred API to prepare the component for sleep. The
* XBEE_Sleep() API saves the current component state. Then it calls the
* XBEE_Stop() function and calls XBEE_SaveConfig() to save the hardware
* configuration. Call the UART_Sleep() function before calling CyPmSleep()
* or CyPmHibernate() functions. Refer to the PSoC Creator System Reference
* Guide for more information about power management functions.
*
* @see XBEE_SaveConfig()
* @see XBEE_Stop()
*/
void `$INSTANCE_NAME`_Sleep(void) 
{
    #if defined(CY_SCB_`$UART`_H)
    while(`$UART`_SpiUartGetTxBufferSize()); // block until TX ends
    #elif defined(CY_UART_`$UART`_H)
    while(`$UART`_GetTxBufferSize());
    #else
        #error "UART not defined"
    #endif
    
    `$INSTANCE_NAME`_SaveConfig();
    
    `$SLEEP_RQ`_Write(1);
    `$UART`_Sleep();
}


/**
* This is the preferred API to restore the component to the state when
* XBEE_Sleep() was called. The XBEE_Wakeup() function calls the
* XBEE_RestoreConfig() function to restore the configuration. If the component
* was enabled before the XBEE_Sleep() function was called, the XBEE_Wakeup()
* function will also re-enable the component.
*
* @see XBEE_Sleep()
* @see XBEE_RestoreConfig()
*/
void `$INSTANCE_NAME`_Wakeup(void) 
{
    `$INSTANCE_NAME`_RestoreConfig();
    
    `$UART`_Wakeup();
    
    `$SLEEP_RQ`_Write(0);
    
    #if !defined(`$UART`_FLOW_CONTROL)
        CyDelay(3);
    #endif
}


/***************************************
* TX functions
***************************************/


/**
* Transmit RF data.
* This method creates a ZIGBEE TRANSMIT REQUEST frame and sends it over the air
* to a destination device.
*
* See XBEE reference manual for detailed information on frame fields.
*
* @see XBEE_packet_t XBEE packet type
*
* @param packet A pointer to the XBEE_packet_t where data is going to be stored.
* @param frameId Frame identifier.
* @param hwAddress Pointer to an 8-bytes array containing the hardware address of the destination device.
* @param nwkAddress Pointer to a 2-bytes array containgin the network address of the destination device.
* @param broadcastRadius Broadcast Radius field.
* @param options Options field.
* @param RFData Ponter to an array containing the actual data to be transmitted.
* @param RFDataLen Length of the RFData array.
*/
uint8_t `$INSTANCE_NAME`_ZigBeeTransmitRequest(`$INSTANCE_NAME`_packet_t * packet, uint8_t frameId, uint8_t * hwAddress, uint8_t * nwkAddress, uint8_t broadcastRadius, uint8_t options, uint8_t * RFData, uint8_t RFDataLen) {
    /* Length */
    packet->length = 14 + RFDataLen;
    /* API Identifier */
    packet->payload[0] = `$INSTANCE_NAME`_APIID_ZIGBEE_TX_RQ;
    /* Frame Id */
    packet->payload[1] = frameId;
    /* Destination Hardware Address */
    memcpy(&(packet->payload[2]), hwAddress, 8);
    /* Destination Network Address */
    memcpy(&(packet->payload[10]), nwkAddress, 2);
    /* Broadcast radius */
    packet->payload[12] = broadcastRadius;
    /* Options */
    packet->payload[13] = options;
    /* Payload */
    memcpy(&(packet->payload[14]), RFData, RFDataLen);
    /* Checksum */
    packet->checksum = `$INSTANCE_NAME`_Checksum(packet);
    
    `$INSTANCE_NAME`_Issue(packet);
    
    return 0;
}


/***************************************
* AT functions
***************************************/


/**
* Issue AT commands to XBee module. 
*
* @param packet A pointer to the XBEE_packet_t where data is going to be stored.
* @param frameId Frame identifier. Note: If Frame ID = 0 in AT Command Mode, no
* AT Command Response will be given.
* @param AT 2-byte array of the AT command.
* @param value Ponter to an array containing the paramter value.
* @param RFDataLen Length of the value array.
* @return Always 0.
*/
uint8_t `$INSTANCE_NAME`_ATCommand(`$INSTANCE_NAME`_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen) {
    /* Length */
    packet->length = 4 + valueLen;
    /* API Identifier */
    packet->payload[0] = `$INSTANCE_NAME`_APIID_AT_COMMAND;
    /* Frame Id */
    packet->payload[1] = frameId;
    /* AT Command */
    packet->payload[2] = AT[0];
    packet->payload[3] = AT[1];
    /* Parameter value */
    memcpy(&(packet->payload[4]), value, valueLen);
    /* Checksum */
    packet->checksum = `$INSTANCE_NAME`_Checksum(packet);
    
    `$INSTANCE_NAME`_Issue(packet);
    
    return 0;
}


/**
* Issue and enqueue AT commands to XBee module. Commands will not be applied
* until either the "AT Command" (0x08) API type or the AC (Apply Changes)
* command is issued.
*
* @param packet A pointer to the XBEE_packet_t where data is going to be stored.
* @param frameId Frame identifier. Note: If Frame ID = 0 in AT Command Mode, no
* AT Command Response will be given.
* @param AT 2-byte array of the AT command.
* @param value Ponter to an array containing the paramter value.
* @param RFDataLen Length of the value array.
* @return Always 0.
*/
uint8_t `$INSTANCE_NAME`_ATCommandQueue(`$INSTANCE_NAME`_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen){
    /* Length */
    packet->length = 4 + valueLen;
    /* API Identifier */
    packet->payload[0] = `$INSTANCE_NAME`_APIID_AT_COMMAND_QUEUE;
    /* Frame Id */
    packet->payload[1] = frameId;
    /* AT Command */
    packet->payload[2] = AT[0];
    packet->payload[3] = AT[1];
    /* Parameter value */
    memcpy(&(packet->payload[4]), value, valueLen);
    /* Checksum */
    packet->checksum = `$INSTANCE_NAME`_Checksum(packet);
    
    `$INSTANCE_NAME`_Issue(packet);
    
    return 0;  
}


/***************************************
* Packet functions
***************************************/


/**
* Send the dessignated packet over the associated UART.
*
* @param packet Pointer to the packet to be sent.
* @return Always 0.
*/
uint8_t `$INSTANCE_NAME`_Issue(`$INSTANCE_NAME`_packet_t * packet) {
    #if defined(CY_SCB_`$UART`_H)
        `$UART`_UartPutChar(`$INSTANCE_NAME`_PACKET_START);
        `$UART`_UartPutChar(packet->length >> 8);
        `$UART`_UartPutChar(packet->length);
        `$UART`_SpiUartPutArray(packet->payload, packet->length);
        `$UART`_UartPutChar(packet->checksum);
    #elif defined(CY_UART_`$UART`_H)
        `$UART`_PutChar(`$INSTANCE_NAME`_PACKET_START);
        `$UART`_PutChar(packet->length >> 8);
        `$UART`_PutChar(packet->length);
        `$UART`_PutArray(packet->payload, packet->length);
        `$UART`_PutChar(packet->checksum);
    #else
        #error "UART not defined"
    #endif
    
    return 0;
}


/**
* Read packet from the XBEE_rxBuffer.
* This functions modifies the XBEE_RX_STATUS_REG variable. Check it for
* deeper insight of the status of the register.
*
* @see XBEE_ReadRxStatus()
* @see XBEE_RX_STATUS_REG
*
* @param packet Packet to store the content from the buffer.
* @return XBEE_READPACKET_OK: Packet read successfully.
* @return XBEE_READPACKET_EMPTY: There are no packets in the buffer.
* @return XBEE_READPACKET_ERROR: There is been an error reading the packet.
*/
uint8_t `$INSTANCE_NAME`_ReadPacket(`$INSTANCE_NAME`_packet_t * packet) {
    uint8_t i, readData, checksum;
    uint16_t length;
    
    /* Check if there are any packets in the RX buffer */
    if(`$INSTANCE_NAME`_rxBufferHead == `$INSTANCE_NAME`_rxBufferTail) {
        /* Unset PACKET status bit */
        `$INSTANCE_NAME`_RX_STATUS_REG &= ~`$INSTANCE_NAME`_RX_STATUS_PACKET;
        return `$INSTANCE_NAME`_READPACKET_EMPTY;
    }

    /* Read from the head of the queue */
    `$INSTANCE_NAME`_rxBufferRead = `$INSTANCE_NAME`_rxBufferHead;
        
    /* Check for packet start */
    if(`$INSTANCE_NAME`_RxBufferRead() != `$INSTANCE_NAME`_PACKET_START) {
        /* Raise START ERROR status bit */
        `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_START_ERROR;
        return `$INSTANCE_NAME`_READPACKET_ERROR;
    }
        
    /* Read packet length */
    length = (`$INSTANCE_NAME`_RxBufferRead() << 8) + `$INSTANCE_NAME`_RxBufferRead();
        
    /* Check length against buffer size */
    if(length > `$INSTANCE_NAME`_RxBufferSize() + 4) {
        /* Raise LENGTH ERROR status bit */
        `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_LENGTH_ERROR;
        return `$INSTANCE_NAME`_READPACKET_ERROR;
    }
    
    /* Update length field */
    packet->length = length;
            
    /* Read packet payload */
    checksum = 0xFF;
    for(i=0; i < length; i++) {
        readData = `$INSTANCE_NAME`_RxBufferRead();
        packet->payload[i] = readData;
        checksum -= readData;
    }
        
    /* Read checksum */
    packet->checksum = `$INSTANCE_NAME`_RxBufferRead();
        
    /* Check if there's been an UNDERRUN condition during reading */
    if((`$INSTANCE_NAME`_RX_STATUS_REG & `$INSTANCE_NAME`_RX_STATUS_UNDERRUN) != 0u) {
        return `$INSTANCE_NAME`_READPACKET_ERROR;
    }
    
    /* Verify checksum and return result */
    if(packet->checksum != checksum) {
        /* Set CHECKSUM ERROR status bit */
        `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_CHECKSUM_ERROR;
        return `$INSTANCE_NAME`_READPACKET_ERROR;
    }
    
    /* Check for more packets in the buffer */
    if(`$INSTANCE_NAME`_rxBufferHead == `$INSTANCE_NAME`_rxBufferTail) {
        /* Unset PACKET status bit */
        `$INSTANCE_NAME`_RX_STATUS_REG &= ~`$INSTANCE_NAME`_RX_STATUS_PACKET;
    }
    
    /* Update buffer head */
    `$INSTANCE_NAME`_rxBufferHead = `$INSTANCE_NAME`_rxBufferRead;
    
    return `$INSTANCE_NAME`_READPACKET_OK;
}


/**
* Calculate checksum.
* Calculate checksum of a given packet. This method does not populate the
* checksum field.
*
* @param packet. Pointer to the packet.
* @return Checksum result.
*/
uint8_t `$INSTANCE_NAME`_Checksum(`$INSTANCE_NAME`_packet_t * packet) {
    uint16_t i;
    uint8_t sum;
    
    sum = 0xFF;
    
    for(i=0; i<packet->length; i++) {
        sum -= packet->payload[i];
    }
    
    return sum;
}


/**
* Read the XBEE_PACKET_STATUS_REG variable.
* Calling this method clears the register.
*
* @return XBEE_PACKET_STATUS_REG content.
*/
uint8_t `$INSTANCE_NAME`_ReadPacketStatus() {
    uint8_t status;
    
    /* Make a copy of register */
    status = `$INSTANCE_NAME`_PACKET_STATUS_REG;
    
    /* Clear all */
    `$INSTANCE_NAME`_PACKET_STATUS_REG = 0;
    
    return status;
}


/**
* Read API ID from a packet.
*
* @param packet Packet to read.
* @return API ID.
*/
uint8_t `$INSTANCE_NAME`_ReadApiId(`$INSTANCE_NAME`_packet_t * packet) {
    return packet->payload[0];
}


/**
* Read the Frame ID field from a packet.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param packet Packet to read.
* @return Frame ID.
*/
uint8_t `$INSTANCE_NAME`_ReadFrameId(`$INSTANCE_NAME`_packet_t * packet) {
    switch(`$INSTANCE_NAME`_ReadApiId(packet)) {
        case `$INSTANCE_NAME`_APIID_ZIGBEE_TRANSMIT_STATUS:
        case `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET:
        case `$INSTANCE_NAME`_APIID_ZIGBEE_EXPLICIT_RX_INDICATOR:
        case `$INSTANCE_NAME`_APIID_AT_COMMAND_RESPONSE:
            return packet->payload[1];
        break;
        default:
            `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
            return 0;
        break;
    }
}


/**
* Read the network address of the source device from a packet.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param Packet to read.
* @return Pointer to the first byte of the address field.
* @return NULL for packets not having such field.
*/
uint8_t * `$INSTANCE_NAME`_ReadNwkSourceAddress(`$INSTANCE_NAME`_packet_t * packet) {
    switch(`$INSTANCE_NAME`_ReadApiId(packet)) {
        case `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET:
            return &(packet->payload[1]);
        break;
        default:
            `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
            return NULL;
        break;
    }
}


/**
* Read the hardware address of the source device from a packet.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param Packet to read.
* @return Pointer to the first byte of the address field.
* @return NULL for packets not having such field.
*/
uint8_t * `$INSTANCE_NAME`_ReadHwSourceAddress(`$INSTANCE_NAME`_packet_t * packet) {
    switch(`$INSTANCE_NAME`_ReadApiId(packet)) {
        case `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET:
            return &(packet->payload[10]);
        break;
        default:
            `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
            return NULL;
        break;
    }
}


/**
* Read Receive Options field from a ZIGBEE RX PACKET.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param packet Packet to read.
* @return Receive Options field.
*/
uint8_t `$INSTANCE_NAME`_ReadReceiveOptions(`$INSTANCE_NAME`_packet_t * packet) {
    switch(`$INSTANCE_NAME`_ReadApiId(packet)) {
        case `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET:
            return packet->payload[11];
        break;
        default:
            `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
            return 0;
        break;
    }
}


/**
* Read the RF data from a ZIGBEE RX PACKET packet.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param Packet to read.
* @return Pointer to the first byte of the RF data.
* @return NULL for packets not having such field.
*/
uint8_t * `$INSTANCE_NAME`_ReadRFData(`$INSTANCE_NAME`_packet_t * packet) {
    switch(`$INSTANCE_NAME`_ReadApiId(packet)) {
        case `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET:
            return &(packet->payload[12]);
        break;
        default:
            `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
            return 0;
        break;
    }
}

/**
* Get the length of the RF data field from a ZIGBEE RX PACKET packet.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param Packet to read.
* @return Length of RF data.
*/
uint8_t `$INSTANCE_NAME`_ReadRFDataLen(`$INSTANCE_NAME`_packet_t * packet) {
    switch(`$INSTANCE_NAME`_ReadApiId(packet)) {
        case `$INSTANCE_NAME`_APIID_ZIGBEE_RX_PACKET:
            return packet->length - 12;
        break;
        default:
            `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
            return 0;
        break;
    }
}


/**
* Read Delivery Status field from a ZIGBEE RX PACKET.
* This function sets the XBEE_PACKET_STATUS_NOT_A_FIELD bit in the
* register XBEE_PACKET_STATUS_REG if a packet has not such field.
*
* @param packet Packet to read.
* @return Delivery Status field.
*/
uint8_t `$INSTANCE_NAME`_ReadDeliveryStatus(`$INSTANCE_NAME`_packet_t * packet) {
    if(`$INSTANCE_NAME`_ReadApiId(packet) == `$INSTANCE_NAME`_APIID_ZIGBEE_TRANSMIT_STATUS) {
        return packet->payload[5];
    } else {
        `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}


uint8_t * `$INSTANCE_NAME`_ReadATResponse_Command(`$INSTANCE_NAME`_packet_t * packet) {
    if(`$INSTANCE_NAME`_ReadApiId(packet) == `$INSTANCE_NAME`_APIID_AT_COMMAND_RESPONSE) {
        return &(packet->payload[2]);
    } else {
        `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}

uint8_t `$INSTANCE_NAME`_ReadATResponse_Status(`$INSTANCE_NAME`_packet_t * packet) {
    if(`$INSTANCE_NAME`_ReadApiId(packet) == `$INSTANCE_NAME`_APIID_AT_COMMAND_RESPONSE) {
        return packet->payload[4];
    } else {
        `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}

uint8_t * `$INSTANCE_NAME`_ReadATResponse_Data(`$INSTANCE_NAME`_packet_t * packet) {
    if(`$INSTANCE_NAME`_ReadApiId(packet) == `$INSTANCE_NAME`_APIID_AT_COMMAND_RESPONSE) {
        return &(packet->payload[5]);
    } else {
        `$INSTANCE_NAME`_PACKET_STATUS_REG |= `$INSTANCE_NAME`_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}



/***************************************
* RX functions
***************************************/

/**
* Read the XBEE_RX_STATUS_REG register.
* This is the preferred method to read the XBEE_RX_STATUS_REG register. All bits are
* cleared after reading except XBEE_RX_STATUS_PACKET and XBEE_RX_STATUS_EMPTY bits.
*
* @see XBEE_RX_STATUS_REG
*
* @return Content of the XBEE_RX_STATUS_REG.
*/
uint8_t `$INSTANCE_NAME`_ReadRxStatus() {
    uint8_t status;
    
    // Make a copy of register
    status = `$INSTANCE_NAME`_RX_STATUS_REG;
    
    // Clear all except PACKET and EMPTY bits
    `$INSTANCE_NAME`_RX_STATUS_REG &= (`$INSTANCE_NAME`_RX_STATUS_PACKET | `$INSTANCE_NAME`_RX_STATUS_EMPTY);
    
    return status;
}


/**
* Read the next byte from XBEE_rxBuffer.
*
* @return Byte from XBEE_rxBuffer.
*/
uint8_t `$INSTANCE_NAME`_RxBufferRead() {
    uint8_t readData;
    
    /* Check for buffer underrun */
    if(`$INSTANCE_NAME`_rxBufferRead == `$INSTANCE_NAME`_rxBufferTail) {
        /* Assert UNDERRUN status bits */
        `$INSTANCE_NAME`_RX_STATUS_REG |=  `$INSTANCE_NAME`_RX_STATUS_UNDERRUN;
        return 0;
    }
    
    /* Read data from buffer */
    readData = `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferRead];
    
    /* Increment pointer */
    `$INSTANCE_NAME`_rxBufferRead = (`$INSTANCE_NAME`_rxBufferRead +1) % `$INSTANCE_NAME`_RX_BUFFER_SIZE;
        
    return readData;
}


/**
* Read the next byte from the XBEE_rxBuffer without extracting it.
* 
* @param shift Offset of byte to be read from the XBEE_rxBufferRead pointer.
* @return Byte content.
*/
uint8_t `$INSTANCE_NAME`_RxBufferPeek(uint8_t shift) {
    return `$INSTANCE_NAME`_rxBuffer[(`$INSTANCE_NAME`_rxBufferRead + shift) % `$INSTANCE_NAME`_RX_BUFFER_SIZE];
}


/**
* Get the number of bytes in XBEE_rxBuffer.
*
* @return Number of bytes.
*/
uint16_t `$INSTANCE_NAME`_RxBufferSize() {
    if(`$INSTANCE_NAME`_rxBufferHead <= `$INSTANCE_NAME`_rxBufferTail) {
        return `$INSTANCE_NAME`_rxBufferTail - `$INSTANCE_NAME`_rxBufferHead;
    } else {
        return `$INSTANCE_NAME`_rxBufferTail + `$INSTANCE_NAME`_RX_BUFFER_SIZE - `$INSTANCE_NAME`_rxBufferHead;
    }
}


/**
* Query if the RX state machine is waiting for a new packet.
*
* @return 1 for IDLE, 0 otherwise.
*/
uint8_t `$INSTANCE_NAME`_RxIsIdle() {
    return `$INSTANCE_NAME`_rxState == IDLE ? 1 : 0;
}


/**
* Flushes the RX buffer.
* Sets XBEE_rxBufferWrite, XBEE_rxBufferRead, XBEE_rxBufferTail and
* XBEE_rxBufferHead pointers to 0 and clears XBEE_RX_STATUS_REG setting
* the XBEE_RX_STATUS_EMPTY bit.
*/
void `$INSTANCE_NAME`_RxBufferFlush() {
    /* Reset buffer pointers */
    `$INSTANCE_NAME`_rxBufferWrite = 0;
    `$INSTANCE_NAME`_rxBufferRead = 0;
    `$INSTANCE_NAME`_rxBufferTail = 0;
    `$INSTANCE_NAME`_rxBufferHead = 0;
    
    /* Reset RX status register */
    `$INSTANCE_NAME`_RX_STATUS_REG = `$INSTANCE_NAME`_RX_STATUS_EMPTY;
}


/**
* Enqueue a packet in the RX buffer.
* Enqueue a packet in the XBEE_rxBuffer for other part of the code to
* handle it.
* 
* @param packet Packet to be recycled.
* @return XBEE_RECYCLE_OK: Packet recycled successfully.
* @return XBEE_RECYCLE_BUSY: Buffer is busy receiving a packet.
* @return XBEE_NOROOM: There is no empty room for the packet to by recycled.
*/
uint8_t `$INSTANCE_NAME`_RxBufferRecycle(`$INSTANCE_NAME`_packet_t * packet) {
    uint32_t intState;
    uint16_t i;
    
    /* Check RX state */
    if(`$INSTANCE_NAME`_rxState != IDLE) {
        return `$INSTANCE_NAME`_RECYCLE_BUSY;
    }
    
    /* Save interrupt state */
    intState = (*`$RX_INT`_INTC_SET_EN & (uint32_t)`$RX_INT`__INTC_MASK);
    
    /* Disable RX interrupt */
    *`$RX_INT`_INTC_SET_EN &= ~((uint32_t) `$RX_INT`__INTC_MASK);
    
    /* Check for room */
    if((`$INSTANCE_NAME`_RX_BUFFER_SIZE - `$INSTANCE_NAME`_RxBufferSize() - 1) < (packet->length + 4)) {
        /* Restore RX interrupt */
        *`$RX_INT`_INTC_SET_EN |= intState;
        return `$INSTANCE_NAME`_RECYCLE_NOROOM;
    }
    
    `$INSTANCE_NAME`_rxBufferWrite = `$INSTANCE_NAME`_rxBufferTail;
    
    /* Write START byte */
    `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferWrite] = `$INSTANCE_NAME`_PACKET_START;
    
    /* Increment WRITE pointer */
    `$INSTANCE_NAME`_rxBufferWrite++;
    if(`$INSTANCE_NAME`_rxBufferWrite == `$INSTANCE_NAME`_RX_BUFFER_SIZE) {
        `$INSTANCE_NAME`_rxBufferWrite = 0;
    }
    
    /* Write LENGTH_H byte */
    `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferWrite] = (uint8_t) (packet->length >> 8);
        
    /* Increment WRITE pointer */
    `$INSTANCE_NAME`_rxBufferWrite++;
    if(`$INSTANCE_NAME`_rxBufferWrite == `$INSTANCE_NAME`_RX_BUFFER_SIZE) {
        `$INSTANCE_NAME`_rxBufferWrite = 0;
    }
    
    /* Write LENGTH_L byte */
    `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferWrite] = (uint8_t) (0x00FF & packet->length);
        
    /* Increment WRITE pointer */
    `$INSTANCE_NAME`_rxBufferWrite++;
    if(`$INSTANCE_NAME`_rxBufferWrite == `$INSTANCE_NAME`_RX_BUFFER_SIZE) {
        `$INSTANCE_NAME`_rxBufferWrite = 0;
    }
    
    /* Copy PAYLOAD */
    for(i=0; i<packet->length; i++) {
        `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferWrite] = packet->payload[i];
        /* Increment WRITE pointer */
        `$INSTANCE_NAME`_rxBufferWrite++;
        if(`$INSTANCE_NAME`_rxBufferWrite == `$INSTANCE_NAME`_RX_BUFFER_SIZE) {
            `$INSTANCE_NAME`_rxBufferWrite = 0;
        }
    }
    
    /* Write CHECKSUM byte */
    `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferWrite] = packet->checksum;
    
    /* Increment WRITE pointer */
    `$INSTANCE_NAME`_rxBufferWrite++;
    if(`$INSTANCE_NAME`_rxBufferWrite == `$INSTANCE_NAME`_RX_BUFFER_SIZE) {
        `$INSTANCE_NAME`_rxBufferWrite = 0;
    }
    
    /* Update TAIL pointer */
    `$INSTANCE_NAME`_rxBufferTail = `$INSTANCE_NAME`_rxBufferWrite;
    
    /* Restore interrupt state */
    *`$RX_INT`_INTC_SET_EN |= intState;
    
    /* Set PACKET and clear EMPTY status bit */
    `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_PACKET;
    `$INSTANCE_NAME`_RX_STATUS_REG &= ~`$INSTANCE_NAME`_RX_STATUS_EMPTY;
    
    return `$INSTANCE_NAME`_RECYCLE_OK;
}



#if defined(CY_SCB_`$UART`_H)
    
    #warning "SCB ISR not implemented"
CY_ISR(`$INSTANCE_NAME`_RX_ISR) {
    `$UART`_SpiUartClearRxBuffer();
    `$UART`_ClearRxInterruptSource(0xFFFFFFFF);
}

#elif defined(CY_UART_`$UART`_H)
    
/**
* RX Interrupt Service Routine.
* 
*/
CY_ISR(`$INSTANCE_NAME`_RX_ISR) {
    uint8_t readData;

    readData = `$UART`_RXSTATUS_REG;

    /* Check for errors reading byte */
    if((readData & (`$UART`_RX_STS_PAR_ERROR | `$UART`_RX_STS_STOP_ERROR | 
                    `$UART`_RX_STS_BREAK | `$UART`_RX_STS_OVERRUN)) != 0u)
    {
        /* Set UART ERROR status bit */
        `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_UART_ERROR;
        
        /* Check buffer overrun condition */
        if((readData & `$UART`_RX_STS_OVERRUN) != 0u) {
            /* Set OVERFLOW status bit */
            `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_OVERFLOW;
        }
        
        /* Return to IDLE */
        `$INSTANCE_NAME`_rxState = IDLE;
        
        /* Flush UART FIFO */
        while((readData & `$UART`_RX_STS_FIFO_NOTEMPTY) != 0u) {
            readData = `$UART`_RXDATA_REG;
            readData = `$UART`_RXSTATUS_REG;
        }
        
        /* Exit ISR */
        return;
    }
    
    /* Check buffer for space */
    if((`$INSTANCE_NAME`_rxBufferWrite +1) % `$INSTANCE_NAME`_RX_BUFFER_SIZE == `$INSTANCE_NAME`_rxBufferHead) {
        /* Hold data in UART FIFO */
        /* Exit ISR */
        return;
    }
    
    while((readData & `$UART`_RX_STS_FIFO_NOTEMPTY) != 0u) {
        /* Read byte from UART */
        readData = `$UART`_RXDATA_REG;
        
        /* Packet buffering state machine */
        switch(`$INSTANCE_NAME`_rxState) {
            case IDLE: /* Expecting a 'start delimiter' */
                if(readData == `$INSTANCE_NAME`_PACKET_START) {
                    `$INSTANCE_NAME`_rxBufferWrite = `$INSTANCE_NAME`_rxBufferTail;
                    `$INSTANCE_NAME`_rxState = LENH;
                } else {
                    /* Check again if there is data */
                    readData = XBEE_UART_RXSTATUS_REG;
                    continue;
                }
            break;
            case LENH: /* Byte is MSB of length field */
                `$INSTANCE_NAME`_rxLength = readData << 8;
                `$INSTANCE_NAME`_rxState = LENL;
            break;
            case LENL: /* Byte is LSB of length field */
                `$INSTANCE_NAME`_rxLength |= readData;
                `$INSTANCE_NAME`_rxChecksum = 0xFF;
                `$INSTANCE_NAME`_rxState = PAYLOAD;
            break;
            case PAYLOAD: /* Buffering payload */
                `$INSTANCE_NAME`_rxLength--;
                `$INSTANCE_NAME`_rxChecksum -= readData;
                if(`$INSTANCE_NAME`_rxLength == 0u) {
                    `$INSTANCE_NAME`_rxState = CHECKSUM;
                }
            break;
            case CHECKSUM: /* Byte is packet checksum */
                if(`$INSTANCE_NAME`_rxChecksum == readData) {
                    `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_PACKET;
                    `$INSTANCE_NAME`_rxPacketOK = 1u;
                } else {
                    `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_CHECKSUM_ERROR;
                }
                `$INSTANCE_NAME`_rxState = IDLE;
            break;
            default: /* This shouldn't happen */
                /* Set UART ERROR status bit */
                `$INSTANCE_NAME`_RX_STATUS_REG |= `$INSTANCE_NAME`_RX_STATUS_UART_ERROR;
                
                /* Reset pointer */
                `$INSTANCE_NAME`_rxBufferWrite = `$INSTANCE_NAME`_rxBufferTail;
                
                /* Return to IDLE */
                `$INSTANCE_NAME`_rxState = IDLE;
                
                /* Check again if there is data */
                readData = `$UART`_RXSTATUS_REG;
                continue;
            break;
        }
        
        /* Buffer new byte */
        `$INSTANCE_NAME`_rxBuffer[`$INSTANCE_NAME`_rxBufferWrite] = readData;
        
        /* Increment WRITE pointer */
        `$INSTANCE_NAME`_rxBufferWrite++;
        
        /* Check pointer for a loop condition */
        if(`$INSTANCE_NAME`_rxBufferWrite >= `$INSTANCE_NAME`_RX_BUFFER_SIZE) {
            `$INSTANCE_NAME`_rxBufferWrite = 0;
        }
        
        /* Packet received */
        if(`$INSTANCE_NAME`_rxPacketOK == 1u) {
            `$INSTANCE_NAME`_rxPacketOK = 0u;
            `$INSTANCE_NAME`_rxBufferTail = `$INSTANCE_NAME`_rxBufferWrite;
        }
        
        /* Check again if there is data */
        readData = XBEE_UART_RXSTATUS_REG;
    }
}

#else
    #error "UART not defined"
#endif


/* [] END OF FILE */
