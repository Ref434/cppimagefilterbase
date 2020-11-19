#include "Threshold.h"
using namespace std;
#include <iostream>

void Threshold::action(image_data &imgData)
{
	
	image_data CopyImgData= imgData;
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
				std::vector<int> v;
				int ptr = (i*imgData.w + j)*imgData.compPerPixel;
				for (int k = i - 2; k <= i + 2; k++)
				{
					if (k >= coordFilter.u && k < coordFilter.b)
					for (int s = j - 2; s <= j + 2; s++)
					{
						if (s >= coordFilter.l && s < coordFilter.r)
						{
							int ptrInt = (k*CopyImgData.w + s)*CopyImgData.compPerPixel;
							int a = (3 * CopyImgData.pixels[ptrInt + 0] + 6 * CopyImgData.pixels[ptrInt + 1] + CopyImgData.pixels[ptrInt + 2]) / 10;
							v.push_back(a);
						}
						//cout << a << endl;

					}
				}
				int intensity = (3 * CopyImgData.pixels[ptr + 0] + 6 * CopyImgData.pixels[ptr + 1] + CopyImgData.pixels[ptr + 2]) / 10;
				sort(v.begin(), v.end());
				//cout << v.size()<< endl;
				if (intensity < v[v.size()/2])
				{
					//cout << "1" << endl;
					imgData.pixels[ptr + 0] = (unsigned char)0;
					imgData.pixels[ptr + 1] = (unsigned char)0;
					imgData.pixels[ptr + 2] = (unsigned char)0;
				}
		}
	}
	delete CopyImgData.pixels;
}