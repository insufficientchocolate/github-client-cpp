#include "password_session.hpp"
namespace GithubClient {
nlohmann::json PasswordSession::get(const std::string& path) {
  return nlohmann::json{};
}
nlohmann::json PasswordSession::post(const std::string& path,
                                     const nlohmann::json& body) {
  return nlohmann::json{};
}
};  // namespace GithubClient