#include "chatroom/storage/user_repository.hpp"

#include "chatroom/storage/mysql_client.hpp"

namespace chatroom::storage {

UserRepository::UserRepository(MySqlClient& client) : client_(client) {}

bool UserRepository::CreateUser(const std::string& user_id, const std::string& password_hash) {
    (void)user_id;
    (void)password_hash;
    // TODO: insert user row.
    return client_.Execute("/* TODO: CreateUser */");
}

std::optional<std::string> UserRepository::GetPasswordHash(const std::string& user_id) const {
    (void)user_id;
    // TODO: select password hash.
    return std::nullopt;
}

}  // namespace chatroom::storage
