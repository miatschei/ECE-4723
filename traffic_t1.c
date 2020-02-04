// ECE 4273/6473 Embedded Systems
// Lab 2 Traffic Controller Spec 1

#include "revF14.h"
#include "esos.h"
#include "esos_pic24.h"
//uint8_t     LED1 = FALSE;
enum states {
    STATE1,
    STATE2,
    STATE3,
    STATE4,
    STATE5,
    STATE6,

} state; 

// ESOS_USER_TASK(NS_LIGHT){
//     ESOS_TASK_BEGIN();
//     while(TRUE){

//         LED1_ON();
//         ESOS_TASK_WAIT_TICKS( 3400 );

//         LED1_OFF();
//         LED3_ON();
//         ESOS_TASK_WAIT_TICKS( 3000 );

//         LED3_OFF();
//         LED2_ON();
//         ESOS_TASK_WAIT_TICKS( 3000 );

//         LED2_OFF();
//         LED1_ON();
//         ESOS_TASK_WAIT_TICKS (1000 );
//     }
//     ESOS_TASK_END();
// }

ESOS_USER_TASK(SWITCH_TASK){
    ESOS_TASK_BEGIN();
    while(TRUE){
        LED1_ON();
        ESOS_TASK_WAIT_TICKS( 500 );
        LED2_ON();
        ESOS_TASK_WAIT_TICKS( 500 );
        LED3_ON();
        ESOS_TASK_WAIT_TICKS( 500 );
        LED1_OFF();
        LED2_OFF();
        LED3_OFF();
    }
    ESOS_TASK_END();
}

void user_init(void){
    __esos_unsafe_PutString(HELLO_MSG); //Esos hidden hardware routine to print strings to serial

    //state = NS_RED1; //current state of NS ligh to first red iteration

    CONFIG_LED1();
    CONFIG_LED2();
    CONFIG_LED3();
    
    LED1_OFF();
    LED2_OFF();
    LED3_OFF();

    //CONFIG_SW3();
    //esos_RegisterTask(NS_LIGHT);
    esos_RegisterTask(SWITCH_TASK);
}