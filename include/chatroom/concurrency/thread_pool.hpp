#pragma once

#include "chatroom/concurrency/blocking_task_queue.hpp"

#include <atomic>
#include <cstddef>
#include <thread>
#include <vector>

namespace chatroom::concurrency {

class ThreadPool {
public:
    explicit ThreadPool(std::size_t thread_count = 4);
    ~ThreadPool();

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    void Start();
    void Stop();
    void Submit(Task task);

private:
    void WorkerLoop();

    std::size_t thread_count_;
    std::atomic<bool> running_{false};
    BlockingTaskQueue queue_;
    std::vector<std::thread> workers_;
};

}  // namespace chatroom::concurrency
