#include "password_session.hpp"
#include "base64.hpp"

namespace GithubClient {

PasswordSession::PasswordSession(std::unique_ptr<JsonHttpClient> client,
                                 const std::string& username,
                                 const std::string& password)
    : client_(std::move(client)), username_(username), password_(password) {}
JsonResponse::Pointer PasswordSession::get(const URI& uri,
                                           const Headers& headers) {
  return client_->get(uri, withAuth(headers));
};

JsonResponse::Pointer PasswordSession::post(const URI& uri,
                                            const nlohmann::json& body,
                                            const Headers& headers) {
  return client_->post(uri, body, withAuth(headers));
};

Headers PasswordSession::withAuth(Headers headers) const {
  headers["Authorization"] =
      "Basic " + Base64::encode(username_ + ":" + password_);
  return headers;
}

};  // namespace GithubClient
