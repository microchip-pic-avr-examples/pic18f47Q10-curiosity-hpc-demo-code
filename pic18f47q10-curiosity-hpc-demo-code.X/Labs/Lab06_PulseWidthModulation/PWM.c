/**
  Pulse Width Modulation Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    PWM.c

  Summary:
    This is the source file for the PWM lab

  Description:
    This source file contains the code on how the PWM lab works.
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

/**
  Section: Included Files
 */

#include "../../mcc_generated_files/system/system.h"
#include "../../labs.h"

/**
  Section: Local Function Prototypes
 */
void PWM_Output_D5_Enable(void);
void PWM_Output_D5_Disable(void);

/**
  Section: Local Variable Declarations
 */
static uint16_t adcResult;

/*
                             Application    
 */
void PWM(void) {
    if (labState == NOT_RUNNING) {
        LEDs_SetLow();
        PWM_Output_D5_Enable();
        TMR6_Start();

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        adcResult = ADC_ChannelSelectAndConvert(POT_CHANNEL) >> 6;
        //Printing ADC result on Serial port
        printf("ADC Result: %u\n\r", adcResult);
        PWM3_LoadDutyValue(adcResult);
    }

    if (switchEvent) {
        TMR6_Stop();
        PWM_Output_D5_Disable();
        labState = NOT_RUNNING;
    }
}

void PWM_Output_D5_Enable(void) {
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS
    // Set D5 as the output of PWM3
    RA7PPS = 0x07;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
}

void PWM_Output_D5_Disable(void) {
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS
    // Set D5 as GPIO pin
    RA7PPS = 0x00;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS

}
/**
 End of File
 */
