cmake_minimum_required(VERSION 3.10)
project(gst_src)

if(MSVC)
    message(STATUS "MSVC DEFINED")
    message(STATUS $ENV{OPENCV_MSVC_DIR})
    find_package(OpenCV REQUIRED PATHS $ENV{OPENCV_MSVC_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCV REQUIRED)
endif()

include_directories( ${OpenCV_INCLUDE_DIRS} .)
add_library(gst_src gst_src.cpp)
add_executable(main main.cpp)

if(MSVC)
    target_link_libraries( ${OpenCV_MSVC_LIBS})
    message(STATUS "MSVC LIBS LINKED.")
else()
    target_link_libraries(main ${OpenCV_LIBS} gst_src)
    target_link_libraries(gst_src ${OpenCV_LIBS})

endif()

set_property(TARGET main PROPERTY CXX_STANDARD 17)