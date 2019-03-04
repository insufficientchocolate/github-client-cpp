cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(HunterGate)

HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.89.tar.gz"
  SHA1 "a370290a8b32987755a36d64807bf8c7f5b61730"
  LOCAL
)

project(github-client-cpp)

hunter_add_package(OpenSSL)
hunter_add_package(Boost)
hunter_add_package(nlohmann_json)
hunter_add_package(GTest)

find_package(Boost CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
# added by GTest package
find_package(GMock CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)



add_library(
  "${CMAKE_PROJECT_NAME}" include/github-client/client.hpp
  include/github-client/json_http_client.hpp
  include/github-client/uri.hpp
  include/github-client/errors/illegal_uri_exception.hpp
  include/github-client/follower.hpp
  include/github-client/headers.hpp
  include/github-client/json_response.hpp
  errors/illegal_uri_exception.cc
  client.cc
  http_client.hpp
  http_client.cc
  uri.cc
  password_session.hpp
  password_session.cc
  cert.hpp
  connection.hpp
  connection.cc
  base64.hpp
  base64.cc
  asio_thread_pool.cc
  asio_thread_pool.hpp
  follower_ns.hpp
  simple_json_response.hpp
  simple_json_response.cc
)

target_link_libraries(
    "${CMAKE_PROJECT_NAME}"
    Boost::boost
    nlohmann_json::nlohmann_json
    OpenSSL::SSL
)

target_include_directories(
  "${CMAKE_PROJECT_NAME}"
  PUBLIC
  $<BUILD_INTERFACE: include>
  $<BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE: include>
)

include(clang_format)
format("${CMAKE_PROJECT_NAME}")

enable_testing()
include(GoogleTest)

add_subdirectory(tests)

include(GNUInstallDirs)

install(TARGETS "${PROJECT_NAME}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

# install public headers
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

add_subdirectory(cmd)

