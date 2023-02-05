#include "../gpio.h"
#include "input.h"

//Enabling the clock

void input_init(char F, int x)
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

int is_pin_high(char F, int x)
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