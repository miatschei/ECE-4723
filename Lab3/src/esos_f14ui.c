/*******************************************************************
 * 
 * C code framework for ESOS user-interface (UI) service
 * 
 *    requires the EMBEDDED SYSTEMS target rev. F14
 * 
 * ****************************************************************/
#include "esos_f14ui.h"
#include "revF14.h"
#include "esos.h"
#include "esos_pic24.h"

volatile _st_esos_uiF14Data_t _st_esos_uiF14Data;

// PRIVATE FUNCTIONS
inline void _esos_uiF14_setRPGCounter (uint16_t newValue) {
    _st_esos_uiF14Data.u16_RPGCounter = newValue;
    return;
}

inline void _esos_uiF14_setLastRPGCounter (uint16_t newValue) {
    _st_esos_uiF14Data.u16_lastRPGCounter = newValue;
    return;
}

// PUBLIC SWITCH FUNCTIONS
inline bool esos_uiF14_getSW1Pressed (void) {
    return (_st_esos_uiF14Data.b_SW1Pressed==true);
}

inline bool esos_uiF14_getSW1Released (void) {
    return (_st_esos_uiF14Data.b_SW1Pressed==false);
}

inline bool esos_uiF14_getSW1DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW1DoublePressed==true);
}

/***** SW2 and SW3 need need similar  *****/

// PUBLIC LED FUNCTIONS

inline bool esos_uiF14_isLED1On (void) {
    return (_st_esos_uiF14Data.b_LED1On==true);
}

inline bool esos_uiF14_isLED1Off (void) {
    return (_st_esos_uiF14Data.b_LED1On==false);
}

inline void esos_uiF14_turnLED1On (void) {
    _st_esos_uiF14Data.b_LED1On = true;
    return;
}

inline void esos_uiF14_turnLED1Off (void) {
    _st_esos_uiF14Data.b_LED1On = false;
    return;
}

inline void esos_uiF14_toggleLED1 (void) {
    _st_esos_uiF14Data.b_LED1On ^= 1;
    return;
}

inline void esos_uiF14_flashLED1( uint16_t u16_period) {
    _st_esos_uiF14Data.u16_LED1FlashPeriod = u16_period;
    return;
}

/****** LED2 and LED3 will need similar.  ********/
/****** RED, GREEN, and YELLOW functions need to be created *******/

// PUBLIC RPG FUNCTIONS

inline uint16_t esos_uiF14_getRpgValue_u16 ( void ) {
    return _st_esos_uiF14Data.u16_RPGCounter;
}

inline bool esos_uiF14_isRpgTurning ( void ) {
    return (esos_uiF14_getRpgVelocity_i16() != 0);
}

inline bool esos_uiF14_isRpgTurningSlow( void ) {
  // not yet implemented
  return 0; //placeholder return statements
}

inline bool esos_uiF14_isRpgTurningMedium( void ) {
  // not yet implemented
  return 0;
}

inline bool esos_uiF14_isRpgTurningFast( void ) {
  // not yet implemented
  return 0;
}

inline bool esos_uiF14_isRpgTurningCW( ) {
  // not yet implemented
  return 0;
}

inline bool esos_uiF14_isRpgTurningCCW( void ) {
  // not yet implemented

  return 0;
}

inline int16_t esos_uiF14_getRpgVelocity_i16( void ) {
  // not yet implemented
  return 0;
}

uint16_t last_state = 0; // stores last state change
uint16_t curr_state = 0; // stores current state change
uint16_t dbnc_state = 0; // stores intermediate state change for debouncing
uint16_t rpg_tmr = 0;    // timer count for debouncing

ESOS_USER_TIMER( dbnc_rpg ){               // timer to debounce rpg input
  if(rpg_tmr == 10){                       // if state hasnt changed for 10 ms
    last_state = curr_state;               // store old state
    curr_state = dbnc_state;               // store new state
    rpg_tmr = 0;                           // reset timer
  } else if( dbnc_state == RPG_STATE ){    // if state hasn't changed
    rpg_tmr++;                             // increment timer
  } else{                                  // if state changed
    dbnc_state = RPG_STATE;                // set new state and restart timer
    rpg_tmr = 0;                           // reset timer
  } 
}

int16_t get_rpg_dir(uint16_t state, uint16_t l_state){ // returns 1 if CW, -1 if CCW, 0 if states skip
  if(state == 3){                                         // CW: 3 1 0 2  CCW: 3 2 0 1
    if(l_state == 2) return 1;   // CW
    if(l_state == 1) return -1;  // CCW
  } else if(state == 1){
    if(l_state == 3) return 1;   // CW
    if(l_state == 0) return -1;  // CCW
  } else if(state == 0){
    if(l_state == 1) return 1;   // CW
    if(l_state == 2) return -1;  // CCW
  } else if(state == 2){
    if(l_state == 0) return 1;   // CW
    if(l_state == 3) return -1;  // CCW
  } else return 0;
}



int16_t dir = 0;
int16_t last_dir = 0;
ESOS_USER_TIMER(process_rpg){
  // check states
  last_dir = dir;
  dir = get_rpg_dir(curr_state, last_state);
  if( dir != last_dir ){
    if(dir == 1){
      // cw
      LED1 = 1;
      LED2 = 0;
    } else if(dir == -1){
      LED1 = 0;
      LED2 = 1;
    }
  }

}



// UIF14 INITIALIZATION FUNCTION
void config_esos_uiF14() {
  // setup your UI implementation
  CONFIG_RPG();
  CONFIG_LED1();
  CONFIG_LED2();


  LED1 = 0;
  LED2 = 0;


  esos_RegisterTimer(dbnc_rpg, 1);
  esos_RegisterTimer(process_rpg, 10);
}


