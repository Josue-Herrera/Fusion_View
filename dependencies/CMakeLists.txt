########################################################################
# Adding GLFW to Framework
########################################################################
set(GLFW_LIB_NAME "glfw")
set(GLFW_INC_PATH ${GLFW_LIB_NAME}/include)

set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#set(GLFW_VULKAN_STATIC  OFF CACHE BOOL "" FORCE)    # OFF by default
#set(BUILD_SHARED_LIBS   OFF CACHE BOOL "" FORCE)    # OFF by default
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)

add_subdirectory(${GLFW_LIB_NAME})


########################################################################
# Adding glad to Framework
########################################################################
set(GLAD_LIB_NAME "glad") 
set(GLAD_SRC_PATH "${GLAD_LIB_NAME}/src")
set(GLAD_INC_PATH "${GLAD_LIB_NAME}/include")

add_library( ${GLAD_LIB_NAME}
    STATIC
        "${GLAD_SRC_PATH}/glad.c"
)
target_include_directories(${GLAD_LIB_NAME}
    PUBLIC
        "${GLAD_INC_PATH}"
)

set_target_properties(${GLAD_LIB_NAME} PROPERTIES FOLDER "Glad_Imgui")

########################################################################
# Adding imgui to Framework
########################################################################
set(IMGUI_LIB_NAME "ImGui")
set(IMGUI_ADDONS "imgui_addons")
set (FREETYPE_LIB_NAME "freetype")


set(IMGUI_SOURCES
    "${IMGUI_LIB_NAME}/imgui.cpp"
    "${IMGUI_LIB_NAME}/imgui_demo.cpp"
    "${IMGUI_LIB_NAME}/imgui_draw.cpp"
    "${IMGUI_LIB_NAME}/imgui_widgets.cpp"
    "${IMGUI_LIB_NAME}/examples/imgui_impl_glfw.cpp"
    "${IMGUI_LIB_NAME}/examples/imgui_impl_opengl3.cpp"
    "${IMGUI_LIB_NAME}/misc/freetype/imgui_freetype.cpp"
)

set(IMGUI_HEADERS
    "${IMGUI_LIB_NAME}/imconfig.h"
    "${IMGUI_LIB_NAME}/imgui.h"
    "${IMGUI_LIB_NAME}/imgui_internal.h"
    "${IMGUI_LIB_NAME}/imstb_rectpack.h"
    "${IMGUI_LIB_NAME}/imstb_textedit.h"
    "${IMGUI_LIB_NAME}/imstb_truetype.h"
    "${IMGUI_LIB_NAME}/examples/imgui_impl_glfw.h"
    "${IMGUI_LIB_NAME}/examples/imgui_impl_opengl3.h"
    "${IMGUI_LIB_NAME}/misc/freetype/imgui_freetype.h"
   
 #external_addons
    "${IMGUI_ADDONS}/stb_image.h"
)

set(IMGUI_INC_PATH "${IMGUI_LIB_NAME}/")
set(IMGUI_ADDONS_PATH "${IMGUI_ADDONS}/")

add_library(${IMGUI_LIB_NAME} 
    STATIC
        ${IMGUI_SOURCES}
        ${IMGUI_HEADERS}
)

target_compile_definitions(${IMGUI_LIB_NAME}
    PRIVATE
        IMGUI_IMPL_OPENGL_LOADER_GLAD=1
)

target_include_directories(${IMGUI_LIB_NAME}
    PUBLIC
        "${IMGUI_INC_PATH}"
        "${IMGUI_ADDONS_PATH}"
        "${GLFW_INC_PATH}"
        "${GLAD_INC_PATH}"
        "${FREETYPE_LIB_NAME}/include/"
)

target_link_libraries(${IMGUI_LIB_NAME} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/freetype/win64/freetype.lib 
)

set_target_properties(${IMGUI_LIB_NAME} PROPERTIES FOLDER "Glad_Imgui")