add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)

add_executable(queuea_doctest queuea_doctest.cpp)
target_link_libraries(queuea_doctest queuea)

add_executable(stackl_doctest stackl_doctest.cpp)
target_link_libraries(stackl_doctest stackl)