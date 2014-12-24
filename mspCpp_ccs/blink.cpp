#include <msp430.h>
#include "msp430cpp/include/Gpio.hpp"
#include "msp430cpp/include/Timer.hpp"
#include "msp430cpp/include/Clock.hpp"

#pragma NOINIT
unsigned int SysRstIv;

Gpio::Pin led( Gpio::port::PORT1, Gpio::pins::pin0 );
Gpio::Pin led2( Gpio::port::PORT4, Gpio::pins::pin7 );
GpTimer::Timer timerA0( GpTimer::instance::TIMERA0, 32000 );

Clock::UCS auxiliaryClock( Clock::clocks::auxiliary );

int main()
{
	// Stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// save reset information
	SysRstIv = SYSRSTIV;

	//auxiliaryClock.selectSource( Clock::config::clockSource::XT2CLK );
	//auxiliaryClock.setDivider( Clock::config::clockDivider::div_16 );

	auxiliaryClock.selectSource( Clock::config::clockSource::DCOCLKDIV );
	auxiliaryClock.setDivider( Clock::config::clockDivider::div_4 );

	led.setMode( Gpio::config::mode::gpio );
	led.setIOMode( Gpio::config::ioMode::output );

	led2.setMode( Gpio::config::mode::gpio );
	led2.setIOMode( Gpio::config::ioMode::output );

	timerA0.config( GpTimer::config::mode::countUp,
					GpTimer::config::divider::div_1,
					GpTimer::config::extDivider::div_5,
					GpTimer::config::timerInterrupt::enabled,
					GpTimer::config::clockSource::ACLK );
	timerA0.configChannel( 50000,
						   GpTimer::channel::SUBTIMER0 );


	__bis_SR_register( GIE );         // Enable interrupts globally

	while( 1 )
	{
		common::sw_delay();
		led.toggle();
	}
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void timer0_isr (void)
{
	timerA0.clearFlag();
	led2.toggle();
}


