/*
 * @File : Calculator.c
 * @Author: Mo'men Elhoseiny
 * @Brief: Main app section of the calculator app
 * @Creation Date: 12 December 2023
 */
#include "Calculator.h"

/***************************** Global Variables *******************************/
/* 
 * Variable Holds the value of current button press 
 * This Variable is called from ISR context (volatile).
 */
volatile uint8 keypadder = 0;
/******************************************************************************/
void main(void)
{
    /* Initialize Modules used in calculator */
    Calculator_Init();
    /*Result Number of the mathematical operation in the string*/
    float32 result =0;
    /*String to hold the mathematical operation*/
    char MATH_STR[MATH_STR_LENGTH];
    /*Current length of string*/
    uint8 length = 0;
    /*Flag used to indicate a change in string and start calculation and print result*/
    uint8 Calculate_flag = 0;
    while(true){
        /* Get Keypad Button Press if there is any */
        /* If button is pressed the function waits for button release */
        keypad_get_val(&Keypad,&keypadder);
        /*if the button press is a number or operation*/
        if((keypadder)&&(keypadder != '=')&&(keypadder != '#')){
            /*In case of external interrupt 1 remove char */
            if(keypadder == REMOVE_CHAR){
                String_Remove_Char(MATH_STR,length);
                length --;
                lcd_send_command(&lcd, _LCD_CLEAR);
            }
            /*In case of keypad press append value to string*/
            else{
                if(length < MATH_STR_LENGTH ){
                    if(length == 0){lcd_send_command(&lcd, _LCD_CLEAR);}
                    String_Append_Char(MATH_STR,keypadder);
                    length ++;
                }
                else{/*Don't append to string*/}
            }
            keypadder = 0;
            Calculate_flag = 1;
            lcd_send_data(&lcd,1,1,MATH_STR);
        }
        
        /*If the on/c value is pressed reset every string and value and clear LCD*/
        else if(keypadder == '#'){
            memset(MATH_STR,0,60);
            length = 0;
            keypadder = 0;
            lcd_send_command(&lcd, _LCD_CLEAR);
            }
        /*Clear lcd in case of = and wait for operation to be done to display the result*/
        else if(keypadder == '='){
            Calculate_flag = 1;
            lcd_send_command(&lcd, _LCD_CLEAR);
        }
        
        /*Check for syntax and math error if there is none calculate and print result*/
        if(Calculate_flag){
            if(SyntaxErr(MATH_STR) == NO_SYNTAX_ERROR){
                if(MathError(MATH_STR) == NO_MATH_ERROR){
                    result = HandleString(MATH_STR);
                    Calculator_display_result(result);
                }
                else{
                    if(keypadder == '='){ 
                    lcd_send_data(&lcd,4,1,"Math Error");
                    }
                }
            }
            else{
                if(keypadder == '='){
                    lcd_send_data(&lcd,4,1,"Syntax Error");
                }
            }
            Calculate_flag = 0;
        }

        
        /*reset values after displaying result if = is pressed*/
        if(keypadder == '='){
            memset(MATH_STR,0,60);
            length = 0;
            keypadder = 0;
        }
    }
}

/*
 * @Brief       : External interrupt on port b pin 0 Callback
 * @Description : Changes the value of keypadder variable to . for float operations in calculator 
 */
void EXTINT0(void){
    keypadder = '.';
}

/*
 * @Brief       : External interrupt on port b pin 1 Callback
 * @Description : Changes the value of keypadder variable to REMOVE_CHAR to remove the last char in the string
 */
void EXTINT1(void){
    keypadder = REMOVE_CHAR;
}

/*
 * @Brief     : Function removes a char from a char array of known length
 * @Parameter : pointer to array of char to remove from
 * @length    : Length of the array 
 * @Return    : State of remove operation
 *              0 : Couldn't remove char (string is empty)
 *              1 : Char removed successfully 
 */
uint8 String_Remove_Char(char *str,uint8 length){
    if(*str){
        str[length-1] = NULL;
        return 1;
    }
    else{
        return 0;
    }
}

/*
 * @Brief       : Appends 1 char to a string
 * @Parameter   : String to append char to
 * @Parameter   : Data char to append.
 */
void String_Append_Char(char *str,char Data){
    strncat(str,&Data,1);
}

/*
 * @Brief       : Function Checks if number can be displayed as int or float and acts accordingly
 * @Parameter   : Float value to display.
 */
void Calculator_display_result(float32 Res){
    /*String Holds Value of result of the calculation*/
    uint8 result_str[20];
    if(
        (ceil(Res) == floor(Res))
            &&
        ((Res <INT32MAX )&&(Res > INT32MIN) )
      )
    {
        convert_int32_to_string(Res,result_str);
    }
    else{
        convert_float_to_string(Res,result_str);
    }
    lcd_send_data(&lcd,4,1,result_str);
}