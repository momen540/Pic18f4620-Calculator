/*
 * @File  : CalculatorMath.h
 * @Author: Mo'men Elhoseiny
 * @Brief : Header file for String math 
 * @Creation Date: 11 December 2023
 */

#ifndef CALCULATORMATH_H
#define	CALCULATORMATH_H
/*============================= Includes Section =============================*/
#include "../MCAL_Layer/mcal_std_types.h"
/*============================================================================*/

/*=============================== Macto Section ==============================*/
#define CHAR_IS_NUMBER      (1)
#define CHAR_NOT_NUMBER     (0)
#define CHAR_IS_OP          (1)
#define CHAR_NOT_OP         (0)
#define CHAR_IS_POW         (1)
#define CHAR_NOT_POW        (0)
#define SYNTAX_ERROR        (1)
#define NO_SYNTAX_ERROR     (0)
#define MATH_ERROR          (1)
#define NO_MATH_ERROR       (0)
#define NUMBER_CAUGHT       (1)
#define NUMBER_NOT_CAUGHT   (0)
/*============================================================================*/

/*========================== Function Declarations ===========================*/
/*
 *@ Brief     : Completely Handles the operations in the string.
 *@ Parameter : Takes a string of mathematical operations.
 *@ Return    : returns the result of these mathematical operations. 
 */
float32 HandleString(char * str);
/*
 * @ Brief : This Function Takes a string of mathematical operations and finds if it has a syntax error
 * @ Parameter char string of the mathematical operations
 * @ return  Error state : 
 *                        SYNTAX_ERROR    : string is not ready for mathematical operations
 *                        NO_SYNTAX_ERROR : string has no syntax error and is ready for mathematical operations
 */
bool SyntaxErr(char * str);

/*
 * @ Brief : This Function Takes a string of mathematical operations and finds if it has a mathematical error
 * @ Parameter char string of the mathematical operations
 * @ return  Error state : 
 *                        MATH_ERROR    : string has a mathematical problem and should not be calculated
 *                        NO_MATH_ERROR : string has no math error and is ready for mathematical operations
 */
bool MathError(char * str);
/*============================================================================*/
#endif	/* CALCULATORMATH_H */

