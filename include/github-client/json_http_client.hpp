#ifndef _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#define _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#include <boost/beast.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include "uri.hpp"

namespace GithubClient {
typedef std::map<std::string, std::string> Headers;
class JsonHttpClient {
 public:
  virtual nlohmann::json get(const URI& uri,
                             const Headers& headers = Headers()) = 0;
  virtual nlohmann::json post(const URI& uri, const nlohmann::json& body,
                              const Headers& headers = Headers()) = 0;
  virtual ~JsonHttpClient() = default;
};
};  // namespace GithubClient
#endif