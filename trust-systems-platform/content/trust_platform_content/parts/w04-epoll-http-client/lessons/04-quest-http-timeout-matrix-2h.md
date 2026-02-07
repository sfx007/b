---
id: w04-epoll-http-client-d04-quest-http-timeout-matrix-2h
part: w04-epoll-http-client
title: "Quest: HTTP Timeout Matrix  2h"
order: 4
duration_minutes: 20
prereqs: ["w04-epoll-http-client-d03-quest-http-parser-spec-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: HTTP Timeout Matrix  2h

## Visual Model

![Visual Model](/visuals/w04-epoll-http-client.svg)



## Lesson Content
### 📖 Learn (30 min)
**DNS/connect timeout behavior**

Key takeaways:
1. Connection phases
2. Timeout per phase
3. Distinguish transient vs permanent failures

### 🔨 Do (80 min)
Define HTTP client timeout and retry policy.

> 🆕 **New constraint:** Separate connect timeout from read timeout.

### ✅ Prove (20 min)
Failure matrix for unreachable host, slow server, partial response.

### 📦 Ship
`week-4/day4-http-timeout-matrix.md`

### 💡 Why This Matters
Separate timeout classes improve diagnosis and resilience. This mirrors real production client behavior. It unlocks robust node-to-node RPC later.

### 🧠 Self-Check
- [ ] Why separate connect/read timeout?
- [ ] Which failures are retryable?
- [ ] How should retry budget be set?

