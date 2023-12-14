/* 
 * File:   mcal_external_interrupt.h
 * Author: Mo'men Ahmed
 *
 * Created on August 9, 2023, 11:26 AM
 */



#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/*************************************** Include section ******************************************************/
#include "mcal_interrupt_cfg.h"
/************************************** End of Include section ************************************************/

/************************************** Macro Functions section ***********************************************/
#ifdef EXTERNAL_INTERRUPT_ENABLE


/* Enable External interrupt on pin B0*/
#define EXT_INT0_INTERRUPT_ENABLE()      (INTCONbits.INT0E=1)
/* Disable External interrupt on pin B0*/
#define EXT_INT0_INTERRUPT_DISABLE()     (INTCONbits.INT0E=0)
/* Clear interrupt flag on pin B0*/
#define EXT_INT0_ClearInterrupt_flag()   (INTCONbits.INT0IF=0)
/*Set interrupt mode to falling edge on B0*/
#define EXT_INT0_set_FallingEdge()       (INTCON2bits.INTEDG0=0)
/*Set interrupt mode to Rising edge on B0*/
#define EXT_INT0_set_RisingEdge()        (INTCON2bits.INTEDG0=1)


/* Enable External interrupt on pin B1*/
#define EXT_INT1_INTERRUPT_ENABLE()      (INTCON3bits.INT1E=1)
/* Disable External interrupt on pin B1*/
#define EXT_INT1_INTERRUPT_DISABLE()     (INTCON3bits.INT1E=0)
/* Clear interrupt flag on pin B1*/
#define EXT_INT1_ClearInterrupt_flag()   (INTCON3bits.INT1IF=0)
/*Set interrupt mode to falling edge on B1*/
#define EXT_INT1_set_FallingEdge()       (INTCON2bits.INTEDG1=0)
/*Set interrupt mode to Rising edge on B1*/
#define EXT_INT1_set_RisingEdge()        (INTCON2bits.INTEDG1=1)


/* Enable External interrupt on pin B2*/
#define EXT_INT2_INTERRUPT_ENABLE()      (INTCON3bits.INT2E=1)
/* Disable External interrupt on pin B2*/
#define EXT_INT2_INTERRUPT_DISABLE()     (INTCON3bits.INT2E=0)
/* Clear interrupt flag on pin B2*/
#define EXT_INT2_ClearInterrupt_flag()   (INTCON3bits.INT2IF=0)
/*Set interrupt mode to falling edge on B2*/
#define EXT_INT2_set_FallingEdge()       (INTCON2bits.INTEDG2=0)
/*Set interrupt mode to Rising edge on B2*/
#define EXT_INT2_set_RisingEdge()        (INTCON2bits.INTEDG2=1)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE


/* SETS PIN B1 TO HIGH PRIORITY MODE */
#define EXT_INT1_set_HighPriority()      (INTCON3bits.INT1IP=1)
/* SETS PIN B1 TO LOW PRIORITY MODE */
#define EXT_INT1_set_LowPriority()       (INTCON3bits.INT1IP=0)


/* SETS PIN B2 TO HIGH PRIORITY MODE */
#define EXT_INT2_set_HighPriority()      (INTCON3bits.INT2IP=1)
/* SETS PIN B2 TO LOW PRIORITY MODE */
#define EXT_INT2_set_LowPriority()       (INTCON3bits.INT2IP=0)

#endif

#endif

#ifdef EXTERNAL_ON_CHANGE_INTERRUPT_ENABLE

/*Enables on change interrupt on pins B4->B7 */
#define EXT_RBx_Interrupt_En()           (INTCONbits.RBIE=1)
/*Disables on change interrupt on pins B4->B7 */
#define EXT_RBx_Interrupt_Disable()      (INTCONbits.RBIE=0)
/*Clears interrupt flag for on change interrupt on pins B4->B7*/
#define EXT_RBx_ClearInterrupt_flag()    (INTCONbits.RBIF=0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

/* SETS on change interrupt pins TO HIGH PRIORITY MODE */
#define EXT_RBx_High_Priority()          (INTCON2bits.RBIP=1)
/* SETS on change interrupt pins TO LOW PRIORITY MODE */
#define EXT_RBx_Low_Priority()           (INTCON2bits.RBIP=0)

#endif

#endif
/********************************** End of Macro Functions section ********************************************/


/**************************************** User Defined Data types *********************************************/

/*Select external interrupt source*/
typedef enum{
    EXT_INT0,//B0
    EXT_INT1,//B1
    EXT_INT2 //B2
}INTx_Pin;

typedef struct{
    void(*Ext_InterruptHandler)(void);  //callback ISR
    Pin_config_t               pin;     //Interrupt pin @ref Pin_config_t
    INTx_Pin                   source;  //Interrupt source @ref INTx_Pin
    INTx_Polarity              edge;    //Interrupt edge @ref Interrupt_Priority_cfg
    Interrupt_Priority_cfg     priority;//Interrupt priority configuration @ref INTx_Polarity
}INTx_t;

typedef struct{
    void(*Ext_InterruptHighHandler)(void); //Rising edge ISR
    void(*Ext_InterruptLowHandler)(void);  //Falling edge ISR
    Pin_config_t               pin;        //Interrupt pin @ref Pin_config_t
    Interrupt_Priority_cfg     priority;   //Interrupt priority configuration @ref INTx_Polarity
}RBx_t;
/************************************* End of User Defined Data types *****************************************/


/************************************** Function Declarations section *****************************************/
Std_ReturnType INTx_interrupt_init(const INTx_t * pin);
Std_ReturnType INTx_interrupt_deinit(const INTx_t * pin);
Std_ReturnType RBx_interrupt_init(const RBx_t * pin);
Std_ReturnType RBx_interrupt_deinit(const RBx_t * pin);
/*********************************** End of Function Declarations section *************************************/

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

