/* 
 * File:   hal_I2C.h
 * Author: Lenovo
 *
 * Created on October 4, 2023, 2:03 PM
 */

#ifndef HAL_I2C_H
#define	HAL_I2C_H

/*============================== Includes section ============================*/
#include "../mcal_interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_gpio.h"
/*============================================================================*/


/*================================= Macros ===================================*/
/*I2C_Roles*/
#define I2C_MASTER                                                           (1)
#define I2C_SLAVE                                                            (0)
#define I2C_SLAVE_READ                                                       (0)
#define I2C_SLAVE_WRITE                                                      (1)
/***********/
#define MSSP_I2C_MODE_SELECT(_I2C)              (SSPCON1bits.SSPM = (uint8)_I2C)
#define I2C_SEND_START()                        (SSPCON2bits.SEN=1)
#define I2C_SEND_STOP()                         (SSPCON2bits.PEN=1)
#define I2C_SEND_REPEATED_START()               (SSPCON2bits.RSEN=1)

#define I2C_ACK_RECEIVED                                                     (0)
#define I2C_NACK_RECEIVED                                                    (1)
#define I2C_ACK_SENT                                                         (0)
#define I2C_NACK_SENT                                                        (1)

/*Stop condition indication*/
#define I2C_STOP_BIT_DETECTED                                                (1)
#define I2C_STOP_BIT_NOT_DETECTED                                            (0)
/*Start condition indication*/
#define I2C_START_BIT_DETECTED                                               (1)
#define I2C_START_BIT_NOT_DETECTED                                           (0)

/*Enable/Disable __MSSP__*/
#define MSSP_I2C_ENABLED                                                     (1)
#define MSSP_I2C_DISABLED                                                    (0)
#define MSSP_I2C_ENABLE()                           (SSPCON1bits.SSPEN=MSSP_I2C_ENABLED)
#define MSSP_I2C_DISABLE()                          (SSPCON1bits.SSPEN=MSSP_I2C_DISABLED)

/*Enable/Disable __SlewRate__*/
#define MSSP_I2C_SLEW_RATE_ENABLED                                           (0)
#define MSSP_I2C_SLEW_RATE_DISABLED                                          (1)
#define MSSP_I2C_SLEW_RATE_ENABLE()                 (SSPSTATbits.SMP=MSSP_I2C_SLEW_RATE_ENABLED)
#define MSSP_I2C_SLEW_RATE_DISABLE()                (SSPSTATbits.SMP=MSSP_I2C_SLEW_RATE_DISABLED)
/*Enab/Disable __SMBUS__*/
#define MSSP_I2C_SMBUS_ENABLED                                               (1)
#define MSSP_I2C_SMBUS_DISABLED                                              (0)
#define MSSP_I2C_SMBUS_ENABLE()                     (SSPSTATbits.CKE=MSSP_I2C_SMBUS_ENABLED)
#define MSSP_I2C_SMBUS_DISABLE()                    (SSPSTATbits.CKE=MSSP_I2C_SMBUS_DISABLED)

/*__General_Call__*/
#define MSSP_I2C_GENERAL_CALL_ENABLED                                        (1)
#define MSSP_I2C_GENERAL_CALL_DISABLED                                       (0)
#define MSSP_I2C_GENERAL_CALL_ENABLE()              (SSPCON2bits.GCEN=MSSP_I2C_GENERAL_CALL_ENABLED)
#define MSSP_I2C_GENERAL_CALL_DISABLE()             (SSPCON2bits.GCEN=MSSP_I2C_GENERAL_CALL_DISABLED)

/*__Master_Receive__*/
#define MSSP_I2C_MASTER_RECEIVE_ENABLED                                      (1)
#define MSSP_I2C_MASTER_RECEIVE_DISABLED                                     (0)
#define MSSP_I2C_MASTER_RECEIVE_ENABLE()            (SSPCON2bits.RCEN=MSSP_I2C_MASTER_RECEIVE_ENABLED)
#define MSSP_I2C_MASTER_RECEIVE_DISABLE()           (SSPCON2bits.RCEN=MSSP_I2C_MASTER_RECEIVE_DISABLED)
#define I2C_MASTER_SEND_ACK()                       (SSPCON2bits.ACKDT = I2C_ACK_SENT);\
                                                    (SSPCON2bits.ACKEN = 1)              //Start ACK Sequenceo= on SDA Line
#define I2C_MASTER_SEND_NACK()                      (SSPCON2bits.ACKDT = I2C_NACK_SENT);\
                                                    (SSPCON2bits.ACKEN = 1)              //Start ACK Sequenceo= on SDA Line


#define MSSP_I2C_SLAVE_CLOCK_RELEASE()              (SSPCON1bits.CKP=1)
#define MSSP_I2C_SLAVE_CLOCK_STRETCH()              (SSPCON1bits.CKP=0)

