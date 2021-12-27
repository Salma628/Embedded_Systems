/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_
#include "../../LIB/types.h"


/***********************  APIS  *****************************/
void Timer0_Init ();
void Timer0_SetConfig ();
void TIMER0_Delay_With_Blocking (uint16 Milli_Seconds);    //block system
//void TIMER_Delay_Without_Blocking (uint16 Milli_Seconds);



/************************ STRUCT  *************************/
typedef struct
{
	uint8 Mode;
	uint8 Enable_Interrupt;
	uint16 prescaler ;

}Timer0_str;


/*************************************************************/

#define PIN_T0 0


/**************************** MODES *************************/
#define NORMAL_MODE 0
#define CTC_MODE 1


#define ENABLE_INTERRUPT_CTC 0
#define ENABLE_INTERRUPT_NORMAL 1
#define DISABLE_INTERRUPT 2

#define NO_PRESCALER 0
#define PRESCALER_8 1
#define PRESCALER_64 2
#define PRESCALER_256 3
#define PRESCALER_1024 4

#define EXTERNAL_SOURCE_FALLING_EDGE 5
#define EXTERNAL_SOURCE_RISING_EDGE 6
#define STOP_TIMER 7



/***********************  PINS  *****************************/

//REG TCCR0
//WAVE FORM GENERATION
#define WGM00 6
#define WGM01 3

//SELECTION LINE OF MUX OF PRESCALER
#define CS00 0
#define CS01 1
#define CS02 2

//REG TIFR
#define TOV0 0
#define OCF0 1

//REG TIMSK
#define TOIE0 0   //ENABLE INTERRUPT OF OVER FLOW //NORMAL
#define TCIE0 1   //ENABLE INTERRUPT OF OVER FLOW //CTC
/******************* TIME DELAY ************************/
#define FREQ_CPU 16000000



#define NUMBER_OF_TICKS_249  249

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
