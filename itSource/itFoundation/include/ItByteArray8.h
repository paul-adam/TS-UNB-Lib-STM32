///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItByteArray8.h
/// @brief         Header file with API for ItByteArray8_t structure
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
///////////////////////////////////////////////////////////////////////////////

#ifndef ItByteArray8_h
#define ItByteArray8_h

#ifdef IT_CONFIG_STDIO_TRACE
#include "ItFormat.h"
#include "ItStdioTrace.h"
#endif // IT_CONFIG_STDIO_TRACE

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// @brief         ItByteArray8_t structure
///
/// @details       ItByteArray8 is a structure representing a 8 bytes sized array. It may be used as base for EUI64.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct IT_ATTRIBUTE_PACKED ItByteArray8_s
{

 union IT_ATTRIBUTE_PACKED
 {
  struct IT_ATTRIBUTE_PACKED
  {
   uint32_t _U32_0;
   uint32_t _U32_1;
  };
  struct IT_ATTRIBUTE_PACKED
  {
   uint16_t _U16_00;
   uint16_t _U16_01;
   uint16_t _U16_02;
   uint16_t _U16_03;
  };
  uint8_t _U8[ 8 ];
  struct IT_ATTRIBUTE_PACKED
  {
   uint8_t _U8_00;
   uint8_t _U8_01;
   uint8_t _U8_02;
   uint8_t _U8_03;
   uint8_t _U8_04;
   uint8_t _U8_05;
   uint8_t _U8_06;
   uint8_t _U8_07;
  };
 };

#ifdef __cplusplus

 inline bool operator==( uint32_t Right ) const
 {
  return    _U32_0 == Right
         && _U32_1 == Right;
 }

 inline bool operator==( const struct ItByteArray8_s& Right ) const
 {
  return    _U32_0 == Right._U32_0
         && _U32_1 == Right._U32_1;
 }

 inline bool operator!=( uint32_t Right ) const
 {
  return    _U32_0 != Right
         || _U32_1 != Right;
 }

 inline bool operator!=( const struct ItByteArray8_s& Right ) const
 {
  return    _U32_0 != Right._U32_0
         || _U32_1 != Right._U32_1;
 }

 inline void clear( )
 {
  _U32_0 = 0;
  _U32_1 = 0;
 }

 inline uint8_t* get( )
 {
  return _U8;
 }

 inline const uint8_t* get( ) const
 {
  return _U8;
 }

 inline uint16_t getId( ) const
 {
  return _U16_02;
 }

 static inline uint32_t getSizeof( )
 {
  return sizeof( _U8 );
 }

 inline bool isCleared( ) const
 {
  return    _U32_0 == 0
         && _U32_1 == 0;
 }

 inline bool isEqual( const uint8_t* Right ) const
 {
  return    _U32_0 == *( ( const uint32_t* ) ( Right                      ) )
         && _U32_1 == *( ( const uint32_t* ) ( Right + sizeof( uint32_t ) ) );
 }

 inline bool isEqual( const ItByteArray8_s& Right ) const
 {
  return    _U32_0 == Right._U32_0
         && _U32_1 == Right._U32_1;
 }

 inline bool isEqualRev( const uint8_t* Right ) const
 {
  return    _U8_00 == Right[ 7 ]
         && _U8_01 == Right[ 6 ]
         && _U8_02 == Right[ 5 ]
         && _U8_03 == Right[ 4 ]
         && _U8_04 == Right[ 3 ]
         && _U8_05 == Right[ 2 ]
         && _U8_06 == Right[ 1 ]
         && _U8_07 == Right[ 0 ];
 }

 inline bool isInvalid( ) const
 {
  return    _U32_0 == 0xFFFFFFFF
         && _U32_1 == 0xFFFFFFFF;
 }

 inline bool isValid( ) const
 {
  return    _U32_0 != 0xFFFFFFFF
         || _U32_1 != 0xFFFFFFFF;
 }

 inline void set( uint8_t U8_00, uint8_t U8_01, uint8_t U8_02, uint8_t U8_03,
                  uint8_t U8_04, uint8_t U8_05, uint8_t U8_06, uint8_t U8_07 )
 {
  _U8_00 = U8_00; _U8_01 = U8_01; _U8_02 = U8_02; _U8_03 = U8_03;
  _U8_04 = U8_04; _U8_05 = U8_05; _U8_06 = U8_06; _U8_07 = U8_07;
 }

 inline void set( uint32_t Source )
 {
  _U32_0 = Source;
  _U32_1 = Source;
 }

 inline void set( const ItByteArray8_s& Right )
 {
  _U32_0 = Right._U32_0;
  _U32_1 = Right._U32_1;
 }

 inline void set( const uint8_t* Source )
 {
  _U32_0 = *( ( const uint32_t* ) ( Source                      ) );
  _U32_1 = *( ( const uint32_t* ) ( Source + sizeof( uint32_t ) ) );
 }

 inline void setId( uint16_t Id )
 {
  _U16_02 = Id;
 }

 inline void setInvalid( )
 {
  _U32_0 = 0xFFFFFFFF;
  _U32_1 = 0xFFFFFFFF;
 }

 inline void setRev( const ItByteArray8_s& Right )
 {
  _U8_00 = Right._U8_07; _U8_01 = Right._U8_06; _U8_02 = Right._U8_05; _U8_03 = Right._U8_04;
  _U8_04 = Right._U8_03; _U8_05 = Right._U8_02; _U8_06 = Right._U8_01; _U8_07 = Right._U8_00;
 }

 inline void trace( uint32_t Trace, const char* Comment ) const
 {
#ifdef IT_CONFIG_STDIO_TRACE
  char S8[ ItFormat_ByteArray8_STRING_SIZE ];
  snprintf( S8, sizeof( S8 ), ItFormat_ByteArray8, _U8_00, _U8_01, _U8_02, _U8_03, _U8_04, _U8_05, _U8_06, _U8_07 );
  ItStdio_traceValueS8( Trace, Comment, S8 );
#endif // IT_CONFIG_STDIO_TRACE
 }

 inline void traceAddressEui( uint32_t Trace, const char* Comment ) const
 {
#ifdef IT_CONFIG_STDIO_TRACE
  char S8[ ItFormat_AddressMac_STRING_SIZE ];
  snprintf( S8, sizeof( S8 ), ItFormat_Eui64, _U8_00, _U8_01, _U8_02, _U8_03, _U8_04, _U8_05, _U8_06, _U8_07 );
  ItStdio_traceValueS8( Trace, Comment, S8 );
#endif // IT_CONFIG_STDIO_TRACE
 }

 inline void traceAddressEuiRev( uint32_t Trace, const char* Comment ) const
 {
#ifdef IT_CONFIG_STDIO_TRACE
  char S8[ ItFormat_AddressMac_STRING_SIZE ];
  snprintf( S8, sizeof( S8 ), ItFormat_Eui64, _U8_07, _U8_06, _U8_05, _U8_04, _U8_03, _U8_02, _U8_01, _U8_00 );
  ItStdio_traceValueS8( Trace, Comment, S8 );
#endif // IT_CONFIG_STDIO_TRACE
 }

#endif // __cplusplus

} IT_ATTRIBUTE_PACKED ItByteArray8_t;

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_getFormatU8( __Source__ )                                                               \
 ( __Source__ )[ 0 ],                                                                                        \
 ( __Source__ )[ 1 ],                                                                                        \
 ( __Source__ )[ 2 ],                                                                                        \
 ( __Source__ )[ 3 ],                                                                                        \
 ( __Source__ )[ 4 ],                                                                                        \
 ( __Source__ )[ 5 ]                                                                                         \
 ( __Source__ )[ 6 ],                                                                                        \
 ( __Source__ )[ 7 ]

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_getFormatU8Rev( __Source__ )                                                            \
 ( __Source__ )[ 7 ],                                                                                        \
 ( __Source__ )[ 6 ],                                                                                        \
 ( __Source__ )[ 5 ],                                                                                        \
 ( __Source__ )[ 4 ],                                                                                        \
 ( __Source__ )[ 3 ],                                                                                        \
 ( __Source__ )[ 2 ],                                                                                        \
 ( __Source__ )[ 1 ],                                                                                        \
 ( __Source__ )[ 0 ]

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_getFormat( __Source__ )                                                                 \
 ( __Source__ )._U8_00,                                                                                      \
 ( __Source__ )._U8_01,                                                                                      \
 ( __Source__ )._U8_02,                                                                                      \
 ( __Source__ )._U8_03,                                                                                      \
 ( __Source__ )._U8_04,                                                                                      \
 ( __Source__ )._U8_05,                                                                                      \
 ( __Source__ )._U8_06,                                                                                      \
 ( __Source__ )._U8_07

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_getFormatRev( __Source__ )                                                              \
 ( __Source__ )._U8_07,                                                                                      \
 ( __Source__ )._U8_06,                                                                                      \
 ( __Source__ )._U8_05,                                                                                      \
 ( __Source__ )._U8_04,                                                                                      \
 ( __Source__ )._U8_03,                                                                                      \
 ( __Source__ )._U8_02,                                                                                      \
 ( __Source__ )._U8_01,                                                                                      \
 ( __Source__ )._U8_00

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_initFromU64( __U64__ )                                                                  \
{                                                                                                            \
 {                                                                                                           \
  {                                                                                                          \
   ._U32_0 = IT_REV32( ( ( uint64_t ) ( __U64__ ) ) >> 32 ),                                                 \
   ._U32_1 = IT_REV32( ( ( uint64_t ) ( __U64__ ) ) ),                                                       \
  },                                                                                                         \
 },                                                                                                          \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_initFromU64Rev( __U64__ )                                                               \
{                                                                                                            \
 {                                                                                                           \
  {                                                                                                          \
   ._U32_0 = ( uint32_t ) ( __U64__ ),                                                                       \
   ._U32_1 = ( uint32_t ) ( ( ( uint64_t ) __U64__ ) >> 32 ),                                                \
  },                                                                                                         \
 },                                                                                                          \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_initFromU8( __U8_00__, __U8_01__, __U8_02__, __U8_03__, __U8_04__, __U8_05__, __U8_06__, __U8_07__ ) \
{                                                                                                            \
 ._U8 = {                                                                                                    \
         ( uint8_t ) ( __U8_00__ ),                                                                          \
         ( uint8_t ) ( __U8_01__ ),                                                                          \
         ( uint8_t ) ( __U8_02__ ),                                                                          \
         ( uint8_t ) ( __U8_03__ ),                                                                          \
         ( uint8_t ) ( __U8_04__ ),                                                                          \
         ( uint8_t ) ( __U8_05__ ),                                                                          \
         ( uint8_t ) ( __U8_06__ ),                                                                          \
         ( uint8_t ) ( __U8_07__ ),                                                                          \
 },                                                                                                          \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_initFromU8Rev( __U8_00__, __U8_01__, __U8_02__, __U8_03__, __U8_04__, __U8_05__, __U8_06__, __U8_07__ ) \
{                                                                                                            \
 ._U8 = {                                                                                                    \
         ( uint8_t ) ( __U8_07__ ),                                                                          \
         ( uint8_t ) ( __U8_06__ ),                                                                          \
         ( uint8_t ) ( __U8_05__ ),                                                                          \
         ( uint8_t ) ( __U8_04__ ),                                                                          \
         ( uint8_t ) ( __U8_03__ ),                                                                          \
         ( uint8_t ) ( __U8_02__ ),                                                                          \
         ( uint8_t ) ( __U8_01__ ),                                                                          \
         ( uint8_t ) ( __U8_00__ ),                                                                          \
 },                                                                                                          \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_isEqual( __Left__, __Right__ )                                                          \
(                                                                                                            \
    ( ( __Left__ )._U8_00 == ( __Right__ )._U8_00 )                                                          \
 && ( ( __Left__ )._U8_01 == ( __Right__ )._U8_01 )                                                          \
 && ( ( __Left__ )._U8_02 == ( __Right__ )._U8_02 )                                                          \
 && ( ( __Left__ )._U8_03 == ( __Right__ )._U8_03 )                                                          \
 && ( ( __Left__ )._U8_04 == ( __Right__ )._U8_04 )                                                          \
 && ( ( __Left__ )._U8_05 == ( __Right__ )._U8_05 )                                                          \
 && ( ( __Left__ )._U8_06 == ( __Right__ )._U8_06 )                                                          \
 && ( ( __Left__ )._U8_07 == ( __Right__ )._U8_07 )                                                          \
)

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_isEqualRev( __Left__, __Right__ )                                                       \
(                                                                                                            \
    ( ( __Left__ )._U8_00 == ( __Right__ )._U8_07 )                                                          \
 && ( ( __Left__ )._U8_01 == ( __Right__ )._U8_06 )                                                          \
 && ( ( __Left__ )._U8_02 == ( __Right__ )._U8_05 )                                                          \
 && ( ( __Left__ )._U8_03 == ( __Right__ )._U8_04 )                                                          \
 && ( ( __Left__ )._U8_04 == ( __Right__ )._U8_03 )                                                          \
 && ( ( __Left__ )._U8_05 == ( __Right__ )._U8_02 )                                                          \
 && ( ( __Left__ )._U8_06 == ( __Right__ )._U8_01 )                                                          \
 && ( ( __Left__ )._U8_07 == ( __Right__ )._U8_00 )                                                          \
)

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_isEqualU8( __Left__, __Right__ )                                                        \
(                                                                                                            \
    ( ( __Left__ )._U8_00 == ( __Right__ )[ 0 ] )                                                            \
 && ( ( __Left__ )._U8_01 == ( __Right__ )[ 1 ] )                                                            \
 && ( ( __Left__ )._U8_02 == ( __Right__ )[ 2 ] )                                                            \
 && ( ( __Left__ )._U8_03 == ( __Right__ )[ 3 ] )                                                            \
 && ( ( __Left__ )._U8_04 == ( __Right__ )[ 4 ] )                                                            \
 && ( ( __Left__ )._U8_05 == ( __Right__ )[ 5 ] )                                                            \
 && ( ( __Left__ )._U8_06 == ( __Right__ )[ 6 ] )                                                            \
 && ( ( __Left__ )._U8_07 == ( __Right__ )[ 7 ] )                                                            \
)

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_isEqualU8Rev( __Left__, __Right__ )                                                     \
(                                                                                                            \
    ( ( __Left__ )._U8_00 == ( __Right__ )[ 7 ] )                                                            \
 && ( ( __Left__ )._U8_01 == ( __Right__ )[ 6 ] )                                                            \
 && ( ( __Left__ )._U8_02 == ( __Right__ )[ 5 ] )                                                            \
 && ( ( __Left__ )._U8_03 == ( __Right__ )[ 4 ] )                                                            \
 && ( ( __Left__ )._U8_04 == ( __Right__ )[ 3 ] )                                                            \
 && ( ( __Left__ )._U8_05 == ( __Right__ )[ 2 ] )                                                            \
 && ( ( __Left__ )._U8_06 == ( __Right__ )[ 1 ] )                                                            \
 && ( ( __Left__ )._U8_07 == ( __Right__ )[ 0 ] )                                                            \
)

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_set( __Dest__, __Source__ )                                                             \
{                                                                                                            \
 ( __Dest__ )._U32_0 = ( __Source__ )._U32_0;                                                                \
 ( __Dest__ )._U32_1 = ( __Source__ )._U32_1;                                                                \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_setRev( __Dest__, __Source__ )                                                          \
{                                                                                                            \
 ( __Dest__ )._U8_00 = ( __Source__ )._U8_07;                                                                \
 ( __Dest__ )._U8_01 = ( __Source__ )._U8_06;                                                                \
 ( __Dest__ )._U8_02 = ( __Source__ )._U8_05;                                                                \
 ( __Dest__ )._U8_03 = ( __Source__ )._U8_04;                                                                \
 ( __Dest__ )._U8_04 = ( __Source__ )._U8_03;                                                                \
 ( __Dest__ )._U8_05 = ( __Source__ )._U8_02;                                                                \
 ( __Dest__ )._U8_06 = ( __Source__ )._U8_01;                                                                \
 ( __Dest__ )._U8_07 = ( __Source__ )._U8_00;                                                                \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_setFromS8( __Dest__, __Source__ )                                                       \
{                                                                                                            \
 ( __Dest__ )._U8_00 = ItS8_toU8( ( __Source__ )      );                                                     \
 ( __Dest__ )._U8_01 = ItS8_toU8( ( __Source__ ) +  2 );                                                     \
 ( __Dest__ )._U8_02 = ItS8_toU8( ( __Source__ ) +  4 );                                                     \
 ( __Dest__ )._U8_03 = ItS8_toU8( ( __Source__ ) +  6 );                                                     \
 ( __Dest__ )._U8_04 = ItS8_toU8( ( __Source__ ) +  8 );                                                     \
 ( __Dest__ )._U8_05 = ItS8_toU8( ( __Source__ ) + 10 );                                                     \
 ( __Dest__ )._U8_06 = ItS8_toU8( ( __Source__ ) + 12 );                                                     \
 ( __Dest__ )._U8_07 = ItS8_toU8( ( __Source__ ) + 14 );                                                     \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_setFromU8( __Dest__, __Source__ )                                                       \
{                                                                                                            \
 ( __Dest__ )._U32_0 = *( ( const uint32_t* )   ( ( const uint8_t* ) __Source__ )                        );  \
 ( __Dest__ )._U32_1 = *( ( const uint32_t* ) ( ( ( const uint8_t* ) __Source__ ) + sizeof( uint32_t ) ) );  \
}

///////////////////////////////////////////////////////////////////////////////
#define ItByteArray8_setFromU8Rev( __Dest__, __Source__ )                                                    \
{                                                                                                            \
 ( __Dest__ )._U8_00 = ( __Source__ )[ 7 ];                                                                  \
 ( __Dest__ )._U8_01 = ( __Source__ )[ 6 ];                                                                  \
 ( __Dest__ )._U8_02 = ( __Source__ )[ 5 ];                                                                  \
 ( __Dest__ )._U8_03 = ( __Source__ )[ 4 ];                                                                  \
 ( __Dest__ )._U8_04 = ( __Source__ )[ 3 ];                                                                  \
 ( __Dest__ )._U8_05 = ( __Source__ )[ 2 ];                                                                  \
 ( __Dest__ )._U8_06 = ( __Source__ )[ 1 ];                                                                  \
 ( __Dest__ )._U8_07 = ( __Source__ )[ 0 ];                                                                  \
}

#ifdef __cplusplus
}
#endif

#endif // ItByteArray8_h

///////////////////////////////////////////////////////////////////////////////
