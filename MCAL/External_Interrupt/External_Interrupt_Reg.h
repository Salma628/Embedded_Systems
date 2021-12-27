/*
 * External_Interrupt_Reg.h
 *
 *  Created on: Aug 28, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REG_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REG_H_


#define SREG (*(volatile uint8 *) 0x5F)
#define GICR (*(volatile uint8 *) 0x5B)
#define GIFR (*(volatile uint8 *) 0x5A)
#define MCUCR (*(volatile uint8 *) 0x55)
#define MCUCSR (*(volatile uint8 *) 0x54)

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REG_H_ */
