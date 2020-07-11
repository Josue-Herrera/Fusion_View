set (SOURCE_FILES main.cpp)

add_executable(Fusion_View
  ${SOURCE_FILES}
)

# Yep, that's it!
target_link_libraries(Fusion_View PUBLIC ImGui-SFML::ImGui-SFML)

include(../cmake/Install.cmake)
