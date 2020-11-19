#include "CfgReader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

CfgReader::CfgReader(std::string const &config, png_toolkit *png)
{
	image_data imgData = png->getPixelData();
	ifstream file(config);
	string str;
	if (!file) {
		std::cout << "File not open!";
		exit(0);
	}
	for (int i = 0; i < num_filtres; i++)
	{
		file >> str >> coordFilter[i].u >> coordFilter[i].l >> coordFilter[i].b >> coordFilter[i].r;
		if (str == "red")	
			coordFilter[i].type = RED_FILTER;
		if (str == "threshold")
			coordFilter[i].type = THRESHOLD_FILTER;
		if (str == "blur")
			coordFilter[i].type = BLUR_FILTER;
		if (str == "edge")
			coordFilter[i].type = EDGE_FILTER;
		if (coordFilter[i].u != 0)
		{
			coordFilter[i].u = int(imgData.h / coordFilter[i].u);
		}
		if (coordFilter[i].l != 0)
		{
			coordFilter[i].l = int(imgData.w / coordFilter[i].l);
		}
		if (coordFilter[i].b != 0)
		{
			coordFilter[i].b = int(imgData.h / coordFilter[i].b);
		}
		if (coordFilter[i].r != 0)
		{
			coordFilter[i].r = int(imgData.w / coordFilter[i].r);
		}
	}
	file.close();
}