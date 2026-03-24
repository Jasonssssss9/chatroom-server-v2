#include "chatroom/service/direct_message_service.hpp"

namespace chatroom::service {

std::vector<protocol::DispatchAction> DirectMessageService::Handle(
    const protocol::MessageEnvelope& request,
    common::ConnectionId source_connection) const {
    (void)request;
    (void)source_connection;
    // TODO: route online messages, persist offline messages, return action set.
    return {};
}

}  // namespace chatroom::service
