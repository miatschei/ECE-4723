/*
 * "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 *
 */

/**
 * addtogroup ESOS_Task_Sensor_Service
 * @{
 */
 
/*** I N C L U D E S *************************************************/
#include "esos_pic24_sensor.h"
#include "esos_sensor.h"

/*** T H E   C O D E *************************************************/

/*********************************************************
 * Public functions intended to be called by other files *
 *********************************************************/

/** file
 *  Sensor support functions. see hwxxx_sensor.h for details.
 */

/**
Configure and enable the sensor module for hwxxx hardware.
\param e_senCh   specifies sensor channel
\param e_senVRef specifies sensor voltage reference
\hideinitializer
 */
void esos_sensor_config_hw (esos_sensor_ch_t e_senCh, esos_sensor_vref_t e_senVRef)
{
    ANALOG_CONFIG();
    ADC_CONFIG();
    AD1CON1bits.ADON = 0;
    AD1CHS0bits.CH0SA = e_senCh;
    AD1CHS0bits.CH0NA = 0;
    AD1CHS123 = 0;
    AD1CSSH = 0;
    AD1CSSL = 0;
    AD1CON1bits.ADON = 1;
}

/**
Determine truth of: the sensor is currently converting
\hideinitializer
 */
BOOL esos_sensor_is_converting_hw (void)
{
    // if done then not converting, return FALSE
    // MAY NEED TO DO DIFFERENTLY
    if (AD1CON1bits.DONE == 1) {
        esos_ClearUserFlag(ESOS_SENSOR_IS_CONVERTING_FLAG);
        return FALSE;
    }
    // if converting flag set, return TRUE
    return esos_IsUserFlagSet(ESOS_SENSOR_IS_CONVERTING_FLAG);
}

/**
Initiate a conversion for a configured sensor
\hideinitializer
 */
void esos_sensor_initiate_hw (void)
{
    // set conversion flag and begin sampling
    esos_SetUserFlag(ESOS_SENSOR_IS_CONVERTING_FLAG);
    AD1CON1bits.SAMP = 1;
}

/**
Receive the value from a conversion that has already been initiated
\hideinitializer
 */
uint16_t esos_sensor_getvalue_u16_hw (void)
{
    // return 0 if still converting (flag set)
    if (!esos_IsUserFlagClear(ESOS_SENSOR_IS_CONVERTING_FLAG)) {
        return 0;
    }
    // return value from ADC buffer
    uint16_t u16_adcVal = (ADC1BUF0);
    return u16_adcVal;
}

/**
Release any pending conversions for the sensor
\hideinitializer
 */
void esos_sensor_release_hw (void)
{
    // clear flag and turn off ADC
    esos_ClearUserFlag(ESOS_SENSOR_IS_CONVERTING_FLAG);
    AD1CON1bits.ADON = 0;
}
