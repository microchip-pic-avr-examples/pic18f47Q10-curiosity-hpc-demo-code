/**
  Blink Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Blink.c

  Summary:
    This is the source file for the Blink lab

  Description:
    This source file contains the code on how the Blink lab works.
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
  Section: Macro Declaration
 */
#define FLAG_COUNTER_MAX 3  // Maximum flag count to create 1.5 seconds delay

/**
  Section: Variable Declaration
 */
static uint8_t flagCounter = 0;

/*
                             Application    
 */
void Blink(void) {
    if (labState  == NOT_RUNNING) {
        LEDs_SetLow();
        TMR1_Start();

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        while(!TMR1_HasOverflowOccured());   
        TMR1IF = 0;  
        TMR1_Reload();
        flagCounter++;

        if(flagCounter == FLAG_COUNTER_MAX){       
            LED_D2_Toggle();    
            flagCounter = 0;
        }  
    }

    if (switchEvent) {
        TMR1_Stop();
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
