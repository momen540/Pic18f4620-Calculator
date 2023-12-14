/*
 * @File  : CalculatorMath.c
 * @Author: Mo'men Elhoseiny
 * @Brief : Source file for String math
 * @Creation Date: 11 December 2023
 */


/*============================= Includes Section =============================*/
#include "CalculatorMath.h"
/*============================================================================*/

/*===================== Static Functions Declarations ========================*/
/*
 * @Brief     : Checks if the charachter is a number or not
 * @Parameter : Char to check
 * @return    : returns the state
 *                                CHAR_IS_NUMBER    The value is actually a number
 *                                CHAR_NOT_NUMBER   The Value is not a number
 */
static bool is_num(char x);
/*
 * @Brief     : Checks if the charachter is an operation or not
 * @Parameter : Char to check
 * @return    : returns the state
 *                                CHAR_IS_OP    The value is actually an operation
 *                                CHAR_NOT_OP   The Value is not an operation
 */
static bool is_op(char x);
/*
 * @Brief     : Checks if the charachter is a power operation (**) or not
 * @Parameter : string to check (check for 2 charachters making sure not to segfault)
 * @return    : returns the state
 *                                CHAR_IS_POW    The value is actually a Power Operation
 *                                CHAR_NOT_POW   The Value is not a Power Operation
 */
static bool is_power(char *x);
/*
 * @Brief : Function Takes two numbers and perform an operation on them
 * @Parameter float32 n1: First Number
 * @Parameter float32 n2: Second Number
 * @Parameter Char  op: operation to perform on float32s
 * @Return    float32 : return value n1 op n2
 */
static float32 Calculate(float32 n1,float32 n2,char op);
/*============================================================================*/

/*=========================== Function Definitions ===========================*/
/*
 *@ Brief     : Completely Handles the operations in the string.
 *@ Parameter : Takes a string of mathematical operations.
 *@ Return    : returns the result of these mathematical operations.
 */
float32 HandleString(char * str){
    /*Holds the value of the previous char in the string and it's used to check if it was an op or number*/
    char prev_char = 0;
    /*Indeicates that a number was captured so that the string can continue until it hits an op*/
    unsigned char numberCaught = NUMBER_NOT_CAUGHT;
    /*Indicates that the first number has been caught*/
    unsigned char FIRST_NUM = 1;
    /*Idicates the current operation*/
    char op = 0;
    /*Indicates the next operation*/
    char op2 = 0;
    /*A value that change the operation if a power operation is caught*/
    char op_Handle_Power=0;
    /*Indicates that the second operation has priority over the first operation*/
    bool president_flag = 0;
    /*A temporary value to save the first number in case of second operation priority*/
    float32 temp = 0;
    /*Variable to hold the first number which is the return value*/
    float32 num1 = 0;
    /*Variable to Hold the Second number*/
    float32 num2 = 0;

    /*Handle The case where the first elemnt of the string is a +- sign */
    if((*str == '-')||(*str == '+')){
        FIRST_NUM = 0;
        numberCaught = NUMBER_CAUGHT;
    }


    while(*str){
        /*Capture Number Value*/
        if(numberCaught == NUMBER_NOT_CAUGHT){
            numberCaught = NUMBER_CAUGHT;
            if(FIRST_NUM){
                FIRST_NUM = 0;
                num1 = atof(str);
            }
            else{
                num2 = atof(str);
            }
        }
        /*if number is captured check for the next operation*/
        else if(is_op(*str)){
            /*Check if that operations is a power operation (**) */
            if(is_power(str)){
                /* if it's a power operation then the value of op is a dot char */
                op_Handle_Power = '.';
                str++;
            }
            else{
                op_Handle_Power = *str;
            }


            /******* Handle the operation *******/

            /*if previous operation has priority*/
            if(president_flag){
                num2=Calculate(num1,num2,op2);
                num1 = temp;
                president_flag = 0;
            }

            /*if this is not the first operation check for priority*/
            if(op!=0){
                op2=op_Handle_Power;
                /*Higher priority Go cature next number*/
                 if(
                    (((op2 == '*') || (op2 == '/')) && (op != '.') && (op !='*') && (op != '/'))
                     ||
                    (op2 == '.')
                    ){
                    temp = num1;
                    num1 = num2;
                    president_flag = 1;
                }
                /*Equal or lower priority calculate*/
                else{
                    num1 = Calculate(num1,num2,op);
                    op = op_Handle_Power;
                }
            }
            /*if this is the first operation capture it and go capture next number*/
            else{
                op = op_Handle_Power;
            }
            /*Indicate that you are waiting on a number*/
            numberCaught = NUMBER_NOT_CAUGHT;
        }
        /*Save value of previous char*/
        prev_char = *str;
        str++;
    }
    /*------- Last calculation -------*/
    if(op){
        if(president_flag){
            num2=Calculate(num1,num2,op2);
            num1 = temp;
        }
        num1 = Calculate(num1,num2,op);
    }

    return num1;
}


