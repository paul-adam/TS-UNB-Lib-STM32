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
 * @brief	TS-UNB configs for different frequency ranges and TX chips for the STM32 micro controller
 *
 * @authors	Joerg Robert
 * @authors     Modifications made by Paul Adam
 * @file	STM32TsUnbTemplates.h
 *
 */


#ifndef STM32_TSUNB_TEMPLATES_H_
#define STM32_TSUNB_TEMPLATES_H_

#include "../Trx/Rfm69hw.h"

namespace TsUnbLib {
namespace STM32 {

/////////////////////////////////
// RFM69w
/////////////////////////////////

//! RFM69w in EU0 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14224261, 39, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU0_Rfm69w_t;

//! RFM69w in EU1 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14222623, 39, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU1_Rfm69w_t;

//! RFM69w in EU2 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14215168, 14202061, 468, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU2_Rfm69w_t;

//! RFM69w in US0 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<15014297, 15001190, 468, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, true> TsUnb_US0_Rfm69w_t;

//! RFM69w in EU0 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14224261, 39, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU0_LowLatency_Rfm69w_t;

//! RFM69w in EU1 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14222623, 39, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU1_LowLatency_Rfm69w_t;

//! RFM69w in EU2 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14215168, 14202061, 468, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU2_LowLatency_Rfm69w_t;

//! RFM69w in US0 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<15014297, 15001190, 468, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, false, 10, TsUnb::RadioBurst <2,2> >, true> TsUnb_US0_LowLatency_Rfm69w_t;



/////////////////////////////////
// RFM69hw
/////////////////////////////////

//! RFM69hw in EU0 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14224261, 39, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU0_Rfm69hw_t;

//! RFM69hw in EU1 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14222623, 39, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU1_Rfm69hw_t;

//! RFM69hw in EU2 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14215168, 14202061, 468, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU2_Rfm69hw_t;

//! RFM69hw in US0 configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<15014297, 15001190, 468, 39, TsUnb::TsUnb_UPG1, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, true> TsUnb_US0_Rfm69hw_t;

//! RFM69hw in EU0 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14224261, 39, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU0_LowLatency_Rfm69hw_t;

//! RFM69hw in EU1 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14224261, 14222623, 39, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU1_LowLatency_Rfm69hw_t;

//! RFM69hw in EU2 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<14215168, 14202061, 468, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, false> TsUnb_EU2_LowLatency_Rfm69hw_t;

//! RFM69hw in US0 Low Latency configuration
typedef TsUnb::SimpleNode<TsUnb::FixedUplinkMac,
	TsUnb::Phy<15014297, 15001190, 468, 39, TsUnb::TsUnb_UPG3, 0, 3, TsUnb::RadioBurst <2,2> >,
	Trx::Rfm69hw<STM32TsUnb<48>, true, 10, TsUnb::RadioBurst <2,2> >, true> TsUnb_US0_LowLatency_Rfm69hw_t;



};	// namespace STM32
};	// namespace TsUnbLib
#endif // STM32_TSUNB_TEMPLATES_H_

