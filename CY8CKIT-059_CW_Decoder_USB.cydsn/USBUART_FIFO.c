/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "USBUART_FIFO.h"

// USBUART packet size
#define     UART_TX_QUEUE_SIZE      (64)
#define     UART_RX_QUEUE_SIZE      (64)

// USBUART Tx queue buffer
uint8       uartTxQueue[UART_TX_QUEUE_SIZE];    // Tx queue
uint8       uartTxCount = 0;                    // Data count in the Tx queue
CYBIT       uartZlpRequired = 0;                // Zero Length Packet(ZLP) request flag
uint8       uartTxReject = 0;                   // Number of Tx is rejected

// USBUART Rx queue buffer
uint8       uartRxQueue[UART_RX_QUEUE_SIZE];    // Rx queue
uint8       uartRxCount = 0;                    // Data count in the Rx queue
uint8       uartRxIndex = 0;                    // Index number of the Rx queue
CYBIT       uartRxCRDetect = 0;                 // CR detection flag

//
// Send 1 byte
//
static void putch_sub(const int16 ch) 
{
    uint8 state;
    
    for (;;) 
    {
        // Wait for Tx queue is empty.
        state = CyEnterCriticalSection();
        if (uartTxCount < UART_TX_QUEUE_SIZE) break;
        CyExitCriticalSection(state);
    }
    // Put 1 character to the Tx queue.
    uartTxQueue[uartTxCount++] = ch;
    CyExitCriticalSection(state);
}

//
// Tx ISR
//
void uartTxIsr(void)
{
    uint8 state = CyEnterCriticalSection();
    
    if ((uartTxCount > 0) || uartZlpRequired)
    {
        // If there is data in the Tx buffer or ZLP is required, then send the packet.
        if (USBUART_CDCIsReady())
        {
            // Send the packet
            USBUART_PutData(uartTxQueue, uartTxCount);
            // Tx buffer clear
            uartZlpRequired = (uartTxCount == UART_TX_QUEUE_SIZE);
            uartTxCount = 0;
            uartTxReject = 0;
        }
        else if (++uartTxReject > 4)
        {
            // Dispose the data.
            uartTxCount = 0;
            uartTxReject = 0;
        }
        else
        {
            // Nothing to do in this interruption.
        }
    }
    CyExitCriticalSection(state);
}

//
// Send one caracter to USBUART
//
void putch(const uint8 ch)
{
    if (ch == '\n')
    {
        // Convert 'LF' to 'CR+LF'
        putch_sub('\r');
    }
    putch_sub(ch);
}

//
// Send the string to USBUART
//
void putstr(const char *s)
{
    // Display one line.
    while (*s)
        putch(*s++);
}

//
// Rx ISR
//
void uartRxIsr(void)
{
    uint8 state = CyEnterCriticalSection();

    // Rx buffer is empty
    if (uartRxIndex >= uartRxCount)
    {
        // Is there any data received?
        if (USBUART_DataIsReady())
        {
            // Get the Rx data to Rx buffer
            uartRxCount = USBUART_GetAll(uartRxQueue);
            uartRxIndex = 0;
        }
    }
    CyExitCriticalSection(state);
}

//
// Get one byte
//
uint8 getch_sub(void)
{
    uint8 ch = -1;
    
    uint8 state = CyEnterCriticalSection();
    
    // Is there any data in the Rx buffer?
    if (uartRxIndex < uartRxCount)
    {
        // If so, then get one character.
        ch = uartRxQueue[uartRxIndex++];
    }
    CyExitCriticalSection(state);
    return ch;
}

//
// Receive one character from USBUART
//
uint8 getch(void)
{
    uint8 ch = getch_sub();
    
    if (uartRxCRDetect && ch == '\n')
    {
        uartRxCRDetect = 0;
        ch = getch_sub();
    }
    else if (ch == '\r')
    {
        ch = '\n';
        uartRxCRDetect = 1;
    }
    return ch;
}

#if 0
// ISR of int_uartQueue(2kHz clock) interrupt.
CY_ISR(int_uartQueue_isr)
{
    uartTxIsr();
    uartRxIsr();
}

int main(void)
{
    uint32 nLine = 0;           // Line number
    uint32 nChars = 0;          // Number of characters
    
    CyGlobalIntEnable;  
    //USBUART_Start(0, USBUART_5V_OPERATION);
    USBUART_Start(0, USBUART_DWR_VDDD_OPERATION);

    int_uartQueue_StartEx(int_uartQueue_isr);   // start 2kHz timer interrupt

    for(;;)
    {
        // Wait until the intialization is done.
        while (USBUART_GetConfiguration() == 0);

        USBUART_IsConfigurationChanged();       // Clear CHANGE flag
        USBUART_CDC_Init();                     // Start CDC function
        
        for (;;)
        {
            // If the confoguration is changed, then initialize USB again.
            if (USBUART_IsConfigurationChanged())
                break;

            // Send the number of Rx character.
            int16 ch = getch();
            if (ch >= 0)
            {
                nChars++;
                if (ch == '\n') 
                {
                    putdec32(nLine, 7);
                    putstr(" - ");
                    putdec32(nChars, 7);
                    putstr("\n");
                    nLine++;
                    nChars = 0;
                }
            }
            
            // Ignore the control comands
            (void)USBUART_IsLineChanged();
        }
    }
}
#endif

/* [] END OF FILE */
