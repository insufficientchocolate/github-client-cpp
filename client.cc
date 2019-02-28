#include <curl/curl.h>
#include <github-client/client.hpp>
#include <sstream>
#include "password_session.hpp"

namespace GithubClient {
std::unique_ptr<Client> Client::login(const std::string& username,
                                      const std::string& password) {
  boost::asio::io_context io;
  std::thread t([&io] { io.run(); });
  // FIXME: implement library init and thread pool
  t.detach();
  return boost::make_unique<Client>(PasswordSession(io, username, password));
}

std::unique_ptr<Client> Client::oauth(const std::string& oauthToken) {
  throw "not implemented yet";
}
};  // namespace GithubClient
