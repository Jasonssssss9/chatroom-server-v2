#pragma once

#include "chatroom/common/types.hpp"
#include "chatroom/protocol/action.hpp"

#include <string>
#include <vector>

namespace chatroom::service {

class OfflineDeliveryService {
public:
    std::vector<protocol::DispatchAction> BuildInitialDeliveryActions(
        const std::string& user_id,
        common::ConnectionId active_connection) const;
};

}  // namespace chatroom::service
