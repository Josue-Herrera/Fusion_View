project(Fusion_View)

find_package(OpenGL REQUIRED)

set(source 
main.cc
src/fusion_view.cc
src/fusion_imgui.cc
src/gui_stack.cc
src/main_menu.cc
include/fusion_imgui.h
include/fusion_view.h
include/gui_layer.h
include/gui_stack.h
include/main_menu.h
include/components.h
)

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "Fusion_View" )
add_executable(Fusion_View ${source} )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${OPENGL_INCLUDE_DIR}
        include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${OPENGL_gl_LIBRARY}
        glfw
        glad
        ImGui
        glm
)