#pragma once

#include <optional>
#include <string>

namespace chatroom::storage {

class MySqlClient;

class UserRepository {
public:
    explicit UserRepository(MySqlClient& client);

    [[nodiscard]] bool CreateUser(const std::string& user_id, const std::string& password_hash);
    [[nodiscard]] std::optional<std::string> GetPasswordHash(const std::string& user_id) const;

private:
    MySqlClient& client_;
};

}  // namespace chatroom::storage
