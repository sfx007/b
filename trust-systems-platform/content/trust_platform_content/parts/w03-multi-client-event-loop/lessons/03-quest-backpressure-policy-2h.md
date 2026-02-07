---
id: w03-multi-client-event-loop-d03-quest-backpressure-policy-2h
part: w03-multi-client-event-loop
title: "Quest: Backpressure Policy  2h"
order: 3
duration_minutes: 20
prereqs: ["w03-multi-client-event-loop-d02-quest-first-multi-client-loop-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Backpressure Policy  2h

## Visual Model

![Visual Model](/visuals/w03-multi-client-event-loop.svg)



## Lesson Content
### 📖 Learn (30 min)
**Backpressure at socket level**

Key takeaways:
1. Write buffers can fill
2. Slow clients hurt everyone
3. Bounded queues protect process

### 🔨 Do (80 min)
Define per-client outbound buffer policy.

> 🆕 **New constraint:** Cap queued bytes per client and disconnect on abuse.

### ✅ Prove (20 min)
Slow-reader test scenario with expected disconnect threshold.

### 📦 Ship
`week-3/day3-backpressure-policy.md`

### 💡 Why This Matters
This day prevents one slow client from destabilizing the service. It introduces fairness as a correctness property. It unlocks formal backpressure controls in Month 2.

### 🧠 Self-Check
- [ ] Why cap per-client queue?
- [ ] What is fairness in I/O servers?
- [ ] When is forced disconnect correct?

