/*
 * Clock.hpp
 *
 *  Created on: Dec 23, 2014
 *      Author: wilsan
 */

#ifndef CLOCK_HPP_
#define CLOCK_HPP_


namespace Clock
{
	namespace baseAddress
	{
		enum _baseAddress 
		{ 
			ucsAddress = 0x0160 
		};		
	}

	namespace clocks
	{
		enum _clocks
		{
			master = 0,// offset in the control registers		
			subMaster = 4,
			auxiliary = 8
		};
	}

	namespace config
	{
		namespace clockSource
		{
			enum _clockSource 
			{  
				XT1CLK 		= 0,
				VLOCLK 		= 1,
				REFOCLK 	= 2,
				DCOCLK 		= 3,
				DCOCLKDIV 	= 4,
				XT2CLK 		= 5				
			};
		}

		namespace clockDivider
		{
			enum _clockDivider 
			{  
				div_1 = 0,
				div_2 = 1,
				div_4 = 2,
				div_8 = 3,
				div_16 = 4,
				div_32 = 5				
			};
		}
	}

	class UCS
	{
	private:
		clocks::_clocks m_clockInstance;
	public:
		UCS();
		UCS( clocks::_clocks clockInstance );
		void selectSource( config::clockSource::_clockSource cSource );
		void setDivider( config::clockDivider::_clockDivider cDivider );
		void config( config::clockSource::_clockSource cSource,
					 config::clockDivider::_clockDivider cDivider );
	};

}


#include "../src/ClockImplement.hpp"

#endif /* CLOCK_HPP_ */
