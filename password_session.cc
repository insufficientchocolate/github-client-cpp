#include "password_session.hpp"
namespace GithubClient {

PasswordSession::PasswordSession(boost::asio::io_context& io,
                                 const std::string& username,
                                 const std::string& password)
    : HttpClient(io, "https://api.github.com"),
      username_(username),
      password_(password) {}
nlohmann::json PasswordSession::get(const std::string& path,
                                    const Headers& headers) {
  return HttpClient::get(path, headers);
};

nlohmann::json PasswordSession::post(const std::string& path,
                                     const nlohmann::json& body,
                                     const Headers& headers) {
  return HttpClient::post(path, body, headers);
};
};  // namespace GithubClient