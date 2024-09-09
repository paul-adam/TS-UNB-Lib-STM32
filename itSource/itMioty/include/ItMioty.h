///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItMioty.h
/// @brief         Header file with API for ItMioty module
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
/// @details       ItMioty contains means for networking.
///
/// @defgroup      ItMioty
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItMioty_h
#define ItMioty_h

#ifdef IT_CONFIG_MIOTY

#include <stdint.h>

/// @addtogroup ItMioty
/// @{

#ifdef __cplusplus
extern "C" {
#endif

#define ItMioty_NETWORK_KEY_SIZE       16

///////////////////////////////////////////////////////////////////////////////
bool ItMioty_init( const uint8_t* MacEui64, const uint8_t* MacNetworkKey, uint8_t TxPower );

///////////////////////////////////////////////////////////////////////////////
bool ItMioty_isComplete( );

///////////////////////////////////////////////////////////////////////////////
bool ItMioty_send( const void* Data, uint32_t Size );

///////////////////////////////////////////////////////////////////////////////
void ItMioty_test( uint32_t Count );

#ifdef __cplusplus
}
#endif

/// @}

#endif // IT_CONFIG_MIOTY

#endif // ItMioty_h

///////////////////////////////////////////////////////////////////////////////
