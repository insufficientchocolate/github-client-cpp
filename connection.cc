#include "connection.hpp"

namespace GithubClient {
Connection::Connection(boost::asio::io_context& io, ssl::context& sslContext,
                       const std::string& host, const std::string& port) {
  connect(sslContext, host, port);
};

void Connection::connect(ssl::context& sslContext, const std::string& host,
                         const std::string& port) {
  ip::tcp::resolver resolver{io_};
  auto const results = resolver.resolve(host, port);
  stream_ = boost::make_unique<ssl::stream<ip::tcp::socket>>(io_, sslContext);
  // tcp connect
  boost::asio::connect(stream_->next_layer(), results.begin(), results.end());
  // ssl handshake
  stream_->handshake(ssl::stream_base::client);
}

Response Connection::doRequest(Request& request) {
  http::write(*stream_, request);
  boost::beast::flat_buffer buffer;
  Response response;
  http::read(*stream_, buffer, response);
  boost::system::error_code ec;
  stream_->shutdown(ec);
  // if (ec == boost::asio::ip::error::eof()) {
  //   ec = {};
  // }
  if (ec) {
    throw boost::beast::system_error(ec);
  }
  return response;
}

};  // namespace GithubClient
