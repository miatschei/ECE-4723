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

// PRIVATE FUNCTIONS ///////////////////////////////////////////////////////////
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


// PUBLIC SWITCH FUNCTIONS ///////////////////////////////////////////////////////////

//SW1 ----------------------------------------------------
inline bool esos_uiF14_isSW1Pressed (void) {         // should be "isSW1", check all functions. Should not return a true, just the struct properties
    return (_st_esos_uiF14Data.b_SW1Pressed);
}

inline bool esos_uiF14_isSW1Released (void) {
    return (!_st_esos_uiF14Data.b_SW1Pressed);
}

inline bool esos_uiF14_isSW1DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW1DoublePressed);
}

inline uint16_t esos_uiF14_getSW1Period(void){
  return _st_esos_uiF14Data.u16_SW1Period;
}
inline uint16_t esos_uiF14_setSW1Period(uint16_t period){
  _st_esos_uiF14Data.u16_SW1Period = period;
}

//SW2 -----------------------------------------------------
inline bool esos_uiF14_isSW2Pressed (void) {
    return (_st_esos_uiF14Data.b_SW2Pressed);
}

inline bool esos_uiF14_isSW2Released (void) {
    return (!_st_esos_uiF14Data.b_SW2Pressed);
}

inline bool esos_uiF14_isSW2DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW2DoublePressed);
}

inline uint16_t esos_uiF14_getSW2Period(void){
  return _st_esos_uiF14Data.u16_SW2Period;
}
inline uint16_t esos_uiF14_setSW2Period(uint16_t period){
  _st_esos_uiF14Data.u16_SW2Period = period;
}

//SW3 --------------------------------------------------------
inline bool esos_uiF14_isSW3Pressed (void) {
    return (_st_esos_uiF14Data.b_SW3Pressed);
}

inline bool esos_uiF14_isSW3Released (void) {
    return (!_st_esos_uiF14Data.b_SW3Pressed);
}

inline bool esos_uiF14_isSW3DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW3DoublePressed);
}

inline uint16_t esos_uiF14_getSW3Period(void){
  return _st_esos_uiF14Data.u16_SW3Period;
}
inline uint16_t esos_uiF14_setSW3Period(uint16_t period){
  _st_esos_uiF14Data.u16_SW3Period = period;
}


// PUBLIC LED FUNCTIONS ///////////////////////////////////////////////////

inline bool esos_uiF14_isLED1On (void) {
    return (_st_esos_uiF14Data.b_LED1On);
}

