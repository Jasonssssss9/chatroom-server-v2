#pragma once

#include "chatroom/common/types.hpp"
#include "chatroom/protocol/action.hpp"
#include "chatroom/protocol/envelope.hpp"

#include <vector>

namespace chatroom::service {

class GroupMessageService {
public:
    std::vector<protocol::DispatchAction> Handle(
        const protocol::MessageEnvelope& request,
        common::ConnectionId source_connection) const;
};

}  // namespace chatroom::service
