---
id: w03-multi-client-event-loop-d05-quest-connection-lifecycle-tests-2h
part: w03-multi-client-event-loop
title: "Quest: Connection Lifecycle Tests  2h"
order: 5
duration_minutes: 20
prereqs: ["w03-multi-client-event-loop-d04-quest-poll-migration-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Connection Lifecycle Tests  2h

## Visual Model

![Visual Model](/visuals/w03-multi-client-event-loop.svg)



## Lesson Content
### 📖 Learn (30 min)
**Connection churn handling**

Key takeaways:
1. Half-close states
2. Cleanup ordering
3. fd leak detection

### 🔨 Do (80 min)
Define lifecycle for open/read/write/error/close paths.

> 🆕 **New constraint:** Zero descriptor leaks under churn.

### ✅ Prove (20 min)
Run a churn script plan with leak counter target.

### 📦 Ship
`week-3/day5-connection-lifecycle-tests.md`

### 💡 Why This Matters
Resource leaks kill long-running services quietly. This day adds operational durability, not just correctness. It unlocks safe long soak tests.

### 🧠 Self-Check
- [ ] What is half-close?
- [ ] How do fd leaks appear?
- [ ] What cleanup order is safest?

