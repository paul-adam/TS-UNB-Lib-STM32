///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_Spi.hxx
/// @brief         Header file with API for ItHal_Spi module
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
/// @details       API for SPI access.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_Spi_hxx
#define ItHal_Spi_hxx

#ifdef IT_CONFIG_HAL_SPI

#include "ItCallback.h"

#include "../inline/ItHal_Dma.hxx"
#include "../inline/ItHal_Pin.hxx"

#include <stdbool.h>
#include <string.h>

/// @addtogroup ItHal
/// @{

#define ItHal_SPI_POLL_TIMEOUT                   500

///////////////////////////////////////////////////////////////////////////////
class ItHal_Spi_t
: protected ItHal_Pin_t
{

 public:

  ItHal_Spi_t( SPI_TypeDef* Spi, DMA_TypeDef* Dma, uintptr_t DmaChannelRx, uintptr_t DmaChannelTx, GPIO_TypeDef* Port = 0, uint16_t Pin = 0 )
  : ItHal_Pin_t( Port, Pin )
  , _CompleteTx( true )
  , _DataTxMulti( 0 )
  , _DmaRx( Dma, DmaChannelRx )
  , _DmaTx( Dma, DmaChannelTx )
  , _Spi( Spi )
  {
   _CallbackParam.clear( );
  }

  inline void init( )
  {
   LL_SPI_SetRxFIFOThreshold( _Spi, LL_SPI_RX_FIFO_TH_QUARTER );
   _DmaRx.init( LL_SPI_DMA_GetRegAddr( _Spi ) );
   _DmaTx.init( LL_SPI_DMA_GetRegAddr( _Spi ) );
  }

  inline void init( ItCallback_t Callback, uintptr_t CallbackParam )
  {
   _CallbackParam.set( Callback, CallbackParam );
  }

  inline void init( GPIO_TypeDef* Port, uint16_t Pin )
  {
   ItHal_Pin_t::init( Port, Pin );
  }

  inline bool isComplete( ) const
  {
   return _CompleteTx;
  }

  inline bool wait( uint32_t TimeOut ) const
  {
   while ( TimeOut -- )
    if ( isComplete( ) )
     return true;
   return false;
  }

  inline bool isDmaRx( void* Dma, uint32_t Channel ) const
  {
   return _DmaRx.isDma( Dma, Channel );
  }

  inline bool isDmaTx( void* Dma, uint32_t Channel ) const
  {
   return _DmaTx.isDma( Dma, Channel );
  }

  inline void isr( )
  {
   if ( LL_SPI_IsActiveFlag_RXNE( _Spi ) )
    LL_SPI_ReceiveData8( _Spi );
   if ( LL_SPI_IsActiveFlag_TXE( _Spi ) )
   {
    if (    LL_SPI_GetTxFIFOLevel(    _Spi ) == LL_SPI_TX_FIFO_EMPTY
         && !LL_SPI_IsActiveFlag_BSY( _Spi ) )
    {
     __ISB( );
     LL_SPI_DisableIT_TXE( _Spi );
     if ( !_CompleteTx )
     {
      if ( _DataTxMulti )
      {
       unselectSlave( );
       uint32_t SizeTx = _DataTxMulti[ 0 ];
       if ( SizeTx )
       {
        const uint8_t* DataTx = _DataTxMulti + 1;
        selectSlave( );
        startTx( DataTx, SizeTx, DataTx + SizeTx );
       }
       else
       {
        _CompleteTx = true;
        if ( _CallbackParam.isOngoing( ) )
         _CallbackParam.callback( );
        _DataTxMulti = 0;
       }
      }
      else
      {
       _CompleteTx = true;
      }
     }
    }
   }
  }

  inline void isrRx( )
  {
   if ( _DmaRx.isr( ) )
   {
    _DmaRx.disable( );
   }
  }
  inline void isrTx( )
  {
   if ( _DmaTx.isr( ) )
   {
    _DmaTx.disable( );
    LL_SPI_EnableIT_TXE( _Spi );
   }
  }

  inline bool readRegisterU8( uint8_t Register, uint8_t& ValueRx, uint8_t ValueTx, GPIO_TypeDef* Port, uint16_t Pin, uint32_t TimeOut = ItHal_SPI_POLL_TIMEOUT )
  {
   uint8_t DataTx[ ] = { Register, ValueTx };
   uint8_t DataRx[ ] = { ValueTx,  ValueTx };
   selectSlave( Port, Pin );
   bool Return = start( DataTx, DataRx, sizeof( DataTx ) );
   if ( Return )
    Return = wait( TimeOut );
   unselectSlave( Port, Pin );
   if ( Return )
    ValueRx = DataRx[ 1 ];
   return Return;
  }

  inline void selectSlave( ) const
  {
   ItHal_Pin_t::off( );
   __ISB( );
  }

  static inline void selectSlave( GPIO_TypeDef* Port, uint16_t Pin )
  {
   ItHal_Pin_t::off( Port, Pin );
  }

  inline bool start( const uint8_t* DataTx, uint8_t* DataRx, uint32_t Size )
  {
   if ( !isComplete( ) )
    return false;
   _CompleteTx = false;
   _DataTxMulti = 0;
   _DmaRx.start( DataRx, Size );
   _DmaTx.start( DataTx, Size );
   LL_SPI_EnableDMAReq_RX( _Spi );
   LL_SPI_EnableDMAReq_TX( _Spi );
//   LL_SPI_DisableIT_RXNE(  _Spi );
   LL_SPI_DisableIT_TXE(   _Spi );
   __ISB( );
   LL_SPI_Enable(          _Spi );
   _DmaRx.enable( );
   _DmaTx.enable( );
   return true;
  }

  inline bool startRx( uint8_t* DataRx, uint32_t SizeRx, uint8_t DataTx )
  {
   if ( !isComplete( ) )
    return false;
   _DataTxMulti = 0;
   memset( DataRx, DataTx, SizeRx );
   return start( DataRx, DataRx, SizeRx );
  }

  inline bool startTx( const uint8_t* DataTx, uint32_t SizeTx )
  {
   if ( !isComplete( ) )
    return false;
   startTx( DataTx, SizeTx, 0 );
   return true;
  }

  inline bool startTxMulti( const uint8_t* DataTxMulti )
  {
   if ( !isComplete( ) )
    return false;
   const uint8_t* DataTx = DataTxMulti + 1;
   uint32_t       SizeTx = DataTxMulti[ 0 ];
//   ItStdio_traceAssertion( SizeTx > 0 );
   selectSlave( );
   startTx( DataTx, SizeTx, DataTx + SizeTx );
   return true;
  }

  inline void unselectSlave( ) const
  {
   __ISB( );
   ItHal_Pin_t::on( );
  }

  static inline void unselectSlave( GPIO_TypeDef* Port, uint16_t Pin )
  {
   __ISB( );
   ItHal_Pin_t::on( Port, Pin );
  }

  inline bool writeRegisterU8( uint8_t Register, uint8_t ValueTx, GPIO_TypeDef* Port, uint16_t Pin, uint32_t TimeOut = ItHal_SPI_POLL_TIMEOUT )
  {
   uint8_t DataTx[ ] = { Register, ValueTx };
//   uint8_t DataRx[ ] = { ValueTx,  ValueTx };
   selectSlave( Port, Pin );
//   bool Return = start( DataTx, DataRx, sizeof( DataTx ) );
   bool Return = startTx( DataTx, sizeof( DataTx ) );
   if ( Return )
    Return = wait( TimeOut );
   unselectSlave( Port, Pin );
   return Return;
  }

 protected:

  inline void startTx( const uint8_t* DataTx, uint32_t SizeTx, const uint8_t* DataTxMulti )
  {
   _CompleteTx = false;
   _DataTxMulti = DataTxMulti;
   _DmaTx.start( DataTx, SizeTx );
   LL_SPI_EnableDMAReq_TX( _Spi );
   LL_SPI_EnableIT_RXNE(   _Spi );
   LL_SPI_DisableIT_TXE(   _Spi );
   __ISB( );
   LL_SPI_Enable(          _Spi );
   _DmaTx.enable( );
  }

  ItCallbackParam_t   _CallbackParam;
  volatile bool       _CompleteTx;
  const uint8_t*      _DataTxMulti;
  ItHal_Dma_t         _DmaRx;
  ItHal_Dma_t         _DmaTx;
  SPI_TypeDef*        _Spi;

};

