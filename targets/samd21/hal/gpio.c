#include "samd21.h"
#include "pinNames.h"
#include "hal/gpio.h"

void pinMode(PinName pin, PinDirection direction)
{
  uint8_t port = PINPORT(pin);
  uint8_t index = PININDEX(pin);
  if (direction == OUTPUT)
  {
    PORT->Group[port].DIRSET.reg |= 1 << index;
  }
  else
  {
    PORT->Group[port].DIRCLR.reg |= 1 << index;
  }
}

void pinWrite(PinName pin, PinLevel level)
{
  uint8_t port = PINPORT(pin);
  uint8_t index = PININDEX(pin);
  if (level == HIGH)
  {
    PORT->Group[port].OUTSET.reg |= 1 << index;
  }
  else
  {
    PORT->Group[port].OUTCLR.reg |= 1 << index;
  }
}