///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItHal_TimExtension.hxx
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
/// @details       The ItHal_TimExtension_t class provides extension for ItHal_Tim_t, if used with 16 bit timer peripherals.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItHal_TimExtension_hxx
#define ItHal_TimExtension_hxx

#ifdef IT_CONFIG_HAL_TIM

#ifdef IT_CONFIG_HAL_SYSTICK
#include "ItHal_SysTick.h"
#endif //IT_CONFIG_HAL_SYSTICK

#include "../inline/ItHal_CriticalSection.hxx"
#include "../inline/ItHal_TestPoint.hxx"
#include "../inline/ItHal_Tim.hxx"

/// @addtogroup ItHal
/// @{

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         The ItHal_Tim_t class manages the functionality of a timer
///
/// @details       The ItHal_TimExtension_t class provides extension for ItHal_Tim_t, if used with 16 bit timer peripherals.
///
///////////////////////////////////////////////////////////////////////////////
template < typename _T, uintptr_t _TimT, int32_t _CounterMinT >
class ItHal_TimExtension_t
: public ItHal_Tim_t< _TimT >
{

 typedef ItHal_Tim_t< _TimT > BaseClass_t;

 public:

  ItHal_TimExtension_t( )
  {
   clear( );
  }

  inline void addInterval( _T Interval )
  {
   ItHal_enterCriticalSection( );
   _IntervalAdded   = true;
   _IntervalPrecise += Interval;
   ItHal_leaveCriticalSection( );
//   ItHal_TimExtension_Interval[ ItHal_TimExtension_IntervalIndex ++ ] = Interval;
   ItHal_pulseLedRed( );
  }

  inline void clear( )
  {
   _CounterOngoing   = 0;
   _IntervalAdded    = false;
   _IntervalPrecise  = ( _T ) 0;
  }

  inline void isr( )
  {
   if ( BaseClass_t::isr( ) )
   {
//    ItHal_onTestPoint0( );
    if ( _CounterOngoing > 0 )
    {
     BaseClass_t::continueTimer( );
     if ( _CounterOngoing > 0xFFFF )
     {
      BaseClass_t::updateCounterMax( 0xFFFF );
      _CounterOngoing  -= 0xFFFF;
     }
     else
     {
      BaseClass_t::updateCounterMax( _CounterOngoing );
      _CounterOngoing = 0;
     }
//     ItHal_pulseTestPoint1( );
    }
    else
    {
     updateCounterMax( );
     if ( _IntervalAdded )
     {
      BaseClass_t::continueTimer( );
//      ItHal_pulseTestPoint2( );
     }
     else
     {
//      ItHal_pulseTestPoint3( );
     }
    }
//    ItHal_offTestPoint0( );
   }
  }

  inline void start( )
  {
//   ItHal_onTestPoint0( );
//   ItHal_onTestPoint1( );
//   ItHal_onTestPoint2( );
//   ItHal_onTestPoint3( );
//   ItHal_offTestPoint0( );
//   ItHal_offTestPoint1( );
//   ItHal_offTestPoint2( );
//   ItHal_offTestPoint3( );
   updateCounterMax( );
   BaseClass_t::start( );
  }

  inline void stop( )
  {
   BaseClass_t::stop( );
//   ItHal_onTestPoint0( );
//   ItHal_onTestPoint1( );
//   ItHal_onTestPoint2( );
//   ItHal_onTestPoint3( );
//   ItHal_offTestPoint0( );
//   ItHal_offTestPoint1( );
//   ItHal_offTestPoint2( );
//   ItHal_offTestPoint3( );
   clear( );
  }

  inline void updateCounterMax( )
  {
   volatile int32_t Counter  = ( int32_t ) _IntervalPrecise;
   if ( Counter > 0xFFFF )
   {
    _CounterOngoing = Counter - 0xFFFF;
    BaseClass_t::updateCounterMax( 0xFFFF );
   }
   else
   {
    _CounterOngoing = 0;
    if ( Counter < 1 )
    {
     if ( Counter == 0 )
     {
      _IntervalAdded = false;
     }
     Counter = _CounterMinT;
    }
    BaseClass_t::updateCounterMax( Counter );
   }
   _IntervalPrecise -= Counter;
  }

  inline void wait( )
  {
   while ( 1 )
   {
    if ( !_IntervalAdded )
     break;
   }
   ItHal_pulseLedGreen( );
  }

 protected:

  volatile int32_t      _CounterOngoing;
  volatile bool         _IntervalAdded;
  volatile _T           _IntervalPrecise;

};

/// @}

#endif // IT_CONFIG_HAL_TIM

#endif // ItHal_TimExtension_hxx

///////////////////////////////////////////////////////////////////////////////
