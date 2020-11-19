#ifndef CFG_READER_H
#define CFG_READER_H
#include <string>
#include <iostream>
#include <map>
#include "png_toolkit.h"

typedef enum filter_type {
	RED_FILTER,
	THRESHOLD_FILTER,
	BLUR_FILTER,
	EDGE_FILTER
} filter_type_t;
struct coordinates_filter
{
	int u; 
	int l;
	int b;
	int r;
	filter_type_t type;
	
};

class CfgReader
{
	
	public:
		static const int num_filtres=2;
		CfgReader(std::string const &config, png_toolkit *png);
		coordinates_filter coordFilter[num_filtres];
};


#endif 
