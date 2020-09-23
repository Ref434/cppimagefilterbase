#ifndef RED_FILTER_H
#define RED_FILTER_H
#include <string>
#include <iostream>
#include <map>
#include "png_toolkit.h"
#include "BasicFilter.h"


class FilterRed :public BasicFilter {
public:
	using BasicFilter::BasicFilter;
	void action(png_toolkit *png);

};


#endif 
