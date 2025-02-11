cmake_minimum_required(VERSION 3.19)
project(Amazonka LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

qt_add_executable(Amazonka
    WIN32 MACOSX_BUNDLE
    main.c++
    login_window.c++
    login_window.h
    login_window.ui
    menu_window.c++
    menu_window.h
    menu_window.ui
    user.h user.c++
    edit_window.h edit_window.c++ edit_window.ui
    content.h content.c++
    add_window.h add_window.c++ add_window.ui
    zakup_window.h zakup_window.c++ zakup_window.ui
    zakup.h zakup.c++
    biblioteka_window.h biblioteka_window.c++ biblioteka_window.ui
    raport_window.h raport_window.c++ raport_window.ui


)

target_link_libraries(Amazonka
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Sql
)

qt_add_resources(Amazonka "resources"
    PREFIX "/"
    FILES resources/logo.png
)


include(GNUInstallDirs)

install(TARGETS Amazonka
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Amazonka
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
