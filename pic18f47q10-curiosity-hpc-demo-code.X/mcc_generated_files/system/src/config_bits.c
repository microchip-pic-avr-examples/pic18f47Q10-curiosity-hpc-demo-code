/**
  @Generated CCL Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    config_bits.c

  @Summary:
    This is the config_bits.c file generated using CCL

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information : 
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLAB X 5.40
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

// Configuration bits: selected in the GUI

//CONFIG1L
#pragma config FEXTOSC = OFF     // External Oscillator Mode Selection->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_1MHZ     // Power-Up Default Value for COSC->HFINTOSC with HFFRQ = 4 MHz and CDIV = 4:1

//CONFIG1H
#pragma config CLKOUTEN = OFF     // Clock Out Enable->CLKOUT function is disabled
#pragma config FCMEN = ON     // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor enabled
#pragma config CSWEN = ON     // Clock Switch Enable->Writing to NOSC and NDIV is allowed

//CONFIG2L
#pragma config MCLRE = EXTMCLR     // Master Clear (MCLR) Enable->MCLR pin (RE3) is MCLR
#pragma config BOREN = SBORDIS     // Brown-Out Reset Enable->Brown-out Reset enabled , SBOREN bit is ignored
#pragma config PWRTE = OFF     // Power-Up Timer Enable->Power up timer disabled
#pragma config LPBOREN = OFF     // Low-Power BOR Enable->Low power BOR is disabled

//CONFIG2H
#pragma config XINST = OFF     // Extended Instruction Set Enable->Extended Instruction Set and Indexed Addressing Mode disabled
#pragma config ZCD = OFF     // ZCD Disable->ZCD disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON
#pragma config STVREN = ON     // Stack Overflow/Underflow Reset Enable->Stack full/underflow will cause Reset
#pragma config BORV = VBOR_190     // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.90V
#pragma config PPS1WAY = OFF     // PPSLOCKED bit One-Way Set Enable->PPSLOCK bit can be set and cleared repeatedly (subject to the unlock sequence)

//CONFIG3L
#pragma config WDTCPS = WDTCPS_12     // WDT Period Select->Divider ratio 1:131072
#pragma config WDTE = SWDTEN     // WDT Operating Mode->WDT enabled/disabled by SWDTEN bit

//CONFIG3H
#pragma config WDTCWS = WDTCWS_7     // WDT Window Select->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = LFINTOSC    // WDT input clock selector->WDT reference clock is the 31.0 kHz LFINTOSC

//CONFIG4L
#pragma config WRT1 = OFF     // User NVM Self-Write Protection Block 1->Block 1 (004000-007FFFh) not write-protected
#pragma config WRT0 = OFF     // User NVM Self-Write Protection Block 0->Block 0 (000800-003FFFh) not write-protected
#pragma config WRT2 = OFF     // User NVM Self-Write Protection Block 2->Block 2 (008000-00BFFFh) not write-protected
#pragma config WRT3 = OFF     // User NVM Self-Write Protection Block 3->Block 3 (00C000-00FFFFh) not write-protected
#pragma config WRT4 = OFF     // User NVM Self-Write Protection Block 4->Block 4 (010000-013FFFh) not write-protected
#pragma config WRT5 = OFF     // User NVM Self-Write Protection Block 5->Block 5 (014000-017FFFh) not write-protected
#pragma config WRT6 = OFF     // User NVM Self-Write Protection Block 6->Block 6 (018000-01BFFFh) not write-protected
#pragma config WRT7 = OFF     // User NVM Self-Write Protection Block 7->Block 7 (01C000-01FFFFh) not write-protected

//CONFIG4H
#pragma config WRTB = OFF     // Boot Block Write Protection->Boot Block (000000-0007FFh) not write-protected
#pragma config WRTC = OFF     // Configuration Register Write Protection->Configuration registers (300000-30000Bh) not write-protected
#pragma config WRTD = OFF     // Data EEPROM Write Protection->Data EEPROM not write-protected
#pragma config LVP = ON     // Low Voltage Programming Enable->Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored
#pragma config SCANE = ON     // Scanner Enable->Scanner module is available for use, SCANMD bit can control the module

//CONFIG5L
#pragma config CPD = OFF     // Data NVM (DFM) Memory Code Protection->DataNVM code protection disabled
#pragma config CP = OFF     // User NVM Program Memory Code Protection->UserNVM code protection disabled

//CONFIG6L
#pragma config EBTR1 = OFF     // Table Read Protection Block 1->Block 1 (004000-007FFFh) not protected from table reads executed in other blocks
#pragma config EBTR0 = OFF     // Table Read Protection Block 0->Block 0 (000800-003FFFh) not protected from table reads executed in other blocks
#pragma config EBTR3 = OFF     // Table Read Protection Block 3->Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF     // Table Read Protection Block 2->Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks
#pragma config EBTR6 = OFF     // Table Read Protection Block 6->Block 6 (018000-01BFFFh) not protected from table reads executed in other blocks
#pragma config EBTR5 = OFF     // Table Read Protection Block 5->Block 5 (014000-017FFFh) not protected from table reads executed in other blocks
#pragma config EBTR4 = OFF     // Table Read Protection Block 4->Block 4 (010000-013FFFh) not protected from table reads executed in other blocks
#pragma config EBTR7 = OFF     // Table Read Protection Block 7->Block 7 (01C000-01FFFFh) not protected from table reads executed in other blocks

//CONFIG6H
#pragma config EBTRB = OFF     // Boot Block Table Read Protection->Boot Block (000000-0007FFh) not protected from table reads executed in other blocks

