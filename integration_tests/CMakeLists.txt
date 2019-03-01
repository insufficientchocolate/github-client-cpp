add_executable(integration_tests main.cc)

target_link_libraries(integration_tests "${CMAKE_PROJECT_NAME}")

format(integration_tests)