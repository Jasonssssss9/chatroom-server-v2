#include "chatroom/concurrency/thread_pool.hpp"

namespace chatroom::concurrency {

ThreadPool::ThreadPool(std::size_t thread_count) : thread_count_(thread_count) {}

ThreadPool::~ThreadPool() {
    Stop();
}

void ThreadPool::Start() {
    if (running_.exchange(true)) {
        return;
    }

    workers_.reserve(thread_count_);
    for (std::size_t i = 0; i < thread_count_; ++i) {
        workers_.emplace_back([this] { WorkerLoop(); });
    }
}

void ThreadPool::Stop() {
    if (running_.exchange(false) == false) {
        return;
    }

    queue_.Shutdown();
    for (auto& worker : workers_) {
        if (worker.joinable()) {
            worker.join();
        }
    }
    workers_.clear();
}

void ThreadPool::Submit(Task task) {
    queue_.Push(std::move(task));
}

void ThreadPool::WorkerLoop() {
    Task task;
    while (queue_.Pop(task)) {
        if (task) {
            task();
        }
        if (running_.load() == false) {
            break;
        }
    }
}

}  // namespace chatroom::concurrency
