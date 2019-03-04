#ifndef _GITHUB_CLIENT_SIMPLE_JSON_RESPONSE_HPP_
#define _GITHUB_CLIENT_SIMPLE_JSON_RESPONSE_HPP_
#include <github-client/json_response.hpp>
namespace GithubClient {
class SimpleJsonResponse : public JsonResponse {
 public:
  SimpleJsonResponse(StatusCode code, Headers headers, nlohmann::json body);
  virtual StatusCode getStatus() override;
  virtual nlohmann::json getJson() override;
  virtual Headers getHeaders() override;
  StatusCode status;
  nlohmann::json json;
  Headers headers;
};
};  // namespace GithubClient
#endif
