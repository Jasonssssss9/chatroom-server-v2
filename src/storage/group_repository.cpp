#include "chatroom/storage/group_repository.hpp"

#include "chatroom/storage/mysql_client.hpp"

namespace chatroom::storage {

GroupRepository::GroupRepository(MySqlClient& client) : client_(client) {}

bool GroupRepository::CreateGroup(const std::string& group_id, const std::string& owner_user_id) {
    (void)group_id;
    (void)owner_user_id;
    // TODO: insert group + owner membership rows.
    return client_.Execute("/* TODO: CreateGroup */");
}

std::vector<std::string> GroupRepository::ListMembers(const std::string& group_id) const {
    (void)group_id;
    // TODO: select all group members.
    return {};
}

}  // namespace chatroom::storage
