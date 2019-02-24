#include <github-client/errors/illegal_uri_exception.hpp>

namespace GithubClient {
namespace Errors {
IllegalURIException::IllegalURIException(const std::string& input)
    : std::runtime_error("IllegalURIException: " + input) {}
};  // namespace Errors
};  // namespace GithubClient