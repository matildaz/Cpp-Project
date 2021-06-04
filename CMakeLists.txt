# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Cpp Project")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/Catch.cmake)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)

enable_testing()
add_subdirectory(external/doctest)
# Подключение библиотеки nana
# add_subdirectory(nana EXCLUDE_FROM_ALL)
# target_compile_definitions(nana PUBLIC NANA_ENABLE_PNG NANA_ENABLE_JPEG)
# target_link_libraries(nana PUBLIC CONAN_PKG::libpng CONAN_PKG::libjpeg)