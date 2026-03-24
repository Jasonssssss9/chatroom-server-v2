#include "chatroom/service/group_message_service.hpp"

namespace chatroom::service {

std::vector<protocol::DispatchAction> GroupMessageService::Handle(
    const protocol::MessageEnvelope& request,
    common::ConnectionId source_connection) const {
    (void)request;
    (void)source_connection;
    // TODO: resolve group recipients and produce batched actions.
    return {};
}

}  // namespace chatroom::service
