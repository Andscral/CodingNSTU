cmake_minimum_required(VERSION 3.28)
project(Laba7)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(test-unit)

add_executable(Laba7 main.cpp
        src/List.h
        src/ComplexNum.cpp
        src/ComplexNum.h
        src/ComplexNum.cpp)

#[[add_executable(Tests test-unit/catch.hpp
        test-unit/test.cpp
        src/List/List.h
        src/ComplexNum/ComplexNum.h
        src/ComplexNum/ComplexNum.cpp
        src/ComplexStr/ComplexStr.h
        src/ComplexStr/ComplexStr.cpp)]]
