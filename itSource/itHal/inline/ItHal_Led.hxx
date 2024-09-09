///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_Led.hxx
/// @brief         Header file with API for ItHal_Led module
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
/// @details       The ItHal_Led module contains means for use the LEDs on the PCB.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_Led_hxx
#define ItHal_Led_hxx

#ifdef IT_CONFIG_HAL_LED

#include "ItHal.h"
#ifdef IT_CONFIG_HAL_SYSTICK
#include "ItHal_SysTick.h"
#endif // IT_CONFIG_HAL_SYSTICK
#include "ItStdioTrace.h"

#include "../inline/ItHal_CriticalSection.hxx"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @addtogroup ItHal
/// @{

extern const uint16_t      ItHal_LedPin [ ];
extern GPIO_TypeDef* const ItHal_LedPort[ ];

uint8_t ItHal_getCountLed( );

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleLedBlue( );
static inline void ItHal_toggleLedGreen( );
static inline void ItHal_toggleLedRed( );

///////////////////////////////////////////////////////////////////////////////
static inline bool ItHal_callbackToggleLedBlue( uintptr_t Param )
{
 ItHal_toggleLedBlue( );
#ifdef IT_CONFIG_HAL_LED_BLUE
#ifdef IT_CONFIG_HAL_SYSTICK
 ItHal_SysTick_start( ItHal_SysTick_HAL_LED_BLUE, ItHal_callbackToggleLedBlue, Param, Param );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_BLUE
 return true;
}

///////////////////////////////////////////////////////////////////////////////
static inline bool ItHal_callbackToggleLedGreen( uintptr_t Param )
{
 ItHal_toggleLedGreen( );
#ifdef IT_CONFIG_HAL_LED_GREEN
#ifdef IT_CONFIG_HAL_SYSTICK
 ItHal_SysTick_start( ItHal_SysTick_HAL_LED_GREEN, ItHal_callbackToggleLedGreen, Param, Param );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_GREEN
 return true;
}

///////////////////////////////////////////////////////////////////////////////
static inline bool ItHal_callbackToggleLedRed( uintptr_t Param )
{
 ItHal_toggleLedRed( );
#ifdef IT_CONFIG_HAL_LED_RED
#ifdef IT_CONFIG_HAL_SYSTICK
 ItHal_SysTick_start( ItHal_SysTick_HAL_LED_RED, ItHal_callbackToggleLedRed, Param, Param );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_RED
 return true;
}

