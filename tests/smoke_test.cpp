#include "chatroom/net/framer.hpp"

int main() {
    const auto frame = chatroom::net::Framer::Encode("ping");
    if (frame.empty()) {
        return 1;
    }
    return 0;
}
