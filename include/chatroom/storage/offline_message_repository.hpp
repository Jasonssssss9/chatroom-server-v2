#pragma once

#include <string>
#include <vector>

namespace chatroom::storage {

class MySqlClient;

struct OfflineMessageRecord {
    std::string message_id;
    std::string recipient;
    std::string payload_json;
};

class OfflineMessageRepository {
public:
    explicit OfflineMessageRepository(MySqlClient& client);

    [[nodiscard]] bool SaveOfflineMessage(const std::string& recipient, const std::string& payload_json);
    [[nodiscard]] std::vector<OfflineMessageRecord> LoadUndelivered(const std::string& recipient) const;
    [[nodiscard]] bool MarkDelivered(const std::vector<std::string>& message_ids);

private:
    MySqlClient& client_;
};

}  // namespace chatroom::storage
