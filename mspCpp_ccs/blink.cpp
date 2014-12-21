
#include "msp430cpp/include/Gpio.hpp"

Gpio::Pin led( Gpio::port::PORT1, Gpio::pins::pin0 );

int main()
{

	led.setMode( Gpio::config::mode::gpio );
	led.setIOMode( Gpio::config::ioMode::output );

	while( 1 )
	{
		common::sw_delay();
		led.toggle();
	}
}
