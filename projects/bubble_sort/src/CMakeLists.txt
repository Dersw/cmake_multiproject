project(bubble_sort)

target_include_directories(bubble_sort_lib PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

add_subdirectory(sortings)
