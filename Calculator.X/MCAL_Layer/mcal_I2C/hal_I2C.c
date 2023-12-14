/* 
 * File:   hal_I2C.c
 * Author: Mo'men EL-hoseiny
 *
 * Created on October 4, 2023, 2:03 PM
 */
/*======================== Helper Functions Declarations =====================*/
#include "hal_I2C.h"
#ifdef MSSP_I2C_INTERRUPT_FEATURE
    static void(*I2C_DefaultInterruptHandler)(void) = NULL ;
    void MSSP_I2C_ISR()
    {
        MSSP_I2C_Clear_Interrupt_Flag();
        if(I2C_DefaultInterruptHandler)
        {
            I2C_DefaultInterruptHandler();
        }
    }
#endif
#ifdef MSSP_I2C_BUS_COL_INTERRUPT_FEATURE
    static void(*I2C_BusCol_InterruptHandler)(void) = NULL ;
    void MSSP_I2C_BUS_COL_ISR()
    {
        MSSP_I2C_BUS_COL_Clear_Interrupt_Flag();
        if(I2C_BusCol_InterruptHandler)
        {
            I2C_BusCol_InterruptHandler();
        }
    }
#endif
static Std_ReturnType MSSP_I2C_Cfg(const mssp_i2c_t * _i2c);
/*
 * @Brief       : Function Configures I2C Settings
 * @Parameter   : Pointer to I2C Configuration
 */
static void Set_I2C_Master_cfg(const mssp_i2c_t * _i2c);
/*
 * @Brief       : Function Configures I2C Settings
 * @Parameter   : Pointer to I2C Configuration
 */
static void Slave_cfg(const mssp_i2c_t * _i2c);
/*
 * @Brief       : Function Initializes interrupt module if precompile configuration is Enabled
 * @Parameter   : Pointer to I2C Configuration
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
static Std_ReturnType I2C_Module_Interrupt_cfg(const mssp_i2c_t * _i2c);
/*============================================================================*/

/**
 * @summary Initialize i2c module in Master/Receive module with interrupt configuration
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_init(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        ret = E_OK;
        /*Disable I2C MSSP Module*/
        MSSP_I2C_DISABLE();
        /* MSSP I2C Mode Configuration */
        ret = MSSP_I2C_Cfg(_i2c);
        /*SlewRate Configurations */
        if(MSSP_I2C_SLEW_RATE_ENABLED == _i2c->I2C_SlewRate){
            MSSP_I2C_SLEW_RATE_ENABLE();
        }
        else if(MSSP_I2C_SLEW_RATE_DISABLED == _i2c->I2C_SlewRate){
            MSSP_I2C_SLEW_RATE_DISABLE();
        }
        else{/*Nothing*/}
        /*SMBus configuration*/
        if(MSSP_I2C_SMBUS_ENABLED == _i2c->I2C_SMBus){
            MSSP_I2C_SMBUS_ENABLE();
        }
        else if(MSSP_I2C_SMBUS_DISABLED == _i2c->I2C_SMBus){
            MSSP_I2C_SMBUS_DISABLE();
        }
        else{/*Nothing*/}
        /*Clear over flow  pit no overflow by default*/
        MSSP_I2C_RECEIVE_OVF_CLEAR();
        /*Interrupt Configuration*/
        ret = I2C_Module_Interrupt_cfg(_i2c);
        /*Enable I2C MSSP Module*/
        MSSP_I2C_ENABLE();
    }
    return ret;
}
/**
 * @summary : Disables I2C Module and interrupt features
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_deinit(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        ret = E_OK;
        MSSP_I2C_DISABLE();
#ifdef MSSP_I2C_INTERRUPT_FEATURE
        MSSP_I2C_Interrupt_Disable();      
#endif
#ifdef MSSP_I2C_BUS_COL_INTERRUPT_FEATURE
        MSSP_I2C_BUS_COL_Interrupt_Disable();
#endif
    }
    return ret;    
}
/**
 * @summary : Sends a start condition on the i2c buses.
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        /*Initiate start condition*/
        I2C_SEND_START();
        /*Wait for start condition to be cleared (Automatically clears by hardware)*/
        while(SSPCON2bits.SEN);
        /*Clear SSPIF Flag*/
        PIR1bits.SSPIF=0;
        /*Check for start condition transmission*/
        if(I2C_START_BIT_DETECTED == SSPSTATbits.S){
            ret = E_OK;
        }
        else{
            ret = E_NOT_OK;
        } 
    }
    return ret;
}
/**
 * @summary : Sends a repeated start condition on the i2c buses.
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        /*Initiate Repeated Start condition*/
        I2C_SEND_REPEATED_START();
        /*Wait for Repeated Start condition to be cleared (Automatically clears by hardware)*/
        while(SSPCON2bits.RSEN);
        /*Clear SSPIF Flag*/
        PIR1bits.SSPIF=0;
        ret = E_OK;
    }
    return ret;
}
/**
 * @summary : Sends a Stop condition on the i2c buses.
 * @param _i2c : pointer to i2c configuration object
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        /*Initiate Stop condition*/
        I2C_SEND_STOP();
        /*Wait for Stop condition to be cleared (Automatically clears by hardware)*/
        while(SSPCON2bits.PEN);
        /*Clear SSPIF Flag*/
        PIR1bits.SSPIF=0;
        /*Check for Stop condition transmission*/
        if(I2C_STOP_BIT_DETECTED==SSPSTATbits.P){
            ret = E_OK;
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}
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
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t * _i2c,uint8 Data,uint8 * ACK_State)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL != _i2c)&&(NULL != ACK_State))
    {
        ret = E_OK;
        /*Load data to register*/
        SSPBUF = Data;
        /*Wait for SSPIF Flag*/
        while(!PIR1bits.SSPIF);
        /*Clear interrupt flag*/
        PIR1bits.SSPIF = 0;
        /*Return acknowledge state*/
        if(I2C_ACK_RECEIVED == SSPCON2bits.ACKDT){
            *ACK_State = I2C_ACK_RECEIVED;
        }
        else{
            *ACK_State = I2C_NACK_RECEIVED;
        }
    }
    return ret;
}

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
 * @NOTE        : This function blocks the code
 */
