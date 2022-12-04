cmake_minimum_required(VERSION 3.5)

project(Infantry-autoaim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



FIND_PACKAGE(OpenCV 4 REQUIRED)
FIND_PACKAGE(Threads)
FIND_PACKAGE(Eigen3 REQUIRED)

INCLUDE_DIRECTORIES(
           "include"
                    )

FILE(GLOB_RECURSE LibFiles "include/*.hpp")
add_custom_target(headers SOURCES ${LibFiles})


FILE(GLOB_RECURSE sourcefiles "src/*.cpp")
add_executable(Infantry-autoaim ${sourcefiles})






