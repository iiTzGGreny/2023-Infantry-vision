cmake_minimum_required(VERSION 3.5)

project(Infantry-autoaim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")




FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Threads)
FIND_PACKAGE(Eigen3 REQUIRED)

INCLUDE_DIRECTORIES(
           "include"
           "include/Armor"
           "include/ImageProgress"
           "include/Const"

           ${OPENCV_INCLUDE_DIRECTORIES}
           ${Eigen_INCLUDE_DIRECTORIES}
                    )

FILE(GLOB_RECURSE sourcefiles "src/*.cpp")
ADD_EXECUTABLE(Infantry-autoaim ${sourcefiles})

target_link_libraries(Infantry-autoaim ${OpenCV_LIBS})








