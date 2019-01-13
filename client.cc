#include <curl/curl.h>
#include <github-client/client.hpp>
#include <sstream>
#include "password_session.hpp"

namespace GithubClient {
Client::Client(const std::string& username, const std::string& password)
    : session_(std::make_unique<PasswordSession>(username, password)) {}
};  // namespace GithubClient
