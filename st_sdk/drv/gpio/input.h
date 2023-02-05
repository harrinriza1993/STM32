#ifndef __INPUT_H
#define __INPUT_H

#include "stm32l4xx_hal.h"

void input_init(char F, int x);
int is_pin_high(char F, int x);

#endif