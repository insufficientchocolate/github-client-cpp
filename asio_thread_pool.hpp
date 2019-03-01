#ifndef _GITHUB_CLIENT_ASIO_THREAD_POOL_HPP_
#define _GITHUB_CLIENT_ASIO_THREAD_POOL_HPP_
#include <boost/asio.hpp>
#include <boost/make_unique.hpp>
#include <memory>
#include <thread>
namespace GithubClient {
class AsioThreadPool : public std::enable_shared_from_this<AsioThreadPool> {
 public:
  AsioThreadPool(
      unsigned int threadCount = std::thread::hardware_concurrency());
  ~AsioThreadPool() noexcept;
  boost::asio::io_context& getService();

 private:
  void addThread();
  boost::asio::io_context io_;
  std::vector<std::unique_ptr<std::thread>> threads_;
};
};  // namespace GithubClient
#endif