inline bool esos_uiF14_isLED1Off (void) {
    return (!_st_esos_uiF14Data.b_LED1On);
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

inline bool esos_uiF14_isLED2On (void) {
    return (_st_esos_uiF14Data.b_LED2On);
}

inline bool esos_uiF14_isLED2Off (void) {
    return (!_st_esos_uiF14Data.b_LED2On);
}

inline void esos_uiF14_turnLED2On (void) {
    _st_esos_uiF14Data.b_LED2On = true;
    return;
}

inline void esos_uiF14_turnLED2Off (void) {
    _st_esos_uiF14Data.b_LED2On = false;
    return;
}

inline void esos_uiF14_toggleLED2 (void) {
    _st_esos_uiF14Data.b_LED2On ^= 1;
    return;
}

inline void esos_uiF14_flashLED2( uint16_t u16_period) {
    _st_esos_uiF14Data.u16_LED2FlashPeriod = u16_period;
    return;
}

inline bool esos_uiF14_isLED3On (void) {
    return (_st_esos_uiF14Data.b_LED3On);
}

inline bool esos_uiF14_isLED3Off (void) {
    return (!_st_esos_uiF14Data.b_LED3On);
}

inline void esos_uiF14_turnLED3On (void) {
    _st_esos_uiF14Data.b_LED3On = true;
    return;
}

inline void esos_uiF14_turnLED3Off (void) {
    _st_esos_uiF14Data.b_LED3On = false;
    return;
}

inline void esos_uiF14_toggleLED3 (void) {
    _st_esos_uiF14Data.b_LED3On ^= 1;
    return;
}

inline void esos_uiF14_flashLED3( uint16_t u16_period) {
    _st_esos_uiF14Data.u16_LED3FlashPeriod = u16_period;
    return;
}

// PUBLIC RPG FUNCTIONS //////////////////////////////////////////////////////////

inline uint16_t esos_uiF14_getRpgValue_u16 ( void ) {
    return _st_esos_uiF14Data.u16_RPGCounter;
}

inline bool esos_uiF14_isRpgTurning ( void ) {
    return (esos_uiF14_getRpgVelocity_i16() != 0);
}

inline bool esos_uiF14_isRpgTurningSlow( void ) {
  return ((abs(esos_uiF14_getRpgVelocity_i16())) && (abs(esos_uiF14_getRpgVelocity_i16()) <= _st_esos_uiF14Data.u16_RPGLower));
}

inline bool esos_uiF14_isRpgTurningMedium( void ) {
  return ((_st_esos_uiF14Data.u16_RPGLower < abs(esos_uiF14_getRpgVelocity_i16())) && (abs(esos_uiF14_getRpgVelocity_i16()) <= _st_esos_uiF14Data.u16_RPGUpper));
}

inline bool esos_uiF14_isRpgTurningFast( void ) {
  return (_st_esos_uiF14Data.u16_RPGUpper < abs(esos_uiF14_getRpgVelocity_i16()));
}

inline uint16_t esos_uiF14_getRPGLower(void){
  return _st_esos_uiF14Data.u16_RPGLower;
}
inline void esos_uiF14_setRPGLower(uint16_t val){
  _st_esos_uiF14Data.u16_RPGLower = val;
}

inline uint16_t esos_uiF14_getRPGUpper(void){
  return _st_esos_uiF14Data.u16_RPGUpper;
}
inline void esos_uiF14_setRPGUpper(uint16_t val){
  _st_esos_uiF14Data.u16_RPGUpper = val;
}


inline bool esos_uiF14_isRpgTurningCW( void ) {
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
  if(esos_uiF14_isRpgTurningCW()){ // positive rotation
    return (int16_t) _st_esos_uiF14Data.u16_RPGVelocity;
  } else if(esos_uiF14_isRpgTurningCCW()){ // negtive rotation
    return (int16_t) _st_esos_uiF14Data.u16_RPGVelocity * -1;
  } else return 0; // invalid turning
}

// PUBLIC MENU STATE FUNCTIONs //////////////////////////////
inline void esos_uiF14_setMenuState(uint16_t next_state) {
  _st_esos_uiF14Data.u16_menuState = next_state;
  return;
}

inline int16_t esos_uiF14_getMenuState(void) {
  return _st_esos_uiF14Data.u16_menuState;
}

uint16_t dbnc_state = 0; // stores intermediate state change for debouncing
uint16_t vel_tmr = 0;    // timer count for debouncing
int16_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0}; // valid movements from state to state

ESOS_USER_TIMER( dbnc_rpg ){ 
  // look at last state and current state
  vel_tmr++;
  dbnc_state = ((_esos_uiF14_getRPGCounter() << 2) | RPG_STATE); // old state, new state in 0000 format
  if(rot_enc_table[dbnc_state]){
    // valid state change occured
    _esos_uiF14_setLastRPGCounter(_esos_uiF14_getRPGCounter());
    _esos_uiF14_setRPGCounter(RPG_STATE);
    // calc velocity in clicks per second
    if(dbnc_state == 13 || dbnc_state == 14){ // transitions from 0 to high 
      _st_esos_uiF14Data.u16_RPGVelocity = ((uint16_t) 1000/vel_tmr);
      vel_tmr = 0;
    }
  } else if (vel_tmr >= 500){
    // not moving set velocity to zero
    _st_esos_uiF14Data.u16_RPGVelocity = 0;
  }
}


uint32_t sw1_old_time = 0; 
uint16_t sw1_state = 0;

uint8_t  led1_f = 0;
//     SW1_IDLE 0
//     SW1_SINGLE_HIGH  1
//     SW1_SINGLE_LOW 2
//     SW1_WAIT  3

//display leds
#define SW1_SHOW 0
#define SW2_SHOW 1
uint8_t led_display;
enum sw1_led_states {
  L1_OFF, 
  L1_ON, 
  L1_BLINK,
} sw1_led_state;

enum sw2_led_states {
  L2_OFF, 
  L2_ON, 
  L2_BLINK,
} sw2_led_state;


