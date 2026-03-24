#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace chatroom::net {

class Framer {
public:
    static std::vector<std::uint8_t> Encode(const std::string& payload);
    static std::vector<std::string> ExtractFrames(std::string& input_buffer);
};

}  // namespace chatroom::net
