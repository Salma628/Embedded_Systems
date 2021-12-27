/*
 * UART_Program.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Masria For PCs
 */

#include "UART_Reg.h"
#include "UART_Interface.h"
#include "../../LIB/types.h"
#include "../../LIB/calc_bits.h"
#include "../../MCAL/DIO/DIO_Interface.h"






static UART_CONFIG UART_Str = { ASYNCHRONOUS , DISABLED ,STOP_1BIT , BITS_8 };

 void UART_Init ()
 {



	 UBRRL = Buad_Rate ;
	 //using ucsrc register
	 set_bit(UCSRC ,URSEL);


	 if (UART_Str.MODE_SELECT == ASYNCHRONOUS)
	 {
		 set_bit(UCSRC ,URSEL);
		 clear_bit(UCSRC , UMSEL);
	 }
	 else
	 {
		 set_bit(UCSRC ,URSEL);
		 set_bit(UCSRC , UMSEL);
	 }

	 if ( UART_Str.PARITY_MODE== DISABLED)
	 {
		 set_bit(UCSRC ,URSEL);
		 clear_bit(UCSRC,UPM0);
		 clear_bit(UCSRC,UPM1);
	 }
	 else if (UART_Str.PARITY_MODE == EVEN_PARITY)
	 {
		 set_bit(UCSRC ,URSEL);
		 set_bit(UCSRC,UPM1);
		 clear_bit(UCSRC, UPM0);
	 }
	 else
	 {
		 //set_bit(UCSRC ,URSEL);
		 set_bit(UCSRC ,URSEL);
		 set_bit(UCSRC,UPM0);
		 set_bit(UCSRC,UPM1);
	 }


	 if (UART_Str.STOP_SELECT == STOP_1BIT)
	 {
		 set_bit(UCSRC ,URSEL);
		 clear_bit(UCSRC ,USBS);
	 }
	 else
	 {
		 set_bit(UCSRC ,URSEL);
		 set_bit(UCSRC , USBS);
	 }


	 if (UART_Str.CHAR_SIZE==BITS_7)
	 {
		 set_bit(UCSRC ,URSEL);
		 clear_bit(UCSRC ,UCSZ0);
		 set_bit(UCSRC , UCSZ1);
		 clear_bit(UCSRB ,UCSZ2);
	 }
	 else
	 {
		 //in case 8_bits
		 set_bit(UCSRC ,URSEL);
		 set_bit(UCSRC , UCSZ0);
		 set_bit(UCSRC , UCSZ1);
		 clear_bit(UCSRB ,UCSZ2);
	 }

	 //DISABLE INTERRUPT TRANSMITTER AND RECIEVER
	 set_bit(UCSRB,RXEN);
	 	set_bit(UCSRB,TXEN);
 }


 void UART_TransmitData (uint8 character)
 {

	 while (get_bit(UCSRA,UDRE) != 1);
	 UDR = character ;
 }


uint8 UART_ReceivetData ()
{
	uint8 data =0 ;
	while  (get_bit(UCSRA , RXC) != 1) ;
	data=UDR;
	return data ;
}
