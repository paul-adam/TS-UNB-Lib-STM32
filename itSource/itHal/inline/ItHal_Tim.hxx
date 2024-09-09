///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_Tim.hxx
/// @brief         Header file with API for ItHal_Tim_t class
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
/// @details       The ItHal_Tim module contains means for timer peripheral.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_Tim_hxx
#define ItHal_Tim_hxx

#ifdef IT_CONFIG_HAL_TIM

#ifdef IT_CONFIG_HAL_TIM_CALLBACK
#include "ItCallback.h"
#endif // IT_CONFIG_HAL_TIM_CALLBACK

#include <stdint.h>

/// @addtogroup ItHal
/// @{

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         The ItHal_Tim_t class manages the functionality of a timer
///
/// @details       The ItHal_Tim_t class encapsulates one timer of the underlying peripheral.
///                It can be used for 16 or 32 bit timer.
///
///////////////////////////////////////////////////////////////////////////////
template < uintptr_t _TimT >
class ItHal_Tim_t
{

 public:

  ItHal_Tim_t( )
  : _Complete( true )
  {
#ifdef IT_CONFIG_HAL_TIM_CALLBACK
   _CallbackParam.clear( );
#endif // IT_CONFIG_HAL_TIM_CALLBACK
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function clears the flags of the underlying timer peripheral
///
///////////////////////////////////////////////////////////////////////////////
  inline void clearFlag( ) const
  {
   LL_TIM_ClearFlag_CC1(    getTimer( ) );
   LL_TIM_ClearFlag_CC1OVR( getTimer( ) );
   LL_TIM_ClearFlag_CC2(    getTimer( ) );
   LL_TIM_ClearFlag_CC2OVR( getTimer( ) );
   LL_TIM_ClearFlag_CC2(    getTimer( ) );
   LL_TIM_ClearFlag_CC2OVR( getTimer( ) );
   LL_TIM_ClearFlag_CC3(    getTimer( ) );
   LL_TIM_ClearFlag_CC3OVR( getTimer( ) );
   LL_TIM_ClearFlag_CC4(    getTimer( ) );
   LL_TIM_ClearFlag_CC4OVR( getTimer( ) );
   LL_TIM_ClearFlag_CC5(    getTimer( ) );
   LL_TIM_ClearFlag_CC6(    getTimer( ) );
   LL_TIM_ClearFlag_COM(    getTimer( ) );
   LL_TIM_ClearFlag_SYSBRK( getTimer( ) );
   LL_TIM_ClearFlag_TRIG(   getTimer( ) );
   LL_TIM_ClearFlag_UPDATE( getTimer( ) );
#ifdef IT_CONFIG_TARGET_STM32U5
     LL_TIM_ClearFlag_DIR(  getTimer( ) );
     LL_TIM_ClearFlag_IDX(  getTimer( ) );
     LL_TIM_ClearFlag_IERR( getTimer( ) );
     LL_TIM_ClearFlag_TERR( getTimer( ) );
#endif // IT_CONFIG_TARGET_STM32U5
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function declares the timer "to continue"
///
///////////////////////////////////////////////////////////////////////////////
  inline void continueTimer( )
  {
   _Complete = false;
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function gives access to the current counter value of the underlying timer peripheral
///
///////////////////////////////////////////////////////////////////////////////
  static inline uint32_t getCounter( )
  {
   return LL_TIM_GetCounter( ( TIM_TypeDef* ) _TimT );
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function gives access to the underlying timer peripheral
///
///////////////////////////////////////////////////////////////////////////////
  static inline TIM_TypeDef* getTimer( )
  {
   return ( TIM_TypeDef* ) _TimT;
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function can be used to check whether the timer is running
///
///////////////////////////////////////////////////////////////////////////////
  inline bool isComplete( ) const
  {
   return _Complete;
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function can be used to check whether the underlying timer peripheral is 32 bit
///
///////////////////////////////////////////////////////////////////////////////
  static inline bool is32BitTimer( )
  {
   return IS_TIM_32B_COUNTER_INSTANCE( getTimer( ) );
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         The interrupt service routine to be called by hardware interrupt handler
///
///////////////////////////////////////////////////////////////////////////////
  inline bool isr( )
  {
   if ( LL_TIM_IsActiveFlag_UPDATE( getTimer( ) ) == 1 )
   {
    LL_TIM_ClearFlag_UPDATE( getTimer( ) );
    _Complete = true;
#ifdef IT_CONFIG_HAL_TIM_CALLBACK
    if ( _CallbackParam.isOngoing( ) )
     _CallbackParam.callback( );
#endif // IT_CONFIG_HAL_TIM_CALLBACK
    return true;
   }
   return false;
  }

#ifdef IT_CONFIG_HAL_TIM_CALLBACK

  inline void setCallback( ItCallback_t Callback, uintptr_t CallbackParam = 0 )
  {
   _CallbackParam.set( Callback, CallbackParam );
  }

#endif // IT_CONFIG_HAL_TIM_CALLBACK

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function starts the timer
///
///////////////////////////////////////////////////////////////////////////////
  inline void start( )
  {
   _Complete = false;
   clearFlag( );
   LL_TIM_SetCounter(      getTimer( ), 0 );
   LL_TIM_EnableIT_UPDATE( getTimer( ) );
   __ISB( );
   LL_TIM_EnableCounter(   getTimer( ) );
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function stops (cancels, aborts) the timer
///
///////////////////////////////////////////////////////////////////////////////
  inline void stop( )
  {
   LL_TIM_DisableCounter( getTimer( ) );
   __ISB( );
   _Complete = true;
  }

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         This function updates the maximal value to what the counter will be incremented
///
///////////////////////////////////////////////////////////////////////////////
  static inline void updateCounterMax( uint32_t CounterMax )
  {
   LL_TIM_SetAutoReload( getTimer( ), CounterMax - 1 );
   __DSB( );
  }

 protected:

#ifdef IT_CONFIG_HAL_TIM_CALLBACK
  ItCallbackParam_t     _CallbackParam;
#endif // IT_CONFIG_HAL_TIM_CALLBACK
  volatile bool         _Complete;               ///< This variable will become true, if timer period has finished.

};

#ifdef IT_CONFIG_HAL_TIM2

extern ItHal_Tim_t< TIM2_BASE > ItHal_Tim2;

#endif // IT_CONFIG_HAL_TIM2

#ifdef IT_CONFIG_HAL_TIM16

extern ItHal_Tim_t< TIM16_BASE > ItHal_Tim16;

#endif // IT_CONFIG_HAL_TIM16

#ifdef IT_CONFIG_HAL_TIM17

extern ItHal_Tim_t< TIM17_BASE > ItHal_Tim17;

#endif // IT_CONFIG_HAL_TIM17

/// @}

#endif // IT_CONFIG_HAL_TIM

#endif // ItHal_Tim_hxx

///////////////////////////////////////////////////////////////////////////////
