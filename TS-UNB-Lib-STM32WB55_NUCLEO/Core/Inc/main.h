/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbxx_hal.h"
#include "stm32wbxx_ll_dma.h"
#include "stm32wbxx_ll_spi.h"
#include "stm32wbxx_ll_tim.h"
#include "stm32wbxx_ll_system.h"
#include "stm32wbxx_ll_gpio.h"
#include "stm32wbxx_ll_exti.h"
#include "stm32wbxx_ll_bus.h"
#include "stm32wbxx_ll_cortex.h"
#include "stm32wbxx_ll_rcc.h"
#include "stm32wbxx_ll_utils.h"
#include "stm32wbxx_ll_pwr.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SYS_WKUP2_Pin LL_GPIO_PIN_13
#define SYS_WKUP2_GPIO_Port GPIOC
#define RCC_OSC32_IN_Pin LL_GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port GPIOC
#define RCC_OSC32_OUT_Pin LL_GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port GPIOC
#define CLICK_1_RST_Pin LL_GPIO_PIN_0
#define CLICK_1_RST_GPIO_Port GPIOA
#define CLICK_1_CS_Pin LL_GPIO_PIN_4
#define CLICK_1_CS_GPIO_Port GPIOA
#define B1_Pin LL_GPIO_PIN_4
#define B1_GPIO_Port GPIOC
#define LD2_Pin LL_GPIO_PIN_0
#define LD2_GPIO_Port GPIOB
#define LD3_Pin LL_GPIO_PIN_1
#define LD3_GPIO_Port GPIOB
#define USB_DM_Pin LL_GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin LL_GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define JTMS_Pin LL_GPIO_PIN_13
#define JTMS_GPIO_Port GPIOA
#define JTCK_Pin LL_GPIO_PIN_14
#define JTCK_GPIO_Port GPIOA
#define B2_Pin LL_GPIO_PIN_0
#define B2_GPIO_Port GPIOD
#define B3_Pin LL_GPIO_PIN_1
#define B3_GPIO_Port GPIOD
#define JTDO_Pin LL_GPIO_PIN_3
#define JTDO_GPIO_Port GPIOB
#define LD1_Pin LL_GPIO_PIN_5
#define LD1_GPIO_Port GPIOB
#define STLINK_RX_Pin LL_GPIO_PIN_6
#define STLINK_RX_GPIO_Port GPIOB
#define STLINK_TX_Pin LL_GPIO_PIN_7
#define STLINK_TX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
