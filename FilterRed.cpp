#include "FilterRed.h"
using namespace std;
#include <iostream>

void FilterRed::action(png_toolkit *png)
{
	image_data imgData = png->getPixelData();
	/*int coord_i = 0, coord_j = 0;
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
	}*/
	for (int i = coordFilter.u; i < coordFilter.b; ++i) {
		for (int j = coordFilter.l; j < coordFilter.r; ++j) {
			int ptr = (i*imgData.w + j)*imgData.compPerPixel;
			imgData.pixels[ptr + 0] = (unsigned char)255;
			imgData.pixels[ptr + 1] = (unsigned char)0;
			imgData.pixels[ptr + 2] = (unsigned char)0;
		}
	}
}