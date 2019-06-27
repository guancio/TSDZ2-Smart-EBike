#include "platform.h"

#include <EEPROM.h>

uint8_t EEPROM_READ(int address)
{
  return EEPROM.read(address);
}
void EEPROM_WRITE(int address, uint8_t value)
{
  return EEPROM.write(address, value);
}
