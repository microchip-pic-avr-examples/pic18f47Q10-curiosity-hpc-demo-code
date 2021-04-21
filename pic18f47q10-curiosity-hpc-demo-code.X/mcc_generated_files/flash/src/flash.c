
/**
  MEMORY Generated Driver File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    memory.c
 
  @Summary
    This is the generated file for the MEMORY driver implementation
 
  @Description
    This source file provides driver APIs for MEMORY.
    Generation Information :
        Device            :  
        Driver Version    :  4.2.2
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.30
        MPLAB             :  MPLABX v5.45
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../flash.h"

/**
  Section: Flash Module APIs
*/
//128-bytes of Sector RAM for  is available at 0xD00
uint8_t sectorRAM __at(0xD00);

void FLASH_Initialize(void)
{
    // No initialization needed.
}

uint8_t FLASH_ReadByte(uint32_t flashAddr)
{
    //Set TBLPTR with the target byte address
    TBLPTRU = (uint8_t)((flashAddr & 0x00FF0000) >> 16);
    TBLPTRH = (uint8_t)((flashAddr & 0x0000FF00)>> 8);
    TBLPTRL = (uint8_t)(flashAddr & 0x000000FF);

    //Perform table read to move one byte from NVM to TABLAT
    asm("TBLRD");

    return (TABLAT);
}

uint16_t FLASH_ReadWord(uint32_t flashAddr)
{
    //Set TBLPTR with the target byte address
    NVMADRU = (uint8_t) ((flashAddr & 0x00FF0000) >> 16);
    NVMADRH = (uint8_t) ((flashAddr & 0x0000FF00) >> 8);
    NVMADRL = (uint8_t) (flashAddr & 0x000000FF);
    
    //NVMCON1.RD operations are not affected by NVMEN, ignore NVMEN
    RD = 1;
    while (RD);
    
    return ((((uint16_t)NVMDATH) << 8) | NVMDATL);
}

void FLASH_ReadSector(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
        
    //Enable NVM access
    NVMEN = 1;

    //Set NVMADR with the target word address
    NVMADRU = (uint8_t) ((flashAddr & 0x00FF0000) >> 16);
    NVMADRH = (uint8_t) ((flashAddr & 0x0000FF00) >> 8);
    NVMADRL = (uint8_t) (flashAddr & 0x000000FF);
    
    //Disable all interrupt
    INTCONbits.GIE = 0;

    //Perform the unlock sequence
    NVMCON2 = 0xBB;
    NVMCON2 = 0x44;

    //Start sector read and wait for the operation to complete
    SECRD = 1;
    while (SECRD);

    //Restore the interrupts
    INTCONbits.GIE = GIEBitValue;

    //Disable NVM access
    NVMEN = 0;
}

void FLASH_WriteSector(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    
    //Enable NVM access
    NVMEN = 1;

    //Set NVMADR with the target word address
    NVMADRU = (uint8_t) ((flashAddr & 0x00FF0000) >> 16);
    NVMADRH = (uint8_t) ((flashAddr & 0x0000FF00) >> 8);
    NVMADRL = (uint8_t) (flashAddr & 0x000000FF);

    //Disable all interrupt
    INTCONbits.GIE = 0;

    //Perform the unlock sequence
    NVMCON2 = 0xDD;
    NVMCON2 = 0x22;

    //Start sector write and wait for the operation to complete
    SECWR = 1;
    while (SECWR);

    //Restore the interrupts
    INTCONbits.GIE = GIEBitValue;

    //Disable NVM access
    NVMEN = 0;
}

void FLASH_WriteWord(uint32_t flashAddr, uint16_t word)
{
    uint16_t *secramWordPtr = (uint16_t*) & sectorRAM;
    uint32_t blockStartAddr = (uint32_t) (flashAddr & ((END_FLASH - 1) ^ ((ERASE_FLASH_BLOCKSIZE * 2) - 1)));
    uint8_t offset = (uint8_t) ((flashAddr & ((ERASE_FLASH_BLOCKSIZE * 2) - 1)) / 2);
        
    //Read existing block into Sector RAM
    FLASH_ReadSector(blockStartAddr);

    //Erase the given block
    FLASH_EraseBlock(blockStartAddr);

    //Modify Sector RAM for the given word to be written to Program Flash Memory
    secramWordPtr += offset;
    *secramWordPtr = word;

    //Write Sector RAM contents to given Program Flash Memory block
    FLASH_WriteSector(blockStartAddr);
}

int8_t FLASH_WriteBlock(uint32_t flashAddr, uint16_t *flashWrBufPtr)
{
    uint16_t *secramWordPtr = (uint16_t*) & sectorRAM;
    uint32_t blockStartAddr = (uint32_t) (flashAddr & ((END_FLASH - 1) ^ ((ERASE_FLASH_BLOCKSIZE * 2) - 1)));
    uint8_t i;

    //Block write must start at the beginning of a row
    if (flashAddr != blockStartAddr)
    {
        return -1;
    }

    //Copy application buffer contents to Buffer RAM
    for (i = 0; i < WRITE_FLASH_BLOCKSIZE; i++)
    {
        *secramWordPtr++ = flashWrBufPtr[i];
    }

    //Erase the given block
    FLASH_EraseBlock(flashAddr);

    //Write Sector RAM contents to given Program Flash Memory block
    FLASH_WriteSector(flashAddr);

    return 0;
}

void FLASH_EraseBlock(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    
    NVMEN = 1;    // Enable NVM access

    //Set NVMADR with the target word address
    NVMADRU = (uint8_t) ((flashAddr & 0x00FF0000) >> 16);
    NVMADRH = (uint8_t) ((flashAddr & 0x0000FF00) >> 8);
    NVMADRL = (uint8_t) (flashAddr & 0x000000FF);

    //Disable all interrupts
    INTCONbits.GIE = 0;

    //Perform the unlock sequence
    NVMCON2 = 0xCC;
    NVMCON2 = 0x33;

    //Start block erase and wait for the operation to complete
    SECER = 1;
    while (SECER);

    //Restore the interrupts
    INTCONbits.GIE = GIEBitValue;

    //Disable NVM access
    NVMEN = 0;
}

/**
  Section: Data EEPROM Module APIs
*/
void DATAEE_WriteByte(uint16_t bAdd, uint8_t bData)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    
    //Set NVMADR with the target word address: 0x310000 - 0x3103FF
    NVMADRU = 0x31;
    NVMADRH = (uint8_t)((bAdd & 0xFF00) >> 8);
    NVMADRL = (uint8_t)(bAdd & 0x00FF);

    //Load NVMDATL with desired byte
    NVMDATL = (uint8_t)(bData & 0xFF);
    
    //Enable NVM access
    NVMEN = 1;
    
    //Disable interrupts
    INTCONbits.GIE = 0;

    //Perform the unlock sequence
    NVMCON2 = 0x55;
    NVMCON2 = 0xAA;

    //Start DATAEE write and wait for the operation to complete
    WR = 1;
    while (WR);

    //Restore all the interrupts
    INTCONbits.GIE = GIEBitValue;

    //Disable NVM access
    NVMEN = 0;
}

uint8_t DATAEE_ReadByte(uint16_t bAdd)
{
    //Set NVMADR with the target word address: 0x310000 - 0x3103FF
    NVMADRU = 0x31;
    NVMADRH = (uint8_t)((bAdd & 0xFF00) >> 8);
    NVMADRL = (uint8_t)(bAdd & 0x00FF);
    

    //Start DATAEE read
    RD = 1;
    NOP();  // NOPs may be required for latency at high frequencies
    NOP();

    return (NVMDATL);
}
