/*
 * MapClock.hpp
 *
 *  Created on: Dec 23, 2014
 *      Author: wilsan
 */

#ifndef MAPCLOCK_HPP_
#define MAPCLOCK_HPP_

#include "../common.hpp"

namespace MapClock
{
	struct ClockRegs
	{
		u16 UCSCTL0;
		u16 UCSCTL1;
		u16 UCSCTL2;
		u16 UCSCTL3;
		u16 UCSCTL4;
		u16 UCSCTL5;
		u16 UCSCTL6;
		u16 UCSCTL7;
		u16 UCSCTL8;
	};

}

#endif /* MAPCLOCK_HPP_ */
