#pragma once

#include "chatroom/common/types.hpp"

#include <cstdint>
#include <deque>
#include <string>
#include <vector>

namespace chatroom::net {

class Connection {
public:
    Connection(common::ConnectionId id, int fd);

    [[nodiscard]] common::ConnectionId id() const noexcept;
    [[nodiscard]] int fd() const noexcept;

    void AppendIncoming(const std::uint8_t* data, std::size_t size);
    void EnqueueOutbound(std::vector<std::uint8_t> frame);

    [[nodiscard]] std::string& input_buffer() noexcept;
    [[nodiscard]] const std::string& input_buffer() const noexcept;
    [[nodiscard]] std::deque<std::vector<std::uint8_t>>& outbound_queue() noexcept;

private:
    common::ConnectionId id_{};
    int fd_{-1};
    std::string input_buffer_;
    std::deque<std::vector<std::uint8_t>> outbound_queue_;
};

}  // namespace chatroom::net
