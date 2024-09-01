# TS-UNB-Lib-STM32

This repository contains different projects reproducing the functionality of the TS-UNB-Lib for [mioty](https://en.wikipedia.org/wiki/MIoTy) communication with implementation ported on STM32 microcontrollers.

## Original source code

The original source code of the TS-UNB-Lib is published (copyright 2019 - 2023 Fraunhofer-Gesellschaft zur Förderung der angewandten Forschung e.V, cited as "Fraunhofer-Gesellschaft") on 
* https://github.com/mioty-iot/TS-UNB-Lib-Arduino and
* https://github.com/mioty-iot/TS-UNB-Lib-Pico

## License

All parts of the repository written by Paul ADAM are distributed under the [license](https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/LICENSE.md).

The part of the original source code from "Fraunhofer-Gesellschaft" is distributed under the [license](https://github.com/paul-adam/TS-UNB-Lib-STM32/blob/main/LICENSE-Fraunhofer.md).

# Getting started

This sample projects implement the same functionality as the "example" of the original TS-UNB-lib:
* Executing on "endpoint device", the code uploads some data ("Hello") to the base station.

# Development

The different projects/subdirectories "TS-UNB_Lib-<TargetName>" are to be executed on correspondent development boards from STMicroelectronics. Following target boards are supported today:

* [STM32WB55_NUCLEO](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html) 

## Development Environment

The projects have been developped with [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html), the eclipse-based free of charge development environment from STMicroelectronics. 
Minimum version is 1.16. Newer version can be used by migrating the *.ioc file.

Using other IDE (e.g.: from IAR or Keil) is possible but needs adaptations (e.g.: linker scripts).

## Hardware prerequisite

## Software prerequisite

## Source code

## Contribution

Anyone is invited to contribute by adding corrections or enhancements, if you accept to transfer the copyright of the corresponding source code modifications to Paul ADAM and/or "Fraunhofer-Gesellschaft".
