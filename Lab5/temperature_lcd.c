#include "esos.h"
#include "revF14.h"
#include "esos_pic24.h"
#include <stdio.h>
#include "esos_lcd44780.h"
#include "esos_pic24_lcd44780.h"
#include "esos_lcd44780_customChars.h"
#include "esos_sensor.h"
#include "esos_pic24_sensor.h"

static enum display_states {pot, temp};
static enum display_states pstate = pot;

static uint16_t u16_adcval;
static uint8_t u8_read_type = ESOS_SENSOR_ONE_SHOT;
static uint8_t counter = 0;
uint8_t rate = 100;
//static char* str_adc = "00";
char str_temp[8];
char t[12];

ESOS_USER_TASK(adc_handle){
    ESOS_TASK_BEGIN();
    static ESOS_TASK_HANDLE get_temp;
    while(TRUE){
        ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_ON_AVAILABLE_SENSOR, tempCH, ESOS_SENSOR_VREF_3V0);
        ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_SENSOR_READ, &u16_adcval, u8_read_type, ESOS_SENSOR_FORMAT_VOLTAGE);
        float adc32_out = (uint32_t) u16_adcval;
        //adc32_out = (adc32_out - 424000)/625;
        //float temp32_C = adc32_out / 100;

        sprintf(str_temp, "%f \n", adc32_out);
        
        ESOS_SENSOR_CLOSE();

        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING(str_temp);
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        ESOS_TASK_YIELD();
        ESOS_TASK_WAIT_TICKS(1000); 
    }
    ESOS_TASK_END();
}
ESOS_USER_TASK(display_handle){
    ESOS_TASK_BEGIN();
    
    while(TRUE){
        // potentiometer
        //if(counter == rate){
        
            
            //esos_lcd44780_clearScreen();
            // if(pstate == pot){
            //     // ESOS_ALLOCATE_CHILD_TASK(get_adc);
            //     // ESOS_TASK_SPAWN_AND_WAIT(get_adc, _WAIT_ON_AVAILABLE_SENSOR, potCH, ESOS_SENSOR_VREF_3V0);
            //     // ESOS_TASK_SPAWN_AND_WAIT(get_adc, _WAIT_SENSOR_READ, &u16_adcval, u8_read_type, ESOS_SENSOR_FORMAT_BITS);
            //     // ESOS_SENSOR_CLOSE();
            //     //ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            //     //ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING(u16_adcval);
            //     //ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
            //     esos_lcd44780_writeString(1, 0, "pot");
            // }

            //if(pstate == temp) esos_lcd44780_writeString(0, 0, "temp");
            
            ESOS_TASK_YIELD();

        
    }    
    ESOS_TASK_END();
}

ESOS_USER_TASK(state_handle){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_UNTIL(SW3_PRESSED);
        pstate = !pstate;
        esos_lcd44780_clearScreen();
        counter == rate;
        ESOS_TASK_WAIT_UNTIL(SW3_RELEASED);
        ESOS_TASK_YIELD();
    }    
    ESOS_TASK_END();
}

void user_init(){
    config_esos_uiF14();
    esos_lcd44780_init();
    esos_lcd44780_configDisplay();
    
    esos_RegisterTask(state_handle);
    esos_RegisterTask(display_handle);
    esos_RegisterTask(adc_handle);
}