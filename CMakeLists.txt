cmake_minimum_required(VERSION 3.9)
project(Splitty)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(GTKMM gtkmm-3.0)

set(CMAKE_CXX_STANDARD 14)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

set(SOURCE_FILES Splitty.cpp view/SplitWindow.cpp view/SplitWindow.h util/Timer.cpp util/Timer.h)
add_executable(Splitty ${SOURCE_FILES})

target_link_libraries(Splitty
        ${GTKMM_LIBRARIES}  )