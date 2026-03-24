#include "chatroom/net/connection.hpp"

namespace chatroom::net {

Connection::Connection(common::ConnectionId id, int fd) : id_(id), fd_(fd) {}

common::ConnectionId Connection::id() const noexcept {
    return id_;
}

int Connection::fd() const noexcept {
    return fd_;
}

void Connection::AppendIncoming(const std::uint8_t* data, std::size_t size) {
    input_buffer_.append(reinterpret_cast<const char*>(data), size);
}

void Connection::EnqueueOutbound(std::vector<std::uint8_t> frame) {
    outbound_queue_.push_back(std::move(frame));
}

std::string& Connection::input_buffer() noexcept {
    return input_buffer_;
}

const std::string& Connection::input_buffer() const noexcept {
    return input_buffer_;
}

std::deque<std::vector<std::uint8_t>>& Connection::outbound_queue() noexcept {
    return outbound_queue_;
}

}  // namespace chatroom::net
