/**
 * TMR6 Generated Driver API Header File
 *
 * @file tmr6.h
 *  
 * @defgroup tmr6 TMR6
 *
 * @brief This file contains deprecated macros or functions for the TMR6 driver.
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

#ifndef TMR6_DEPRECATED_H
#define TMR6_DEPRECATED_H

#warning "The tmr6_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CounterGet API.
 *        The TMR6_Read will be deprecated in the future release. Use TMR6_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR6_Read TMR6_CounterGet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CounterGet API.
 *        The Timer6_Read will be deprecated in the future release. Use Timer6_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Read TMR6_CounterGet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CounterSet API.
 *        The TMR6_Write will be deprecated in the future release. Use TMR6_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR6_Write TMR6_CounterSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_CounterSet API.
 *        The Timer6_Write will be deprecated in the future release. Use Timer6_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Write TMR6_CounterSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodSet API.
 *        The TMR6_PeriodCountSet will be deprecated in the future release. Use TMR6_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR6_PeriodCountSet TMR6_PeriodSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodSet API.
 *        The Timer6_PeriodCountSet will be deprecated in the future release. Use Timer6_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodCountSet TMR6_PeriodSet
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodMatchCallbackRegister API.
 *        The TMR6_OverflowCallbackRegister will be deprecated in the future release. Use TMR6_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR6_OverflowCallbackRegister TMR6_PeriodMatchCallbackRegister
/**
 * @ingroup tmr6
 * @brief Defines the Custom Name for the \ref TMR6_PeriodMatchCallbackRegister API.
 *        The Timer6_OverflowCallbackRegister will be deprecated in the future release. Use Timer6_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_OverflowCallbackRegister TMR6_PeriodMatchCallbackRegister

#endif // TMR6_DEPRECATED_H
/**
 End of File
*/
