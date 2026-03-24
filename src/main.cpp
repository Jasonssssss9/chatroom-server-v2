#include "chatroom/app/server_app.hpp"

#include <cstdlib>

int main() {
    chatroom::app::ServerApp app;
    if (!app.Initialize("configs/server.yaml")) {
        return EXIT_FAILURE;
    }

    app.Run();
    app.Shutdown();
    return EXIT_SUCCESS;
}
