#include "chatroom/net/acceptor.hpp"

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

namespace chatroom::net {

namespace {

bool SetNonBlocking(int fd) {
    const int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) {
        return false;
    }
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK) == 0;
}

}  // namespace

Acceptor::~Acceptor() {
    if (listen_fd_ >= 0) {
        close(listen_fd_);
    }
}

bool Acceptor::Initialize(const std::string& host, std::uint16_t port, int backlog) {
    listen_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd_ < 0) {
        return false;
    }

    int opt = 1;
    setsockopt(listen_fd_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (SetNonBlocking(listen_fd_) == false) {
        return false;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host.c_str(), &addr.sin_addr) <= 0) {
        return false;
    }

    if (bind(listen_fd_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0) {
        return false;
    }

    return listen(listen_fd_, backlog) == 0;
}

int Acceptor::listen_fd() const noexcept {
    return listen_fd_;
}

std::optional<int> Acceptor::AcceptOnce() {
    sockaddr_in peer{};
    socklen_t len = sizeof(peer);
    const int client_fd = accept4(listen_fd_, reinterpret_cast<sockaddr*>(&peer), &len, SOCK_NONBLOCK);
    if (client_fd < 0) {
        return std::nullopt;
    }
    return client_fd;
}

}  // namespace chatroom::net
