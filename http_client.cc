#include <boost/system/error_code.hpp>
#include <stdexcept>
#include <string>

#include "cert.hpp"
#include "connection.hpp"
#include "http_client.hpp"

namespace GithubClient {
static const auto kSSLMethod = ssl::context::method::tlsv12_client;
using tcp = boost::asio::ip::tcp;
HttpClient::HttpClient(boost::asio::io_context& io)
    : io_(io), sslContext_(kSSLMethod) {
  loadRootCertificates(sslContext_);
}

nlohmann::json HttpClient::get(const URI& uri, const Headers& headers) {
  Connection connection(io_, sslContext_, uri.getHost(), uri.getPort());
  Request request = newRequest(http::verb::get, uri, "", headers);
  Response response = connection.doRequest(request);
  return nlohmann::json::parse(response.body());
}

nlohmann::json HttpClient::post(const URI& uri, const nlohmann::json& body,
                                const Headers& headers) {
  Connection connection(io_, sslContext_, uri.getHost(), uri.getPort());
  Request request = newRequest(http::verb::post, uri, body.dump(), headers);
  Response response = connection.doRequest(request);
  return nlohmann::json::parse(response.body());
}

Request HttpClient::newRequest(http::verb const method, const URI& uri,
                               const boost::string_view& body,
                               const Headers& headers) const {
  Request r{method, "/" + uri.getPath(), 11, body};
  for (auto const& pair : headers) {
    r.set(pair.first, pair.second);
  }
  r.set(http::field::host, uri.getHost());
  r.set(http::field::user_agent, "github_client_cpp");
  return r;
}

};  // namespace GithubClient
