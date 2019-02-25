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
  for (int i = 0; i <= s; i++) {
    char thisShift = ((i + 1) % 3) * 2;
    char lastShift = 8 - thisShift;
    char value = 0;
    if (i > 0) {
      value += data[i - 1] & !(255 << lastShift);
    }
    value += data[i] >> thisShift;
    ss << characters[value];
    if (thisShift == 6) {
      ss << characters[data[i] >> 2];
    }
  }
  return ss.str();
}
}  // namespace GithubClient