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
uint8_t payload[] = "HOLA";

int main()
{
    uint8_t frameId = 0;
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    XBEE_Start();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        XBEE_ZigBeeTransmitRequest(&packet, frameId++, XBEE_BROADCAST_HW_ADDRESS, XBEE_BROADCAST_NWK_ADDRESS, 0, 0, payload, 4);
        CyDelay(3000);
    }
}

/* [] END OF FILE */
