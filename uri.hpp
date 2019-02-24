#ifndef _GITHUB_CLIENT_CPP_URI_H_
#define _GITHUB_CLIENT_CPP_URI_H_
#include <boost/utility/string_view.hpp>
#include <string>

namespace GithubClient {
class URI {
 public:
  // static const std::string getHost(const std::string& input);
  URI(const std::string& uri);
  URI(const URI& uri);
  std::string getHost() const;
  std::string getPort() const;
  std::string getPath() const;
  std::string getScheme() const;
  std::string str() const;

  URI& operator/(const boost::string_view& path);

 private:
  std::string host_;
  std::string port_;
  std::string path_;
  std::string scheme_;
  bool isDefaultPort_;
};
};  // namespace GithubClient
#endif