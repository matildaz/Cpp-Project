cmake_minimum_required(VERSION 3.10.0)
project(the game CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(theGame_test.cpp)