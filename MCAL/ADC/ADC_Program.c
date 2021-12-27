/*
 * ADC_Program.c
 *
 *  Created on: Sep 11, 2019
 *      Author: Masria For PCs
 */

#include "ADC_Interface.h"
#include "ADC_Reg.h"
#include "../../MCAL/External_Interrupt/External_Interrupt_Reg.h"
#include "../../LIB/calc_bits.h"
#include "../../LIB/types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/interrupt.h>

static ADC_CONFIG ADC_Str = {Channel0 , Enable_ADC , PRESCALER1_128 , Disable_Interrupt , Internal_voltage };


void ADC_Init ()
{
	DIO_vSetPinDirection(PORT_A ,0, INPUTWOPULLUP);
	set_bit(ADCSRA,ADEN);
}


/*------------------------------------------------------------------------------------------------------------------------------------------------*/
void ADC_Config ()
{
	if(ADC_Str.Channel == Channel0)
	{
		DIO_vSetPinDirection(PORT_A ,Channel0 , INPUTWOPULLUP);
		clear_bit(ADMUX,MUX0);
		clear_bit(ADMUX,MUX1);
		clear_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else if (ADC_Str.Channel==Channel1)
	{
		DIO_vSetPinDirection(PORT_A ,Channel1 , INPUTWOPULLUP);
		set_bit(ADMUX,MUX0);
		clear_bit(ADMUX,MUX1);
		clear_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else if (ADC_Str.Channel==Channel2)
	{
		DIO_vSetPinDirection(PORT_A ,Channel2 , INPUTWOPULLUP);
		clear_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		clear_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else if (ADC_Str.Channel==Channel3)
	{
		DIO_vSetPinDirection(PORT_A ,Channel3 , INPUTWOPULLUP);
		set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		clear_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else if (ADC_Str.Channel==Channel4)
	{
		DIO_vSetPinDirection(PORT_A ,Channel4 , INPUTWOPULLUP);
		clear_bit(ADMUX,MUX0);
		clear_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else if (ADC_Str.Channel==Channel5)
	{
		DIO_vSetPinDirection(PORT_A ,Channel5 , INPUTWOPULLUP);
		set_bit(ADMUX,MUX0);
		clear_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else if (ADC_Str.Channel==Channel6)
	{
		DIO_vSetPinDirection(PORT_A ,Channel6 , INPUTWOPULLUP);
		clear_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}
	else
	{
		DIO_vSetPinDirection(PORT_A ,Channel7 , INPUTWOPULLUP);
		set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);
		clear_bit(ADMUX,MUX3);
		clear_bit(ADMUX,MUX4);
	}


	if (ADC_Str.ADC_Enable == Enable_ADC)
	{
		set_bit(ADCSRA,ADEN);
	}
	else
	{
		clear_bit(ADCSRA,ADEN);
	}


	if (ADC_Str.prescaler == PRESCALER1_2)
	{
		set_bit(ADCSRA, ADPS0);
		clear_bit(ADCSRA, ADPS1);
		clear_bit(ADCSRA, ADPS2);
	}

	else if (ADC_Str.prescaler == PRESCALER1_4)
	{
		clear_bit(ADCSRA, ADPS0);
		set_bit(ADCSRA, ADPS1);
		clear_bit(ADCSRA, ADPS2);
	}

	else if (ADC_Str.prescaler == PRESCALER1_8)
	{
		set_bit(ADCSRA, ADPS0);
		set_bit(ADCSRA, ADPS1);
		clear_bit(ADCSRA, ADPS2);
	}

	else if (ADC_Str.prescaler == PRESCALER1_16)
	{
		clear_bit(ADCSRA, ADPS0);
		clear_bit(ADCSRA, ADPS1);
		set_bit(ADCSRA, ADPS2);
	}

	else if (ADC_Str.prescaler == PRESCALER1_32)
	{
		set_bit(ADCSRA, ADPS0);
		clear_bit(ADCSRA, ADPS1);
		set_bit(ADCSRA, ADPS2);
	}

	else if (ADC_Str.prescaler == PRESCALER1_64)
	{
		clear_bit(ADCSRA, ADPS0);
		set_bit(ADCSRA, ADPS1);
		set_bit(ADCSRA, ADPS2);
	}

	else
	{
		set_bit(ADCSRA, ADPS0);
		set_bit(ADCSRA, ADPS1);
		set_bit(ADCSRA, ADPS2);
	}


	if (ADC_Str.Interrupt==Enable_Interrupt)
	{
		set_bit(SREG,7);
		set_bit(ADCSRA, ADIE);
	}
	else
	{
		clear_bit(ADCSRA, ADIE);
	}



	if (ADC_Str.Voltage_reference == AVREF)
	{
		DIO_vSetPinDirection(PORT_A ,AVREF_PIN,INPUTWOPULLUP);
		clear_bit(ADMUX ,REFS0);
		clear_bit(ADMUX ,REFS1);
	}

	else if (ADC_Str.Voltage_reference == AVCC)
	{
		DIO_vSetPinDirection(PORT_A, AVCC , INPUTWOPULLUP);
		set_bit(ADMUX ,REFS0);
		clear_bit(ADMUX ,REFS1);
	}

	else
	{
		set_bit(ADMUX ,REFS0);
		set_bit(ADMUX ,REFS1);
	}

}

void ADC_StartConversion ()
{
	//clear flag bu putting 1
	set_bit(ADCSRA ,ADSC);   //start conversion
}


uint16 ADC_GetConvertedValue ()
{
	//right adjustified
	clear_bit(ADMUX ,ADLAR);
	set_bit(ADCSRA , ADIF);
	set_bit(ADCSRA ,ADSC);   //start conversion
	while (get_bit(ADCSRA ,ADIF) != 1);
	set_bit(ADCSRA , ADIF);
	//making 2 ports as output
	//DIO_vSetPortDirection(PORT_C , OUTPUT);
	//DIO_vSetPortDirection(PORT_D , OUTPUT);
	//PORTC = ADCL;
	//PORTD = ADCH;

	uint16 low=0;
	uint16 high=0;
	uint16 res=0;

	low =ADCL & 0x00ff ;
	high= ADCH  & 0x0300 ;
	res = low | ( high << 0x08 ) ;
	return res;

}
