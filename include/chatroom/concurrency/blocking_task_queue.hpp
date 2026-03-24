#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>

namespace chatroom::concurrency {

using Task = std::function<void()>;

class BlockingTaskQueue {
public:
    void Push(Task task);
    bool Pop(Task& task);
    void Shutdown();

private:
    std::queue<Task> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool closed_{false};
};

}  // namespace chatroom::concurrency
