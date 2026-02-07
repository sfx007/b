---
id: w03-multi-client-event-loop-d02-quest-first-multi-client-loop-2h
part: w03-multi-client-event-loop
title: "Quest: First Multi-Client Loop  2h"
order: 2
duration_minutes: 20
prereqs: ["w03-multi-client-event-loop-d01-quest-event-loop-state-model-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: First Multi-Client Loop  2h

## Visual Model

![Visual Model](/visuals/w03-multi-client-event-loop.svg)



## Lesson Content
### 📖 Learn (30 min)
**`select` mechanics and limits**

Key takeaways:
1. fd sets mutate
2. Max fd caveats
3. Read/write readiness sets

### 🔨 Do (80 min)
Plan first multi-client loop using `select`.

> 🆕 **New constraint:** Support at least 50 concurrent idle clients.

### ✅ Prove (20 min)
Connection matrix test plan (connect/disconnect bursts).

### 📦 Ship
`week-3/day2-select-plan.md`

### 💡 Why This Matters
This is your first true multi-client architecture step. Even simple loads expose state bugs fast. It unlocks migration to better pollers.

### 🧠 Self-Check
- [ ] What are `select` limits?
- [ ] Why track max fd?
- [ ] What events need separate handling?

