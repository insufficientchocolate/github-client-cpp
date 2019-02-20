#include <curl/curl.h>
#include <github-client/client.hpp>
#include <sstream>
#include "password_session.hpp"

namespace GithubClient {
std::unique_ptr<Client> Client::login(const std::string& username,
                                      const std::string& password) {
  return std::make_unique<Client>(PasswordSession(username, password));
}

std::unique_ptr<Client> Client::oauth(const std::string& oauthToken) {
  throw "not implemented yet";
}
};  // namespace GithubClient
