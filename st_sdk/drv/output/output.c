#include "output.h"

// PB7 initialized as output
void outputinit(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
    if (GPIOx == GPIOB)
    {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }
    else if(GPIOx == GPIOC)
    {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else if (GPIOx == GPIOF)
    {
        __HAL_RCC_GPIOF_CLK_ENABLE();
    }
    else if(GPIOx == GPIOE)
    {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }
    else if(GPIOx == GPIOD)
    {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    }
    GPIO_InitTypeDef GPIO_Init;

    GPIO_Init.Pin = GPIO_PIN;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull = GPIO_NOPULL;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init.Alternate = 0;
    HAL_GPIO_Init(GPIOx, &GPIO_Init);
}

void setpin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_PIN, GPIO_PIN_SET);
}

void clearpin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
   HAL_GPIO_WritePin(GPIOx, GPIO_PIN, GPIO_PIN_RESET);
}