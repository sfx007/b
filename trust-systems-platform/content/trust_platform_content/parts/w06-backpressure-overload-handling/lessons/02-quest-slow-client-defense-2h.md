---
id: w06-backpressure-overload-handling-d02-quest-slow-client-defense-2h
part: w06-backpressure-overload-handling
title: "Quest: Slow-Client Defense  2h"
order: 2
duration_minutes: 20
prereqs: ["w06-backpressure-overload-handling-d01-quest-overload-policy-ladder-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Slow-Client Defense  2h

## Visual Model

![Visual Model](/visuals/w06-backpressure-overload-handling.svg)



## Lesson Content
### 📖 Learn (30 min)
**Slow-client attack patterns** — slowloris, read deadlines, per-connection quotas

### 🔨 Do (80 min)
Define slow-client defense strategy.
> 🆕 **New constraint:** Minimum progress rule for active connections.

### ✅ Prove (20 min)
Simulated slow-sender test plan and expected disconnect timing.

### 📦 Ship
`week-6/day2-slow-client-defense.md`

### 💡 Why
One bad peer can starve resources without this control.

### 🧠 Self-Check
- [ ] What is minimum progress rule? · Why not allow infinite slow sends? · What metric signals abuse?

