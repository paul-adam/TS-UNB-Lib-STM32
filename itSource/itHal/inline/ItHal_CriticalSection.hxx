///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_CriticalSection.hxx
/// @brief         Header file for critical section routines
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
/// @details       The ItHal_CriticalSection module contains means to protect parallel execution of code.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_CriticalSection_hxx
#define ItHal_CriticalSection_hxx

#ifdef IT_CONFIG_TARGET_LINUX
#include <pthread.h>
#endif // IT_CONFIG_TARGET_LINUX

/// @addtogroup ItHal
/// @{

//extern int32_t ItHal_CriticalSection_Counter;

///////////////////////////////////////////////////////////////////////////////
///
/// @brief Enter critical section
///
/// @details        This function disables interrupts, thus the following code will be guaranteed to be executed without interruption.
///                 Critical sections may be nested in different ( due to local variable ) scopes.
///
/// @return         void
///
///////////////////////////////////////////////////////////////////////////////
#ifdef IT_CONFIG_TARGET_ARM_CM

#define ItHal_enterCriticalSection( )                                          \
 uint32_t ItHal_CriticalSection_PriMask = __get_PRIMASK( );                    \
 __disable_irq( );                                                             \
 __ISB( );                                                                     \
/* ItHal_CriticalSection_Counter ++;*/

#elif defined( IT_CONFIG_TARGET_LINUX )

 void ItHal_enterCriticalSection( );

#else // IT_CONFIG_TARGET_ARM_CM

#define ItHal_enterCriticalSection( ) { }

#endif // IT_CONFIG_TARGET_ARM_CM

///////////////////////////////////////////////////////////////////////////////
///
/// @brief Leave critical section
///
/// @details        This function enables interrupts, if the interrupts have been enabled before entering the critical section.
///                 Critical sections may be nested in different ( due to local variable ) scopes.
///
/// @return         void
///
///////////////////////////////////////////////////////////////////////////////
#ifdef IT_CONFIG_TARGET_ARM_CM

#define   ItHal_leaveCriticalSection( )                                        \
{                                                                              \
/* ItHal_CriticalSection_Counter --; */                                            \
 __ISB( );                                                                     \
 __set_PRIMASK( ItHal_CriticalSection_PriMask );                               \
}

#elif defined( IT_CONFIG_TARGET_LINUX )

void ItHal_leaveCriticalSection( );

#else // IT_CONFIG_TARGET_ARM_CM

#define   ItHal_leaveCriticalSection( ) { }

#endif // IT_CONFIG_TARGET_ARM_CM

///////////////////////////////////////////////////////////////////////////////
///
/// @brief Enter critical section
///
/// @details        This function disables interrupts, thus the following code will be guaranteed to be executed without interruption.
///                 Critical sections may be nested in different ( due to local variable ) scopes.
///
/// @return         void
///
///////////////////////////////////////////////////////////////////////////////
#ifdef IT_CONFIG_TARGET_ARM_CM

#define ItHal_reenterCriticalSection( )                                        \
 ItHal_CriticalSection_PriMask = __get_PRIMASK( );                             \
 __disable_irq( );                                                             \
 __ISB( );                                                                     \
/* ItHal_CriticalSection_Counter ++; */

#elif defined( IT_CONFIG_TARGET_LINUX )

void ItHal_reenterCriticalSection( );

#else // IT_CONFIG_TARGET_ARM_CM

#define ItHal_reenterCriticalSection( ) { }

#endif // IT_CONFIG_TARGET_ARM_CM

/// @}

#endif // ItHal_CriticalSection_hxx

///////////////////////////////////////////////////////////////////////////////
