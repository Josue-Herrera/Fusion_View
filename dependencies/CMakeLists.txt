########################################################################
# CPM bootstrap
########################################################################
include(FetchContent)

set(CPM_DOWNLOAD_VERSION 0.38.6)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
if(NOT EXISTS ${CPM_DOWNLOAD_LOCATION})
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
        ${CPM_DOWNLOAD_LOCATION}
        TLS_VERIFY ON)
endif()
include(${CPM_DOWNLOAD_LOCATION})

########################################################################
# GLFW via CPM
########################################################################
set(GLFW_LIB_NAME "glfw")
set(GLFW_INC_PATH ${GLFW_LIB_NAME}/include)

CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.3.8
    OPTIONS
        "GLFW_BUILD_DOCS OFF"
        "GLFW_BUILD_TESTS OFF"
        "GLFW_BUILD_EXAMPLES OFF"
        "GLFW_INSTALL OFF"
)


########################################################################
# GLAD via CPM (generator)
########################################################################
find_package(Python3 COMPONENTS Interpreter REQUIRED)

CPMAddPackage(
    NAME glad_py
    GITHUB_REPOSITORY Dav1dde/glad
    GIT_TAG v0.1.36
    DOWNLOAD_ONLY YES
)

set(GLAD_OUT_DIR ${CMAKE_BINARY_DIR}/generated/glad)
set(GLAD_INCLUDE_DIR ${GLAD_OUT_DIR}/include)
set(GLAD_SOURCE ${GLAD_OUT_DIR}/src/glad.c)

add_custom_target(glad_py_fetch DEPENDS ${glad_py_SOURCE_DIR}/glad/__main__.py)

add_custom_command(
    OUTPUT ${GLAD_SOURCE}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${GLAD_OUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${glad_py_SOURCE_DIR} ${Python3_EXECUTABLE} -m glad --generator c --spec gl --api gl=3.3 --profile core --out-path ${GLAD_OUT_DIR}
    DEPENDS glad_py_fetch
    COMMENT "Generating GLAD (OpenGL 3.3 core)"
    VERBATIM
)

add_library(glad STATIC ${GLAD_SOURCE})
target_include_directories(glad PUBLIC ${GLAD_INCLUDE_DIR})
set_target_properties(glad PROPERTIES FOLDER "Glad_Imgui")

########################################################################
# FreeType via CPM
########################################################################
CPMAddPackage(
    NAME freetype
    GITHUB_REPOSITORY freetype/freetype
    GIT_TAG VER-2-13-3
    OPTIONS
        "BUILD_SHARED_LIBS OFF"
        "CMAKE_POSITION_INDEPENDENT_CODE ON"
        "FT_WITH_ZLIB OFF"
        "FT_WITH_BZIP2 OFF"
        "FT_WITH_PNG OFF"
        "FT_WITH_HARFBUZZ OFF"
        "FT_WITH_BROTLI OFF"
)

########################################################################
# ImGui via CPM (fetched sources + backends)
########################################################################
CPMAddPackage(
    NAME imgui
    GITHUB_REPOSITORY ocornut/imgui
    VERSION 1.90.9
)

set(IMGUI_LIB_NAME "ImGui")

########################################################################
# STB via CPM (header-only)
########################################################################
CPMAddPackage(
    NAME stb
    GITHUB_REPOSITORY nothings/stb
    GIT_TAG master
    DOWNLOAD_ONLY YES
)

add_library(${IMGUI_LIB_NAME} STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    ${imgui_SOURCE_DIR}/misc/freetype/imgui_freetype.cpp
)

target_compile_definitions(${IMGUI_LIB_NAME} PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD=1)

target_include_directories(${IMGUI_LIB_NAME}
    PUBLIC
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
        ${stb_SOURCE_DIR}
        ${GLAD_INCLUDE_DIR}
)

target_link_libraries(${IMGUI_LIB_NAME}
    PRIVATE
        glfw
        freetype
        glad
)

set_target_properties(${IMGUI_LIB_NAME} PROPERTIES FOLDER "Glad_Imgui")

########################################################################
# GLM via CPM (header-only)
########################################################################
CPMAddPackage(
    NAME glm
    GITHUB_REPOSITORY g-truc/glm
    GIT_TAG 1.0.1
)

# Ensure expected alias exists for consumer targets
if(TARGET glm::glm AND NOT TARGET glm)
    add_library(glm ALIAS glm::glm)
endif()

########################################################################
# Additional libs: ImPlot, spdlog, fmt, nlohmann_json
########################################################################
CPMAddPackage(
    NAME implot
    GITHUB_REPOSITORY epezent/implot
    GIT_TAG v0.16
)

CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    GIT_TAG v1.13.0
)

CPMAddPackage(
    NAME fmt
    GITHUB_REPOSITORY fmtlib/fmt
    GIT_TAG 11.0.2
)

CPMAddPackage(
    NAME nlohmann_json
    GITHUB_REPOSITORY nlohmann/json
    GIT_TAG v3.11.3
)
