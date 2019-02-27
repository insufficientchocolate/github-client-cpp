#include "base64.hpp"
#include <gtest/gtest.h>

namespace {
TEST(Base64, Encode) {
  ASSERT_EQ("aGVsbG8gd29ybGQ", GithubClient::Base64::encode("hello world"));
  ASSERT_EQ("YSB2ZXJ5IHZlcnkgbG9uZyB0ZXh0A",
            GithubClient::Base64::encode("a very very long text"));
};
};  // namespace