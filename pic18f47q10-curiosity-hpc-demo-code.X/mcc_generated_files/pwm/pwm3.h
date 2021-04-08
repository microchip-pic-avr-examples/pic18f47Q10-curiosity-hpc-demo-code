 /**
   PWM3 Generated Driver API Header File
 
   @Company
     Microchip Technology Inc. 

   @File Name
    pwm3.h

   @Summary
     This is the generated header file for the PWM3 driver.
 
   @Description
     This header file provides APIs for the PWM3 driver.
     Generation Information :
         Driver Version    :  2.01
     The generated drivers are tested against the following:
         Compiler          :  XC8 v2.20
         MPLAB             :  MPLABX v5.40
 */

/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

#ifndef PWM3_H
 #define PWM3_H
 
 /**
   Section: Included Files
 */

 #include <xc.h>
 #include <stdint.h>

 /**
   Section: Macro Declarations
 */

 #define PWM3_INITIALIZE_DUTY_VALUE    818

 /**
   Section: PWM Module APIs
 */

 /**
   @Summary
     Initializes the PWM3

   @Description
     This routine initializes the PWM3_Initialize
     This routine must be called before any other PWM3 routine is called.
     This routine should only be called once during system initialization.

   @Preconditions
     None

   @Param
     None

   @Returns
     None

   @Comment
     

  @Example
     <code>
     uint16_t dutycycle;

     PWM3_Initialize();
     PWM3_LoadDutyValue(dutycycle);
     </code>
  */
 void PWM3_Initialize(void);

 /**
   @Summary
     Loads 16-bit duty cycle.

   @Description
     This routine loads the 16 bit duty cycle value.

   @Preconditions
     PWM3_Initialize() function should have been called 
         before calling this function.

   @Param
     Pass 16bit duty cycle value.

   @Returns
     None

   @Example
     <code>
     uint16_t dutycycle;

     PWM3_Initialize();
     PWM3_LoadDutyValue(dutycycle);
     </code>
 */
 void PWM3_LoadDutyValue(uint16_t dutyValue);
 
 #endif	//PWM3_H
