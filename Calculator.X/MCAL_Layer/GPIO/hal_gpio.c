/*
 * @File : hal_gpio.c
 * @Author: Mo'men Elhoseiny
 * @Brief: Source file for GPIO driver for pic18f4620
 * @Creation Date: 26 July 2023
 */


#include "hal_gpio.h"
/******************************* Global Variables *****************************/
/*Direction control reference*/
volatile uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
/*Logic control reference*/
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};
/*Port control reference*/
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/******************************************************************************/

/************************ Function Definitions section ************************/

/**
 * Function to initialize pin as input or output
 * @param _pin_cfg
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */

Std_ReturnType GPIO_pin_dir_init(const Pin_config_t * _pin_cfg)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=_pin_cfg)&&(_pin_cfg->Pin < (MAX_PIN_NUMBER))&&(_pin_cfg->Port < (MAX_PORT_NUMBER)))
    {
        ret=E_OK;
        switch(_pin_cfg->Direction)
        {
            case GPIO_Output:
                CLEAR_BIT(*tris_registers[_pin_cfg->Port],_pin_cfg->Pin);
                GPIO_pin_write(_pin_cfg,_pin_cfg->Logic);
                break;
            case GPIO_Input:
                SET_BIT(*tris_registers[_pin_cfg->Port],_pin_cfg->Pin);
                GPIO_pin_write(_pin_cfg,_pin_cfg->Logic);
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret; 
}
/**
 * Function to initialize pin as input or output and writes the default logic to pin
 * @param _pin_cfg
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */

Std_ReturnType GPIO_pin_init(const Pin_config_t * _pin_cfg)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=_pin_cfg)&&(_pin_cfg->Pin < (MAX_PIN_NUMBER))&&(_pin_cfg->Port < (MAX_PORT_NUMBER)))
    {
    ret = E_OK;
    ret=GPIO_pin_dir_init(_pin_cfg);
    ret=GPIO_pin_write(_pin_cfg,_pin_cfg->Logic);
    }
    return ret;
}

/**
 * Function to find if the pin is input or output
 * @param _pin_cfg
 * @param Dir
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_get_dir(const Pin_config_t * _pin_cfg,Direction_t *Dir)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=_pin_cfg)&&(_pin_cfg->Pin < (MAX_PIN_NUMBER))&&(_pin_cfg->Port < (MAX_PORT_NUMBER))&&(NULL!=Dir))
    {
        ret=E_OK;
        *Dir=READ_BIT(*tris_registers[_pin_cfg->Port],_pin_cfg->Pin);
    }
    return ret;
}

/**
 * Function to write pin logic
 * @param _pin_cfg
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_write(const Pin_config_t * _pin_cfg,Logic_t logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=_pin_cfg)&&(_pin_cfg->Pin < (MAX_PIN_NUMBER))&&(_pin_cfg->Port < (MAX_PORT_NUMBER)))
    {
        ret=E_OK;
        switch(logic)
        {
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[_pin_cfg->Port],_pin_cfg->Pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[_pin_cfg->Port],_pin_cfg->Pin);
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
     return ret;
}
/**
 * Function to read pin logic
 * @param _pin_cfg
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_read_logic(const Pin_config_t * _pin_cfg,Logic_t *logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=_pin_cfg)&&(_pin_cfg->Pin < (MAX_PIN_NUMBER))&&(_pin_cfg->Port < (MAX_PORT_NUMBER))&&(NULL!=logic))
    {
        *logic=READ_BIT(*port_registers[_pin_cfg->Port],_pin_cfg->Pin);
        ret=E_OK;
    }
    return ret;
}

/**
 * Function to toggle pin logic
 * @param _pin_cfg
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_pin_toggle(const Pin_config_t * _pin_cfg)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=_pin_cfg)&&(_pin_cfg->Pin < (MAX_PIN_NUMBER))&&(_pin_cfg->Port < (MAX_PORT_NUMBER)))
    {
        TOGGLE_BIT(*lat_registers[_pin_cfg->Port],_pin_cfg->Pin);
        ret=E_OK;
    }
    return ret;
}

/**
 * Function to initialize direction of port
 * @param port
 * @param Dir
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_init(Port_Index_t port,uint8 Dir)
{
    Std_ReturnType ret = E_NOT_OK;
    if(port < MAX_PORT_NUMBER)
    {
        *tris_registers[port]=Dir;
        ret = E_OK;
    }
    return ret;
}
/**
 * Function to find direction of port
 * @param port
 * @param Dir
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_get_dir(Port_Index_t port,uint8 *Dir)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=Dir)&&(port < MAX_PORT_NUMBER))
    {
        *Dir=*tris_registers[port];
        ret = E_OK;
    }
    return ret;
}
/**
 * Function to write logic to port 
 * @param port
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_write(Port_Index_t port,uint8 logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if(port < MAX_PORT_NUMBER)
    {
        *lat_registers[port]=logic;
        ret = E_OK;
    }
    return ret; 
}
/**
 * Function to read logic from port
 * @param port
 * @param logic
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_read_logic(Port_Index_t port,uint8 *logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=logic)&&(port < MAX_PORT_NUMBER))
    {
        *logic=*port_registers[port];
        ret = E_OK;
    }
    return ret;
}
/**
 * Function to toggle port logic
 * @param port
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType GPIO_port_toggle(Port_Index_t port)
{
    Std_ReturnType ret = E_OK;
    if(port < MAX_PORT_NUMBER)
    {
        *lat_registers[port]^=0xFF;
        ret = E_OK;
    }
    return ret;
}
/******************************************************************************/