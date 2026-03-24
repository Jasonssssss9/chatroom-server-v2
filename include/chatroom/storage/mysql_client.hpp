#pragma once

#include <string>

namespace chatroom::storage {

class MySqlClient {
public:
    bool Connect(const std::string& dsn);
    void Disconnect();

    [[nodiscard]] bool Execute(const std::string& sql) const;

private:
    bool connected_{false};
};

}  // namespace chatroom::storage
