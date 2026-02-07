# Week 2 Day 1 — TCP Sockets Server in C++ on Linux

A small, systems‑engineer‑style book that builds a TCP echo server step by step.

---

## 1) Big picture: what problem TCP solves, and how a server “thinks”

**Why**  
When two programs talk across a network, you want reliability: the bytes arrive, in order, and without guessing what was lost. TCP solves this by turning a best‑effort network into a dependable byte stream.

**Analogy: phone call**  
TCP is like a phone call. You dial, the other side picks up, you talk in order, and if the call drops, you know it ended.

**How a server “thinks”**  
A TCP server acts like a receptionist:
1. Opens a front desk (create a listening socket).
2. Posts the address (bind IP + port).
3. Waits for visitors (listen).
4. Accepts a visitor (accept creates a new connection).
5. Talks (recv/send).
6. Ends the conversation (close).

**ASCII mental model**

```
Client                         Server
  |                               |
  | --- connect (TCP handshake) ->|
  |                               |
  | <--- accept returns new FD ---|
  |                               |
  | ---- data ---->               |
  | <--- data ----                |
  |                               |
  | ----------- close ----------> |
```

**Checkpoint quiz**
1) What two guarantees does TCP provide about data?  
2) Why is TCP compared to a phone call?  
3) What is the “front desk” in server terms?

**Exercise**  
Explain in 3 sentences why UDP might be wrong for a chat app.

---

## 2) Core vocabulary: socket, port, IP, bind/listen/accept, FD

**Why**  
Systems engineers think in primitives. These are the primitives that make TCP servers work.

**Vocabulary (plain language)**
- **IP address**: the machine’s street address (e.g., `127.0.0.1` for local).
- **Port**: a door number on that machine (e.g., `8080`).
- **Socket**: a handle to a network endpoint (like a phone handset).
- **bind()**: claims a specific IP + port for a socket.
- **listen()**: tells the OS you’re ready to accept calls.
- **accept()**: accepts one call and creates a **new** socket for it.
- **FD (file descriptor)**: an integer handle for something you can read/write.
- **errno**: a global error code set by failing system calls.

**ASCII map**

```
IP address (machine)
  |
  +-- port 22   (SSH)
  +-- port 80   (HTTP)
  +-- port 8080 (your server)
            |
          socket FD
```

**Checkpoint quiz**
1) What is the difference between IP and port?  
2) Why does `accept()` create a new FD?  
3) What does `listen()` change inside the OS?

**Exercise**  
List three things besides sockets that use file descriptors in Linux.

---

# 3) Step‑by‑step build (chapters)

## Chapter A: `socket()` + error handling

**Why**  
You need a socket before you can bind or listen. It’s like owning a phone before you can give out a number.

**Function explained: `socket()`**
- **Takes**:
  - **Domain** (e.g., `AF_INET` for IPv4)
  - **Type** (`SOCK_STREAM` for TCP)
  - **Protocol** (0 lets the OS choose TCP for `SOCK_STREAM`)
- **Returns**: a new **FD** on success; **-1** on error.
- **Errors**: `-1` with `errno` set (e.g., `EMFILE` = too many open FDs).

**How (code added in this chapter only)**

```cpp
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <iostream>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "socket() failed: " << std::strerror(errno) << "\n";
        return 1;
    }

    close(server_fd);
    return 0;
}
```

**Note on `close()`**  
`close(fd)` takes a file descriptor and releases it. It returns 0 on success, -1 on error.

**Checkpoint quiz**
1) What does `socket()` return on success?  
2) Why is `AF_INET` used here?  
3) What does `SOCK_STREAM` imply?

**Exercise**  
Modify the snippet to print the FD number when `socket()` succeeds.

---

## Chapter B: `bind()` + `sockaddr_in` + `htons/htonl`

**Why**  
A server must announce its address and door so clients can find it. That’s `bind()`.

**Function explained: `bind()`**
- **Takes**:
  - Socket FD
  - Pointer to an address structure
  - Size of that structure
