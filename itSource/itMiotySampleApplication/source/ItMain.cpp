///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItMain.cpp
/// @brief         Source file for main function
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

#include "ItConfig.h"

#include "ItHal.h"
#ifdef IT_CONFIG_MIOTY
#include "ItMioty.h"
#endif // IT_CONFIG_MIOTY
#include "ItStdioTrace.h"

#include "../inline/ItHal_Led.hxx"

/// @addtogroup ItMioty
/// @{

// This is the node specific configuration
#define IT_CONFIG_MIOTY_MAC_NETWORK_KEY 0x1b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
#define IT_CONFIG_MIOTY_MAC_EUI64       0x70, 0xB3, 0xD5, 0x67, 0x32, 0x32, 0x00, 0x00

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION_USED( ".text.ItMioty" )
int ItMain( )
{
 // ItHal must be initialized before any other "it" function
 ItHal_init( );
 // Init mioty stack
 const uint8_t MacEui64[ ]      = { IT_CONFIG_MIOTY_MAC_EUI64 };
 const uint8_t MacNetworkKey[ ] = { IT_CONFIG_MIOTY_MAC_NETWORK_KEY };
 if ( ItMioty_init( MacEui64, MacNetworkKey, IT_CONFIG_MIOTY_TX_PWR_LEVEL ) )
 {
  while ( 1 )
  {
   // Blink green LED once
   ItHal_onLedGreen( );
   HAL_Delay( 100 );
   ItHal_offLedGreen( );
   HAL_Delay( 100 );
   // Send "Hello"
   ItMioty_send( "Hello", sizeof( "Hello" ) );
  }
 }
 return 0;
}

/// @}

///////////////////////////////////////////////////////////////////////////////
