/*
 * LCD_Interface.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Masria For PCs
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/******************** definition of pins ***********************/
#define DATA_LINES PORT_A
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define CONTROL_LINES PORT_B
#define LCD_RS 1
#define LCD_RW 2
#define LCD_ENABLE  3

/***************************************************************/

#define CONST 4

/************************** command ****************************/
//#define LCD_INIT_PHASE_ONE 0x32        //--------------------------
#define LCD_INIT_PHASE_TWO 0x2         //--------------------------
#define LCD_INIT_PHASE_THREE 0x28        //SET FUNCTION
#define LCD_DISPLAY_OPTIONS 0x0E         //DISPLAY ON/OFF
#define LCD_CLEAR 0x01                   //CLEAR
#define LCD_INCREMENT_CURSOR 0x06        //INCREMENT CURSOR TO RIGHT /*ENTRY MODE */
/**************************************************************/


/************************** FUNCTION ****************************/
extern void LCD_vSendCommand (uint8 Command );
extern void LCD_vSendCharacter  (uint8 Data);
extern void LCD_vInit ();
extern void LCD_vClear ();
extern void LCD_vSendString (uint8 String[]);
extern void LCD_vGotoxy(uint8 Row,uint8 Col);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
