#ifndef _GITHUB_CLIENT_CPP_SESSION_H_
#define _GITHUB_CLIENT_CPP_SESSION_H_
#include <nlohmann/json.hpp>

namespace GithubClient {
class Session {
    public:
        ~Session() noexcept;
        virtual nlohmann::json get(const std::string& path) const = 0;
        virtual nlohmann::json post(const std::string& path,const nlohmann::json& body) const = 0;
};
};
#endif