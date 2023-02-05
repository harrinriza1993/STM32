#include "lcd.h"
#include <stdio.h>

/*
    EN: D9: PD15 
    RS: D8: PF12

    LCD_D7: D7: PF13
    LCD_D6: D6: PE9
    LCD_D5: D5: PE11
    LCD_D4: D4: PF14

    Ardiuno pinout: http://store-usa.arduino.cc/products/arduino-uno-rev3
    STM32L4r5zi nucleo pinout: https://os.mbed.com/platforms/NUCLEO-L4R5ZI/
*/

#define D4_PIN GPIO_PIN_14
#define D5_PIN GPIO_PIN_11
#define D6_PIN GPIO_PIN_9
#define D7_PIN GPIO_PIN_13
#define RS_PIN GPIO_PIN_12
#define EN_PIN GPIO_PIN_15

#define D4_PORT GPIOF
#define D5_PORT GPIOE
#define D6_PORT GPIOE
#define D7_PORT GPIOF
#define RS_PORT GPIOF
#define EN_PORT GPIOD

#define LCD_CMD_DISPLAY_ON 0x0C
#define LCD_CMD_4BIT_MODE 0x28
#define LCD_CMD_CLEAR 0x01
#define LCD_CMD_SELECT_LINE1 0x80
#define LCD_CMD_SELECT_LINE2 0xC0

static void send_data(unsigned char data);
static void send_command(unsigned char cmd);
static void write_data(unsigned char data);
static void enable_pulse();

/**
 * @brief Lcd pin initilization for lcd keyboard shield.
 */
void lcd_init()
{
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_Init;

    GPIO_Init.Pin = EN_PIN;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull = GPIO_NOPULL;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init.Alternate = 0;
    HAL_GPIO_Init(GPIOD, &GPIO_Init);

    GPIO_Init.Pin = D5_PIN | D6_PIN;
    HAL_GPIO_Init(GPIOE, &GPIO_Init);

    GPIO_Init.Pin = D4_PIN | D7_PIN | RS_PIN;
    HAL_GPIO_Init(GPIOF, &GPIO_Init);

    /*Display on */
    send_command(LCD_CMD_DISPLAY_ON);
    HAL_Delay(50);
    send_command(LCD_CMD_4BIT_MODE);
    HAL_Delay(50);
    send_command(LCD_CMD_CLEAR);
    HAL_Delay(50);
}

/**
 * @brief Displays string on the lcd
 * @param[in] data_name - String to display
 * @param[in] line_selection - Select the line (1: First line, 2: Second line)
 */
void lcd_display(unsigned char *data_name, int line_selection) 
{
  if(line_selection == 1)
  {
    send_command(LCD_CMD_SELECT_LINE1);
  }
  else if(line_selection == 2)
  {
    send_command(LCD_CMD_SELECT_LINE2);
  }

  while(*data_name != '\0')
  {
    send_data(*data_name);
    data_name++;
  }
}

/**
 * @brief Enable the pulse (on and off the en pin)
 */
static void enable_pulse()
{
  HAL_GPIO_WritePin(EN_PORT, EN_PIN, GPIO_PIN_SET);
  HAL_Delay(20);
  HAL_GPIO_WritePin(EN_PORT, EN_PIN, GPIO_PIN_RESET);
  HAL_Delay(20);
}

/**
 * @brief Write the data to the lcd
 * @param[in] data - Character/command to write on the lcd.
 */
static void write_data(unsigned char data)
{
  unsigned char lsb_nibble = data & 0xF, msb_nibble = (data >> 4) & 0xF;

  // MSB data
  HAL_GPIO_WritePin(D4_PORT, D4_PIN, (GPIO_PinState)(msb_nibble & 0x1));
  HAL_GPIO_WritePin(D5_PORT, D5_PIN, (GPIO_PinState)(msb_nibble & 0x2));
  HAL_GPIO_WritePin(D6_PORT, D6_PIN, (GPIO_PinState)(msb_nibble & 0x4));
  HAL_GPIO_WritePin(D7_PORT, D7_PIN, (GPIO_PinState)(msb_nibble & 0x8));

  enable_pulse();
  
  // LSB data
  HAL_GPIO_WritePin(D4_PORT, D4_PIN, (GPIO_PinState)(lsb_nibble & 0x1));
  HAL_GPIO_WritePin(D5_PORT, D5_PIN, (GPIO_PinState)(lsb_nibble & 0x2));
  HAL_GPIO_WritePin(D6_PORT, D6_PIN, (GPIO_PinState)(lsb_nibble & 0x4));
  HAL_GPIO_WritePin(D7_PORT, D7_PIN, (GPIO_PinState)(lsb_nibble & 0x8));

  enable_pulse();
}

/**
 * @brief Send the data to the lcd
 * @param[in] data - Character to write on the lcd.
 */
static void send_data(unsigned char data)
{
  /*Setting rs pin high */
  HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_SET);
  HAL_Delay(20);

  write_data(data);
}

/**
 * @brief Send the command to the lcd
 * @param[in] cmd - Command to write on the lcd.
 */
static void send_command(unsigned char cmd)
{
  /*Setting rs pin low */
  HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_RESET);
  HAL_Delay(20);

  write_data(cmd);
}
