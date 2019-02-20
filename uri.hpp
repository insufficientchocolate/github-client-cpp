#ifndef _GITHUB_CLIENT_CPP_URI_H_
#define _GITHUB_CLIENT_CPP_URI_H_
#include <string>
namespace GithubClient {
class URI {
 public:
  static const std::string getHost(const std::string& input);
};
};  // namespace GithubClient
#endif