#ifndef BASIC_FILTER_H
#define BASIC_FILTER_H

#include <string>
#include <iostream>
#include <map>
#include "png_toolkit.h"

struct coordinates_filter
{
	int u, l, b, r;
};
class BasicFilter {
public:
	BasicFilter(coordinates_filter coordFilter);
	virtual void action(png_toolkit *png)=0;
	coordinates_filter coordFilter;

};


#endif 
