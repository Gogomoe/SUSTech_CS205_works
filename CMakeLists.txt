cmake_minimum_required(VERSION 3.15)
project(works)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(works main.cpp)

add_executable(exercise01_main exercise01/main.cpp)
add_executable(exercise01_smile exercise01/smile.cpp)

add_executable(exercise02_E1 exercise02/E1.cpp)
add_executable(exercise02_E2 exercise02/E2.cpp)
add_executable(exercise02_E3 exercise02/E3.cpp)

add_executable(assignment01_main assignment01/main.cpp)

add_executable(exercise03_main exercise03/main.cpp)

add_executable(exercise04_main exercise04/main.cpp)
add_executable(exercise05_main exercise05/main.cpp)

add_executable(assignment02_main assignment02/main.cpp)

add_executable(exercise06_E1 exercise06/E1.cpp)
add_executable(exercise06_E2 exercise06/E2.cpp)
add_executable(exercise06_E3 exercise06/E3.cpp)

add_executable(exercise07_E1 exercise07/E1.cpp)
add_executable(exercise07_E2 exercise07/E2.cpp)
add_executable(exercise07_E3 exercise07/E3.cpp)

add_executable(assignment03_A1 assignment03/A1.cpp)
add_executable(assignment03_A2 assignment03/A2.cpp)
add_executable(assignment03_A3 assignment03/A3.cpp assignment03/utf8.c assignment03/utf8.h)

add_executable(exercise08_E1 exercise08/E1.cpp)
add_executable(exercise08_E2 exercise08/E2.cpp)

add_executable(assignment04_A1 assignment04/A1.cpp)
add_executable(assignment04_A4 assignment04/A4.cpp)
add_executable(assignment04_A5 assignment04/A5.cpp)

add_executable(midterm_Q1 midterm/11811712_question1.cpp)
add_executable(midterm_Q3 midterm/11811712_question3.cpp)
add_executable(midterm_Q4 midterm/11811712_question4.cpp)

add_executable(assignment05 assignment05/UTF8string.cpp assignment05/testUTF8string.cpp assignment05/utf8.c)

add_executable(exercise11_main exercise11/main.cpp)

add_executable(exercise12_main exercise12/main.cpp exercise12/Complex.cpp exercise12/Number.cpp)

add_executable(exercise13_main exercise13/main.cpp)
