---
id: w03-multi-client-event-loop-d04-quest-poll-migration-2h
part: w03-multi-client-event-loop
title: "Quest: Poll Migration  2h"
order: 4
duration_minutes: 20
prereqs: ["w03-multi-client-event-loop-d03-quest-backpressure-policy-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Poll Migration  2h

## Visual Model

![Visual Model](/visuals/w03-multi-client-event-loop.svg)



## Lesson Content
### 📖 Learn (30 min)
**`poll` advantages over `select`**

Key takeaways:
1. Dynamic fd list
2. Simpler scaling
3. Cleaner event iteration

### 🔨 Do (80 min)
Plan migration from `select` to `poll`.

> 🆕 **New constraint:** Preserve exact protocol behavior while changing poller.

### ✅ Prove (20 min)
Regression checklist comparing outputs before/after migration.

### 📦 Ship
`week-3/day4-poll-migration-checklist.md`

### 💡 Why This Matters
You practice changing internals without changing behavior. This is key for long-lived systems. It unlocks future epoll upgrade with confidence.

### 🧠 Self-Check
- [ ] What behavior must stay identical?
- [ ] Why swap poller now?
- [ ] How do you detect regression quickly?

