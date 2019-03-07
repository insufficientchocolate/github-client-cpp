#ifndef _GIT_HUB_FOLLOWERS_HPP_
#define _GIT_HUB_FOLLOWERS_HPP_
#include <CLI/CLI.hpp>
#include <string>

class FollowerCommand {
  public:
	FollowerCommand(CLI::App* app);
  private:
	std::string username_;
};
#endif
