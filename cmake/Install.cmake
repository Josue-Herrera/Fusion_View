include(GNUInstallDirs)

install(TARGETS Fusion_View
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(SCRIPT PostInstall.cmake)

include(CPack)
