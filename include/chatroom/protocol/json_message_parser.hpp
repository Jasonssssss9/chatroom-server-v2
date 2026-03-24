#pragma once

#include "chatroom/common/result.hpp"
#include "chatroom/protocol/envelope.hpp"

#include <string>

namespace chatroom::protocol {

class JsonMessageParser {
public:
    common::Result<MessageEnvelope> Parse(const std::string& frame_payload) const;
};

}  // namespace chatroom::protocol
