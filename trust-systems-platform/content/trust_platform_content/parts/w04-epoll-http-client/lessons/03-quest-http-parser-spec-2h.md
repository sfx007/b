---
id: w04-epoll-http-client-d03-quest-http-parser-spec-2h
part: w04-epoll-http-client
title: "Quest: HTTP Parser Spec  2h"
order: 3
duration_minutes: 20
prereqs: ["w04-epoll-http-client-d02-quest-timer-design-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: HTTP Parser Spec  2h

## Visual Model

![Visual Model](/visuals/w04-epoll-http-client.svg)



## Lesson Content
### 📖 Learn (30 min)
**HTTP/1.1 essentials for clients**

Key takeaways:
1. Request line + headers
2. Status code families
3. `Content-Length` parsing

### 🔨 Do (80 min)
Specify simple HTTP client request/response parser behavior.

> 🆕 **New constraint:** Reject malformed headers with explicit error class.

### ✅ Prove (20 min)
Build parser test list for normal and malformed responses.

### 📦 Ship
`week-4/day3-http-parser-spec.md`

### 💡 Why This Matters
HTTP gives practical protocol parsing experience beyond echo. This day strengthens input-safety habits. It unlocks health-check integrations for later services.

### 🧠 Self-Check
- [ ] What is minimal valid HTTP response?
- [ ] How detect malformed headers?
- [ ] Why parse `Content-Length` carefully?

