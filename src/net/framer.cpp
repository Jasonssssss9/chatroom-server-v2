#include "chatroom/net/framer.hpp"

#include <cstring>

namespace chatroom::net {

std::vector<std::uint8_t> Framer::Encode(const std::string& payload) {
    const std::uint32_t len = static_cast<std::uint32_t>(payload.size());
    std::vector<std::uint8_t> out(sizeof(std::uint32_t) + payload.size());

    out[0] = static_cast<std::uint8_t>((len >> 24) & 0xFF);
    out[1] = static_cast<std::uint8_t>((len >> 16) & 0xFF);
    out[2] = static_cast<std::uint8_t>((len >> 8) & 0xFF);
    out[3] = static_cast<std::uint8_t>(len & 0xFF);
    std::memcpy(out.data() + sizeof(std::uint32_t), payload.data(), payload.size());
    return out;
}

std::vector<std::string> Framer::ExtractFrames(std::string& input_buffer) {
    std::vector<std::string> frames;

    while (input_buffer.size() >= sizeof(std::uint32_t)) {
        const std::uint32_t len =
            (static_cast<std::uint8_t>(input_buffer[0]) << 24) |
            (static_cast<std::uint8_t>(input_buffer[1]) << 16) |
            (static_cast<std::uint8_t>(input_buffer[2]) << 8) |
            (static_cast<std::uint8_t>(input_buffer[3]));

        const std::size_t frame_size = sizeof(std::uint32_t) + static_cast<std::size_t>(len);
        if (input_buffer.size() < frame_size) {
            break;
        }

        frames.emplace_back(input_buffer.substr(sizeof(std::uint32_t), len));
        input_buffer.erase(0, frame_size);
    }

    return frames;
}

}  // namespace chatroom::net
