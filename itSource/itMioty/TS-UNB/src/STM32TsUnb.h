/* -----------------------------------------------------------------------------

Software License for the Fraunhofer TS-UNB-Lib

(c) Copyright  2019 - 2023 Fraunhofer-Gesellschaft zur Förderung der angewandten
Forschung e.V. All rights reserved.


1. INTRODUCTION

The Fraunhofer Telegram Splitting - Ultra Narrowband Library ("TS-UNB-Lib") is software
that implements only the uplink of the ETSI TS 103 357 TS-UNB standard ("MIOTY") for wireless
data transmission in the field of IoT. Patent licenses for any patent claim regarding the
ETSI TS 103 357 TS-UNB standard implementation (including those of Fraunhofer) may be
obtained through Sisvel International S.A.
(https://www.sisvel.com/licensing-programs/wireless-communications/mioty/license-terms)
or through the respective patent owners individually. The purpose of this TS-UNB-Lib is
academic and non-commercial use. Therefore, Fraunhofer does not offer any support for the
TS-UNB-Lib. Furthermore, the TS-UNB-Lib is NOT identical and on the same quality level as
the commercially-licensed MIOTY software also available from Fraunhofer. Users are encouraged
to check the Fraunhofer website for additional applications information and documentation.


2. COPYRIGHT LICENSE

Redistribution and use in source and binary forms, with or without modification, are
permitted without payment of copyright license fees provided that you satisfy the following
conditions: You must retain the complete text of this software license in redistributions
of the TS-UNB-Lib software or your modifications thereto in source code form. You must retain
the complete text of this software license in the documentation and/or other materials provided
with redistributions of the TS-UNB-Lib software or your modifications thereto in binary form.
You must make available free of charge copies of the complete source code of the TS-UNB-Lib
software and your modifications thereto to recipients of copies in binary form. The name of
Fraunhofer may not be used to endorse or promote products derived from this software without
prior written permission. You may not charge copyright license fees for anyone to use, copy or
distribute the TS-UNB-Lib software or your modifications thereto. Your modified versions of the
TS-UNB-Lib software must carry prominent notices stating that you changed the software and the
date of any change. For modified versions of the TS-UNB-Lib software, the term
"Fraunhofer TS-UNB-Lib" must be replaced by the term
"Third-Party Modified Version of the Fraunhofer TS-UNB-Lib."


3. NO PATENT LICENSE

NO EXPRESS OR IMPLIED LICENSES TO ANY PATENT CLAIMS, including without limitation the patents
of Fraunhofer, ARE GRANTED BY THIS SOFTWARE LICENSE. Fraunhofer provides no warranty of patent
non-infringement with respect to this software. You may use this TS-UNB-Lib software or modifications
thereto only for purposes that are authorized by appropriate patent licenses.


4. DISCLAIMER

This TS-UNB-Lib software is provided by Fraunhofer on behalf of the copyright holders and contributors
"AS IS" and WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, including but not limited to the implied warranties
of merchantability and fitness for a particular purpose. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE for any direct, indirect, incidental, special, exemplary, or consequential damages,
including but not limited to procurement of substitute goods or services; loss of use, data, or profits,
or business interruption, however caused and on any theory of liability, whether in contract, strict
liability, or tort (including negligence), arising in any way out of the use of this software, even if
advised of the possibility of such damage.


5. CONTACT INFORMATION

Fraunhofer Institute for Integrated Circuits IIS
Attention: Division Communication Systems
Am Wolfsmantel 33
91058 Erlangen, Germany
ks-contracts@iis.fraunhofer.de

----------------------------------------------------------------------------- */

/**
 * @brief TS-UNB abstractions for STM32 micro controllers
 *
 * @authors Joerg Robert, Augusto Klotn
 * @authors Modifications made by Paul Adam
 * @file STM32TsUnb.h
 *
 */

#ifndef STM32_TSUNB_H_
#define STM32_TSUNB_H_

#include "ItConfig.h"

#include "../TsUnb/RadioBurst.h"
#include "../TsUnb/FixedMac.h"
#include "../TsUnb/Phy.h"
#include "../TsUnb/SimpleNode.h"

#ifdef IT_CONFIG_STDIO_TRACE
#include "ItStdioTrace.h"
#endif // IT_CONFIG_STDIO_TRACE

#include "../inline/ItHal_Led.hxx"
#include "../inline/ItHal_Spi.hxx"
#ifdef IT_CONFIG_MIOTY_FRAME
#include "../inline/ItMioty_Frame.hxx"
#else // IT_CONFIG_MIOTY_FRAME
#include "../inline/ItHal_TimExtension.hxx"
#endif // IT_CONFIG_MIOTY_FRAME

