cmake_minimum_required(VERSION 3.20)
project(chatroom_server_v2 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(CHATROOM_BUILD_TESTS "Build tests" ON)

set(CHATROOM_WARNING_FLAGS
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wsign-conversion
)

set(CHATROOM_SOURCES
    src/app/server_app.cpp
    src/net/epoll_poller.cpp
    src/net/reactor.cpp
    src/net/connection.cpp
    src/net/acceptor.cpp
    src/net/framer.cpp
    src/concurrency/blocking_task_queue.cpp
    src/concurrency/thread_pool.cpp
    src/protocol/json_message_parser.cpp
    src/service/auth_service.cpp
    src/service/direct_message_service.cpp
    src/service/group_message_service.cpp
    src/service/offline_delivery_service.cpp
    src/session/session_manager.cpp
    src/session/connection_registry.cpp
    src/storage/mysql_client.cpp
    src/storage/user_repository.cpp
    src/storage/message_repository.cpp
    src/storage/group_repository.cpp
    src/storage/offline_message_repository.cpp
    src/common/config.cpp
    src/common/logger.cpp
)

add_library(chatroom_core STATIC ${CHATROOM_SOURCES})
target_include_directories(chatroom_core PUBLIC include)
target_compile_options(chatroom_core PRIVATE ${CHATROOM_WARNING_FLAGS})

target_compile_definitions(chatroom_core PRIVATE
    $<$<CONFIG:Debug>:CHATROOM_DEBUG_BUILD>
)

add_executable(chatroom_server src/main.cpp)
target_link_libraries(chatroom_server PRIVATE chatroom_core)
target_compile_options(chatroom_server PRIVATE ${CHATROOM_WARNING_FLAGS})

if(CHATROOM_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
