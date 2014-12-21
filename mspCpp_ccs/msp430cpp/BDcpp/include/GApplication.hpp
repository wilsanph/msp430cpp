/*
 * GApplication.hpp
 *
 *  Created on: Nov 30, 2014
 *      Author: wilsan
 */

#ifndef GAPPLICATION_HPP_
#define GAPPLICATION_HPP_

#include "../../common.hpp"
#include "../base/GList.hpp"
#include "../include/GComponent.hpp"

/*
 * TODO: Dynamic memory allocation seems necessary
 */

class GApplication
{
public:
	GList<GComponent,20> components;
	void init();
	void update( u8 dt );

	/*
	 * TODO: Implement this
	 */

//	void schedule( u8 componentIndx, GScheduleProp props );
};


#endif /* GAPPLICATION_HPP_ */
