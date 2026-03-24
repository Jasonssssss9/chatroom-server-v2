#pragma once

#include <string>
#include <utility>

namespace chatroom::common {

enum class ErrorCode {
    kOk = 0,
    kInvalidArgument,
    kNotFound,
    kNotImplemented,
    kInternalError,
};

template <typename T>
class Result {
public:
    static Result<T> Ok(T value) {
        return Result<T>(true, ErrorCode::kOk, {}, std::move(value));
    }

    static Result<T> Err(ErrorCode code, std::string message) {
        return Result<T>(false, code, std::move(message), T{});
    }

    [[nodiscard]] bool ok() const noexcept { return ok_; }
    [[nodiscard]] ErrorCode code() const noexcept { return code_; }
    [[nodiscard]] const std::string& message() const noexcept { return message_; }
    [[nodiscard]] const T& value() const noexcept { return value_; }
    [[nodiscard]] T& value() noexcept { return value_; }

private:
    Result(bool ok, ErrorCode code, std::string message, T value)
        : ok_(ok), code_(code), message_(std::move(message)), value_(std::move(value)) {}

    bool ok_;
    ErrorCode code_;
    std::string message_;
    T value_;
};

}  // namespace chatroom::common
