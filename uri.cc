#include "uri.hpp"
#include <github-client/errors/illegal_uri_exception.hpp>
#include <regex>

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
URI::URI(const std::string& uri) {
  std::regex uriRegexp(kUriPattern);
  std::smatch m;
  if (!std::regex_search(uri, m, uriRegexp)) {
    throw Errors::IllegalURIException(uri);
  }
  scheme_ = m[1];
  host_ = m[2];
  port_ = m[3];
  if (port_.empty()) {
    port_ = inferPortByScheme(scheme_);
  }
  path_ = m[4];
}

std::string URI::getHost() const { return host_; }

std::string URI::getPort() const { return port_; }

std::string URI::getPath() const { return path_; }

std::string URI::getScheme() const { return scheme_; }
};  // namespace GithubClient