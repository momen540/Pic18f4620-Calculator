/*
 * File:   ECU_LCD.c
 * Author: Mo'men Ahmed
 * 
 * Created on August 4, 2023, 12:33 PM
 */
#include "ECU_LCD.h"
/***************************** Global Variables *******************************/
#if(LCD_MODE == LCD_I2C)
/*Used to indicate sending mode for I2C Lcd*/
static uint8 RS=0;
#endif
/******************************************************************************/
/********************** Static Functions Declarations *************************/
#if(LCD_MODE != LCD_8BIT)
/**
 * Function sends 4bits to lcd
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_send_4bits(const chr_lcd_t *lcd, uint8 _data_command);
#endif
#if ((LCD_MODE == LCD_4BIT) ||(LCD_MODE == LCD_8BIT))
/**
 * Function sends enable signal to LCD
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_enable_signal(const chr_lcd_t *lcd);
#endif
#if(LCD_MODE == LCD_I2C)
/*
 * @Brief       : Function sends a Byte over the LCD on I2C Bus
 * @Parameters  : pointer to lcd configuration 
 * @Data        : Data to send over to LCD
 * @return Status of the function
 *          (E_OK)     : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType IO_expander_write(const chr_lcd_t *lcd,uint8 data);
#endif
/**
 * Function selects location on LCD
 * @param lcd
 * @param row
 * @param column
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_set_cursor(const chr_lcd_t *lcd, uint8 row, uint8 column);
/******************************************************************************/

/*************************** Functions Definitions ****************************/
/**
 * Function to initialize LCD
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_init(const chr_lcd_t *lcd)
{
    uint8 l_lcd_data_pins_ctr=0;
    Std_ReturnType ret = E_NOT_OK;
    if(NULL!=lcd)
    {
#if ((LCD_MODE == LCD_4BIT) ||(LCD_MODE == LCD_8BIT))
        ret=E_OK;
        ret = ret&(GPIO_pin_init(&(lcd->lcd_en)));
        ret = ret&(GPIO_pin_init(&(lcd->lcd_rs)));
        for(l_lcd_data_pins_ctr=0;l_lcd_data_pins_ctr < LCD_PINS;l_lcd_data_pins_ctr++)
        {
            ret = ret &(GPIO_pin_init(&(lcd->lcd_data[l_lcd_data_pins_ctr])));
        }
#endif
#if(LCD_MODE == LCD_4BIT) //4bit mode
        __delay_ms(20);
        ret = lcd_send_command(lcd, _LCD_4BIT_1);
        __delay_ms(5);
        ret = lcd_send_command(lcd, _LCD_4BIT_2);
        __delay_ms(150);
        ret = lcd_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
#elif (LCD_MODE == LCD_8BIT) //8bit mode
        __delay_ms(20);
        ret = lcd_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(150);
        ret = lcd_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
#elif (LCD_MODE == LCD_I2C)
        __delay_ms(20);
        ret &= IO_expander_write(lcd,0x00);
        __delay_ms(5);
        ret &= lcd_send_command(lcd,0x03);
        __delay_ms(5);
        ret &= lcd_send_command(lcd,0x03);
        __delay_ms(5);
        ret &= lcd_send_command(lcd,0x03);
        __delay_ms(5);
        ret &= lcd_send_command(lcd,_LCD_4BIT_1);
        __delay_ms(5);
        ret &= lcd_send_command(lcd,_LCD_4BIT_2);
        __delay_ms(150);
        ret &= lcd_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
#endif
        ret = lcd_send_command(lcd, _LCD_CLEAR);
        ret = lcd_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_send_command(lcd, _LCD_DDRAM_START);
    }
    return ret;
}
/**
 * Function to send commands to lcd
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_command(const chr_lcd_t *lcd, uint8 command)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL!=lcd)
    {
#if ((LCD_MODE == LCD_4BIT) ||(LCD_MODE == LCD_8BIT))
        /* R/W Pin Hard Wired to ground */
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        ret = ret &( GPIO_pin_write(&(lcd->lcd_rs), GPIO_LOW) );
#endif
#if (LCD_MODE == LCD_4BIT)
        /* Send the Command through the (4-Pins" Data lines */
        ret = ret &(lcd_send_4bits(lcd, command >> 4));
        /* Send the Enable Signal on the "E" Pin */
        ret = ret &(lcd_enable_signal(lcd));
        /* Send the Command through the (4-Pins" Data lines */
        ret = ret &(lcd_send_4bits(lcd, command));
        /* Send the Enable Signal on the "E" Pin */
        ret = ret &(lcd_enable_signal(lcd));
#elif (LCD_MODE == LCD_8BIT)
        uint8 l_pin_counter=0;
        /* Send the Command through the (8-Pins" Data lines */
        for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
            ret = ret &(GPIO_pin_write(&(lcd->lcd_data[l_pin_counter]), (command >> l_pin_counter) & (uint8)0x01));
        }
        /* Send the Enable Signal on the "E" Pin */
        ret = ret &(lcd_enable_signal(lcd));
