#pragma once

#include "chatroom/common/types.hpp"
#include "chatroom/net/connection.hpp"

#include <memory>
#include <mutex>
#include <unordered_map>

namespace chatroom::session {

class ConnectionRegistry {
public:
    void Add(std::shared_ptr<net::Connection> connection);
    std::shared_ptr<net::Connection> Get(common::ConnectionId id) const;
    void Remove(common::ConnectionId id);

private:
    mutable std::mutex mutex_;
    std::unordered_map<common::ConnectionId, std::shared_ptr<net::Connection>> connections_;
};

}  // namespace chatroom::session
