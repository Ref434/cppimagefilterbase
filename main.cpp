#include <iostream>
#include "png_toolkit.h"
#include "FilterRed.h"
#include "FilterBW.h"
#include "CfgReader.h"
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
		coordinates_filter coordFilter;
        png_toolkit studTool;
        studTool.load(argv[2]);
		CfgReader CfgReader(argv[1], &studTool, &coordFilter);
		FilterRed Red(coordFilter);
		BasicFilter *Filter = &Red;
		Filter->action(&studTool);
        studTool.save(argv[3]);

    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
