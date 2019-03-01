#ifndef _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#define _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#include <boost/beast.hpp>
#include <map>
#include <nlohmann/json.hpp>
namespace GithubClient {
typedef boost::beast::http::request_header<boost::beast::http::fields> Headers;
class JsonHttpClient {
 public:
  virtual nlohmann::json get(const std::string& path,
                             const Headers& headers = Headers()) = 0;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body,
                              const Headers& headers = Headers()) = 0;
  virtual ~JsonHttpClient() = default;
};
};  // namespace GithubClient
#endif