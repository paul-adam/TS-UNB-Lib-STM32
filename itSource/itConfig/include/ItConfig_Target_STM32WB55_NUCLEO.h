///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItConfig_Target_STM32WB55_NUCLEO.h
/// @brief         Header file with defines for configuration on specific execution target
///
/// @copyright     Paul ADAM, inidinn.technology, all rights reserved\n
///                Redistribution and use in source and binary forms, with or without modification, are
///                permitted without payment of copyright license fees provided that you satisfy the
///                following conditions:\n
///                - You must retain the complete text of this software license in redistributions of the
///                  "itSource" software or your modifications thereto in source code form.\n
///                - You must retain the complete text of this software license in the documentation and/or
///                  other materials provided with redistributions of the "itSource" software or your
///                  modifications thereto in binary form.\n
///                - You must make available free of charge copies of the complete source code of the "itSource"
///                  software and your modifications thereto to recipients of copies in binary form.\n
///                - The name of Paul ADAM or inidinn.technology may not be used to endorse or promote products
///                  derived from this "itSource" software without prior written permission.\n
///                - You may not charge copyright license fees for anyone to use, copy or distribute the
///                  "itSource" software or your modifications thereto.\n
///                - Your modified versions of the "itSource" software must carry prominent notices stating
///                  that you changed the "itSource" software and the date of any change.\n
///                \n
/// @copyright     NO PATENT LICENSE\n
///                NO EXPRESS OR IMPLIED LICENSES TO ANY PATENT CLAIMS, including without limitation the patents
///                of Fraunhofer-Gesellschaft or STMicroelectronics, ARE GRANTED BY THIS SOFTWARE LICENSE.
///                Paul ADAM provides no warranty of patent non-infringement with respect to this "itSource"
///                software. You may use this "itSource" software or modifications thereto only for purposes
///                that are authorized by appropriate patent licenses.\n
///                \n
///                DISCLAIMER\n
///                This "itSource" software is provided by Paul ADAM "AS IS" and WITHOUT ANY EXPRESS OR IMPLIED
///                WARRANTIES, including but not limited to the implied warranties of merchantability and fitness
///                for a particular purpose. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
///                for any direct, indirect, incidental, special, exemplary, or consequential damages, including
///                but not limited to procurement of substitute goods or services; loss of use, data, or profits,
///                or business interruption, however caused and on any theory of liability, whether in contract,
///                strict liability, or tort (including negligence), arising in any way out of the use of
///                this "itSource" software, even if advised of the possibility of such damage.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItConfig_Target_STM32WB55_NUCLEO_h
#define ItConfig_Target_STM32WB55_NUCLEO_h

/// @addtogroup ItConfig
/// @{

/// The name of the execution target ( may be used for tracing )
#define IT_CONFIG_TARGET_NAME                                        "  STM32WB55_NUCLEO  "

///////////////////////////////////////////////////////////////////////////////
///
/// Implemented features
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// mioty

#ifdef IT_CONFIG_MIOTY

/// Mioty on this execution target uses SPI1
#define IT_CONFIG_HAL_SPI1
/// Mioty on this execution target uses TIM16
#define IT_CONFIG_HAL_TIM16

#endif // IT_CONFIG_MIOTY

///////////////////////////////////////////////////////////////////////////////
///
/// Config of implemented features
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// hal

#ifdef IT_CONFIG_HAL_LED

/// The blue LED on this execution target uses this GPIO
#define IT_CONFIG_HAL_LED_BLUE                                       GPIOB, LL_GPIO_PIN_5
/// The blue LED on this execution target uses this GPIO
#define IT_CONFIG_HAL_LED_GREEN                                      GPIOB, LL_GPIO_PIN_0
/// The blue LED on this execution target uses this GPIO
#define IT_CONFIG_HAL_LED_RED                                        GPIOB, LL_GPIO_PIN_1

/// Index of blue LED on this execution target
#define IT_CONFIG_HAL_LED_INDEX_BLUE                                 0
/// Index of green LED on this execution target
#define IT_CONFIG_HAL_LED_INDEX_GREEN                                1
/// Index of red LED on this execution target
#define IT_CONFIG_HAL_LED_INDEX_RED                                  2
/// Start of indices of additional LEDs on this execution target
#define IT_CONFIG_HAL_LED_INDEX_ADDITIONAL                           3

/// Pin array for LEDs
#define IT_CONFIG_HAL_LED_PIN                                        LL_GPIO_PIN_5, LL_GPIO_PIN_0, LL_GPIO_PIN_1
/// Port array for LEDs
#define IT_CONFIG_HAL_LED_PORT                                       GPIOB,         GPIOB,         GPIOB

#endif // IT_CONFIG_HAL_LED

#ifdef IT_CONFIG_HAL_MIKROE

#define IT_CONFIG_HAL_MIKROE_1_CS_PIN                                LL_GPIO_PIN_4
#define IT_CONFIG_HAL_MIKROE_1_CS_PORT                               GPIOA
#define IT_CONFIG_HAL_MIKROE_1_CS                                    IT_CONFIG_HAL_MIKROE_1_CS_PORT, IT_CONFIG_HAL_MIKROE_1_CS_PIN
#define IT_CONFIG_HAL_MIKROE_1_RST_PIN                               LL_GPIO_PIN_0
#define IT_CONFIG_HAL_MIKROE_1_RST_PORT                              GPIOA
#define IT_CONFIG_HAL_MIKROE_1_RST                                   IT_CONFIG_HAL_MIKROE_1_RST_PORT, IT_CONFIG_HAL_MIKROE_1_RST_PIN

