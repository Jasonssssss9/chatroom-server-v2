#include "chatroom/common/config.hpp"

#include <fstream>

namespace chatroom::common {

bool Config::LoadFromFile(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return false;
    }

    // TODO: replace with robust config parsing.
    values_["config.path"] = path;
    return true;
}

std::string Config::GetString(const std::string& key, const std::string& fallback) const {
    const auto it = values_.find(key);
    if (it == values_.end()) {
        return fallback;
    }
    return it->second;
}

int Config::GetInt(const std::string& key, int fallback) const {
    const auto it = values_.find(key);
    if (it == values_.end()) {
        return fallback;
    }

    try {
        return std::stoi(it->second);
    } catch (...) {
        return fallback;
    }
}

}  // namespace chatroom::common
