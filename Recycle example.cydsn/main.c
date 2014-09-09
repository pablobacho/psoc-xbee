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

#include <project.h>

XBEE_packet_t packet1;
XBEE_packet_t packet2;

int main()
{
    uint8_t frameId = 0;
    uint8_t readPacket;
    
    XBEE_Start();
    UART_Start();
    
    CyGlobalIntEnable;
    
    /* Create a reference packet */
    packet1.length = 2;
    packet1.payload[0] = 0xBE;
    packet1.payload[1] = 0xEF;
    packet1.checksum = (uint8_t) ((0xFF - 0xBE) - 0xEF);
    
    /* Copy it into rxBuffer */
    XBEE_rxBuffer[0] = XBEE_PACKET_START;
    XBEE_rxBuffer[1] = 0;
    XBEE_rxBuffer[2] = packet1.length;
    XBEE_rxBuffer[3] = packet1.payload[0];
    XBEE_rxBuffer[4] = packet1.payload[1];
    XBEE_rxBuffer[5] = packet1.checksum;
    
    /* Set rxBuffer variables */
    XBEE_rxBufferRead = 0;
    XBEE_rxBufferHead = 0;
    XBEE_rxBufferWrite = 6;
    XBEE_rxBufferTail = 6;
    XBEE_RX_STATUS_REG = XBEE_RX_STATUS_PACKET;
        
    for(;;)
    {
        readPacket = XBEE_ReadPacket(&packet2);
        if(readPacket == XBEE_READPACKET_OK) {
            /* Print packet for debugging */
            UART_PutChar(XBEE_PACKET_START);
            UART_PutChar(0);
            UART_PutChar(packet2.length);
            UART_PutArray(packet2.payload, 2);
            UART_PutChar(packet2.checksum);
            
            /* If payload matches, recycle packet */
            if((packet2.payload[0] == packet1.payload[0]) && (packet2.payload[1] == packet1.payload[1])) {
                /* Recycle indefinitely */
                XBEE_RxBufferRecycle(&packet2);
            }
        }
        CyDelay(500);
    }
}

/* [] END OF FILE */
