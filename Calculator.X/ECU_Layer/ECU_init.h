/*
 * @File  : ECU_init.c
 * @Author: Mo'men Elhoseiny
 * @Brief : Header file for ECU initialization modules used in Calculator
 * @Creation Date: 12 December 2023
 */
#ifndef ECU_INIT_H
#define	ECU_INIT_H

/***************************** Include section ********************************/
#include "../MCAL_Layer/mcal_I2C/hal_I2C.h"
#include "../MCAL_Layer/mcal_interrupt/mcal_external_interrupt.h"
#include "ECU_keypad/ECU_keypad.h"
#include "ECU_LCD/ECU_LCD.h"
/******************************************************************************/
/*********************** Hardware Definitions sections ************************/
extern keypad_t Keypad;
extern chr_lcd_t lcd;
extern INTx_t NB0;
extern INTx_t NB1;
extern mssp_i2c_t I2C;
/******************************************************************************/

/*********************** Function Declarations section ************************/
/**
 * Function Initializes hardware components
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType Calculator_Init(void);

/*
 * @Brief       : External interrupt on port b pin 0 Callback
 * @Description : Changes the value of keypadder variable to . for float operations in calculator 
 */
void EXTINT0(void);
/*
 * @Brief       : External interrupt on port b pin 1 Callback
 * @Description : Changes the value of keypadder variable to REMOVE_CHAR to remove the last char in the string
 */
void EXTINT1(void);
/*********************************/
/******************************************************************************/

#endif	/* ECU_INIT_H */

