project(Fusion_View)

find_package(OpenGL REQUIRED)

set(source 
main.cc
src/fusion_view.cc
src/fusion_imgui.cc
include/fusion_imgui.h
include/fusion_view.h
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