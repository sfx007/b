---
id: w06-backpressure-overload-handling-d03-quest-egress-throttle-2h
part: w06-backpressure-overload-handling
title: "Quest: Egress Throttle  2h"
order: 3
duration_minutes: 20
prereqs: ["w06-backpressure-overload-handling-d02-quest-slow-client-defense-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Egress Throttle  2h

## Visual Model

![Visual Model](/visuals/w06-backpressure-overload-handling.svg)



## Lesson Content
### 📖 Learn (30 min)
**Write-side pressure control** — socket send buffer limits, app-level buffer caps, drop/close policy

### 🔨 Do (80 min)
Define outbound throttling behavior.
> 🆕 **New constraint:** Per-client egress rate limit with burst cap.

### ✅ Prove (20 min)
High-volume client test case verifying throttling kicks in.

### 📦 Ship
`week-6/day3-egress-throttle.md`

### 💡 Why
Protects server memory and fairness. Prepares you for replication traffic shaping.

### 🧠 Self-Check
- [ ] Why rate-limit writes? · What is burst cap? · When close vs throttle?

