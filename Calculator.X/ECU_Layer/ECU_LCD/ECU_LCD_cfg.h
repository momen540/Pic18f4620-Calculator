/* 
 * File:   ECU_LCD_cfg.h
 * Author: Mo'men Ahmed
 *
 * Created on August 4, 2023, 12:34 PM
 */

#ifndef ECU_LCD_CFG_H
#define	ECU_LCD_CFG_H

/* Enable/Disable Float conversion (Uses a lot of memory)*/

#define FLOAT_EN             (1)
#define FLOAT_DISABLE        (0)
#define FLOAT_CONVERSION     (FLOAT_EN)

/*LCD MODE*/
#define LCD_8BIT (0)
#define LCD_4BIT (1)
#define LCD_I2C  (2)
#define LCD_MODE (LCD_I2C)

/*Charachter LCD Size*/
#define ROW_NUMBER    (4)
#define COLUMN_NUMBER (20)

#if (LCD_MODE == LCD_4BIT)
#define LCD_PINS (4)
#elif (LCD_MODE == LCD_8BIT)
#define LCD_PINS (8)
#elif (LCD_MODE == LCD_I2C)
#define  LCD_ADDR          (0x70)
#endif

#endif	/* ECU_LCD_CFG_H */

