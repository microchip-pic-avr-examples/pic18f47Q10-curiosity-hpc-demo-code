 /**
   PWM3 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     pwm3.c
 
   @Summary
     This is the generated driver implementation file for the PWM3 driver.
 
   @Description
     This source file provides APIs for driver for PWM3.
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
 
 /**
   Section: Included Files
 */

 #include <xc.h>
 #include "../pwm3.h"

 /**
   Section: PWM Module APIs
 */

 void PWM3_Initialize(void)
 {
    // Set the PWM to the options selected in the .
    // CTSEL PWM3timer2; 
    CCPTMRS = 0x10;   

    // PWMPOL active_hi; PWMEN enabled; 
    PWM3CON = 0x80;   

    // PWMDCH 204; 
    PWM3DCH = 0xCC;   

    // PWMDCL 2; 
    PWM3DCL = 0x80;   

 }

 void PWM3_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM3DCH = (uint8_t) ((dutyValue & 0x03FCu) >> 2);
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM3DCL = (uint8_t) ((dutyValue & 0x0003u) << 6);
 }
