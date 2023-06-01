/**
 * PWM3 Generated Driver API Header File
 *
 * @file pwm3.h
 *
 * @defgroup pwm3 PWM3
 *
 * @brief This file contains the API prototypes for the PWM3 driver.
 *
 * @version PWM3 Driver Version 2.0.3
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PWM3_H
 #define PWM3_H
 
 /**
  * Section: Included Files
  */

 #include <xc.h>
 #include <stdint.h>

 /**
  * Section: Macro Declarations
 */

 #define PWM3_INITIALIZE_DUTY_VALUE    818


/**
 * @ingroup pwm3
 * @brief Initializes the PWM3 interface.
 * @param None.
 * @return None.
 */
 void PWM3_Initialize(void);

 /**
 * @ingroup pwm3
 * @brief Loads the 16-bit duty cycle value.
 * @param uint16_t dutyValue - PWM3 duty cycle value to be loaded.
 * @return None.
 */
 void PWM3_LoadDutyValue(uint16_t dutyValue);
 
 #endif	//PWM3_H
