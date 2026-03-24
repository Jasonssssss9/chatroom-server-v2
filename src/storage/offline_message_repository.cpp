#include "chatroom/storage/offline_message_repository.hpp"

#include "chatroom/storage/mysql_client.hpp"

namespace chatroom::storage {

OfflineMessageRepository::OfflineMessageRepository(MySqlClient& client) : client_(client) {}

bool OfflineMessageRepository::SaveOfflineMessage(const std::string& recipient, const std::string& payload_json) {
    (void)recipient;
    (void)payload_json;
    // TODO: insert undelivered offline message.
    return client_.Execute("/* TODO: SaveOfflineMessage */");
}

std::vector<OfflineMessageRecord> OfflineMessageRepository::LoadUndelivered(const std::string& recipient) const {
    (void)recipient;
    // TODO: select undelivered messages by recipient.
    return {};
}

bool OfflineMessageRepository::MarkDelivered(const std::vector<std::string>& message_ids) {
    (void)message_ids;
    // TODO: update delivery status in bulk.
    return client_.Execute("/* TODO: MarkDelivered */");
}

}  // namespace chatroom::storage