- **Returns**: 0 on success; **-1** on error.
- **Errors**: `EADDRINUSE` (port busy), `EACCES` (privileged port).

**`sockaddr_in`**  
A struct for IPv4 addresses. It stores IP and port in **network byte order**.

**Byte‑order helpers**
- `htons()` = host to network short (16‑bit port).
- `htonl()` = host to network long (32‑bit IP).

**How (code added in this chapter only)**

```cpp
#include <arpa/inet.h> // htons/htonl

sockaddr_in addr{};
addr.sin_family = AF_INET;
addr.sin_port = htons(8080);
addr.sin_addr.s_addr = htonl(INADDR_ANY);

if (bind(server_fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1) {
    std::cerr << "bind() failed: " << std::strerror(errno) << "\n";
    close(server_fd);
    return 1;
}
```

**Checkpoint quiz**
1) Why do we need `htons()`?  
2) What does `INADDR_ANY` mean?  
3) What does `bind()` return on failure?

**Exercise**  
Change the port to 9090 and explain what `htons(9090)` does.

---

## Chapter C: `listen()` + backlog

**Why**  
Binding reserves the address. Listening tells the kernel to **start queueing** incoming calls.

**Function explained: `listen()`**
- **Takes**: socket FD, backlog size.
- **Returns**: 0 on success; **-1** on error.
- **Errors**: `EINVAL` (not bound or invalid FD).

**Backlog analogy**  
A restaurant’s waiting list. If the host can’t seat you now, you wait in a queue.

**How (code added in this chapter only)**

```cpp
if (listen(server_fd, 10) == -1) {
    std::cerr << "listen() failed: " << std::strerror(errno) << "\n";
    close(server_fd);
    return 1;
}
```

**Checkpoint quiz**
1) Does `listen()` accept a client?  
2) What is backlog for?  
3) What happens if the queue is full?

**Exercise**  
Pick a backlog value and explain why you chose it.

---

## Chapter D: `accept()` returns a NEW FD (explain clearly)

**Why**  
Each client needs its own dedicated line. `accept()` creates that line.

**Key idea**  
- The **listening FD** is like a front desk.  
- `accept()` returns a **new FD** for the client.  
- You keep the listening FD for future clients.

**Function explained: `accept()`**
- **Takes**: listening FD, optional client address buffer, and its size.
- **Returns**: **new** client FD; **-1** on error.
- **Errors**: `EINTR` (interrupted), `ECONNABORTED`.

**ASCII**

```
listening FD (server_fd)
          |
          +-- accept() --> client FD (client_fd)
```

**How (code added in this chapter only)**

```cpp
sockaddr_in client_addr{};
socklen_t client_len = sizeof(client_addr);

int client_fd = accept(server_fd,
                       reinterpret_cast<sockaddr*>(&client_addr),
                       &client_len);
if (client_fd == -1) {
    std::cerr << "accept() failed: " << std::strerror(errno) << "\n";
    close(server_fd);
    return 1;
}
```

**Checkpoint quiz**
1) Which FD do you use to talk to the client?  
2) Does `accept()` destroy the listening FD?  
3) What does `accept()` return on error?

**Exercise**  
Explain in your own words why we need two FDs.

---

## Chapter E: `recv()/send()` loop + detect client disconnect

**Why**  
TCP is a stream. Data can arrive in chunks, so you must loop and keep reading.

**Function explained: `recv()`**
- **Takes**: client FD, buffer pointer, buffer size, flags.
- **Returns**:
  - **>0** bytes read
  - **0** = peer closed connection
  - **-1** = error (`errno` set)

**Function explained: `send()`**
- **Takes**: client FD, buffer pointer, number of bytes, flags.
- **Returns**: bytes sent or **-1** on error.
- **Note**: can send fewer bytes than requested (partial send).

**How to detect disconnect**  
If `recv()` returns **0**, the client closed the connection cleanly.

