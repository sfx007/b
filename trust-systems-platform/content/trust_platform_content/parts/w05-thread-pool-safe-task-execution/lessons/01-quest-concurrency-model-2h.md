---
id: w05-thread-pool-safe-task-execution-d01-quest-concurrency-model-2h
part: w05-thread-pool-safe-task-execution
title: "Quest: Concurrency Model  2h"
order: 1
duration_minutes: 20
prereqs: []
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Concurrency Model  2h

## Visual Model

![Visual Model](/visuals/w05-thread-pool-safe-task-execution.svg)



## Lesson Content
### 📖 Learn (30 min)
**C++ threads and shared-state risks**

Key takeaways:
1. Data races are **undefined behavior**
2. Mutex protects invariants
3. Lock scope should be small

### 🔨 Do (80 min)
Define concurrency model (event loop + worker pool responsibilities).

> 🆕 **New constraint:** No shared mutable state without explicit ownership rule.

### ✅ Prove (20 min)
Ownership map of each shared object.

### 📦 Ship
`week-5/day1-concurrency-model.md`

### 💡 Why This Matters
This prevents ad-hoc locking as complexity grows. Clear ownership is the core of safe concurrency. It unlocks predictable task processing.

### 🧠 Self-Check
- [ ] What is a data race?
- [ ] Which state is thread-confined?
- [ ] Which state is shared and why?

