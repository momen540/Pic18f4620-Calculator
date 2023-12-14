# Pic18f4620-Calculator
1) Hardware :
   • Pic 18F4620 main micro controller.
   • PCF8574A IO Expander.
   • character LCD 20x4.
   • 4x4 Keypad for math.
   • 2 Push Buttons.
   • 2x4.7k ohm resistors for I2C Bus
   • Variable Resistor for Backlight of LCD
   • 2x 10k ohm resistors for pulling buttons up
---------------------------------------------------------------------------------------------------
3) Specifications :
   • Performs the following operations :
     sum(+) - substraction(-) - Multiblication(*) - division(/) - Power and roots using power(**).
   • Full operation precedence is implemented.
   • Float operations are implemented.
   • Can Handle up to 60 character operations.
   • Syntax error Handling
   • Math error Handling
---------------------------------------------------------------------------------------------------
4) Description :
   • LCD is used to display operations and results it is chosen to be a 4*20 display but it's easily changaable from the lcd configuration file, It also has 3 modes of operation:
1) 4bit Mode.                    2)8bit Mode.                  3)I2C Mode using IO expander.
The I2C Mode is used in this project but also can be easily changed using LCD Configuration file
LCD is connected to IO Expander and IO Expander is connected to Microcontroller through bit (3-SCL)
and (4-SDA) on port C which are pulled up by 4.7 k ohm resistors

   • 4x4 Keypad used as mathematical operations input from user with 2 Extra buttons connected as External Interrupt on Pin 0 and 1 on port B of The Micro Controller a button is used to insert '.' symbol to indicate the number is float and the other is a delete button which the user can use to delete the last appended character, these buttons are pulled up by using 10k ohm resistors.

   •Simmulation is included on proteus version 8.15 and project code is made using Mplab IDE v6.0
