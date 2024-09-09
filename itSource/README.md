itSource Documentation
======

# Software

The "isSource" directory constists of different modules:
* itConfig: module to handle conditional compile
* itFoundation: module with generic code
* itHal: the hardware abstraction layer of itSource
* itMioty: module with encapsulation of the TS-UNB library
* itMiotySampleApplication: represents a mioty application 

The sub directories of "itSource" are not integrated directly into the project directories but added as "Linked Folder" in
"File" -> "New" -> "Folder" -> "Advanced >>" -> "Link to alternate location (Linked Folder)".

## Module structure

* Each module contains an include folder with the API header files of the functionalities.
* The inline folder contains more internal defines as also C++ class/template definitions.
* The source folder contains the (not inline) source code as also global variables.

# Development Environment

The projects have been developped with [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html), the eclipse-based free of charge development environment from STMicroelectronics. 
Minimum version is 1.16. Newer version can be used by migrating the *.ioc file.

Using other IDE (e.g.: from IAR or Keil) is possible but needs adaptations (e.g.: linker scripts). To completely replace the STM32CubeMX technology including MCU peripheral initialization, some initialization code must be added.

## Compiler Options

Following compiler options must be set in "Properties for TS-UNB-Lib-STM32xxx" -> "C/C++ Build" -> "Settings" -> "Tool Settings":

* The principal define must be set in "MCU/MPU GCC Compiler" and "MCU/MPU G++ Compiler", add the "Proprocessor" -> "Define symbols (-D)" 
  - IF_CONFIG_TARGET_XXX
  It determines the execution target.

* In "MCU/MPU GCC Compiler" and "MCU/MPU G++ Compiler", add the "Include paths" 
  - ${workspace_loc:/${ProjName}/itConfig/include}
  - ${workspace_loc:/${ProjName}/itFoundation/include}
  - ${workspace_loc:/${ProjName}/itHal/include}
  - ${workspace_loc:/${ProjName}/itMioty/include}
  - ${workspace_loc:/${ProjName}/itMiotySampleApplication/include}
