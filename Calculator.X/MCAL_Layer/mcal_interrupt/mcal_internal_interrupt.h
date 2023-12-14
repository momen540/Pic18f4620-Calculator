/* 
 * File:   mcal_internal_interrupt.h
 * Author: Mo'men Ahmed
 *
 * Created on August 9, 2023, 11:27 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/*************************************** Include section ******************************************************/
#include "mcal_interrupt_cfg.h"
#include "../GPIO/hal_gpio.h"
/************************************** End of Include section ************************************************/

/************************************** Macro Functions section ***********************************************/

/*============================ ADC Interrupt mactos ==========================*/
#ifdef ADC_INTERRUPT_FEATURE
/*Disables ADC Interrupt*/
#define ADC_Interrupt_Disable()          (PIE1bits.ADIE = 0)
/*Sets ADC Interrupt Enable*/
#define ADC_Interrupt_Enable()           (PIE1bits.ADIE = 1)
/*Clears Interrupt flag */
#define ADC_Clear_Interrupt_Flag()       (PIR1bits.ADIF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define ADC_SetHighPrioity()             (IPR1bits.ADIP=1)
#define ADC_SetLowPriority()             (IPR1bits.ADIP=0)
#endif
#endif

#ifdef TIMER0_INTERRUPT_FEATURE
/*Disables timer 0 Interrupt*/
#define Timer0_Interrupt_Disable()          (INTCONbits.TMR0IE = 0)
/*Sets timer 0 Interrupt Enable*/
#define Timer0_Interrupt_Enable()           (INTCONbits.TMR0IE = 1)
/*Clears Interrupt flag */
#define Timer0_Clear_Interrupt_Flag()       (INTCONbits.TMR0IF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define Timer0_SetHighPrioity()             (INTCON2bits.TMR0IP = 1)
#define Timer0_SetLowPriority()             (INTCON2bits.TMR0IP = 0)
#endif
#endif

#ifdef TIMER1_INTERRUPT_FEATURE
/*Disables timer 1 Interrupt*/
#define Timer1_Interrupt_Disable()          (PIE1bits.TMR1IE = 0)
/*Sets ADC Interrupt Enable*/
#define Timer1_Interrupt_Enable()           (PIE1bits.TMR1IE = 1)
/*Clears Interrupt flag */
#define Timer1_Clear_Interrupt_Flag()       (PIR1bits.TMR1IF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define Timer1_SetHighPrioity()             (IPR1bits.TMR1IP = 1)
#define Timer1_SetLowPriority()             (IPR1bits.TMR1IP = 0)
#endif
#endif

#ifdef TIMER2_INTERRUPT_FEATURE
/*Disables timer 1 Interrupt*/
#define Timer2_Interrupt_Disable()          (PIE1bits.TMR2IE = 0)
/*Sets ADC Interrupt Enable*/
#define Timer2_Interrupt_Enable()           (PIE1bits.TMR2IE = 1)
/*Clears Interrupt flag */
#define Timer2_Clear_Interrupt_Flag()       (PIR1bits.TMR2IF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define Timer2_SetHighPrioity()             (IPR1bits.TMR2IP = 1)
#define Timer2_SetLowPriority()             (IPR1bits.TMR2IP = 0)
#endif
#endif

#ifdef TIMER3_INTERRUPT_FEATURE
/*Disables timer 1 Interrupt*/
#define Timer3_Interrupt_Disable()          (PIE2bits.TMR3IE = 0)
/*Sets ADC Interrupt Enable*/
#define Timer3_Interrupt_Enable()           (PIE2bits.TMR3IE = 1)
/*Clears Interrupt flag */
#define Timer3_Clear_Interrupt_Flag()       (PIR2bits.TMR3IF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define Timer3_SetHighPrioity()             (IPR2bits.TMR3IP = 1)
#define Timer3_SetLowPriority()             (IPR2bits.TMR3IP = 0)
#endif
#endif

