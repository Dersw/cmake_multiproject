target_sources(${LIB}
	PRIVATE
		vector.cpp
	PUBLIC
		vector.hpp
)

target_include_directories(${LIB} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
