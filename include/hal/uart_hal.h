#ifndef _UART_HAL_H_
#define _UART_HAL_H_

#include <stdint.h>
#include "pinNames.h"

typedef struct
{
  PinName TX;
  PinName RX;
  uint16_t baud_rate;
  uint8_t stop_bits;
  uint8_t char_size;
} UART_Config;

#ifdef __cplusplus
extern "C"
{
#endif

  void uart_init(UART_Config *config);
  uint8_t uart_getc();
  void uart_putc(uint8_t data);

#ifdef __cplusplus
}
#endif

#endif // _UART_HAL_H_