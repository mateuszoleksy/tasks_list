enable_testing()

add_executable(unit_tests
        unit_test.cpp
)

target_link_libraries(unit_tests
        GTest::gtest
        GTest::gtest_main
)

add_test(NAME unit_tests COMMAND unit_tests)