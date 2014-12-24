/*
 * Timer.hpp
 *
 *  Created on: Nov 30, 2014
 *      Author: wilsan
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

namespace GpTimer
{

	namespace instance
	{
		enum _instance
		{
			TIMERA0 = 0x0340,
			TIMERA1 = 0x0380,
			TIMERA2 = 0x0400,
			TIMERB0 = 0x03c0
		};
	}

	// CCR channels ( channels for me are ...
	// ... the capture compare blocks :D )
	namespace channel
	{
		enum _channel
		{
			SUBTIMER0 = 0x00,
			SUBTIMER1 = 0x02,
			SUBTIMER2 = 0x04,
			SUBTIMER3 = 0x06,
			SUBTIMER4 = 0x08,
			SUBTIMER5 = 0x0a,
			SUBTIMER6 = 0x0c
		};
	}

	namespace config
	{
		namespace mode
		{
			enum _mode 
			{
				stop = 0x00,
				countUp = 0x10,
				countContinuous = 0x20,
				countUpAndDown = 0x30
			}; 
		}

		namespace clockSource
		{
			enum _clockSource
			{
				ACLK = 0x100,
				SMCLK = 0x200,
				INCLK = 0x300
			};
		}

		namespace divider
		{
			enum _divider
			{
				div_1 = 0,
				div_2 = 0x040,
				div_3 = 0x080,
				div_4 = 0x0c0
			};
		}

		namespace extDivider
		{
			enum _extDivider
			{
				div_1 = 0x0,
				div_2 = 0x1,
				div_3 = 0x2,
				div_4 = 0x3,
				div_5 = 0x4,
				div_6 = 0x5,
				div_7 = 0x6,
				div_8 = 0x7
			};
		}

		namespace timerInterrupt
		{
			enum _timerInterrupt
			{  
				disabled = 0x0,
				enabled = 0x2
			};
		}

		namespace captureMode
		{
			enum _captureMode
			{
				captureNone 	= 0x0000,
				captureRising 	= 0x4000,
				captureFalling 	= 0x8000,
				captureBoth 	= 0xc000
			};
		}

		namespace capcomInput
		{
			enum _capcomInput
			{
				CCIxA 	= 0x0000,
				CCIxB 	= 0x1000,
				GND 	= 0x2000,
				VCC		= 0x3000
			};
		}

		namespace captureSync
		{
			enum _captureSync
			{
				capSync 	= 0x000,
				capAsync	= 0x800
			};
		}

		namespace capcomMode
		{
			enum _capcomMode
			{
				modeCompare = 0x000,
				modeCapture = 0x100
			};
		}

		namespace outputMode
		{
			enum _outputMode
			{
				modeOut = 0x00,
				modeSet = 0x20,
				modeToggleReset = 0x40,
				modeSetReset = 0x60,
				modeToggle = 0x80,
				modeReset = 0xa0,
				modeToggleSet = 0xc0,
				modeResetSet = 0xe0
			};
		}

		namespace forcedOutput
		{
			enum _forcedOutput 
			{
				outputLow 	= 0x0,
				outputHigh 	= 0x4
			};
		}
	}

	class Timer
	{
	protected:
		instance::_instance m_timerID;
		u32 m_clockRate;

		//void enableClock( clockSource::_clockSource tClockSource );
		//void clearTimer();
		//void setOutputMode();
		//void enableInterrupt();
		//bool isPendingInterrupt();

	public:		
		Timer();
		Timer( instance::_instance timerID,
			   u32 clockRate );

		void config( config::mode::_mode tMode,
					 config::divider::_divider tDivider,
					 config::extDivider::_extDivider tExtDivider,
					 config::timerInterrupt::_timerInterrupt tInterrupt,
					 config::clockSource::_clockSource tClockSource );

		void configChannel( u16 ticks,
							channel::_channel tSubtimer,
							config::captureMode::_captureMode tCaptureMode = config::captureMode::captureNone,
							config::capcomInput::_capcomInput tCapComInput = config::capcomInput::CCIxA,
							config::captureSync::_captureSync tCaptureSync = config::captureSync::capSync,
							config::capcomMode::_capcomMode tCapcomMode = config::capcomMode::modeCompare,
							config::outputMode::_outputMode tOutputMode = config::outputMode::modeSetReset,
							config::forcedOutput::_forcedOutput tForcedOutput = config::forcedOutput::outputLow );
		void clearCapComFlag( channel::_channel tSubtimer );
		void clearFlag();
	};

	class Pwm : public Timer
	{
	private:
		float m_duty;
		u16 m_frequency;

	public:
		Pwm();
		Pwm( GpTimer::instance::_instance timerID,
			 u32 clockRate );
		void config( u16 frequency );
		void setDuty( channel::_channel pChannel, float duty );
	};

	/*
	class Subtimer
	{
	private:
		instance::_instance m_timerID;
		subtimer::_subtimer m_subtimerID;
		u32 m_clockRate;
		u32 m_period_us;
		u32 m_numTicks;

	public:
		Subtimer();
		Subtimer( instance::_instance timerID, 
			   	  subtimer::_subtimer subtimerID,
			   	  u32 clockRate );

		void config(  );
	};
	 */

}

#include "../src/TimerImplement.hpp"

#endif /* TIMER_HPP_ */
