#include <curl/curl.h>
#include <github-client/client.hpp>
#include <sstream>
#include "asio_thread_pool.hpp"
#include "http_client.hpp"
#include "password_session.hpp"

namespace GithubClient {
struct Client::Impl {
  Impl(std::unique_ptr<JsonHttpClient> client)
      : pool_(boost::make_unique<AsioThreadPool>()),
        client_(std::move(client)) {}
  Impl(JsonHttpClient* client)
      : pool_(boost::make_unique<AsioThreadPool>()), client_(client) {}
  Impl(AsioBasedClientFactory factory)
      : pool_(boost::make_unique<AsioThreadPool>()) {
    client_ = factory(pool_->getService());
  };
  std::unique_ptr<JsonHttpClient> client_;
  // TODO: asio thread pool can be removed, if client doesn't use asio
  std::unique_ptr<AsioThreadPool> pool_;
};
std::unique_ptr<Client> Client::login(const std::string& username,
                                      const std::string& password) {
  return boost::make_unique<Client>(
      [&username, &password](boost::asio::io_context& io) {
        return boost::make_unique<PasswordSession>(
            boost::make_unique<HttpClient>(io, "github.com", "443", "api"),
            username, password);
      });
}

std::unique_ptr<Client> Client::oauth(const std::string& oauthToken) {
  throw "not implemented yet";
}

Client::Client(JsonHttpClient* client)
    : impl_(boost::make_unique<Impl>(client)) {}
Client::Client(AsioBasedClientFactory factory)
    : impl_(boost::make_unique<Impl>(factory)) {}
};  // namespace GithubClient
