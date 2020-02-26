#include "esos.h"
#include "esos_pic24_sensor.h"
#include "revF14.h"
#include "esos_f14ui.h"
#include "esos_pic24.h"
#include "esos_sensor.h"
#include <stdio.h>

//dummy strings
static char str_SW1[] = "\n";
static char str_SW2[] = "SWITCH PRESSED\n";

//process strings 
static char str_process_menu_title[] = "Processing Modes\n1. One Shot\n2. Average\n3. Minimum\n4. Maximum\n5. Median\n";

//sample number strings
static char str_sample_menu_title[] = "Number of Samples\n1. two\n2. four\n3. eight\n4. sixteen\n5. thirty-two\n6. sixty-four\n";

static uint16_t u16_adcval;
static uint16_t u16_state;
static uint8_t en_print = 0;
static bool continuous = 0;
static uint8_t my_state; //state variable holder

//user input variables 
static uint8_t u8_process; //user set process variable - ex: 1 for one_shot, 2 for average, etc... 
static uint8_t u8_sample; 
static uint8_t u8_read_type = ESOS_SENSOR_ONE_SHOT; //store the e_senProcess here 


ESOS_USER_TASK(read_pot){
    ESOS_TASK_BEGIN();
    static ESOS_TASK_HANDLE get_adc;
    while(TRUE){
        if (en_print == 1){
            ESOS_ALLOCATE_CHILD_TASK(get_adc);
            ESOS_TASK_SPAWN_AND_WAIT(get_adc, _WAIT_ON_AVAILABLE_SENSOR, potCH, ESOS_SENSOR_VREF_3V0);
            // ESOS_TASK_SPAWN_AND_WAIT(get_adc,_WAIT_SENSOR_QUICK_READ, &u16_adcval);
            ESOS_TASK_SPAWN_AND_WAIT(get_adc, _WAIT_SENSOR_READ, &u16_adcval, u8_read_type, ESOS_SENSOR_FORMAT_BITS);
            ESOS_SENSOR_CLOSE();
            ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
            ESOS_TASK_WAIT_ON_SEND_UINT32_AS_HEX_STRING(u16_adcval);
            ESOS_TASK_WAIT_ON_SEND_STRING(str_SW1);
            ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
            if (continuous){ 
                ESOS_TASK_WAIT_TICKS(1000); 
            }
            
        }

        ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}



ESOS_USER_TASK(state_change){
    ESOS_TASK_BEGIN();
        while(TRUE){

            if (my_state == 0){
                en_print = 0;
                continuous = 0;
                if(SW1_PRESSED){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 1;
                    en_print = 1;
                }
                if(SW2_PRESSED){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 2;
                    en_print = 1;
                    continuous = 1;
                }

                // **sw3 not currently working**
                if(SW3_PRESSED){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 4;
                    en_print = 0;
                    continuous = 0;
                } 

            } else if(my_state == 1) {
                if(SW1_RELEASED){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 0;
                }
                en_print = 0;
            } else if (my_state == 2){
                if (SW2_RELEASED || SW1_RELEASED){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 3; //go back to first state and wait for a single SW2 press
                } else if (SW1_PRESSED){
                    ESOS_TASK_WAIT_TICKS( 25 ); //debounce
                    my_state = 0;
                }
            } else if (my_state == 3){
                if ((SW2_PRESSED) || (SW1_PRESSED)){
                    ESOS_TASK_WAIT_TICKS( 10 ); //debounce
                    my_state = 0;
                    en_print = 0;
                    continuous = 0;
                } else if(SW3_PRESSED){
                    my_state = 4;
                    en_print = 0;
                    continuous = 0;
                }
            } else if (my_state == 4){
                if (SW3_RELEASED){
                    //print out processing modes here
                    my_state = 5;
                }
            } else if (my_state == 5){
                // print process menu
                ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
                ESOS_TASK_WAIT_ON_SEND_STRING(str_process_menu_title);
                ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
                ESOS_TASK_WAIT_TICKS( 10 );
                // wait for user input
                ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
                ESOS_TASK_WAIT_ON_GET_UINT8(u8_process);
                ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();
                ESOS_TASK_WAIT_TICKS( 10 );

                my_state = 5;
                
                 if (u8_process == '1'){
                     //one shot process mode, only need one sample and do not need to select the sample size
                     u8_read_type = ESOS_SENSOR_ONE_SHOT;
                     my_state = 0;
                 } 
             
                if (u8_process != '1' && my_state == 5){
                        // print process menu
                        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
                        ESOS_TASK_WAIT_ON_SEND_STRING(str_sample_menu_title);
                        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
                        ESOS_TASK_WAIT_TICKS( 10 );
                        // wait for use input
                        ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
                        ESOS_TASK_WAIT_ON_GET_UINT8(u8_sample);
                        ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();
                        ESOS_TASK_WAIT_TICKS( 10 );
                        my_state = 6; 
                }
            } 
            else if (my_state == 6){
                
                if(u8_process == '2' && u8_sample=='1'){
                    u8_read_type = ESOS_SENSOR_AVG2;
                } else if (u8_process == '3' && u8_sample=='1'){
                    u8_read_type = ESOS_SENSOR_MIN2;
                } else if (u8_process == '4' && u8_sample=='1'){
                    u8_read_type = ESOS_SENSOR_MAX2;
                } else if (u8_process == '5' && u8_sample=='1'){
                    u8_read_type = ESOS_SENSOR_MEDIAN2;
                } else if (u8_process == '2' && u8_sample=='2'){
                    u8_read_type = ESOS_SENSOR_AVG4;
                } else if (u8_process == '3' && u8_sample=='2'){
                    u8_read_type = ESOS_SENSOR_MIN4;
                } else if (u8_process == '4' && u8_sample=='2'){
                    u8_read_type = ESOS_SENSOR_MAX4;
                } else if (u8_process == '5' && u8_sample=='2'){
                    u8_read_type = ESOS_SENSOR_MEDIAN4;
                } else if (u8_process == '2' && u8_sample=='3'){
                    u8_read_type = ESOS_SENSOR_AVG8;
                } else if (u8_process == '3' && u8_sample=='3'){
                    u8_read_type = ESOS_SENSOR_MIN8;
                } else if (u8_process == '4' && u8_sample=='3'){
                    u8_read_type = ESOS_SENSOR_MAX8;
                } else if (u8_process == '5' && u8_sample=='3'){
                    u8_read_type = ESOS_SENSOR_MEDIAN8;
                } else if (u8_process == '2' && u8_sample=='4'){
                    u8_read_type = ESOS_SENSOR_AVG16;
                } else if (u8_process == '3' && u8_sample=='4'){
                    u8_read_type = ESOS_SENSOR_MIN16;
                } else if (u8_process == '4' && u8_sample=='4'){
                    u8_read_type = ESOS_SENSOR_MAX16;
                } else if (u8_process == '5' && u8_sample=='4'){
                    u8_read_type = ESOS_SENSOR_MEDIAN16;
                } else if (u8_process == '2' && u8_sample=='5'){
                    u8_read_type = ESOS_SENSOR_AVG32;
                } else if (u8_process == '3' && u8_sample=='5'){
                    u8_read_type = ESOS_SENSOR_MIN32;
                } else if (u8_process == '4' && u8_sample=='5'){
                    u8_read_type = ESOS_SENSOR_MAX32;
                } else if (u8_process == '5' && u8_sample=='5'){
                    u8_read_type = ESOS_SENSOR_MEDIAN32;
                } else if (u8_process == '2' && u8_sample=='6'){
                    u8_read_type = ESOS_SENSOR_AVG64;
                } else if (u8_process == '3' && u8_sample=='6'){
                    u8_read_type = ESOS_SENSOR_MIN64;
                } else if (u8_process == '4' && u8_sample=='6'){
                    u8_read_type = ESOS_SENSOR_MAX64;
                } else if (u8_process == '5' && u8_sample=='6'){
                    u8_read_type = ESOS_SENSOR_MEDIAN64;
                }
                
                my_state = 0;  

                //set the process type 
            }
            ESOS_TASK_YIELD();
        }
    ESOS_TASK_END();
}

void user_init(){
    // Run esos_uiF14 setup module
    config_esos_uiF14();

    my_state = 0;
    //one_shot_state = 0;
    // Register local tasks
    esos_RegisterTask(read_pot);
    esos_RegisterTask(state_change);
    //esos_RegisterTask(adc_interface);
}