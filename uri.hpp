#ifndef _GITHUB_CLIENT_CPP_URI_H_
#define _GITHUB_CLIENT_CPP_URI_H_
#include <string>
namespace GithubClient {
class URI {
 public:
  // static const std::string getHost(const std::string& input);
  URI(const std::string& uri);
  std::string getHost() const;
  std::string getPort() const;
  std::string getPath() const;
  std::string getScheme() const;

 private:
  std::string host_;
  std::string port_;
  std::string path_;
  std::string scheme_;
};
};  // namespace GithubClient
#endif