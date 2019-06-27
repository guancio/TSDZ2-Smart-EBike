#ifndef _PLATFORM_STM_H
#define _PLATFORM_STM_H

#define PLATFORM_STM

#include "pins_stm.h"
#include "stm8s.h"
#include "stm8s_adc1.h"
#include "stm8s_it.h"
#include "stm8s_flash.h"
#include "stm8s_tim1.h"

#define ATTACH_INTERRUPT(PORT, PIN, EVENT, INT_PORT, HANDLER)    \
  GPIO_Init(PORT,PIN, GPIO_MODE_IN_FL_IT);                       \
  EXTI_SetExtIntSensitivity(INT_PORT,EVENT);
#define READ_DIGITAL(PORT, PIN) GPIO_ReadInputPin(PORT, PIN)

#define RETURN_READ_ANALOG_16(PIN) \
  uint16_t temph;\
  uint8_t templ;\
  templ = *(uint8_t*)(PIN+1);\
  temph = *(uint8_t*)(PIN);\
  return ((uint16_t) temph) << 2 | ((uint16_t) templ);

#define RETURN_READ_ANALOG_8(PIN) \
  return *(uint8_t*)(PIN);


#define EEPROM_READ(address) FLASH_ReadByte (address)
#define EEPROM_WRITE(address, value) FLASH_ProgramByte (address, value)
#define EEPROM_UNLOCK()                                         \
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);         \
  FLASH_Unlock (FLASH_MEMTYPE_DATA);                            \
  while (FLASH_GetFlagStatus(FLASH_FLAG_DUL) == RESET) { } 
#define EEPROM_LOCK()                           \
  FLASH_Lock (FLASH_MEMTYPE_DATA);

#endif
