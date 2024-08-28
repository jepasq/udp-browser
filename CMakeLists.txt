cmake_minimum_required(VERSION 3.5.0)

project(udp-browser VERSION 0.0.1 LANGUAGES CXX)
set(REVISION 18)

set(CMAKE_BUILD_TYPE Debug)

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
  "${PROJECT_SOURCE_DIR}/udp-browser.qhc.in"
  "${PROJECT_BINARY_DIR}/udp-browser.qhc"
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

find_package(Qt5 COMPONENTS Widgets WebView WebEngineWidgets REQUIRED)

# The main library (at least used by editor)
add_library(udpb SHARED
  src/lib/ConfigReader.cpp
  src/lib/FileArchiver.cpp
  src/lib/FileCompressor.cpp
  src/lib/History.cpp
  src/lib/NetworkNode.cpp
  src/lib/Preferences.cpp
  src/lib/Serializer.cpp
  src/lib/User.cpp
  src/lib/WebContent.cpp
  src/lib/WebFile.cpp
  src/lib/WebTable.cpp

  src/lib/faLibarchive.cpp
  )

target_link_libraries(udpb ${LIBS_LIBRARIES} Qt5::Widgets Qt5::WebEngineWidgets)

# Shared both main rule and unit tests
# Do not contain main.cpp to avoid multiple definitions of main() when linking
# tests
set(BROWSER_SRC
  src/browser/MainWindow.cpp
  src/browser/PreferencesDialog.cpp

  src/browser/SpecialPage.cpp
  src/browser/spAbout.cpp
  src/browser/spHistory.cpp
  
  src/browser/ui/MainWindow.ui
  src/browser/ui/PreferencesDialog.ui

  media/resources.qrc
)
add_executable(udp-browser ${BROWSER_SRC} src/browser/main.cpp) 
target_link_libraries(udp-browser ${LIBS_LIBRARIES} udpb Qt5::Widgets)
target_include_directories(udp-browser PUBLIC src/lib  ${PROJECT_BINARY_DIR})

# Unit tests
enable_testing()
find_package(Boost COMPONENTS unit_test_framework REQUIRED) # filesystem system 
add_executable(tests src/tests.cpp
  ${BROWSER_SRC}
  src/lib/FileCompressor_Test.cpp
  src/lib/NetworkNode_Test.cpp
  src/lib/Preferences_Test.cpp
  src/lib/User_Test.cpp
  src/lib/WebContent_Test.cpp
  src/lib/WebFile_Test.cpp
  src/lib/WebTable_Test.cpp

  src/browser/SpecialPage_Test.cpp
  
  src/lib/faLibarchive_Test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES} ${LIBS_LIBRARIES}
  udpb Qt5::Widgets)
target_include_directories(tests PUBLIC src/lib  ${PROJECT_BINARY_DIR})
add_custom_target(check COMMAND tests) # Add the `make check` command
add_test(NAME tests COMMAND test)
