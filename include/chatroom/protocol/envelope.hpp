#pragma once

#include <string>

namespace chatroom::protocol {

struct MessageEnvelope {
    std::string request_type;
    std::string request_id;
    std::string sender_user;
    std::string target_user;
    std::string payload_json;
};

}  // namespace chatroom::protocol
