# HCSR04 ULTRASONIC SENSOR

## Introduction  
1. General description about `HCSR04 Ultra sonic sensor`.  
2. Generate a code for `HCSR04 Ultra sonic sensor` using `STM32CubeMX`.  
3. The distance to an oject is displayed in `putty` using `UART`.

## General description about `HCSR04 Ultra sonic sensor`:  
- HCSR04 sensor is used for detecting an object and it's distance using sonar.
- It can detect an object from 2cm to 400cm.
- It is used in many embedeed applications where we need to avoid objects.

### Working of `HCSR04 Ultra sonic sensor`:
- It has four pins. They are VCC, GND, Trig pin and Echo pin.
- The Echo pin emits an ultrasound at 40 KHz, if the wave find any obstacle it reflect back
  and bounces to the Trig pin.
- The distance between the waves travelling in to the object and back to the module  is the distance
  between the object and the sensor.
- To calculate the distance following thing should be done.
- Keep the Trig pin high for 10 microseconds.
- The module will now send 8 cycle of ultrasound in 40KHZ and check weather the waves will reflect back.
- If the waves doesnot reflect back then there is no object.
- If the wave reflect back, output will be high and its width is propotinal to the range of the object,
- Distance can be calculated using the below formula
        Distance = uS / 58
![](images/Uart_connection.png)

### Timing Diagram for `HCSR04 Ultra sonic sensor`:
-  

## Generate a code for `HCSR04 Ultra sonic sensor` using `STM32CubeMX`
- Open STM32CUBEMX software.
- In System Core select RCC --> High Speed Clock(HSE)--> Crystal/Ceramic Resonator.
- In Timers select TIM16, then select Input Capture direct mode in Channel 1.
- Then in Parameter setting set prescaler to (4 - 1).
- The Timer16 pin is selected in board, which should be connected with Echo pin.
- Select a pin as GPIO output pin, which should be connected with Trig pin.
- Generate the code.

## The distance to an oject is displayed in `putty` using `UART`:
- Using putty the distance in cm is displayed.
- So we have to use UART in STM32CUBEMX. Select UART4 in Connectivity.
- After compiling the code using make file we get the distance in cm in putyy
  as follows