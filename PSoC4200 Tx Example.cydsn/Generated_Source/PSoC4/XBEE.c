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

#include "XBEE.h"

/***************************************
* Global data allocation
***************************************/

/**
* Init var.
* @see XBEE_Start()
*/
uint8 XBEE_initVar = 0u;


/** Array containing the broadcast hardware address */
uint8_t XBEE_BROADCAST_HW_ADDRESS[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


/** Array containing the broadcast network address */
uint8_t XBEE_BROADCAST_NWK_ADDRESS[] = {0xFF, 0xFE};


/** RX buffer status register */
volatile uint8_t XBEE_RX_STATUS_REG;


/** Packet parsing status register */
volatile uint8_t XBEE_PACKET_STATUS_REG;


/** RX buffer FSM state */
volatile XBEE_rxState_t XBEE_rxState;


/**
* RX buffer.
*/
volatile uint8_t XBEE_rxBuffer[XBEE_RX_BUFFER_SIZE];


/**
* RX buffer WRITE pointer.
* This variable points to the next available space in the RX buffer.
*/
volatile uint16_t XBEE_rxBufferWrite;


/**
* RX buffer READ pointer.
* This variable points to the next byte to be read from the RX buffer.
*/
volatile uint16_t XBEE_rxBufferRead;


/**
* RX buffer TAIL pointer.
* This variable points to the next writeable byte after the last valid packet.
*/
volatile uint16_t XBEE_rxBufferTail;


/**
* RX buffer HEAD pointer.
* This variable points to the first byte of the first valid packet in the buffer.
*/
volatile uint16_t XBEE_rxBufferHead;


/**
* Current packet length.
* Temporary variable to store the length of the packet being received.
* XBEE_RX_ISR internal use only.
*/
volatile uint16_t XBEE_rxLength;


/**
* Current packet checksum.
* Temporary variable to store the calculation of the packet being
* received. After reception, its content is checked against the
* received checksum byte. XBEE_RX_ISR internal use only.
*/
volatile uint8_t XBEE_rxChecksum;


/**
* Valid packet received.
* When the last byte of an incoming packet is received, this variable is set to
* 1u for the ISR. XBEE_RX_ISR internal use only.
*/
volatile uint8_t XBEE_rxPacketOK;


/**
* Initializes and enables the XBEE operation.
* This is the preferred method to begin component operation. XBEE_Start()
* starts the associated UART, sets the initVar variable, calls the XBEE_Init()
* function, and then calls the XBEE_Enable() function.
*
* @see XBEE_Init()
* @see XBEE_Enable()
*/
void XBEE_Start(void)
{
    /* Start UART component */
    XBEE_UART_Start();
    
    /* If not Initialized then initialize all required hardware and software */
    if(XBEE_initVar == 0u)
    {
        XBEE_Init();
        XBEE_initVar = 1u;
    }
    
    XBEE_Enable();
}


/**
* Disables the XBEE operation.
* This is the preferred method to stop component operation. XBEE_Stop()
* stops the associated UART, and sets the XBEE module to sleep.
*/
void XBEE_Stop(void) 
{
    XBEE_SLEEP_RQ_Write(1);
    XBEE_UART_Stop();
}


/**
* Initializes or restores the component according to the customizer Configure
* dialog settings. It is not necessary to call XBEE_Init() because the
* XBEE_Start() API calls this function and is the preferred method to begin
* component operation.
*
* @see XBEE_Start()
*/
void XBEE_Init(void) 
{
    XBEE_RESET_Write(0);
    
    XBEE_rxState = IDLE;
    XBEE_rxBufferWrite = 0;
    XBEE_rxBufferRead = 0;
    XBEE_rxBufferTail = 0;
    XBEE_rxBufferHead = 0;
    XBEE_rxLength = 0;
    XBEE_rxPacketOK = 0;
    
    XBEE_RX_STATUS_REG = XBEE_RX_STATUS_EMPTY;
    XBEE_PACKET_STATUS_REG = 0;
    
    XBEE_RESET_Write(1);
}


/**
* Activates the hardware and begins component operation. It is not necessary to
* call XBEE_Enable() because the XBEE_Start() API calls this function, which is
* the preferred method to begin component operation.
*
* @see XBEE_Start()
*/
void XBEE_Enable(void) 
{
    #if defined(CY_SCB_XBEE_UART_H)
        XBEE_UART_SetRxInterruptMode(XBEE_UART_INTR_RX_NOT_EMPTY);
        XBEE_RX_INT_StartEx(XBEE_RX_ISR);
    #elif defined(CY_UART_XBEE_UART_H)
        XBEE_UART_SetRxInterruptMode(XBEE_UART_RX_STS_FIFO_NOTEMPTY);
        XBEE_RX_INT_StartEx(XBEE_RX_ISR);
    #else
        #error "UART not defined"
    #endif
    
    XBEE_SLEEP_RQ_Write(0);
}


/**
* This function saves the component configuration and nonretention registers.
* It also saves the current component parameter values, as defined in the
* Configure dialog or as modified by appropriate APIs. This function is called
* by the XBEE_Sleep() function.
*
* @see XBEE_Sleep()
*/
void XBEE_SaveConfig(void) 
{
    
}


/**
* Restores the user configuration of nonretention registers.
*
* @see XBEE_Wakeup()
*/
void XBEE_RestoreConfig(void) 
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
void XBEE_Sleep(void) 
{
    #if defined(CY_SCB_XBEE_UART_H)
    while(XBEE_UART_SpiUartGetTxBufferSize()); // block until TX ends
    #elif defined(CY_UART_XBEE_UART_H)
    while(XBEE_UART_GetTxBufferSize());
    #else
        #error "UART not defined"
    #endif
    
    XBEE_SaveConfig();
    
    XBEE_SLEEP_RQ_Write(1);
    XBEE_UART_Sleep();
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
void XBEE_Wakeup(void) 
{
    XBEE_RestoreConfig();
    
    XBEE_UART_Wakeup();
    
    XBEE_SLEEP_RQ_Write(0);
    
    #if !defined(XBEE_UART_FLOW_CONTROL)
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
uint8_t XBEE_ZigBeeTransmitRequest(XBEE_packet_t * packet, uint8_t frameId, uint8_t * hwAddress, uint8_t * nwkAddress, uint8_t broadcastRadius, uint8_t options, uint8_t * RFData, uint8_t RFDataLen) {
    /* Length */
    packet->length = 14 + RFDataLen;
    /* API Identifier */
    packet->payload[0] = XBEE_APIID_ZIGBEE_TX_RQ;
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
    packet->checksum = XBEE_Checksum(packet);
    
    XBEE_Issue(packet);
    
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
uint8_t XBEE_ATCommand(XBEE_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen) {
    /* Length */
    packet->length = 4 + valueLen;
    /* API Identifier */
    packet->payload[0] = XBEE_APIID_AT_COMMAND;
    /* Frame Id */
    packet->payload[1] = frameId;
    /* AT Command */
    packet->payload[2] = AT[0];
    packet->payload[3] = AT[1];
    /* Parameter value */
    memcpy(&(packet->payload[4]), value, valueLen);
    /* Checksum */
    packet->checksum = XBEE_Checksum(packet);
    
    XBEE_Issue(packet);
    
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
uint8_t XBEE_ATCommandQueue(XBEE_packet_t * packet, uint8_t frameId, char * AT, uint8 * value, uint8 valueLen){
    /* Length */
    packet->length = 4 + valueLen;
    /* API Identifier */
    packet->payload[0] = XBEE_APIID_AT_COMMAND_QUEUE;
    /* Frame Id */
    packet->payload[1] = frameId;
    /* AT Command */
    packet->payload[2] = AT[0];
    packet->payload[3] = AT[1];
    /* Parameter value */
    memcpy(&(packet->payload[4]), value, valueLen);
    /* Checksum */
    packet->checksum = XBEE_Checksum(packet);
    
    XBEE_Issue(packet);
    
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
uint8_t XBEE_Issue(XBEE_packet_t * packet) {
    #if defined(CY_SCB_XBEE_UART_H)
        XBEE_UART_UartPutChar(XBEE_PACKET_START);
        XBEE_UART_UartPutChar(packet->length >> 8);
        XBEE_UART_UartPutChar(packet->length);
        XBEE_UART_SpiUartPutArray(packet->payload, packet->length);
        XBEE_UART_UartPutChar(packet->checksum);
    #elif defined(CY_UART_XBEE_UART_H)
        XBEE_UART_PutChar(XBEE_PACKET_START);
        XBEE_UART_PutChar(packet->length >> 8);
        XBEE_UART_PutChar(packet->length);
        XBEE_UART_PutArray(packet->payload, packet->length);
        XBEE_UART_PutChar(packet->checksum);
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
uint8_t XBEE_ReadPacket(XBEE_packet_t * packet) {
    uint8_t i, readData, checksum;
    uint16_t length;
    
    /* Check if there are any packets in the RX buffer */
    if(XBEE_rxBufferHead == XBEE_rxBufferTail) {
        /* Unset PACKET status bit */
        XBEE_RX_STATUS_REG &= ~XBEE_RX_STATUS_PACKET;
        return XBEE_READPACKET_EMPTY;
    }

    /* Read from the head of the queue */
    XBEE_rxBufferRead = XBEE_rxBufferHead;
        
    /* Check for packet start */
    if(XBEE_RxBufferRead() != XBEE_PACKET_START) {
        /* Raise START ERROR status bit */
        XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_START_ERROR;
        return XBEE_READPACKET_ERROR;
    }
        
    /* Read packet length */
    length = (XBEE_RxBufferRead() << 8) + XBEE_RxBufferRead();
        
    /* Check length against buffer size */
    if(length > XBEE_RxBufferSize() + 4) {
        /* Raise LENGTH ERROR status bit */
        XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_LENGTH_ERROR;
        return XBEE_READPACKET_ERROR;
    }
    
    /* Update length field */
    packet->length = length;
            
    /* Read packet payload */
    checksum = 0xFF;
    for(i=0; i < length; i++) {
        readData = XBEE_RxBufferRead();
        packet->payload[i] = readData;
        checksum -= readData;
    }
        
    /* Read checksum */
    packet->checksum = XBEE_RxBufferRead();
        
    /* Check if there's been an UNDERRUN condition during reading */
    if((XBEE_RX_STATUS_REG & XBEE_RX_STATUS_UNDERRUN) != 0u) {
        return XBEE_READPACKET_ERROR;
    }
    
    /* Verify checksum and return result */
    if(packet->checksum != checksum) {
        /* Set CHECKSUM ERROR status bit */
        XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_CHECKSUM_ERROR;
        return XBEE_READPACKET_ERROR;
    }
    
    /* Check for more packets in the buffer */
    if(XBEE_rxBufferHead == XBEE_rxBufferTail) {
        /* Unset PACKET status bit */
        XBEE_RX_STATUS_REG &= ~XBEE_RX_STATUS_PACKET;
    }
    
    /* Update buffer head */
    XBEE_rxBufferHead = XBEE_rxBufferRead;
    
    return XBEE_READPACKET_OK;
}


/**
* Calculate checksum.
* Calculate checksum of a given packet. This method does not populate the
* checksum field.
*
* @param packet. Pointer to the packet.
* @return Checksum result.
*/
uint8_t XBEE_Checksum(XBEE_packet_t * packet) {
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
uint8_t XBEE_ReadPacketStatus() {
    uint8_t status;
    
    /* Make a copy of register */
    status = XBEE_PACKET_STATUS_REG;
    
    /* Clear all */
    XBEE_PACKET_STATUS_REG = 0;
    
    return status;
}


/**
* Read API ID from a packet.
*
* @param packet Packet to read.
* @return API ID.
*/
uint8_t XBEE_ReadApiId(XBEE_packet_t * packet) {
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
uint8_t XBEE_ReadFrameId(XBEE_packet_t * packet) {
    switch(XBEE_ReadApiId(packet)) {
        case XBEE_APIID_ZIGBEE_TRANSMIT_STATUS:
        case XBEE_APIID_ZIGBEE_RX_PACKET:
        case XBEE_APIID_ZIGBEE_EXPLICIT_RX_INDICATOR:
        case XBEE_APIID_AT_COMMAND_RESPONSE:
            return packet->payload[1];
        break;
        default:
            XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t * XBEE_ReadNwkSourceAddress(XBEE_packet_t * packet) {
    switch(XBEE_ReadApiId(packet)) {
        case XBEE_APIID_ZIGBEE_RX_PACKET:
            return &(packet->payload[1]);
        break;
        default:
            XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t * XBEE_ReadHwSourceAddress(XBEE_packet_t * packet) {
    switch(XBEE_ReadApiId(packet)) {
        case XBEE_APIID_ZIGBEE_RX_PACKET:
            return &(packet->payload[10]);
        break;
        default:
            XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t XBEE_ReadReceiveOptions(XBEE_packet_t * packet) {
    switch(XBEE_ReadApiId(packet)) {
        case XBEE_APIID_ZIGBEE_RX_PACKET:
            return packet->payload[11];
        break;
        default:
            XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t * XBEE_ReadRFData(XBEE_packet_t * packet) {
    switch(XBEE_ReadApiId(packet)) {
        case XBEE_APIID_ZIGBEE_RX_PACKET:
            return &(packet->payload[12]);
        break;
        default:
            XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t XBEE_ReadRFDataLen(XBEE_packet_t * packet) {
    switch(XBEE_ReadApiId(packet)) {
        case XBEE_APIID_ZIGBEE_RX_PACKET:
            return packet->length - 12;
        break;
        default:
            XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t XBEE_ReadDeliveryStatus(XBEE_packet_t * packet) {
    if(XBEE_ReadApiId(packet) == XBEE_APIID_ZIGBEE_TRANSMIT_STATUS) {
        return packet->payload[5];
    } else {
        XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}


uint8_t * XBEE_ReadATResponse_Command(XBEE_packet_t * packet) {
    if(XBEE_ReadApiId(packet) == XBEE_APIID_AT_COMMAND_RESPONSE) {
        return &(packet->payload[2]);
    } else {
        XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}

uint8_t XBEE_ReadATResponse_Status(XBEE_packet_t * packet) {
    if(XBEE_ReadApiId(packet) == XBEE_APIID_AT_COMMAND_RESPONSE) {
        return packet->payload[4];
    } else {
        XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
        return 0;
    }
}

uint8_t * XBEE_ReadATResponse_Data(XBEE_packet_t * packet) {
    if(XBEE_ReadApiId(packet) == XBEE_APIID_AT_COMMAND_RESPONSE) {
        return &(packet->payload[5]);
    } else {
        XBEE_PACKET_STATUS_REG |= XBEE_PACKET_STATUS_NOT_A_FIELD;
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
uint8_t XBEE_ReadRxStatus() {
    uint8_t status;
    
    // Make a copy of register
    status = XBEE_RX_STATUS_REG;
    
    // Clear all except PACKET and EMPTY bits
    XBEE_RX_STATUS_REG &= (XBEE_RX_STATUS_PACKET | XBEE_RX_STATUS_EMPTY);
    
    return status;
}


/**
* Read the next byte from XBEE_rxBuffer.
*
* @return Byte from XBEE_rxBuffer.
*/
uint8_t XBEE_RxBufferRead() {
    uint8_t readData;
    
    /* Check for buffer underrun */
    if(XBEE_rxBufferRead == XBEE_rxBufferTail) {
        /* Assert UNDERRUN status bits */
        XBEE_RX_STATUS_REG |=  XBEE_RX_STATUS_UNDERRUN;
        return 0;
    }
    
    /* Read data from buffer */
    readData = XBEE_rxBuffer[XBEE_rxBufferRead];
    
    /* Increment pointer */
    XBEE_rxBufferRead = (XBEE_rxBufferRead +1) % XBEE_RX_BUFFER_SIZE;
        
    return readData;
}


/**
* Read the next byte from the XBEE_rxBuffer without extracting it.
* 
* @param shift Offset of byte to be read from the XBEE_rxBufferRead pointer.
* @return Byte content.
*/
uint8_t XBEE_RxBufferPeek(uint8_t shift) {
    return XBEE_rxBuffer[(XBEE_rxBufferRead + shift) % XBEE_RX_BUFFER_SIZE];
}


/**
* Get the number of bytes in XBEE_rxBuffer.
*
* @return Number of bytes.
*/
uint16_t XBEE_RxBufferSize() {
    if(XBEE_rxBufferHead <= XBEE_rxBufferTail) {
        return XBEE_rxBufferTail - XBEE_rxBufferHead;
    } else {
        return XBEE_rxBufferTail + XBEE_RX_BUFFER_SIZE - XBEE_rxBufferHead;
    }
}


/**
* Query if the RX state machine is waiting for a new packet.
*
* @return 1 for IDLE, 0 otherwise.
*/
uint8_t XBEE_RxIsIdle() {
    return XBEE_rxState == IDLE ? 1 : 0;
}


/**
* Flushes the RX buffer.
* Sets XBEE_rxBufferWrite, XBEE_rxBufferRead, XBEE_rxBufferTail and
* XBEE_rxBufferHead pointers to 0 and clears XBEE_RX_STATUS_REG setting
* the XBEE_RX_STATUS_EMPTY bit.
*/
void XBEE_RxBufferFlush() {
    /* Reset buffer pointers */
    XBEE_rxBufferWrite = 0;
    XBEE_rxBufferRead = 0;
    XBEE_rxBufferTail = 0;
    XBEE_rxBufferHead = 0;
    
    /* Reset RX status register */
    XBEE_RX_STATUS_REG = XBEE_RX_STATUS_EMPTY;
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
uint8_t XBEE_RxBufferRecycle(XBEE_packet_t * packet) {
    uint32_t intState;
    uint16_t i;
    
    /* Check RX state */
    if(XBEE_rxState != IDLE) {
        return XBEE_RECYCLE_BUSY;
    }
    
    /* Save interrupt state */
    intState = (*XBEE_RX_INT_INTC_SET_EN & (uint32_t)XBEE_RX_INT__INTC_MASK);
    
    /* Disable RX interrupt */
    *XBEE_RX_INT_INTC_SET_EN &= ~((uint32_t) XBEE_RX_INT__INTC_MASK);
    
    /* Check for room */
    if((XBEE_RX_BUFFER_SIZE - XBEE_RxBufferSize() - 1) < (packet->length + 4)) {
        /* Restore RX interrupt */
        *XBEE_RX_INT_INTC_SET_EN |= intState;
        return XBEE_RECYCLE_NOROOM;
    }
    
    XBEE_rxBufferWrite = XBEE_rxBufferTail;
    
    /* Write START byte */
    XBEE_rxBuffer[XBEE_rxBufferWrite] = XBEE_PACKET_START;
    
    /* Increment WRITE pointer */
    XBEE_rxBufferWrite++;
    if(XBEE_rxBufferWrite == XBEE_RX_BUFFER_SIZE) {
        XBEE_rxBufferWrite = 0;
    }
    
    /* Write LENGTH_H byte */
    XBEE_rxBuffer[XBEE_rxBufferWrite] = (uint8_t) (packet->length >> 8);
        
    /* Increment WRITE pointer */
    XBEE_rxBufferWrite++;
    if(XBEE_rxBufferWrite == XBEE_RX_BUFFER_SIZE) {
        XBEE_rxBufferWrite = 0;
    }
    
    /* Write LENGTH_L byte */
    XBEE_rxBuffer[XBEE_rxBufferWrite] = (uint8_t) (0x00FF & packet->length);
        
    /* Increment WRITE pointer */
    XBEE_rxBufferWrite++;
    if(XBEE_rxBufferWrite == XBEE_RX_BUFFER_SIZE) {
        XBEE_rxBufferWrite = 0;
    }
    
    /* Copy PAYLOAD */
    for(i=0; i<packet->length; i++) {
        XBEE_rxBuffer[XBEE_rxBufferWrite] = packet->payload[i];
        /* Increment WRITE pointer */
        XBEE_rxBufferWrite++;
        if(XBEE_rxBufferWrite == XBEE_RX_BUFFER_SIZE) {
            XBEE_rxBufferWrite = 0;
        }
    }
    
    /* Write CHECKSUM byte */
    XBEE_rxBuffer[XBEE_rxBufferWrite] = packet->checksum;
    
    /* Increment WRITE pointer */
    XBEE_rxBufferWrite++;
    if(XBEE_rxBufferWrite == XBEE_RX_BUFFER_SIZE) {
        XBEE_rxBufferWrite = 0;
    }
    
    /* Update TAIL pointer */
    XBEE_rxBufferTail = XBEE_rxBufferWrite;
    
    /* Restore interrupt state */
    *XBEE_RX_INT_INTC_SET_EN |= intState;
    
    /* Set PACKET and clear EMPTY status bit */
    XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_PACKET;
    XBEE_RX_STATUS_REG &= ~XBEE_RX_STATUS_EMPTY;
    
    return XBEE_RECYCLE_OK;
}



#if defined(CY_SCB_XBEE_UART_H)
    
    #warning "SCB ISR not implemented"
CY_ISR(XBEE_RX_ISR) {
    XBEE_UART_SpiUartClearRxBuffer();
    XBEE_UART_ClearRxInterruptSource(0xFFFFFFFF);
}

#elif defined(CY_UART_XBEE_UART_H)
    
/**
* RX Interrupt Service Routine.
* 
*/
CY_ISR(XBEE_RX_ISR) {
    uint8_t readData;

    readData = XBEE_UART_RXSTATUS_REG;

    /* Check for errors reading byte */
    if((readData & (XBEE_UART_RX_STS_PAR_ERROR | XBEE_UART_RX_STS_STOP_ERROR | 
                    XBEE_UART_RX_STS_BREAK | XBEE_UART_RX_STS_OVERRUN)) != 0u)
    {
        /* Set UART ERROR status bit */
        XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_UART_ERROR;
        
        /* Check buffer overrun condition */
        if((readData & XBEE_UART_RX_STS_OVERRUN) != 0u) {
            /* Set OVERFLOW status bit */
            XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_OVERFLOW;
        }
        
        /* Return to IDLE */
        XBEE_rxState = IDLE;
        
        /* Flush UART FIFO */
        while((readData & XBEE_UART_RX_STS_FIFO_NOTEMPTY) != 0u) {
            readData = XBEE_UART_RXDATA_REG;
            readData = XBEE_UART_RXSTATUS_REG;
        }
        
        /* Exit ISR */
        return;
    }
    
    /* Check buffer for space */
    if((XBEE_rxBufferWrite +1) % XBEE_RX_BUFFER_SIZE == XBEE_rxBufferHead) {
        /* Hold data in UART FIFO */
        /* Exit ISR */
        return;
    }
    
    while((readData & XBEE_UART_RX_STS_FIFO_NOTEMPTY) != 0u) {
        /* Read byte from UART */
        readData = XBEE_UART_RXDATA_REG;
        
        /* Packet buffering state machine */
        switch(XBEE_rxState) {
            case IDLE: /* Expecting a 'start delimiter' */
                if(readData == XBEE_PACKET_START) {
                    XBEE_rxBufferWrite = XBEE_rxBufferTail;
                    XBEE_rxState = LENH;
                } else {
                    /* Check again if there is data */
                    readData = XBEE_UART_RXSTATUS_REG;
                    continue;
                }
            break;
            case LENH: /* Byte is MSB of length field */
                XBEE_rxLength = readData << 8;
                XBEE_rxState = LENL;
            break;
            case LENL: /* Byte is LSB of length field */
                XBEE_rxLength |= readData;
                XBEE_rxChecksum = 0xFF;
                XBEE_rxState = PAYLOAD;
            break;
            case PAYLOAD: /* Buffering payload */
                XBEE_rxLength--;
                XBEE_rxChecksum -= readData;
                if(XBEE_rxLength == 0u) {
                    XBEE_rxState = CHECKSUM;
                }
            break;
            case CHECKSUM: /* Byte is packet checksum */
                if(XBEE_rxChecksum == readData) {
                    XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_PACKET;
                    XBEE_rxPacketOK = 1u;
                } else {
                    XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_CHECKSUM_ERROR;
                }
                XBEE_rxState = IDLE;
            break;
            default: /* This shouldn't happen */
                /* Set UART ERROR status bit */
                XBEE_RX_STATUS_REG |= XBEE_RX_STATUS_UART_ERROR;
                
                /* Reset pointer */
                XBEE_rxBufferWrite = XBEE_rxBufferTail;
                
                /* Return to IDLE */
                XBEE_rxState = IDLE;
                
                /* Check again if there is data */
                readData = XBEE_UART_RXSTATUS_REG;
                continue;
            break;
        }
        
        /* Buffer new byte */
        XBEE_rxBuffer[XBEE_rxBufferWrite] = readData;
        
        /* Increment WRITE pointer */
        XBEE_rxBufferWrite++;
        
        /* Check pointer for a loop condition */
        if(XBEE_rxBufferWrite >= XBEE_RX_BUFFER_SIZE) {
            XBEE_rxBufferWrite = 0;
        }
        
        /* Packet received */
        if(XBEE_rxPacketOK == 1u) {
            XBEE_rxPacketOK = 0u;
            XBEE_rxBufferTail = XBEE_rxBufferWrite;
        }
        
        /* Check again if there is data */
        readData = XBEE_UART_RXSTATUS_REG;
    }
}

#else
    #error "UART not defined"
#endif


/* [] END OF FILE */
