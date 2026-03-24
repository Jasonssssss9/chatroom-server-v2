#pragma once

#include "chatroom/common/types.hpp"
#include "chatroom/protocol/envelope.hpp"

#include <string>

namespace chatroom::protocol {

enum class ActionType {
    kNone = 0,
    kEnqueueOutbound,
    kPersistOffline,
    kPersistHistory,
};

struct DispatchAction {
    ActionType type{ActionType::kNone};
    common::ConnectionId connection_id{0};
    std::string user_id;
    MessageEnvelope envelope;
};

}  // namespace chatroom::protocol
