/*
 * @File : hal_gpio.h
 * @Author: Mo'men Elhoseiny
 * @Brief: Header file for GPIO driver for pic18f4620
 * @Creation Date: 26 July 2023
 */
#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/****************************** Include section *******************************/
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "pic18f4620.h"
#include "../../CommonMacros.h"
/******************************************************************************/

/************************** Macro Functions section ***************************/
#define MAX_PIN_NUMBER  (8)
#define MAX_PORT_NUMBER (5)
/******************************************************************************/

/************************* User Defined Data types ****************************/
/*
 * Enumeration for PIN number
 */
typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,            
    PIN5,
    PIN6,
    PIN7,
}Pin_Index_t;

/*
 * Enumeration of GPIO voltage level
 * GPIO_LOW  = 0 V
 * GPIO_HIGH = 5 V
 */
typedef enum
{
    GPIO_LOW,
    GPIO_HIGH       
}Logic_t;

/*
 *Enumeration for pin direction 
 */
typedef enum
{
    GPIO_Output,
    GPIO_Input       
}Direction_t;

/*
 *Enumeration for port number 
 */
typedef enum
{
    PORTA_Index,
    PORTB_Index,
    PORTC_Index,
    PORTD_Index,
    PORTE_Index
}Port_Index_t;

/*
 * Structure to initialize a Pin 
 */
typedef struct
{
    uint8 Port       :3; /*
                          * Select Port Index
                          * @ref Port_Index_t
                          */
    uint8 Pin        :3; /*
                          * Select pin index
                          * @ref Pin_Index_t
                          */
    uint8 Direction  :1; /*
                          * Pin Direction IN/OUT
                          * @ref Direction_t
                          */
    uint8 Logic      :1; /* Initial Pin Logic
                          * @ref Logic_t
                          */
}Pin_config_t;

/******************************************************************************/

/************************ Function Declarations section ***********************/

/**
 * Function to initialize pin as input or output
 * @param _pin_cfg
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_dir_init(const Pin_config_t * _pin_cfg);

/**
 * Function to initialize pin as input or output and writes the default logic to pin
 * @param _pin_cfg
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_init(const Pin_config_t * _pin_cfg);
/**
 * Function to find if the pin is input or output
 * @param _pin_cfg
 * @param Dir
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_get_dir(const Pin_config_t * _pin_cfg,Direction_t *Dir);

/**
 * Function to write pin logic
 * @param _pin_cfg
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_write(const Pin_config_t * _pin_cfg,Logic_t logic);
/**
 * Function to read pin logic
 * @param _pin_cfg
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_read_logic(const Pin_config_t * _pin_cfg,Logic_t *logic);
/**
 * Function to toggle pin logic
 * @param _pin_cfg
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_toggle(const Pin_config_t * _pin_cfg);
 
/**
 * Function to initialize direction of port
 * @param port
 * @param Dir
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_init(Port_Index_t port,uint8 Dir);
/**
 * Function to find direction of port
 * @param port
 * @param Dir
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_get_dir(Port_Index_t port,uint8 *Dir);
/**
 * Function to write logic to port 
 * @param port
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_write(Port_Index_t port,uint8 logic);
/**
 * Function to read logic from port
 * @param port
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_read_logic(Port_Index_t port,uint8 *logic);
/**
 * Function to toggle port logic
 * @param port
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_toggle(Port_Index_t port);

/******************************************************************************/
#endif	/* HAL_GPIO_H */

