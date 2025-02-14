/**
  Interrupt Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Interrupt.c

  Summary:
    This is the source file for the Interrupt lab

  Description:
    This source file contains the code on how the Interrupt lab works.
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
void LAB_ISR(void);

/**
  Section: Local Variable Declarations
 */
static uint8_t rotateReg;

/*
                             Application    
 */
void Interrupt(void) {

    if (labState == NOT_RUNNING) {
        LEDs_SetLow();
        LED_D2_SetHigh();
        
        rotateReg = 1;
       
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        INTERRUPT_TMR0InterruptEnable();
        
        TMR0_OverflowCallbackRegister(LAB_ISR);
        labState = RUNNING;
    }

    if(labState == RUNNING){ 
        // Do nothing. Just wait for an interrupt event 
    }
    
    if (switchEvent) {
        INTERRUPT_TMR0InterruptDisable();
        INTERRUPT_GlobalInterruptDisable();
        INTERRUPT_PeripheralInterruptDisable();
        labState = NOT_RUNNING;
    }
}

void LAB_ISR(void) {    
    //If the last LED has been lit, restart the pattern    
    if (rotateReg == 1) {
        rotateReg = LAST;
    }

    rotateReg >>= 1;
    
    //Check which LED should be lit
    LEDs = (rotateReg << 4);
}
/**
 End of File
 */
