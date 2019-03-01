#include "password_session.hpp"
#include "base64.hpp"

namespace GithubClient {

PasswordSession::PasswordSession(std::unique_ptr<JsonHttpClient> client,
                                 const std::string& username,
                                 const std::string& password)
    : client_(std::move(client)), username_(username), password_(password) {}
nlohmann::json PasswordSession::get(const std::string& path,
                                    const Headers& headers) {
  return client_->get(path, withAuth(headers));
};

nlohmann::json PasswordSession::post(const std::string& path,
                                     const nlohmann::json& body,
                                     const Headers& headers) {
  return client_->post(path, body, withAuth(headers));
};

Headers PasswordSession::withAuth(Headers headers) const {
  headers.insert("Authorization", Base64::encode(username_ + ":" + password_));
  return headers;
}

};  // namespace GithubClient