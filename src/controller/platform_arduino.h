#ifndef _PLATFORM_ARDUINO_H
#define _PLATFORM_ARDUINO_H

#define PLATFORM_ARDUINO

#include <stdint.h>
#include "pins_arduino.h"
#define __interrupt(A)

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus, BitAction;
#define EXTI_SENSITIVITY_RISE_FALL CHANGE
#define CONFIG_PIN_INPUT(PIN) pinMode(PIN, INPUT)
#define ATTACH_INTERRUPT(PORT, PIN, EVENT, INT_PORT, HANDLER)            \
  pinMode(PIN, INPUT);                                                 \
  attachInterrupt(digitalPinToInterrupt(PIN), HANDLER, EVENT);
#define READ_DIGITAL(PORT, PIN) digitalRead(PIN)
#define RETURN_READ_ANALOG_16(PIN) \
  return analogRead(PIN);
#define RETURN_READ_ANALOG_8(PIN) \
  return (uint8_t)(analogRead(PIN) >> 2);

#ifdef __cplusplus
extern "C" uint8_t EEPROM_READ(int address);
extern "C" void EEPROM_WRITE(int address, uint8_t value);
#else
uint8_t EEPROM_READ(int address);
void EEPROM_WRITE(int address, uint8_t value);
#endif

#define EEPROM_UNLOCK()
#define EEPROM_LOCK()

#endif
