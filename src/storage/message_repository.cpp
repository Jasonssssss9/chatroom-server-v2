#include "chatroom/storage/message_repository.hpp"

#include "chatroom/storage/mysql_client.hpp"

namespace chatroom::storage {

MessageRepository::MessageRepository(MySqlClient& client) : client_(client) {}

bool MessageRepository::PersistDirectMessage(
    const std::string& sender,
    const std::string& recipient,
    const std::string& payload_json) {
    (void)sender;
    (void)recipient;
    (void)payload_json;
    // TODO: insert message history row.
    return client_.Execute("/* TODO: PersistDirectMessage */");
}

}  // namespace chatroom::storage
