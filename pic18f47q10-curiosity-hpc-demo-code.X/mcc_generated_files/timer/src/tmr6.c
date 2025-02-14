/**
 * TMR6 Generated Driver File
 *
 * @file tmr6.c
 * 
 * @ingroup  tmr6
 * 
 * @brief Driver implementation for the TMR6 module.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr6.h"

static void (*TMR6_PeriodMatchCallback)(void);
static void TMR6_DefaultPeriodMatchCallback(void);

/**
  Section: TMR6 APIs
*/

void TMR6_Initialize(void)
{
    T6CLKCON = (1 << _T6CLKCON_T6CS_POSN);  // T6CS FOSC/4

    T6HLT = (0 << _T6HLT_T6MODE_POSN)   // T6MODE Software control
        | (0 << _T6HLT_T6CKSYNC_POSN)   // T6CKSYNC Not Synchronized
        | (0 << _T6HLT_T6CKPOL_POSN)   // T6CKPOL Rising Edge
        | (0 << _T6HLT_T6PSYNC_POSN);  // T6PSYNC Not Synchronized

    T6RST = (0 << _T6RST_T6RSEL_POSN);  // T6RSEL T6INPPS pin

    T6PR = 0xFF;    // Period 0.002048s; Frequency 125000Hz; Count 255

    T6TMR = 0x0;

    TMR6_PeriodMatchCallback = TMR6_DefaultPeriodMatchCallback;
    
    PIR4bits.TMR6IF = 0;

    T6CON = (0 << _T6CON_T6CKPS_POSN)   // T6CKPS 1:1
        | (1 << _T6CON_TMR6ON_POSN)   // TMR6ON on
        | (0 << _T6CON_T6OUTPS_POSN);  // T6OUTPS 1:1
}

void TMR6_Deinitialize(void)
{
    T6CONbits.TMR6ON = 0;
    
    PIR4bits.TMR6IF = 0;	   
    PIE4bits.TMR6IE = 0;		
    
    T6CON = 0x0;
    T6CLKCON = 0x0;
    T6HLT = 0x0;
    T6RST = 0x0;
    T6PR = 0xFF;
    T6TMR =0x0;
}

void TMR6_Start(void)
{   
    T6CONbits.TMR6ON = 1;
}

void TMR6_Stop(void)
{   
    T6CONbits.TMR6ON = 0;
}

void TMR6_ModeSet(TMR6_HLT_MODE mode)
{  
    T6HLTbits.T6MODE = mode;
}

void TMR6_ExtResetSourceSet(TMR6_HLT_EXT_RESET_SOURCE reset)
{   
    T6RSTbits.T6RSEL = reset;
}

uint8_t TMR6_CounterGet(void)
{
    return T6TMR;
}

void TMR6_CounterSet(uint8_t count)
{  
    T6TMR = count;
}

void TMR6_PeriodSet(uint8_t periodVal)
{
    T6PR = periodVal;
}

uint8_t TMR6_PeriodGet(void)
{
    return T6PR;
}

uint8_t TMR6_MaxCountGet(void)
{
    return TMR6_MAX_COUNT;
}

bool TMR6_PeriodMatchStatusGet(void)
{
    return PIR4bits.TMR6IF;
}

void TMR6_PeriodMatchStatusClear(void)
{
    PIR4bits.TMR6IF = 0;
}

void TMR6_Tasks(void)
{
    if(1U == PIR4bits.TMR6IF)
    {
        if(NULL != TMR6_PeriodMatchCallback)
        {
            TMR6_PeriodMatchCallback();
        }
        PIR4bits.TMR6IF = 0;
    }
}

void TMR6_PeriodMatchCallbackRegister(void (* callbackHandler)(void))
{
   TMR6_PeriodMatchCallback = callbackHandler;
}

static void TMR6_DefaultPeriodMatchCallback(void)
{
    // Default callback function
}


