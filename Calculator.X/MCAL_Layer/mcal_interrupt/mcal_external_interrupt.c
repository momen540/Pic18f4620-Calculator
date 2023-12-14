/* 
 * File:   mcal_external_interrupt.c
 * Author: Mo'men Ahmed
 *
 * Created on August 9, 2023, 11:26 AM
 */

#include "mcal_external_interrupt.h"
#ifdef USE_INTERRUPT
/*************************** Helper functions declarations ********************************/

/*============= Interrupt Handlers for External interrupts =============*/
static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;

/*======== Interrupt Handlers for External On change interrupts ========*/
static InterruptHandler RB4_InterruptHighHandler = NULL;
static InterruptHandler RB4_InterruptLowHandler = NULL;
static InterruptHandler RB5_InterruptHighHandler = NULL;
static InterruptHandler RB5_InterruptLowHandler = NULL;
static InterruptHandler RB6_InterruptHighHandler = NULL;
static InterruptHandler RB6_InterruptLowHandler = NULL;
static InterruptHandler RB7_InterruptHighHandler = NULL;
static InterruptHandler RB7_InterruptLowHandler = NULL;

/*========= Functions to set Handlers for External interrupts ==========*/
static Std_ReturnType INT0_SetHandler(void(*InterruptHandler)(void));
static Std_ReturnType INT1_SetHandler(void(*InterruptHandler)(void));
static Std_ReturnType INT2_SetHandler(void(*InterruptHandler)(void));
static Std_ReturnType INTx_SetHandler(const INTx_t * pin);


static Std_ReturnType INTx_Enable(const INTx_t * pin);
static Std_ReturnType INTx_Disable(const INTx_t * pin);
static Std_ReturnType INTx_Set_Priority(const INTx_t * pin);
static Std_ReturnType INTx_Set_Polarity(const INTx_t * pin);
static Std_ReturnType INTx_Clear_Flag(const INTx_t * pin);

static Std_ReturnType RBx_Set_Priority(const RBx_t * pin);

/************************* End of Helper functions declarations ******************************/

/*=========================== Implementation of ISRs =======================================*/
void INT0_ISR(void)
{
    EXT_INT0_ClearInterrupt_flag();
    if(INT0_InterruptHandler)
    {
        INT0_InterruptHandler();
    }
}
void INT1_ISR(void)
{
    EXT_INT1_ClearInterrupt_flag();
    if(INT1_InterruptHandler)
    {
        INT1_InterruptHandler();
    }
}
void INT2_ISR(void)
{
    EXT_INT2_ClearInterrupt_flag();
    if(INT2_InterruptHandler)
    {
        INT2_InterruptHandler();
    }
}

