/* 
 * File:   ECU_Button.c
 * Author: Mo'men Ahmed
 *
 * Created on July 28, 2023, 1:30 PM
 */

#include"ECU_Button.h"

/**
 * Function to initialize a button
 * @param button
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType button_init(const Button_t *button)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=button)
    {
        ret=GPIO_pin_dir_init(&(button->Button_pin));
        ret=E_OK;
    }
    return ret;
}
/**
 * Function to get Button status
 * @param button
 * @param state
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType button_read_state(const Button_t *button,Button_state_t * state)
{
    Std_ReturnType ret=E_NOT_OK;
    Logic_t        button_logic=GPIO_LOW;
    if((NULL!=button)&&(NULL!=state))
    {
        ret=E_OK;
        ret = GPIO_pin_read_logic(&(button->Button_pin),&button_logic);
        switch(button->connection)
        {
            case Button_Active_High:
                if(button_logic == GPIO_HIGH)
                {
                    *state = Button_pressed;
                }
                else
                {
                    *state = Button_released;
                }
                break;
                
            case Button_Active_Low:
                if(button_logic == GPIO_HIGH)
                {
                    *state = Button_released;
                }
                else
                {
                    *state = Button_pressed;
                }
                break;
                
            default: 
                ret=E_NOT_OK;
                break;
        }
    }
    return ret;
}
#ifdef SOFTWARE_DEBOUNCE
Std_ReturnType button_read_state_debounce(const Button_t *button,Button_state_t * state)
{
    Std_ReturnType ret= E_NOT_OK;
    if((NULL!=button)&&(NULL!=state))
    {
        ret= E_OK;
        uint8 debounce_threshold=0;
        for(int i=0;i<20;i++)
        {
            ret = button_read_state(button,state);
            if(Button_pressed == *state)
            {
                debounce_threshold++;
            }
            else{
                
            }
            __delay_ms(5);
        }
        if(debounce_threshold>=11)
        {
            *state = Button_pressed;
        }
        else
        {
            *state = Button_released;
        }
    }
    return ret;
}
#endif