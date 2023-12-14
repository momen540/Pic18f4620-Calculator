/* 
 * File:   ECU_keypad.c
 * Author: Mo'men Ahmed
 *
 * Created on July 30, 2023, 12:22 PM
 */

#include "ECU_keypad.h"

static const uint8 keypad_buttons[KEYPAD_ROWS][KEYPAD_COLS]={
                                                                {'7','8','9','/'},
                                                                {'4','5','6','*'},                
                                                                {'1','2','3','-'},
                                                                {'#','0','=','+'},
                                                            }; 
/**
 * Function to initialize keypad module
 * @param keypad
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType keypad_init(const keypad_t *keypad)
{
    uint8 index=0;
    Std_ReturnType ret = E_NOT_OK;
    if(NULL!=keypad)
    {
        ret = E_OK;
        for(index=0;index<KEYPAD_ROWS;index++)
        {
            GPIO_pin_init(&keypad->keypad_row_pins[index]);        
        }
        for(index=0;index<KEYPAD_COLS;index++)
        {
            GPIO_pin_init(&keypad->keypad_col_pins[index]);    
        }
    }
    return ret;
}
/**
 * Function to return pressed key values
 * @param keypad
 * @param val
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType keypad_get_val(const keypad_t *keypad,uint8 * val)
{
    uint8 row_counter_1=0,row_counter_2=0,col_counter=0;
    Logic_t col_logic=0;
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=keypad)&&(NULL!=val))
    {
        ret = E_OK;
        for(row_counter_2=0;row_counter_2<KEYPAD_ROWS;row_counter_2++)
        {
            for(row_counter_1=0;row_counter_1<KEYPAD_ROWS;row_counter_1++)
            {
                ret=GPIO_pin_write(&(keypad->keypad_row_pins[row_counter_1]),GPIO_LOW);
            }
            ret=GPIO_pin_write(&(keypad->keypad_row_pins[row_counter_2]),GPIO_HIGH);
            __delay_ms(5);
            for(col_counter=0;col_counter<KEYPAD_COLS;col_counter++)
            {
                ret=GPIO_pin_read_logic(&(keypad->keypad_col_pins[col_counter]),&col_logic);
                if(col_logic)
                {
                    *val = keypad_buttons[row_counter_2][col_counter];
                    while(col_logic){ret=GPIO_pin_read_logic(&(keypad->keypad_col_pins[col_counter]),&col_logic);}
                    return ret;
                }
            }
        }

    }
    return ret;    
}