#include "BasicFilter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

BasicFilter::BasicFilter(coordinates_filter coordFilter)
{
	this->coordFilter.u = coordFilter.u;
	this->coordFilter.l = coordFilter.l;
	this->coordFilter.b = coordFilter.b;
	this->coordFilter.r = coordFilter.r;
}
