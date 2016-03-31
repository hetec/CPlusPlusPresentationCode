cmake_minimum_required(VERSION 3.4)
project(CodeCPlusPlus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp InfoHidingObject/Grid.h InfoHidingObject/OpenGrid.h)
add_executable(CodeCPlusPlus ${SOURCE_FILES})