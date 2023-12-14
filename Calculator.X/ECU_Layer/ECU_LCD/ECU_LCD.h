/* 
 * File:   ECU_LCD.h
 * Author: Mo'men Ahmed
 *
 * Created on August 4, 2023, 12:33 PM
 */
/****************************** Include section *******************************/
#include "ECU_LCD_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../../MCAL_Layer/mcal_I2C/hal_I2C.h"
/******************************************************************************/


/************************** Macro Definitions section *************************/
/*====================== LCD Commands ======================*/
#define _LCD_CLEAR                                      (0x01)
#define _LCD_RETURN_HOME                                (0x02)
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF                   (0x04)
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                    (0x05)
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF                   (0x06)
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                    (0x07)
#define _LCD_CURSOR_MOVE_SHIFT_LEFT                     (0x10)
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT                    (0x14)
#define _LCD_DISPLAY_SHIFT_LEFT                         (0x18)
#define _LCD_DISPLAY_SHIFT_RIGHT                        (0x1C)
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF        (0x0C)
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON         (0x0D)
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF         (0x0E)
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON          (0x0F)
#define _LCD_DISPLAY_OFF_CURSOR_OFF                     (0x08)
#define _LCD_8BIT_MODE_2_LINE                           (0x38)
#define _LCD_4BIT_MODE_2_LINE                           (0x28)
#define _LCD_CGRAM_START                                (0x40)
#define _LCD_DDRAM_START                                (0x80)
#define _LCD_4BIT_1                                     (0x33)
#define _LCD_4BIT_2                                     (0x32)
/*==========================================================*/
#define ROW1 (1)
#define ROW2 (2)
#define ROW3 (3)
#define ROW4 (4)
/******************************************************************************/


/************************** User Defined Data types ***************************/    
typedef struct{
#if (LCD_MODE != LCD_I2C)
    Pin_config_t lcd_rs;
    Pin_config_t lcd_en;
    Pin_config_t lcd_data[LCD_PINS];
#elif (LCD_MODE == LCD_I2C)
    mssp_i2c_t I2C_Handle;
#endif
}chr_lcd_t;
/******************************************************************************/



/*********************** Function Declarations section ************************/
/**
 * Converts uint8 to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str);
/**
 * Converts uint16 to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str);
/**
 * Converts sint32 to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_int32_to_string(sint32 value, uint8 *str);
/**
 * Converts Float to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_float_to_string(float value,uint8 *str);

/**
 * Function to initialize LCD
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_init(const chr_lcd_t *lcd);

/**
 * Function to send commands to lcd
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_command(const chr_lcd_t *lcd, uint8 command);

/**
 * Function to send char to LCD
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_char(const chr_lcd_t *lcd, uint8 data);

/**
 * Function to send char at a certain position
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_char_at(const chr_lcd_t *lcd,uint8 row, uint8 column, uint8 data);

/**
 * Function sends a string to LCD
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_string(const chr_lcd_t *lcd, uint8 *str);

/**
 * Function send strings to LCD at specific locations
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_data(const chr_lcd_t *lcd, uint8 row, uint8 column, uint8 *str);

/**
 * Function creates and sends a custom char to LCD
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_custom_char(const chr_lcd_t *lcd, uint8 row, uint8 column,const uint8 _chr[], uint8 mem_pos);

/******************************************************************************/


#ifndef ECU_LCD_H
#define	ECU_LCD_H

#endif	/* ECU_LCD_H */

