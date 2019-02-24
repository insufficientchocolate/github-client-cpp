#include <github-client/errors/illegal_uri_exception.hpp>
#include <regex>
#include <sstream>

#include "uri.hpp"

static const std::string kUriPattern =
    "^([a-z]+):\\/\\/([A-Za-z0-9]+(?:\\.[A-Za-z0-9]+)+)(?:\\:([0-9]+))?\\/(.*)";

namespace GithubClient {
static std::string inferPortByScheme(const std::string& scheme) {
  if (scheme == "http") {
    return "80";
  }
  if (scheme == "https") {
    return "443";
  }

  return "";
}
URI::URI(const std::string& uri) : boost::string_view(uri) {
  std::regex uriRegexp(kUriPattern);
  std::smatch m;
  if (!std::regex_search(uri, m, uriRegexp)) {
    throw Errors::IllegalURIException(uri);
  }
  scheme_ = m[1];
  host_ = m[2];
  port_ = m[3];
  std::string defaultPort = inferPortByScheme(scheme_);
  if (port_.empty()) {
    port_ = defaultPort;
  }
  if (port_ == defaultPort) {
    isDefaultPort_ = true;
  }
  path_ = m[4];
}

URI::URI(const URI& origin)
    : scheme_(origin.getScheme()),
      host_(origin.getHost()),
      port_(origin.getPort()),
      path_(origin.getPath()),
      isDefaultPort_(origin.isDefaultPort_) {}

std::string URI::getHost() const { return host_; }

std::string URI::getPort() const { return port_; }

std::string URI::getPath() const { return path_; }

std::string URI::getScheme() const { return scheme_; }

URI& URI::operator/(const boost::string_view& path) {
  std::stringstream ss;
  ss << this->path_ << "/" << path;
  this->path_ = ss.str();
  return *this;
}

// URI& URI::operator/(const std::string& path) {
//   this-><< (path);
//   return *this;
// }

};  // namespace GithubClient