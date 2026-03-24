#include "chatroom/protocol/json_message_parser.hpp"

namespace chatroom::protocol {

common::Result<MessageEnvelope> JsonMessageParser::Parse(const std::string& frame_payload) const {
    if (frame_payload.empty()) {
        return common::Result<MessageEnvelope>::Err(common::ErrorCode::kInvalidArgument, "empty frame payload");
    }

    // TODO: parse JSON and validate message schema.
    MessageEnvelope envelope;
    envelope.payload_json = frame_payload;
    return common::Result<MessageEnvelope>::Ok(std::move(envelope));
}

}  // namespace chatroom::protocol
