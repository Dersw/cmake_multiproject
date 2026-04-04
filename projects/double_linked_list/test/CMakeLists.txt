add_executable(doubly_linked_list_tests test_doubly_linked_list.cpp templates_doubly_linked_list.cpp)
target_link_libraries(doubly_linked_list_tests 
	gtest 
	${LIB}
)
add_test(doubly_linked_list_tests doubly_linked_list_tests)
