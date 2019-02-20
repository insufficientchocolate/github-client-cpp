#ifndef _GITHUB_CLIENT_ERRORS_ILLEGAL_URI_EXCEPTION_HPP_
#define _GITHUB_CLIENT_ERRORS_ILLEGAL_URI_EXCEPTION_HPP_
#include <stdexcept>
#include <string>

namespace GithubClient {
namespace Errors {
class IllegalURIException : public std::runtime_error {
 public:
  IllegalURIException(const std::string& input);
};
};  // namespace Errors
};  // namespace GithubClient
#endif