ESOS_USER_TASK(switch_t1){
  ESOS_TASK_BEGIN();
  while(true){
    if(SW1_PRESSED && sw1_state == 0){
      ESOS_TASK_WAIT_TICKS( 25 ); //debounce
      _st_esos_uiF14Data.b_SW1Pressed = true; 
      sw1_led_state = L1_ON; 
      sw1_state = 1; 
    }
    else if (sw1_state == 1){
     
      sw1_led_state = L1_ON; //LED1 = 1;

      if (SW1_RELEASED){
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        _st_esos_uiF14Data.b_SW1Pressed = false; 
        sw1_led_state = L1_OFF; //LED1 = 0;
        sw1_state = 2;
        sw1_old_time = esos_GetSystemTick();
      }
    }
    else if (sw1_state == 2){
      //wait for second press here
      if ((esos_GetSystemTick() - sw1_old_time) >= _st_esos_uiF14Data.u16_SW1Period){
        sw1_state = 0; //go back to first state
      }

      if (((esos_GetSystemTick() - sw1_old_time) <= _st_esos_uiF14Data.u16_SW1Period) && SW1_PRESSED){
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        _st_esos_uiF14Data.b_SW1DoublePressed = true;
        sw1_state = 3;
      }
    }
    else if(sw1_state == 3){
      //blink led
      sw1_led_state = L1_BLINK;
      //should we wait here for blinking to stop? yah probably.
      //return to first state
      sw1_state = 4;
    } 
    else if (sw1_state == 4){
      sw1_led_state = L1_BLINK;
      ESOS_TASK_WAIT_TICKS( 7*_st_esos_uiF14Data.u16_LED1FlashPeriod ); // waits for off -> on -> off -> on-> off -> on -> off before switching flash off
      led1_f = 0;
      sw1_state = 5;
      sw1_led_state = L1_OFF; //turn led off
    } 
    else if (sw1_state == 5){
      if(SW1_PRESSED){
          ESOS_TASK_WAIT_TICKS( 25 ); //debounce
          _st_esos_uiF14Data.b_SW1Pressed = true; //testing
          _st_esos_uiF14Data.b_SW1DoublePressed = false;
          sw1_state = 6;
          sw1_led_state = L1_ON;
       }
    } else if(sw1_state == 6){
      if(SW1_RELEASED){
        _st_esos_uiF14Data.b_SW1Pressed = false; 
        sw1_led_state = L1_OFF;
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        sw1_state = 2;
        sw1_old_time = esos_GetSystemTick();
      }
    }
    ESOS_TASK_YIELD();
  }
  ESOS_TASK_END();
}

char buff[50];

