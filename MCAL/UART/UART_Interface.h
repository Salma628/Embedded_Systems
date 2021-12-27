/*
 * UART_Interface.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
#include "../../LIB/types.h"


/*#define Enable_USART_TXEN  0x08
#define Enable_USART_RXEN  0x10
*/

#define Buad_Rate 0x67

#define UDRE 5
//#define Ready_To_Receive 0x20
#define RXC 7
//#define Data_not_read_yet  0x80

#define Rx 0
#define Tx 1

#define UDRIE  5


#define RXEN 4
#define TXEN 3

/******************* REG UCSRC *******************/

#define UCSZ0 1
#define UCSZ1 2
#define UCSZ2 2
#define USBS  3
#define UPM0  4
#define UPM1  5
#define UMSEL 6
#define URSEL 7


/***************** MODES ************************/
#define ENABLE_UCSRC 1
#define ENABLE_UBRRH 2

#define ASYNCHRONOUS 1
#define SUNCHRONOUS  2

#define DISABLED 1
#define EVEN_PARITY 2
#define ODD_PARITY 3

#define STOP_1BIT 1
#define STOP_2BITS 2

#define BITS_7 1
#define BITS_8 2




/******************* STRUCT *******************/

typedef struct
{
	uint8 MODE_SELECT;
	uint8 PARITY_MODE;
	uint8 STOP_SELECT;
	uint8 CHAR_SIZE ;


}UART_CONFIG ;



/******************** APIS *******************/
extern void UART_Init ();
extern void UART_TransmitData (uint8 character);
extern uint8 UART_ReceivetData ();

#endif /* MCAL_UART_UART_INTERFACE_H_ */
