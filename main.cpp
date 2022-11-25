/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"

#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);
Grove_LCD_RGB_Backlight rgbLCD(PB_9,PB_8);
int c=0;
char cadena[16];
int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (true)
    {
        rgbLCD.setRGB(0xff, 0xff, 0xff);                 //set the color 
        rgbLCD.locate(0,0);
        rgbLCD.print("Hola buenos dias");
        c++;
        sprintf(cadena,"%d",c);
        rgbLCD.locate(0,1);
        rgbLCD.print(cadena);
        led1 = !led1;
        thread_sleep_for(WAIT_TIME_MS);
    }
}
