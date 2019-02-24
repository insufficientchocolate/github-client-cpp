#include <github-client/json_http_client.hpp>

namespace GithubClient {
    boost::beast::http::basic_fields<> JsonHttpClient::Headers::toFields() const {
        boost::beast::http::basic_fields<> fields;
        for(auto const& x : *this) {
            fields.insert(x.first, x.second);
        }
        return fields;
    }
};