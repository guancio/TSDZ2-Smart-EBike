#ifndef _PINS_ARDUINO_H
#define _PINS_ARDUINO_H

#include <Arduino.h>

/* Connections:
 *
 * PIN                | IN/OUT|Function
 * ----------------------------------------------------------
 * PIN2               | in  | brake
 * PIN44              | out | lights. Enable/disable 5V output of the circuit that powers the lights wire of 6V.
 * A3                 | in  | analog throttle
 */

#define BRAKE__PIN                2
#define LIGHTS__PIN                44
#define UI8_ADC_THROTTLE              A3

#endif
