---
id: w05-thread-pool-safe-task-execution-d05-quest-graceful-shutdown-2h
part: w05-thread-pool-safe-task-execution
title: "Quest: Graceful Shutdown  2h"
order: 5
duration_minutes: 20
prereqs: ["w05-thread-pool-safe-task-execution-d04-quest-contention-metrics-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Graceful Shutdown  2h

## Visual Model

![Visual Model](/visuals/w05-thread-pool-safe-task-execution.svg)



## Lesson Content
### 📖 Learn (30 min)
**Graceful shutdown design**

Key takeaways:
1. Stop intake first
2. Drain queue
3. Join workers safely

### 🔨 Do (80 min)
Define shutdown sequence and deadlines.

> 🆕 **New constraint:** Zero task loss for accepted work during graceful shutdown.

### ✅ Prove (20 min)
Shutdown test checklist with in-flight tasks.

### 📦 Ship
`week-5/day5-graceful-shutdown.md`

### 💡 Why This Matters
Clean shutdown is reliability, not polish. It protects correctness during deploys and crashes. It unlocks safer failure drills.

### 🧠 Self-Check
- [ ] What is shutdown order?
- [ ] How avoid task loss?
- [ ] When force-terminate?

