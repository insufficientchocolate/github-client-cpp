#ifndef _GITHUB_CLIENT_CPP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_CLIENT_H_
#include <memory>
#include <nlohmann/json.hpp>
#include "json_http_client.hpp"

namespace GithubClient {
class Client {
 public:
  static std::unique_ptr<Client> login(const std::string& username,
                                       const std::string& password);
  static std::unique_ptr<Client> oauth(const std::string& oauthToken);
  Client(const JsonHttpClient&& session);

 private:
  std::unique_ptr<JsonHttpClient> session_;
};
};  // namespace GithubClient
#endif