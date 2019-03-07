#include <github-client/client.hpp>
#include <CLI/CLI.hpp>
#include "followers.hpp"

int main(int argc,char** argv) {
  CLI::App app("github client","git-hub");
  FollowerCommand{app.add_subcommand("followers")};
  CLI11_PARSE(app, argc, argv);
  return 0;
}
