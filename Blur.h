#ifndef BLUR_H
#define BLUR_H
#include <iostream>
#include "png_toolkit.h"
#include "BasicFilter.h"
#include <vector>
#include <algorithm> 


class Blur :public BasicFilter {
public:
	using BasicFilter::BasicFilter;
	void action(image_data &imgData);

};



#endif 
