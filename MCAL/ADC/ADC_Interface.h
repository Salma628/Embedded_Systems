/*
 * ADC_Interface.h
 *
 *  Created on: Sep 11, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../LIB/types.h"
/*************************** REGISTER *******************************/
// REG ADMUX

//CHANNEL
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
//ADC LEFT & RIGHT
#define ADLAR 5

#define Left_justified  1
#define Right_justified 0

//REFERENCE SELECTION
#define REFS0 6
#define REFS1 7

/*********************************************************************/

//REG ADCSRA

#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2


/**********************************************************************/

typedef struct
{
	uint8 Channel ;
	uint8 ADC_Enable ;
	uint8 prescaler ;
	uint8 Interrupt ;
	uint8 Voltage_reference;
	uint8 mode;


}ADC_CONFIG ;

/**********************************************************************/

/*********************************************************************/


// mode
#define TEN_BIT_MODE   1
#define EIGHT_BIT_MODE 2
//7 BITS ADC PRESCALER

#define PRESCALER1_2   1
#define PRESCALER1_4   2
#define PRESCALER1_8   3
#define PRESCALER1_16  4
#define PRESCALER1_32  5
#define PRESCALER1_64  6
#define PRESCALER1_128 7
/*********************************************************************/

#define Enable_ADC  1
#define Disable_ADC 2

#define Enable_Interrupt  1
#define Disable_Interrupt 2

/*********************************************************************/
#define Channel0 0
#define Channel1 1
#define Channel2 2
#define Channel3 3
#define Channel4 4
#define Channel5 5
#define Channel6 6
#define Channel7 7


/*********************************************************************/

#define AVREF            1
#define AVCC             2
#define Internal_voltage 3


#define AVCC_PIN  30
#define AVREF_PIN 32  //External fixed voltage
/***************************** APIS **********************************/

extern void ADC_Init ();
extern void ADC_Config ();
extern void ADC_StartConversion ();
extern uint16 ADC_GetConvertedValue ();


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
