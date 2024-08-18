cmake_minimum_required(VERSION 3.29)

project(minimal_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS OpenGLWidgets)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)

# set(Boost_DIR C:/D/Apps/MyOpenSource/O3DEFlightSimulation/Open3DE-ExtSimInt-Gem/examples/minimal_app/build/Desktop_Qt_6_7_2_MSVC2019_64bit-Debug/_deps/boost-src)

# find_package(boost
#   1.84.0                 # Minimum version
#   COMPONENTS "interprocess" # Boost libraries by their canonical name # e.g. "date_time" for "libboost_date_time"
#   # [OPTIONAL_COMPONENTS <libs>...] # Optional Boost libraries by their canonical name)
#   PATHS ${CMAKE_CURRENT_SOURCE_DIR}/build/Desktop_Qt_6_7_2_MSVC2019_64bit-Debug/_deps/boost-src
#   NO_DEFAULT_PATH
#   )

# message(STATUS "PWD = ${CMAKE_CURRENT_SOURCE_DIR}")

# if(Boost_FOUND)
#     include_directories(${Boost_INCLUDE_DIRS})
#     message(STATUS "Boost library already installed")
# else()
    # message(STATUS "Boost library not installed, using public git repo")

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# set(CMAKE_POLICY_DEFAULT_CMP0135 OLD)
FetchContent_Declare(
    Boost
    # URL "https://archives.boost.io/release/1.85.0/source/boost_1_85_0.zip" НЕ ПОДХОДИТ, Т.К. НЕТ CMakeLists.txt
    URL https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.7z
    DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/boost_download
    # DOWNLOAD_EXTRACT_TIMESTAMP ON
    # OVERRIDE_FIND_PACKAGE

    # GIT_REPOSITORY "https://github.com/boostorg/boost.git"
    # GIT_TAG "boost-1.85.0"
    # GIT_PROGRESS ON
    # GIT_SHALLOW ON

    OVERRIDE_FIND_PACKAGE
)
    # URL "https://github.com/boostorg/boost/releases/download/boost-1.85.0/boost-1.85.0-cmake.7z"
    # too much, >1.5Gb if fetching by git
    # GIT_REPOSITORY "https://github.com/boostorg/boost.git"
    # GIT_TAG "boost-1.85.0"
    # GIT_PROGRESS ON
    # GIT_SHALLOW ON
    # OVERRIDE_FIND_PACKAGE
    # FIND_PACKAGE_ARGS



# # add_library(boost INTERFACE)
message(STATUS "*** Boost_FOUND = ${Boost_FOUND}")
# message(STATUS "*** Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
# message(STATUS "*** Boost_SOURCE_DIR = ${Boost_SOURCE_DIR}")
FetchContent_MakeAvailable(Boost)

find_package(Boost
    REQUIRED
    COMPONENTS interprocess)

# if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
# message(STATUS "Boost library already installed")
# else()
# message(STATUS "Boost library downloaded from git and installed to ${Boost_SOURCE_DIR}")

# endif()

# add_library(Boost INTERFACE)
# target_include_directories(Boost INTERFACE {Boost_INCLUDE_DIRS} )
# target_include_directories(boost INTERFACE ${Boost_INCLUDE_DIRS})
# target_include_directories(boost INTERFACE ${Boost_SOURCE_DIR})
# message(STATUS "*** Boost_SOURCE_DIR = ${Boost_SOURCE_DIR}")


set(PROJECT_SOURCES
        main.cpp
        mainwindow.h    mainwindow.cpp
        mainwindow.ui
        translatestatevectorthread.h    translatestatevectorthread.cpp
        receivevideothread.h            receivevideothread.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(minimal_app
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET minimal_app APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(minimal_app SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(minimal_app
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(minimal_app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(minimal_app PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(minimal_app PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
target_link_libraries(minimal_app PRIVATE Boost::interprocess)
include_directories(${Boost_INCLUDE_DIRS})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.app)
endif()
set_target_properties(minimal_app PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS minimal_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(minimal_app)
endif()
