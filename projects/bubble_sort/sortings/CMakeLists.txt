target_sources(bubble_sort
    PRIVATE
        io.cpp
        io.hpp
        sortings.cpp
        sortings.hpp
)

target_include_directories(bubble_sort PRIVATE
    "${PROJECT_SOURCE_DIR}/sortings"
)
