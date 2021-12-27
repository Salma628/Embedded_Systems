/*
 * Timer1_Reg.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_TIMER1_TIMER1_REG_H_
#define MCAL_TIMER1_TIMER1_REG_H_

#define TCCR1A  (*(volatile uint8 *) 0x4F)
#define TCCR1B  (*(volatile uint8 *) 0x5E)
#define TIFR    (*(volatile uint8 *) 0x58)
#define TCNT1H  (*(volatile uint8 *) 0x4D)
#define TCNT1L  (*(volatile uint8 *) 0x4C)
#define OCR1AH  (*(volatile uint8 *) 0x4B)
#define OCR1AL  (*(volatile uint8 *) 0x4A)
#define OCR1BH  (*(volatile uint8 *) 0x49)
#define OCR1BL  (*(volatile uint8 *) 0x48)
#define ICR1H   (*(volatile uint8 *) 0x47)
#define ICR1L   (*(volatile uint8 *) 0x46)

#endif /* MCAL_TIMER1_TIMER1_REG_H_ */
