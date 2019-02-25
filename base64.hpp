#ifndef _GITHUB_CLIENT_BASE64_HPP_
#define _GITHUB_CLIENT_BASE64_HPP_
#include <string>

namespace GithubClient {
class Base64 {
 public:
  static std::string encode(std::string input);
  static std::string decode(std::string code);
};
};  // namespace GithubClient
#endif