project(vector)

set(LIB
    vector_lib
    )

add_library(${LIB} "")

add_subdirectory(src)
add_subdirectory(test)
