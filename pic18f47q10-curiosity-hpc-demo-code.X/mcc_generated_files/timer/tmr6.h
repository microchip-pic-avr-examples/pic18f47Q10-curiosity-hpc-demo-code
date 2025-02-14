/**
 * TMR6 Generated Driver API Header File
 *
 * @file tmr6.h
 *  
 * @defgroup tmr6 TMR6
 *
 * @brief This file contains API prototypes and other data types for the TMR6 driver.
 *
 * @version Driver Version 4.0.0
 *
 * @version Package Version 5.0.0
 */
 
/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef TMR6_H
#define TMR6_H

#include <stdint.h>
#include <stdbool.h>
#include "tmr6_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tmr6
 * @brief Defines the TMR6 maximum count value.
 */
#define TMR6_MAX_COUNT (255U)
/**
 * @ingroup tmr6
 * @brief Defines the TMR6 prescaled clock frequency in hertz.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR6_CLOCK_FREQ (125000UL)
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_MAX_COUNT.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TIMER6_MAX_COUNT TMR6_MAX_COUNT
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CLOCK_FREQ.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TIMER6_CLOCK_FREQ TMR6_CLOCK_FREQ
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_Initialize API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Initialize TMR6_Initialize
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_Deinitialize API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Deinitialize TMR6_Deinitialize
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_Start API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Start TMR6_Start
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_Stop API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Stop TMR6_Stop
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CounterGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_CounterGet TMR6_CounterGet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CounterSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_CounterSet TMR6_CounterSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodSet TMR6_PeriodSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_MaxCountGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_MaxCountGet TMR6_MaxCountGet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_ModeSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_ModeSet TMR6_ModeSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_ExtResetSourceSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_ExtResetSourceSet TMR6_ExtResetSourceSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodMatchCallbackRegister API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodMatchCallbackRegister TMR6_PeriodMatchCallbackRegister
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodMatchStatusGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodMatchStatusGet TMR6_PeriodMatchStatusGet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodMatchStatusClear API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodMatchStatusClear TMR6_PeriodMatchStatusClear
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_Tasks API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Tasks TMR6_Tasks

/**
 * @ingroup tmr6
 * @enum TMR6_HLT_EXT_RESET_SOURCE
 * @brief Defines the several modes of timer's operation of the timer with the Hardware Limit Timer (HLT) extension.
 */
typedef enum
{
	/* Roll-over Pulse mode clears the TMRx upon TMRx = PRx, then continue running.
	ON bit must be set and is not affected by Resets
	*/

   /* Roll-over Pulse mode indicates that Timer starts
   immediately upon ON = 1 (Software Control)
   */
   TMR6_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   TMR6_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   TMR6_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   TMR6_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   TMR6_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   TMR6_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   TMR6_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   TMR6_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   TMR6_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   TMR6_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   TMR6_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   TMR6_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   TMR6_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   TMR6_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   TMR6_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   TMR6_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   TMR6_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   TMR6_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   TMR6_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   TMR6_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   TMR6_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} TMR6_HLT_MODE;

/**
 * @ingroup tmr6
 * @enum TMR6_HLT_EXT_RESET_SOURCE
 * @brief Defines the different Reset sources of the HLT.
 */
