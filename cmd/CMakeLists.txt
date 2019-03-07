project(git-hub)

hunter_add_package(CLI11)
hunter_add_package(libgit2)

find_package(CLI11 CONFIG REQUIRED)
find_package(libgit2 CONFIG REQUIRED)

add_executable("${PROJECT_NAME}"
  main.cc
  followers.hpp
  followers.cc)
target_link_libraries("${PROJECT_NAME}" "${CMAKE_PROJECT_NAME}" CLI11::CLI11)
