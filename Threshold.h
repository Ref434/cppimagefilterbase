#ifndef THRESHOLD_H
#define THRESHOLD_H
#include <iostream>
#include "png_toolkit.h"
#include "BasicFilter.h"
#include <vector>
#include <algorithm> 


class Threshold :public BasicFilter {
public:
	using BasicFilter::BasicFilter;
	void action(image_data &imgData);

};



#endif 

