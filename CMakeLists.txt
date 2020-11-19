cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" "FilterRed.h" "FilterRed.cpp" "FilterBW.h" "FilterBW.cpp" "BasicFilter.cpp" "BasicFilter.h" "Edge.h" "Edge.cpp" "Blur.cpp" "Blur.h" "CfgReader.cpp" "CfgReader.h" "Threshold.cpp" "Threshold.h")
