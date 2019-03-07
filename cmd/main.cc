#include <github-client/client.hpp>
#include <CLI/CLI.hpp>
#include <iostream>
#include <string>
// FIXME: support Windows
#include <unistd.h>

int main(int argc,char** argv) {
  CLI::App app("github client","git-hub");
  app.add_subcommand("followers")->callback([]{
	std::string username, password;
	std::cout << "Github username:" << std::endl;
	std::cin >> username;
	password = getpass("password:");
	auto client = GithubClient::Client::login(username, password);
	std::vector<GithubClient::Follower> followers = client->listFollowers();
	size_t count = followers.size();
	if (count <= 0) {
	  std::cout << "Currently, you have no follower." << std::endl;
	  return;
	}
	std::cout << "You have " << followers.size() << " followers:" << std::endl;
	for(auto const& f : followers) 
	{
	  std::cout << f.username << std::endl;
	}
  });
  CLI11_PARSE(app, argc, argv);
  return 0;
}
