#include "CfgReader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

CfgReader::CfgReader(std::string const &config, png_toolkit *png,coordinates_filter *coordFilter)
{
	image_data imgData = png->getPixelData();
	string str;
	ifstream file(config);
	if (!file) {
		std::cout << "File not open!";
		exit(0);
	}
	file >> str >> coordFilter->u >> coordFilter->l >> coordFilter->b >> coordFilter->r;
	file.close();
		cout << "Using " << str << " Filter" << endl;
		if (coordFilter->u != 0)
		{
			coordFilter->u = int(imgData.h / coordFilter->u);
		}
		if (coordFilter->l != 0)
		{
			coordFilter->l = int(imgData.w / coordFilter->l);
		}
		if (coordFilter->b != 0)
		{
			coordFilter->b = int(imgData.h / coordFilter->b);
		}
		if (coordFilter->r != 0)
		{
			coordFilter->r = int(imgData.w / coordFilter->r);
		}
}