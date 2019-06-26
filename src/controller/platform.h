#ifndef _PLATFORM_H
#define _PLATFORM_H

#include <stdint.h>

#define PLATFORM_ARDUINO
// #define PLATFORM_STM

#ifdef PLATFORM_STM
#define ATTACH_INTERRUPT(PORT, PIN, EVENT, INT_PORT, HANDLER)    \
  GPIO_Init(PORT,PIN, GPIO_MODE_IN_FL_IT);                       \
  EXTI_SetExtIntSensitivity(INT_PORT,EVENT);
#define READ_DIGITAL(PORT, PIN) GPIO_ReadInputPin(PORT, PIN)
#define EEPROM_READ(address) FLASH_ReadByte (address)
#define EEPROM_WRITE(address, value) FLASH_ProgramByte (address, value)
#define EEPROM_UNLOCK()                                         \
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);         \
  FLASH_Unlock (FLASH_MEMTYPE_DATA);                            \
  while (FLASH_GetFlagStatus(FLASH_FLAG_DUL) == RESET) { } 
#define EEPROM_LOCK()                           \
  FLASH_Lock (FLASH_MEMTYPE_DATA);

#endif

#ifdef PLATFORM_ARDUINO
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus, BitAction;
#define EXTI_SENSITIVITY_RISE_FALL CHANGE
#define ATTACH_INTERRUPT(PORT, PIN, EVENT, INT_PORT, HANDLER)            \
  pinMode(PIN, INPUT);                                                 \
  attachInterrupt(digitalPinToInterrupt(PIN), HANDLER, EVENT);
#define READ_DIGITAL(PORT, PIN) digitalRead(PIN)

uint8_t EEPROM_READ(int address);
void EEPROM_WRITE(int address, uint8_t value);
#define EEPROM_UNLOCK()
#define EEPROM_LOCK()

#endif


#endif
