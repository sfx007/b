---
id: w05-thread-pool-safe-task-execution-d04-quest-contention-metrics-2h
part: w05-thread-pool-safe-task-execution
title: "Quest: Contention Metrics  2h"
order: 4
duration_minutes: 20
prereqs: ["w05-thread-pool-safe-task-execution-d03-quest-scheduling-policy-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Contention Metrics  2h

## Visual Model

![Visual Model](/visuals/w05-thread-pool-safe-task-execution.svg)



## Lesson Content
### 📖 Learn (30 min)
**Contention measurement basics**

Key takeaways:
1. Lock wait time
2. Queue wait time
3. Throughput-latency tradeoff

### 🔨 Do (80 min)
Define instrumentation points around queue and locks.

> 🆕 **New constraint:** Capture p95 queue wait for every task type.

### ✅ Prove (20 min)
Build metric collection checklist and expected ranges.

### 📦 Ship
`week-5/day4-contention-metrics.md`

### 💡 Why This Matters
Concurrency without measurement is guesswork. This day sets concrete performance evidence. It unlocks objective tuning.

### 🧠 Self-Check
- [ ] Which metric reveals contention first?
- [ ] Why p95 over average?
- [ ] What threshold means overload?

