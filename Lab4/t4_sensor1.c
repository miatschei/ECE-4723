#include "esos.h"
#include "esos_pic24_sensor.h"
#include "revF14.h"
#include "esos_f14ui.h"
#include "esos_pic24.h"
#include "esos_sensor.h"
#include <stdio.h>

static char str_SW1[] = "\n";
static char str_SW2[] = "SWITCH PRESSED\n";

static uint16_t u16_adcval;
static uint16_t u16_state;

ESOS_USER_TASK(read_pot){
    ESOS_TASK_BEGIN();
    static ESOS_TASK_HANDLE get_adc;
    while(TRUE){
        ESOS_ALLOCATE_CHILD_TASK(get_adc);
        ESOS_TASK_SPAWN_AND_WAIT(get_adc, _WAIT_ON_AVAILABLE_SENSOR, potCH, ESOS_SENSOR_VREF_3V0);
        ESOS_TASK_SPAWN_AND_WAIT(get_adc,_WAIT_SENSOR_QUICK_READ, &u16_adcval);
        ESOS_SENSOR_CLOSE();
        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING(u16_adcval);
        ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1);
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_TICKS(1000);
        // ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}

enum sw_states{
    STATE_0,
    STATE_1,
    STATE_2,
    STATE_3,
    STATE_4,
    STATE_5,
} sw_state; 

ESOS_USER_TASK(state_change){
    ESOS_TASK_BEGIN();
        while(TRUE){
            if (sw_state == STATE_0){
                if(esos_uiF14_isSW1Pressed()){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    sw_state = STATE_1;
                    //set 
                }
            } else if(sw_state == STATE_1) {

                if(!esos_uiF14_isSW1Pressed){
                    sw_state = STATE_2;
                }

            } else if (esos_uiF14_isSW2Pressed()){
                
            }
            ESOS_TASK_YIELD();
        }
    ESOS_TASK_END();
}

void user_init(){
    // Run esos_uiF14 setup module
    config_esos_uiF14();

    sw_state = STATE_0;
    // Register local tasks
    esos_RegisterTask(read_pot);
    esos_RegisterTask(state_change);
}