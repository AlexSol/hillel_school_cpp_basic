cmake_minimum_required(VERSION 3.16)

# Project Name Version & main Languages.
project(todo-list-app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(todo-list-app
    main.cpp
    MenuCLI.cpp
    MenuCLI.hpp
    Task.hpp
    TaskManager.hpp
    TaskManager.cpp
)