/**
 * Configuration Bits Generated Driver Source File
 * 
 * @file config_bits.c
 * 
 * @ingroup config_bitsdriver
 * 
 * @brief This file contains the API Implementation for the Device Configuration Bits driver.
 *
 * @version Driver Version 2.0.2
 *
 * @version Package Version 2.1.5
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
#pragma config WDTCCS = SC     // WDT Input Clock Selector->Software Control

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

/**
 End of File
*/
