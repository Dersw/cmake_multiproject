cmake_minimum_required(VERSION 3.2...3.27.5)

project(cmake_multiproject)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(bubble_sort_test)
add_subdirectory(multilevel_menu)
add_subdirectory(long_numbers)
add_subdirectory(double_linked_list)
add_subdirectory(vector)

set(CMAKE_SUPPRESS_REGENERATION true)
