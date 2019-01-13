#ifndef _GITHUB_CLIENT_CPP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_CLIENT_H_
#include <memory>
#include <nlohmann/json.hpp>
#include "session.hpp"

namespace GithubClient {
class Client {
 public:
  Client(const std::string& username, const std::string& password);
  Client(const std::string& oauthToken);
  Client(const Session&& session);

 private:
  std::unique_ptr<Session> session_;
};
};  // namespace GithubClient
#endif