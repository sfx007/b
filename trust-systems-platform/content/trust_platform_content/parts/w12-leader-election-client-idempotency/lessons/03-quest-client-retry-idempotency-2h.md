---
id: w12-leader-election-client-idempotency-d03-quest-client-retry-idempotency-2h
part: w12-leader-election-client-idempotency
title: "Quest: Client Retry + Idempotency  2h"
order: 3
duration_minutes: 20
prereqs: ["w12-leader-election-client-idempotency-d02-quest-vote-rules-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Client Retry + Idempotency  2h

## Visual Model

![Visual Model](/visuals/w12-leader-election-client-idempotency.svg)



## Lesson Content
### 📖 Learn — Retry under leader changes, same request ID, redirect hints
### 🔨 Do — Define client retry policy for `not_leader` and timeout errors. **Constraint:** All retries reuse original request ID.
### 📦 Ship — `week-12/day3-client-retry-idempotency.md`

