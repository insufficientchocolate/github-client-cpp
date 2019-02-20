#include "uri.hpp"
#include <github-client/errors/illegal_uri_exception.hpp>
#include <regex>

static const std::string kGetHostPattern =
    "^([a-z]+):\\/\\/([A-Za-z0-9]+(.[A-Za-z0-9]+)+)(\\/.*)";

namespace GithubClient {
const std::string URI::getHost(const std::string& input) {
  std::regex schemaAndHostRegexp(kGetHostPattern);
  std::smatch m;
  if (!std::regex_search(input, m, schemaAndHostRegexp)) {
    throw Errors::IllegalURIException(input);
  }
  return m[2];
}
};  // namespace GithubClient