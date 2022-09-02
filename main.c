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
#include <time.h>
#include <stdlib.h>
#include "lib/OLED.h"

// Maximum number of array: 80
// 0-9
const unsigned char myASCII[][16] = {
    {0b11111110, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b11111110, 0b00000000}, // 0
    
    // TODO: Should rotate 180
    {0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b11111110, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000000}, // 1
    {0b10011110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11110010, 0b00000000}, // 2
    {0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11111110, 0b00000000}, // 3
    {0b11110000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b11111110, 0b00000000}, // 4
    
    {0b11110000, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10011110, 0b00000000}, // 5
    {0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b00000000}, // 6
    {0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b11111110, 0b00000000}, // 7
    {0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11111110, 0b00000000}, // 8
    {0b11110010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b10010010, 0b11111110, 0b00000000}, // 9
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
    srand((unsigned int) time(NULL));
    IO_RC3_SetHigh();
    
    OLED_Init();
    OLED_Clear();
    __delay_ms(1000);
    
    int wait = 0;
    int direction = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    
//    
//    // number, current, time
//    uint8_t numbers[32][2] = {0};
//    uint8_t waits[32] = {0};
//    for (i = 0; i < sizeof(numbers); i++) {
//        wait = (uint8_t) rand() % 10 + 1;
//        direction = rand() % 2;
//        
//        numbers[i][0] = rand() % 10 * 10 + direction;
//        numbers[i][1] = wait;
//        waits[i] = wait;
//    }

    // Loop
    while (1)
    {
        OLED_SelectPage(0);
        
        for (i = 0; i < 64; i++) {
            OLED_Data(0b11111110);
            for (j = 0; j < 13; j++) {
                OLED_Data(0b10000010);
            }
            OLED_Data(0b11111110);
            OLED_Data(0b00000000);
        }
        
//        for (i = 0; i < 1024; i++) {
//            int tmpNum = numbers[i][0] / 10;
//            uint8_t tmpDirection = numbers[i][0] % 10;
            
            
            
//            for (j = 0; j < 8; j++) {
//                // OLED_Data(myASCII[tmpNum][j]);
//                
//            }
            
//            numbers[i][1]--;
//            if (numbers[i][1] == 0) {
//                if (tmpDirection == 1) {
//                    tmpNum++;
//                    if (tmpNum > 9) {
//                        tmpNum = 0;
//                    }
//                } else {
//                    tmpNum--;
//                    if (tmpNum < 0) {
//                        tmpNum = 9;
//                    }
//                }
//                
//                numbers[i][0] = (uint8_t) tmpNum * 10 + tmpDirection;
//                numbers[i][1] = waits[i];
//            }
//        }
    }
}

/**
 End of File
*/