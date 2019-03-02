#ifndef _GITHUB_CLIENT_CPP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_CLIENT_H_
#include <memory>
#include <nlohmann/json.hpp>
#include <vector>
#include "follower.hpp"
#include "json_http_client.hpp"

namespace GithubClient {
class Client {
  typedef std::function<std::unique_ptr<JsonHttpClient>(
      boost::asio::io_context&)>
      AsioBasedClientFactory;

 public:
  static std::unique_ptr<Client> login(const std::string& username,
                                       const std::string& password);
  static std::unique_ptr<Client> oauth(const std::string& oauthToken);
  Client(JsonHttpClient* client);
  Client(AsioBasedClientFactory factory);
  std::vector<Follower> listFollowers();
  std::vector<Follower> listFollowers(const std::string& username);

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
};  // namespace GithubClient
#endif
