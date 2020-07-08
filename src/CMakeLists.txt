add_executable(Fusion_View
  main.cpp
)

# Yep, that's it!
target_link_libraries(Fusion_View
  PUBLIC
    ImGui-SFML::ImGui-SFML
)

include(../cmake/Install.cmake)
