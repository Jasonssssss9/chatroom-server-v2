#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace chatroom::net {

class Acceptor {
public:
    Acceptor() = default;
    ~Acceptor();

    Acceptor(const Acceptor&) = delete;
    Acceptor& operator=(const Acceptor&) = delete;

    bool Initialize(const std::string& host, std::uint16_t port, int backlog = 128);
    [[nodiscard]] int listen_fd() const noexcept;

    std::optional<int> AcceptOnce();

private:
    int listen_fd_{-1};
};

}  // namespace chatroom::net
