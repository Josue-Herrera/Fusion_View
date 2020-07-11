cmake_minimum_required(VERSION 3.12)

set(TARGET_NAME Fusion_View)
project(
${TARGET_NAME} 
VERSION 0.1.0
LANGUAGES CXX
)

add_subdirectory(dependencies)
add_subdirectory(src)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${TARGET_NAME})
