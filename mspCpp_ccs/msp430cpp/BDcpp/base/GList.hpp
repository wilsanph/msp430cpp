/*
 * GList.hpp
 *
 *  Created on: Nov 30, 2014
 *      Author: wilsan
 */

#ifndef GLIST_HPP_
#define GLIST_HPP_

#include "../../common.hpp"

template<typename Type,u8 size>
class GList
{
public:
	Type* buff[size];
	u8 maxSize;
	u8 length;

	GList()
	{
		this->maxSize = size;
		this->length = 0;
		for ( int i = 0; i < size; ++i )
		{
			this->buff[i] = NULL;
		}
	}

	bool append( Type* pElement )
	{
		if ( this->length < size )
		{
			this->buff[this->length] = pElement;
			this->length++;
			return true;
		}
		return false;
	}
	Type* pop( Type element )
	{
		Type* temp = this->buff[this->length - 1];
		this->buff[this->length - 1] = NULL;
		this->length--;
		return temp;
	}
	void getElement( u8 indx )
	{
		if ( indx > this->length - 1 )
		{
			return NULL;
		}
		return this->buff[indx];
	}
};



#endif /* GLIST_HPP_ */
