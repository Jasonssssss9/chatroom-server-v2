#pragma once

#include <chrono>
#include <cstdint>
#include <vector>

namespace chatroom::net {

struct IoEvent {
    int fd{-1};
    std::uint32_t events{0};
};

class EpollPoller {
public:
    EpollPoller();
    ~EpollPoller();

    EpollPoller(const EpollPoller&) = delete;
    EpollPoller& operator=(const EpollPoller&) = delete;

    bool Add(int fd, std::uint32_t events);
    bool Modify(int fd, std::uint32_t events);
    bool Remove(int fd);

    std::vector<IoEvent> Wait(std::chrono::milliseconds timeout);

private:
    int epoll_fd_{-1};
};

}  // namespace chatroom::net
