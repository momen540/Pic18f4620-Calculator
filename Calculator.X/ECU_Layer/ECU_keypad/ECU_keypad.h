/* 
 * File:   ECU_keypad.h
 * Author: Mo'men Ahmed
 *
 * Created on July 30, 2023, 12:22 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

#include "ECU_keypad_cfg.h"

/*************************************** Include section ******************************************************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ECU_keypad_cfg.h"
/************************************** End of Include section ************************************************/

/********************************* Macro Definitions section **********************************/
#define KEYPAD_ROWS (4)
#define KEYPAD_COLS (4)
/******************************* End of Macro Definitions section******************************/

/**************************************** User Defined Data types *********************************************/    
typedef struct{
    Pin_config_t keypad_row_pins[KEYPAD_ROWS];
    Pin_config_t keypad_col_pins[KEYPAD_COLS];
}keypad_t;
/************************************* End of User Defined Data types *****************************************/

/************************************** Function Declarations section *****************************************/
Std_ReturnType keypad_init(const keypad_t *keypad);
Std_ReturnType keypad_get_val(const keypad_t *keypad,uint8 * val);
/*********************************** End of Function Declarations section *************************************/


#endif	/* ECU_KEYPAD_H */

