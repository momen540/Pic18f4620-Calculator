/* 
 * File:   ECU_Button.h
 * Author: Mo'men Ahmed
 *
 * Created on July 28, 2023, 1:30 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*************************************** Include section ******************************************************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ECU_Button_cfg.h"
/************************************** End of Include section ************************************************/

/**************************************** User Defined Data types *********************************************/
typedef enum
{
    Button_Active_Low,
    Button_Active_High
}button_connection_t;

typedef enum
{
    Button_pressed,
    Button_released
}Button_state_t;

typedef struct
{
    Pin_config_t             Button_pin; //button directory  @ref Pin_config_t  
    Button_state_t           state;      //button pressed?   @ref Button_state_t
    button_connection_t      connection; //button connection @ref button_connection_t
}Button_t;

/************************************* End of User Defined Data types *****************************************/

/************************************** Function Declarations section *****************************************/
Std_ReturnType button_init(const Button_t *button);
Std_ReturnType button_read_state(const Button_t *button,Button_state_t * state);
Std_ReturnType button_read_state_debounce(const Button_t *button,Button_state_t * state);
/*********************************** End of Function Declarations section *************************************/


#endif	/* ECU_BUTTON_H */

