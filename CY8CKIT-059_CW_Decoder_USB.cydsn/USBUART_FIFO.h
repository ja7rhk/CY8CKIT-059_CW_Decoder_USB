#ifndef __USBUART_FIFO_H__
#define __USBUART_FIFO_H__

#include <device.h>
    
//
// Tx ISR
//
void uartTxIsr(void);

//
// Send one caracter to USBUART
//
void putch(const uint8 ch);

//
// Send the string to USBUART
//
void putstr(const char *s);

//
// Rx ISR
//
void uartRxIsr(void);

//
// Receive one character from USBUART
//
uint8 getch(void);

#endif	/* __USBUART_FIFO_H__ */
