#include "FilterRed.h"
using namespace std;
#include <iostream>

void FilterRed::action(image_data &imgData)
{
	for (int i = coordFilter.u; i < coordFilter.b; ++i) {
		for (int j = coordFilter.l; j < coordFilter.r; ++j) {
			int ptr = (i*imgData.w + j)*imgData.compPerPixel;
			imgData.pixels[ptr + 0] = (unsigned char)255;
			imgData.pixels[ptr + 1] = (unsigned char)0;
			imgData.pixels[ptr + 2] = (unsigned char)0;
		}
	}
}