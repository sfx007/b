---
id: w02-tcp-echo-server-with-stream-safe-framing-d05-quest-client-retry-rules-2h
part: w02-tcp-echo-server-with-stream-safe-framing
title: "Quest: Client Retry Rules  2h"
order: 5
duration_minutes: 20
prereqs: ["w02-tcp-echo-server-with-stream-safe-framing-d04-quest-timeout-policy-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Client Retry Rules  2h

## Visual Model

![Visual Model](/visuals/w02-tcp-echo-server-with-stream-safe-framing.svg)



## Lesson Content
### 📖 Learn (30 min)
**Client observability and retries**

Key takeaways:
1. Retry budget
2. Backoff basics
3. Distinguish transport vs protocol errors

### 🔨 Do (80 min)
Define client retry behavior for connection failures.

> 🆕 **New constraint:** Bounded retries to prevent retry storms.

### ✅ Prove (20 min)
Simulate server-down case and record retry timeline.

### 📦 Ship
`week-2/day5-client-retry-rules.md`

### 💡 Why This Matters
Client behavior is part of system correctness. Controlled retries reduce cascading failures. It unlocks idempotent client semantics in Month 3.

### 🧠 Self-Check
- [ ] Why bound retries?
- [ ] What should never be retried?
- [ ] What signal ends the retry loop?

