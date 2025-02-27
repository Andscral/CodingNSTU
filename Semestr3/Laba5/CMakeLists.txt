cmake_minimum_required(VERSION 3.28)
project(Laba5)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(test-unit)

add_executable(Laba5 main.cpp
        src/List/List.cpp
        src/List/List.h
        src/ComplexLife/ComplexLife.cpp
        src/ComplexStr/ComplexStr.h
        src/ComplexStr/ComplexStr.cpp
        src/ComplexLife/ComplexLife.h
        src/ComplexNum/ComplexNum.cpp
        src/ComplexNum/ComplexNum.h
)

add_executable(Tests test-unit/catch.hpp
        test-unit/test.cpp
        src/List/List.h
        src/List/List.cpp
        src/ComplexNum/ComplexNum.h
        src/ComplexNum/ComplexNum.cpp
        src/ComplexStr/ComplexStr.h
        src/ComplexStr/ComplexStr.cpp)

