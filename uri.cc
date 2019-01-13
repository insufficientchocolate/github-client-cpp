#include "uri.hpp"
#include <regex>

static const std::string kGetHostPattern =
    "^([a-z]+):\/\/([A-Za-z0-9]+(.[A-Za-z0-9]+)+)";

namespace GithubClient {
const std::string URI::getHost(const std::string& input) {
  std::regex schemaAndHostRegexp(kGetHostPattern);
  std::smatch m;
  std::regex_search(input, schemaAndHostRegexp);
}
};  // namespace GithubClient