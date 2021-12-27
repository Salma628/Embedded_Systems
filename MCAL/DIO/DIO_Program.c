/*
 * DIO_Program.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Masria For PCs
 */

#include "../../LIB/types.h"
#include "../../LIB/calc_bits.h"
#include "DIO_Reg.h"
#include "DIO_Interface.h"

void  DIO_vSetPortDirection  (uint8 Name_Port ,uint8 State_Port)
{
	switch (Name_Port)
	{
	case PORT_A:
		switch (State_Port)
		{
		case OUTPUT:
			PORTA=ALLHIGH;
			break;
		case INPUTWPULLUP:
			PORTA=ALLHIGH;
			PORTA=ALLLOW;
			break;
		case INPUTWOPULLUP:
			PORTA=ALLLOW;
			break;
		}
		break;
	case PORT_B:
		switch (State_Port)
		{
		case OUTPUT:
			PORTB=ALLHIGH;
			break;
		case INPUTWPULLUP:
			PORTB=ALLHIGH;
			PORTB=ALLLOW;
			break;
		case INPUTWOPULLUP:
			PORTB=ALLLOW;
			break;
		}
		break;
	case PORT_C:
		switch (State_Port)
		{
		case OUTPUT:
			PORTC=ALLHIGH;
			break;
		case INPUTWPULLUP:
			PORTC=ALLHIGH;
			PORTC=ALLLOW;
			break;
		case INPUTWOPULLUP:
			PORTC=ALLLOW;
			break;
		}
		break;
	case PORT_D:
		switch (State_Port)
		{
		case OUTPUT:
			PORTD=ALLHIGH;
			break;
		case INPUTWPULLUP:
			PORTD=ALLHIGH;
			PORTD=ALLLOW;
			break;
		case INPUTWOPULLUP:
			PORTD=ALLLOW;
			break;
		}
		break;
	}
}
void  DIO_vWritePortValue    (uint8 Name_Port , uint8 Case_Port)
{
	switch (Name_Port)
	{
	case PORT_A:
		PORTA=Case_Port;
		break;
	case PORT_B:
		PORTB=Case_Port;
		break;
	case PORT_C:
		PORTC=Case_Port;
		break;
	case PORT_D:
		PORTD=Case_Port;
		break;
	}
}
uint8 DIO_uReadPortDirection (uint8 Name_Port)
{
	uint8 res=0;
	switch(Name_Port)
	{
	case PORT_A:
		res=PINA;
		break;
	case PORT_B:
		res=PINB;
		break;
	case PORT_C:
		res=PINC;
		break;
	case PORT_D:
		res=PIND;
		break;
	}
	return res;
}
void  DIO_vSetPinDirection   (uint8 Name_Port ,uint8 Pin_Num ,uint8 State_Pin )
{
	switch (Name_Port)
	{
	case PORT_A:
		switch(State_Pin)
		{
		case OUTPUT:
			set_bit(DDRA , Pin_Num);  // REG DDRA
			break;
		case INPUTWPULLUP:
			clear_bit(DDRA , Pin_Num);
			set_bit(PORTA , Pin_Num);
			break ;
		case INPUTWOPULLUP:
			clear_bit(DDRA , Pin_Num);

		}
		break ;
	case PORT_B:
		switch(State_Pin)
		{
		case OUTPUT:
			set_bit(DDRB , Pin_Num);
			break;
		case INPUTWPULLUP:
			clear_bit(DDRB , Pin_Num);
			set_bit(PORTB , Pin_Num);
			break ;
		case INPUTWOPULLUP:
			clear_bit(DDRB , Pin_Num);
			break;
		}
		break ;
	case PORT_C:
		switch(State_Pin)
		{
		case OUTPUT:
			set_bit(DDRC , Pin_Num);
			break;
		case INPUTWPULLUP:
			clear_bit(DDRC , Pin_Num);
			set_bit(PORTC , Pin_Num);
			break ;
		case INPUTWOPULLUP:
			clear_bit(DDRC , Pin_Num);
			break;
		}
		break ;
	case PORT_D:
		switch(State_Pin)
		{
		case OUTPUT:
			set_bit(DDRD , Pin_Num);
			break;
		case INPUTWPULLUP:
			clear_bit(DDRD , Pin_Num);
			set_bit(PORTD , Pin_Num);
			break ;
		case INPUTWOPULLUP:
			clear_bit(DDRD , Pin_Num);
			break;
		}
		break ;

	}
}
void  DIO_vWritePinValue     (uint8 Name_Port ,uint8 Pin_Num ,uint8 Value_Pin)
{
	switch (Name_Port)
	{
	case PORT_A:
		switch (Value_Pin)
		{
		case HIGH:
			set_bit(PORTA , Pin_Num);
			break;
		case LOW:
			clear_bit(PORTA , Pin_Num);
			break;
		}
		break;
	case PORT_B:
		switch (Value_Pin)
		{
		case HIGH:
			set_bit(PORTB , Pin_Num);
			break;
		case LOW:
			clear_bit(PORTB , Pin_Num);
			break;
		}
		break;
	case PORT_C:
		switch (Value_Pin)
		{
		case HIGH:
			set_bit(PORTC , Pin_Num);
			break;
		case LOW:
			clear_bit(PORTC , Pin_Num);
			break;
		}
		break;
	case PORT_D:
		switch (Value_Pin)
		{
		case HIGH:
			set_bit(PORTD , Pin_Num);
			break;
		case LOW:
			clear_bit(PORTD , Pin_Num);
			break;
		}
		break;
	}
}
uint8 DIO_uReadPinDirection  (uint8 Name_Port ,uint8 Pin_Num)
{
	uint8 bit=0;
	switch (Name_Port)
	{
	case PORT_A:
		bit=get_bit(PINA,Pin_Num);
		break;
	case PORT_B:
			bit=get_bit(PINB,Pin_Num);
			break;
	case PORT_C:
			bit=get_bit(PINC,Pin_Num);
			break;
	case PORT_D:
			bit=get_bit(PIND,Pin_Num);
			break;
	}
	return bit;
}
void  DIO_vTogglePin         (uint8 Name_Port , uint8 Pin_Num)
{
	switch (Name_Port)
	{
	case PORT_A:
		toggle_bit(PORTA,Pin_Num);
		break;
	case PORT_B:
			toggle_bit(PORTB,Pin_Num);
			break;
	case PORT_C:
			toggle_bit(PORTC,Pin_Num);
			break;
	case PORT_D:
			toggle_bit(PORTD,Pin_Num);
			break;

	}

}
