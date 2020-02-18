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

inline uint16_t _esos_uiF14_getRPGCounter (void) {
    return _st_esos_uiF14Data.u16_RPGCounter;
}

inline void _esos_uiF14_setLastRPGCounter (uint16_t newValue) {
    _st_esos_uiF14Data.u16_lastRPGCounter = newValue;
    return;
}

inline uint16_t _esos_uiF14_getLastRPGCounter (void) {
    return _st_esos_uiF14Data.u16_lastRPGCounter;
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
  // CW: 3 1 0 2  CCW: 3 2 0 1
  uint16_t state = _esos_uiF14_getRPGCounter(); 
  uint16_t last_state = _esos_uiF14_getLastRPGCounter();
  if((state == 3) && (last_state == 2)) return TRUE;
  else if((state == 1) && (last_state == 3)) return TRUE;
  else if((state == 0) && (last_state == 1)) return TRUE;
  else if((state == 2) && (last_state == 0)) return TRUE;
  else return FALSE;
}

inline bool esos_uiF14_isRpgTurningCCW( void ) {
  // CW: 3 1 0 2  CCW: 3 2 0 1
  uint16_t state = _esos_uiF14_getRPGCounter(); 
  uint16_t last_state = _esos_uiF14_getLastRPGCounter();
  if((state == 3) && (last_state == 1)) return TRUE;
  else if((state == 2) && (last_state == 3)) return TRUE;
  else if((state == 0) && (last_state == 2)) return TRUE;
  else if((state == 1) && (last_state == 0)) return TRUE;
  else return FALSE;
}

inline int16_t esos_uiF14_getRpgVelocity_i16( void ) {
  // not yet implemented
  return 0;
}

//uint16_t last_state = 0; // stores last state change
//uint16_t curr_state = 0; // stores current state change
uint16_t dbnc_state = 0; // stores intermediate state change for debouncing
uint16_t rpg_tmr = 0;    // timer count for debouncing

ESOS_USER_TIMER( dbnc_rpg ){               // timer to debounce rpg input
  if(rpg_tmr == 10){                       // if state hasnt changed for 10 ms
    _esos_uiF14_setLastRPGCounter(_esos_uiF14_getRPGCounter());               // store old state
    _esos_uiF14_setRPGCounter(dbnc_state);               // store new state
    rpg_tmr = 0;                           // reset timer
  } else if( dbnc_state == RPG_STATE ){    // if state hasn't changed
    rpg_tmr++;                             // increment timer
  } else{                                  // if state changed
    dbnc_state = RPG_STATE;                // set new state and restart timer
    rpg_tmr = 0;                           // reset timer
  } 
}



uint16_t stateCheck = 0; 
uint16_t last_stateCheck = 0;
int16_t dir = 0;
int16_t last_dir = 0;
char psz_state[16];
ESOS_USER_TIMER(debug_rpg){
  // check states
  stateCheck = _esos_uiF14_getRPGCounter(); 
  last_stateCheck = _esos_uiF14_getLastRPGCounter();
  if(stateCheck != last_stateCheck){
    sprintf(psz_state, "%d \n", stateCheck); // debug hope it works
     __esos_unsafe_PutString(psz_state);
  }
  if(esos_uiF14_isRpgTurningCW()){
    LED1 = 1;
    LED2 = 0;
  } else if(esos_uiF14_isRpgTurningCCW()){
    LED1 = 0;
    LED2 = 1;
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
  esos_RegisterTimer(debug_rpg, 10);
}


