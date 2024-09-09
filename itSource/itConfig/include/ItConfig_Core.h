///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItConfig_Core.h
/// @brief         Header file with defines for the MCU core and tool chain
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

#ifndef ItConfig_Core_h
#define ItConfig_Core_h

#include <stdint.h>

/// @addtogroup ItConfig
/// @{

#if defined( __GNUC__ )

#define IT_ATTRIBUTE_ALIGNED( _Aligned__ )                           __attribute__ ( ( aligned( _Aligned__ ) ) )
#define IT_ATTRIBUTE_ALIGNED_U32                                     __attribute__ ( ( aligned( 4 ) ) )
#define IT_ATTRIBUTE_ALIGNED_U64                                     __attribute__ ( ( aligned( 8 ) ) )
#define IT_ATTRIBUTE_NORETURN                                        __attribute__ ( ( noreturn ) )
#define IT_ATTRIBUTE_PACKED                                          __attribute__ ( ( __packed__ ) )
#define IT_ATTRIBUTE_PACKED_ALIGNED( _Aligned__ )                    __attribute__ ( ( __packed__ , aligned( _Aligned__ ) ) )
#define IT_ATTRIBUTE_PACKED_ALIGNED_U32                              __attribute__ ( ( __packed__ , aligned( 4 ) ) )
#define IT_ATTRIBUTE_PACKED_ALIGNED_U64                              __attribute__ ( ( __packed__ , aligned( 8 ) ) )
#define IT_ATTRIBUTE_SECTION( _SectionName_ )                        __attribute__ ( ( section( _SectionName_ ) ) )
#define IT_ATTRIBUTE_SECTION_ALIGNED( _SectionName_, _Aligned__ )    __attribute__ ( ( section( _SectionName_ ), aligned( _Aligned__ ) ) )

#ifdef IT_CONFIG_TARGET_STM32

#define IT_ATTRIBUTE_SECTION_USED( _SectionName_ )                   __attribute__ ( ( section( _SectionName_ ), used ) )

#else // IT_CONFIG_TARGET_STM32

#define IT_ATTRIBUTE_SECTION_USED( _SectionName_ )

#endif // IT_CONFIG_TARGET_STM32

#define IT_ATTRIBUTE_SECTION_WEAK( _SectionName_ )                   __attribute__ ( ( section( _SectionName_ ), weak ) )
#define IT_ATTRIBUTE_UNUSED                                          __attribute__ ( ( unused ) )
#define IT_ATTRIBUTE_WEAK                                            __attribute__ ( ( weak ) )
#define IT_ATTRIBUTE_WEAK_ALIAS( _AliasName_ )                       __attribute__ ( ( weak, alias( _AliasName_ ) ) )

#else // defined ( __GNUC__ )

#define IT_ATTRIBUTE_ALIGNED
#define IT_ATTRIBUTE_NORETURN
#define IT_ATTRIBUTE_PACKED
#define IT_ATTRIBUTE_SECTION( _SectionName_ )
#define IT_ATTRIBUTE_SECTION_ALIGNED( _SectionName_, _Aligned__ )
#define IT_ATTRIBUTE_PACKED_ALIGNED_U32
#define IT_ATTRIBUTE_SECTION_USED( _SectionName_ )
#define IT_ATTRIBUTE_UNUSED
#define IT_ATTRIBUTE_WEAK                                            __attribute__ ( ( weak ) )
#define IT_ATTRIBUTE_WEAK_ALIAS( _AliasName_ )

#endif // defined ( __GNUC__ )

#ifdef IT_CONFIG_TARGET_ARM_CM

#include "main.h"

#define IT_REV16( __VALUE__ )                                        ( ( uint16_t ) __REV16( ( uint32_t ) ( __VALUE__ ) ) )

#define IT_REV32( __VALUE__ )                                        ( ( uint32_t ) __REV(   ( uint32_t ) ( __VALUE__ ) ) )

#else // IT_CONFIG_TARGET_ARM_CM

#if defined( __GNUC__ )

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          Swap bytes of 16 bit value
///
///////////////////////////////////////////////////////////////////////////////
#define IT_REV16( __VALUE__ )                                        ( __builtin_bswap16( ( uint16_t ) ( __VALUE__ ) ) )

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          Swap bytes of 32 bit value
///
///////////////////////////////////////////////////////////////////////////////
#define IT_REV32( __VALUE__ )                                        ( __builtin_bswap32( ( uint32_t ) ( __VALUE__ ) ) )

#else // defined ( __GNUC__ )

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          Swap bytes of 16 bit value
///
///////////////////////////////////////////////////////////////////////////////
#define IT_REV16( __VALUE__ )                                        ( ( ( ( uint16_t ) ( __VALUE__ ) & 0xFF00 ) >> 8 ) |        \
                                                                       ( ( ( uint16_t ) ( __VALUE__ ) & 0x00FF ) << 8 ) )

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          Swap bytes of 32 bit value
///
///////////////////////////////////////////////////////////////////////////////
#define IT_REV32( __VALUE__ )                                        ( ( ( ( uint32_t ) ( __VALUE__ ) & 0xFF000000 ) >> 24 ) |   \
                                                                       ( ( ( uint32_t ) ( __VALUE__ ) & 0x00FF0000 ) >>  8 ) |   \
                                                                       ( ( ( uint32_t ) ( __VALUE__ ) & 0x0000FF00 ) <<  8 ) |   \
                                                                       ( ( ( uint32_t ) ( __VALUE__ ) & 0x000000FF ) << 24 ) )

#endif // defined ( __GNUC__ )

#endif // IT_CONFIG_TARGET_ARM_CM

///////////////////////////////////////////////////////////////////////////////
///
/// @brief          Comparison between two float values
///
/// @details        This macro function may be called to compare two float values. The two values are said to be equal, if the difference is less than 0.0000001.
///
/// @param [in]     __LEFT__           The first value to compare
/// @param [in]     __RIGHT__          The second value to compare
///
/// @return         true, if the difference of both values is less than 0.0000001\n
///                 false else
///
///////////////////////////////////////////////////////////////////////////////
#define IT_FLOAT_IS_EQUAL( __LEFT__, __RIGHT__ )                     (   ( float ) ( __LEFT__  ) > ( float ) ( __RIGHT__ )               \
                                                                       ? ( float ) ( __LEFT__  ) - ( float ) ( __RIGHT__ ) < 0.0000001   \
                                                                       : ( float ) ( __RIGHT__ ) - ( float ) ( __LEFT__  ) < 0.0000001 )

/// @}

#endif // ItConfig_Core_h

///////////////////////////////////////////////////////////////////////////////
