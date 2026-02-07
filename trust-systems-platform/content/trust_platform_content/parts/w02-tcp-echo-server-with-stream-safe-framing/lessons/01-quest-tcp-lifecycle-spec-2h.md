---
id: w02-tcp-echo-server-with-stream-safe-framing-d01-quest-tcp-lifecycle-spec-2h
part: w02-tcp-echo-server-with-stream-safe-framing
title: "Quest: TCP Lifecycle Spec  2h"
order: 1
duration_minutes: 20
prereqs: []
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: TCP Lifecycle Spec  2h

## Visual Model

![Visual Model](/visuals/w02-tcp-echo-server-with-stream-safe-framing.svg)



## Lesson Content
### 📖 Learn (30 min)
**TCP lifecycle and stream semantics**

Key takeaways:
1. `connect`/`listen`/`accept` split
2. Stream ≠ message
3. Close handling

### 🔨 Do (80 min)
Specify single-client echo protocol behavior.

> 🆕 **New constraint:** Handle port-in-use startup failure explicitly.

### ✅ Prove (20 min)
Startup/shutdown scenario table including bind failures.

### 📦 Ship
`week-2/day1-tcp-lifecycle-spec.md`

### 💡 Why This Matters
This day defines server behavior before coding details spread. It anchors all future protocol constraints. It unlocks deterministic network tests.

### 🧠 Self-Check
- [ ] Why is TCP a byte stream?
- [ ] What happens when port is busy?
- [ ] What is accept socket vs listen socket?

