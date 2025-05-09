cmake_minimum_required(VERSION 3.31)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/c++.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/c++.exe")

project(dzienniczek VERSION 0.1.0 LANGUAGES C CXX)

add_executable(dzienniczek
    lista_zadan.cpp
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)


add_subdirectory(tests)