#include "chatroom/net/epoll_poller.hpp"

#include <sys/epoll.h>
#include <unistd.h>

namespace chatroom::net {

EpollPoller::EpollPoller() {
    epoll_fd_ = epoll_create1(0);
}

EpollPoller::~EpollPoller() {
    if (epoll_fd_ >= 0) {
        close(epoll_fd_);
    }
}

bool EpollPoller::Add(int fd, std::uint32_t events) {
    epoll_event ev{};
    ev.data.fd = fd;
    ev.events = events;
    return epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &ev) == 0;
}

bool EpollPoller::Modify(int fd, std::uint32_t events) {
    epoll_event ev{};
    ev.data.fd = fd;
    ev.events = events;
    return epoll_ctl(epoll_fd_, EPOLL_CTL_MOD, fd, &ev) == 0;
}

bool EpollPoller::Remove(int fd) {
    return epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, nullptr) == 0;
}

std::vector<IoEvent> EpollPoller::Wait(std::chrono::milliseconds timeout) {
    constexpr int kMaxEvents = 128;
    epoll_event events[kMaxEvents];

    const int ready = epoll_wait(epoll_fd_, events, kMaxEvents, static_cast<int>(timeout.count()));
    std::vector<IoEvent> out;
    if (ready <= 0) {
        return out;
    }

    out.reserve(static_cast<std::size_t>(ready));
    for (int i = 0; i < ready; ++i) {
        out.push_back(IoEvent{events[i].data.fd, events[i].events});
    }
    return out;
}

}  // namespace chatroom::net
