#ifndef _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#define _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#include <github-client/json_http_client.hpp>
#include "http_client.hpp"

namespace GithubClient {
class PasswordSession : public HttpClient {
 public:
  PasswordSession(boost::asio::io_context& io, const std::string& username,
                  const std::string& password);
  virtual nlohmann::json get(const std::string& path,
                             const Headers& headers) override;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body,
                              const Headers& headers) override;

 private:
  const std::string username_;
  const std::string password_;
};
};  // namespace GithubClient
#endif