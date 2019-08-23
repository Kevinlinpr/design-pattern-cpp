cmake_minimum_required(VERSION 3.12)
project(CPP17)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP17 main.cpp Builder.cpp Car.cpp CarFactory.cpp)