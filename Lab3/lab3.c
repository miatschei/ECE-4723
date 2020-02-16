// ECE 4273/6473 Embedded Systems
// Lab 2 Traffic Controller Spec 1

#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"
#include "revF14.h"


ESOS_USER_TASK(test){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_TICKS(300);
        LED1 = !LED1;
    }
    ESOS_TASK_END();

}

void user_init(){

    CONFIG_LED1();

    //config_esos_uiF14();
    esos_RegisterTask(test);
}