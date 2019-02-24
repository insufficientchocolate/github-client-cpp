#include <boost/system/error_code.hpp>
#include <stdexcept>
#include <string>

#include "cert.hpp"
#include "connection.hpp"
#include "http_client.hpp"
#include "uri.hpp"

namespace GithubClient {
using tcp = boost::asio::ip::tcp;
HttpClient::HttpClient(boost::asio::io_context& io, const std::string& base)
    : io_(io),
      pathBase_(base),
      sslContext_(ssl::context::method::tlsv11_client) {
  loadRootCertificates(sslContext_);
}

nlohmann::json HttpClient::get(const std::string& path) {
  Connection connection(io_, sslContext_, host_, port_);
  return nlohmann::json{};
}

nlohmann::json HttpClient::post(const std::string& path,
                                const nlohmann::json& body) {
  return nlohmann::json{};
}

};  // namespace GithubClient
