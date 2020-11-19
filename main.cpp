#include <iostream>
#include "png_toolkit.h"
#include "FilterRed.h"
#include "FilterBW.h"
#include "CfgReader.h"
#include "Threshold.h"
using namespace std;

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
		//cout << argc << endl;
        if (argc != 4)
            throw "Not enough arguments";
        png_toolkit studTool;
        studTool.load(argv[2]);
		image_data imgData = studTool.getPixelData();
		CfgReader CfgReader(argv[1], &studTool);
		BasicFilter *Filter;
		cout << CfgReader.num_filtres << endl;
		FilterRed Red(CfgReader.coordFilter[0]);
		Filter = &Red;
		Filter->action(imgData);
		Threshold Threshold(CfgReader.coordFilter[1]);
		FilterBW BW(CfgReader.coordFilter[1]);
		Filter = &BW;
		Filter->action(imgData);

		Filter = &Threshold;
		Filter->action(imgData);
		/*for (int i = 0; i < CfgReader.num_filtres; i++)
		{
			switch (CfgReader.coordFilter[i].type)
			{
			case RED_FILTER:
			{
				cout << "Using RED" << endl;
				FilterRed Red(CfgReader.coordFilter[i]);
				Filter = &Red;
				Filter->action(imgData);
				break;
			}
			case THRESHOLD_FILTER:
			{
				cout << "Using THRESHOLD" << endl;
				Threshold Threshold(CfgReader.coordFilter[i]);
				FilterBW BW(CfgReader.coordFilter[i]);
				Filter = &BW;
				Filter->action(imgData);

				Filter = &Threshold;
				Filter->action(imgData);

				break;
			}
			case BLUR_FILTER:
			{
				cout << "Using BLUR" << endl;
				FilterRed Red(CfgReader.coordFilter[i]);
				Filter = &Red;
				Filter->action(imgData);
				break;
			}
			case EDGE_FILTER:
			{
				cout << "Using EDGE" << endl;
				FilterRed Red(CfgReader.coordFilter[i]);
				Filter = &Red;
				Filter->action(imgData);
				
				break;
			}
			default:
				break;
			}
		}*/
        studTool.save(argv[3]);

    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
