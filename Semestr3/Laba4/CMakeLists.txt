cmake_minimum_required(VERSION 3.28)
project(Laba4)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(test-unit)

add_executable(Laba4 main.cpp src/ComplexNum/ComplexNum.cpp
        src/ComplexNum/ComplexNum.h
        src/ComplexStr/ComplexStr.cpp
        src/ComplexStr/ComplexStr.h
        src/ComplexLife/ComplexLife.cpp
        src/ComplexLife/ComplexLife.h
        src/List/List.cpp
        src/List/List.h
)

add_executable(Test_catch
        test-unit/catch.hpp
        test-unit/test.cpp
        src/ComplexNum/ComplexNum.cpp
        src/ComplexNum/ComplexNum.h
        src/ComplexStr/ComplexStr.cpp
        src/ComplexStr/ComplexStr.h
        src/ComplexLife/ComplexLife.cpp
        src/ComplexLife/ComplexLife.h
        src/List/List.cpp
        src/List/List.h)