#elif (LCD_MODE == LCD_I2C)
    RS=0;
    ret &= lcd_send_4bits(lcd,command & 0xf0);
    ret &= lcd_send_4bits(lcd,(command << 4) & ( 0xf0 ));
#endif
    }
    return ret;
}
/**
 * Function to send char to LCD
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_char(const chr_lcd_t *lcd, uint8 data)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL!=lcd)
    {
#if ((LCD_MODE == LCD_4BIT) ||(LCD_MODE == LCD_8BIT))
        /* R/W Pin Hard Wired to ground */
        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
        ret = GPIO_pin_write(&(lcd->lcd_rs), GPIO_HIGH);
#endif
#if (LCD_MODE == LCD_4BIT)
        /* Send the Command through the (4-Pins" Data lines */
        ret = ret &(lcd_send_4bits(lcd, data >> 4));
        /* Send the Enable Signal on the "E" Pin */
        ret = ret &(lcd_enable_signal(lcd));
        /* Send the Command through the (4-Pins" Data lines */
        ret = ret &(lcd_send_4bits(lcd, data));
        /* Send the Enable Signal on the "E" Pin */
        ret = ret &(lcd_enable_signal(lcd));
#elif (LCD_MODE == LCD_8BIT)
        uint8 l_pin_counter=0;
        /* Send the Command through the (8-Pins" Data lines */
        for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
            ret = ret &(GPIO_pin_write(&(lcd->lcd_data[l_pin_counter]), (data >> l_pin_counter) & (uint8)0x01));
        }
        /* Send the Enable Signal on the "E" Pin */
        ret = ret &(lcd_enable_signal(lcd));
#elif (LCD_MODE == LCD_I2C)
    RS=1;
    ret &= lcd_send_4bits(lcd,data & 0xf0);
    ret &= lcd_send_4bits(lcd,(data << 4) & ( 0xf0 ));
#endif
    }
    return ret;
}
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
Std_ReturnType lcd_send_char_at(const chr_lcd_t *lcd,uint8 row, uint8 column, uint8 data)
{
    column--;
    Std_ReturnType ret = E_NOT_OK;
    if(NULL!=lcd)
    {
        if((row>0)&&(column>=0)&&(row<=(ROW_NUMBER))&&(column<(COLUMN_NUMBER)))
        {
        ret = E_OK;
        ret = ret & (lcd_set_cursor(lcd,row,column));
        ret = ret & ( lcd_send_char(lcd,data));
        }
    }    
    return ret;
}
/**
 * Function sends a string to LCD
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_send_string(const chr_lcd_t *lcd, uint8 *str)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=lcd)&&(NULL!=str))
    {
        ret = E_OK;
        while(*str)
        {
            ret = ret & (lcd_send_char(lcd,*str++));
        }
    }    
    return ret;
}
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
Std_ReturnType lcd_send_data(const chr_lcd_t *lcd, uint8 row, uint8 column, uint8 *str)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=lcd)&&(NULL!=str))
    {
        ret = E_OK;
        if((row>0)&&(column>=0)&&(row<=(ROW_NUMBER))&&(column<=(COLUMN_NUMBER)))
        {
            while(*str)
            {
                ret &= lcd_send_char_at(lcd,row,column,*str++);
                column++;
                if(column >COLUMN_NUMBER){
                    column = 1;
                    if(row < (ROW_NUMBER)){
                        row ++;
                    }
                    else{
                        row = 1;
                    }
                }
                else{/* Continue */}
            }
        }
    }    
    return ret;    
}
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
Std_ReturnType lcd_send_custom_char(const chr_lcd_t *lcd, uint8 row, uint8 column,const uint8 _chr[], uint8 mem_pos)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 lcd_ctr=0;
    if(NULL!=lcd)
    {
        ret = E_OK;
        lcd_send_command(lcd,((_LCD_CGRAM_START)+(mem_pos*8)));
        for(lcd_ctr = 0;lcd_ctr<8;lcd_ctr++)
        {
            ret = ret&(lcd_send_char(lcd,_chr[lcd_ctr]));
        }
        ret = ret&(lcd_send_char_at(lcd,row,column,mem_pos));
    }    
    return ret;
}
/**
 * Converts uint8 to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 Temp_String[5] = {0};
    uint8 DataCounter = 0;
    if(NULL != str)
        {
            ret = E_OK;   
            memset((char *)str, ' ', 4);
            str[4]='\0';
            sprintf((char *)Temp_String, "%i", value);
            while(Temp_String[DataCounter] != '\0')
            {
                str[DataCounter] = Temp_String[DataCounter]; 
                DataCounter++;
            }
        }
    return ret;
}

/**
 * Converts uint16 to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 Temp_String[6] = {0};
    uint8 DataCounter = 0;
    if(NULL != str)
    {
        ret = E_OK;  
        memset((char *)str, ' ', 5);
        str[5] = '\0';
        sprintf((char *)Temp_String, "%i", value);
        while(Temp_String[DataCounter] != '\0')
        {
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
    }
    return ret;
}

/**
 * Converts sint32 to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_int32_to_string(sint32 value, uint8 *str)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 Temp_String[12] = {' '};
    uint8 DataCounter = 0;
    if(NULL != str)
        {
            ret = E_OK;   
            memset((uint8 *)str, ' ', 11);
            str[11]='\0';
            sprintf((char *)Temp_String, "%i", value);
            while(Temp_String[DataCounter] != '\0')
            {
                str[DataCounter] = Temp_String[DataCounter]; 
                DataCounter++;
            }
        }
    return ret;
}

#if  (FLOAT_CONVERSION == FLOAT_EN)
/**
 * Converts Float to string
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

Std_ReturnType convert_float_to_string(float value,uint8 *str)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 Temp_String[16] = {' '};
    uint8 DataCounter = 0;
    if(NULL != str)
        {
            ret = E_OK;   
            memset((char *)str, ' ', 15);
            str[15]='\0';
            sprintf((char *)Temp_String, "%0.3f", value);
            while(Temp_String[DataCounter] != '\0')
            {
                str[DataCounter] = Temp_String[DataCounter]; 
                DataCounter++;
            }
        }
    return ret;    
}
#endif
/******************************************************************************/


