cmake_minimum_required(VERSION 3.28)
project(Test_catch)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(test-unit)

add_executable(Laba3 main.cpp src/ComplexNum/ComplexNum.cpp)

add_executable(Test_catch
test-unit/catch.hpp
test-unit/test.cpp
        src/ComplexNum/ComplexNum.h
        src/ComplexNum/ComplexNum.cpp)

