Module ItConfig
=====

The same source code is executable on different processors or microcontrollers. Today, (parts of) the code is used on 
PC (Linux), ARM Cortex A (e.g.: Rapsberry Pi in Linux user space), ARM Cortex M microcontrollers (STM32).

Different boards (evaluation boards, STM32 nucleo boards or production PCB) may support or not different hardware or 
implement different features.

The ItConfig module handles the code execution on different targets by conditional compile 
with the help of defines prefixed "IT_CONFIG_". 

There are several types of defines:
* defines for different targets boards
* defines for microcontrollers / processors
* difines for code functionlities, which may be integrated into one but not into another application 

# Selection of execution targets

The principal define (e.g.: IT_CONFIG_TARGET_STM32WB55_NUCLEO, the list may be found in file ItConfig_Target.h) must be defined in the compiler options "Preprocessor".

# Include in each source code.

Each compiled source code file (*.c or *.cpp) which uses features of the itSource, must as first file include the "ItConfig.h" file.