#ifdef CCP1_INTERRUPT_FEATURE
/*Disables timer 1 Interrupt*/
#define CCP1_Interrupt_Disable()          (PIE1bits.CCP1IE = 0)
/*Sets ADC Interrupt Enable*/
#define CCP1_Interrupt_Enable()           (PIE1bits.CCP1IE = 1)
/*Clears Interrupt flag */
#define CCP1_Clear_Interrupt_Flag()       (PIR1bits.CCP1IF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define CCP1_SetHighPrioity()             (IPR1bits.CCP1IP = 1)
#define CCP1_SetLowPriority()             (IPR1bits.CCP1IP = 0)
#endif
#endif

#ifdef CCP2_INTERRUPT_FEATURE
/*Disables timer 1 Interrupt*/
#define CCP2_Interrupt_Disable()          (PIE2bits.CCP2IE = 0)
/*Sets ADC Interrupt Enable*/
#define CCP2_Interrupt_Enable()           (PIE2bits.CCP2IE = 1)
/*Clears Interrupt flag */
#define CCP2_Clear_Interrupt_Flag()       (PIR2bits.CCP2IF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define CCP2_SetHighPrioity()             (IPR2bits.CCP2IP = 1)
#define CCP2_SetLowPriority()             (IPR2bits.CCP2IP = 0)
#endif
#endif

#ifdef EUSART_TX_INTERRUPT_FEATURE
/*Disables UART transmission/Reception Interrupt*/
#define EUSART_Tx_Interrupt_Disable()             (PIE1bits.TXIE = 0)
/*Enables UART transmission/Reception Interrupt*/
#define EUSART_Tx_Interrupt_Enable()              (PIE1bits.TXIE = 1)
/*EUSART Priority levels*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EUSART_Tx_SetHighPrioity()             (IPR1bits.TXIP = 1)
#define EUSART_Tx_SetLowPriority()             (IPR1bits.TXIP = 0)
#endif
#endif

#ifdef EUSART_RX_INTERRUPT_FEATURE
/*Disables UART transmission/Reception Interrupt*/
#define EUSART_Rx_Interrupt_Disable()             (PIE1bits.RCIE = 0)
/*Enables UART transmission/Reception Interrupt*/
#define EUSART_Rx_Interrupt_Enable()              (PIE1bits.RCIE = 1)
/*EUSART Priority levels*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EUSART_Rx_SetHighPrioity()             (IPR1bits.RCIP = 1)
#define EUSART_Rx_SetLowPriority()             (IPR1bits.RCIP = 0)
#endif
#endif

#ifdef MSSP_I2C_INTERRUPT_FEATURE
/*Disables I2C transmission/Reception Interrupt*/
#define MSSP_I2C_Interrupt_Disable()                     (PIE1bits.SSPIE = 0)
/*Enables I2C transmission/Reception Interrupt*/
#define MSSP_I2C_Interrupt_Enable()                      (PIE1bits.SSPIE = 1)
/*Clears Interrupt flag */
#define MSSP_I2C_Clear_Interrupt_Flag()                  (PIR1bits.SSPIF = 0)
/*I2C Priority levels*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define MSSP_I2C_SetHighPrioity()                        (IPR1bits.SSPIP = 1)
#define MSSP_I2C_SetLowPriority()                        (IPR1bits.SSPIP = 0)
#endif
#endif

#ifdef MSSP_I2C_BUS_COL_INTERRUPT_FEATURE
/*Disables I2C Bus collision Interrupt*/
#define MSSP_I2C_BUS_COL_Interrupt_Disable()             (PIE2bits.BCLIE = 0)
/*Enables I2C Bus collision Interrupt*/
#define MSSP_I2C_BUS_COL_Interrupt_Enable()              (PIE2bits.BCLIE = 1)
/*Clears Interrupt flag */
#define MSSP_I2C_BUS_COL_Clear_Interrupt_Flag()          (PIR2bits.BCLIF = 0)
/*I2C Bus collision Priority levels*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define MSSP_I2C_BUS_COL_SetHighPrioity()                (IPR2bits.BCLIP = 1)
#define MSSP_I2C_BUS_COL_SetLowPriority()                (IPR2bits.BCLIP = 0)
#endif
#endif

/*============================================================================*/

/********************************** End of Macro Functions section ********************************************/


/**************************************** User Defined Data types *********************************************/

/************************************* End of User Defined Data types *****************************************/


/************************************** Function Declarations section *****************************************/

/*********************************** End of Function Declarations section *************************************/

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

