#ifndef _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#define _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#include <github-client/session.hpp>

namespace GithubClient {
class PasswordSession : public Session {
 public:
  PasswordSession(const std::string& username, const std::string& password)
      : username_(username), password_(password) {}
  nlohmann::json get(const std::string& path) const;
  nlohmann::json post(const std::string& path,
                      const nlohmann::json& body) const;

 private:
  const std::string username_;
  const std::string password_;
};
};  // namespace GithubClient
#endif