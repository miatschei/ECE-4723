// ECE 4273/6473 Embedded Systems
// Lab 3 ESOS UI Service


#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"
#include "revF14.h"
#include <stdio.h>

// Esc key for navigation
#define ESC_KEY 0x1B

// Menu States
#define START               0 // Macros easier to use across multiple files
#define SWITCH_SETTINGS     1 // Functions split up across tasks to help with memory
#define RPG_SETTINGS        2 // But still need to be able to share state data across tasks
#define SW1_PERIOD          3
#define SW2_PERIOD          4
#define RPG_LOWER           5
#define RPG_UPPER           6

// Strings for menu interface
static char str_SETTINGS_MENU[] =   "START: Press ESC at any point to return to prev menu\nSelect From: Double Press Settings (1) RPG Settings (2)\n\n";
static char str_SWITCH_MENU[] =     "Select Double Press Period: SW1 (1), SW2 (2)\n";
static char str_RPG_MENU[] =        "Select RPG Threshold: Lower (1), Upper (2)\n";

static char str_SW1_SET[] =          "Select SW1 Period:\n250 ms (1), 1000 ms (2), 2000 ms (3), 3000 ms (4)\nCurrent SW1 Period: ";
static char str_SW2_SET[] =          "Select SW2 Period:\n250 ms (1), 1000 ms (2), 2000 ms (3), 3000 ms (4)\nCurrent SW2 Period: ";

static char str_RPGLOWER_SET[] =     "Select Lower Threshold for RPG:\n0 (1), 15 (2), 40 (3), 60 (4)\nCurrent lower threshold: ";
static char str_RPGLOWER_VAL[] =     "Must Be LESS THAN Current Upper Threshold: ";
static char str_RPGUPPER_SET[] =      "Select upper threshold for RPG:\n15 (1), 40 (2), 60 (3), 100 (4)\nCurrent upper threshold: ";
static char str_RPGUPPER_VAL[] =     "Must Be GREATER THAN Current Lower Threshold: ";


ESOS_USER_TASK(menuUI_Start){
    // Starting Menu
    static uint8_t u8_input = 0x00; // defining local variables
    static uint16_t next_state;
    static uint16_t menu_state;
    ESOS_TASK_BEGIN();
    while(TRUE){
        menu_state = esos_uiF14_getMenuState(); // Get menu state
        if(menu_state == START){
            // Printing out UI strings
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SETTINGS_MENU);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            // Menu navigation
            if(u8_input == '1'){
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == '2'){
                next_state = RPG_SETTINGS;
            } else {
                next_state = START;
            } esos_uiF14_setMenuState(next_state); // store next state
        } 
    ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}

ESOS_USER_TASK(menuUI_Switches){
    // Menus for switches
    static uint8_t u8_input = 0x00;
    static uint16_t next_state;
    static uint16_t menu_state;
    static char u16_sw1_period[16];
    static char u16_sw2_period[16];
    ESOS_TASK_BEGIN();
    while(TRUE){
        menu_state = esos_uiF14_getMenuState();  // Get menu state
        if(menu_state == SWITCH_SETTINGS){
            // User interface strings
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SWITCH_MENU);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            // Navigation
            if(u8_input == '1'){
                next_state = SW1_PERIOD;
            } else if(u8_input == '2'){
                next_state = SW2_PERIOD;
            } else if(u8_input == ESC_KEY){
                next_state = START;
            } else {
                next_state = SWITCH_SETTINGS;
            } esos_uiF14_setMenuState(next_state); // Store next state
        } else if(menu_state == SW1_PERIOD){
            // Convert int to str
            sprintf(u16_sw1_period, "%d ms", esos_uiF14_getSW1Period()); 

            // UI strings
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1_SET);
            ESOS_TASK_WAIT_ON_SEND_STRING(u16_sw1_period);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            // Navigation
            if(u8_input == '1'){
                esos_uiF14_setSW1Period(250); // Set new period
                next_state = SWITCH_SETTINGS; // Go back to settings
            } else if(u8_input == '2'){
                esos_uiF14_setSW1Period(1000);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == '3'){
                esos_uiF14_setSW1Period(2000);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == '4'){
                esos_uiF14_setSW1Period(3000);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == ESC_KEY){
                next_state = SWITCH_SETTINGS;
            } else {
                next_state = SW1_PERIOD;
            }  esos_uiF14_setMenuState(next_state); // Store next state
        } else if(menu_state == SW2_PERIOD){
            // Int to String
            sprintf(u16_sw2_period, "%d ms", esos_uiF14_getSW2Period());

            // User interface strings
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW2_SET);
            ESOS_TASK_WAIT_ON_SEND_STRING(u16_sw2_period);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            // Navigation
            if(u8_input == '1'){
                esos_uiF14_setSW2Period(250);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == '2'){
                esos_uiF14_setSW2Period(1000);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == '3'){
                esos_uiF14_setSW2Period(2000);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == '4'){
                esos_uiF14_setSW2Period(3000);
                next_state = SWITCH_SETTINGS;
            } else if(u8_input == ESC_KEY){
                next_state = SWITCH_SETTINGS;
            } else {
                next_state = SW2_PERIOD;
            } esos_uiF14_setMenuState(next_state); // store next state
        }
    ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
    
}

