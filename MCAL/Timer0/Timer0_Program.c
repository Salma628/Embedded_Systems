/*
 * Timer0_Program.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Masria For PCs
 */
#include "Timer0_Interface.h"
#include "Timer0_Reg.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/interrupt.h>
#include "../../LIB/calc_bits.h"
#include "../../LIB/types.h"

volatile uint16 Timer_Ticks =0;
volatile uint16 time_reached =0;
static Timer0_str Configuration_Timer0_str = {CTC_MODE, ENABLE_INTERRUPT_CTC, PRESCALER_64 };

void Timer0_Init ()
{

	DIO_vSetPinDirection(PORT_B,0,INPUTWOPULLUP);
}




void Timer0_SetConfig ()
{
	if (Configuration_Timer0_str.Mode == NORMAL_MODE)
	{
		clear_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);
	}
	else if (Configuration_Timer0_str.Mode == CTC_MODE)
	{
		//CTC MODE
		OCR0 = NUMBER_OF_TICKS_249 ;  //1000 MICROSECOND +1 TO CLEAR
		clear_bit(TCCR0,WGM00);
		set_bit  (TCCR0,WGM01);
	}


	if (Configuration_Timer0_str.Enable_Interrupt == ENABLE_INTERRUPT_NORMAL)
	{
		set_bit  (SREG,7);
		set_bit  (TIMSK,TOIE0);
	}
	else if  (Configuration_Timer0_str.Enable_Interrupt == ENABLE_INTERRUPT_CTC)
	{
		set_bit  (TIMSK,OCIE0);
		set_bit  (SREG,7);

	}






	if (Configuration_Timer0_str.prescaler == NO_PRESCALER )
	{
		set_bit  (TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS02);

	}
	else if (Configuration_Timer0_str.prescaler == PRESCALER_8)
	{
		clear_bit(TCCR0,CS00);
		set_bit  (TCCR0,CS01);
		clear_bit(TCCR0,CS02);

	}
	else if (Configuration_Timer0_str.prescaler == PRESCALER_64)
	{
		set_bit  (TCCR0,CS00);
		set_bit  (TCCR0,CS01);
		clear_bit(TCCR0,CS02);

	}
	else if (Configuration_Timer0_str.prescaler == PRESCALER_256)
	{
		clear_bit(TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		set_bit  (TCCR0,CS02);

	}
	else if (Configuration_Timer0_str.prescaler == PRESCALER_1024)
	{
		set_bit  (TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		set_bit  (TCCR0,CS02);

	}
	else if (Configuration_Timer0_str.prescaler == EXTERNAL_SOURCE_FALLING_EDGE)
	{
		clear_bit(TCCR0,CS00);
		set_bit  (TCCR0,CS01);
		set_bit  (TCCR0,CS02);
	}
	else if (Configuration_Timer0_str.prescaler == EXTERNAL_SOURCE_RISING_EDGE)
	{
		set_bit  (TCCR0,CS00);
		set_bit  (TCCR0,CS01);
		set_bit  (TCCR0,CS02);
	}
	else
	{
		clear_bit(TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS02);
	}

}



void TIMER0_Delay_With_Blocking (uint16 Milli_Seconds)
{
	if (Configuration_Timer0_str.Mode == NORMAL_MODE)
	{
		clear_bit  (TIMSK,TOIE0);
	}






	/********************************************/
	static uint16 ticks=0;
	if (Configuration_Timer0_str.Mode == CTC_MODE)
	{
		clear_bit  (TIMSK,OCIE0);
		while (ticks != Milli_Seconds)
		{
			while (get_bit(TIFR,OCF0)==0);
			set_bit  (TIFR , OCF0);
			ticks ++;
		}
		set_bit(TIMSK,OCIE0);
		ticks =0;
	}
}



ISR (TIMER0_COMP_vect)
{
	Timer_Ticks ++ ;
}
