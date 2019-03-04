#include <gtest/gtest.h>
#include <algorithm>
#include <github-client/client.hpp>
#include "mock/json_http_client.mock.hpp"
#include "simple_json_response.hpp"
using GithubClient::Test::MockJsonHttpClient;

using ::testing::_;
using ::testing::Return;

using GithubClient::Follower;
using GithubClient::URI;

namespace {
static const std::string followerResponse = R"(
  [
	{
	  "login": "follower1",
	  "id": 0,
	  "node_id": "FOLLOWER1",
	  "avatar_url": "https://avatars2.githubusercontent.com/u/0?v=4",
	  "gravatar_id": "",
	  "url": "https://api.github.com/users/follower1",
	  "html_url": "https://github.com/follower1",
	  "followers_url": "https://api.github.com/users/follower1/followers",
	  "following_url": "https://api.github.com/users/follower1/following{/other_user}",
	  "gists_url": "https://api.github.com/users/follower1/gists{/gist_id}",
	  "starred_url": "https://api.github.com/users/follower1/starred{/owner}{/repo}",
	  "subscriptions_url": "https://api.github.com/users/follower1/subscriptions",
	  "organizations_url": "https://api.github.com/users/follower1/orgs",
	  "repos_url": "https://api.github.com/users/follower1/repos",
	  "events_url": "https://api.github.com/users/follower1/events{/privacy}",
	  "received_events_url": "https://api.github.com/users/follower1/received_events",
	  "type": "User",
	  "site_admin": false
	},
	{
	  "login": "follower2",
	  "id": 1,
	  "node_id": "FOLLOWER2",
	  "avatar_url": "https://avatars3.githubusercontent.com/u/1?v=4",
	  "gravatar_id": "",
	  "url": "https://api.github.com/users/follower2",
	  "html_url": "https://github.com/follower2",
	  "followers_url": "https://api.github.com/users/follower2/followers",
	  "following_url": "https://api.github.com/users/follower2/following{/other_user}",
	  "gists_url": "https://api.github.com/users/follower2/gists{/gist_id}",
	  "starred_url": "https://api.github.com/users/follower2/starred{/owner}{/repo}",
	  "subscriptions_url": "https://api.github.com/users/follower2/subscriptions",
	  "organizations_url": "https://api.github.com/users/follower2/orgs",
	  "repos_url": "https://api.github.com/users/follower2/repos",
	  "events_url": "https://api.github.com/users/follower2/events{/privacy}",
	  "received_events_url": "https://api.github.com/users/follower2/received_events",
	  "type": "User",
	  "site_admin": false
	}
  ])";
TEST(Client, querySelfFollower) {
  MockJsonHttpClient* mockHttp = new MockJsonHttpClient();
  GithubClient::Client client(mockHttp);
  EXPECT_CALL(*mockHttp, get(URI("https://api.github.com/user/followers"), _))
      .Times(1)
      .WillOnce(Return(std::make_shared<GithubClient::SimpleJsonResponse>(
          200, GithubClient::Headers{},
          nlohmann::json::parse(followerResponse))));
  std::vector<Follower> followers = client.listFollowers();
  // check result
  std::vector<std::string> names;
  std::transform(followers.begin(), followers.end(), std::back_inserter(names),
                 [](const Follower& follower) { return follower.username; });
  ASSERT_EQ(2, names.size());
  ASSERT_EQ((std::vector<std::string>{"follower1", "follower2"}), names);
};
};  // namespace
