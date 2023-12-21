/*
 * File:   main.c
 * Author: ambad
 *
 * Created on April 9, 2021, 11:20 AM
 */


#include <xc.h>
//#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "LCD.h"

#define arrowKey RB7  // the arrow button
#define enterKey RB6  // the enter button
#define weldingButton RA0  // welding activation button
#define discharge RA6
#define charge RA7
uint8_t button1_stat = 0;
bool button2_stat = 0;
bool allow_welding = 0;
uint8_t page = 0;  // program start from page 0
uint8_t choosenValues[1];  // here we will store what the user choosed from the interface
                           // it stores what each page gives in order
                           // first value is 0 or 1, 0 for 0.15mm, and 1 for 0.1mm strip //////

void update(uint8_t button1_tstat, uint8_t button2_stat, uint8_t page_f) {
    
    // page 0 chooses whether battery strip is 0.1 or 0.15mm
    if(page_f == 0) {
        
        // button1 programming as arrow key
        if(button1_tstat >= 2) {
            button1_stat = 0;
        }
        
//        char blah[2];
//        sprintf(blah, "%d", button1_stat);  // using lcd as terminal :))))
        
        char page0_user_input[2][16] = {"0.1mm    0.15mm<", "0.1mm<   0.15mm"};
        LCD_Clear();
        LCD_Set_Cursor(1, 1);
        LCD_Write_String("Strip Depth:");
        LCD_Set_Cursor(2, 1);
        LCD_Write_String(page0_user_input[button1_stat]);
        
        //button2 programming as enter key
        //     since there are only two options so value[0] will be 0 or 1 which is
        //      0.1mm or 0.15mm respectively
        if(button2_stat) {
            choosenValues[0] = button1_tstat;
            button1_stat = 0;
            page = 1;
            LCD_Clear();
            LCD_Set_Cursor(1, 1);
            LCD_Write_String(" Click to start");
            LCD_Set_Cursor(2, 1);
            LCD_Write_String("  Spot weldeing");
        }
    } else if (page_f == 1) {
        LCD_Clear();
        LCD_Set_Cursor(1, 1);
        LCD_Write_String("   Charging..");
        LCD_Set_Cursor(2, 1);
        LCD_Write_String("");
        // turning on the comparator
        CMIE = 1;
        CM2 = 1;
        CM1 = 0;
        CM0 = 1;
    }
}


void main(void) {
    
    //internal oscillator
    OSCF = 1; // 4MHz
    
    //LCD settings
    LCD_Init();
    LCD_Clear();
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("  Battery Spot\0");
    LCD_Set_Cursor(2, 1);
    LCD_Write_String(" Welder    V1.0\0");
    
    //TRIS register
    TRISB6 = 1;  // enter button
    TRISB7 = 1;  // arrow button
    TRISA0 = 1;  // welding activation button
    TRISA7 = 0;  // charge control
    TRISA6 = 0;  // discharge control
    RA7 = 0;  // normally off for both charging and discharging
    RA6 = 0;
    
    //Comparator module
    C2INV = 1;  // inverted, 1 if vin+ < vin-
    CM2 = 1;  // comparator initially off
    CM1 = 1;
    CM0 = 1;
    
    //interrupts
    GIE = 1;
    PEIE = 1;
    
    //Timer
    
    //Main Routine
    while(1) {
        if(arrowKey) {
            button1_stat++;
            update(button1_stat, button2_stat, page);
            __delay_ms(300);
        }
        if(enterKey) {
            button2_stat = ~button2_stat;
            update(button1_stat, button2_stat, page);
            __delay_ms(300);

        }
        if(allow_welding) {
            if(weldingButton) {
                if(choosenValues[0]) { // 1 means 0.1mm
                    discharge = 1;
                    __delay_ms(50);
                    discharge = 0;
                    charge = 1;
                    __delay_ms(300);
                } else {
                    discharge = 1;
                    __delay_ms(100);
                    discharge = 0;
                    charge = 1;
                    __delay_ms(300);
                }
            }
        }
    }
    
    return;
}

void __interrupt() ISR(void) {
    if(CMIF) {
        if(C2OUT) {  // 1 if vin+ < vin-
            discharge = 0; // starting always by closing both charging and discharging
            charge = 0;
            LCD_Clear();
            LCD_Set_Cursor(1, 1);
            LCD_Write_String("    Charged!");
            LCD_Set_Cursor(2, 1);
            LCD_Write_String("");
            allow_welding = 1;
        } else {
            allow_welding = 0;
            LCD_Clear();
            LCD_Set_Cursor(1, 1);
            LCD_Write_String("   Charging..");
            LCD_Set_Cursor(2, 1);
            LCD_Write_String("");
        }
        CMIF = 0;
    }
}
