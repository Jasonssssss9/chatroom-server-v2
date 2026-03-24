#include "chatroom/app/server_app.hpp"

#include "chatroom/common/config.hpp"
#include "chatroom/common/logger.hpp"
#include "chatroom/concurrency/thread_pool.hpp"
#include "chatroom/net/acceptor.hpp"
#include "chatroom/net/epoll_poller.hpp"
#include "chatroom/net/reactor.hpp"
#include "chatroom/session/connection_registry.hpp"
#include "chatroom/session/session_manager.hpp"
#include "chatroom/storage/mysql_client.hpp"

namespace chatroom::app {

ServerApp::ServerApp() = default;

ServerApp::~ServerApp() {
    Shutdown();
}

bool ServerApp::Initialize(const std::string& config_path) {
    config_ = std::make_unique<common::Config>();
    if (!config_->LoadFromFile(config_path)) {
        common::Logger::Instance().Log(common::Logger::Level::kError, "Failed to load config: " + config_path);
        return false;
    }

    poller_ = std::make_unique<net::EpollPoller>();
    acceptor_ = std::make_unique<net::Acceptor>();
    connection_registry_ = std::make_unique<session::ConnectionRegistry>();
    session_manager_ = std::make_unique<session::SessionManager>();
    reactor_ = std::make_unique<net::Reactor>(*poller_, *acceptor_);
    worker_pool_ = std::make_unique<concurrency::ThreadPool>();
    mysql_client_ = std::make_unique<storage::MySqlClient>();

    common::Logger::Instance().Log(common::Logger::Level::kInfo, "ServerApp initialized");
    return true;
}

void ServerApp::Run() {
    running_.store(true);
    if (worker_pool_ != nullptr) {
        worker_pool_->Start();
    }
    if (reactor_ != nullptr) {
        reactor_->Start();
    }
}

void ServerApp::Shutdown() {
    const bool was_running = running_.exchange(false);
    if (!was_running) {
        return;
    }

    if (reactor_ != nullptr) {
        reactor_->Stop();
    }
    if (worker_pool_ != nullptr) {
        worker_pool_->Stop();
    }

    common::Logger::Instance().Log(common::Logger::Level::kInfo, "ServerApp shutdown complete");
}

}  // namespace chatroom::app
