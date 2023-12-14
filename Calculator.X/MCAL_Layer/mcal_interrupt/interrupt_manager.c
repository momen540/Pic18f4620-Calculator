/* 
 * File:   interrupt_manager.c
 * Author: Mo'men Ahmed
 *
 * Created on August 9, 2023, 2:21 PM
 */

#include "interrupt_manager.h"
#ifdef USE_INTERRUPT
/**************************************************/

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
void __interrupt() InterruptManangerHigh(void)
{
#ifdef EXTERNAL_INTERRUPT_ENABLE
    if((INTERRUPT_ENABLED == INTCONbits.INT0IE)&&((INTERRUPT_OCCURED == INTCONbits.INT0F)))
    {
        INT0_ISR(); 
    }
    else{/*Do Nothing*/}
    if((INTERRUPT_ENABLED == INTCON3bits.INT1IE)&&((INTERRUPT_OCCURED == INTCON3bits.INT1F)))
    {
        INT1_ISR(); 
    }
    else{/*Do Nothing*/}
#endif
}
#else
void __interrupt() InterruptMananger(void)
{
#ifdef EXTERNAL_INTERRUPT_ENABLE
    if((INTERRUPT_ENABLED == INTCONbits.INT0IE)&&((INTERRUPT_OCCURED == INTCONbits.INT0F)))
    {
        INT0_ISR(); 
    }
    else{/*Do Nothing*/}
    if((INTERRUPT_ENABLED == INTCON3bits.INT1IE)&&((INTERRUPT_OCCURED == INTCON3bits.INT1F)))
    {
        INT1_ISR(); 
    }
    else{/*Do Nothing*/}
#endif
}


#endif //priority levels

#endif //use interrupt