// ECE 4273/6473 Embedded Systems
// Lab 3 ESOS UI Service


#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"
#include "revF14.h"
#include <stdio.h>

#define ESC_KEY 0x1B
#define PLUS_KEY 0x2B
#define MINUS_KEY 0x2D

enum MENU_STATE {
    START,
    SWITCH_SETTINGS,
    RPG_SETTINGS,
    SW1_PERIOD,
    SW2_PERIOD,
    SW3_PERIOD,
    RPG_SLOW,
    RPG_MEDIUM,
    RPG_FAST
};

static char str_SETTINGS_MENU[] =   "Double Press Settings (1) RPG Settings (2)\n";
static char str_SWITCH_MENU[] =     "Double Press for SW1 (1), SW2 (2), SW3 (3)\n";
static char str_RPG_MENU[] =        "RPG threshold slow (1), medium (2), fast (3)\n";

static char str_sw1p_CUR_VALUE[] = "Increase (+) or Decrease (-) SW1 Period: ";
static char str_sw2p_CUR_VALUE[] = "Increase (+) or Decrease (-) SW2 Period: ";
static char str_sw3p_CUR_VALUE[] = "Increase (+) or Decrease (-) SW3 Period: ";

static char str_rpgs_CUR_VALUE[] = "Increase (+) or Decrease (-) RPG Slow Threshold: ";
static char str_rpgm_CUR_VALUE[] = "Increase (+) or Decrease (-) RPG Medium Threshold: ";
static char str_rpgf_CUR_VALUE[] = "Increase (+) or Decrease (-) RPG Fast Threshold: ";

