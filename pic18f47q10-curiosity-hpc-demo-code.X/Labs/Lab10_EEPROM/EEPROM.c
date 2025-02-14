/**
  EEPROM Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    EEPROM.c

  Summary:
    This is the source file for the EEPROM lab

  Description:
    This source file contains the code on how the EEPROM lab works.
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

#define EEPROM_LAST_ADDR     ((eeprom_address_t)(EEPROM_START_ADDRESS + EEPROM_SIZE - 1))       // address of the last location in EEPROM

static uint8_t adcResult;
static eeprom_address_t currentAddress = EEPROM_START_ADDRESS;

void dumpMemoryContents(void);

void EEPROM(void) {

    if (labState == NOT_RUNNING) {
        LEDs_SetLow();
        labState = RUNNING;
    }

    if (labState == RUNNING) {   
        
        adcResult = (uint8_t)(ADC_ChannelSelectAndConvert(POT_CHANNEL) >> 8);   // Get the top 8 MSBs of the ADC Conversion
        LEDs = (uint8_t)(adcResult);                                            // write adcResult to LEDs
        
        if( CLC2IF ) {                                                          // determine if switch 2 has been pressed            
            
            NVM_UnlockKeySet(0xAA55);                                           // set the unlock key to allow NVM writes
            EEPROM_Write(currentAddress, adcResult);
            while( NVM_IsBusy() ) {
                // wait for EEPROM write to finish
            }
            NVM_UnlockKeyClear();                                               // Clear the unlock key to safeguard against unintended NVM writes            
            
            currentAddress++;
            if( currentAddress > EEPROM_LAST_ADDR) {
                currentAddress = EEPROM_START_ADDRESS;
            }
            
            dumpMemoryContents();
            CLC2IF = 0;
        }                                           
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}

void dumpMemoryContents(void) {
    
    eeprom_address_t address = EEPROM_START_ADDRESS;
    
    printf("\r\n");
    while( address <= EEPROM_LAST_ADDR) {
        
        uint8_t addrUpper = ( (address>>16) & 0xff);
        uint8_t addrHigh =  ( (address>>8) & 0xff);
        uint8_t addrLow =   (  address & 0xff);
        
        printf("\r\n0x%02x%02x%02x: ",addrUpper,addrHigh,addrLow);
        for( uint8_t i=0; i<=0xf; i++) {
            printf("%2x ", EEPROM_Read(address++));
        }
    }
}
/*
 End of File
 */
