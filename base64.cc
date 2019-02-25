#include "base64.hpp"
#include <sstream>
static char characters[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "+/";
namespace GithubClient {
std::string Base64::encode(std::string input) {
  if (input.empty()) {
    return "";
  }
  std::stringstream ss;
  const char* data = input.data();
  size_t s = input.size();
  char left = 8;
  for (size_t i = 0; i < s; i++) {
    char value = 0;
    // accumlate at least 6 bit
    if (left < 6) {
      left += 8;
      continue;
    }
    // have at least 6 bit
    while (left >= 6) {
      char value = 0;
      if (left > 8) {
        char use = left - 8;
        value = data[i - 1] & !(255 << use);
        left -= use;
      }
      char use = 8 - left;
      value += data[i] >> use;
      ss << characters[value];
      left -= use;
    }
  }
  return ss.str();
}
}  // namespace GithubClient