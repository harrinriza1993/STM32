
#include "main.h"
#include "lcd.h"

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* Initialize all configured peripherals */
  lcd_init();

  while (1)
  {
    lcd_display("Lal Bosco", 1);
    HAL_Delay(1000);
    lcd_display("Harrin Delina", 2);
    HAL_Delay(1000);
  }
}
