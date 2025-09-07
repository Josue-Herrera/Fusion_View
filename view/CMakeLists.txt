project(Fusion_View)

find_package(OpenGL REQUIRED)

# New organized sources
set(app_sources
    app/main.cc
    app/fusion_view.cc
    app/fusion_imgui.cc
)

set(panel_sources
    panels/gui_stack.cc
    panels/main_menu.cc
    panels/imgui_helper.cc
)

set(core_sources
    include/core/timebase.h
    include/core/topic_store.h
    include/core/registry.h
    include/app/app_context.h
    include/types/messages.h
    include/render/renderer.h
    include/transport/source.h
)

set(headers
    include/app/fusion_imgui.h
    include/app/fusion_view.h
    include/panels/gui_layer.h
    include/panels/gui_stack.h
    include/panels/main_menu.h
    include/panels/components.h
    include/panels/imgui_helper.h
)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "Fusion_View")
add_executable(Fusion_View ${app_sources} ${panel_sources} ${core_sources} ${headers})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${OPENGL_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${OPENGL_gl_LIBRARY}
        glfw
        glad
        ImGui
        spdlog::spdlog
        fmt::fmt
        nlohmann_json::nlohmann_json
        glm
    PRIVATE
        fv::Resources
)

if(TARGET implot)
    target_link_libraries(${PROJECT_NAME} PUBLIC implot)
endif()
