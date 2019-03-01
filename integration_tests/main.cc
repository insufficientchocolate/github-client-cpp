#include <boost/asio.hpp>
#include <iostream>
#include "http_client.hpp"

int main(int argc, char** argv) {
  try {
    boost::asio::io_context io;
    GithubClient::HttpClient client(io, "https://api.github.com");
    nlohmann::json response = client.get("");
    std::cout << response << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "exception throw: " << e.what() << std::endl;
    return -1;
  }
}