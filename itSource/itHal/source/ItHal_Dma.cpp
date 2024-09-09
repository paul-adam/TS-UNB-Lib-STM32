///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_Dma.cpp
/// @brief         Source file for ItHal_Dma module
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
/// @details       API for real time clock device.
///
///////////////////////////////////////////////////////////////////////////////

#include "ItConfig.h"

#ifdef IT_CONFIG_HAL_DMA

#include "ItStdioTrace.h"

#include "../inline/ItHal_Dma.hxx"
#include "../inline/ItHal_Spi.hxx"

/// @addtogroup ItHal
/// @{

///////////////////////////////////////////////////////////////////////////////
IT_ATTRIBUTE_SECTION_WEAK( ".text.ItHal" )
void ItHal_callbackDmaError( ItHal_Dma_t* Dma )
{
 Dma->disable( );
// ItStdio_traceErrorFunctionEnter( ItStdioTrace_HAL );
// ItStdio_traceValuePtr(           ItStdioTrace_HAL, "Dma    ", Dma->_Dma );
// ItStdio_traceValueU32(           ItStdioTrace_HAL, "Channel", Dma->_Channel );
// ItStdio_traceErrorFunctionLeave( ItStdioTrace_HAL );
// ItStdio_traceBlock( "" );
}

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION_WEAK( ".text.ItHal" )
bool ItHal_isrDma( void* Dma, uint32_t Channel )
{
#ifdef IT_CONFIG_HAL_SPI1_DMA
 if ( ItHal_Spi1.isDmaRx( Dma, Channel ) )
 {
  ItHal_Spi1.isrRx( );
  return true;
 }
 if ( ItHal_Spi1.isDmaTx( Dma, Channel ) )
 {
  ItHal_Spi1.isrTx( );
  return true;
 }
#endif // IT_CONFIG_HAL_SPI1_DMA
 return false;
}

/// @}

#endif// IT_CONFIG_HAL_DMA

///////////////////////////////////////////////////////////////////////////////
