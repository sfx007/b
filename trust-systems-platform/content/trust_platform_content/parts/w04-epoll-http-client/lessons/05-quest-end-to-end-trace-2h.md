---
id: w04-epoll-http-client-d05-quest-end-to-end-trace-2h
part: w04-epoll-http-client
title: "Quest: End-to-End Trace  2h"
order: 5
duration_minutes: 20
prereqs: ["w04-epoll-http-client-d04-quest-http-timeout-matrix-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: End-to-End Trace  2h

## Visual Model

![Visual Model](/visuals/w04-epoll-http-client.svg)



## Lesson Content
### 📖 Learn (30 min)
**Integration testing with local endpoints**

Key takeaways:
1. Deterministic fixtures
2. Request IDs across client/server
3. Reproducible logs

### 🔨 Do (80 min)
Define tests where HTTP client queries your server health endpoint.

> 🆕 **New constraint:** Consistent correlation ID across both tools.

### ✅ Prove (20 min)
End-to-end trace from request to server response log.

### 📦 Ship
`week-4/day5-e2e-trace.md`

### 💡 Why This Matters
End-to-end visibility is a systems superpower. This day links independent components through shared observability. It unlocks easier multi-node debugging next month.

### 🧠 Self-Check
- [ ] What was traced end-to-end?
- [ ] Why correlation ID matters?
- [ ] Which logs were required to debug one request?

