#pragma once

#include <string>

namespace chatroom::storage {

class MySqlClient;

class MessageRepository {
public:
    explicit MessageRepository(MySqlClient& client);

    [[nodiscard]] bool PersistDirectMessage(
        const std::string& sender,
        const std::string& recipient,
        const std::string& payload_json);

private:
    MySqlClient& client_;
};

}  // namespace chatroom::storage
