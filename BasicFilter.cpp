#include "BasicFilter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

BasicFilter::BasicFilter(std::string const &config, png_toolkit *png,std::string FilterName)
{
	image_data imgData = png->getPixelData();
	ifstream cfg(config);
	do
	{
		getline(cfg, coordFilter.str);
	} while (coordFilter.str != FilterName && !cfg.eof());
	if (cfg.eof())
	{
		cout << "Filter is not found" << endl;
	}
	else
	{
		cout << "Using " << FilterName << " Filter" << endl;
		cfg >> coordFilter.u;
		if (coordFilter.u != 0)
		{
			coordFilter.u = int(imgData.h / coordFilter.u);
		}
		cfg >> coordFilter.l;
		if (coordFilter.l != 0)
		{
			coordFilter.l = int(imgData.w / coordFilter.l);
		}
		cfg >> coordFilter.b;
		if (coordFilter.b != 0)
		{
			coordFilter.b = int(imgData.h / coordFilter.b);
		}
		cfg >> coordFilter.r;
		if (coordFilter.r != 0)
		{
			coordFilter.r = int(imgData.w / coordFilter.r);
		}
	}
}