void RB4_ISR(INTx_Polarity pol)
{
    EXT_RBx_ClearInterrupt_flag();
    if(RisingEdge == pol)
    {
        if(RB4_InterruptHighHandler){
            RB4_InterruptHighHandler();
        }
        else{ /* Nothing */ }
    }
    else if(FallingEdge == pol)
    {
        if(RB4_InterruptLowHandler){
            RB4_InterruptLowHandler();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}
void RB5_ISR(INTx_Polarity pol)
{
    EXT_RBx_ClearInterrupt_flag();
    if(RisingEdge == pol)
    {
        if(RB5_InterruptHighHandler){
            RB5_InterruptHighHandler();
        }
        else{ /* Nothing */ }
    }
    else if(FallingEdge == pol)
    {
        if(RB5_InterruptLowHandler){
            RB5_InterruptLowHandler();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}
void RB6_ISR(INTx_Polarity pol)
{
    EXT_RBx_ClearInterrupt_flag();
    if(RisingEdge == pol)
    {
        if(RB6_InterruptHighHandler){
            RB6_InterruptHighHandler();
        }
        else{ /* Nothing */ }
    }
    else if(FallingEdge == pol)
    {
        if(RB6_InterruptLowHandler){
            RB6_InterruptLowHandler();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}
void RB7_ISR(INTx_Polarity pol)
{
    EXT_RBx_ClearInterrupt_flag();
    if(RisingEdge == pol)
    {
        if(RB7_InterruptHighHandler){
            RB7_InterruptHighHandler();
        }
        else{ /* Nothing */ }
    }
    else if(FallingEdge == pol)
    {
        if(RB7_InterruptLowHandler){
            RB7_InterruptLowHandler();
        }
        else{ /* Nothing */ }
    }
}
/*======================================================================================================*/

/*==================================== Module Function definitions =====================================*/
/**
 * Function to initialize external interrupt on INTx Pins
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType INTx_interrupt_init(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        /*Disable External interrupt*/
        ret &= (INTx_Disable(pin));
        /*Clear External interrupt flag*/
        ret &= (INTx_Clear_Flag(pin));
        /*Set External Interrupt polarity*/
        ret &= (INTx_Set_Polarity(pin));
        /*Select Priority if enabled*/
        ret &= (INTx_Set_Priority(pin));
        /* Configure External interrupt I/O pin */
        ret &= (GPIO_pin_dir_init(&(pin->pin))); 
        /*Configure Default interrupt callback*/
        INTx_SetHandler(pin);
        /*Enable External interrupt*/
        ret &= ret & (INTx_Enable(pin));
    }
    return ret;
}

/**
 * Function to De-initialize external interrupt on INTx Pins
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType INTx_interrupt_deinit(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        /*Disable external interrupt*/
        ret = ret & (INTx_Disable(pin));
    }
    return ret;
}

/**
 * Function to initialize external interrupt on RBx Pins
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType RBx_interrupt_init(const RBx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        /*Disable RB interrupt*/
        EXT_RBx_Interrupt_Disable();
        EXT_RBx_ClearInterrupt_flag();
        ret &= (RBx_Set_Priority(pin));
        ret &= (GPIO_pin_dir_init(&(pin->pin)));
        switch(pin->pin.Pin)
        {
            case PIN4:
                RB4_InterruptHighHandler = pin->Ext_InterruptHighHandler;
                RB4_InterruptLowHandler = pin->Ext_InterruptLowHandler;
                break;
            case PIN5:
                RB5_InterruptHighHandler = pin->Ext_InterruptHighHandler;
                RB5_InterruptLowHandler = pin->Ext_InterruptLowHandler;
                break;
            case PIN6:
                RB6_InterruptHighHandler = pin->Ext_InterruptHighHandler;
                RB6_InterruptLowHandler = pin->Ext_InterruptLowHandler;
                break;
            case PIN7:
                RB7_InterruptHighHandler = pin->Ext_InterruptHighHandler;
                RB7_InterruptLowHandler = pin->Ext_InterruptLowHandler;
                break;
            default :ret = E_NOT_OK;
        }
        EXT_RBx_Interrupt_En();
    }
    return ret;
}


/**
 * Function to De-initialize external interrupt on RBx Pins
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
Std_ReturnType RBx_interrupt_deinit(const RBx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        
    }
    return ret;
}
/*======================================= End of Module Function definitions ==========================================*/