**How (code added in this chapter only)**

```cpp
char buf[1024];
while (true) {
    ssize_t n = recv(client_fd, buf, sizeof(buf), 0);
    if (n == 0) {
        // client disconnected
        break;
    }
    if (n == -1) {
        if (errno == EINTR) continue;
        std::cerr << "recv() failed: " << std::strerror(errno) << "\n";
        break;
    }

    ssize_t sent = send(client_fd, buf, static_cast<size_t>(n), 0);
    if (sent == -1) {
        std::cerr << "send() failed: " << std::strerror(errno) << "\n";
        break;
    }
}
```

**Checkpoint quiz**
1) What does `recv()` returning 0 mean?  
2) Can `send()` return fewer bytes than you asked?  
3) Why do we loop on `recv()`?

**Exercise**  
Modify the loop to print how many bytes were received each time.

---

## Chapter F: `SO_REUSEADDR` and “Address already in use”

**Why**  
After a server exits, the port can remain in `TIME_WAIT`. The kernel protects old connections, so rebinding fails.

**Function explained: `setsockopt()`**
- **Takes**: socket FD, level (`SOL_SOCKET`), option name, pointer to value, size.
- **Returns**: 0 on success; **-1** on error.
- **Errors**: `ENOPROTOOPT` if the option isn’t supported.

**Why `SO_REUSEADDR`**  
It tells the OS, “Let me bind even if the port is in `TIME_WAIT`.”

**How (code added in this chapter only)**

```cpp
int opt = 1;
if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
    std::cerr << "setsockopt() failed: " << std::strerror(errno) << "\n";
    close(server_fd);
    return 1;
}
```

**Checkpoint quiz**
1) Why does “Address already in use” happen after restart?  
2) Where should `setsockopt()` be called?  
3) What does `SO_REUSEADDR` change?

**Exercise**  
Restart your server quickly twice. Observe the error with and without `SO_REUSEADDR`.

---

## Chapter G: graceful shutdown with Ctrl+C flag pattern

**Why**  
You need a safe way to stop the server. Signal handlers must be minimal and safe (no `std::cout`).

**Signal handler rule**  
Only set a flag of type `volatile sig_atomic_t` in the handler.

**Function explained: `signal()`**
- **Takes**: a signal number (e.g., `SIGINT`) and a handler function.
- **Returns**: previous handler or `SIG_ERR` on failure.

**How (code added in this chapter only)**

```cpp
#include <csignal>

volatile sig_atomic_t g_stop = 0;

void handle_sigint(int) {
    g_stop = 1; // async-signal-safe
}

if (signal(SIGINT, handle_sigint) == SIG_ERR) {
    std::cerr << "signal() failed\n";
    return 1;
}
```

**Checkpoint quiz**
1) Why can’t we use `std::cout` in a signal handler?  
2) What type should the stop flag be?  
3) What does `signal()` return on failure?

**Exercise**  
Add a check that breaks the recv loop when `g_stop` becomes 1.

---

# 4) Testing chapter

**Why**  
A server isn’t real until you test it. `nc` is a quick TCP client.

**How to test with `nc`**

Terminal 1:
```
./echo_server
```

Terminal 2:
```
nc 127.0.0.1 8080
```

Type messages in terminal 2 and you should see them echoed back.

**What to expect in terminal output**
- Server prints “Listening on port 8080…”
- After a client connects, server prints “Client connected.”
- Client sees each line echoed.

**Checkpoint quiz**
1) What does `nc 127.0.0.1 8080` do?  
2) What should you see when typing text?  
3) What happens if the server is not running?

**Exercise**  
Connect with `nc` and send three different lines; confirm all are echoed.

---

# 5) Debugging chapter

**Why**  
Networking bugs are invisible without tools. You need visibility into ports and packets.

**Tools (brief)**
- `lsof -i :8080` — shows which process owns the port.
- `ss -ltnp` (or `netstat -ltnp`) — shows listening TCP sockets.
- `tcpdump -i lo tcp port 8080` — sniffs packets on loopback.

