#include <curl/curl.h>
#include <github-client/client.hpp>
#include <github-client/follower.hpp>
#include <sstream>
#include "asio_thread_pool.hpp"
#include "follower_ns.hpp"
#include "http_client.hpp"
#include "password_session.hpp"

namespace GithubClient {
static const std::string kAPIBase = "https://api.github.com";
struct Client::Impl {
  Impl(std::unique_ptr<JsonHttpClient> client)
      : base_(kAPIBase),
        pool_(boost::make_unique<AsioThreadPool>()),
        client_(std::move(client)) {}
  Impl(JsonHttpClient* client)
      : base_(kAPIBase),
        pool_(boost::make_unique<AsioThreadPool>()),
        client_(client) {}
  Impl(AsioBasedClientFactory factory)
      : base_(kAPIBase), pool_(boost::make_unique<AsioThreadPool>()) {
    client_ = factory(pool_->getService());
  };
  nlohmann::json get(const std::string& path) {
    return client_->get(base_ / path);
  }
  nlohmann::json post(const std::string& path, const nlohmann::json body) {
    return client_->post(base_ / path, body);
  }
  std::unique_ptr<JsonHttpClient> client_;
  // TODO: asio thread pool can be removed, if client doesn't use asio
  std::unique_ptr<AsioThreadPool> pool_;
  URI base_;
};
std::unique_ptr<Client> Client::login(const std::string& username,
                                      const std::string& password) {
  return boost::make_unique<Client>(
      [&username, &password](boost::asio::io_context& io) {
        return boost::make_unique<PasswordSession>(
            boost::make_unique<HttpClient>(io), username, password);
      });
}

std::unique_ptr<Client> Client::oauth(const std::string& oauthToken) {
  throw "not implemented yet";
}

Client::Client(JsonHttpClient* client)
    : impl_(boost::make_unique<Impl>(client)) {}
Client::Client(AsioBasedClientFactory factory)
    : impl_(boost::make_unique<Impl>(factory)) {}
std::vector<Follower> Client::listFollowers() {
  nlohmann::json response = impl_->get("user/followers");
  return response.get<std::vector<Follower>>();
};
std::vector<Follower> Client::listFollowers(const std::string& username) {
  nlohmann::json response = impl_->get("user/" + username + "/followers");
  return response.get<std::vector<Follower>>();
}

Client::~Client() = default;
};  // namespace GithubClient