ESOS_USER_TASK(menuUI_RPG){
    // menus for RPG
    static uint8_t u8_input = 0x00;
    static uint16_t next_state;
    static uint16_t menu_state;
    static char str_rpg_lower[16];
    static char str_rpg_upper[16];
    ESOS_TASK_BEGIN();
    while(TRUE){
        menu_state = esos_uiF14_getMenuState(); // Get menu state
        if(menu_state == RPG_SETTINGS){
            // Interface
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_RPG_MENU);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();
            // Navigation
            if(u8_input == '1'){
                next_state = RPG_LOWER;
            } else if(u8_input == '2'){
                next_state = RPG_UPPER;
            } else if(u8_input == ESC_KEY){
                next_state = START;
            } else{
                next_state = RPG_SETTINGS;
            } esos_uiF14_setMenuState(next_state); // Store next state
        } else if(menu_state == RPG_LOWER){
            // Storing integer values to strings
            sprintf(str_rpg_lower, "%d", esos_uiF14_getRPGLower());
            sprintf(str_rpg_upper, "%d", esos_uiF14_getRPGUpper());
            // Interface
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_RPGLOWER_VAL);
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpg_upper);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_WAIT_ON_SEND_STRING(str_RPGLOWER_SET);
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpg_lower);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();
            // Navigation
            if(u8_input == '1'){
                esos_uiF14_setRPGLower(0);   // 0 is lowest, always valid
                next_state = RPG_SETTINGS;
            } else if(u8_input == '2'){
                if(esos_uiF14_getRPGUpper() > 15){  // check if lower than upper limit
                    esos_uiF14_setRPGLower(15);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_LOWER;      // if not, go back
            } else if(u8_input == '3'){
                if(esos_uiF14_getRPGUpper() > 40){ 
                    esos_uiF14_setRPGLower(40);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_LOWER;
            } else if(u8_input == '4'){
                if(esos_uiF14_getRPGUpper() > 60){
                    esos_uiF14_setRPGLower(60);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_LOWER;
            } else if(u8_input == ESC_KEY){
                next_state = RPG_SETTINGS;
            } else {
                next_state = RPG_LOWER;
            } esos_uiF14_setMenuState(next_state);
        } else if(menu_state == RPG_UPPER){
            // Integers to strings
            sprintf(str_rpg_upper, "%d", esos_uiF14_getRPGUpper());
            sprintf(str_rpg_lower, "%d", esos_uiF14_getRPGLower());
            // Interface
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_RPGUPPER_VAL);
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpg_lower);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_WAIT_ON_SEND_STRING(str_RPGUPPER_SET);
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpg_upper);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();
            // Navigation
            if(u8_input == '1'){
                if(esos_uiF14_getRPGLower() < 15){ // Check if greater than lower limit
                    esos_uiF14_setRPGUpper(15);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_UPPER;     // If not, try again
            } else if(u8_input == '2'){
                if(esos_uiF14_getRPGLower() < 40){
                    esos_uiF14_setRPGUpper(40);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_UPPER;
            } else if(u8_input == '3'){
                if(esos_uiF14_getRPGLower() < 60){ 
                    esos_uiF14_setRPGUpper(60);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_UPPER;
            } else if(u8_input == '4'){
                if(esos_uiF14_getRPGLower() < 100){  // 100 is highest value, always valid
                    esos_uiF14_setRPGUpper(100);
                    next_state = RPG_SETTINGS;
                } else next_state = RPG_UPPER;
            } else if(u8_input == ESC_KEY){
                next_state = RPG_SETTINGS;
            } else {
                next_state = RPG_UPPER;
            } esos_uiF14_setMenuState(next_state); // Store next state
        }
    ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}




ESOS_USER_TASK(hardware_function){
    ESOS_TASK_BEGIN();
    while(TRUE){
        ESOS_TASK_WAIT_TICKS(250); // Yield control

        static char str_SW1_PRESSED[] = "Switch 1 pressed\n";    // Showing function of switches  
        if (esos_uiF14_isSW1Pressed()) {                         // Prints if switch has been pressed / double pressed
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

        static char str_SW1_DOUBLEPRESS[] = "Switch 1 double pressed\n";
        if (esos_uiF14_isSW1DoublePressed()) {
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1_DOUBLEPRESS);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            _st_esos_uiF14Data.b_SW1DoublePressed = false;
        }

        static char str_SW2_DOUBLEPRESS[] = "Switch 2 double pressed\n";
        if (esos_uiF14_isSW2DoublePressed()) {
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW2_DOUBLEPRESS);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            _st_esos_uiF14Data.b_SW2DoublePressed = false;
        }

        static char str_RPG_TURNING_CW[] =      "RPG turning CW ";
        static char str_RPG_TURNING_CCW[] =     "RPG turning CCW ";
        static char str_RPG_TURNING_SLOW[] =    "slow\n";
        static char str_RPG_TURNING_MED[] =     "med\n";
        static char str_RPG_TURNING_FAST[] =    "fast\n";
        static char str_OUTBOUND[32];


        if (esos_uiF14_isRpgTurning()){                             // Shows RPG function
            if (esos_uiF14_isRpgTurningCW()){                       // Prints out how fast RPG is spinning and in what direction
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
                if(esos_uiF14_isRpgTurningSlow()){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CCW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_SLOW);
                }
                if(esos_uiF14_isRpgTurningMedium()){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CCW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_MED);
                }
                if(esos_uiF14_isRpgTurningFast()){
                    strcpy(str_OUTBOUND, str_RPG_TURNING_CCW);
                    strcat(str_OUTBOUND, str_RPG_TURNING_FAST);             
                }
            }
        }
        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING(str_OUTBOUND);
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
        strcpy(str_OUTBOUND, "");
        ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}


void user_init(){
    // Run esos_uiF14 setup module
    config_esos_uiF14();

    // Register local tasks
    esos_RegisterTask(hardware_function);
    esos_RegisterTask(menuUI_Start);
    esos_RegisterTask(menuUI_Switches);
    esos_RegisterTask(menuUI_RPG);
}