**Typical mistakes**
- Wrong port (client on 8081, server on 8080).
- Missing `htons()` (port looks wrong to clients).
- `recv()` returns 0 (client closed).
- Partial reads/writes (assume one recv is the whole message).

**Checkpoint quiz**
1) Which tool tells you what process owns a port?  
2) What does `recv()` returning 0 indicate?  
3) Why does missing `htons()` break connections?

**Exercise**  
Bind to 8080, then run `lsof -i :8080`. Identify the PID.

---

# 6) Final combined code: echo server (single‑client) with comments

**Why**  
Now that every piece is understood, we combine them into a working single‑client echo server.

**How (complete code)**

```cpp
// echo_server.cpp
#include <arpa/inet.h>
#include <cerrno>
#include <csignal>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

volatile sig_atomic_t g_stop = 0;

void handle_sigint(int) {
    g_stop = 1; // async-signal-safe
}

int main() {
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        std::cerr << "signal() failed\n";
        return 1;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "socket() failed: " << std::strerror(errno) << "\n";
        return 1;
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        std::cerr << "setsockopt() failed: " << std::strerror(errno) << "\n";
        close(server_fd);
        return 1;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1) {
        std::cerr << "bind() failed: " << std::strerror(errno) << "\n";
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) == -1) {
        std::cerr << "listen() failed: " << std::strerror(errno) << "\n";
        close(server_fd);
        return 1;
    }

    std::cout << "Listening on port 8080...\n";

    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(server_fd, reinterpret_cast<sockaddr*>(&client_addr), &client_len);
    if (client_fd == -1) {
        std::cerr << "accept() failed: " << std::strerror(errno) << "\n";
        close(server_fd);
        return 1;
    }

    std::cout << "Client connected.\n";

    char buf[1024];
    while (!g_stop) {
        ssize_t n = recv(client_fd, buf, sizeof(buf), 0);
        if (n == 0) {
            std::cout << "Client disconnected.\n";
            break;
        }
        if (n == -1) {
            if (errno == EINTR) continue;
            std::cerr << "recv() failed: " << std::strerror(errno) << "\n";
            break;
        }

        ssize_t sent = send(client_fd, buf, static_cast<size_t>(n), 0);
        if (sent == -1) {
            std::cerr << "send() failed: " << std::strerror(errno) << "\n";
            break;
        }
    }

    close(client_fd);
    close(server_fd);
    std::cout << "Server shutdown.\n";
    return 0;
}
```

**Build and test**

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic echo_server.cpp -o echo_server
./echo_server
```

In another terminal:

```bash
nc 127.0.0.1 8080
```

Type text; it should echo back.

**Checkpoint quiz**
1) Which FD is used for `recv()`/`send()`?  
2) Where is `SO_REUSEADDR` set?  
3) What breaks the recv loop?

**Exercise**  
Change the port to 9090 and update your `nc` command accordingly.

---

# 7) Summary: 10 bullet “rules of thumb” to remember

- Always `socket()` first; check for `-1` and `errno`.
- `bind()` must use network byte order (`htons`, `htonl`).
- `listen()` starts the queue; it does not accept clients.
- `accept()` returns a **new FD**; don’t lose the listening FD.
- `recv()` returning **0** means the peer closed the connection.
- `send()` can be partial; don’t assume it sent everything.
- Use `SO_REUSEADDR` to avoid “Address already in use.”
- Use a signal flag (`sig_atomic_t`) for Ctrl+C shutdown.
- Close both client and server FDs.
- Test early with `nc` and inspect with `ss` or `lsof`.

**Checkpoint quiz**
1) What does `recv()` returning 0 mean?  
2) Why do we keep the listening FD after `accept()`?  
3) What does `SO_REUSEADDR` prevent?

**Exercise**  
Write a 5‑line “server checklist” you will use before every test run.

