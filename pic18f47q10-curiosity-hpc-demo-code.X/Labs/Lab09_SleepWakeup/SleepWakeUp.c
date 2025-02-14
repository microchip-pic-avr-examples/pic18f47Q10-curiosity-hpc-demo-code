/**
  Sleep Wakeup Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    SleepWakeUp.c

  Summary:
    This is the source file for the Sleep Wakeup lab

  Description:
    This source file contains the code on how the Sleep Wakeup lab works.
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
#define WDT_Enable()        (WDTCON0bits.SWDTEN = 1)
#define WDT_Disable()       (WDTCON0bits.SWDTEN = 0)

/*
                             Application    
 */
void SleepWakeUp(void) {

    if (labState == NOT_RUNNING) {
        LED_D2_LAT = LED_D4_LAT = HIGH;
        LED_D3_LAT = LED_D5_LAT = LOW;

        WDT_Enable();

        SLEEP();

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        //Wait 4 seconds for the WDT time out
        //and reverse the states of the LEDs
        LED_D2_LAT = LED_D4_LAT = LOW;
        LED_D3_LAT = LED_D5_LAT = HIGH;

        WDT_Disable();
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */