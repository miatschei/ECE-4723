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
uint8_t en_print = 0;

ESOS_USER_TASK(read_pot){
    ESOS_TASK_BEGIN();
    static ESOS_TASK_HANDLE get_adc;
    while(TRUE){
        if (en_print){
            ESOS_ALLOCATE_CHILD_TASK(get_adc);
            ESOS_TASK_SPAWN_AND_WAIT(get_adc, _WAIT_ON_AVAILABLE_SENSOR, potCH, ESOS_SENSOR_VREF_3V0);
            ESOS_TASK_SPAWN_AND_WAIT(get_adc,_WAIT_SENSOR_QUICK_READ, &u16_adcval);
            ESOS_SENSOR_CLOSE();
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING(u16_adcval);
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_TICKS(1000);
        }

        ESOS_TASK_YIELD();
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

uint8_t my_state; 

ESOS_USER_TASK(state_change){
    ESOS_TASK_BEGIN();
        while(TRUE){
            //__esos_unsafe_PutString("state 1");
            if (my_state == 0){
                if(esos_uiF14_isSW2Pressed()){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 1;
                    en_print = 1;

                    __esos_unsafe_PutString("state 1"); //cheat print
                }
            } else if(my_state == 1) {

                if(esos_uiF14_isSW2Released()){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 2;
                    __esos_unsafe_PutString("state 2"); //cheat print
                }

            } else if (my_state == 2){
                if (esos_uiF14_isSW1Pressed() || esos_uiF14_isSW2Pressed()){
                    my_state = 0; //go back to first state and wait for a single SW2 press
                    en_print = 0; //stop printing
                }
                
            }
            ESOS_TASK_YIELD();
        }
    ESOS_TASK_END();
}

void user_init(){
    // Run esos_uiF14 setup module
    config_esos_uiF14();

    my_state = 0;
    // Register local tasks
    esos_RegisterTask(read_pot);
    esos_RegisterTask(state_change);
}