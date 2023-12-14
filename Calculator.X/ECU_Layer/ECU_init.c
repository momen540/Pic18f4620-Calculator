/*
 * @File  : ECU_init.c
 * @Author: Mo'men Elhoseiny
 * @Brief : Contains Initialization information for modules used in Calculator
 * @Creation Date: 12 December 2023
 */

/*========================== Include Section =================================*/
#include "ECU_init.h"
/*============================================================================*/

/*====================== Global Variables Section ============================*/
/*
 *Initialization for keypad module On port C
 */
keypad_t Keypad = {
    .keypad_row_pins[0].Port = PORTD_Index,
    .keypad_row_pins[0].Pin  = PIN0,
    .keypad_row_pins[0].Direction = GPIO_Output,
    .keypad_row_pins[0].Logic = GPIO_LOW,
    .keypad_row_pins[1].Port = PORTD_Index,
    .keypad_row_pins[1].Pin  = PIN1,
    .keypad_row_pins[1].Direction = GPIO_Output,
    .keypad_row_pins[1].Logic = GPIO_LOW,
    .keypad_row_pins[2].Port = PORTD_Index,
    .keypad_row_pins[2].Pin  = PIN2,
    .keypad_row_pins[2].Direction = GPIO_Output,
    .keypad_row_pins[2].Logic = GPIO_LOW,
    .keypad_row_pins[3].Port = PORTD_Index,
    .keypad_row_pins[3].Pin  = PIN3,
    .keypad_row_pins[3].Direction = GPIO_Output,
    .keypad_row_pins[3].Logic = GPIO_LOW,
            
    .keypad_col_pins[0].Port = PORTD_Index,
    .keypad_col_pins[0].Pin  = PIN4,
    .keypad_col_pins[0].Direction = GPIO_Input,
    .keypad_col_pins[0].Logic = GPIO_LOW,
    .keypad_col_pins[1].Port = PORTD_Index,
    .keypad_col_pins[1].Pin  = PIN5,
    .keypad_col_pins[1].Direction = GPIO_Input,
    .keypad_col_pins[1].Logic = GPIO_LOW,
    .keypad_col_pins[2].Port = PORTD_Index,
    .keypad_col_pins[2].Pin  = PIN6,
    .keypad_col_pins[2].Direction = GPIO_Input,
    .keypad_col_pins[2].Logic = GPIO_LOW,
    .keypad_col_pins[3].Port = PORTD_Index,
    .keypad_col_pins[3].Pin  = PIN7,
    .keypad_col_pins[3].Direction = GPIO_Input,
    .keypad_col_pins[3].Logic = GPIO_LOW,
};
mssp_i2c_t I2C ={
    .I2C_Frequency = 400000,
    .I2C_GeneralCall = MSSP_I2C_GENERAL_CALL_DISABLED,
    .I2C_MasterReceive = MSSP_I2C_MASTER_RECEIVE_DISABLED,
    .I2C_Mode = I2C_Master_Mode,
    .I2C_Role = I2C_MASTER,
    .I2C_SMBus = MSSP_I2C_SMBUS_DISABLED,
    .I2C_SlewRate = MSSP_I2C_SLEW_RATE_DISABLED,
};
chr_lcd_t lcd={
.I2C_Handle = NULL,
};

INTx_t NB0={
    .Ext_InterruptHandler = EXTINT0,
    .edge = FallingEdge,
    .priority = High_Priority,
    .source =EXT_INT0,
    .pin.Port = PORTB_Index,
    .pin.Pin = PIN0,
    .pin.Direction = GPIO_Input,
};
INTx_t NB1={
    .Ext_InterruptHandler = EXTINT1,
    .edge = FallingEdge,
    .priority = High_Priority,
    .source =EXT_INT1,
    .pin.Port = PORTB_Index,
    .pin.Pin = PIN1,
    .pin.Direction = GPIO_Input,
};

/*============================================================================*/

/*======================== Function Definition section =======================*/
/**
 * Function Initializes hardware components
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType Calculator_Init(void)
{
#ifdef USE_INTERRUPT
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    INTERRUPT_PRIORITY_ENABLE;
    ENABLE_GLOBAL_INTERRUPT_HIGH;
    ENABLE_GLOBAL_INTERRUPT_LOW;
#else
    ENABLE_GLOBAL_INTERRUPT;
    ENABLE_PERIPHERAL_INTERRUPT;
#endif
#endif
    Std_ReturnType ret=E_OK;
    ret &= MSSP_I2C_init(&I2C);
    ret &= INTx_interrupt_init(&NB0);
    ret &= INTx_interrupt_init(&NB1);
    lcd.I2C_Handle = I2C;
    ret &= lcd_init(&lcd);
    ret &= keypad_init(&Keypad);
    return ret;
}
/*============================================================================*/