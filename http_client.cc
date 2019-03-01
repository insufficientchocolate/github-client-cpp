#include <boost/system/error_code.hpp>
#include <stdexcept>
#include <string>

#include "cert.hpp"
#include "connection.hpp"
#include "http_client.hpp"

namespace GithubClient {
static const auto kSSLMethod = ssl::context::method::tlsv12_client;
using tcp = boost::asio::ip::tcp;
HttpClient::HttpClient(boost::asio::io_context& io, const std::string& base)
    : io_(io), base_(base), sslContext_(kSSLMethod) {
  loadRootCertificates(sslContext_);
}

HttpClient::HttpClient(boost::asio::io_context& io, const std::string& host,
                       const std::string& port, const std::string& path)
    : io_(io), base_("https", host, port, path), sslContext_(kSSLMethod) {
  loadRootCertificates(sslContext_);
}

nlohmann::json HttpClient::get(const std::string& path,
                               const Headers& headers) {
  Connection connection(io_, sslContext_, base_.getHost(), base_.getPort());
  Request request =
      newRequest(http::verb::get, (URI(base_) / path).str(), "", headers);
  Response response = connection.doRequest(request);
  return nlohmann::json::parse(response.body());
}

nlohmann::json HttpClient::post(const std::string& path,
                                const nlohmann::json& body,
                                const Headers& headers) {
  Connection connection(io_, sslContext_, base_.getHost(), base_.getPort());
  Request request = newRequest(http::verb::post, (URI(base_) / path).str(),
                               body.dump(), headers);
  Response response = connection.doRequest(request);
  return nlohmann::json::parse(response.body());
}

Request HttpClient::newRequest(http::verb const method,
                               const boost::string_view& target,
                               const boost::string_view& body,
                               const Headers& headers) const {
  Request r{method, target, 11, body, headers};
  r.set(http::field::host, base_.getHost());
  r.set(http::field::user_agent, "github_client_cpp");
  return r;
}

};  // namespace GithubClient