#ifdef IT_CONFIG_HAL_SPI1

extern ItHal_Spi_t ItHal_Spi1;

#endif // IT_CONFIG_HAL_SPI1

/// @}

#else // IT_CONFIG_HAL_SPI

//static inline int32_t ItHal_SPI1_Init( )                                                                  { return 0; }
//static inline int32_t ItHal_SPI1_DeInit( )                                                                { return 0; }
//static inline int32_t ItHal_SPI1_ReadReg(  uint16_t Addr, uint16_t Reg, uint8_t* pData, uint16_t Length ) { return 0; }
//static inline int32_t ItHal_SPI1_WriteReg( uint16_t Addr, uint16_t Reg, uint8_t* pData, uint16_t Length ) { return 0; }
//
//static inline int32_t ItHal_SPI2_Init( )                                                                  { return 0; }
//static inline int32_t ItHal_SPI2_DeInit( )                                                                { return 0; }
//static inline int32_t ItHal_SPI2_ReadRegister(  uint16_t Addr, uint16_t Reg, uint8_t* pData, uint16_t Length ) { return 0; }
//static inline int32_t ItHal_SPI2_WriteReg( uint16_t Addr, uint16_t Reg, uint8_t* pData, uint16_t Length ) { return 0; }

#endif // IT_CONFIG_HAL_SPI

#endif // ItHal_Spi_hxx

///////////////////////////////////////////////////////////////////////////////
