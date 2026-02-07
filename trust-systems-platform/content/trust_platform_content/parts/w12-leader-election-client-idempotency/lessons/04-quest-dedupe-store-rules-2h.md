---
id: w12-leader-election-client-idempotency-d04-quest-dedupe-store-rules-2h
part: w12-leader-election-client-idempotency
title: "Quest: Dedupe Store Rules  2h"
order: 4
duration_minutes: 20
prereqs: ["w12-leader-election-client-idempotency-d03-quest-client-retry-idempotency-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Dedupe Store Rules  2h

## Visual Model

![Visual Model](/visuals/w12-leader-election-client-idempotency.svg)



## Lesson Content
### 📖 Learn — Store recent request IDs, response replay, expiration policy
### 🔨 Do — Define dedupe store rules and TTL. **Constraint:** Duplicate request returns original response, NOT re-execution.
### 📦 Ship — `week-12/day4-dedupe-store-rules.md`

