/*
 * @File : Calculator.h
 * @Author: Mo'men Elhoseiny
 * @Brief: Main app header file of the calculator app
 * @Creation Date: 12 December 2023
 */

#ifndef CALCULATOR_H
#define	CALCULATOR_H

/*============================= Includes section =============================*/
#include "ECU_Layer/ECU_init.h"
#include "Calculator_Math/CalculatorMath.h"
/*============================================================================*/
/*================================= Macros ===================================*/
#define REMOVE_CHAR         ('@')
/*Indicates 3 lines in 20 x 4 LCD so the total is 60*/
#define MATH_STR_LENGTH     ((uint8)60)

#define INT32MAX            ((sint32)2147483647)
#define INT32MIN            ((sint32)-2147483648)
/*============================================================================*/

/*============================== Macro Functions =============================*/

/*============================================================================*/


/*============================ Function Declarations =========================*/
/*
 * @Brief     : Function removes a char from a char array of known length
 * @Parameter : pointer to array of char to remove from
 * @length    : Length of the array 
 * @Return    : State of remove operation
 *              0 : Couldn't remove char (string is empty)
 *              1 : Char removed successfully 
 */
uint8 String_Remove_Char(char *str,uint8 length);

/*
 * @Brief       : Appends 1 char to a string
 * @Parameter   : String to append char to
 * @Parameter   : Data char to append.
 */
void String_Append_Char(char *str,char Data);
/*
 * @Brief       : Function Checks if number can be displayed as int or float and acts accordingly
 * @Parameter   : Float value to display.
 */
void Calculator_display_result(float32 Res);
/*============================================================================*/
#endif	/* CALCULATOR_H */

