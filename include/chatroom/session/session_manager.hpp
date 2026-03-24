#pragma once

#include "chatroom/common/types.hpp"

#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>

namespace chatroom::session {

class SessionManager {
public:
    void BindUserToConnection(const std::string& user_id, common::ConnectionId connection_id);
    void UnbindConnection(common::ConnectionId connection_id);

    [[nodiscard]] bool IsOnline(const std::string& user_id) const;
    [[nodiscard]] std::optional<common::ConnectionId> GetConnectionForUser(const std::string& user_id) const;

private:
    mutable std::mutex mutex_;
    std::unordered_map<std::string, common::ConnectionId> user_to_connection_;
    std::unordered_map<common::ConnectionId, std::string> connection_to_user_;
};

}  // namespace chatroom::session
