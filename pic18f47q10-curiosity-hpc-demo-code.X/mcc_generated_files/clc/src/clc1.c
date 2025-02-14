/**
 * CLC1 Generated Driver File.
 * 
 * @file clc1.c
 * 
 * @ingroup  clc1
 * 
 * @brief This file contains the API implementations for the CLC1 driver.
 *
 * @version CLC1 Driver Version 1.2.0
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


#include <xc.h>
#include "../clc1.h"


static void (*CLC1_Callback)(void);
static void CLC1_DefaultCallback(void);

void CLC1_Initialize(void) 
{
    
    // LCG1POL not_inverted; LCG2POL inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLC1POL = 0x2;
    // LCD1S TMR4_OUT; 
    CLC1SEL0 = 0x15;
    // LCD2S CLCIN2 (CLCIN2PPS); 
    CLC1SEL1 = 0x2;
    // LCD3S CLCIN2 (CLCIN2PPS); 
    CLC1SEL2 = 0x2;
    // LCD4S CLCIN2 (CLCIN2PPS); 
    CLC1SEL3 = 0x2;
    // LCG1D1N disabled; LCG1D1T enabled; LCG1D2N disabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLC1GLS0 = 0x2;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N disabled; LCG2D2T enabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLC1GLS1 = 0x8;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T enabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLC1GLS2 = 0x8;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T disabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLC1GLS3 = 0x0;
    // LCMODE 1-input D flip-flop with S and R; LCINTN disabled; LCINTP enabled; LCEN enabled; 
    CLC1CON = 0x94;

    //Set default callback for CLC1 interrupt Overflow.
    CLC1_CallbackRegister(CLC1_DefaultCallback);

    // Clear the CLC interrupt flag
    PIR5bits.CLC1IF = 0;
}

void CLC1_Enable(void) 
{
    CLC1CONbits.LC1EN = 1;
}

void CLC1_Disable(void) 
{
    CLC1CONbits.LC1EN = 0;
}

void CLC1_RisingEdgeDetectionEnable(void) 
{
    CLC1CONbits.INTP = 1;
}

void CLC1_RisingEdgeDetectionDisable(void) 
{
    CLC1CONbits.INTP = 0;
}

void CLC1_FallingEdgeDetectionEnable(void) 
{
    CLC1CONbits.INTN = 1;
}

void CLC1_FallingEdgeDetectionDisable(void) 
{
    CLC1CONbits.INTN = 0;
}

void CLC1_CallbackRegister(void (* CallbackHandler)(void))
{
    CLC1_Callback = CallbackHandler;
}

static void CLC1_DefaultCallback(void)
{
    //Add your interrupt code here or
    //Use CLC1_CallbackRegister function to use Custom ISR
}

void CLC1_Tasks(void)
{
    if(PIR5bits.CLC1IF == 1)
    {
        if(CLC1_Callback != NULL)
        {
            CLC1_Callback();
        }
        PIR5bits.CLC1IF = 0;
    }
}


bool CLC1_OutputStatusGet(void) 
{
    return(CLC1CONbits.LC1OUT);
}
/**
 End of File
*/
