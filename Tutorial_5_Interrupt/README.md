# INTERRUPT

## Introduction  
1. General description about `INTERRUPT`.  
2. Generate a code for `TIMER INTERRUPT` using `STM32CubeMX`.  
3. Generate a code for `GPIO INTERRUPT` using `STM32CubeMX`

## 1. General description about `INTERRUPT`
       When the processor does the main program, the main program is temporarily suspended by the instruction from the ISR(Interrupt Service Routine). This is called interrupt. Once the Processor finish the instruction from ISR then it  returns again  to main program from where it is suspended.
### TYPES OF INTERRUPT
    	There are six types of interrupt. They are 
                Hardware Interrupt or external interrupt
                Software Interrupt or internal interrupt
                Maskable Interrupt
                Non maskable interrupt
                Vectored Interrupt
                Non Vectored interrupt

## GENERATE A CODE FOR `TIMER INTERRUPT` USING `STM32CubeMX`.
- OPen STM32CUBEMX software. In TIMERS select `TIM16`.
   ![](images/TIM16.png)
- Set the parameters, prescaler to 399(400 - 1) and counter period to 9999(10000 - 1), that means when the count is 9999 , we are making an interrupt and the count again sets to 0 and again it starts counting from 0 to 9999, it goes on.Whenever the count reaches 9999 an interrupt will occur.
![](images/parameter.png)
- Then in NVIC setting enable the TM1 update interrupt and TM16 global interrupt.
![](images/NVIC.png)
- If we set counter period to 9999
(10000 - 1), at each interval when the clock signal reaches 10000, it is triggered. To know it is triggered we can toggle the led. For toggling led select PC7 as GPIO output pin.
![](images/output_pin.png)
- Generate the code.

In main.c first step is to initialize the timer and outputpin.
MX_GPIO_Init();
MX_TIM16_Init();

Then start the timer interrupt 
  HAL_TIM_Base_Start_IT(&htim16);

Usually the code starts the timer by default, but here we have to start the timer interrupt.

And finally in user code begin 4 just override the HAL_TIM_PeriodElapsedCallback function 

/* USER CODE BEGIN 4 */


// Callback: timer has rolled over
'''
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  // Check which version of the timer triggered this callback and toggle LED
  if (htim == &htim16 )
  {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7);
  }
}
'''

/* USER CODE END 4 */

So automatically when the timer reaches 10000 the led toogles.


## GENERATE A CODE FOR `GPIO INTERRUPT`USING `STM32CubeMX`
- Open STM32cubeMX software and set the onboard switch PC13 as input interrupt pin.
 ![](images/onboard_input_pin.png)
- To check if interrupt occurs or not, turn on PB7 onboard led.
 ![](images/led_output_pin.png)
- In left side of cubemax select GPIO.The input interrupt pin and output interrupt pin is shown.
 ![](images/gpio.png)
- Click PC13 and set the GPIO mode either External Interrupt with Falling edge trigger detection or Raising edge trigger detection.
  A rising edge (or positive edge) is the low-to-high transition. A falling edge (or negative edge) is the high-to-low transition.
 ![](images/gpio_mode.png)
 - Click NVIC, enable the EXIT line[15 : 10] interrupts.
 ![](images/enableNVIC.png)
- Generate the source code.
- Override the HAL_GPIO_EXIT_Callback function in main.c
'''
/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback( uint16_t GPIO_Pin)
{
  if(GPIO_Pin == GPIO_PIN_13){
     //This block will be triggered after pin activated.


     HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
   
  }
  else{
    //Do not do anything when else.
    __NOP();
  }
}
/* USER CODE END 4 */
'''
- When we press the user button in stm32 nucleo board,the onboard led will toggle indicating that a interrupt occurs.

