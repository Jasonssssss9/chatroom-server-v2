#pragma once

#include <string>
#include <vector>

namespace chatroom::storage {

class MySqlClient;

class GroupRepository {
public:
    explicit GroupRepository(MySqlClient& client);

    [[nodiscard]] bool CreateGroup(const std::string& group_id, const std::string& owner_user_id);
    [[nodiscard]] std::vector<std::string> ListMembers(const std::string& group_id) const;

private:
    MySqlClient& client_;
};

}  // namespace chatroom::storage
