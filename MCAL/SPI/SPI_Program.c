/*
 * SPI_Program.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Masria For PCs
 */


#include "../../LIB/calc_bits.h"
#include "../../LIB/types.h"
#include "SPI_Interface.h"
#include "SPI_Reg.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/External_Interrupt/External_Interrupt_Reg.h"


static SPI_CONFIG SPI_STR ={SPI_ENA_INT,ENA_SPI ,ORDER_MSB ,MASTER_MODE ,BASE_0_FIRST_EDGE ,FOSC_128 };


void SPI_Init ()
{
	if (SPI_STR.mode == MASTER_MODE)
	{
		DIO_vSetPinDirection(PORT_B , MOSI , OUTPUT);
		DIO_vSetPinDirection(PORT_B ,SCK , OUTPUT);
		DIO_vSetPinDirection(PORT_B , SS , OUTPUT);
		DIO_vSetPinDirection(PORT_B , MISO , INPUTWOPULLUP);
		DIO_vWritePinValue(PORT_B ,SS ,LOW); // ACTIVE LOW
		set_bit(SPCR,MSTR);
	}
	else
	{
		DIO_vSetPinDirection(PORT_B , MISO , INPUTWOPULLUP);
		DIO_vSetPinDirection(PORT_B , MISO , OUTPUT);
		DIO_vSetPinDirection(PORT_B ,SCK , INPUTWOPULLUP);
		DIO_vSetPinDirection(PORT_B , SS , INPUTWOPULLUP);
		clear_bit(SPCR,MSTR);
	}

	if (SPI_STR.ENA_INT== SPI_ENA_INT )
	{
		set_bit(SREG,7);
		set_bit(SPCR, SPIE);
	}
	else
	{
		clear_bit(SPCR,SPIE);
	}

	if (SPI_STR.EN_SPI == ENA_SPI)
	{
		set_bit(SPCR,SPE);
	}
	else
	{
		clear_bit(SPCR,SPE);
	}

	if (SPI_STR.ORDER_TRANSMITTING==ORDER_LSB)
	{
		set_bit(SPCR,DORD);
	}
	else
	{
		clear_bit(SPCR,DORD);
	}


	if (SPI_STR.cpol_cpha==BASE_0_FIRST_EDGE)
	{
		clear_bit(SPCR,CPOL);
		clear_bit(SPCR,CPHA);
	}
	else if (SPI_STR.cpol_cpha==BASE_0_SECOND_EDGE)
	{
		clear_bit(SPCR,CPOL);
		set_bit(SPCR,CPHA);
	}
	else if (SPI_STR.cpol_cpha==BASE_1_FIRST_EDGE)
	{
		set_bit(SPCR,CPOL);
		clear_bit(SPCR,CPHA);
	}
	else
	{
		set_bit(SPCR,CPOL);
		set_bit(SPCR,CPHA);
	}

	if (SPI_STR.speed == FOSC_128)
	{
		set_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
	}
	else if (SPI_STR.speed==FOSC_64)
	{
		clear_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
	}
	else if (SPI_STR.speed==FOSC_32)
	{
		clear_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
	}

}


void SPI_TransmitData (uint8 character)
{
	while (get_bit(SPSR,SPIF)!=1);
	SPDR=character;

}


uint8 SPI_ReceivetData ()
{
	uint8 data =0 ;
	while  (get_bit(SPCR,SPIF) != 1) ;
	data=SPDR;
	return data ;
}