typedef enum
{
    /*
     * T6INPPS_PIN as the Timer external reset source
     */
    TMR6_T6INPPS_PIN =  0x0,   
    /*
     * TMR2_POSTSCALED as the Timer external reset source
     */
    TMR6_TMR2_POSTSCALED =  0x1,   
    /*
     * TMR4_POSTSCALED as the Timer external reset source
     */
    TMR6_TMR4_POSTSCALED =  0x2,   
    /*
     * CCP1_OUT as the Timer external reset source
     */
    TMR6_CCP1_OUT =  0x4,   
    /*
     * CCP2_OUT as the Timer external reset source
     */
    TMR6_CCP2_OUT =  0x5,   
    /*
     * PWM3_OUT as the Timer external reset source
     */
    TMR6_PWM3_OUT =  0x6,   
    /*
     * PWM4_OUT as the Timer external reset source
     */
    TMR6_PWM4_OUT =  0x7,   
    /*
     * SYNC_C1OUT as the Timer external reset source
     */
    TMR6_SYNC_C1OUT =  0x8,   
    /*
     * SYNC_C2OUT as the Timer external reset source
     */
    TMR6_SYNC_C2OUT =  0x9,   
    /*
     * ZCD_OUT as the Timer external reset source
     */
    TMR6_ZCD_OUT =  0xa,   
    /*
     * EUSART1_DT as the Timer external reset source
     */
    TMR6_EUSART1_DT =  0xc,   
    /*
     * EUSART1_TX_CK as the Timer external reset source
     */
    TMR6_EUSART1_TX_CK =  0xd,   
    /*
     * EUSART2_DT as the Timer external reset source
     */
    TMR6_EUSART2_DT =  0xe,   
    /*
     * EUSART2_TX_CK as the Timer external reset source
     */
    TMR6_EUSART2_TX_CK =  0xf,   
    /*
     * CLC1_OUT as the Timer external reset source
     */
    TMR6_CLC1_OUT =  0x10,   
    /*
     * CLC2_OUT as the Timer external reset source
     */
    TMR6_CLC2_OUT =  0x11,   
    /*
     * CLC3_OUT as the Timer external reset source
     */
    TMR6_CLC3_OUT =  0x12,   
    /*
     * CLC4_OUT as the Timer external reset source
     */
    TMR6_CLC4_OUT =  0x13,   
    /*
     * CLC5_OUT as the Timer external reset source
     */
    TMR6_CLC5_OUT =  0x14,   
    /*
     * CLC6_OUT as the Timer external reset source
     */
    TMR6_CLC6_OUT =  0x15,   
    /*
     * CLC7_OUT as the Timer external reset source
     */
    TMR6_CLC7_OUT =  0x16,   
    /*
     * CLC8_OUT as the Timer external reset source
     */
    TMR6_CLC8_OUT =  0x17   
} TMR6_HLT_EXT_RESET_SOURCE;

/**
  Section: TMR6 APIs
*/

/**
 * @ingroup tmr6
 * @brief Initializes the Timer6 (TMR6) module.
 *        This routine must be called before any other TMR6 routines.
 * @param None.
 * @return None.
 */
void TMR6_Initialize(void);

/**
 * @ingroup tmr6
 * @brief Deinitializes the TMR6 to Power-on Reset (POR) values.
 * @param None.
 * @return None.
 */
void TMR6_Deinitialize(void);

/**
 * @ingroup tmr6
 * @brief Starts the TMR6 timer.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR6_Start(void);

/**
 * @ingroup tmr6
 * @brief Stops the TMR6 timer.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR6_Stop(void);

/**
 * @ingroup tmr6
 * @brief Returns the current counter value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return Current counter value
 */
uint8_t TMR6_CounterGet(void);

/**
 * @ingroup tmr6
 * @brief Sets the counter value for the TMR6 timer.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param count - Counter value to be written to the T6TMR register
 * @return None.
 */
void TMR6_CounterSet(uint8_t count);

/**
 * @ingroup tmr6
 * @brief Sets the period count value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param periodVal - Period count value to be written to the T6PR register
 * @return None.
 */
void TMR6_PeriodSet(uint8_t periodVal);

/**
 * @ingroup tmr6
 * @brief Returns the current period count value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return Period count value from the T6PR register
 */
uint8_t TMR6_PeriodGet(void);

/**
 * @ingroup tmr6
 * @brief Returns the TMR6 maximum count value.
 * @param None.
 * @return Maximum count value of the timer
 */
uint8_t TMR6_MaxCountGet(void);

/**
 * @ingroup tmr6
 * @brief Sets the HLT mode.
 * @pre Initialize TMR6 with TMR6_Initialize() after calling this API.
 * @param mode - Value to be written to the T6HLTbits.MODE bits
 * @return None.
 */
void TMR6_ModeSet(TMR6_HLT_MODE mode);

/**
 * @ingroup tmr6
 * @brief Sets the HLT External Reset source.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param reset - Value to be written to the T6RSTbits.RSEL bits
 * @return None.
 */
void TMR6_ExtResetSourceSet(TMR6_HLT_EXT_RESET_SOURCE reset);

/**
 * @ingroup tmr6
 * @brief Returns the status of the TMR6 Period Match Interrupt flag.
 * @param None.
 * @return Interrupt flag status
 */
bool TMR6_PeriodMatchStatusGet(void);

/**
 * @ingroup tmr6
 * @brief Clears the TMR6 Period Match Interrupt flag.
 * @param None.
 * @return None.
 */
void TMR6_PeriodMatchStatusClear(void);

/**
 * @ingroup tmr6
 * @brief Performs tasks to be executed during the TMR6 period match event.
 * @param None.
 * @return None.
 */
void TMR6_Tasks(void);
/**
 * @ingroup tmr6
 * @brief Registers a callback function for the TMR6 period match event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR6_PeriodMatchCallbackRegister(void (* callbackHandler)(void));

#endif // TMR6_H
/**
 End of File
*/
