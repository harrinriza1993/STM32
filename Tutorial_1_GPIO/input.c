#include "stm32l4xx_hal.h"

/* PF9 is used as input pin. */

#define RCC_BASE_ADDRESS 0x40021000
#define GPIOF_BASE_ADDRESS 0x48001400

#define RCC_AHB2ENR_OFFSET 0x40021000
#define GPIOx_MODER_OFFSET 0x00
#define GPIO_IDR_OFFSET 0x10
#define GPIO_OTYPER_OFFSET 0x04
#define GPIO_SPEEDR_OFFSET 0x08
#define GPIO_PUPDR_OFFSET 0x0c

#define RCC_AHB1ENR (*((volatile uint32_t*) (RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET)))
#define GPIOF_MODER (*((volatile uint32_t*) (GPIOF_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOF_IDR (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + GPIO_IDR_OFFSET)))
#define GPIOF_OTYPER (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS +  GPIO_OTYPER_OFFSET)))
#define GPIO_SPEEDR  (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + GPIO_SPEEDR_OFFSET )))
#define GPIO_PUPDR  (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + GPIO_PUPDR_OFFSET)))

//Enabling the clock 
void input_init(char port, int pin_number)
{
    RCC_AHB1ENR = RCC_AHB1ENR | (1 << 5);

    GPIOF_MODER = GPIOF_MODER & ~(1 << (9+9));
    GPIOF_MODER = GPIOF_MODER & ~(1 << (9+9+1));

    GPIOF_OTYPER = GPIOF_OTYPER | (1 << 5);

    GPIO_SPEEDR = GPIO_SPEEDR | ( 1 << (5 + 5));
    GPIO_SPEEDR = GPIO_SPEEDR | ( 1 << ( 5 + 5 + 1));

    GPIO_PUPDR = GPIO_PUPDR | ( 1 << ( 5 + 5));
    GPIO_PUPDR = GPIO_PUPDR & ~ ( 1 << (5 + 5 + 1));
}

//Read the pin
int is_pin_high(char port, int pin_number)
{
    if (GPIOF_IDR & (1 << 9))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}