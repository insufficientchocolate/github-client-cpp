#ifndef _GITHUB_CLIENT_CONNECTION_HPP_
#define _GITHUB_CLIENT_CONNECTION_HPP_
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <memory>
#include "http_client.hpp"

namespace ip = boost::asio::ip;
namespace http = boost::beast::http;
namespace ssl = boost::asio::ssl;
namespace GithubClient {
class Connection {
 public:
  Connection(boost::asio::io_context& io, ssl::context& sslContext,
             const std::string& host, const std::string& port);
  Response doRequest(Request& request);

 private:
  void connect(ssl::context& sslContext, const std::string& host,
               const std::string& port);
  boost::asio::io_context io_;
  std::unique_ptr<ssl::stream<ip::tcp::socket>> stream_;
};
};  // namespace GithubClient
#endif
