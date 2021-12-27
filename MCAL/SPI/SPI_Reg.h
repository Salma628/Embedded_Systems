/*
 * SPI_Reg.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_

#define SPDR     (*(volatile uint8 *) 0x2F)
#define SPSR     (*(volatile uint8 *) 0x2E)
#define SPCR     (*(volatile uint8 *) 0x2D)

#endif /* MCAL_SPI_SPI_REG_H_ */