#define MSSP_I2C_SLAVE_CLEAR_COLLISION_BIT()        (SSPCON1bits.WCOL=0)
#define MSSP_I2C_RECEIVE_OVF_CLEAR()                (SSPCON1bits.SSPOV=0)
#define MSSP_I2C_SLAVE_RELEASE_CLOCK()              (SSPCON1bits.CKP=0)
/*============================================================================*/


/*========================== User defined data types =========================*/
/*
 *Enumeration for I2C Modes
 */
typedef enum{
    I2C_Slave_10Bit_Interrupt=15,/*
                                  * Slave mode 10 Bit address with interrupt
                                  */
    I2C_Slave_7Bit_Interrupt=14, /*
                                  * Slave mode 7 Bit address with interrupt
                                  */
    I2C_Firmware_Master=11,      /*
                                  * Firmware Master Mode
                                  */
    I2C_Master_Mode=8,           /*
                                  * I2C Master Mode Generating frequency of :
                                  * @Frequency  F = FOSC/(4*(SSPAD+1))
                                  */
    I2C_Slave_10Bit=7,           /*
                                  * Slave mode 10 Bit address with no interrupt
                                  */
    I2C_Slave_7Bit=6             /*
                                  * Slave mode 7 Bit address with no interrupt
                                  */
}MSSP_I2C_mode_t;

typedef struct{
#ifdef MSSP_I2C_INTERRUPT_FEATURE
    void(*I2C_DefaultInterruptHandler)(void);
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority_cfg      I2C_Priority;
#endif
#endif
#ifdef MSSP_I2C_BUS_COL_INTERRUPT_FEATURE
    void(*I2C_BusCol_InterruptHandler)(void);
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority_cfg      I2C_BusCol_Priority;
#endif
#endif
    MSSP_I2C_mode_t  I2C_Mode;        /*
                                       * Selects I2C Mode
                                       * @Ref MSSP_I2C_mode_t
                                       */
    uint32 I2C_Frequency;              /*
                                        * Value of i2c Frequency 
                                        * 100 KHZ (Standard)
                                        * 400 KHZ (Fast)
                                        */
    uint16 I2C_SlaveAddress;           /*
                                        * Slave address in case of Slave mode
                                        */
    uint8  I2C_SlewRate :1;            /*
                                        * Enable/Disable Slew Rate
                                        * @ref __SlewRate__
                                        */
    uint8  I2C_Role :1;                /*
                                        * Selects role of i2c
                                        * @ref I2C_Roles
                                        */
    uint8  I2C_SMBus               :1; /*
                                        * Enable/Disable SMBus
                                        * @ref __SMBUS__
                                        */
    uint8  I2C_GeneralCall         :1; /*
                                        * Enable/Disable General Call
                                        * @ref __General_Call__
                                        */
    uint8  I2C_MasterReceive       :1; /*
                                        * Enable/Disable Master Receive mode
                                        * @ref __Master_Receive__
                                        */
    uint8  I2C_Reserved            :2; /*
                                        * Reserved for future use
                                        */ 
                                       
}mssp_i2c_t;
/*============================================================================*/


/*======================= Software interfaces Declarations ===================*/
/**
 * @summary Initialize i2c module in Master/Receive module with interrupt configuration
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_init(const mssp_i2c_t * _i2c);
/**
 * @summary : Disables I2C Module and interrupt features
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_deinit(const mssp_i2c_t * _i2c);
/**
 * @summary : Sends a start condition on the i2c buses.
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t * _i2c);
/**
 * @summary : Sends a repeated start condition on the i2c buses.
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t * _i2c);
/**
 * @summary : Sends a Stop condition on the i2c buses.
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t * _i2c);
/**
 * @summary : Sends Data on i2c line and reads acknowledge state
 * @NOTE :This function blocks the code
 * @param _i2c : pointer to i2c configuration object
 * @param Data : Data required to be sent on i2c lines
 * @param ACK_State : pointer to acknowledge state received by the slave
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t * _i2c,uint8 Data,uint8 * ACK_State);
/*
 * @Brief       : Function Transmits Length Bytes of str over the I2C Bus to selected slave address.
 * @Paramaeter  : _i2c configuration pointer
 * @Parameter   : Address 8Bit Slave address
 * @Parameter   : Length Length of data to send
 * @Parameter   : str array of data to send
 * @Parameter   : ACK_State acknowledge state of slave.
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 * @NOTE :This function blocks the code
 */
Std_ReturnType I2C_Master_Transmit(const mssp_i2c_t * _i2c,uint8 Address,uint8 Length,uint8 *str,uint8 * ACK_State);
/**
 * @summary : Receives Data in master mode
 * @NOTE :This function blocks the code
 * @param _i2c : pointer to i2c configuration object
 * @param Data : Pointer to Data received by Master
 * @param ACK_State : Acknowledge state to send to the slave
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t * _i2c,uint8 * _Data,uint8 ACK_State);
/*============================================================================*/

#endif	/* HAL_I2C_H */

