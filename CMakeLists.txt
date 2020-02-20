cmake_minimum_required(VERSION 3.15)
project(Finy_string)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(Finy_string src/String.cpp src/Test.cpp main.cpp)
