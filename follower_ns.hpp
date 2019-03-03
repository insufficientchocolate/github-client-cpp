#ifndef _GITHUB_CLIENT_FOLLOWER_NS_HPP_
#define _GITHUB_CLIENT_FOLLOWER_NS_HPP_
using nlohmann::json;

namespace GithubClient {
void from_json(const json& j, GithubClient::Follower& p) {
  j.at("login").get_to(p.username);
}
}  // namespace GithubClient
#endif
