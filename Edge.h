#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include "png_toolkit.h"
#include "BasicFilter.h"
#include <vector>
#include <algorithm> 


class Edge :public BasicFilter {
public:
	using BasicFilter::BasicFilter;
	void action(image_data &imgData);

};



#endif 
