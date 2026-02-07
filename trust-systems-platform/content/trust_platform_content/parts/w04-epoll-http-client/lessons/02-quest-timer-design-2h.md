---
id: w04-epoll-http-client-d02-quest-timer-design-2h
part: w04-epoll-http-client
title: "Quest: Timer Design  2h"
order: 2
duration_minutes: 20
prereqs: ["w04-epoll-http-client-d01-quest-epoll-strategy-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Timer Design  2h

## Visual Model

![Visual Model](/visuals/w04-epoll-http-client.svg)



## Lesson Content
### 📖 Learn (30 min)
**Timer integration with event loops**

Key takeaways:
1. Idle timeout wheel/heap
2. Timer drift awareness
3. Cleanup scheduling

### 🔨 Do (80 min)
Define idle timeout and periodic health checks.

> 🆕 **New constraint:** Stale connections removed without scanning all clients each tick.

### ✅ Prove (20 min)
Timeout-accuracy measurement plan.

### 📦 Ship
`week-4/day2-timer-design.md`

### 💡 Why This Matters
Timers prevent silent resource hoarding. This day adds temporal correctness to your server. It unlocks robust slow-client control.

### 🧠 Self-Check
- [ ] Why avoid full scans?
- [ ] What timer accuracy is acceptable?
- [ ] How log timeout reasons?

