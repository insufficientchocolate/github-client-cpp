#ifndef _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_
#define _GITHUB_CLIENT_CPP_HTTP_CLIENT_H_

#include <boost/asio.hpp>
#include <github-client/session.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace GithubClient {
namespace net = boost::asio::ip;
class HttpClient : public Session {
 public:
  HttpClient(boost::asio::io_context& io, const std::string& base);
  virtual nlohmann::json get(const std::string& path) const override;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body) const override;

 private:
  void resolveEndpoint(const std::string& host, const unsigned int port);
  const std::string pathBase_;
  std::vector<net::basic_resolver_entry<net::tcp>> endpoints_;
  boost::asio::io_context& io_;
};
};  // namespace GithubClient

#endif