ESOS_USER_TASK(led_t1){
  ESOS_TASK_BEGIN();
  while(true){
      if (((sw1_led_state == L1_ON) && (led_display == SW1_SHOW)) || ((sw2_led_state == L2_ON) && (led_display == SW2_SHOW))){
        LED1 = 1;
        _st_esos_uiF14Data.b_LED1On = TRUE;
      } else if(((sw1_led_state == L1_OFF) && (led_display == SW1_SHOW)) || ((sw2_led_state == L2_OFF) && (led_display == SW2_SHOW))){
        LED1 = 0;
        _st_esos_uiF14Data.b_LED1On = FALSE;
      } else if(((sw1_led_state == L1_BLINK) && (led_display == SW1_SHOW)) || ((sw2_led_state == L2_BLINK) && (led_display == SW2_SHOW))){
        led1_f = 1;
      } else if ((sw1_led_state == L1_BLINK) && (led_display != SW1_SHOW)){
        led1_f = 0;
        LED1 = 0;
        _st_esos_uiF14Data.b_LED1On = FALSE;
      }
      ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
  }

ESOS_USER_TASK(sw3_handler){
  ESOS_TASK_BEGIN();
  while(true){
      if (SW3_PRESSED){
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        led_display = SW2_SHOW;
      } else {
        led_display = SW1_SHOW;
      }
      ESOS_TASK_YIELD();
    }
  ESOS_TASK_END();
  }
  
ESOS_USER_TIMER(blink_l1){
      if(led1_f){
        LED1_TOGGLE();
      }
}


uint32_t sw2_old_time = 0; 
uint16_t sw2_state = 0;
uint16_t sw2_flash_counter = 0;



ESOS_USER_TASK(switch_t2){
  ESOS_TASK_BEGIN();
  while(true){
    if(SW2_PRESSED && sw2_state == 0){
      ESOS_TASK_WAIT_TICKS( 25 ); //debounce
      _st_esos_uiF14Data.b_SW2Pressed = true; 
      sw2_led_state = L2_ON; 
      sw2_state = 1; 
    }
    else if (sw2_state == 1){
      sw2_led_state = L2_ON; //LED1 = 1;

      if (SW2_RELEASED){
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        _st_esos_uiF14Data.b_SW2Pressed = false;
        sw2_led_state = L2_OFF; //LED1 = 0;
        sw2_state = 2;
        sw2_old_time = esos_GetSystemTick();
      }
    }
    else if (sw2_state == 2){
      //wait for second press here
      if ((esos_GetSystemTick() - sw2_old_time) >= _st_esos_uiF14Data.u16_SW2Period){
        sw2_state = 0; //go back to first state
      }

      if (((esos_GetSystemTick() - sw2_old_time) <= _st_esos_uiF14Data.u16_SW2Period) && SW2_PRESSED){
        _st_esos_uiF14Data.b_SW2Pressed = true;
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        _st_esos_uiF14Data.b_SW2DoublePressed = true;
        sw2_state = 3;
      }
    }
    else if(sw2_state == 3){
      //blink led
      _st_esos_uiF14Data.b_SW2Pressed = false;
      sw2_led_state = L2_BLINK;
      //should we wait here for blinking to stop? yah probably.
      //return to first state
      sw2_state = 4;
    } 
    else if (sw2_state == 4){
      sw2_led_state = L2_BLINK;
      ESOS_TASK_WAIT_TICKS( 7*_st_esos_uiF14Data.u16_LED1FlashPeriod ); //blinking time for timer
      led1_f = 0;
      sw2_state = 5;
      sw2_led_state = L2_OFF; //turn led off

    } else if (sw2_state == 5){
      if(SW2_PRESSED){
          ESOS_TASK_WAIT_TICKS( 25 ); //debounce
          _st_esos_uiF14Data.b_SW2Pressed = true; //testing
          _st_esos_uiF14Data.b_SW2DoublePressed = false;
          sw2_state = 6;
          sw2_led_state = L2_ON;
       }
    } else if(sw2_state == 6){
      if(SW2_RELEASED){
        _st_esos_uiF14Data.b_SW2Pressed = false; 
        sw2_led_state = L2_OFF;
        ESOS_TASK_WAIT_TICKS( 25 ); //debounce
        sw2_state = 2;
        sw2_old_time = esos_GetSystemTick();
        
      }
    }
    ESOS_TASK_YIELD();
  }
  ESOS_TASK_END();
}

uint16_t led1_flash_counter = 0;
uint16_t led2_flash_counter = 0;
uint16_t led3_flash_counter = 0;

ESOS_USER_TIMER(run_leds){
  // led 1 flashing
  if(led1_f){// if led flashing
    if(led1_flash_counter < (_st_esos_uiF14Data.u16_LED1FlashPeriod/25)){ // if counter less than period
        led1_flash_counter++; // increment
    } else { // if timer exceeded
        LED1_TOGGLE(); // toggle led
        led1_flash_counter = 0;
    }
  }
  // led 2 lights
  if(esos_uiF14_isRpgTurningMedium()){
    // if moving medium
    if(led2_flash_counter < (_st_esos_uiF14Data.u16_RPGMediumPeriod/25)){
      led2_flash_counter++;
    } else {
      LED2_TOGGLE();
      led2_flash_counter = 0;
    } 
  } else if(esos_uiF14_isRpgTurningFast()){
    // if moving fast
    if(led2_flash_counter < (_st_esos_uiF14Data.u16_RPGFastPeriod/25)){
      led2_flash_counter++;
    } else {
      LED2_TOGGLE();
      led2_flash_counter = 0;
    } 
  } else if(esos_uiF14_isRpgTurningSlow()){
    LED2_ON();
  } else {
    LED2_OFF();
  }

  // do HB
  if(led3_flash_counter < (_st_esos_uiF14Data.u16_HBLEDPeriod/25)){
    led3_flash_counter++;
  } else{
    LED3_TOGGLE();
    led3_flash_counter = 0;
  }
}
ESOS_USER_TIMER(process_rpg){

}



// UIF14 INITIALIZATION FUNCTION
void config_esos_uiF14() {
  // Hardware Configuration
  CONFIG_RPG();
  CONFIG_LED1();
  CONFIG_LED2();
  CONFIG_LED3();
  CONFIG_SW1();
  CONFIG_SW2();
  CONFIG_SW3();

  // Turn all LEDs off
  LED1_OFF();
  LED2_OFF();
  LED3_OFF(); 

  // Default values for struct members
  sw1_state = 0;
  _st_esos_uiF14Data.b_SW1Pressed = false;

  sw1_led_state = L1_OFF;
  _st_esos_uiF14Data.u16_LED1FlashPeriod = 125;

  _st_esos_uiF14Data.u16_RPGLower= 15;
  _st_esos_uiF14Data.u16_RPGUpper = 50;
  _st_esos_uiF14Data.u16_RPGMediumPeriod = 250;
  _st_esos_uiF14Data.u16_RPGFastPeriod = 50;
  _st_esos_uiF14Data.u16_SW1Period = 1000;
  _st_esos_uiF14Data.u16_SW2Period = 1000;
  _st_esos_uiF14Data.u16_HBLEDPeriod = 250;

  // Register local tasks and timers
  esos_RegisterTimer(dbnc_rpg, 1);
  esos_RegisterTimer(process_rpg, 25);
  esos_RegisterTask(switch_t1);
  esos_RegisterTask(switch_t2);
  esos_RegisterTask(led_t1);
  esos_RegisterTask(sw3_handler);
  esos_RegisterTimer(run_leds, 25);

}