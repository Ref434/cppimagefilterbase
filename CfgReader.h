#ifndef CFG_READER_H
#define CFG_READER_H
#include <string>
#include <iostream>
#include <map>
#include "png_toolkit.h"
#include "BasicFilter.h"


class CfgReader
{
	public:
		CfgReader(std::string const &config, png_toolkit *png, coordinates_filter *coordFilter);
};


#endif 
