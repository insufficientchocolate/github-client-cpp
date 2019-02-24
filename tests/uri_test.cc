#include "uri.hpp"
#include <gtest/gtest.h>

namespace {
TEST(URI, getHost) {
  GithubClient::URI uri("https://github.com/path");
  ASSERT_EQ("github.com", uri.getHost());
}
};  // namespace