///////////////////////////////////////////////////////////////////////////////
static inline bool ItHal_isIndexOkLed( uint8_t Index )
{
 return Index < ItHal_getCountLed( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offLedBlue( )
{
#ifdef IT_CONFIG_HAL_LED_BLUE
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_LED_BLUE );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_BLUE
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offLedGreen( )
{
#ifdef IT_CONFIG_HAL_LED_GREEN
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_LED_GREEN );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_GREEN
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offLedRed( )
{
#ifdef IT_CONFIG_HAL_LED_RED
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_LED_RED );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_RED
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onLedBlue( )
{
#ifdef IT_CONFIG_HAL_LED_BLUE
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_LED_BLUE );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_BLUE
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onLedGreen( )
{
#ifdef IT_CONFIG_HAL_LED_GREEN
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_LED_GREEN );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_GREEN
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onLedRed( )
{
#ifdef IT_CONFIG_HAL_LED_RED
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_LED_RED );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_RED
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_ledOff( uint8_t Index )
{
 ItStdio_traceAssertion( ItHal_isIndexOkLed( Index ) );
 LL_GPIO_ResetOutputPin( ( GPIO_TypeDef * ) ItHal_LedPort[ Index ], ItHal_LedPin[ Index ] );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_ledOn( uint8_t Index )
{
 ItStdio_traceAssertion( ItHal_isIndexOkLed( Index ) );
 LL_GPIO_SetOutputPin( ( GPIO_TypeDef * ) ItHal_LedPort[ Index ], ItHal_LedPin[ Index ] );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_ledPulse( uint8_t Index, uint32_t DurationMillisecond )
{
 ItHal_ledOn( Index );
 ItHal_wait( DurationMillisecond );
 ItHal_ledOff( Index );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_ledPulseMulti( uint8_t Index, uint32_t DurationMillisecond, uint32_t WaitMillisecond, uint32_t Count )
{
 if ( Count )
  while ( Count -- )
  {
   ItHal_ledPulse( Index, DurationMillisecond );
   ItHal_wait( WaitMillisecond );
  }
 else
  while ( 1 )
  {
   ItHal_ledPulse( Index, DurationMillisecond );
   ItHal_wait( WaitMillisecond );
  }
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_ledToggle( uint8_t Index )
{
 LL_GPIO_TogglePin( ( GPIO_TypeDef * ) ItHal_LedPort[ Index ], ItHal_LedPin[ Index ] );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_ledSignalError( uint32_t Count )
{
 while ( 1 )
 {
  ItHal_ledPulseMulti( IT_CONFIG_HAL_LED_INDEX_RED, 50, 200, Count );
  ItHal_wait( 1000 );
 }
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseLedBlue( )
{
 ItHal_enterCriticalSection( );
 ItHal_onLedBlue( );
 ItHal_offLedBlue( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseLedGreen( )
{
 ItHal_enterCriticalSection( );
 ItHal_onLedGreen( );
 ItHal_offLedGreen( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseLedRed( )
{
 ItHal_enterCriticalSection( );
 ItHal_onLedRed( );
 ItHal_offLedRed( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_startBlinkLedBlue( uint32_t PeriodMilliSecond )
{
#ifdef IT_CONFIG_HAL_LED_BLUE
#ifdef IT_CONFIG_HAL_SYSTICK
 PeriodMilliSecond >>= 1;
 ItHal_SysTick_start( ItHal_SysTick_HAL_LED_BLUE, ItHal_callbackToggleLedBlue, ( uintptr_t ) PeriodMilliSecond, PeriodMilliSecond );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_BLUE
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_startBlinkLedGreen( uint32_t PeriodMilliSecond )
{
#ifdef IT_CONFIG_HAL_LED_GREEN
#ifdef IT_CONFIG_HAL_SYSTICK
 PeriodMilliSecond >>= 1;
 ItHal_SysTick_start( ItHal_SysTick_HAL_LED_GREEN, ItHal_callbackToggleLedGreen, ( uintptr_t ) PeriodMilliSecond, PeriodMilliSecond );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_GREEN
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_startBlinkLedRed( uint32_t PeriodMilliSecond )
{
#ifdef IT_CONFIG_HAL_LED_RED
#ifdef IT_CONFIG_HAL_SYSTICK
 PeriodMilliSecond >>= 1;
 ItHal_SysTick_start( ItHal_SysTick_HAL_LED_RED, ItHal_callbackToggleLedRed, ( uintptr_t ) PeriodMilliSecond, PeriodMilliSecond );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_RED
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_stopBlinkLedBlue( )
{
#ifdef IT_CONFIG_HAL_LED_BLUE
#ifdef IT_CONFIG_HAL_SYSTICK
 ItHal_SysTick_stop( ItHal_SysTick_HAL_LED_BLUE );
 ItHal_offLedBlue( );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_BLUE
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_stopBlinkLedGreen( )
{
#ifdef IT_CONFIG_HAL_LED_GREEN
#ifdef IT_CONFIG_HAL_SYSTICK
 ItHal_SysTick_stop( ItHal_SysTick_HAL_LED_GREEN );
 ItHal_offLedGreen( );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_GREEN
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_stopBlinkLedRed( )
{
#ifdef IT_CONFIG_HAL_LED_RED
#ifdef IT_CONFIG_HAL_SYSTICK
 ItHal_SysTick_stop( ItHal_SysTick_HAL_LED_RED );
 ItHal_offLedRed( );
#endif // IT_CONFIG_HAL_SYSTICK
#endif // IT_CONFIG_HAL_LED_RED
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleLedBlue( )
{
#ifdef IT_CONFIG_HAL_LED_BLUE
 LL_GPIO_TogglePin( IT_CONFIG_HAL_LED_BLUE );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_BLUE
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleLedGreen( )
{
#ifdef IT_CONFIG_HAL_LED_GREEN
 LL_GPIO_TogglePin( IT_CONFIG_HAL_LED_GREEN );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_GREEN
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleLedRed( )
{
#ifdef IT_CONFIG_HAL_LED_RED
 LL_GPIO_TogglePin( IT_CONFIG_HAL_LED_RED );
 __ISB( );
#endif // IT_CONFIG_HAL_LED_RED
}

/// @}

#ifdef __cplusplus
}
#endif

#else // IT_CONFIG_HAL_LED

#define ItHal_ledOff(         ... ) { }
#define ItHal_ledOn(          ... ) { }
#define ItHal_ledToggle(      ... ) { }
#define ItHal_ledPulse(       ... ) { }
#define ItHal_ledPulseMulti(  ... ) { }
#define ItHal_ledSignalError( ... ) { }

#define ItHal_offLedBlue(  ... ) { }
#define ItHal_offLedGreen( ... ) { }
#define ItHal_offLedRed(   ... ) { }

#define ItHal_onLedBlue(  ... ) { }
#define ItHal_onLedGreen( ... ) { }
#define ItHal_onLedRed(   ... ) { }

#define ItHal_pulseLedBlue(  ... ) { }
#define ItHal_pulseLedGreen( ... ) { }
#define ItHal_pulseLedRed(   ... ) { }

#define ItHal_startBlinkLedBlue(  ... ) { }
#define ItHal_startBlinkLedGreen( ... ) { }
#define ItHal_startBlinkLedRed(   ... ) { }

#define ItHal_stopBlinkLedBlue(  ... ) { }
#define ItHal_stopBlinkLedGreen( ... ) { }
#define ItHal_stopBlinkLedRed(   ... ) { }

#define ItHal_toggleLedBlue(  ... ) { }
#define ItHal_toggleLedGreen( ... ) { }
#define ItHal_toggleLedRed(   ... ) { }

#endif // IT_CONFIG_HAL_LED

#endif // ItHal_Led_hxx

///////////////////////////////////////////////////////////////////////////////
