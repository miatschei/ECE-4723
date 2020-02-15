// ECE 4273/6473 Embedded Systems
// Lab 2 Traffic Controller Spec 1

#include "revF14.h"
#include "esos.h"
#include "esos_pic24.h"

// Road States
#define N_S        0
#define E_W        1

// Light States
#define RED          0
#define AMBER        1
#define GREEN        2
#define TURN         3

// State storage
uint8_t state[2];

// Macro functions for turning on lights
#define LIGHT_RED()     {\
                          LED1_ON(); \
                          LED2_OFF(); \
                          LED3_OFF(); \
                        }

#define LIGHT_AMBER()   {\
                          LED1_OFF(); \
                          LED2_ON(); \
                          LED3_OFF(); \
                        }

#define LIGHT_GREEN()   {\
                          LED1_OFF(); \
                          LED2_OFF(); \
                          LED3_ON(); \
                        }
#define TOGGLE_GREEN() {\
                         LED1_OFF(); \
                         LED2_OFF(); \
                         LED3 = !LED3; \
                        }

// Macro functions for setting lights to given state
#define SET_RED(s) state[s] = RED;
#define SET_AMBER(s) state[s] = AMBER;
#define SET_GREEN(s) state[s] = GREEN;
#define SET_TURN(s)  state[s] = TURN;

// Display lights for given road state
#define DISPLAY_LIGHTS(s)   {\
                              if(state[s] == RED) LIGHT_RED(); \
                              if(state[s] == AMBER) LIGHT_AMBER(); \
                              if(state[s] == GREEN) LIGHT_GREEN(); \
                            }

// Task for sampling pushbuttons
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

// Task for setting state lights
ESOS_USER_TASK(traffic_light){
    ESOS_TASK_BEGIN();
    while(TRUE){
        if(SW1_RELEASED){
        // Normal conditions
        // first color
        SET_RED(N_S);
        SET_TURN(E_W);
        ESOS_TASK_WAIT_TICKS(10000);
        // second color
        SET_RED(N_S);
        SET_GREEN(E_W);
        ESOS_TASK_WAIT_TICKS(10000);
        // third color
        SET_RED(N_S);
        SET_AMBER(E_W);
        ESOS_TASK_WAIT_TICKS(3000);
        // fourth color
        SET_TURN(N_S);
        SET_RED(E_W);
        ESOS_TASK_WAIT_TICKS(10000);
        // fifth color
        SET_GREEN(N_S);
        SET_RED(E_W);
        ESOS_TASK_WAIT_TICKS(10000);
        // sixth color
        SET_AMBER(N_S);
        SET_RED(E_W);
        ESOS_TASK_WAIT_TICKS(3000);
        } else {
            // Rush Hour conditions
            // first color
            SET_RED(N_S);
            SET_TURN(E_W);
            ESOS_TASK_WAIT_TICKS(10000);
            // second color
            SET_RED(N_S);
            SET_GREEN(E_W);
            ESOS_TASK_WAIT_TICKS(30000);
            // third color
            SET_RED(N_S);
            SET_AMBER(E_W);
            ESOS_TASK_WAIT_TICKS(3000);
            // fourth color
            SET_RED(N_S);
            SET_RED(E_W);
            ESOS_TASK_WAIT_TICKS(1000);
            // fifth color
            SET_TURN(N_S);
            SET_RED(E_W);
            ESOS_TASK_WAIT_TICKS(10000);
            // sixth color
            SET_GREEN(N_S);
            SET_RED(E_W);
            ESOS_TASK_WAIT_TICKS(30000);
            // seventh color
            SET_AMBER(N_S);
            SET_RED(E_W);
            ESOS_TASK_WAIT_TICKS(3000);
            // eighth color
            SET_RED(N_S);
            SET_RED(E_W);
            ESOS_TASK_WAIT_TICKS(1000);
        }
    }
    ESOS_TASK_END();
}

// timer for toggling turn signal
ESOS_USER_TIMER(turn_signal){
        if((SW3_PRESSED && state[E_W] == TURN) || (SW3_RELEASED && state[N_S] == TURN)){
            LED1_OFF();
            LED2_OFF();
            TOGGLE_GREEN();
        }
}

// user init function
void user_init(void){
    // Configure leds
    CONFIG_LED1();
    CONFIG_LED2();
    CONFIG_LED3();
    
    // default led values
    LED1_OFF();
    LED2_OFF();
    LED3_OFF();
    
    // configure switches
    CONFIG_SW3();
    CONFIG_SW1();
    
    // register user tasks
    esos_RegisterTask(switch_state);
    esos_RegisterTask(traffic_light);
    esos_RegisterTimer(turn_signal, 125);
}