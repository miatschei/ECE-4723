// ECE 4273/6473 Embedded Systems
// Lab 2 Traffic Controller Spec 1

//#include "revF14.h"
#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"

ESOS_USER_TASK(lab_3){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_TICKS(300);
    }
    ESOS_TASK_END();

}

void user_init(){
    config_esos_uiF14();
    esos_RegisterTask( lab_3 );
}