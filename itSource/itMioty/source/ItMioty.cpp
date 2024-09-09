///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItMioty.cpp
/// @brief         Source file for ItMioty module
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
/// @details
///
///////////////////////////////////////////////////////////////////////////////

#include "ItConfig.h"

#ifdef IT_CONFIG_MIOTY

#include "ItEui64.h"
#include "ItMioty.h"

#ifdef IT_CONFIG_TARGET_STM32

#include "../inline/ItHal_Led.hxx"
#include "../inline/ItHal_Pin.hxx"
#include "../inline/ItHal_Spi.hxx"
#include "../inline/ItHal_TestPoint.hxx"
#include "../inline/ItHal_Tim.hxx"

#include "STM32TsUnb.h"

/// @addtogroup ItMioty
/// @{

#ifdef IT_CONFIG_MIOTY_RFM69HW

/////////////////////////////////////////////////////////////////////////////////
IT_ATTRIBUTE_SECTION( ".data.ItMioty" )
TsUnbLib::STM32::TsUnb_EU1_Rfm69hw_t TsUnb_Node;

#endif // IT_CONFIG_MIOTY_RFM69HW

#ifdef IT_CONFIG_MIOTY_RFM69W

/////////////////////////////////////////////////////////////////////////////////
IT_ATTRIBUTE_SECTION( ".data.ItMioty" )
TsUnbLib::STM32::TsUnb_EU1_Rfm69w_t TsUnb_Node;

#endif // IT_CONFIG_MIOTY_RFM69W

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION_USED( ".text.ItMioty" )
bool ItMioty_init( const uint8_t* MacEui64, const uint8_t* MacNetworkKey, uint8_t TxPower )
{
 ItStdio_traceFunctionEnter(           ItStdioTrace_MIOTY );
 ItStdio_traceValueF32(                ItStdioTrace_MIOTY, "TS_UNB_BIT_DURATION_US", TsUnb_Node.Tx.Cpu.TS_UNB_BIT_DURATION_US );
 ItStdio_traceValueU8Array(            ItStdioTrace_MIOTY, "MacEui64              ", MacEui64, sizeof( ItEui64_t ) );
 ItStdio_traceValueU8Array(            ItStdioTrace_MIOTY, "MacNetworkKey         ", MacNetworkKey, ItMioty_NETWORK_KEY_SIZE );
 ItStdio_traceValueU8(                 ItStdioTrace_MIOTY, "TxPower               ", TxPower );
 IT_CONFIG_MIOTY_SPI.init( IT_CONFIG_MIOTY_CS );
 ItHal_Pin_t::off( IT_CONFIG_MIOTY_RST );
 TsUnb_Node.init( );
#ifdef IT_CONFIG_MIOTY_FRAME
 TsUnb_Node.Tx.Cpu.sendSpi( );
#endif // IT_CONFIG_MIOTY_FRAME
 TsUnb_Node.Tx.setTxPower(       TxPower );
 TsUnb_Node.Mac.setEui64(        MacEui64[ 0 ], MacEui64[ 1 ], MacEui64[ 2 ], MacEui64[ 3 ],
                                 MacEui64[ 4 ], MacEui64[ 5 ], MacEui64[ 6 ], MacEui64[ 7 ] );
 TsUnb_Node.Mac.setNetworkKey(   MacNetworkKey[  0 ], MacNetworkKey[  1 ], MacNetworkKey[  2 ], MacNetworkKey[  3 ],
                                 MacNetworkKey[  4 ], MacNetworkKey[  5 ], MacNetworkKey[  6 ], MacNetworkKey[  7 ],
                                 MacNetworkKey[  8 ], MacNetworkKey[  9 ], MacNetworkKey[ 10 ], MacNetworkKey[ 11 ],
                                 MacNetworkKey[ 12 ], MacNetworkKey[ 13 ], MacNetworkKey[ 14 ], MacNetworkKey[ 15 ] );
 TsUnb_Node.Mac.setShortAddress( MacEui64[ 4 ], MacEui64[ 5 ] );
 TsUnb_Node.Mac.extPkgCnt = 0x01;
 ItStdio_traceFunctionLeave(           ItStdioTrace_MIOTY );
 return true;
}

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION_USED( ".text.ItMioty" )
bool ItMioty_isComplete( )
{
 return TsUnb_Node.Tx.Cpu.isComplete( );
}

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION_USED( ".text.ItMioty" )
void ItMioty_isr( )
{
 TsUnb_Node.Tx.Cpu.isr( );
}

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION( ".text.ItMioty" )
bool ItMioty_send( const void* Data, uint32_t Size )
{
 ItStdio_traceFunctionEnter(           ItStdioTrace_MIOTY );
 bool Return = TsUnb_Node.send( ( const uint8_t* ) Data, Size ) >= 0;
 ItStdio_traceAssertion( Return == true );
 ItStdio_traceFunctionLeave(           ItStdioTrace_MIOTY );
 return Return;
}

/// @}

#endif // IT_CONFIG_TARGET_STM32

#endif // IT_CONFIG_MIOTY

///////////////////////////////////////////////////////////////////////////////
