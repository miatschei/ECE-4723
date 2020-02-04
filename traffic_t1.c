// ECE 4273/6473 Embedded Systems
// Lab 2 Traffic Controller Spec 1

#include "revF14.h"
#include "esos.h"
#include "esos_pic24.h"

#define N_S 0
#define E_W 1


// 0 -> Red 1 -> Amber 2 -> Green
#define DISPLAY_LIGHTS(l) {\
                            if(l = 0){ \
                                LED1_ON(); \
                                LED2_OFF(); \
                                LED3_OFF(); \
                            } else if(l = 1){ \
                                LED1_OFF(); \
                                LED2_ON(); \
                                LED3_OFF(); \
                            } else { \
                                LED1_OFF(); \
                                LED2_OFF(); \
                                LED3_ON(); \
                            } \
                           }

//ESOS_USER_TASK(test){
//    ESOS_TASK_BEGIN();
//    while(TRUE){
//        LED1 = !LED1;
//        ESOS_TASK_WAIT_TICKS( 500 );
//    }
//    ESOS_TASK_END();
//}

ESOS_USER_TASK(switch_state){
    ESOS_TASK_BEGIN();
    while(TRUE){
        if(SW3_PRESSED){
            // set to east west
            DISPLAY_LIGHTS(E_W);
            ESOS_TASK_WAIT_TICKS(15); // debounce delay
        } else {
            // set to north south
            DISPLAY_LIGHTS(N_S);
            ESOS_TASK_WAIT_TICKS(15); 
        }
    }
    ESOS_TASK_END();
}

ESOS_USER_TASK(traffic_light){
    ESOS_TASK_BEGIN();
    while(TRUE){
        // first color 0
        ESOS_TASK_WAIT_TICKS(10000);
        // second color 1
        ESOS_TASK_WAIT_TICKS(3000);
        // third color 2
        ESOS_TASK_WAIT_TICKS(10000);
        // fourth color 3
        ESOS_TASK_WAIT_TICKS(3000);
    }
    ESOS_TASK_END();
}

void user_init(void){
    CONFIG_LED1();
    CONFIG_LED2();
    CONFIG_LED3();
    
    LED1_OFF();
    LED2_OFF();
    LED3_OFF();
    
    // configure switch 3
    CONFIG_SW3();
    
    // register user tasks
    esos_RegisterTask(switch_state);
    esos_RegisterTask(traffic_light);
}