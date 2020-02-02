// ECE 4273/6473 Embedded Systems
  
#ifndef REVF14_H
#define	REVF14_H

#include "pic24_all.h"

// Lab 2 Definitions and Macros
#define CONFIG_LED1 ()    CONFIG_RF5_AS_DIG_OUTPUT()
#define LED1              (_LATF5)

#define CONFIG_LED2 ()    CONFIG_RB14_AS_DIG_OUTPUT()
#define LED2              (_LATB14) 

#define CONFIG_LED3 ()    CONFIG_RB15_AS_DIG_OUTPUT()
#define LED3              (_LATB15) 

#define CONFIG_SW1 ()     {\
                            CONFIG_RB13_AS_DIG_INPUT();\
                            ENABLE_RB13_PULLUP();\
                            DELAY_US(1);\
                            }


#define SW1_PRESSED()      (_RB13 == 0)
#define SW1_RELEASED()     (_RB13 == 1)

#define CONFIG_SW2 ()      {\
                            CONFIG_RB12_AS_DIG_INPUT();\
                            ENABLE_RB12_PULLUP();\
                            DELAY_US(1);\
                            }


#define SW2_PRESSED()      (_RB12 == 0)
#define SW2_RELEASED()     (_RB12 == 1)

#define CONFIG_SW3 ()      {\
                            CONFIG_RC15_AS_DIG_INPUT();\
                            ENABLE_RC15_PULLUP();\
                            DELAY_US(1);\
                            }


#define SW3_PRESSED()      (_RC15 == 0)
#define SW3_RELEASED()     (_RC15 == 1)


#endif	/* REVF14_H */

