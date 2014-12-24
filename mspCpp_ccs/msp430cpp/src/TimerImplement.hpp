/*
 * TimerImplement.hpp
 *
 *  Created on: Nov 30, 2014
 *      Author: wilsan
 */

#ifndef TIMERIMPLEMENT_HPP_
#define TIMERIMPLEMENT_HPP_

#include "../common.hpp"
#include "../memorymap/MapTimer.hpp"
#include "../include/Timer.hpp"

namespace GpTimer
{
	GpTimer::Timer::Timer()
	{
		this->m_timerID 	= GpTimer::instance::TIMERA0;
		this->m_clockRate	= 32000;
	}

	GpTimer::Timer::Timer( GpTimer::instance::_instance timerID,
						   u32 clockRate )
	{
		this->m_timerID 	= timerID;
		this->m_clockRate 	= clockRate;
	}

	void GpTimer::Timer::config( GpTimer::config::mode::_mode tMode,
								 GpTimer::config::divider::_divider tDivider,
								 GpTimer::config::extDivider::_extDivider tExtDivider,
								 GpTimer::config::timerInterrupt::_timerInterrupt tInterrupt,
								 GpTimer::config::clockSource::_clockSource tClockSource )
	{
		// Clear the timer first
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID )->TxnCTL |= ( 1 << 2 );
		// Load the desired configuration to the ctl register
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID )->TxnCTL = tClockSource | tMode | tDivider | tInterrupt;
		// Load the external divider
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID )->TxnEX0 = tExtDivider;
	}

	void GpTimer::Timer::configChannel( u16 ticks,
										GpTimer::channel::_channel tSubtimer,
										GpTimer::config::captureMode::_captureMode tCaptureMode,
										GpTimer::config::capcomInput::_capcomInput tCapComInput,
										GpTimer::config::captureSync::_captureSync tCaptureSync,
										GpTimer::config::capcomMode::_capcomMode tCapcomMode,
										GpTimer::config::outputMode::_outputMode tOutputMode,
										GpTimer::config::forcedOutput::_forcedOutput tForcedOutput )
	{
		// Configure the corresponding CapCom block
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID + tSubtimer )->TxnCCTL0 = tCapcomMode | tCapComInput |
														tCaptureSync | tCapcomMode |
														tOutputMode | tForcedOutput;
		// Load the number of ticks to the corresponding CapCom reg
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID + tSubtimer )->TxnCCR0 = ticks;
	}

	void GpTimer::Timer::clearCapComFlag( GpTimer::channel::_channel tSubtimer )
	{
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID + tSubtimer )->TxnCCTL0 &= ( 0xffff - 1 );
	}

	void GpTimer::Timer::clearFlag()
	{
		reinterpret_cast<MapTimer::TimerRegs*>
			( this->m_timerID )->TxnCTL &= ( 0xffff - 1 );
	}

	// TODO: Check ( check your glfw project :D ) how to call super

	GpTimer::Pwm::Pwm()
	{		
		this->m_timerID 	= GpTimer::instance::TIMERA0;
		this->m_clockRate	= 32000;		
		this->m_duty = 0;
		this->m_frequency = 1;
	}

	GpTimer::Pwm::Pwm( GpTimer::instance::_instance timerID,
			 		   u32 clockRate )
	{
		this->m_timerID = GpTimer::instance::TIMERA0;
		this->m_clockRate = 32000;		
		this->m_duty = 0;
		this->m_frequency = 1;
	}

	void GpTimer::Pwm::config( u16 frequency )
	{
		this->m_frequency = frequency;
		
	}

	void GpTimer::Pwm::setDuty( GpTimer::channel::_channel pChannel,
								float duty )
	{
		this->m_duty = duty;
	}
}



#endif /* TIMERIMPLEMENT_HPP_ */
