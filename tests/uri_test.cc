#include "uri.hpp"
#include <gtest/gtest.h>

namespace {
TEST(URI, getHost) {
  ASSERT_EQ("github.com",
            GithubClient::URI::getHost("https://github.com/path"));
}
};  // namespace
