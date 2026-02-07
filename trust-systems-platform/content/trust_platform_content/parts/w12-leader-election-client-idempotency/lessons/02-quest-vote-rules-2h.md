---
id: w12-leader-election-client-idempotency-d02-quest-vote-rules-2h
part: w12-leader-election-client-idempotency
title: "Quest: Vote Rules  2h"
order: 2
duration_minutes: 20
prereqs: ["w12-leader-election-client-idempotency-d01-quest-election-timeouts-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Vote Rules  2h

## Visual Model

![Visual Model](/visuals/w12-leader-election-client-idempotency.svg)



## Lesson Content
### 📖 Learn — One vote per term, up-to-date log requirement, term update on newer term seen
### 🔨 Do — Define candidate/voter state transitions. **Constraint:** Reject vote if candidate log is stale.
### 📦 Ship — `week-12/day2-vote-rules.md`

