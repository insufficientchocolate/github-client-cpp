#include <github-client/errors/illegal_uri_exception.hpp>
#include <github-client/uri.hpp>
#include <regex>
#include <sstream>

static const std::string kUriPattern =
    "^([a-z]+):\\/\\/([A-Za-z0-9]+(?:\\.[A-Za-z0-9]+)+)(?:\\:([0-9]+))?(?:\\/"
    "(.*))?";

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
URI::URI(const std::string& uri) {
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

URI::URI(const std::string& scheme, const std::string& host,
         const std::string& port, const std::string& path)
    : scheme_(scheme), host_(host), port_(port), path_(path) {}

std::string URI::getHost() const { return host_; }

std::string URI::getPort() const { return port_; }

std::string URI::getPath() const { return path_; }

std::string URI::getScheme() const { return scheme_; }

URI operator/(URI& parent, const boost::string_view& path) {
  if (path.empty()) {
    return parent;
  }
  URI child = parent;
  std::stringstream ss;
  ss << parent.path_ << "/" << path;
  child.path_ = ss.str();
  return child;
}

std::string URI::str() const {
  std::stringstream ss;
  ss << getScheme() << "://" << getHost();
  if (!isDefaultPort_) {
    ss << ":" << getPort();
  }
  if (!path_.empty()) {
    ss << "/" << getPath();
  }
  return ss.str();
}

};  // namespace GithubClient