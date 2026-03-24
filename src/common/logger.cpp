#include "chatroom/common/logger.hpp"

#include <ctime>
#include <iostream>

namespace chatroom::common {

Logger& Logger::Instance() {
    static Logger logger;
    return logger;
}

void Logger::SetLevel(Level level) {
    std::scoped_lock lock(mutex_);
    level_ = level;
}

void Logger::Log(Level level, const std::string& message) {
    std::scoped_lock lock(mutex_);
    if (static_cast<int>(level) < static_cast<int>(level_)) {
        return;
    }

    const std::time_t now = std::time(nullptr);
    std::cout << "[" << ToString(level) << "] [" << now << "] " << message << '\n';
}

const char* Logger::ToString(Level level) const noexcept {
    switch (level) {
        case Level::kDebug:
            return "DEBUG";
        case Level::kInfo:
            return "INFO";
        case Level::kWarn:
            return "WARN";
        case Level::kError:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

}  // namespace chatroom::common
