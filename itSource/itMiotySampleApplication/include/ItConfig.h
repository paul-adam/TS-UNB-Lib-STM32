///////////////////////////////////////////////////////////////////////////////
///
/// @file          ItConfig.h
/// @brief         Header file with defines for code configuration
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
/// @details       This file contains the list of features implemented by conditional compile in the source code.
///                It must be included by source files at first position before any other itSource header files ("It*.h" or "It*.hxx").
///
/// @defgroup      ItConfig     ItConfig
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ItConfig_h
#define ItConfig_h

/// @addtogroup ItConfig
/// @{

#define IT_CONFIG_CODE_NAME                                          "  itMiotyEndpoint   "

///////////////////////////////////////////////////////////////////////////////
///
/// Implemented features
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// hal

#define IT_CONFIG_HAL_LED
#define IT_CONFIG_HAL_TEST_POINT

///////////////////////////////////////////////////////////////////////////////
// mioty

#define IT_CONFIG_MIOTY

#include "ItConfig_Dependency.h"

///////////////////////////////////////////////////////////////////////////////
///
/// Config of implemented features
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// mioty

#ifdef IT_CONFIG_MIOTY

// define one of following
#define IT_CONFIG_MIOTY_RFM69HW                                                                    ///< RFM69hw will be used for transmission
//#define IT_CONFIG_MIOTY_RFM69W                                                                     ///< RFM69w will be used for transmission

#define IT_CONFIG_MIOTY_TX_PWR_LEVEL                                 7

#endif // IT_CONFIG_MIOTY

/// @}

///////////////////////////////////////////////////////////////////////////////

#include "ItConfig_Target.h"
#include "ItConfig_Core.h"
#include "ItConfig_Check.h"

#endif // ItConfig_h

///////////////////////////////////////////////////////////////////////////////
