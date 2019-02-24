#ifndef _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#define _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#include <github-client/json_http_client.hpp>

namespace GithubClient {
class PasswordSession : public JsonHttpClient {
 public:
  PasswordSession(const std::string& username, const std::string& password)
      : username_(username), password_(password) {}
  nlohmann::json get(const std::string& path);
  nlohmann::json get(const std::string& path, JsonHttpClient::Headers headers);
  nlohmann::json post(const std::string& path, const nlohmann::json& body);
  nlohmann::json post(const std::string& path, const nlohmann::json& body,
                      JsonHttpClient::Headers headers);

 private:
  const std::string username_;
  const std::string password_;
};
};  // namespace GithubClient
#endif