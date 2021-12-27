/*
 * DIO_Interface.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../LIB/types.h"
/********** MAKING GENERIC DEFINITION OF PORTS ************/
#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4
/**********************************************************/

/******************** STATES OF PINS ************************/
#define OUTPUT 1
#define INPUTWPULLUP 2
#define INPUTWOPULLUP 3
/************************************************************/

/************************ CASE ******************************/
#define HIGH 1
#define LOW  0
/************************************************************/

/********************* case of ports ************************/
#define ALLHIGH 0xff
#define ALLLOW  0x00
/************************************************************/


/******************** FUNCTION WE NEED **********************/

extern void  DIO_vSetPortDirection  (uint8 Name_port ,uint8 State_port);                  //3
extern void  DIO_vWritePortValue    (uint8 Name_Port , uint8 Case_Port);                  //6
extern uint8 DIO_uReadPortDirection (uint8 Name_Port);                                    //7
extern void  DIO_vSetPinDirection   (uint8 Name_port ,uint8 Pin_Num ,uint8 State_Pin );   //1
extern void  DIO_vWritePinValue     (uint8 Name_Port ,uint8 Pin_Num ,uint8 Value_Pin);    //2
extern uint8 DIO_uReadPinDirection  (uint8 Name_Port ,uint8 Pin_Num);                     //4
extern void  DIO_vTogglePin         (uint8 Name_Port , uint8 Pin_Num);                    //5

/************************************************************/

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