#define IT_CONFIG_HAL_MIKROE_2_CS_PIN                                LL_GPIO_PIN_9
#define IT_CONFIG_HAL_MIKROE_2_CS_PORT                               GPIOA
#define IT_CONFIG_HAL_MIKROE_2_CS                                    IT_CONFIG_HAL_MIKROE_2_CS_PORT, IT_CONFIG_HAL_MIKROE_2_CS_PIN
#define IT_CONFIG_HAL_MIKROE_2_RST_PIN                               LL_GPIO_PIN_1
#define IT_CONFIG_HAL_MIKROE_2_RST_PORT                              GPIOA
#define IT_CONFIG_HAL_MIKROE_2_RST                                   IT_CONFIG_HAL_MIKROE_2_RST_PORT, IT_CONFIG_HAL_MIKROE_2_RST_PIN

#define IT_CONFIG_HAL_MIKROE_SPI                                     SPI1
#define IT_CONFIG_HAL_MIKROE_SPI_CLK_PIN                             LL_GPIO_PIN_5
#define IT_CONFIG_HAL_MIKROE_SPI_CLK_PORT                            GPIOA
#define IT_CONFIG_HAL_MIKROE_SPI_MISO_PIN                            LL_GPIO_PIN_6
#define IT_CONFIG_HAL_MIKROE_SPI_MISO_PORT                           GPIOA
#define IT_CONFIG_HAL_MIKROE_SPI_MOSI_PIN                            LL_GPIO_PIN_7
#define IT_CONFIG_HAL_MIKROE_SPI_MOSI_PORT                           GPIOA

#endif // IT_CONFIG_HAL_MIKROE

#ifdef IT_CONFIG_HAL_SPI1

#define IT_CONFIG_HAL_SPI1_DMA                                       DMA1
#define IT_CONFIG_HAL_SPI1_DMA_CHANNEL_RX                            LL_DMA_CHANNEL_3
#define IT_CONFIG_HAL_SPI1_DMA_CHANNEL_TX                            LL_DMA_CHANNEL_4
#define IT_CONFIG_HAL_SPI1_CS_COUNT                                  1
#define IT_CONFIG_HAL_SPI1_CS_PIN                                    LL_GPIO_PIN_4
#define IT_CONFIG_HAL_SPI1_CS_PORT                                   GPIOA
#define IT_CONFIG_HAL_SPI1_CS                                        IT_CONFIG_HAL_SPI1_CS_PORT, IT_CONFIG_HAL_SPI1_CS_PIN

#endif // IT_CONFIG_HAL_SPI1

#define IT_CONFIG_HAL_TP_0                                           GPIOB, LL_GPIO_PIN_2
#define IT_CONFIG_HAL_TP_1                                           GPIOC, LL_GPIO_PIN_5
#define IT_CONFIG_HAL_TP_2                                           GPIOE, LL_GPIO_PIN_4
#define IT_CONFIG_HAL_TP_3                                           GPIOC, LL_GPIO_PIN_0

///////////////////////////////////////////////////////////////////////////////
// mioty

#ifdef IT_CONFIG_MIOTY

#define IT_CONFIG_MIOTY_CS_PIN                                       IT_CONFIG_HAL_MIKROE_1_CS_PIN
#define IT_CONFIG_MIOTY_CS_PORT                                      IT_CONFIG_HAL_MIKROE_1_CS_PORT
#define IT_CONFIG_MIOTY_CS                                           IT_CONFIG_HAL_MIKROE_1_CS
#define IT_CONFIG_MIOTY_RST_PIN                                      IT_CONFIG_HAL_MIKROE_1_RST_PIN
#define IT_CONFIG_MIOTY_RST_PORT                                     IT_CONFIG_HAL_MIKROE_1_RST_PORT
#define IT_CONFIG_MIOTY_RST                                          IT_CONFIG_HAL_MIKROE_1_RST
#define IT_CONFIG_MIOTY_SPI                                          ItHal_Spi1
#define IT_CONFIG_MIOTY_TIM                                          ItHal_Tim16
#define IT_CONFIG_MIOTY_TIM_BASE                                     TIM16_BASE
#define ItHal_isrTim16                                               ItMioty_isr

#endif // IT_CONFIG_MIOTY

///////////////////////////////////////////////////////////////////////////////
// target

#define IT_CONFIG_TARGET_32B                                                             ///< Target is 32 bit processor

#define IT_CONFIG_TARGET_ARM_CM                                                          ///< Code specific to ARM Cortex M processor
#define IT_CONFIG_TARGET_ARM_CM4                                                         ///< Code specific to ARM Cortex M4 processor

#define IT_CONFIG_TARGET_STM32                                                           ///< Code specific to STM32 processor
#define IT_CONFIG_TARGET_STM32WB                                                         ///< Code specific to STM32WB processor

///////////////////////////////////////////////////////////////////////////////
// include

#ifdef IT_CONFIG_HAL_SPI

#include "stm32wbxx_ll_spi.h"

#endif // IT_CONFIG_HAL_SPI

///////////////////////////////////////////////////////////////////////////////

/// @}

#endif // ItConfig_Target_STM32WB55_NUCLEO_h

///////////////////////////////////////////////////////////////////////////////

