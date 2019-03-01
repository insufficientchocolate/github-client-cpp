#include "asio_thread_pool.hpp"

namespace GithubClient {
AsioThreadPool::AsioThreadPool(unsigned int threadCount) {
  for (unsigned int i = 0; i < threadCount; i++) {
    addThread();
  }
}

AsioThreadPool::~AsioThreadPool() noexcept {
  io_.stop();
  for (auto& t : threads_) {
    t->join();
  }
}

void AsioThreadPool::addThread() {
  threads_.push_back(boost::make_unique<std::thread>([this] { io_.run(); }));
}

boost::asio::io_context& AsioThreadPool::getService() { return io_; }
};  // namespace GithubClient