cmake_minimum_required(VERSION 3.16)

# Project Name Version & main Languages.
project(unit-6 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(base-class.cpp   base-class.cpp)

add_executable(polymorphism     polymorphism.cpp)
add_executable(inheritance      inheritance.cpp)
add_executable(encapsulation    encapsulation.cpp)

add_executable(virtual-override     virtual-override.cpp)

add_executable(virtual-without-override     virtual-without-override.cpp)