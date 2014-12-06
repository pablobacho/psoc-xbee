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

XBEE_packet_t packet;
uint8_t np;

int main()
{
    uint8_t frameId = 1;
    uint8_t readPacket;
    
    np = 0;
    
    XBEE_Start();
    UART_Start();
    
    CyGlobalIntEnable;
    
    for(;;)
    {
        XBEE_ATCommand(&packet, frameId++, "MY", NULL, 0);
        UART_PutChar(XBEE_PACKET_START);
        UART_PutChar(packet.length >> 8);
        UART_PutChar(packet.length);
        UART_PutArray((uint8_t *) &(packet.payload), packet.length);
        UART_PutChar(packet.checksum);
            
        /* Check for AT response */
        if((XBEE_ReadRxStatus() & XBEE_RX_STATUS_PACKET) != 0u) {
        
            UART_PutChar('c');
            /* If packet is parsed OK */
            if(XBEE_ReadPacket(&packet) == XBEE_READPACKET_OK) {
                /* Print packet over UART for debug */
                UART_PutChar(XBEE_PACKET_START);
                UART_PutChar(packet.length >> 8);
                UART_PutChar(packet.length);
                UART_PutArray((uint8_t *) &(packet.payload), packet.length);
                UART_PutChar(packet.checksum);
            }
        }
                
        CyDelay(500);
            
    }
}

/* [] END OF FILE */
