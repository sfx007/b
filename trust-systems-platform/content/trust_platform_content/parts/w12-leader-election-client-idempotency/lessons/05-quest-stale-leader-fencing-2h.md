---
id: w12-leader-election-client-idempotency-d05-quest-stale-leader-fencing-2h
part: w12-leader-election-client-idempotency
title: "Quest: Stale-Leader Fencing  2h"
order: 5
duration_minutes: 20
prereqs: ["w12-leader-election-client-idempotency-d04-quest-dedupe-store-rules-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Stale-Leader Fencing  2h

## Visual Model

![Visual Model](/visuals/w12-leader-election-client-idempotency.svg)



## Lesson Content
### 📖 Learn — Term-based fencing, stale write rejection, role transition logging
### 🔨 Do — Define stale-leader handling path. **Constraint:** Any request carrying old term is rejected.
### 📦 Ship — `week-12/day5-stale-leader-fencing.md`

