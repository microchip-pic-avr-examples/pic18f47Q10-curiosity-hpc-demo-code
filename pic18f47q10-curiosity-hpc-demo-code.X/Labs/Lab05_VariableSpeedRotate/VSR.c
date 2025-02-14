/**
  Variable Speed Rotate Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    VSR.c

  Summary:
    This is the source file for the VSR lab

  Description:
    This source file contains the code on how the VSR lab works.
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
  Section: Local Variable Declarations
 */
static uint8_t delay;
static uint8_t rotateReg;

/*
                             Application    
 */
void VSR(void) {

    if (labState == NOT_RUNNING) {
        LEDs_SetLow();

        //Initialize temporary register to begin at 1
        rotateReg = 1;

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        // Use the top 8 MSbs of the ADC result as delay
        delay = ADC_ChannelSelectAndConvert(POT_CHANNEL) >> 8;
        //Printing ADC result on Serial port
        printf("ADC Result: %u\n\r", ADRES >> 6);
        __delay_ms(2);

        // Decrement the 8 MSbs of the ADC and delay each for 2ms
        while (delay-- != 0) {
            __delay_ms(2);
        }

        //Determine which LED will light up
        LEDs = (rotateReg << 4);

        rotateReg <<= 1;

        //Return to initial position of LED
        if (rotateReg == LAST) {
            rotateReg = 1;
        }
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
