add_executable(chatroom_smoke_test smoke_test.cpp)
target_link_libraries(chatroom_smoke_test PRIVATE chatroom_core)
target_compile_options(chatroom_smoke_test PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME chatroom_smoke_test COMMAND chatroom_smoke_test)
