
#ifndef __OUTPUT_H
#define __OUTPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"

void outputinit(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
void setpin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
void clearpin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);

#endif