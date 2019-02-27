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
  char left = 0;
  for (size_t i = 0; i < s; i++) {
    left += 8;
    /*
    h                 e                 l
    0 1 1 0 1 0 0 0 | 0 1 1 0 0 1 0 1 | 0 1 1 0 1 1 0 0
    ----------|--------------|-------------|-----------|
    loop and left:
    ----------------| 0 + 8 => 8 (first)
              |------------------------| (8 - 6) + 8 = 10 (second)
                             |--------------------------| (10 - 6) + 8 = 12
    (third)
                                           |------------| 12 - 6 = 6 (forth)

    */
    // have at least 6 bit
    while (left >= 6) {
      char value = 0;
      char used = 0;
      if (left > 8) {
        const char fromLastByte = left - 8;   // 4
        char remaining = (6 - fromLastByte);  // 2
        char toMask = fromLastByte;           // 4
        value = (data[i - 1] & ~(255 << toMask)) << remaining;
        used += fromLastByte;
      }
      // left is equal to 6 bit, fetch 6 bit from current byte directly
      if (left == 6) {
        value = data[i] & ~(255 << 6);
      } else {
        value |= data[i] >> (8 - (6 - used));  // 2 + used
      }
      ss << characters[value];
      left -= 6;
    }
    if (i == s - 1) {
      ss << characters[(data[i] & ~(255 << left)) << (6 - left)];
    }
  }
  return ss.str();
}
}  // namespace GithubClient
