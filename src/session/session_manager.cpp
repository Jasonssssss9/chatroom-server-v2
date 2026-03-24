#include "chatroom/session/session_manager.hpp"

namespace chatroom::session {

void SessionManager::BindUserToConnection(const std::string& user_id, common::ConnectionId connection_id) {
    std::scoped_lock lock(mutex_);
    user_to_connection_[user_id] = connection_id;
    connection_to_user_[connection_id] = user_id;
}

void SessionManager::UnbindConnection(common::ConnectionId connection_id) {
    std::scoped_lock lock(mutex_);
    const auto it = connection_to_user_.find(connection_id);
    if (it == connection_to_user_.end()) {
        return;
    }
    user_to_connection_.erase(it->second);
    connection_to_user_.erase(it);
}

bool SessionManager::IsOnline(const std::string& user_id) const {
    std::scoped_lock lock(mutex_);
    return user_to_connection_.find(user_id) != user_to_connection_.end();
}

std::optional<common::ConnectionId> SessionManager::GetConnectionForUser(const std::string& user_id) const {
    std::scoped_lock lock(mutex_);
    const auto it = user_to_connection_.find(user_id);
    if (it == user_to_connection_.end()) {
        return std::nullopt;
    }
    return it->second;
}

}  // namespace chatroom::session
