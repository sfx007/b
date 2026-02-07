---
id: w06-backpressure-overload-handling-d04-quest-deadline-budget-2h
part: w06-backpressure-overload-handling
title: "Quest: Deadline Budget  2h"
order: 4
duration_minutes: 20
prereqs: ["w06-backpressure-overload-handling-d03-quest-egress-throttle-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Deadline Budget  2h

## Visual Model

![Visual Model](/visuals/w06-backpressure-overload-handling.svg)



## Lesson Content
### 📖 Learn (30 min)
**Tail latency management** — p99 pain point, deadline propagation, timeout budget split

### 🔨 Do (80 min)
Define request deadline budget across stages.
> 🆕 **New constraint:** Drop request when deadline is exceeded at any stage.

### ✅ Prove (20 min)
Deadline violation scenario with expected logs.

### 📦 Ship
`week-6/day4-deadline-budget.md`

### 💡 Why
Deadlines prevent zombie work and long-tail collapse.

### 🧠 Self-Check
- [ ] Why p99 matters? · How split deadlines? · What should happen on expired deadline?

