///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItStdioTrace.h
/// @brief         Header file with API for ItStdio module
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
/// @details       This file contains tracing means.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItStdioTrace_h
#define ItStdioTrace_h

#include "ItConfig.h"

#ifdef ARM_MATH_CM4
#include "arm_math.h"
#endif // ARM_MATH_CM4

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// @addtogroup ItStdio
/// @{

#ifdef __cplusplus
extern "C" {
#endif

#define ItStdioTrace_BAUDRATE                              115200

#define ItStdioTrace_NONE                                  0x00000000          ///< Switch off traces on all components
#define ItStdioTrace_BLE                                   0x00000001          ///< Switch on traces on BLE
#define ItStdioTrace_BLE_EVENT                             0x00000002          ///< Switch on traces on BLE ( events only )
#define ItStdioTrace_COMM                                  0x00000004
#define ItStdioTrace_COMPONENT                             0x00000008
#define ItStdioTrace_CRYPTO                                0x00000010          ///< Switch on traces on Crypto
#define ItStdioTrace_DDN                                   0x00000020          ///< Switch on traces on DDN
#define ItStdioTrace_DDN_OTA                               0x00000040          ///< Switch on traces on DDN
#define ItStdioTrace_DIAGNOSIS                             0x00000080
#define ItStdioTrace_ETH                                   0x00000100
#define ItStdioTrace_FLIGHT                                0x00000200
#define ItStdioTrace_FOUNDATION                            0x00000400
#define ItStdioTrace_FUNCTION                              0x00000800
#define ItStdioTrace_HAL                                   0x00001000
#define ItStdioTrace_IMAGE                                 0x00002000
#define ItStdioTrace_ITSS                                  0x00004000
#define ItStdioTrace_LIST                                  0x00008000
#define ItStdioTrace_MATH                                  0x00010000
#define ItStdioTrace_MEMORY                                0x00020000
#define ItStdioTrace_MIOTY                                 0x00040000
#define ItStdioTrace_MOTOR                                 0x00080000
#define ItStdioTrace_NET                                   0x00100000
#define ItStdioTrace_NET_EVENT                             0x00200000
#define ItStdioTrace_NVM                                   0x00800000
#define ItStdioTrace_NVM_FLASH                             0x01000000
#define ItStdioTrace_NVM_POOL                              0x02000000          ///< Switch on traces on NvmPool
#define ItStdioTrace_OPENCV                                0x04000000          ///< Switch on traces on openCV
#define ItStdioTrace_STDIO                                 0x08000000          ///< Switch on traces on STDIO
#define ItStdioTrace_TEST                                  0x10000000          ///< Switch on traces on test functions
#define ItStdioTrace_TP                                    0x20000000          ///< Switch on traces on test platform
#define ItStdioTrace_USB                                   0x40000000          ///< Switch on traces on USB
#define ItStdioTrace_JSON                                  0x80000000          ///< Switch on traces for JSON
#define ItStdioTrace_ALL                                   0xFFFFFFFF          ///< Applies to any component

#ifdef IT_CONFIG_STDIO_TRACE

/// @brief Decrement indent of traces
void ItStdio_decrementTraceIndent( uint32_t Trace );

/// @brief Get status of the traces
uint32_t ItStdio_getTrace( );

/// @brief Increment indent of traces
void ItStdio_incrementTraceIndent( uint32_t Trace );

/// @brief This function restores the status of the traces
#define ItStdio_restoreTrace( ) ItStdio_setTrace( ItStdio_TraceLocal )

#endif // IT_CONFIG_STDIO_TRACE

void ItStdio_resumeTrace( void );

#ifdef IT_CONFIG_STDIO_TRACE

/// @brief This function sets the status of the traces
uint32_t ItStdio_setTrace( uint32_t Trace );

/// @brief Switch traces off for feature
void ItStdio_setTraceOff( uint32_t Trace );

/// @brief Switch traces on for feature
void ItStdio_setTraceOn( uint32_t Trace );

/// @brief Switch traces on for feature with condition
void ItStdio_setTraceOnWithCondition( uint32_t Trace, uint32_t ConditionalTrace );

bool ItStdio_setTraceTimestampEnabled( bool TimestampEnabled );

/// @brief Store status of the traces
#define ItStdio_storeTrace( ) uint32_t ItStdio_TraceLocal = ItStdio_getTrace( )

void ItStdio_trace( uint32_t Trace, const char* Format, ... );

/// @brief Assert condition
void ItStdio_traceAssertion_( bool Condition, const char* ConditionText );
#define ItStdio_traceAssertion( __Condition__ ) ItStdio_traceAssertion_( __Condition__, #__Condition__ )

/// @brief Display text and block
void ItStdio_traceBlock( const char* Text );

/// @brief Print one single character
void ItStdio_traceChar( uint32_t Trace, char Char, uint32_t Count );

/// @brief Print comment
void ItStdio_traceComment(          uint32_t Trace, const char* Comment );
void ItStdio_traceCommentTimestamp( uint32_t Trace, const char* Comment );

#ifdef IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print start/initialization of function
void ItStdio_traceErrorFunctionEnter_( uint32_t Trace, const char* FunctionName );
#define ItStdio_traceErrorFunctionEnter( __Trace__ )                      ItStdio_traceErrorFunctionEnter_( __Trace__, __func__ )

/// @brief Print exit of/leaving function
void ItStdio_traceErrorFunctionLeave_( uint32_t Trace, const char* FunctionName );
#define ItStdio_traceErrorFunctionLeave( __Trace__ )                      ItStdio_traceErrorFunctionLeave_( __Trace__, __func__ )

/// @brief Print exit of/leaving function with additional text
void ItStdio_traceErrorFunctionLeaveWithText_( uint32_t Trace, const char* FunctionName, const char* Text );
#define ItStdio_traceErrorFunctionLeaveWithText( __Trace__, __Text__ )    ItStdio_traceErrorFunctionLeaveWithText_( __Trace__, __func__, __Text__ )

#else // IT_CONFIG_STDIO_TEXT_COLOR

#define ItStdio_traceErrorFunctionEnter( __Trace__ )                      ItStdio_traceFunctionEnter_( __Trace__, __func__ )
#define ItStdio_traceErrorFunctionEnterHighlight( __Trace__ )             ItStdio_traceFunctionEnterHighlight_( __Trace__, __func__ )
#define ItStdio_traceErrorFunctionLeave( __Trace__ )                      ItStdio_traceFunctionLeave_( __Trace__, __func__ )
#define ItStdio_traceErrorFunctionLeaveWithText( __Trace__, __Text__ )    ItStdio_traceFunctionLeaveWithText_( __Trace__, __func__, __Text__ )

#endif // IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print start/initialization of function
void ItStdio_traceFunctionEnter_( uint32_t Trace, const char* FunctionName );
#define ItStdio_traceFunctionEnter( __Trace__ )                           ItStdio_traceFunctionEnter_( __Trace__, __func__ )

void ItStdio_traceFunctionEnterHighlight_( uint32_t Trace, const char* FunctionName );
#define ItStdio_traceFunctionEnterHighlight( __Trace__ )                  ItStdio_traceFunctionEnterHighlight_( __Trace__, __func__ )

/// @brief Print exit of/leaving function
void ItStdio_traceFunctionLeave_( uint32_t Trace, const char* FunctionName );
#define ItStdio_traceFunctionLeave( __Trace__ )                           ItStdio_traceFunctionLeave_( __Trace__, __func__ )

#ifdef IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print exit of/leaving function with additional text
void ItStdio_traceFunctionLeaveWithError_( uint32_t Trace, const char* FunctionName, const char* Text );
#define ItStdio_traceFunctionLeaveWithError( __Trace__, __Text__ )        ItStdio_traceFunctionLeaveWithError_( __Trace__, __func__, __Text__ )

#else // IT_CONFIG_STDIO_TEXT_COLOR

#define ItStdio_traceFunctionLeaveWithError( __Trace__, __Text__ ) ItStdio_traceFunctionLeaveWithText_( __Trace__, __func__, __Text__ )

#endif // IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print exit of/leaving function with additional text
void ItStdio_traceFunctionLeaveWithText_( uint32_t Trace, const char* FunctionName, const char* Text );
#define ItStdio_traceFunctionLeaveWithText( __Trace__, __Text__ )         ItStdio_traceFunctionLeaveWithText_( __Trace__, __func__, __Text__ )

void ItStdio_traceIndex( uint32_t Trace, uint32_t Index );

/// @brief Print start/initialization of class method
#define ItStdio_traceMethodEnter( __Trace__ )                             ItStdio_traceFunctionEnter_( __Trace__, __PRETTY_FUNCTION__ )

/// @brief Print start/initialization of class method
#define ItStdio_traceMethodEnterHighlight( __Trace__ )                    ItStdio_traceFunctionEnterHighlight_( __Trace__, __PRETTY_FUNCTION__ )

/// @brief Print exit of/leaving class method
#define ItStdio_traceMethodLeave( __Trace__ )                             ItStdio_traceFunctionLeave_( __Trace__, __PRETTY_FUNCTION__ )

#ifdef IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print exit of/leaving class method with additional text
#define ItStdio_traceMethodLeaveWithError( __Trace__, __Text__ )          ItStdio_traceFunctionLeaveWithError_( __Trace__, __PRETTY_FUNCTION__, __Text__ )

#else // IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print exit of/leaving class method with additional text
#define ItStdio_traceMethodLeaveWithError( __Trace__, __Text__ ) ItStdio_traceFunctionLeaveWithText_( __Trace__, __PRETTY_FUNCTION__, __Text__ )

#endif // IT_CONFIG_STDIO_TEXT_COLOR

/// @brief Print exit of/leaving class method with additional text
#define ItStdio_traceMethodLeaveWithText( __Trace__, __Text__ )           ItStdio_traceFunctionLeaveWithText_( __Trace__, __PRETTY_FUNCTION__, __Text__ )

/// @brief Print new line
#define ItStdio_traceNewLine( __Trace__, __Count__ )                      ItStdio_traceChar( __Trace__, '\n', __Count__ )

#ifdef IT_CONFIG_BLE

void ItStdio_traceValueBleAciEvent(        uint32_t Trace, const char* Comment, uint16_t    Value );
void ItStdio_traceValueBleAddressType(     uint32_t Trace, const char* Comment, uint8_t     Value );
void ItStdio_traceValueBleAdvertisingType( uint32_t Trace, const char* Comment, uint8_t     Value );
void ItStdio_traceValueBleHciEvent(        uint32_t Trace, const char* Comment, uint8_t     Value );
void ItStdio_traceValueBleHciSubEvent(     uint32_t Trace, const char* Comment, uint8_t     Value );
void ItStdio_traceValueBleProcedureCode(   uint32_t Trace, const char* Comment, uint8_t     Value );
void ItStdio_traceValueBleStatus(          uint32_t Trace, const char* Comment, uint8_t     Value );

#else // IT_CONFIG_BLE

#define ItStdio_traceValueBleAciEvent( ... )               { }
#define ItStdio_traceValueBleAddressType( ... )            { }
#define ItStdio_traceValueBleAdvertisingType( ... )        { }
#define ItStdio_traceValueBleHciEvent( ... )               { }
#define ItStdio_traceValueBleHciSubEvent( ... )            { }
#define ItStdio_traceValueBleProcedureCode( ... )          { }
#define ItStdio_traceValueBleStatus( ... )                 { }

#endif // IT_CONFIG_BLE

#ifdef IT_CONFIG_BLE_CLIENT

void ItStdio_traceValueBleScanningReport( uint32_t Trace, const char* Comment, const void* Value );

#else // IT_CONFIG_BLE_CLIENT

#define ItStdio_traceValueBleScanningReport( ... )         { }

#endif // IT_CONFIG_BLE_CLIENT

void ItStdio_traceValueBool( uint32_t Trace, const char* Comment, uint32_t Value );

/// @brief Trace first "Size" boolean values of array
void ItStdio_traceValueBoolArray( uint32_t Trace, const char* Comment, const bool* Value, uint32_t Size );

#ifdef IT_CONFIG_DDN_IMG
void ItStdio_traceValueDdnDeviceInfo(      uint32_t Trace, const char* Comment, const void* Value );
#else // IT_CONFIG_DDN_IMG
#define ItStdio_traceValueDdnDeviceInfo( ... )             { }
#endif // IT_CONFIG_DDN_IMG

/// @brief Trace value of float
void ItStdio_traceValueF32( uint32_t Trace, const char* Comment, float Value );

/// @brief Trace first "Size" float values of array
void ItStdio_traceValueF32Array(         uint32_t Trace, const char* Comment, const float* Value, uint32_t Size );
void ItStdio_traceValueF32ArrayVertical( uint32_t Trace, const char* Comment, const float* Value, uint32_t Size );

/// @brief Trace hex value of int16_t
void ItStdio_traceValueI16( uint32_t Trace, const char* Comment, int16_t Value );

/// @brief Trace hex value of int32_t
void ItStdio_traceValueI32( uint32_t Trace, const char* Comment, int32_t Value );

/// @brief Trace hex value of int64_t
void ItStdio_traceValueI64( uint32_t Trace, const char* Comment, int64_t Value );

/// @brief Trace hex value of int8_t
void ItStdio_traceValueI8( uint32_t Trace, const char* Comment, int8_t Value );

#ifdef IT_CONFIG_MATH_
/// @brief Trace values of matrix
void ItStdio_traceValueMatrixBool( uint32_t Trace, const char* TextBegin, const char* TextEnd, const void* Value );
void ItStdio_traceValueMatrixF32(  uint32_t Trace, const char* TextBegin, const char* TextEnd, const void* Value );
void ItStdio_traceValueMatrixQ31(  uint32_t Trace, const char* TextBegin, const char* TextEnd, const void* Value );
void ItStdio_traceValueNeuronalNetF32( uint32_t Trace, const char* TextBegin, const char* TextEnd, const void* Value );
#else // IT_CONFIG_MATH_
#define ItStdio_traceValueMatrixBool( ... )                { }
#define ItStdio_traceValueMatrixF32( ... )                 { }
#define ItStdio_traceValueMatrixQ31( ... )                 { }
#define ItStdio_traceValueNeuronalNetF32( ... )            { }
#endif // IT_CONFIG_MATH_

/// @brief Trace hex value of uintptr_t
void ItStdio_traceValuePtr( uint32_t Trace, const char* Comment, uintptr_t Value );

#ifdef ARM_MATH_CM4

/// @brief Trace value of float
void ItStdio_traceValueQ15( uint32_t Trace, const char* Comment, q15_t Value );

#endif // ARM_MATH_CM4

#ifdef IT_CONFIG_HAL_RESET
void ItStdio_traceValueResetReason( uint32_t Trace, const char* Comment, uint32_t Value );
#else // IT_CONFIG_HAL_RESET
#define ItStdio_traceValueResetReason( ... )               { }
#endif // IT_CONFIG_HAL_RESET

/// @brief Trace text
void ItStdio_traceValueS8( uint32_t Trace, const char* Comment, const char* Value );

/// @brief Trace hex value of uint16_t
void ItStdio_traceValueU16( uint32_t Trace, const char* Comment, uint16_t Value );

/// @brief Trace hex value of uint32_t
void ItStdio_traceValueU32( uint32_t Trace, const char* Comment, uint32_t Value );

/// @brief Trace hex value of uint64_t
void ItStdio_traceValueU64( uint32_t Trace, const char* Comment, uint64_t Value );

/// @brief Trace hex value of uint8_t
void ItStdio_traceValueU8( uint32_t Trace, const char* Comment, uint8_t Value );

/// @brief Trace first "Size" hex values of array
void ItStdio_traceValueU8Array( uint32_t Trace, const char* Comment, const uint8_t* Value, uint32_t Size );

void ItStdio_traceWaitEndOfTx( );

#else // IT_CONFIG_STDIO_TRACE

#define ItStdio_decrementTraceIndent( ... )                          { }
static inline bool ItStdio_setTraceTimestampEnabled( bool )          { return 0; }
#define ItStdio_getTrace( ... )                                      0
#define ItStdio_incrementTraceIndent( ... )                          { }
#define ItStdio_restoreTrace( ... )                                  { }
#define ItStdio_setTrace( ... )                                      { }
#define ItStdio_setTraceOff( ... )                                   { }
#define ItStdio_setTraceOn( ... )                                    { }
#define ItStdio_setTraceOnWithCondition( ... )                       { }
#define ItStdio_storeTrace( ... )                                    { }

#define ItStdio_trace( ... )                                         { }
static inline void ItStdio_traceAssertion( bool )                    { }
#define ItStdio_traceBlock( ... )                                    { }
#define ItStdio_traceChar( ... )                                     { }
#define ItStdio_traceComment( ... )                                  { }
#define ItStdio_traceCommentTimestamp( ... )                         { }

#define ItStdio_traceErrorFunctionEnter( ... )                       { }
#define ItStdio_traceErrorFunctionLeave( ... )                       { }
#define ItStdio_traceErrorFunctionLeaveWithError( ... )              { }
#define ItStdio_traceErrorFunctionLeaveWithText( ... )               { }
#define ItStdio_traceFunctionEnter( ... )                            { }
#define ItStdio_traceFunctionEnterHighlight( ... )                   { }
#define ItStdio_traceFunctionLeave( ... )                            { }
#define ItStdio_traceFunctionLeaveWithError( ... )                   { }
#define ItStdio_traceFunctionLeaveWithText( ... )                    { }
#define ItStdio_traceIndex(   ... )                                  { }
#define ItStdio_traceMethodEnter( ... )                              { }
#define ItStdio_traceMethodEnterHighlight( ... )                     { }
#define ItStdio_traceMethodLeave( ... )                              { }
#define ItStdio_traceMethodLeaveWithError( ... )                     { }
#define ItStdio_traceMethodLeaveWithText( ... )                      { }

#define ItStdio_traceNewLine( ... )                                  { }

#define ItStdio_traceValueBleAciEvent( ... )                         { }
#define ItStdio_traceValueBleAddressType( ... )                      { }
#define ItStdio_traceValueBleAdvertisingReport( ... )                { }
#define ItStdio_traceValueBleAdvertisingType( ... )                  { }
#define ItStdio_traceValueBleHciEvent( ... )                         { }
#define ItStdio_traceValueBleHciSubEvent( ... )                      { }
#define ItStdio_traceValueBleProcedureCode( ... )                    { }
#define ItStdio_traceValueBleStatus( ... )                           { }
#define ItStdio_traceValueBool( ... )                                { }
#define ItStdio_traceValueBoolArray( ... )                           { }
#define ItStdio_traceValueDdnDeviceInfo( ... )                       { }
#define ItStdio_traceValueF32( ... )                                 { }
#define ItStdio_traceValueF32Array( ... )                            { }
#define ItStdio_traceValueF32ArrayVertical( ... )                    { }
#define ItStdio_traceValueI16( ... )                                 { }
#define ItStdio_traceValueI32( ... )                                 { }
#define ItStdio_traceValueI64( ... )                                 { }
#define ItStdio_traceValueI8( ... )                                  { }
#define ItStdio_traceValueMatrixBool( ... )                          { }
#define ItStdio_traceValueMatrixF32( ... )                           { }
#define ItStdio_traceValueMatrixQ31( ... )                           { }
#define ItStdio_traceValueNetService( ... )                          { }
#define ItStdio_traceValueNeuronalNetF32( ... )                      { }
#define ItStdio_traceValuePtr( ... )                                 { }
#define ItStdio_traceValueQ15( ... )                                 { }
#define ItStdio_traceValueResetReason( ... )                         { }
#define ItStdio_traceValueS8( ... )                                  { }
#define ItStdio_traceValueU16( ... )                                 { }
#define ItStdio_traceValueU32( ... )                                 { }
#define ItStdio_traceValueU64( ... )                                 { }
#define ItStdio_traceValueU8( ... )                                  { }
#define ItStdio_traceValueU8Array( ... )                             { }
#define ItStdio_traceWaitEndOfTx( ... )                              { }

#endif // IT_CONFIG_STDIO_TRACE

#ifdef __cplusplus
}
#endif

/// @}

#endif // ItStdioTrace_h

///////////////////////////////////////////////////////////////////////////////
