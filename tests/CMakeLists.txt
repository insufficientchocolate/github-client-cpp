add_executable(unit_test
    uri_test.cc
    base64_test.cc
    asio_thread_pool.test.cc)

target_link_libraries(unit_test GTest::gtest GTest::main "${CMAKE_PROJECT_NAME}")

gtest_discover_tests(unit_test)

format(unit_test)