#ifndef BASIC_FILTER_H
#define BASIC_FILTER_H

#include <string>
#include <iostream>
#include <map>
#include "png_toolkit.h"
#include "CfgReader.h"

class BasicFilter {
public:
	BasicFilter(coordinates_filter coordFilter);
	virtual void action(image_data &imgData)=0;
	coordinates_filter coordFilter;

};


#endif 