Std_ReturnType I2C_Master_Transmit(const mssp_i2c_t * _i2c,uint8 Address,uint8 Length,uint8 *str,uint8 * ACK_State){
    Std_ReturnType ret = E_NOT_OK;
    uint8 ack = I2C_NACK_RECEIVED;
    uint8 ctr = 0;
    if((NULL != _i2c)&&(NULL != ACK_State))
    {
        ret = E_OK;
        ret &= ret = MSSP_I2C_Master_Send_Start(_i2c);
        ret &= MSSP_I2C_Master_Write_Blocking(_i2c,Address,&ack);
        while((ctr<Length)&&(ack == I2C_ACK_RECEIVED)){
        ret &= MSSP_I2C_Master_Write_Blocking(_i2c,*str++,&ack);
        ctr++;
        }
        ret = MSSP_I2C_Master_Send_Stop(_i2c);
        *ACK_State = ack;
    }
    return ret;    
}
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
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t * _i2c,uint8 * _Data,uint8 ACK_State)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL != _i2c)&&(NULL != _Data))
    {
        ret = E_OK;
        /*Enable master receive*/
        MSSP_I2C_MASTER_RECEIVE_ENABLE();
        /*Wait for SSPBIF Flag*/
        while(!SSPSTATbits.BF);
        /*Copy Data From buffer register*/
        *_Data = SSPBUF;
        /*Send ACK/NACK to slave*/
        if(I2C_ACK_SENT == ACK_State){
            I2C_MASTER_SEND_ACK();
        }
        else if(I2C_NACK_SENT == ACK_State){
            I2C_MASTER_SEND_NACK();
        }
        else{/*Nothing*/}
        while(SSPCON2bits.ACKEN); /* Automatically cleared by hardware */
    }
    return ret;
}

