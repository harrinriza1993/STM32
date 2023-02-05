#include "stm32l4xx_hal.h"
#include "../gpio.h"
// init PB7
// PC6
void init(char port, int pin_number)
{
    // Enabling the clock for GPIOB
    

    switch (port)
    {
        case 'A':
            RCC_AHB1ENR = RCC_AHB1ENR | (1 << 0);
            GPIOA_MODER = GPIOA_MODER | (1 << (pin_number + pin_number));
            GPIOA_MODER = GPIOA_MODER &  ~(1 << (pin_number + pin_number + 1)); 
            break;
        case 'B' :
            RCC_AHB1ENR = RCC_AHB1ENR | (1 << 1);
            GPIOB_MODER = GPIOB_MODER | (1 << (pin_number + pin_number));
            GPIOB_MODER = GPIOB_MODER &  ~(1 << (pin_number + pin_number + 1));
            break;
        case 'C' :
            RCC_AHB1ENR = RCC_AHB1ENR | (1 << 2);
            GPIOC_MODER = GPIOC_MODER | (1 << (pin_number + pin_number));
            GPIOC_MODER = GPIOC_MODER &  ~(1 << (pin_number + pin_number + 1));
            break;
        case 'D' :
            RCC_AHB1ENR = RCC_AHB1ENR | (1 << 3);
            GPIOB_MODER = GPIOB_MODER | (1 << (pin_number + pin_number));
            GPIOB_MODER = GPIOB_MODER &  ~(1 << (pin_number + pin_number + 1));
            break;
        case 'E' :
            RCC_AHB1ENR = RCC_AHB1ENR | (1 << 4);
            GPIOE_MODER = GPIOE_MODER | (1 << (pin_number + pin_number));
            GPIOE_MODER = GPIOE_MODER &  ~(1 << (pin_number + pin_number + 1));
            break;
        case 'F' :
             RCC_AHB1ENR = RCC_AHB1ENR | (1 << 5);
             GPIOF_MODER = GPIOF_MODER | (1 << (pin_number + pin_number));
             GPIOF_MODER = GPIOF_MODER &  ~(1 << (pin_number + pin_number + 1));
             break;
        case 'G' :
             RCC_AHB1ENR = RCC_AHB1ENR | (1 << 6);
             GPIOG_MODER = GPIOG_MODER | (1 << (pin_number + pin_number));
             GPIOG_MODER = GPIOG_MODER &  ~(1 << (pin_number + pin_number + 1));
             break;
        case 'H' :
            RCC_AHB1ENR = RCC_AHB1ENR | (1 << 7);
            GPIOH_MODER = GPIOH_MODER | (1 << (pin_number + pin_number));
            GPIOH_MODER = GPIOH_MODER &  ~(1 << (pin_number + pin_number + 1));
            break;
        case 'I' :
             RCC_AHB1ENR = RCC_AHB1ENR | (1 << 8);
             GPIOI_MODER = GPIOI_MODER | (1 << (pin_number + pin_number));
             GPIOI_MODER = GPIOI_MODER &  ~(1 << (pin_number + pin_number + 1));
             break;
        default:
            break;
    }
}   
 
   

void ledon(char port, int pin_number)
{
    
    switch (port)
    {
        case 'A':
            GPIOA_BSRR = GPIOA_BSRR | (1 << pin_number);
            break;
        case 'B' :
            GPIOB_BSRR = GPIOB_BSRR | (1 << pin_number);
        case 'C' :
            GPIOC_BSRR = GPIOC_BSRR | (1 << pin_number);
            break;
        case 'D' :
            GPIOD_BSRR = GPIOD_BSRR | (1 << pin_number);
            break;
        case 'E' :
            GPIOE_BSRR = GPIOE_BSRR | (1 << pin_number);
            break;
        case 'F' :
            GPIOF_BSRR = GPIOF_BSRR | (1 << pin_number);
            break;
        case 'G' :
            GPIOG_BSRR = GPIOG_BSRR | (1 << pin_number);
             break;
        case 'H' :
            GPIOH_BSRR = GPIOH_BSRR | (1 << pin_number);
            break;
        case 'I' :
            GPIOI_BSRR = GPIOI_BSRR | (1 << pin_number);
        default:
            break;
    }
    
}

void ledoff(char port, int pin_number)
{
    switch (port)
    {
        case 'A':
            GPIOA_BSRR = GPIOA_BSRR & ~(1 << pin_number);
            GPIOA_BSRR = GPIOA_BSRR | (1 << (pin_number + 16));
            break;
        case 'B' :
           GPIOB_BSRR = GPIOB_BSRR & ~(1 << pin_number);
           GPIOB_BSRR = GPIOB_BSRR | (1 << (pin_number + 16));
           break;
        case 'C' :
            GPIOC_BSRR = GPIOC_BSRR & ~(1 << pin_number);
            GPIOC_BSRR = GPIOC_BSRR | (1 << (pin_number + 16));
            break;
        case 'D' :
           GPIOD_BSRR = GPIOD_BSRR & ~(1 << pin_number);
           GPIOD_BSRR = GPIOD_BSRR | (1 << (pin_number + 16));
            break;
        case 'E' :
            GPIOE_BSRR = GPIOE_BSRR & ~(1 << pin_number);
            GPIOE_BSRR = GPIOE_BSRR | (1 << (pin_number + 16));
            break;
        case 'F' :
            GPIOF_BSRR = GPIOF_BSRR & ~(1 << pin_number);
            GPIOF_BSRR = GPIOF_BSRR | (1 << (pin_number + 16));
            break;
        case 'G' :
            GPIOG_BSRR = GPIOG_BSRR & ~(1 << pin_number);
            GPIOG_BSRR = GPIOG_BSRR | (1 << (pin_number + 16));
            break;
        case 'H' :
            GPIOH_BSRR = GPIOH_BSRR & ~(1 << pin_number);
            GPIOH_BSRR = GPIOH_BSRR | (1 << (pin_number + 16));
            break;
        case 'I' :
            GPIOI_BSRR = GPIOI_BSRR & ~(1 << pin_number);
            GPIOI_BSRR = GPIOI_BSRR | (1 << (pin_number + 16));
            break;
        default:
            break;
    }
}