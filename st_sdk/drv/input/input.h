#ifndef __INTPUT_H
#define __INTPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"

void input_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
GPIO_PinState read_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
#endif