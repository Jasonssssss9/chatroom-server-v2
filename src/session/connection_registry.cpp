#include "chatroom/session/connection_registry.hpp"

namespace chatroom::session {

void ConnectionRegistry::Add(std::shared_ptr<net::Connection> connection) {
    if (connection == nullptr) {
        return;
    }
    std::scoped_lock lock(mutex_);
    connections_[connection->id()] = std::move(connection);
}

std::shared_ptr<net::Connection> ConnectionRegistry::Get(common::ConnectionId id) const {
    std::scoped_lock lock(mutex_);
    const auto it = connections_.find(id);
    if (it == connections_.end()) {
        return nullptr;
    }
    return it->second;
}

void ConnectionRegistry::Remove(common::ConnectionId id) {
    std::scoped_lock lock(mutex_);
    connections_.erase(id);
}

}  // namespace chatroom::session
