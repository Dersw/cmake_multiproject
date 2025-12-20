cmake_minimum_required(VERSION 3.2...3.27.5)

project(cmake_multiproject)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(bubble_sort_test)
add_subdirectory(multilevel_menu)

set(CMAKE_SUPPRESS_REGENERATION true)
