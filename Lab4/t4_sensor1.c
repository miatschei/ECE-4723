#include "esos.h"
// #include "esos_pic24_sensor.h"
#include "revF14.h"
#include "esos_f14ui.h"
#include "esos_pic24.h"
// #include "esos_sensor.h"
#include <stdio.h>

static char str_SW1[] = "SWITCH 1 PRESSED\n";
static char str_SW2[] = "SWITCH 2 PRESSED\n";

ESOS_USER_TASK(dummy){
    ESOS_TASK_BEGIN();
        while(TRUE){
            if (esos_uiF14_isSW1Pressed()){
                ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
                ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1);
                ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
            }
            else if (esos_uiF14_isSW2Pressed()){
                ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
                ESOS_TASK_WAIT_ON_SEND_STRING(str_SW2);
                ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
            }
            ESOS_TASK_YIELD();
        }
    ESOS_TASK_END();
}

void user_init(){
    // Run esos_uiF14 setup module
    config_esos_uiF14();

    // Register local tasks
    esos_RegisterTask(dummy);
}