namespace TsUnbLib {

namespace STM32 {

/**
 * @brief Platform dependent TS-UNB implementation for STM32 based systems.
 *
 * This class implements all platform dependent methods for TS-UNB.
 * It mainly offer SPI communication and a timer to generate the TS-UNB symbol clock.
 *
 * @param SYMBOL_RATE_MULT    TS-UNB, symbol rate in multiples of 49.591064453125, set for 48 for 2380.371sym/s and 8 for 396.729sym/s. For higher rates the clock divider of the timer may have to be adjusted.
 */
template < uint16_t SYMBOL_RATE_MULT = 48 >
class STM32TsUnb
#ifdef IT_CONFIG_MIOTY_FRAME
: protected ItMioty_Frame_t< 2000, 1000 >
#else // IT_CONFIG_MIOTY_FRAME
: protected ItHal_TimExtension_t< float, IT_CONFIG_MIOTY_TIM_BASE, 600 >
#endif // IT_CONFIG_MIOTY_FRAME
{

#ifdef IT_CONFIG_MIOTY_FRAME
 typedef ItMioty_Frame_t< 2000, 1000 > BaseClass_t;
#else // IT_CONFIG_MIOTY_FRAME
 typedef ItHal_TimExtension_t< float, IT_CONFIG_MIOTY_TIM_BASE, 600 > BaseClass_t;
#endif // IT_CONFIG_MIOTY_FRAME

 public:

  STM32TsUnb( )
  {
  }

 /**
  * @brief Bit duration in microseconds
  *
  * This value is the duration of a single TS-UNB symbol, e.g. 1/2380.372s for the normal mode.
  *
  */
  static constexpr double TS_UNB_BIT_DURATION_US = ( ( double ) 1000000.0 / ( ( double ) 49.591064453125 * ( double ) SYMBOL_RATE_MULT ) );


 /**
  * @brief Init the timer
  */
  inline void initTimer( )
  {
//  ItStdio_traceFunctionEnter(          ItStdioTrace_MIOTY );
//  ItStdio_traceValueF32(               ItStdioTrace_MIOTY, "TS_UNB_BIT_DURATION_US", TS_UNB_BIT_DURATION_US );
   BaseClass_t::clear( );
//  ItStdio_traceFunctionLeave(          ItStdioTrace_MIOTY );
  }

  using BaseClass_t::isr;
  using BaseClass_t::isComplete;

#ifdef IT_CONFIG_MIOTY_FRAME
  using BaseClass_t::sendSpi;
#endif // IT_CONFIG_MIOTY_FRAME

 /**
  * @brief Start the timer
  */
  inline void startTimer()
  {
#ifdef IT_CONFIG_MIOTY_FRAME
#else // IT_CONFIG_MIOTY_FRAME
//   ItStdio_traceFunctionEnter(         ItStdioTrace_MIOTY );
   BaseClass_t::start( );
#endif // IT_CONFIG_MIOTY_FRAME
  }

 /**
  * @brief Stop the timer
  */
  inline void stopTimer( )
  {
#ifdef IT_CONFIG_MIOTY_FRAME
//   BaseClass_t::trace(                 ItStdioTrace_MIOTY, "_Frame" );
   bool Return = BaseClass_t::startTim( );
   ItStdio_traceAssertion( Return == true );
#else // IT_CONFIG_MIOTY_FRAME
   BaseClass_t::stop( );
//   ItStdio_traceFunctionLeave(         ItStdioTrace_MIOTY );
#endif // IT_CONFIG_MIOTY_FRAME
  }

 /**
  * @brief Add the counter compare value for the next interrupt
  *
  * @param count Delay in TX symbols
  */
  inline void addTimerDelay( const int32_t Count )
  {
//  ItStdio_traceFunctionEnter(          ItStdioTrace_MIOTY );
//  ItStdio_traceValueI32(               ItStdioTrace_MIOTY, "TimerDelay       ", Count );
//  ItStdio_traceFunctionLeave(          ItStdioTrace_MIOTY );
   if ( Count <= 0 )
    return;
#ifdef IT_CONFIG_MIOTY_FRAME
   bool Return = BaseClass_t::writeSymbolCount( Count );
   ItStdio_traceAssertion( Return == true );
#else // IT_CONFIG_MIOTY_FRAME
   BaseClass_t::addInterval( TS_UNB_BIT_DURATION_US * Count );
#endif // IT_CONFIG_MIOTY_FRAME
  }

 /**
  * @brief Wait until the timer values expires
  */
  inline void waitTimer( )
  {
//   ItStdio_traceFunctionEnter(          ItStdioTrace_MIOTY );
//   ItStdio_traceFunctionLeave(          ItStdioTrace_MIOTY );
#ifdef IT_CONFIG_MIOTY_FRAME
#else // IT_CONFIG_MIOTY_FRAME
   BaseClass_t::wait( );
#endif // IT_CONFIG_MIOTY_FRAME
  }

 /**
  * @brief Initialization of the SPI interface
  */
  inline void spiInit( )
  {
//   ItStdio_traceFunctionEnter(         ItStdioTrace_MIOTY );
//   ItStdio_traceFunctionLeave(         ItStdioTrace_MIOTY );
  }

 /**
  * @brief Deinitialization of the SPI interface
  */
  inline void spiDeinit( )
  {
//   ItStdio_traceFunctionEnter(         ItStdioTrace_MIOTY );
//   ItStdio_traceFunctionLeave(         ItStdioTrace_MIOTY );
  }

 /**
  * @brief Sends multiple bytes using SPI and sets the slave select pin accordingly
  *
  * @param Data Bytes to be transmitted
  * @param Count Number of bytes to be transmitted
  */
  inline void spiSend( const uint8_t* Data, uint8_t Count )
  {
//  ItStdio_traceFunctionEnter(          ItStdioTrace_MIOTY );
//  ItStdio_traceValueU8(                ItStdioTrace_MIOTY, "Count S          ", Count );
//  ItStdio_traceValueU8Array(           ItStdioTrace_MIOTY, "                 ", Data, Count );
//  if ( Count == 4 )
//   ItHal_pulseLedRed( );
#ifdef IT_CONFIG_MIOTY_FRAME
   bool Return = BaseClass_t::writeData( Data, Count );
   ItStdio_traceAssertion( Return == true );
#else // IT_CONFIG_MIOTY_FRAME
   IT_CONFIG_MIOTY_SPI.selectSlave( IT_CONFIG_MIOTY_CS );
   if ( IT_CONFIG_MIOTY_SPI.startTx( Data, Count ) )
    while ( !IT_CONFIG_MIOTY_SPI.isComplete( ) );
//   else
//   {
//    ItStdio_traceBlock( "!spiSend( )" );
//   }
   IT_CONFIG_MIOTY_SPI.unselectSlave( IT_CONFIG_MIOTY_CS );
#endif // IT_CONFIG_MIOTY_FRAME
//   ItStdio_traceFunctionLeave(          ItStdioTrace_MIOTY );
  }

  /**
   * @brief Sends multiple and receives bytes using SPI and sets the slave select pin accordingly
   *
   * This method write and reads the SPI data. Please not that the read data has a delay of one byte.
   * Hence, the first returned byte normally has no meaning.
   *
   * @param Data Bytes to be transmitted and buffer containing the read data
   * @param Count  Number of bytes to be transmitted
   */
  inline void spiSendReceive( uint8_t* Data, uint8_t Count)
  {
//   ItStdio_traceFunctionEnter(          ItStdioTrace_MIOTY );
//   ItStdio_traceValueU8(                ItStdioTrace_MIOTY, "Count SR         ", Count );
//   ItStdio_traceValueU8Array(           ItStdioTrace_MIOTY, "                 ", Data, Count );
   IT_CONFIG_MIOTY_SPI.selectSlave( IT_CONFIG_MIOTY_CS );
   if ( IT_CONFIG_MIOTY_SPI.start( Data, Data, Count ) )
    while ( !IT_CONFIG_MIOTY_SPI.isComplete( ) );
//   else
//   {
//    ItStdio_traceBlock( "!spiSendReceive( )" );
//   }
   IT_CONFIG_MIOTY_SPI.unselectSlave( IT_CONFIG_MIOTY_CS );
//   ItStdio_traceFunctionLeave(          ItStdioTrace_MIOTY );
  }

  /**
   * @brief Reset watchdog (just stub, not implemented)
   *
   */
  inline void resetWatchdog( )
  {
//   ItStdio_traceFunctionEnter(         ItStdioTrace_MIOTY );
//   ItStdio_traceFunctionLeave(         ItStdioTrace_MIOTY );
  };

 protected:

};

}; // namespace STM32

}; // namespace TsUnbLib

#include "STM32TsUnbTemplates.h"

#endif  // STM32_TSUNB_H_
