///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItCallback.h
/// @brief         Header file with API for ItCallback module
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
/// @details       ItCallback is a pointer to a function, which can be stored and called later or periodically.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItCallback_h
#define ItCallback_h

#include "ItStdioTrace.h"

#include <stdbool.h>

/// @addtogroup ItFoundation
/// @{

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          User defined function to process at different time
///
/// @details        This function may be called later and must executes the task.
///
/// @param [in]     CallbackParam      The function parameter as given by user
///
/// @return         true, if processing must continue\n
///                 false, if processing must be abandoned/canceled
///
///////////////////////////////////////////////////////////////////////////////
typedef bool ( *ItCallback_t )( uintptr_t CallbackParam );

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          Structure to store a pointer to callback function and a numeric parameter
///
///////////////////////////////////////////////////////////////////////////////
typedef struct IT_ATTRIBUTE_PACKED
{
 volatile ItCallback_t _Callback;
 uintptr_t             _CallbackParam;

#ifdef __cplusplus

 inline bool callback( )
 {
  return _Callback( _CallbackParam );
 }

 inline void clear( )
 {
  _Callback      = 0;
  _CallbackParam = 0;
 }

 inline bool isOngoing( ) const
 {
//  ItStdio_traceValuePtr( ItStdioTrace_FOUNDATION, "Callback     ", ( uintptr_t ) _Callback );
  return _Callback != 0;
 }

 inline void set( ItCallback_t Callback )
 {
  _Callback = Callback;
 }

 inline void set( ItCallback_t Callback, uintptr_t CallbackParam )
 {
  _Callback      = Callback;
  _CallbackParam = CallbackParam;
 }

 inline void trace( uint32_t Trace )
 {
  ItStdio_traceValuePtr( ItStdioTrace_FOUNDATION, "Callback     ", ( uintptr_t ) _Callback );
  ItStdio_traceValuePtr( ItStdioTrace_FOUNDATION, "CallbackParam", ( uintptr_t ) _CallbackParam );
 }

#endif // __cplusplus

} ItCallbackParam_t;

/// @}

#endif // ItCallback_h

///////////////////////////////////////////////////////////////////////////////
