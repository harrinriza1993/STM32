#include "stm32l4xx_hal.h"

/* PA0 is used as a output pin. */

#define RCC_BASE_ADDRESS 0x40021000
#define GPIOA_BASE_ADDRESS  0x48000000

#define RCC_AHB2ENR_OFFSET 0x40021000
#define GPIOx_MODER_OFFSET 0x00
#define GPIO_BSRR_OFFSET 0x18

#define RCC_AHB1ENR (*((volatile uint32_t*) (RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET)))
#define GPIOA_MODER (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOA_BSRR  (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIO_BSRR_OFFSET)))

// Enabling the clock for GPIOA. 

void enable(char port, int pin_number)
{
    RCC_AHB1ENR = RCC_AHB1ENR | (1 << 0);
    GPIOA_MODER = GPIOA_MODER | (1 << (pin_number + pin_number));
    GPIOA_MODER = GPIOA_MODER &  ~(1 << (pin_number + pin_number + 1)); 
}


void setpin(char port, int pin_number)
{
    GPIOA_BSRR = GPIOA_BSRR | (1 << pin_number);
}

void clearpin(char port, int pin_number)
{
    GPIOA_BSRR = GPIOA_BSRR & ~(1 << pin_number);
    GPIOA_BSRR = GPIOA_BSRR | (1 << (pin_number + 16));
}