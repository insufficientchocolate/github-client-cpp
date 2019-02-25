#include "base64.hpp"
#include <gtest/gtest.h>

namespace {
TEST(Base64, Encode) {
  ASSERT_EQ("aGVsbG8gd29ybGQK", GithubClient::Base64::encode("helle world"));
};
};  // namespace