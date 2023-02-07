# STM32-nucleo board bring up

## Introduction

- Generate a source code for `STM32L4R5ZI` using `STM32CubeMx`
- Build the source code in order to get the hexfile.
- Flash the hexfile on `STM32L4R5ZI` using `STM32 utility`

## Procedures
- Open `STM32CubeMX` software.
  ![](images/newproject.png)

- Select `file->New Project` that will create a new project
  as shown in figure.
  ![](images/selectboard.png)

- Please enter the commercial part number. Example: `STM32L4R5ZIT6`
![](images/STM32L4R5ZInucleoboard.png)

- Press `Start project` that shows the `pinout and configuration` of the board as shown in the figure.
   ![](images/pinoutview.png)

- Press the tab `Project Manager`, fill the `Project seetings` and make sure that you have selected the `Toolchain` as `Makefile`

- Click `Generate code` that will generate a code at the select path before.
![](images/generatecode.png)

- Make sure that you installed the `make` and `Embedded Arm GNU tool chain` (https://developer.arm.com/downloads/-/gnu-rm) on your PC.
![](images/projectmanager.png)


- Build and generate a hex file by using `make`

  ![](images/make.png)

- Connect `STM32-nucleo` board to the computer. Open `STM32 ST-LINK utility`  and Press `connect to the target`. Then select the hexfile which we build before.
  ![](images/STM32utility.png)

  - Press `start` that will flash the hexfile into the    STM32 nuclo board.
   ![](images/utilitystart.png)
