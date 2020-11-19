#include "FilterBW.h"
using namespace std;
#include <iostream>

void FilterBW::action(image_data &imgData)
{
	cout << coordFilter.u << " " << coordFilter.b << " " << coordFilter.l << " " << coordFilter.r << " " << endl;
	for (int i = coordFilter.u; i < coordFilter.b; ++i) {
		for (int j = coordFilter.l; j < coordFilter.r; ++j) {
			int ptr = (i*imgData.w + j)*imgData.compPerPixel;
			int x = int(0.3*(imgData.pixels[ptr]) + 0.6*(imgData.pixels[ptr + 1]) + 0.1*(imgData.pixels[ptr + 2]));
			imgData.pixels[ptr] = (unsigned char)x;
			imgData.pixels[ptr + 1] = (unsigned char)x;
			imgData.pixels[ptr + 2] = (unsigned char)x;
		}
	}
}