#include <gtest/gtest.h>
#include <github-client/uri.hpp>

namespace {
TEST(URI, Parsing) {
  GithubClient::URI uri("https://github.com/path");

  ASSERT_EQ("https", uri.getScheme());
  ASSERT_EQ("github.com", uri.getHost());
  ASSERT_EQ("path", uri.getPath());
}

TEST(URI, InferDefaultPort) {
  GithubClient::URI uriHttp("http://github.com/path");
  ASSERT_EQ("80", uriHttp.getPort());

  GithubClient::URI uriHttps("https://github.com/path");
  ASSERT_EQ("443", uriHttps.getPort());
}

TEST(URI, PathConcat) {
  GithubClient::URI uri("https://github.com/api");
  ASSERT_EQ("https://github.com/api/resource", (uri / "resource").str());
}

TEST(URI, PathConcatEmptyPath) {
  GithubClient::URI uri("https://api.github.com");
  ASSERT_EQ("https://api.github.com", uri.str());
  ASSERT_EQ("https://api.github.com", (uri / "").str());
}

TEST(URI, ParsingURLWithoutPath) {
  try {
    GithubClient::URI uri("https://github.com");
    ASSERT_EQ("https", uri.getScheme());
    ASSERT_EQ("github.com", uri.getHost());
    ASSERT_EQ("", uri.getPath());
  } catch (const std::exception& e) {
    FAIL() << "exception threw: " << e.what();
  }
}

TEST(URI, EqualOperator) {
  GithubClient::URI uri("https://api.github.com");
  ASSERT_TRUE(uri / "test" == GithubClient::URI("https://api.github.com/test"));
}

};  // namespace
