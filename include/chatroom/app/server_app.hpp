#pragma once

#include <atomic>
#include <memory>
#include <string>

namespace chatroom::concurrency {
class ThreadPool;
}
namespace chatroom::net {
class Acceptor;
class EpollPoller;
class Reactor;
}
namespace chatroom::session {
class ConnectionRegistry;
class SessionManager;
}
namespace chatroom::storage {
class MySqlClient;
}
namespace chatroom::common {
class Config;
}

namespace chatroom::app {

class ServerApp {
public:
    ServerApp();
    ~ServerApp();

    bool Initialize(const std::string& config_path);
    void Run();
    void Shutdown();

private:
    std::atomic<bool> running_{false};

    std::unique_ptr<common::Config> config_;
    std::unique_ptr<net::EpollPoller> poller_;
    std::unique_ptr<net::Acceptor> acceptor_;
    std::unique_ptr<net::Reactor> reactor_;
    std::unique_ptr<concurrency::ThreadPool> worker_pool_;
    std::unique_ptr<session::ConnectionRegistry> connection_registry_;
    std::unique_ptr<session::SessionManager> session_manager_;
    std::unique_ptr<storage::MySqlClient> mysql_client_;
};

}  // namespace chatroom::app
