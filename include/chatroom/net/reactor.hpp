#pragma once

#include <atomic>
#include <chrono>

namespace chatroom::net {

class Acceptor;
class EpollPoller;

class Reactor {
public:
    Reactor(EpollPoller& poller, Acceptor& acceptor);

    void Start();
    void Stop();
    void PollOnce(std::chrono::milliseconds timeout);

    [[nodiscard]] bool IsRunning() const noexcept;

private:
    EpollPoller& poller_;
    Acceptor& acceptor_;
    std::atomic<bool> running_{false};
};

}  // namespace chatroom::net
