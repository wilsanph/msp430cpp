/*
 * TimerImplement.hpp
 *
 *  Created on: Nov 30, 2014
 *      Author: wilsan
 */

#ifndef CLOCKIMPLEMENT_HPP_
#define CLOCKIMPLEMENT_HPP_

#include "../common.hpp"
#include "../memorymap/MapClock.hpp"
#include "../include/Clock.hpp"

namespace Clock
{

	Clock::UCS::UCS()
	{
		this->m_clockInstance = Clock::clocks::auxiliary;
	}

	Clock::UCS::UCS( clocks::_clocks clockInstance )
	{
		this->m_clockInstance = clockInstance;
	}	

	void Clock::UCS::selectSource( Clock::config::clockSource::_clockSource cSource )
	{
		u16 unchangedPart = reinterpret_cast<MapClock::ClockRegs*>
								( Clock::baseAddress::ucsAddress )->UCSCTL4;
		// Clean the part corresponding to the related clock instance
		unchangedPart &= ( 0xffff - ( 0x7 << this->m_clockInstance ) );
		reinterpret_cast<MapClock::ClockRegs*>
			( Clock::baseAddress::ucsAddress )->UCSCTL4 = unchangedPart | ( cSource << this->m_clockInstance );
	}

	void Clock::UCS::setDivider( Clock::config::clockDivider::_clockDivider cDivider )
	{
		u16 unchangedPart = reinterpret_cast<MapClock::ClockRegs*>
								( Clock::baseAddress::ucsAddress )->UCSCTL5;
		// Clean the part corresponding to the related clock instance
		unchangedPart &= ( 0xffff - ( 0x7 << this->m_clockInstance ) );
		reinterpret_cast<MapClock::ClockRegs*>
			( Clock::baseAddress::ucsAddress )->UCSCTL5 = unchangedPart | ( cDivider << this->m_clockInstance );
	}

	void Clock::UCS::config( Clock::config::clockSource::_clockSource cSource,
							 Clock::config::clockDivider::_clockDivider cDivider )
	{
		this->selectSource( cSource );
		this->setDivider( cDivider );
	}	
}


#endif /* CLOCKIMPLEMENT_HPP_ */
