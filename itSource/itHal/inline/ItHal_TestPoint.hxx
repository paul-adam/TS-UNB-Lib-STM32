///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_TestPoint.hxx
/// @brief         Header file with API for ItHal_TestPoint module
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
/// @details       The ItHal_TestPoint module contains means for test points. These are GPIO which can be set or cleared by software to trigger a logic analyser.
///                All functions are static inline to reduce latency.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_TestPoint_hxx
#define ItHal_TestPoint_hxx

#ifdef IT_CONFIG_HAL_TEST_POINT

#include "ItHal.h"

#include "../inline/ItHal_CriticalSection.hxx"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @addtogroup ItHal
/// @{

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offTestPoint0( )
{
#ifdef IT_CONFIG_HAL_TP_0
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_TP_0 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_0
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offTestPoint1( )
{
#ifdef IT_CONFIG_HAL_TP_1
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_TP_1 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_1
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offTestPoint2( )
{
#ifdef IT_CONFIG_HAL_TP_2
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_TP_2 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_2
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_offTestPoint3( )
{
#ifdef IT_CONFIG_HAL_TP_3
 LL_GPIO_ResetOutputPin( IT_CONFIG_HAL_TP_3 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_3
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onTestPoint0( )
{
#ifdef IT_CONFIG_HAL_TP_0
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_TP_0 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_0
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onTestPoint1( )
{
#ifdef IT_CONFIG_HAL_TP_1
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_TP_1 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_1
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onTestPoint2( )
{
#ifdef IT_CONFIG_HAL_TP_2
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_TP_2 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_2
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_onTestPoint3( )
{
#ifdef IT_CONFIG_HAL_TP_3
 LL_GPIO_SetOutputPin( IT_CONFIG_HAL_TP_3 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_3
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseTestPoint0( )
{
 ItHal_enterCriticalSection( );
 ItHal_onTestPoint0( );
 ItHal_offTestPoint0( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseTestPoint1( )
{
 ItHal_enterCriticalSection( );
 ItHal_onTestPoint1( );
 ItHal_offTestPoint1( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseTestPoint2( )
{
 ItHal_enterCriticalSection( );
 ItHal_onTestPoint2( );
 ItHal_offTestPoint2( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_pulseTestPoint3( )
{
 ItHal_enterCriticalSection( );
 ItHal_onTestPoint3( );
 ItHal_offTestPoint3( );
 ItHal_leaveCriticalSection( );
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleTestPoint0( )
{
#ifdef IT_CONFIG_HAL_TP_0
 LL_GPIO_TogglePin( IT_CONFIG_HAL_TP_0 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_0
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleTestPoint1( )
{
#ifdef IT_CONFIG_HAL_TP_1
 LL_GPIO_TogglePin( IT_CONFIG_HAL_TP_1 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_1
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleTestPoint2( )
{
#ifdef IT_CONFIG_HAL_TP_2
 LL_GPIO_TogglePin( IT_CONFIG_HAL_TP_2 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_2
}

///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_toggleTestPoint3( )
{
#ifdef IT_CONFIG_HAL_TP_3
 LL_GPIO_TogglePin( IT_CONFIG_HAL_TP_3 );
 __ISB( );
#endif // IT_CONFIG_HAL_TP_3
}

/// @}

#ifdef __cplusplus
}
#endif

#else // IT_CONFIG_HAL_TEST_POINT

#define ItHal_offTestPoint0( ... )
#define ItHal_offTestPoint1( ... )
#define ItHal_offTestPoint2( ... )
#define ItHal_offTestPoint3( ... )

#define ItHal_onTestPoint0( ... )
#define ItHal_onTestPoint1( ... )
#define ItHal_onTestPoint2( ... )
#define ItHal_onTestPoint3( ... )

#define ItHal_pulseTestPoint0( ... )
#define ItHal_pulseTestPoint1( ... )
#define ItHal_pulseTestPoint2( ... )
#define ItHal_pulseTestPoint3( ... )

#define ItHal_toggleTestPoint0( ... )
#define ItHal_toggleTestPoint1( ... )
#define ItHal_toggleTestPoint2( ... )
#define ItHal_toggleTestPoint3( ... )

#endif // IT_CONFIG_HAL_TEST_POINT

#endif // ItHal_TestPoint_hxx

///////////////////////////////////////////////////////////////////////////////
