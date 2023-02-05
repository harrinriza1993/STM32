#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"

void lcd_init();
void lcd_display(unsigned char* data_name, int line_selection);

#endif