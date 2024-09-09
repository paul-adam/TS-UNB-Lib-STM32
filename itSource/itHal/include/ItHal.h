///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal.h
/// @brief         Header file of ItHal
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
/// @details       The ItHal module is the hardware abstraction layer.
///
/// @defgroup      ItHal
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_h
#define ItHal_h

#include <stdint.h>
#ifdef IT_CONFIG_TARGET_LINUX
#include <unistd.h>
#endif // IT_CONFIG_TARGET_LINUX

/// @addtogroup ItHal
/// @{

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// @brief Wait amount of time
///
/// @details        This function blocks until the delay has elapsed.
///
/// @param [in]     WaitMillisecond    The amount of time in milliseconds
///
/// @return         void
///
///////////////////////////////////////////////////////////////////////////////
static inline void ItHal_wait( uint32_t WaitMillisecond )
{
#ifdef IT_CONFIG_TARGET_LINUX
 usleep( WaitMillisecond * 1000 );
#endif // IT_CONFIG_TARGET_LINUX
#ifdef IT_CONFIG_TARGET_STM32
 void HAL_Delay( uint32_t );
 HAL_Delay( WaitMillisecond );
#endif // IT_CONFIG_TARGET_STM32
}

///////////////////////////////////////////////////////////////////////////////
///
/// @brief Initialize the HAL
///
/// @details        This function initializes the ItHal and low level drivers. It must be called as first before any other function of ItHal.
///
/// @param [in]     void
///
/// @return         void
///
///////////////////////////////////////////////////////////////////////////////
void ItHal_init( );

#ifdef __cplusplus
}
#endif

/// @}

#endif // ItHal_h

///////////////////////////////////////////////////////////////////////////////
