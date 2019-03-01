#include <gtest/gtest.h>
#include "asio_thread_pool.hpp"

namespace {
TEST(AsioThreadPool, getService) {
  GithubClient::AsioThreadPool pool(2);
  boost::asio::io_context& io = pool.getService();
};
};  // namespace