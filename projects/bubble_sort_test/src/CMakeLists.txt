
target_sources(${LIB}
    PRIVATE
        io.cpp
        sortings.cpp
    PUBLIC
        io.hpp
        sortings.hpp
)

target_include_directories(${LIB} PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)
