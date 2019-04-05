include(FindGTest)

add_executable(tests test_main.cpp event_test.cpp event_queue_test.cpp)

target_link_libraries( tests pthread)
target_link_libraries( tests gtest gtest_main)

target_link_libraries(tests Core)

gtest_discover_tests(tests)
#add_test(NAME test COMMAND tests)
