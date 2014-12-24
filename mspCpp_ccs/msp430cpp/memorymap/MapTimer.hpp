/*
 * MapTimer.hpp
 *
 *  Created on: Nov 30, 2014
 *      Author: wilsan
 */

#ifndef MAPTIMER_HPP_
#define MAPTIMER_HPP_

#include "../common.hpp"

namespace MapTimer
{

	struct TimerRegs
	{
		u16 TxnCTL;// 0x00
		u16 TxnCCTL0;// 0x02
		u16 TxnCCTL1;// 0x04
		u16 TxnCCTL2;// 0x06
		u16 TxnCCTL3;// 0x08
		u16 TxnCCTL4;// 0x0a
		u16 TxnCCTL5;// 0x0c
		u16 TxnCCTL6;// 0x0e
		u16 TxnR;// 0x10
		u16 TxnCCR0;// 0x12
		u16 TxnCCR1;// 0x14
		u16 TxnCCR2;// 0x16
		u16 TxnCCR3;// 0x18
		u16 TxnCCR4;// 0x1a
		u16 TxnCCR5;// 0x1c
		u16 TxnCCR6;// 0x1e
		u16 TxnEX0;// 0x20
		u16 reserved1[6];// 0x2i 'i' in { 2,4,6,8,a,c }
		u16 TxnIV;// 0x2e
	};
}



#endif /* MAPTIMER_HPP_ */
