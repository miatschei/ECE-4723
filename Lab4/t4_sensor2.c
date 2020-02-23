#include "esos.h"
#include "esos_pic24.h"
#include "esos_f14ui.h"
#include "revF14.h"
#include <stdio.h>

// channel macros - needed?
#define ESOS_SENSOR_CH00    0x00
#define ESOS_SENSOR_CH01    0x01
#define ESOS_SENSOR_CH02    0x02
#define ESOS_SENSOR_CH03    0x03
#define ESOS_SENSOR_CH04    0x04
#define ESOS_SENSOR_CH05    0x05
#define ESOS_SENSOR_CH06    0x06
#define ESOS_SENSOR_CH07    0x07
#define ESOS_SENSOR_CH08    0x08
#define ESOS_SENSOR_CH09    0x09
#define ESOS_SENSOR_CH10    0x0A
#define ESOS_SENSOR_CH11    0x0B
#define ESOS_SENSOR_CH12    0x0C
#define ESOS_SENSOR_CH13    0x0D
#define ESOS_SENSOR_CH14    0x0E
#define ESOS_SENSOR_CH15    0x0F

// VREF macros - needed?
#define ESOS_VREF_1V0       0x00
#define ESOS_VREF_1V024     0x01
#define ESOS_VREF_2V0       0x02
#define ESOS_VREF_2v048     0x03
#define ESOS_VREF_3V0       0x04
#define ESOS_VREF_3V3       0x05
#define ESOS_VREF_4V0       0x06
#define ESOS_VREF_4V096     0x07
#define ESOS_VREF_5V0       0x08

// representation macros - needed?
#define ESOS_SENSOR_FORMAT_BITS     0x00
#define ESOS_SENSOR_FORMAT_VOLTAGE  0x80
#define ESOS_SENSOR_FORMAT_PERCENT  0x40

// process macros (selction #1 - 2 inputs except 0x00 - mode and # samples)
#define ESOS_SENSOR_ONE_SHOT        0x00

#define ESOS_SENSOR_AVG2            0x01
#define ESOS_SENSOR_AVG4            0x02
#define ESOS_SENSOR_AVG8            0x03
#define ESOS_SENSOR_AVG16           0x04
#define ESOS_SENSOR_AVG32           0x05
#define ESOS_SENSOR_AVG64           0x06

#define ESOS_SENSOR_MIN2            0x21
#define ESOS_SENSOR_MIN4            0x22
#define ESOS_SENSOR_MIN8            0x23
#define ESOS_SENSOR_MIN16           0x24
#define ESOS_SENSOR_MIN32           0x25
#define ESOS_SENSOR_MIN64           0x26

#define ESOS_SENSOR_MAX2            0x41
#define ESOS_SENSOR_MAX4            0x42
#define ESOS_SENSOR_MAX8            0x43
#define ESOS_SENSOR_MAX16           0x44
#define ESOS_SENSOR_MAX32           0x45
#define ESOS_SENSOR_MAX64           0x46

#define ESOS_SENSOR_MEDIAN2         0x81
#define ESOS_SENSOR_MEDIAN4         0x82
#define ESOS_SENSOR_MEDIAN8         0x83
#define ESOS_SENSOR_MEDIAN16        0x84
#define ESOS_SENSOR_MEDIAN32        0x85
#define ESOS_SENSOR_MEDIAN64        0x86