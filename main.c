/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1705
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include "lib/OLED.h"

#define NUMBER_OF_ARRAY 64

// 0-9
const unsigned char myASCII[][8] = {
    {0b11111110, 0b11000010, 0b10100010, 0b10010010, 0b10001010, 0b10000110, 0b11111110, 0b00000000}, // 0
    {0b10000010, 0b10000010, 0b10000010, 0b11111110, 0b10000000, 0b10000000, 0b10000000, 0b00000000}, // 1
    {0b11110010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10011110, 0b00000000}, // 2
    {0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11111110, 0b00000000}, // 3
    {0b00011110, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b11111110, 0b00000000}, // 4
    
    {0b10011110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11110010, 0b00000000}, // 5
    {0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11110010, 0b00000000}, // 6
    {0b00000010, 0b00000010, 0b00000010, 0b11110010, 0b00001010, 0b00000110, 0b00000010, 0b00000000}, // 7
    {0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11111110, 0b00000000}, // 8
    {0b10011110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11111110, 0b00000000}, // 9
};


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // My settings
    // Lazy seed to replace from time(NULL) because it returns always 0 without RTCC
    srand((unsigned int) rand());
    
    __delay_ms(1000);
    
    OLED_Init();
    OLED_Clear();
    
    __delay_ms(1000);
    IO_RC3_SetHigh();
    
    uint8_t wait = 0;
    int i = 0;
    int j = 0;
    int tmpNum = 0;

    // Maximum number of array: 80
    // Initialize number, current, time
    uint8_t numbers[NUMBER_OF_ARRAY] = {0};
    uint8_t currents[NUMBER_OF_ARRAY] = {0};
    uint8_t waits[NUMBER_OF_ARRAY] = {0};

    for (i = 0; i < sizeof(numbers); i++) {
        wait = (rand() % 10 == 1) ? rand() % 4 + 1 : rand() % 96 + 1;
        numbers[i] = rand() % 10;
        currents[i] = wait;
        waits[i] = wait;
    }

    // Display and count down numbers
    while (1)
    {
        tmpNum = 0;
        OLED_SelectPage(0);
        
        for (i = 0; i < sizeof(numbers); i++) {
            for (j = 0; j < 8; j++) {
                tmpNum = numbers[i];
                OLED_Data(myASCII[tmpNum][j]);
            }
            
            // Count down
            currents[i]--;
            if (currents[i] <= 0) {
                tmpNum--;
                
                if (tmpNum == 0) {
                    wait = waits[i];
                    
                    if (wait > 4) {
                        wait = rand() % 4 + 1;
                    } else {
                        uint8_t randNum = rand() % 100;
                        
                        if (randNum <= 1) {
                            wait = rand() % 255 + 1;
                        } else if (randNum <= 5) {
                            wait = rand() % 192 + 1;
                        } else {
                            wait = rand() % 32 + 1;
                        }
                    }
                    
                    waits[i] = wait;
                } else if (tmpNum < 0) {
                    tmpNum = 9;
                }
                
                currents[i] = waits[i];
            }
            
            numbers[i] = (uint8_t) tmpNum;
        }
    }
}

/**
 End of File
*/