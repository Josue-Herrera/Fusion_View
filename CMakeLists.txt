cmake_minimum_required(VERSION 3.12)

project(Fusion_View_Framework 
VERSION 0.0.1
LANGUAGES CXX C
)

include(cmake/CMakeRC.cmake)

cmrc_add_resource_library(
    Fusion_View_Resources
    ALIAS fv::Resources
    NAMESPACE fv
    WHENCE 
    RESOURCES
     resources/fonts/Open_Sans/OpenSans-Bold.ttf
     resources/fonts/Open_Sans/OpenSans-BoldItalic.ttf
     resources/fonts/Open_Sans/OpenSans-ExtraBold.ttf
     resources/fonts/Open_Sans/OpenSans-ExtraBoldItalic.ttf
     resources/fonts/Open_Sans/OpenSans-Italic.ttf
     resources/fonts/Open_Sans/OpenSans-Light.ttf
     resources/fonts/Open_Sans/OpenSans-LightItalic.ttf
     resources/fonts/Open_Sans/OpenSans-Regular.ttf
     resources/fonts/Open_Sans/OpenSans-SemiBold.ttf
     resources/fonts/Open_Sans/OpenSans-SemiBoldItalic.ttf
     resources/google/home/1x/baseline_home_white_18dp.png
     resources/google/home/2x/baseline_home_white_18dp.png
     resources/google/home/3x/baseline_home_white_18dp.png
     resources/test.txt
)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(dependencies)
add_subdirectory(view)

