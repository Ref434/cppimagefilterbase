#include "Blur.h"
using namespace std;
#include <iostream>

void Blur::action(image_data &imgData)
{

	image_data CopyImgData = imgData;
	CopyImgData.h = imgData.h;
	CopyImgData.w = imgData.w;
	CopyImgData.compPerPixel = imgData.compPerPixel;
	int size = imgData.h*imgData.w*imgData.compPerPixel;
	CopyImgData.pixels = new stbi_uc[size];
	for (int i = 0; i < size; i++)
	{
		CopyImgData.pixels[i] = imgData.pixels[i];
	}


	for (int i = coordFilter.u; i < coordFilter.b; ++i) {
		for (int j = coordFilter.l; j < coordFilter.r; ++j) {
			int ptr = (i*imgData.w + j)*imgData.compPerPixel;
			int col1 = 0, col2 = 0, col3 = 0;
			for (int k = i - 1; k <= i + 1; k++)
			{
				if (k >= coordFilter.u && k < coordFilter.b)
					for (int s = j - 1; s <= j + 1; s++)
					{
						if (s >= coordFilter.l && s < coordFilter.r)
						{
							int ptrInt = (k*CopyImgData.w + s)*CopyImgData.compPerPixel;
								col1 += CopyImgData.pixels[ptrInt + 0];
								col2 += CopyImgData.pixels[ptrInt + 1];
								col3 += CopyImgData.pixels[ptrInt + 2];
						}
						//cout << a << endl;

					}
			}
			col1 /= 9;
			col2 /= 9;
			col3 /= 9;
			imgData.pixels[ptr + 0] = (unsigned char)col1;
			imgData.pixels[ptr + 1] = (unsigned char)col2;
			imgData.pixels[ptr + 2] = (unsigned char)col3;
		}
	}
	delete CopyImgData.pixels;
}