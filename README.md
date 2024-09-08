# TS-UNB-Lib-STM32

This repository contains different projects reproducing the functionality of the TS-UNB-Lib for [mioty](https://en.wikipedia.org/wiki/MIoTy) communication with implementation ported on STM32 microcontrollers.

## Original source code

The original source code of the TS-UNB-Lib is published (copyright 2019 - 2023 Fraunhofer-Gesellschaft zur Förderung der angewandten Forschung e.V, further cited as "Fraunhofer-Gesellschaft") on 
* https://github.com/mioty-iot/TS-UNB-Lib-Arduino and
* https://github.com/mioty-iot/TS-UNB-Lib-Pico

## License

All parts of the repository written by Paul ADAM (e.g.: subdirectories and files starting with prefix "it" in the directory "itSource") are distributed under the [license](https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/LICENSE.md).

The part of the original source code from "Fraunhofer-Gesellschaft" (source code in directory "itSource/ItMioty/TS-UNB") is distributed under the [license](https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/LICENSE-Fraunhofer.md).

The TS-UNB technology is protected by patents. More information can be found at [sisvel](https://www.sisvel.com/licensing-programmes/iot/mioty/).

# Getting started

The software in this repository implements the same functionality as the original TS-UNB-lib (with its published example code):

* Executing on a "mioty endpoint device", the code uploads some data ("Hello" message) to the mioty base station which will forward the message to the mioty application server.
* The generic code executing on the micro controller communicates via SPI with an external module "RFM69W" responsable to do the radio transmission.
* Using this technology, every micro controller with timer and SPI (with minimum speed) could do the mioty upload communication.
* Thus much information given in https://github.com/mioty-iot may be used to understand the code.

# Software

The software stack processes mioty communication in "blocking mode": 
* Once the "ItMioty_send( )" function is called, it will only return when the complete message is sent on air. This may take some seconds depending on the message size. 
* This functioning is suited to small sensor devices which might wake up every minutes or hours, measure sensor values, send them to server and go back to sleep.

There is a non public version of the software stack, where the "ItMioty_send( )" function returns immediately and all the transmission will be done in parallel of the continuing application processing. 
This functioning is needed, if your device incorporates other software stacks (e.g.: USB or BLE) which must be executed during the mioty transmission.

## Software architecture

The software in this repository is organized in different directories.

### Generic software

The directory "itSource" contains the generic code (including the TS-UNB-Lib) which can be compiled and executed on many STM32 micro controllers (named as "execution targets"). Adaptations for specific micro controllers are managed by conditional compile with defines. The source code documentation may be found in "https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/itSource/documentation/html/index.html"

### Specific software

The different projects/subdirectories "TS-UNB_Lib-<TargetName>" contain projects created by and to be used with the integrated development environment STM32CubeIDE from STMicroelectronics. The code is executable on correspondent execution targets (e.g.: development boards from STMicroelectronics).

Following target boards are supported today:

[STM32WB55_NUCLEO](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html) 

### Software from STMicroelectronics

The peripherals of the STM32 microcontroller are initialized with code directly generated by STM32CubeMX. Thus the software stack does not contain any initialization code and the porting to other STM32 MCUs is much easier. The code generated by STM32CubeMX may be found in source file "main.c" in functions "MX_*_Init()".

The LL (low level) drivers of STMicroelectronics are used, since they are much faster than the HAL drivers.

# Hardware

The execution targets may be some development boards, nucleo boards or even customer production boards. They are connected to the transmiter module "RFM69W" with following connections:

* GND:  Ground
* 3V3:  3.3 V power supply
* SCLK: SPI "serial clock"
* MOSI: SPI "master out slave in"
* MISO: SPI "master in slave out"
* CS:   SPI chip select
* RST:  Reset line

The transmiter module "RFM69W" is directly connected to the antenna. 

A nice diagram is shown in chapter "1.1.2 Hardware setup" of the document "https://github.com/mioty-iot/TS-UNB-Lib-Pico/blob/main/documentation/RP_Pico_mioty_Manual.pdf" (off course the Pico board must be replaced by STM32 board).

The image shows a white STM32WB55_NUCLEO board, a blue [arduino-microe adapter board](https://www.mikroe.com/arduino-uno-click-shield) (which is only needed to redirect the arduino connector of the nucleo board to the [mikrobus](https://download.mikroe.com/documents/standards/mikrobus/mikrobus-standard-specification-v200.pdf) connector used by the green shield with the RFM69W module.

![Hardware boards](https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/image/Mioty_HW.jpg  =200x)

The green shield is also simply connecting the lines listed above from mikrobus connector the the RFM69W module.

![RFM69W shield](https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/image/Mioty_HW_TX.jpg  =200x)

# Microcontroller peripherals

Following peripherals are needed by the software stack

* SPI: The software stack needs a SPI to communicate to the RFM69W module.
* Timer: The software stack needs a timer. Since 32 bit timer are rare on STM32 MCUs, a 16 bit timer is used. The timer must be configured to be triggered each micro second.
* GPIO are needed to control the RFM69W module ( CS and RST ).
* Additional GPIO (e.g.: LEDs or test points) may be used for debug purpose. 

# Contribution

Anyone is invited to contribute by using (and testing) the software, reporting corrections or enhancements. Your modifications are wellcome if you accept to transfer the copyright of the corresponding source code modifications to Paul ADAM and/or "Fraunhofer-Gesellschaft".
