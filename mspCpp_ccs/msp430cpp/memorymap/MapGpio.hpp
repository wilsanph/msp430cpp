/*
 * MapGpio.hpp
 *
 *  Created on: 18/11/2014
 *      Author: USER01
 */

#ifndef MAPGPIO_HPP_
#define MAPGPIO_HPP_

#include "../common.hpp"

namespace MapGpio {

	namespace baseAddresses
	{
		enum _baseAddresses
		{
			PORT1 = 0x200,
			PORT2 = 0x201
		};
	}

	struct GpioRegs
	{
		u8 PxIN;
		u8 reserved1;
		u8 PxOUT;
		u8 reserved2;
		u8 PxDIR;
		u8 reserved3;
		u8 PxREN;
		u8 reserved4;
		u8 PxDS;
		u8 reserved5;
		u8 PxSEL;
		u8 reserved6;
		u8 PxIES;
		u8 reserved7;
		u8 PxIE;
		u8 reserved8;
		u8 PxIFG;
	};



}


#endif /* MAPGPIO_HPP_ */
