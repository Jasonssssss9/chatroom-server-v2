#include "chatroom/service/offline_delivery_service.hpp"

namespace chatroom::service {

std::vector<protocol::DispatchAction> OfflineDeliveryService::BuildInitialDeliveryActions(
    const std::string& user_id,
    common::ConnectionId active_connection) const {
    (void)user_id;
    (void)active_connection;
    // TODO: load undelivered messages from storage and convert to enqueue actions.
    return {};
}

}  // namespace chatroom::service
