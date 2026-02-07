---
id: w03-multi-client-event-loop-d01-quest-event-loop-state-model-2h
part: w03-multi-client-event-loop
title: "Quest: Event Loop State Model  2h"
order: 1
duration_minutes: 20
prereqs: []
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Event Loop State Model  2h

## Visual Model

![Visual Model](/visuals/w03-multi-client-event-loop.svg)



## Lesson Content
### 📖 Learn (30 min)
**Non-blocking I/O semantics**

Key takeaways:
1. Readiness ≠ completion
2. `EAGAIN` is normal
3. Per-connection state needed

### 🔨 Do (80 min)
Define connection state model for event loop.

> 🆕 **New constraint:** No blocking calls allowed in loop path.

### ✅ Prove (20 min)
Checklist validating all loop operations are non-blocking-safe.

### 📦 Ship
`week-3/day1-event-loop-state-model.md`

### 💡 Why This Matters
Event loops fail when state is implicit. You make state explicit before scaling connections. It unlocks predictable multi-client behavior.

### 🧠 Self-Check
- [ ] Why is `EAGAIN` expected?
- [ ] What state must each connection track?
- [ ] What call can accidentally block?

