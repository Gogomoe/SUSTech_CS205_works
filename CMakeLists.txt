cmake_minimum_required(VERSION 3.15)
project(works)

set(CMAKE_CXX_STANDARD 14)

add_executable(works main.cpp)

add_executable(exercise01_main exercise01/main.cpp)
add_executable(exercise01_smile exercise01/smile.cpp)

add_executable(exercise02_E1 exercise02/E1.cpp)
add_executable(exercise02_E2 exercise02/E2.cpp)
add_executable(exercise02_E3 exercise02/E3.cpp)