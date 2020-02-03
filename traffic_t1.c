// ECE 4273/6473 Embedded Systems
// Lab 2 Traffic Controller Spec 1

#include "revF14.h"
#include "esos.h"
#include "esos_pic24.h"
//uint8_t     LED1 = FALSE;


ESOS_USER_TASK(test){
    ESOS_TASK_BEGIN();
    while(TRUE){
        LED1 = !LED1;
        ESOS_TASK_WAIT_TICKS( 500 );
    }
    ESOS_TASK_END();
}

void user_init(void){
    CONFIG_LED1();
    LED1 = 1;
    //CONFIG_SW3();
    esos_RegisterTask(test);
}