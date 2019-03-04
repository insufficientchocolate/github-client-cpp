#ifndef _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#define _GITHUB_CLIENT_JSON_HTTP_CLIENT_HPP_
#include <boost/beast.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include "headers.hpp"
#include "json_response.hpp"
#include "uri.hpp"

namespace GithubClient {
class JsonHttpClient {
 public:
  virtual JsonResponse::Pointer get(const URI& uri,
                                    const Headers& headers = Headers()) = 0;
  virtual JsonResponse::Pointer post(const URI& uri, const nlohmann::json& body,
                                     const Headers& headers = Headers()) = 0;
  virtual ~JsonHttpClient() = default;
};
};  // namespace GithubClient
#endif
