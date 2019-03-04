#include "simple_json_response.hpp"

namespace GithubClient {
SimpleJsonResponse::SimpleJsonResponse(StatusCode code, Headers headers,
                                       nlohmann::json body)
    : status(code), headers(headers), json(body) {}

StatusCode SimpleJsonResponse::getStatus() { return status; }

nlohmann::json SimpleJsonResponse::getJson() { return json; }

Headers SimpleJsonResponse::getHeaders() { return headers; }
};  // namespace GithubClient
