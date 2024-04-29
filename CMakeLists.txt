cmake_minimum_required(VERSION 3.27)
project(C___Assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(C___Assignment main.cpp
        Patient.h
        Medicine.h
        SystemAdministrator.cpp
        SystemAdministrator.h
        Medicine.cpp)
