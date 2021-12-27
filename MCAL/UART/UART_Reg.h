/*
 * UART_Reg.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_


#define UDR    (*(volatile uint8 *) 0x2C)
#define UCSRA  (*(volatile uint8 *) 0x2B)
#define UCSRB  (*(volatile uint8 *) 0x2A)
#define UCSRC  (*(volatile uint8 *) 0x40)
#define UBRRL  (*(volatile uint8 *) 0x29)
#define UBRRH  (*(volatile uint8 *) 0x40)



#endif /* MCAL_UART_UART_REG_H_ */