/*********************** Static Functions Declarations ************************/

/**
 * Function sends 4bits to lcd or i2c LCD
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if(LCD_MODE != LCD_8BIT)
static Std_ReturnType lcd_send_4bits(const chr_lcd_t *lcd, uint8 _data_command)
{
    Std_ReturnType ret = E_OK;
#if (LCD_MODE == LCD_4BIT)
    ret = ret &(GPIO_pin_write(&(lcd->lcd_data[0]), (_data_command >> 0) & (uint8)0x01));
    ret = ret &(GPIO_pin_write(&(lcd->lcd_data[1]), (_data_command >> 1) & (uint8)0x01));
    ret = ret &(GPIO_pin_write(&(lcd->lcd_data[2]), (_data_command >> 2) & (uint8)0x01));
    ret = ret &(GPIO_pin_write(&(lcd->lcd_data[3]), (_data_command >> 3) & (uint8)0x01));
#elif (LCD_MODE == LCD_I2C)
    _data_command|=RS;
    IO_expander_write(lcd,_data_command | 0x04);
    IO_expander_write(lcd,_data_command & 0xfb);
    __delay_us(100);
#endif
    return ret;
}
#endif
#if ((LCD_MODE == LCD_4BIT) ||(LCD_MODE == LCD_8BIT))
/**
 * Function sends enable signal to LCD
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_enable_signal(const chr_lcd_t *lcd)
{
    Std_ReturnType ret = E_OK;
    ret = ret &(GPIO_pin_write(&(lcd->lcd_en), GPIO_HIGH));
    __delay_us(5);
    ret = ret &(GPIO_pin_write(&(lcd->lcd_en), GPIO_LOW));
    return ret;
}
#endif
/**
 * Function selects location on LCD
 * @param lcd
 * @param row
 * @param column
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_set_cursor(const chr_lcd_t *lcd, uint8 row, uint8 column)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL!=lcd)&&((ROW_NUMBER) >= row)&&((COLUMN_NUMBER)>=column)&&((column>=0))&&(row > 0))
    {
        switch (row)
        {
#if ((ROW_NUMBER >= 1))

            case ROW1 : ret = lcd_send_command(lcd, (0x80 + column)); break;
#endif
#if(ROW_NUMBER >= 2)
            case ROW2 : ret = lcd_send_command(lcd, (0xc0 + column)); break;
#endif
#if(ROW_NUMBER == 4)
            case ROW3 : ret = lcd_send_command(lcd, (0x94 + column)); break;
            case ROW4 : ret = lcd_send_command(lcd, (0xd4 + column)); break;
#endif
            default: ;
        }
    }
    return ret;
}
#if(LCD_MODE == LCD_I2C)
/*
 * @Brief       : Function sends a Byte over the LCD on I2C Bus
 * @Parameters  : pointer to lcd configuration 
 * @Data        : Data to send over to LCD
 * @return Status of the function
 *          (E_OK)     : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType IO_expander_write(const chr_lcd_t *lcd,uint8 data){
    uint8 ack_St = I2C_NACK_RECEIVED;
    Std_ReturnType ret = E_NOT_OK; 
    ret &= I2C_Master_Transmit(&(lcd->I2C_Handle),LCD_ADDR,1,&data,&ack_St);
    if(ack_St == I2C_ACK_RECEIVED){
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    return ret;
}
#endif
/******************************************************************************/