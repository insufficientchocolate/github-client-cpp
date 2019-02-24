#ifndef _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <github-client/json_http_client.hpp>
#include <nlohmann/json.hpp>
#include <string>

#include "uri.hpp"

namespace GithubClient {
namespace net = boost::asio::ip;
namespace ssl = boost::asio::ssl;
namespace http = boost::beast::http;
typedef http::request<http::string_body> Request;
typedef http::response<http::string_body> Response;
class HttpClient : public JsonHttpClient {
 public:
  HttpClient(boost::asio::io_context& io, const std::string& base);
  HttpClient(boost::asio::io_context& io, const std::string& host,
             const std::string& port, const std::string);
  virtual nlohmann::json get(const std::string& path,
                             const Headers& headers) override;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body,
                              const Headers& headers) override;

 private:
  const URI base_;
  boost::asio::io_context& io_;
  ssl::context sslContext_;
  std::string host_;
  std::string port_;
};
};  // namespace GithubClient

#endif