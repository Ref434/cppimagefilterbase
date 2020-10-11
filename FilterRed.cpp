#include "FilterRed.h"
using namespace std;
#include <iostream>

void FilterRed::action(png_toolkit *png)
{
	image_data imgData = png->getPixelData();
	int coord_i = 0, coord_j = 0;
	for (int i = 0; i < imgData.compPerPixel*imgData.w*imgData.h; i += 3)
	{
		coord_i += 3;
		if (coord_i >= imgData.w*imgData.compPerPixel)
		{
			coord_j += 1;
			coord_i = 0;
		}
		if (coord_i >= coordFilter.l*imgData.compPerPixel && coord_j >= coordFilter.u && coord_i<=coordFilter.r*imgData.compPerPixel && coord_j<=coordFilter.b)
		{
			*(imgData.pixels + i) = 255;
			*(imgData.pixels + i + 1) = 0;
			*(imgData.pixels + i + 2) = 0;
		}
	}
	cout << coordFilter.u << " " << coordFilter.l << " " << coordFilter.b << " " << coordFilter.r << " " << endl;
}