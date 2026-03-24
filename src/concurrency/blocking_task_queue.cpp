#include "chatroom/concurrency/blocking_task_queue.hpp"

namespace chatroom::concurrency {

void BlockingTaskQueue::Push(Task task) {
    {
        std::scoped_lock lock(mutex_);
        if (closed_) {
            return;
        }
        queue_.push(std::move(task));
    }
    cv_.notify_one();
}

bool BlockingTaskQueue::Pop(Task& task) {
    std::unique_lock lock(mutex_);
    cv_.wait(lock, [this] { return closed_ || queue_.empty() == false; });
    if (queue_.empty()) {
        return false;
    }
    task = std::move(queue_.front());
    queue_.pop();
    return true;
}

void BlockingTaskQueue::Shutdown() {
    {
        std::scoped_lock lock(mutex_);
        closed_ = true;
    }
    cv_.notify_all();
}

}  // namespace chatroom::concurrency
