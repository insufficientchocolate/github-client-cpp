#include "http_client.hpp"
#include <string>
namespace GithubClient {
using tcp = boost::asio::ip::tcp;
HttpClient::HttpClient(boost::asio::io_context& io, const std::string& base)
    : io_(io), pathBase_(base) {}

nlohmann::json HttpClient::get(const std::string& path) const {
  return nlohmann::json{};
}

nlohmann::json HttpClient::post(const std::string& path,
                                const nlohmann::json& body) const {
  return nlohmann::json{};
}

void HttpClient::resolveEndpoint(const std::string& host,
                                 const unsigned int port) {
  tcp::resolver resolver{io_};
  auto const results = resolver.resolve(host, std::to_string(port));
  endpoints_ = results.begin();
}
};  // namespace GithubClient
