/*
 * ADC_Reg.h
 *
 *  Created on: Sep 11, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_


#define ADMUX    (*(volatile uint8 *) 0x27)
#define ADCSRA   (*(volatile uint8 *) 0x26)
#define ADCH     (*(volatile uint8 *) 0x25)
#define ADCL     (*(volatile uint8 *) 0x24)


#endif /* MCAL_ADC_ADC_REG_H_ */