/*======================= Helper Functions Definitions =======================*/
/*
 * @Brief : Function Configures I2C Bits (Hardware) depending on Role(Master Out - Slave In)
 * @Parameter   : Pointer to I2C Configuration
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
static Std_ReturnType MSSP_I2C_Cfg(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        ret = E_OK;
        /*Configure mode in configuration register*/
        MSSP_I2C_MODE_SELECT(_i2c->I2C_Mode);
        
        if(I2C_SLAVE == _i2c->I2C_Role){
            /*I2C Pins are output in master mode*/
            TRISCbits.RC3=0;
            TRISCbits.RC4=0;
            Slave_cfg(_i2c);
        }
        else if(I2C_MASTER == _i2c->I2C_Role){
            /*I2C Pins are input in slave mode*/
            TRISCbits.RC3=1;
            TRISCbits.RC4=1;
            Set_I2C_Master_cfg(_i2c);     
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}
/*
 * @Brief       : Function Configures I2C Settings
 * @Parameter   : Pointer to I2C Configuration
 */
static void Set_I2C_Master_cfg(const mssp_i2c_t * _i2c)
{
    /*Set master clock*/
    SSPADD = (uint8)(((_XTAL_FREQ /4.0) / _i2c->I2C_Frequency)-1);
    /*Enable/Disable master receive mode*/
    if(MSSP_I2C_MASTER_RECEIVE_ENABLED == _i2c->I2C_MasterReceive)
    {
        MSSP_I2C_MASTER_RECEIVE_ENABLE();
    }
    else if(MSSP_I2C_MASTER_RECEIVE_DISABLED == _i2c->I2C_MasterReceive)
    {
        MSSP_I2C_MASTER_RECEIVE_DISABLE();
    }
    else{/*Do Nothing*/}
}
/*
 * @Brief       : Function Configures I2C Settings
 * @Parameter   : Pointer to I2C Configuration
 */
static void Slave_cfg(const mssp_i2c_t * _i2c)
{
    if((I2C_Slave_7Bit_Interrupt == _i2c->I2C_Mode ) ||(I2C_Slave_7Bit == _i2c->I2C_Mode))
    {
        SSPADD = (_i2c->I2C_Frequency & 0x00ff);
    }
    else{
        SSPADD = (_i2c->I2C_Frequency & 0x03FF);
    }
    /*Clear collision bit*/
    MSSP_I2C_SLAVE_CLEAR_COLLISION_BIT();
    /*Release clock line no stretching occurred*/
    MSSP_I2C_SLAVE_RELEASE_CLOCK();
    /*General call Configuration */
    if(MSSP_I2C_GENERAL_CALL_ENABLED == _i2c->I2C_GeneralCall)
    {
        MSSP_I2C_GENERAL_CALL_ENABLE();
    }
    else if(MSSP_I2C_GENERAL_CALL_DISABLED == _i2c->I2C_GeneralCall)
    {
        MSSP_I2C_GENERAL_CALL_DISABLE();
    }
    else{/*Do Nothing*/}
}
/*
 * @Brief       : Function Initializes interrupt module if precompile configuration is Enabled
 * @Parameter   : Pointer to I2C Configuration
 * @return 
 *         E_OK     : Function execution successful.
 *         E_NOT_OK : Function failed to execute successfully.
 */
static Std_ReturnType I2C_Module_Interrupt_cfg(const mssp_i2c_t * _i2c)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _i2c)
    {
        ret = E_OK;
        /* I2C Transmission interrupt configuration */
#ifdef MSSP_I2C_INTERRUPT_FEATURE
        MSSP_I2C_Interrupt_Disable();
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
       if(Low_Priority == I2C_Priority){
           MSSP_I2C_SetLowPriority()
       }
       else{
           MSSP_I2C_SetHighPrioity();
       }
#endif
        I2C_DefaultInterruptHandler = _i2c->I2C_DefaultInterruptHandler;
        MSSP_I2C_Interrupt_Enable();
        MSSP_I2C_Clear_Interrupt_Flag();
#endif
        
        /*I2C Bus collision interrupt configuration*/
#ifdef MSSP_I2C_BUS_COL_INTERRUPT_FEATURE
       MSSP_I2C_BUS_COL_Interrupt_Disable();
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
       if(Low_Priority == I2C_BusCol_Priority){
           MSSP_I2C_BUS_COL_SetLowPriority()
       }
       else{
           MSSP_I2C_BUS_COL_SetHighPrioity();
       }
#endif 
       I2C_BusCol_InterruptHandler = _i2c->I2C_BusCol_InterruptHandler;
       MSSP_I2C_BUS_COL_Interrupt_Enable();
       MSSP_I2C_BUS_COL_Clear_Interrupt_Flag();
#endif
    }
    return ret;    
}