#include "chatroom/service/auth_service.hpp"

namespace chatroom::service {

std::vector<protocol::DispatchAction> AuthService::Handle(
    const protocol::MessageEnvelope& request,
    common::ConnectionId source_connection) const {
    (void)request;
    (void)source_connection;
    // TODO: validate login/register and produce actions.
    return {};
}

}  // namespace chatroom::service
