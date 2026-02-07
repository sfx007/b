---
id: w11-replicated-kv-23-nodes-d05-quest-partition-policy-2h
part: w11-replicated-kv-23-nodes
title: "Quest: Partition Policy  2h"
order: 5
duration_minutes: 20
prereqs: ["w11-replicated-kv-23-nodes-d04-quest-follower-catch-up-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Partition Policy  2h

## Visual Model

![Visual Model](/visuals/w11-replicated-kv-23-nodes.svg)



## Lesson Content
### 📖 Learn — Partition behavior: split-brain risk, minority isolation, recovery sequencing
### 🔨 Do — Define partition behavior policy. **Constraint:** Minority side CANNOT accept committed writes.
### 📦 Ship — `week-11/day5-partition-policy.md`

