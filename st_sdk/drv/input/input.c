#include "input.h"

void input_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
    if (GPIOx == GPIOE)
    {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }

    GPIO_InitTypeDef GPIO_Init;

    GPIO_Init.Pin = GPIO_PIN;
    GPIO_Init.Mode = GPIO_MODE_INPUT;
    GPIO_Init.Pull = GPIO_NOPULL;
    GPIO_Init.Alternate = 0;

    HAL_GPIO_Init(GPIOx, &GPIO_Init);
}

GPIO_PinState read_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}