/*
 * @ Brief : This Function Takes a string of mathematical operations and finds if it has a syntax error
 * @ Parameter char string of the mathematical operations
 * @ return  Error state :
 *                        SYNTAX_ERROR    : string is not ready for mathematical operations
 *                        NO_SYNTAX_ERROR : string has no syntax error and is ready for mathematical operations
 */
bool SyntaxErr(char * str){

    int length = strlen(str);

    if
    (
        (!is_num(*str))
        &&
        (*str != '-')
        &&
        (*str != '+')
        &&
        (*str != '.')
    ){
        return SYNTAX_ERROR;
    }

    if((!is_num(str[length-1])) && (str[length-1]!='.'))
    {
        return SYNTAX_ERROR;
    }
    char *temp = str;
    while(*str)
    {
        if(*str == '/'){
            temp++;
            if(*temp){
                if((*temp=='*')||(*temp == '/')){
                    return SYNTAX_ERROR;
                }
            }
        }
        if(*str == '.'){
            temp++;
            while(*temp){
                if(*temp=='.'){
                    return SYNTAX_ERROR;
                }
                if(is_op(*temp)){
                    break;
                }
                temp++;
            }
        }
        
        if((*str == '+')||(*str == '-')){
            temp++;
            if(*temp){
                if(is_op(*temp)){
                    return SYNTAX_ERROR;
                }
            }
        }
        
        if(*str == '*'){
            if(is_power(str)){
                temp++;
                temp++;
                if(*temp){
                if((*temp=='*')||(*temp == '/')){
                    return SYNTAX_ERROR;
                    }
                }
            }
            else{
                temp++;
                if(*temp){
                    if(*temp == '/'){
                        return SYNTAX_ERROR;
                    }
                }
            }
        }

        if((!is_num(*str))&&(!is_op(*str))&&(*str!='.')){
            return SYNTAX_ERROR;
        }
        str++;
        temp = str;
    }
    return NO_SYNTAX_ERROR;
}

/*
 * @ Brief : This Function Takes a string of mathematical operations and finds if it has a mathematical error
 * @ Parameter char string of the mathematical operations
 * @ return  Error state :
 *                        MATH_ERROR    : string has a mathematical problem and should not be calculated
 *                        NO_MATH_ERROR : string has no math error and is ready for mathematical operations
 */
bool MathError(char * str){
    char *temp = str;
    while(*str){
        if(*str=='/'){
            temp++;
            if(*temp){
                if((*temp == '0')||(*temp == '.')){
                    return MATH_ERROR;
                }
            }
        }
        if(*str == '0'){
            temp++;
            if(is_power(temp)){
                temp++;
                temp++;
                if(*str){
                    if(atoi(temp)<=0)
                    {
                        return MATH_ERROR;
                    }
                }
            }
        }
        str++;
        temp = str;
    }
    return NO_MATH_ERROR;
}
/*============================================================================*/
/*===================== Static Functions Definitions =========================*/
/*
 * @Brief     : Checks if the charachter is a number or not
 * @Parameter : Char to check
 * @return    : returns the state
 *                                CHAR_IS_NUMBER    The value is actually a number
 *                                CHAR_NOT_NUMBER   The Value is not a nmber
 */
static bool is_num(char x){
    if((x >= '0') && (x <= '9')){
        return CHAR_IS_NUMBER;
    }
    return CHAR_NOT_NUMBER;
}

/*
 * @Brief     : Checks if the charachter is an operation or not
 * @Parameter : Char to check
 * @return    : returns the state
 *                                CHAR_IS_OP    The value is actually an operation
 *                                CHAR_NOT_OP   The Value is not an operation
 */
static bool is_op(char x){
    if((x=='-')||(x=='+')||(x=='*')||(x=='/')){
        return CHAR_IS_OP;
    }
    return CHAR_NOT_OP;
}

/*
 * @Brief     : Checks if the charachter is a power operation (**) or not
 * @Parameter : string to check (check for 2 charachters making sure not to segfault)
 * @return    : returns the state
 *                                CHAR_IS_POW    The value is actually a Power Operation
 *                                CHAR_NOT_POW   The Value is not a Power Operation
 */
static bool is_power(char *x){
    char *temp = x;
    if(temp != NULL){
        if(*temp == '*'){
            temp++;
            if(temp!=NULL){
                if(*temp =='*'){
                    return CHAR_IS_POW;
                }
            }
        }
    }
    return CHAR_NOT_POW;
}

/*
 * @Brief : Function Takes two numbers and perform an operation on them
 * @Parameter float32 n1: First Number
 * @Parameter float32 n2: Second Number
 * @Parameter Char  op: operation to perform on float32s
 * @Return    float32 : return value n1 op n2
 */
static float32 Calculate(float32 n1,float32 n2,char op){
    switch (op)
    {
    case '+':
        return (n1+n2);
        break;
    case '-':
        return (n1-n2);
        break;
    case '*':
        return (n1*n2);
        break;
    case '/':
        return (n1/n2);
        break;
    case '.':
        return pow(n1,n2);
    default:
        break;
    }
    return 0;
}

/*============================================================================*/