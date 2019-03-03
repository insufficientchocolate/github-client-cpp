#ifndef _TEST_JSON_HTTP_CLIENT_MOCK_HPP_
#define _TEST_JSON_HTTP_CLIENT_MOCK_HPP_
#include <gmock/gmock.h>
#include <github-client/json_http_client.hpp>

namespace GithubClient {
namespace Test {
class MockJsonHttpClient : public ::GithubClient::JsonHttpClient {
 public:
  MOCK_METHOD2(get, nlohmann::json(const URI& uri, const Headers& headers));
  MOCK_METHOD3(post, nlohmann::json(const URI& uri, const nlohmann::json& body,
                                    const Headers&));
};
};  // namespace Test
};  // namespace GithubClient
#endif
