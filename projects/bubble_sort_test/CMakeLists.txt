project(bubble_sort_test)

set (LIB
    bubble_sort_lib
)

add_library(${LIB} "")

add_subdirectory(src)
add_subdirectory(test)
