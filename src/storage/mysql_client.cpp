#include "chatroom/storage/mysql_client.hpp"

namespace chatroom::storage {

bool MySqlClient::Connect(const std::string& dsn) {
    (void)dsn;
    // TODO: connect via MySQL client library.
    connected_ = true;
    return connected_;
}

void MySqlClient::Disconnect() {
    connected_ = false;
}

bool MySqlClient::Execute(const std::string& sql) const {
    (void)sql;
    // TODO: execute SQL through prepared statements.
    return connected_;
}

}  // namespace chatroom::storage
