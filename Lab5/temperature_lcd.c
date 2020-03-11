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
char temp[7];

ESOS_USER_TASK(adc_handle){
    ESOS_TASK_BEGIN();
    static ESOS_TASK_HANDLE get_temp;
    while(TRUE){
        //if (en_print == 1){
        ESOS_ALLOCATE_CHILD_TASK(get_temp);
        ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_ON_AVAILABLE_SENSOR, tempCH, ESOS_SENSOR_VREF_3V0);
        ESOS_TASK_SPAWN_AND_WAIT(get_temp, _WAIT_SENSOR_READ, &u16_adcval, u8_read_type, ESOS_SENSOR_FORMAT_VOLTAGE);
        float adc32_out = (uint32_t)u16_adcval * 1000;
        adc32_out = (adc32_out - 424000)/625;
        float temp32_C = adc32_out / 100;
        
        sprintf(temp, "%.1fC", temp32_C);
        ESOS_SENSOR_CLOSE();
        //ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        //ESOS_TASK_WAIT_ON_SEND_STRING(temp);
        //ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        esos_lcd44780_clearScreen();
        esos_lcd44780_writeString(0, 0, "LM60");
        esos_lcd44780_writeString(1, 0, temp);
        //ESOS_TASK_WAIT_TICKS(1000); 
        ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}

ESOS_USER_TASK(state_handle){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_UNTIL(SW3_PRESSED);
        pstate = !pstate;
        //esos_lcd44780_clearScreen();
        //counter == rate;
        ESOS_TASK_WAIT_UNTIL(SW3_RELEASED);
        ESOS_TASK_YIELD();
    }    
    ESOS_TASK_END();
}

void user_init(){
    // Run esos_uiF14 setup module
    config_esos_uiF14();
    esos_lcd44780_init();
    esos_lcd44780_configDisplay();
    //one_shot_state = 0;
    // Register local tasks
    esos_RegisterTask(adc_handle);
    esos_RegisterTask(state_handle);
    //esos_RegisterTask(adc_interface);
}