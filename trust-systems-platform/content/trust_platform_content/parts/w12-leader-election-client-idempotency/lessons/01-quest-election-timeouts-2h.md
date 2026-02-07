---
id: w12-leader-election-client-idempotency-d01-quest-election-timeouts-2h
part: w12-leader-election-client-idempotency
title: "Quest: Election Timeouts  2h"
order: 1
duration_minutes: 20
prereqs: []
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Election Timeouts  2h

## Visual Model

![Visual Model](/visuals/w12-leader-election-client-idempotency.svg)



## Lesson Content
### 📖 Learn — Randomized timeout reduces split votes, heartbeat cadence, term monotonicity
### 🔨 Do — Define election timeout/heartbeat ranges. **Constraint:** Randomized election timeout per node.
### 📦 Ship — `week-12/day1-election-timeouts.md`

