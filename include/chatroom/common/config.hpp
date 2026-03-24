#pragma once

#include <string>
#include <unordered_map>

namespace chatroom::common {

class Config {
public:
    bool LoadFromFile(const std::string& path);

    [[nodiscard]] std::string GetString(const std::string& key, const std::string& fallback = "") const;
    [[nodiscard]] int GetInt(const std::string& key, int fallback = 0) const;

private:
    std::unordered_map<std::string, std::string> values_;
};

}  // namespace chatroom::common