ESOS_USER_TASK(menuUI){
    static uint8_t u8_input = 0x00;
    static enum MENU_STATE menu_state = START;

    ESOS_TASK_BEGIN();

    while (TRUE){
        if(menu_state == START){
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SETTINGS_MENU);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch(u8_input){
                case '1':
                    menu_state = SWITCH_SETTINGS;
                    break;
                case '2':
                    menu_state = RPG_SETTINGS;
                    break;
                default:
                    menu_state = START;
                    break;
            }
        }

        else if(menu_state == SWITCH_SETTINGS){
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SWITCH_MENU);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case '1':
                menu_state = SW1_PERIOD;
                break;
            case '2':
                menu_state = SW2_PERIOD;
                break;
            case '3':
                menu_state = SW3_PERIOD;
                break;
            case ESC_KEY:
                menu_state = START;
                break;
            default:
                menu_state = SWITCH_SETTINGS;
                break;
            }
        }

        else if (menu_state == RPG_SETTINGS){
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_RPG_MENU);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case '1':
                menu_state = RPG_SLOW;
                break;
            case '2':
                menu_state = RPG_MEDIUM;
                break;
            case '3':
                menu_state = RPG_FAST;
                break;
            case ESC_KEY:
                menu_state = START;
                break;
            default:
                menu_state = RPG_SETTINGS;
                break;
            }
        }


        else if(menu_state = SW1_PERIOD){
            static uint16_t u16_sw1_period;
            u16_sw1_period = esos_uiF14_getSW1Period();

            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_sw1p_CUR_VALUE);
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING((uint32_t)u16_sw1_period);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case PLUS_KEY:
                u16_sw1_period = esos_uiF14_getSW1Period();
                esos_uiF14_setSW1Period(u16_sw1_period + 1);
                break;
            case MINUS_KEY:
                u16_sw1_period = esos_uiF14_getSW1Period();
                esos_uiF14_setSW1Period(u16_sw1_period - 1);
                break;
            case ESC_KEY:
                menu_state = SWITCH_SETTINGS;
                break;
            default:
                menu_state = SW1_PERIOD;
                break;
            }            
        }


        else if(menu_state == SW2_PERIOD){
            static uint16_t u16_sw2_period;
            u16_sw2_period = esos_uiF14_getSW2Period();

            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_sw2p_CUR_VALUE);
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING((uint32_t)u16_sw2_period);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case PLUS_KEY:
                u16_sw2_period = esos_uiF14_getSW2Period();
                esos_uiF14_setSW2Period(u16_sw2_period + 1);
                break;
            case MINUS_KEY:
                u16_sw2_period = esos_uiF14_getSW2Period();
                esos_uiF14_setSW2Period(u16_sw2_period - 1);
                break;
            case ESC_KEY:
                menu_state = SWITCH_SETTINGS;
                break;
            default:
                menu_state = SW2_PERIOD;
                break;
            }
        }

        
        else if(menu_state == SW3_PERIOD){
            static uint16_t u16_sw3_period;
            u16_sw3_period = esos_uiF14_getSW3Period();

            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_sw3p_CUR_VALUE);
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING((uint32_t)u16_sw3_period);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case PLUS_KEY:
                u16_sw3_period = esos_uiF14_getSW3Period();
                esos_uiF14_setSW3Period(u16_sw3_period + 1);
                break;
            case MINUS_KEY:
                u16_sw3_period = esos_uiF14_getSW3Period();
                esos_uiF14_setSW3Period(u16_sw3_period - 1);
                break;
            case ESC_KEY:
                menu_state = SWITCH_SETTINGS;
                break;
            default:
                menu_state = SW3_PERIOD;
                break;
            }
        }


        else if (menu_state == RPG_SLOW) {
            static uint16_t i16_rpg_slow;
            i16_rpg_slow = esos_uiF14_getRPGSlow();

            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpgs_CUR_VALUE);
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING((uint32_t)i16_rpg_slow);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case PLUS_KEY:
                i16_rpg_slow = esos_uiF14_getRPGSlow();
                esos_uiF14_setRPGSlow(i16_rpg_slow + 1);
                break;
            case MINUS_KEY:
                i16_rpg_slow = esos_uiF14_getRPGSlow();
                esos_uiF14_setRPGSlow(i16_rpg_slow - 1);
                break;
            case ESC_KEY:
                menu_state = RPG_SETTINGS;
                break;
            default:
                menu_state = RPG_SLOW;
                break;
            }
        } 
        
        
        else if (menu_state == RPG_MEDIUM) {
            static uint16_t i16_rpg_med;
            i16_rpg_med = esos_uiF14_getRPGMedium();

            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpgm_CUR_VALUE);
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING((uint32_t)i16_rpg_med);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case PLUS_KEY:
                i16_rpg_med = esos_uiF14_getRPGMedium();
                esos_uiF14_setRPGMedium(i16_rpg_med + 1);
                break;
            case MINUS_KEY:
                i16_rpg_med = esos_uiF14_getRPGMedium();
                esos_uiF14_setRPGMedium(i16_rpg_med - 1);
                break;
            case ESC_KEY:
                menu_state = RPG_SETTINGS;
                break;
            default:
                menu_state = RPG_MEDIUM;
                break;
            }
        }
        
        
        else if (menu_state == RPG_FAST) {
            static uint16_t i16_rpg_fast;
            i16_rpg_fast = esos_uiF14_getRPGFast();

            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_STRING(str_rpgf_CUR_VALUE);
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING((uint32_t)i16_rpg_fast);
            ESOS_TASK_WAIT_ON_SEND_UINT8('\n');
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

            ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
            ESOS_TASK_WAIT_ON_GET_UINT8(u8_input);
            ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

            switch (u8_input) {
            case PLUS_KEY:
                i16_rpg_fast = esos_uiF14_getRPGFast();
                esos_uiF14_setRPGFast(i16_rpg_fast + 1);
                break;
            case MINUS_KEY:
                i16_rpg_fast = esos_uiF14_getRPGFast();
                esos_uiF14_setRPGFast(i16_rpg_fast - 1);
                break;
            case ESC_KEY:
                menu_state = RPG_SETTINGS;
                break;
            default:
                menu_state = RPG_FAST;
                break;
            }
        }
    }
    ESOS_TASK_END();
}


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
    esos_RegisterTask(menuUI);
}