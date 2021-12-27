/*
 * Timer0_Reg.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_TIMER0_TIMER0_REG_H_
#define MCAL_TIMER0_TIMER0_REG_H_


/*********************** TIMER 0  **************************/


#define SREG   (*(volatile uint8 *) 0x5F)
#define OCR0   (*(volatile uint8 *) 0x5C)
#define TCCR0  (*(volatile uint8 *) 0x53)
#define TCNT0  (*(volatile uint8 *) 0x52)
#define TIFR   (*(volatile uint8 *) 0x58)
#define TIMSK  (*(volatile uint8 *) 0x59)




#endif /* MCAL_TIMER0_TIMER0_REG_H_ */
