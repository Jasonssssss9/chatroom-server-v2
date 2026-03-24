# Chatroom Server V2

`chatroom-server-v2` is a modern C++ chatroom server for Linux focused on high concurrency and real-time communication.

## Current Status

This repository is currently in the **architecture skeleton stage**.
Core module boundaries, build system, and class scaffolding are in place.
Detailed networking behavior, business logic, and persistence flows are intentionally left for later implementation steps.

## High-Level Architecture

- Main thread: startup, initialization, coordination, shutdown
- Reactor thread: epoll-driven network I/O and frame extraction
- Worker thread pool: full request lifecycle processing
- Protocol layer: length-prefixed framing + JSON request parsing
- Service layer: auth, direct messaging, group messaging, offline delivery
- Session layer: user/session/connection runtime mappings
- Storage layer: MySQL-backed repositories

## Notes

- TCP long-lived connections with non-blocking sockets + epoll + Reactor pattern
- Per-connection outbound queues are part of the network/session runtime model
- Offline messages are intended for MySQL persistence (not file-based)

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
ctest --test-dir build
```

