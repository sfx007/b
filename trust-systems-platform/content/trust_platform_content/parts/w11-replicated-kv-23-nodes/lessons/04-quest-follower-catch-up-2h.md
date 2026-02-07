---
id: w11-replicated-kv-23-nodes-d04-quest-follower-catch-up-2h
part: w11-replicated-kv-23-nodes
title: "Quest: Follower Catch-Up  2h"
order: 4
duration_minutes: 20
prereqs: ["w11-replicated-kv-23-nodes-d03-quest-quorum-commit-rules-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Follower Catch-Up  2h

## Visual Model

![Visual Model](/visuals/w11-replicated-kv-23-nodes.svg)



## Lesson Content
### 📖 Learn — Retry from lower index, conflict resolution, snapshot install fallback
### 🔨 Do — Define catch-up sequence for lagging follower. **Constraint:** Bounded retry steps before snapshot fallback.
### 📦 Ship — `week-11/day4-follower-catchup.md`

