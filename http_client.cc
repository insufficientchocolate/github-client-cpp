#include <boost/system/error_code.hpp>
#include <stdexcept>
#include <string>

#include "cert.hpp"
#include "connection.hpp"
#include "http_client.hpp"

namespace GithubClient {
using tcp = boost::asio::ip::tcp;
HttpClient::HttpClient(boost::asio::io_context& io, const std::string& base)
    : io_(io), base_(base), sslContext_(ssl::context::method::tlsv11_client) {
  loadRootCertificates(sslContext_);
}

nlohmann::json HttpClient::get(const std::string& path,
                               const Headers& headers) {
  Connection connection(io_, sslContext_, host_, port_);
  Request request{http::verb::get, (URI(base_) / path).str(), 11, nullptr,
                  headers};
  Response response = connection.doRequest(request);
  return nlohmann::json::parse(response.body());
}

nlohmann::json HttpClient::post(const std::string& path,
                                const nlohmann::json& body,
                                const Headers& headers) {
  Connection connection(io_, sslContext_, host_, port_);
  Request request{http::verb::post, (URI(base_) / path).str(), 11, nullptr,
                  headers};
  Response response = connection.doRequest(request);
  return nlohmann::json::parse(response.body());
}

};  // namespace GithubClient
