// ECE 4273/6473 Embedded Systems
  
#ifndef REVF14_H
#define	REVF14_H

#include "pic24_all.h"

// LED-related hardware definitions and macros
// Do we want toggle macros for LEDs?
#define CONFIG_LED1()     CONFIG_RF4_AS_DIG_OUTPUT()
#define LED1              (_LATF4)
#define LED1_ON()         (_LATF4 = 1)
#define LED1_OFF()        (_LATF4 = 0)
#define LED1_TOGGLE()     (LED1 = !LED1)

#define CONFIG_LED2()     CONFIG_RB14_AS_DIG_OUTPUT()
#define LED2              (_LATB14)
#define LED2_ON()         (_LATB14 = 1) 
#define LED2_OFF()        (_LATB14 = 0) 
#define LED2_TOGGLE()     (LED2 = !LED2)

#define CONFIG_LED3()     CONFIG_RB15_AS_DIG_OUTPUT()
#define LED3              (_LATB15) 
#define LED3_ON()         (_LATB15 = 0)
#define LED3_OFF()        (_LATB15 = 1)
#define LED3_TOGGLE()     (LED3 = !LED3)


// Switch-related hardware definitions and macros
#define CONFIG_SW1()       { \
                            CONFIG_RB13_AS_DIG_INPUT(); \
                            ENABLE_RB13_PULLUP(); \
                            DELAY_US(1); \
                            }

#define SW1              (_RB13)
#define SW1_PRESSED      (_RB13 == 0)
#define SW1_RELEASED     (_RB13 == 1)

#define CONFIG_SW2()       { \
                            CONFIG_RB12_AS_DIG_INPUT(); \
                            ENABLE_RB12_PULLUP(); \
                            DELAY_US(1); \
                            }

#define SW2              (_RB12)
#define SW2_PRESSED      (_RB12 == 0)
#define SW2_RELEASED     (_RB12 == 1)

#define CONFIG_SW3()       { \
                            CONFIG_RC15_AS_DIG_INPUT();\
                            ENABLE_RC15_PULLUP(); \
                            DELAY_US(1); \
                            }

#define SW3              (_RB15)
#define SW3_PRESSED      (_RC15 == 0)
#define SW3_RELEASED     (_RC15 == 1)

#define POT1 (RB2_AN)
#define TEMP1 (RB3_AN)

#define ANALOG_CONFIG() { \
                        CONFIG_RB2_AS_ANALOG(); \
                        CONFIG_RB3_AS_ANALOG(); \
                        }

#define ADC_CONFIG()    { \
                        AD1CON1bits.ADON = 0;\
                        AD1CON1bits.ADSIDL = 0;\
                        AD1CON1bits.ADDMABM = 1;\
                        AD1CON1bits.AD12B = 1;\
                        AD1CON1bits.FORM = 0;\
                        AD1CON1bits.SSRC = 0b111;\
                        AD1CON1bits.SSRCG = 0;\
                        AD1CON1bits.ASAM = 0;\
                        AD1CON1bits.SAMP = 0;\
                        AD1CON1bits.DONE = 0;\
                        AD1CON2bits.VCFG = 0b000;\
                        AD1CON2bits.CSCNA = 0;\
                        AD1CON2bits.CHPS = 0b00;\
                        AD1CON2bits.SMPI = 0b00000;\
                        AD1CON2bits.BUFM = 0;\
                        AD1CON2bits.ALTS = 0;\
                        AD1CON3bits.ADRC = 1;\
                        AD1CON3bits.SAMC = 0b11111;\
                        AD1CON4bits.ADDMAEN = 0;\
                        AD1CON1bits.ADON = 1;\
                        }

// RPG-related hardware definitions and macros
#define RPG_A            (_RB8)
#define RPG_B            (_RB9)
#define RPG_STATE        (((uint8_t) RPG_A << 1) | RPG_B)

#define CONFIG_RPG()     { \
                          CONFIG_RB8_AS_DIG_INPUT(); \  
                          CONFIG_RB9_AS_DIG_INPUT(); \
                          ENABLE_RB8_PULLUP(); \
                          ENABLE_RB9_PULLUP(); \
                          DELAY_US(1); \
                         }

// LCD Defines
#define LCD44780_E (_LATD10)
#define LCD44780_E_CONFIG()                                                                                            \
    {                                                                                                                  \
        CONFIG_RD10_AS_DIG_OUTPUT();                                                                                   \
    }

#define LCD44780_RW (_LATD11)
#define LCD44780_RW_CONFIG()                                                                                           \
    {                                                                                                                  \
        CONFIG_RD11_AS_DIG_OUTPUT();                                                                                   \
    }

#define LCD44780_RS (_LATC12)
#define LCD44780_RS_CONFIG()                                                                                           \
    {                                                                                                                  \
        CONFIG_RC12_AS_DIG_OUTPUT();                                                                                   \
    }

