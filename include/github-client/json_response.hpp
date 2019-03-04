#ifndef _GITHUB_CLIENT_JSON_RESPONSE_HPP_
#define _GITHUB_CLIENT_JSON_RESPONSE_HPP_
#include <memory>
#include <nlohmann/json.hpp>
#include "headers.hpp"

namespace GithubClient {
typedef unsigned StatusCode;
class JsonResponse {
 public:
  typedef std::shared_ptr<JsonResponse> Pointer;
  virtual StatusCode getStatus() = 0;
  virtual nlohmann::json getJson() = 0;
  virtual Headers getHeaders() = 0;
  virtual ~JsonResponse() = default;
};
};  // namespace GithubClient
#endif
