#pragma once

#include <mutex>
#include <string>

namespace chatroom::common {

class Logger {
public:
    enum class Level {
        kDebug,
        kInfo,
        kWarn,
        kError,
    };

    static Logger& Instance();

    void SetLevel(Level level);
    void Log(Level level, const std::string& message);

private:
    Logger() = default;

    [[nodiscard]] const char* ToString(Level level) const noexcept;

    Level level_{Level::kInfo};
    std::mutex mutex_;
};

}  // namespace chatroom::common
