project(double_linked_list)

set(LIB
    double_linked_list_lib
    )

add_library(${LIB} "")

add_subdirectory(src)
add_subdirectory(test)