#define LCD44780_D0 (_LATE0)
#define LCD44780_D0_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE0_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE0_PULLUP();                                                                                           \
    }
#define LCD44780_D0_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE0_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE0_PULLUP();                                                                                          \
    }

#define LCD44780_D1 (_LATE1)
#define LCD44780_D1_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE1_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE1_PULLUP();                                                                                           \
    }
#define LCD44780_D1_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE1_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE1_PULLUP();                                                                                          \
    }

#define LCD44780_D2 (_LATE2)
#define LCD44780_D2_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE2_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE2_PULLUP();                                                                                           \
    }
#define LCD44780_D2_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE2_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE2_PULLUP();                                                                                          \
    }

#define LCD44780_D3 (_LATE3)
#define LCD44780_D3_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE3_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE3_PULLUP();                                                                                           \
    }
#define LCD44780_D3_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE3_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE3_PULLUP();                                                                                          \
    }

#define LCD44780_D4 (_LATE4)
#define LCD44780_D4_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE4_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE4_PULLUP();                                                                                           \
    }
#define LCD44780_D4_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE4_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE4_PULLUP();                                                                                          \
    }

#define LCD44780_D5 (_LATE5)
#define LCD44780_D5_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE5_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE5_PULLUP();                                                                                           \
    }
#define LCD44780_D5_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE5_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE5_PULLUP();                                                                                          \
    }

#define LCD44780_D6 (_LATE6)
#define LCD44780_D6_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE6_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE6_PULLUP();                                                                                           \
    }
#define LCD44780_D6_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE6_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE6_PULLUP();                                                                                          \
    }

#define LCD44780_D7 (_LATE7)
#define LCD44780_D7_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE7_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE7_PULLUP();                                                                                           \
    }
#define LCD44780_D7_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE7_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE7_PULLUP();                                                                                          \
    }

// LCD Defines
// D 0 - 7
#define LCD44780_D0 (_LATE0)
#define LCD44780_D0_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE0_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE0_PULLUP();                                                                                           \
    }
#define LCD44780_D0_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE0_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE0_PULLUP();                                                                                          \
    }

#define LCD44780_D1 (_LATE1)
#define LCD44780_D1_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE1_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE1_PULLUP();                                                                                           \
    }
#define LCD44780_D1_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE1_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE1_PULLUP();                                                                                          \
    }

#define LCD44780_D2 (_LATE2)
#define LCD44780_D2_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE2_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE2_PULLUP();                                                                                           \
    }
#define LCD44780_D2_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE2_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE2_PULLUP();                                                                                          \
    }

#define LCD44780_D3 (_LATE3)
#define LCD44780_D3_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE3_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE3_PULLUP();                                                                                           \
    }
#define LCD44780_D3_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE3_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE3_PULLUP();                                                                                          \
    }

#define LCD44780_D4 (_LATE4)
#define LCD44780_D4_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE4_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE4_PULLUP();                                                                                           \
    }
#define LCD44780_D4_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE4_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE4_PULLUP();                                                                                          \
    }

#define LCD44780_D5 (_LATE5)
#define LCD44780_D5_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE5_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE5_PULLUP();                                                                                           \
    }
#define LCD44780_D5_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE5_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE5_PULLUP();                                                                                          \
    }

#define LCD44780_D6 (_LATE6)
#define LCD44780_D6_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE6_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE6_PULLUP();                                                                                           \
    }
#define LCD44780_D6_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE6_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE6_PULLUP();                                                                                          \
    }

#define LCD44780_D7 (_LATE7)
#define LCD44780_D7_CONFIG_INPUT()                                                                                     \
    {                                                                                                                  \
        CONFIG_RE7_AS_DIG_INPUT();                                                                                     \
        ENABLE_RE7_PULLUP();                                                                                           \
    }
#define LCD44780_D7_CONFIG_OUTPUT()                                                                                    \
    {                                                                                                                  \
        CONFIG_RE7_AS_DIG_OUTPUT();                                                                                    \
        DISABLE_RE7_PULLUP();                                                                                          \
    }

// E, RW, RS
#define LCD44780_E (_LATD10)
#define LCD44780_E_CONFIG()                                                                                            \
    {                                                                                                                  \
        CONFIG_RD10_AS_DIG_OUTPUT();                                                                                   \
    }

#define LCD44780_RW (_LATD11)
#define LCD44780_RW_CONFIG()                                                                                           \
    {                                                                                                                  \
        CONFIG_RD11_AS_DIG_OUTPUT();                                                                                   \
    }

#define LCD44780_RS (_LATC12)
#define LCD44780_RS_CONFIG()                                                                                           \
    {                                                                                                                  \
        CONFIG_RC12_AS_DIG_OUTPUT();                                                                                   \
    }


#endif	/* REVF14_H */