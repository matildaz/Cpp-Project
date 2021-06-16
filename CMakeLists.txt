# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Cpp Project")

set(SFML_DIR "C:/Users/asis/Desktop/SFML-2.5.1/lib/cmake/SFML") # you have to change the direction

enable_testing()
add_subdirectory(external/doctest)
find_package(SFML REQUIRED system window graphics network)
add_executable(testlib "the_game/theGame.cpp" "the_game/theGame_tests.cpp")
target_link_libraries(testlib sfml-graphics sfml-window sfml-system)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/Catch.cmake)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)