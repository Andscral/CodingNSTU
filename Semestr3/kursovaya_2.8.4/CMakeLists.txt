cmake_minimum_required(VERSION 3.28)
project(kursovaya_2_8_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(kursovaya_2_8_4 main.cpp
        src/List/StudentList.cpp
        src/List/StudentList.h
        src/Student/Student.h
)
