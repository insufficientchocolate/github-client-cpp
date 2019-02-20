#ifndef _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#define _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#include <map>
#include <nlohmann/json.hpp>
namespace GithubClient {
class JsonHttpClient {
 public:
  typedef std::map<std::string, std::string> Headers;
  virtual nlohmann::json get(const std::string& path) const = 0;
  virtual nlohmann::json get(const std::string& path,
                             const Headers headers) const = 0;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body) const = 0;
  virtual nlohmann::json post(const std::string& path,
                              const nlohmann::json& body,
                              const Headers headers) const = 0;
};
};  // namespace GithubClient
#endif