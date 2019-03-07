#include "followers.hpp"
#include <string>
#include <github-client/client.hpp>

static std::unique_ptr<GithubClient::Client> askLogin() {
  std::string username, password;
  std::cout << "Github username:" << std::endl;
  std::cin >> username;
  password = getpass("password:");
  return GithubClient::Client::login(username, password);
}

FollowerCommand::FollowerCommand(CLI::App* app) {
  app->add_option("username",username_,"optional username");
  app->callback([this]{
	auto client = askLogin();
	std::vector<GithubClient::Follower> followers;
	if (username_.empty()) {
	 followers = client->listFollowers();
	} else {
	  followers = client->listFollowers(username_);
	  }
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
}
