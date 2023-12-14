/* 
 * File:   mcal_interrupt_cfg.h
 * Author: Mo'men Ahmed
 *
 * Created on August 9, 2023, 11:24 AM
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H
/*************************************** Include section ******************************************************/
#include "mcal_interrupt_gen.h"
#include "../GPIO/hal_gpio.h"
/************************************** End of Include section ************************************************/

/*************************************** Macro Declarations section *******************************************/

#define INTERRUPT_ENABLED              (1)
#define INTERRUPT_DISABLED             (0)
#define INTERRUPT_OCCURED              (1)
#define INTERRUPT_NOT_OCCUR            (0)
/************************************* End of Macro Declarations section **************************************/


/*************************************** Macro function declarations ******************************************/

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE


/*Enable priority levels*/
#define INTERRUPT_PRIORITY_ENABLE           (RCONbits.IPEN=1)
/*Disable priority levels*/
#define INTERRUPT_PRIORITY_DISABLE          (RCONbits.IPEN=0)

/*Macro to enable high priority global interrupt*/
#define ENABLE_GLOBAL_INTERRUPT_HIGH       (INTCONbits.GIEH=1)
/*Macro to disable high priority global interrupt*/
#define DISABLE_GLOBAL_INTERRUPT_HIGH      (INTCONbits.GIEH=0)

/*Macro to enable low priority global interrupts*/
#define ENABLE_GLOBAL_INTERRUPT_LOW    (INTCONbits.GIEL=1)
/*Macro to disable low priority global interrupts*/
#define DISABLE_GLOBAL_INTERRUPT_LOW   (INTCONbits.GIEL=0)
    

#else

/*Enable global interrupts*/
#define ENABLE_GLOBAL_INTERRUPT            (INTCONbits.GIE=1)
/*Disable global interrupts*/
#define DISABLE_GLOBAL_INTERRUPT           (INTCONbits.GIE=0)

/*Macro to enable Peripheral interrupts*/
#define ENABLE_PERIPHERAL_INTERRUPT        (INTCONbits.PEIE=1)
/*Macro to disable Peripheral interrupts*/
#define DISABLE_PERIPHERAL_INTERRUPT       (INTCONbits.PEIE=0)



#endif

/************************************* End of Macro function declarations**************************************/


/***************************************** User defined Data types ********************************************/

/*pointer to void function */
typedef void(*InterruptHandler)(void); 

/*Priority selection Data type*/
typedef enum
{
    Low_Priority,
    High_Priority
}Interrupt_Priority_cfg;
/*Edge selection Data type*/
typedef enum{
    RisingEdge,
    FallingEdge
}INTx_Polarity;
/************************************** End of User defined Data types ****************************************/

#endif	/* MCAL_INTERRUPT_CFG_H */

