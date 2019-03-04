#ifndef _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#define _GITHUB_CLIENT_CPP_PASSWORD_SESSION_H_
#include <github-client/json_http_client.hpp>

namespace GithubClient {
class PasswordSession : public JsonHttpClient {
 public:
  PasswordSession(std::unique_ptr<JsonHttpClient> client,
                  const std::string& username, const std::string& password);
  virtual JsonResponse::Pointer get(const URI& uri, const Headers& headers);
  virtual JsonResponse::Pointer post(const URI& uri, const nlohmann::json& body,
                                     const Headers& headers);

 private:
  std::unique_ptr<JsonHttpClient> client_;
  const std::string username_;
  const std::string password_;
  Headers withAuth(Headers headers) const;
};
};  // namespace GithubClient
#endif
