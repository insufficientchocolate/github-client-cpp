#ifndef _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <github-client/json_http_client.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace GithubClient {
namespace net = boost::asio::ip;
namespace ssl = boost::asio::ssl;
class HttpClient : public JsonHttpClient {
 public:
  typedef net::basic_resolver_results<net::tcp>::const_iterator
      EndpointResolveResult;
  HttpClient(boost::asio::io_context& io, const std::string& base);
  virtual nlohmann::json get(const std::string& path) const override;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body) const override;

 private:
  void resolveEndpoint(const std::string& host, const unsigned int port);
  const std::string pathBase_;
  EndpointResolveResult endpoints_;
  boost::asio::io_context& io_;
  ssl::context sslContext_;
};
};  // namespace GithubClient

#endif