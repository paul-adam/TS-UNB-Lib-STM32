///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_Spi.cpp
/// @brief         Source file for ItHal_Spi module
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

#ifdef IT_CONFIG_HAL_SPI

#include "../inline/ItHal_Spi.hxx"

/// @addtogroup ItHal
/// @{

#ifdef IT_CONFIG_HAL_SPI1_DMA

#ifdef IT_CONFIG_HAL_SPI1

///////////////////////////////////////////////////////////////////////////////
IT_ATTRIBUTE_SECTION_USED( ".data.ItHal" )
ItHal_Spi_t ItHal_Spi1( SPI1, IT_CONFIG_HAL_SPI1_DMA, IT_CONFIG_HAL_SPI1_DMA_CHANNEL_RX, IT_CONFIG_HAL_SPI1_DMA_CHANNEL_TX );

#endif // IT_CONFIG_HAL_SPI1

#endif // IT_CONFIG_HAL_SPI1_DMA

///////////////////////////////////////////////////////////////////////////////
extern "C" IT_ATTRIBUTE_SECTION_USED( ".text.ItHal" )
void ItHal_isrSpi1( void* Spi )
{
#ifdef IT_CONFIG_HAL_SPI1
 ItHal_Spi1.isr( );
#endif // IT_CONFIG_HAL_SPI1
}

/// @}

#endif // IT_CONFIG_HAL_SPI

///////////////////////////////////////////////////////////////////////////////
