/* 
 * File:   interrupt_manager.h
 * Author: Mo'men Ahmed
 *
 * Created on August 9, 2023, 2:21 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

/****************************** Include section *******************************/
#include "mcal_interrupt_cfg.h"
/******************************************************************************/

/*********************** Function Declarations section ************************/

/*======External Interrupts=====*/
void INT0_ISR(void);
void INT1_ISR(void);
/*==============================*/

/******************************************************************************/

#endif	/* INTERRUPT_MANAGER_H */

