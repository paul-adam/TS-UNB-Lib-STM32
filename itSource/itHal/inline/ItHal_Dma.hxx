///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_Dma.hxx
/// @brief         Header file with ItHal_Dma_t class
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
/// @details       ItHal_Dma_t handles the functionality of one DMA channel.
///                The class can be used on different STM32 MCUs with different API (called HAL_DMA_API and HAL_DMA_API2). This reflects modifications of STMicroelectronics in the source code of the LL drivers.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_Dma_hxx
#define ItHal_Dma_hxx

#include <stdbool.h>
#include <stdint.h>

/// @addtogroup ItHal
/// @{

#ifndef IT_CONFIG_HAL_DMA_API2

///////////////////////////////////////////////////////////////////////////////
#define ItHal_Dma_ClearFlag( __ChannelIndex__ )                                \
 case LL_DMA_CHANNEL_##__ChannelIndex__:                                       \
  LL_DMA_ClearFlag_TC##__ChannelIndex__( ( DMA_TypeDef* ) _Dma );              \
  LL_DMA_ClearFlag_TE##__ChannelIndex__( ( DMA_TypeDef* ) _Dma );              \
 break

///////////////////////////////////////////////////////////////////////////////
#define ItHal_Dma_Isr( __ChannelIndex__ )                                      \
 case LL_DMA_CHANNEL_##__ChannelIndex__:                                       \
  if ( LL_DMA_IsActiveFlag_TC##__ChannelIndex__( ( DMA_TypeDef* ) _Dma ) )     \
  {                                                                            \
   LL_DMA_ClearFlag_TC##__ChannelIndex__( ( DMA_TypeDef* ) _Dma );             \
   _IsComplete = true;                                                         \
   return true;                                                                \
  }                                                                            \
  if ( LL_DMA_IsActiveFlag_TE##__ChannelIndex__( ( DMA_TypeDef* ) _Dma ) )     \
  {                                                                            \
   LL_DMA_ClearFlag_TE##__ChannelIndex__( ( DMA_TypeDef* ) _Dma );             \
   ItHal_callbackDmaError( this );                                             \
  }                                                                            \
 break

#endif // IT_CONFIG_HAL_DMA_API2

///////////////////////////////////////////////////////////////////////////////
class ItHal_Dma_t
{

 friend void ItHal_callbackDmaError( ItHal_Dma_t* Dma );

 public:

  ItHal_Dma_t( void* Dma, uintptr_t Channel )
  : _Channel( Channel )
  , _Dma( Dma )
  , _IsComplete( true )
  { }

  inline void disable( )
  {
#ifdef IT_CONFIG_HAL_DMA
#ifdef IT_CONFIG_TARGET_STM32
   LL_DMA_DisableChannel( ( DMA_TypeDef* ) _Dma, _Channel );
#endif // IT_CONFIG_TARGET_STM32
#endif // IT_CONFIG_HAL_DMA
   _IsComplete = true;
  }

  inline void disableTx( )
  {
#ifdef IT_CONFIG_HAL_DMA
#ifdef IT_CONFIG_TARGET_STM32
   LL_DMA_DisableIT_TC(   ( DMA_TypeDef* ) _Dma, _Channel );
#ifdef IT_CONFIG_HAL_DMA_API2
#else // IT_CONFIG_HAL_DMA_API2
   LL_DMA_DisableIT_TE(   ( DMA_TypeDef* ) _Dma, _Channel );
#endif // IT_CONFIG_HAL_DMA_API2
#endif // IT_CONFIG_TARGET_STM32
#endif // IT_CONFIG_HAL_DMA
  }

  inline void enable( )
  {
#ifdef IT_CONFIG_HAL_DMA
#ifdef IT_CONFIG_TARGET_STM32
   __ISB( );
   LL_DMA_EnableChannel( ( DMA_TypeDef* ) _Dma, _Channel );
#endif // IT_CONFIG_TARGET_STM32
#endif // IT_CONFIG_HAL_DMA
  }

  inline void init( uint32_t Address )
  {
#ifdef IT_CONFIG_HAL_DMA
#ifdef IT_CONFIG_TARGET_STM32
#ifdef IT_CONFIG_HAL_DMA_API2
   LL_DMA_DisableChannel( ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_SetDestAddress( ( DMA_TypeDef* ) _Dma, _Channel, Address );
#else // IT_CONFIG_HAL_DMA_API2
   LL_DMA_SetPeriphAddress( ( DMA_TypeDef* ) _Dma, _Channel, Address );
#endif // IT_CONFIG_HAL_DMA_API2
#endif // IT_CONFIG_TARGET_STM32
#endif // IT_CONFIG_HAL_DMA
  }

  inline bool isComplete( ) const
  {
   return _IsComplete;
  }

  inline bool isDma( void* Dma, uint32_t Channel ) const
  {
#ifdef IT_CONFIG_HAL_DMA
   return Dma == _Dma && Channel == _Channel;
#else // IT_CONFIG_HAL_DMA
   return false;
#endif // IT_CONFIG_HAL_DMA
  }

  inline bool isr( )
  {
#ifdef IT_CONFIG_HAL_DMA
#ifdef IT_CONFIG_HAL_DMA_API2
   if ( LL_DMA_IsActiveFlag_TC( ( DMA_TypeDef* ) _Dma, _Channel ) )
   {
     LL_DMA_ClearFlag_TC( ( DMA_TypeDef* ) _Dma, _Channel );
     _IsComplete = true;
     return true;
   }
#else // IT_CONFIG_HAL_DMA_API2
   switch ( _Channel )
   {
#ifdef LL_DMA_CHANNEL_1
    ItHal_Dma_Isr( 1 );
#endif // LL_DMA_CHANNEL_1
#ifdef LL_DMA_CHANNEL_2
    ItHal_Dma_Isr( 2 );
#endif // LL_DMA_CHANNEL_2
#ifdef LL_DMA_CHANNEL_3
    ItHal_Dma_Isr( 3 );
#endif // LL_DMA_CHANNEL_3
#ifdef LL_DMA_CHANNEL_4
    ItHal_Dma_Isr( 4 );
#endif // LL_DMA_CHANNEL_4
#ifdef LL_DMA_CHANNEL_5
    ItHal_Dma_Isr( 5 );
#endif // LL_DMA_CHANNEL_5
#ifdef LL_DMA_CHANNEL_6
    ItHal_Dma_Isr( 6 );
#endif // LL_DMA_CHANNEL_6
#ifdef LL_DMA_CHANNEL_7
    ItHal_Dma_Isr( 7 );
#endif // LL_DMA_CHANNEL_7
#ifdef LL_DMA_CHANNEL_8
    ItHal_Dma_Isr( 8 );
#endif // LL_DMA_CHANNEL_8
#ifdef LL_DMA_CHANNEL_9
    ItHal_Dma_Isr( 9 );
#endif // LL_DMA_CHANNEL_9
#ifdef LL_DMA_CHANNEL_10
    ItHal_Dma_Isr( 10 );
#endif // LL_DMA_CHANNEL_10
#ifdef LL_DMA_CHANNEL_11
    ItHal_Dma_Isr( 11 );
#endif // LL_DMA_CHANNEL_11
#ifdef LL_DMA_CHANNEL_12
    ItHal_Dma_Isr( 12 );
#endif // LL_DMA_CHANNEL_12
#ifdef LL_DMA_CHANNEL_13
    ItHal_Dma_Isr( 13 );
#endif // LL_DMA_CHANNEL_13
#ifdef LL_DMA_CHANNEL_14
    ItHal_Dma_Isr( 14 );
#endif // LL_DMA_CHANNEL_14
#ifdef LL_DMA_CHANNEL_15
    ItHal_Dma_Isr( 15 );
#endif // LL_DMA_CHANNEL_15
#ifdef LL_DMA_CHANNEL_16
    ItHal_Dma_Isr( 16 );
#endif // LL_DMA_CHANNEL_16
   }
#endif // IT_CONFIG_HAL_DMA_API2
#endif // IT_CONFIG_HAL_DMA
   return false;
  }

  inline bool start( volatile const void* Data, uint32_t Size )
  {
#ifdef IT_CONFIG_HAL_DMA
   if ( !_IsComplete )
    return false;
#ifdef IT_CONFIG_TARGET_STM32
   __ISB( );
   LL_DMA_DisableChannel(   ( DMA_TypeDef* ) _Dma, _Channel );
   clearFlag( );
   _IsComplete = false;
#ifdef IT_CONFIG_HAL_DMA_API2
   LL_DMA_SetSrcAddress(    ( DMA_TypeDef* ) _Dma, _Channel, ( uintptr_t ) Data );
   LL_DMA_SetBlkDataLength( ( DMA_TypeDef* ) _Dma, _Channel, Size );
   LL_DMA_EnableIT_TC(      ( DMA_TypeDef* ) _Dma, _Channel );
#else // IT_CONFIG_HAL_DMA_API2
   LL_DMA_SetMemoryAddress( ( DMA_TypeDef* ) _Dma, _Channel, ( uintptr_t ) Data );
   LL_DMA_SetDataLength(    ( DMA_TypeDef* ) _Dma, _Channel, Size );
   __ISB( );
   LL_DMA_EnableIT_TE(      ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_EnableIT_TC(      ( DMA_TypeDef* ) _Dma, _Channel );
#endif // IT_CONFIG_HAL_DMA_API2
#endif // IT_CONFIG_TARGET_STM32
#endif // IT_CONFIG_HAL_DMA
   return true;
  }

protected:

  inline void clearFlag( ) const
  {
#ifdef IT_CONFIG_HAL_DMA
#ifdef IT_CONFIG_HAL_DMA_API2
   LL_DMA_ClearFlag_DTE(  ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_ClearFlag_SUSP( ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_ClearFlag_TC(   ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_ClearFlag_TO(   ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_ClearFlag_ULE(  ( DMA_TypeDef* ) _Dma, _Channel );
   LL_DMA_ClearFlag_USE(  ( DMA_TypeDef* ) _Dma, _Channel );
#else // IT_CONFIG_HAL_DMA_API2
   switch ( _Channel )
   {
#ifdef LL_DMA_CHANNEL_1
    ItHal_Dma_ClearFlag( 1 );
#endif // LL_DMA_CHANNEL_1
#ifdef LL_DMA_CHANNEL_2
    ItHal_Dma_ClearFlag( 2 );
#endif // LL_DMA_CHANNEL_2
#ifdef LL_DMA_CHANNEL_3
    ItHal_Dma_ClearFlag( 3 );
#endif // LL_DMA_CHANNEL_3
#ifdef LL_DMA_CHANNEL_4
    ItHal_Dma_ClearFlag( 4 );
#endif // LL_DMA_CHANNEL_4
#ifdef LL_DMA_CHANNEL_5
    ItHal_Dma_ClearFlag( 5 );
#endif // LL_DMA_CHANNEL_5
#ifdef LL_DMA_CHANNEL_6
    ItHal_Dma_ClearFlag( 6 );
#endif // LL_DMA_CHANNEL_6
#ifdef LL_DMA_CHANNEL_7
    ItHal_Dma_ClearFlag( 7 );
#endif // LL_DMA_CHANNEL_7
#ifdef LL_DMA_CHANNEL_8
    ItHal_Dma_ClearFlag( 8 );
#endif // LL_DMA_CHANNEL_8
#ifdef LL_DMA_CHANNEL_9
    ItHal_Dma_ClearFlag( 9 );
#endif // LL_DMA_CHANNEL_9
#ifdef LL_DMA_CHANNEL_10
    ItHal_Dma_ClearFlag( 10 );
#endif // LL_DMA_CHANNEL_10
#ifdef LL_DMA_CHANNEL_11
    ItHal_Dma_ClearFlag( 11 );
#endif // LL_DMA_CHANNEL_11
#ifdef LL_DMA_CHANNEL_12
    ItHal_Dma_ClearFlag( 12 );
#endif // LL_DMA_CHANNEL_12
#ifdef LL_DMA_CHANNEL_13
    ItHal_Dma_ClearFlag( 13 );
#endif // LL_DMA_CHANNEL_13
#ifdef LL_DMA_CHANNEL_14
    ItHal_Dma_ClearFlag( 14 );
#endif // LL_DMA_CHANNEL_14
#ifdef LL_DMA_CHANNEL_15
    ItHal_Dma_ClearFlag( 15 );
#endif // LL_DMA_CHANNEL_15
#ifdef LL_DMA_CHANNEL_16
    ItHal_Dma_ClearFlag( 16 );
#endif // LL_DMA_CHANNEL_16
   }
#endif // IT_CONFIG_HAL_DMA_API2
#endif // IT_CONFIG_HAL_DMA
  }

  uintptr_t _Channel;
  void*     _Dma;
  bool      _IsComplete;

};

/// @}

#endif // ItHal_Dma_hxx

///////////////////////////////////////////////////////////////////////////////
