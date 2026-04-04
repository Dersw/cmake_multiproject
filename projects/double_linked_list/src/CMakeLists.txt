target_sources(${LIB}
	PRIVATE
		doubly_linked_list.cpp
	PUBLIC
		doubly_linked_list.hpp
)

target_include_directories(${LIB} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
