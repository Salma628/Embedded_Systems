/*
 * SPI_Interface.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "../../LIB/types.h"

/********** SPSR PINS *************/
#define SPIF  7
#define WCOL  6
#define SPI2X 0

/*********** SPCR PINS ************/
#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

/************ MODES ***************/
#define SPI_ENA_INT 1
#define SPI_DIS_INT 2

#define ENA_SPI 1
#define DIS_INT 2

#define ORDER_MSB 1
#define ORDER_LSB 2

#define MASTER_MODE 1
#define SLAVE_MODE  2

#define BASE_0_FIRST_EDGE 1
#define BASE_1_FIRST_EDGE 2
#define BASE_0_SECOND_EDGE 3
#define BASE_1_SECOND_EDGE 4

#define FOSC_4   1
#define FOSC_16  2
#define FOSC_64  3
#define FOSC_128 4
#define FOSC_8   5
#define FOSC_32   6


/************************************/


/**************** AVR PINS *****************/
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK  7

/**********************************************/
typedef struct
{
	uint8 ENA_INT;
	uint8 EN_SPI ;
	uint8 ORDER_TRANSMITTING ;
	uint8 mode ;
	uint8 cpol_cpha ;
	uint8 speed ;

}SPI_CONFIG;


/********************* APIS *****************/
extern void SPI_Init ();
extern void SPI_TransmitData (uint8 character);
extern uint8 SPI_ReceivetData ();
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
