#include "esos.h"
#include "esos_pic24_sensor.h"
#include "revF14.h"
#include "esos_f14ui.h"
#include "esos_pic24.h"
#include "esos_sensor.h"
#include <stdio.h>
#include "esos_lcd44780.h"
#include "esos_pic24_lcd44780.h"
#include "esos_lcd44780_customChars.h"

static enum display_states {pot_state, temp_state};
static enum display_states pstate = pot_state;

static uint16_t u16_adcval;
static uint8_t u8_read_type = ESOS_SENSOR_ONE_SHOT; //store the e_senProcess here 
static char str_temp[7];
static char str_pot[3];

static uint8_t char_bar_h;
static uint8_t char_bar_l;


static uint8_t char_slide_0;
static uint8_t char_slide_1;
static uint8_t char_slide_2;
static uint8_t char_slide_3;
static uint8_t char_slide_4;
static uint8_t char_slide_5;
static uint8_t char_slide_6;
static uint8_t char_slide_7;

ESOS_USER_TASK(adc_handle){
    ESOS_TASK_BEGIN();
    static ESOS_TASK_HANDLE get_temp;
    while(TRUE){
        //if (en_print == 1){
        if(pstate == temp_state){
            esos_lcd44780_init_char_bar();
            ESOS_ALLOCATE_CHILD_TASK(get_temp);
            ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_ON_AVAILABLE_SENSOR, tempCH, ESOS_SENSOR_VREF_3V0);
            ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_SENSOR_READ, &u16_adcval, u8_read_type, ESOS_SENSOR_FORMAT_VOLTAGE);
            float adc32_out = (uint32_t)u16_adcval * 1000;
            adc32_out = (adc32_out - 424000)/625;
            float temp32_C = adc32_out / 100;
            
            sprintf(str_temp, "%.1fC", temp32_C); // write string to variable
            ESOS_SENSOR_CLOSE();

            // determine bar
            // lowest -> 20C highest-> 35C (15 pt difference)
            char_bar_l = ' ';
            char_bar_h = ' ';
            if((uint16_t)temp32_C <= 20) char_bar_l = BAR0; 
            else if((uint16_t)temp32_C == 21) char_bar_l = BAR1; 
            else if((uint16_t)temp32_C == 22) char_bar_l = BAR2; 
            else if((uint16_t)temp32_C == 23) char_bar_l = BAR3; 
            else if((uint16_t)temp32_C == 24) char_bar_l = BAR4;
            else if((uint16_t)temp32_C == 25) char_bar_l = BAR5;  
            else if((uint16_t)temp32_C == 26) char_bar_l = BAR6; 
            else if((uint16_t)temp32_C == 28) char_bar_h = BAR0;
            else if((uint16_t)temp32_C == 29) char_bar_h = BAR1;
            else if((uint16_t)temp32_C == 30) char_bar_h = BAR2;
            else if((uint16_t)temp32_C == 31) char_bar_h = BAR3;
            else if((uint16_t)temp32_C == 32) char_bar_h = BAR4;
            else if((uint16_t)temp32_C == 33) char_bar_h = BAR5;
            else if((uint16_t)temp32_C == 34) char_bar_h = BAR6;
            else if((uint16_t)temp32_C >= 35) char_bar_h = BAR7;

            if((int)temp32_C >= 27) char_bar_l = BAR7; // acount for higher numbers

            esos_lcd44780_clearScreen();
            esos_lcd44780_writeString(0, 0, "LM60");
            esos_lcd44780_writeString(1, 0, str_temp);
            esos_lcd44780_writeChar(0, 7, char_bar_h);
            esos_lcd44780_writeChar(1, 7, char_bar_l);
        } else if(pstate == pot_state){
            esos_lcd44780_init_char_slider();
            ESOS_ALLOCATE_CHILD_TASK(get_temp);
            ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_ON_AVAILABLE_SENSOR, potCH, ESOS_SENSOR_VREF_3V0);
            // ESOS_TASK_SPAWN_AND_WAIT(get_adc,_WAIT_SENSOR_QUICK_READ, &u16_adcval);
            ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_SENSOR_READ, &u16_adcval, u8_read_type, ESOS_SENSOR_FORMAT_BITS);
            ESOS_SENSOR_CLOSE();
            // determine slider from 0 to 255
            char_slide_0 = SLIDER0; char_slide_1 = SLIDER0; char_slide_2 = SLIDER0; char_slide_3 = SLIDER0;
            char_slide_4 = SLIDER0; char_slide_5 = SLIDER0; char_slide_6 = SLIDER0; char_slide_7 = SLIDER0;
            // 0 to 128 -> 32 each
            if(u16_adcval <= 512){
                if(u16_adcval <= 0)       char_slide_0 = SLIDER1;
                else if(u16_adcval <= 128)  char_slide_0 = SLIDER2;
                else if(u16_adcval <= 256) char_slide_0 = SLIDER3;
                else if(u16_adcval <= 384) char_slide_0 = SLIDER4;
                else if(u16_adcval <= 512) char_slide_0 = SLIDER5;
            } else if(u16_adcval <= 1024){
                if(u16_adcval <= 615)      char_slide_1 = SLIDER1;
                else if(u16_adcval <= 718) char_slide_1 = SLIDER2;
                else if(u16_adcval <= 821) char_slide_1 = SLIDER3;
                else if(u16_adcval <= 924) char_slide_1 = SLIDER4;
                else if(u16_adcval <= 1024) char_slide_1 = SLIDER5;
            } else if(u16_adcval <= 1536){
                if(u16_adcval <= 1127)      char_slide_2 = SLIDER1;
                else if(u16_adcval <= 1230) char_slide_2 = SLIDER2;
                else if(u16_adcval <= 1333) char_slide_2 = SLIDER3;
                else if(u16_adcval <= 1436) char_slide_2 = SLIDER4;
                else if(u16_adcval <= 1536) char_slide_2 = SLIDER5;
            } else if(u16_adcval <= 2048){
                if(u16_adcval <= 1639)      char_slide_3 = SLIDER1;
                else if(u16_adcval <= 1742) char_slide_3 = SLIDER2;
                else if(u16_adcval <= 1845) char_slide_3 = SLIDER3;
                else if(u16_adcval <= 1948) char_slide_3 = SLIDER4;
                else if(u16_adcval <= 2048) char_slide_3 = SLIDER5;
            } else if(u16_adcval <= 2560){
                if(u16_adcval <= 2151)      char_slide_4 = SLIDER1;
                else if(u16_adcval <= 2254) char_slide_4 = SLIDER2;
                else if(u16_adcval <= 2357) char_slide_4 = SLIDER3;
                else if(u16_adcval <= 2460) char_slide_4 = SLIDER4;
                else if(u16_adcval <= 2560) char_slide_4 = SLIDER5;
            } else if(u16_adcval <= 3072){
                if(u16_adcval <= 2663)      char_slide_5 = SLIDER1;
                else if(u16_adcval <= 2766) char_slide_5 = SLIDER2;
                else if(u16_adcval <= 2869) char_slide_5 = SLIDER3;
                else if(u16_adcval <= 2972) char_slide_5 = SLIDER4;
                else if(u16_adcval <= 3072) char_slide_5 = SLIDER5;
            } else if(u16_adcval <= 3584){
                if(u16_adcval <= 3175)      char_slide_6 = SLIDER1;
                else if(u16_adcval <= 3278) char_slide_6 = SLIDER2;
                else if(u16_adcval <= 3381) char_slide_6 = SLIDER3;
                else if(u16_adcval <= 3484) char_slide_6 = SLIDER4;
                else if(u16_adcval <= 3584) char_slide_6 = SLIDER5;
            } else if(u16_adcval <= 4095){
                if(u16_adcval <= 3687)      char_slide_7 = SLIDER1;
                else if(u16_adcval <= 3790) char_slide_7 = SLIDER2;
                else if(u16_adcval <= 3893) char_slide_7 = SLIDER3;
                else if(u16_adcval <= 3996) char_slide_7 = SLIDER4;
                else if(u16_adcval <= 4095) char_slide_7 = SLIDER5;
            }

            sprintf(str_pot, "pot 0x%02x", u16_adcval); // write string to variable
            
            esos_lcd44780_clearScreen();
            esos_lcd44780_writeString(0, 0, str_pot);
            esos_lcd44780_writeChar(1, 0, char_slide_0);
            esos_lcd44780_writeChar(1, 1, char_slide_1);
            esos_lcd44780_writeChar(1, 2, char_slide_2);
            esos_lcd44780_writeChar(1, 3, char_slide_3);
            esos_lcd44780_writeChar(1, 4, char_slide_4);
            esos_lcd44780_writeChar(1, 5, char_slide_5);
            esos_lcd44780_writeChar(1, 6, char_slide_6);
            esos_lcd44780_writeChar(1, 7, char_slide_7);

        }
        ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}

ESOS_USER_TASK(state_handle){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_UNTIL(SW3_PRESSED);
        pstate = !pstate; // change state
        ESOS_TASK_WAIT_UNTIL(SW3_RELEASED);
        ESOS_TASK_YIELD();
    }    
    ESOS_TASK_END();
}

void user_init(){
    // Run esos_uiF14 setup module
    CONFIG_SW3();
    config_esos_uiF14();
    esos_lcd44780_init();
    esos_lcd44780_configDisplay();
    // Register local tasks
    esos_RegisterTask(adc_handle);
    esos_RegisterTask(state_handle);
}