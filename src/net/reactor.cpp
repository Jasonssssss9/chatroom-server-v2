#include "chatroom/net/reactor.hpp"

#include "chatroom/net/acceptor.hpp"
#include "chatroom/net/epoll_poller.hpp"

namespace chatroom::net {

Reactor::Reactor(EpollPoller& poller, Acceptor& acceptor) : poller_(poller), acceptor_(acceptor) {}

void Reactor::Start() {
    running_.store(true);
    // TODO: run dedicated reactor thread and event loop.
}

void Reactor::Stop() {
    running_.store(false);
}

void Reactor::PollOnce(std::chrono::milliseconds timeout) {
    (void)acceptor_;
    (void)poller_.Wait(timeout);
    // TODO: handle accept/read/write/error dispatch.
}

bool Reactor::IsRunning() const noexcept {
    return running_.load();
}

}  // namespace chatroom::net
