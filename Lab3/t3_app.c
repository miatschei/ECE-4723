// ECE 4273/6473 Embedded Systems
// Lab 3 ESOS UI Service


#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"
#include "revF14.h"
#include <stdio.h>

ESOS_USER_TASK(test){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_TICKS(250);

        static char str_SW1_PRESSED[] = "Switch 1 pressed\n";         
        if (esos_uiF14_isSW1Pressed()) { 
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1_PRESSED);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        }

        static char str_SW2_PRESSED[] = "Switch 2 pressed\n";
        if (esos_uiF14_isSW2Pressed()) {
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW2_PRESSED);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        }
        
        static char str_SW3_PRESSED[] = "Switch 3 pressed\n";
        if (esos_uiF14_isSW3Pressed()) {
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW3_PRESSED);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        }

        static char str_RPG_TURNING_CW[] =      "RPG turning CW ";
        static char str_RPG_TURNING_CCW[] =     "RPG turning CCW ";
        static char str_RPG_TURNING_SLOW[] =    "slow\n";
        static char str_RPG_TURNING_MED[] =     "med\n";
        static char str_RPG_TURNING_FAST[] =    "fast\n";
        static char str_OUTBOUND[32];
        static char testprint[10];
        sprintf(testprint, "%d", esos_uiF14_getRpgVelocity_i16());

        if (esos_uiF14_isRpgTurning()){
            if (esos_uiF14_isRpgTurningCW()){
                if(esos_uiF14_isRpgTurningSlow()){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_SLOW);
                }
                if(esos_uiF14_isRpgTurningMedium()){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_MED);
                }
                if(esos_uiF14_isRpgTurningFast()){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_FAST);
 
                }
            }
            if (esos_uiF14_isRpgTurningCCW()){
                if(((0 < abs(esos_uiF14_getRpgVelocity_i16())) && (abs(esos_uiF14_getRpgVelocity_i16()) <= 15))){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CCW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_SLOW);
                }
                if((15 < abs(esos_uiF14_getRpgVelocity_i16())) && (abs(esos_uiF14_getRpgVelocity_i16()) <= 50)){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CCW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_MED);
                }
                if(50 < abs(esos_uiF14_getRpgVelocity_i16())){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CCW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_FAST);             
                }
            }
        }
        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING(str_OUTBOUND);
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        strcpy(str_OUTBOUND, "");
    }
    ESOS_TASK_END();
}



void user_init(){

    CONFIG_LED1();
    CONFIG_SW1();
    CONFIG_SW2();
    CONFIG_SW3();
    CONFIG_RPG();

    config_esos_uiF14();
    esos_RegisterTask(test);
}