/*======================================== Helper Function Definition section =========================================*/
/**
 * Function to Enable external interrupt peripheral on INTx Pin
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType INTx_Enable(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        switch(pin->source)
        {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_ENABLE();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_ENABLE();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_ENABLE();
                break;      
            default: ret=E_NOT_OK;
        }
    }
    return ret;    
}

/**
 * Function to Disable external interrupt peripheral on INTx Pin
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType INTx_Disable(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        switch(pin->source)
        {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_DISABLE();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_DISABLE();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_DISABLE();
                break;
            default: ret=E_NOT_OK;
        }       
    }
    return ret;    
}

/**
 * Function to set interrupt edge polarity for INTx Pin
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType INTx_Set_Polarity(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        switch(pin->source)
        {
            case EXT_INT0:
                if(RisingEdge==pin->edge)
                {
                    EXT_INT0_set_RisingEdge();
                }
                else if(FallingEdge==pin->edge)
                {
                    EXT_INT0_set_FallingEdge();
                }
                else{}
                break;
            case EXT_INT1:
                if(RisingEdge==pin->edge)
                {
                    EXT_INT1_set_RisingEdge();
                }
                else if(FallingEdge==pin->edge)
                {
                    EXT_INT1_set_FallingEdge();
                }
                else{}
                break;
            case EXT_INT2:
                if(RisingEdge==pin->edge)
                {
                    EXT_INT2_set_RisingEdge();
                }
                else if(FallingEdge==pin->edge)
                {
                    EXT_INT2_set_FallingEdge();
                }
                else{}
                break;
            default: ret=E_NOT_OK;            
        }   
    }
    return ret;
}

/**
 * Function to clear interrupt flag for INTx Pin
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType INTx_Clear_Flag(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        switch(pin->source)
        {
            case EXT_INT0:
                EXT_INT0_ClearInterrupt_flag();
                break;
            case EXT_INT1:
                EXT_INT1_ClearInterrupt_flag();
                break;
            case EXT_INT2:
                EXT_INT2_ClearInterrupt_flag();
                break;
            default: ret=E_NOT_OK;
        }       
    }
    return ret; 
}
/**
 * Function to set interrupt priority for INTx pin
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType INTx_Set_Priority(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        #ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        switch(pin->source)
        {
            case EXT_INT0:
                /*Do nothing*/
                break;
            case EXT_INT1:
                
                if(pin->priority == Low_Priority)
                {
                    EXT_INT1_set_LowPriority();
                }
                
                else if(pin->priority == High_Priority)
                {
                    EXT_INT1_set_HighPriority();
                }
                
                else{/*Do Nothing*/}
                
                break;
                
            case EXT_INT2:
                
                if(pin->priority == Low_Priority)
                {
                    EXT_INT2_set_LowPriority();
                }
                
                else if(pin->priority == High_Priority)
                {
                    EXT_INT2_set_HighPriority();
                }
                
                else{/*Do Nothing*/}
                
                break;
                default: ret=E_NOT_OK;
        }
        #endif
    }
    return ret;
}

/**
    * Function sets callback for external interrupt INT0
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */

static Std_ReturnType INT0_SetHandler(void(*InterruptHandler)(void))
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=InterruptHandler)
    {
        ret=E_OK;
        INT0_InterruptHandler=InterruptHandler;
    }
    return ret;
}

/**
 * Function sets callback for external interrupt INT1
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */

static Std_ReturnType INT1_SetHandler(void(*InterruptHandler)(void))
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=InterruptHandler)
    {
        ret=E_OK;
        INT1_InterruptHandler=InterruptHandler;
    }
    return ret;   
}


/**
 * Function sets callback for external interrupt INT2
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType INT2_SetHandler(void(*InterruptHandler)(void))
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=InterruptHandler)
    {
        ret=E_OK;
        INT2_InterruptHandler=InterruptHandler;
    }
    return ret;    
}
/**
 * Function sets callback for external interrupt INTx
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */

static Std_ReturnType INTx_SetHandler(const INTx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
        switch(pin->source)
        {
            case EXT_INT0:ret = INT0_SetHandler(pin->Ext_InterruptHandler);
                break;
            case EXT_INT1:ret = INT1_SetHandler(pin->Ext_InterruptHandler);
                break;
            case EXT_INT2:ret = INT2_SetHandler(pin->Ext_InterruptHandler);
                break;
            default: ret=E_NOT_OK;
        }        
    }    
    return ret;
}

/**
 * Function set priority for interrupt on RBx Pin
 * @param pin
 * @return status of the function
 *         (E_OK)         Success.
 *         (E_NOT_OK)     Error
 */
static Std_ReturnType RBx_Set_Priority(const RBx_t * pin)
{
    Std_ReturnType ret=E_NOT_OK;
    if(NULL!=pin)
    {
        ret=E_OK;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        switch(pin->priority)
        {
            case Low_Priority :
                EXT_RBx_Low_Priority();
                break;
            case High_Priority :
                EXT_RBx_High_Priority();
                break;
            default :ret=E_NOT_OK;
        }
#endif
    }   
    return ret;    
}

/*=====================================End of Helper Function Definition section ======================================*/
#endif