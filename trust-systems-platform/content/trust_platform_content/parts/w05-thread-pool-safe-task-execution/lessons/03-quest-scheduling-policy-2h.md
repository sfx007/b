---
id: w05-thread-pool-safe-task-execution-d03-quest-scheduling-policy-2h
part: w05-thread-pool-safe-task-execution
title: "Quest: Scheduling Policy  2h"
order: 3
duration_minutes: 20
prereqs: ["w05-thread-pool-safe-task-execution-d02-quest-bounded-work-queue-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Scheduling Policy  2h

## Visual Model

![Visual Model](/visuals/w05-thread-pool-safe-task-execution.svg)



## Lesson Content
### 📖 Learn (30 min)
**Task scheduling fairness**

Key takeaways:
1. FIFO tradeoffs
2. Starvation risk
3. Task timeouts

### 🔨 Do (80 min)
Define task dispatch rules for CPU-bound work.

> 🆕 **New constraint:** Max task execution budget with cancellation path.

### ✅ Prove (20 min)
Test plan for one long task among many short tasks.

### 📦 Ship
`week-5/day3-scheduling-policy.md`

### 💡 Why This Matters
Fair scheduling keeps latency stable under mixed workloads. This avoids hidden starvation bugs. It unlocks predictable signing/hash workloads.

### 🧠 Self-Check
- [ ] What causes starvation?
- [ ] Why task budget?
- [ ] What should cancellation guarantee?

