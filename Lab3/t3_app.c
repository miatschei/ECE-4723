// ECE 4273/6473 Embedded Systems
// Lab 3 ESOS UI Service


#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"
#include "revF14.h"

ESOS_USER_TASK(test){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_TICKS(10);

        // static char str_SW1_PRESSED[] = "Switch 1 press\n";         
        // if (esos_uiF14_isSW1Pressed()) {                                  // these esos function names need to be consistent, causes error. Merge task from esos_f14ui.c to here.
        //     ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        //     ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1_PRESSED);
        //     ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        // }

        // static char str_SW2_PRESSED[] = "Switch 2 press\n";
        // if (esos_uiF14_isSW2Pressed()) {
        //     ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        //     ESOS_TASK_WAIT_ON_SEND_STRING(str_SW2_PRESSED);
        //     ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        // }
        
        // static char str_SW3_PRESSED[] = "Switch 3 press\n";
        // if (esos_uiF14_isSW3Pressed()) {
        //     ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        //     ESOS_TASK_WAIT_ON_SEND_STRING(str_SW3_PRESSED);
        //     ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        // }

        // static char str_RPG_TURNING[] =         "RPG turning\n";
        // static char str_RPG_TURNING_CW[] =      "RPG turning CW\n";
        // static char str_RPG_TURNING_CC[] =      "RPG turning CC\n";
        // static char str_RPG_TURNING_SLOW[] =    "RPG turning slow\n";
        // static char str_RPG_TURNING_MED[] =     "RPG turning med\n";
        // static char str_RPG_TURNING_FAST[] =    "RPG turning fast\n";
    }
    ESOS_TASK_END();
}

void user_init(){

    CONFIG_LED1();
    CONFIG_SW1();
    CONFIG_SW2();
    CONFIG_SW3();

    config_esos_uiF14();
    esos_RegisterTask(test);
}

