---
id: w05-thread-pool-safe-task-execution-d02-quest-bounded-work-queue-2h
part: w05-thread-pool-safe-task-execution
title: "Quest: Bounded Work Queue  2h"
order: 2
duration_minutes: 20
prereqs: ["w05-thread-pool-safe-task-execution-d01-quest-concurrency-model-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Bounded Work Queue  2h

## Visual Model

![Visual Model](/visuals/w05-thread-pool-safe-task-execution.svg)



## Lesson Content
### 📖 Learn (30 min)
**Producer-consumer queues**

Key takeaways:
1. Condition-variable signaling
2. Spurious wakeups
3. Bounded capacity

### 🔨 Do (80 min)
Design bounded work queue for worker pool.

> 🆕 **New constraint:** Hard max queue depth with explicit rejection behavior.

### ✅ Prove (20 min)
Overload scenario test plan at queue full condition.

### 📦 Ship
`week-5/day2-bounded-queue-spec.md`

### 💡 Why This Matters
Unbounded queues hide overload until memory collapses. This day makes overload visible and controllable. It unlocks backpressure strategy next week.

### 🧠 Self-Check
- [ ] Why bounded queue?
- [ ] What happens when full?
- [ ] What is correct wake-up condition?

