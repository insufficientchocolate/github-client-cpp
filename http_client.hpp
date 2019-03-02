#ifndef _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <github-client/json_http_client.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace GithubClient {
namespace net = boost::asio::ip;
namespace ssl = boost::asio::ssl;
namespace http = boost::beast::http;
typedef http::request<http::string_body> Request;
typedef http::response<http::string_body> Response;
class HttpClient : public JsonHttpClient {
 public:
  HttpClient(boost::asio::io_context& io);
  virtual nlohmann::json get(const URI& uri,
                             const Headers& headers = Headers()) override;
  virtual nlohmann::json post(const URI& uri, const nlohmann::json& body,
                              const Headers& headers = Headers()) override;

 private:
  Request newRequest(http::verb const method, const URI& uri,
                     const boost::string_view& body,
                     const Headers& headers) const;
  boost::asio::io_context& io_;
  ssl::context sslContext_;
};
};  // namespace GithubClient

#endif