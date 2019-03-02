#ifndef _GITHUB_CLIENT_CPP_URI_H_
#define _GITHUB_CLIENT_CPP_URI_H_
#include <boost/utility/string_view.hpp>
#include <string>

namespace GithubClient {
class URI {
 public:
  URI(const std::string& uri);
  URI(const std::string& scheme, const std::string& host,
      const std::string& port, const std::string& path);
  std::string getHost() const;
  std::string getPort() const;
  std::string getPath() const;
  std::string getScheme() const;
  std::string str() const;

 private:
  std::string host_;
  std::string port_;
  std::string path_;
  std::string scheme_;
  bool isDefaultPort_;
  friend URI operator/(URI&, const boost::string_view&);
};
URI operator/(URI& parent, const boost::string_view& segment);

};  // namespace GithubClient
#endif