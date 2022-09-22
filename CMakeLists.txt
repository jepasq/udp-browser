cmake_minimum_required(VERSION 3.1.0)

project(udp-browser VERSION 0.0.0 LANGUAGES CXX)
set(REVISION 5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/Doxyfile.in"
  "${PROJECT_BINARY_DIR}/Doxyfile"
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(FindPkgConfig)
pkg_check_modules(LIBS REQUIRED libarchive)

find_package(Qt5 COMPONENTS Widgets WebView REQUIRED)

# The main library (at least used by editor)
add_library(udpb SHARED
  src/lib/ConfigReader.cpp
  src/lib/FileArchiver.cpp
  src/lib/FileCompressor.cpp
  src/lib/Preferences.cpp
  src/lib/Serializer.cpp
  src/lib/User.cpp
  src/lib/WebContent.cpp
  src/lib/WebFile.cpp

  src/lib/faLibarchive.cpp
  )

target_link_libraries(udpb Qt5::Widgets)

# Shared both main rule and unit tests editor sources
# Do not contain main.cpp to avoid multiple definitions of main()
set(BROWSER_SRC
  src/browser/main.cpp
  src/browser/MainWindow.cpp
  src/browser/PreferencesDialog.cpp
  
  src/browser/ui/MainWindow.ui
  src/browser/ui/PreferencesDialog.ui

  media/resources.qrc
)
add_executable(udp-browser ${BROWSER_SRC}) 
target_link_libraries(udp-browser ${LIBS_LIBRARIES} udpb Qt5::Widgets)
target_include_directories(udp-browser PUBLIC src/lib  ${PROJECT_BINARY_DIR})

# Unit tests
find_package(Boost COMPONENTS unit_test_framework REQUIRED) # filesystem system 
add_executable(tests src/tests.cpp
  #  ${BROWSER_SRC}
  src/lib/FileCompressor_Test.cpp
  src/lib/Preferences_Test.cpp
  src/lib/User_Test.cpp
  src/lib/WebContent_Test.cpp

  src/lib/faLibarchive_Test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES} ${LIBS_LIBRARIES}
  udpb Qt5::Widgets)
add_custom_target(check COMMAND tests) # Add the `make check` command
