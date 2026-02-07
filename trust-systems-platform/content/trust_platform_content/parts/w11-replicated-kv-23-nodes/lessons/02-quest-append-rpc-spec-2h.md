---
id: w11-replicated-kv-23-nodes-d02-quest-append-rpc-spec-2h
part: w11-replicated-kv-23-nodes
title: "Quest: Append RPC Spec  2h"
order: 2
duration_minutes: 20
prereqs: ["w11-replicated-kv-23-nodes-d01-quest-failure-model-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Append RPC Spec  2h

## Visual Model

![Visual Model](/visuals/w11-replicated-kv-23-nodes.svg)



## Lesson Content
### 📖 Learn — Leader-to-follower log shipping: append entries RPC, prev-index consistency check, ack semantics
### 🔨 Do — Define append RPC fields and follower validation. **Constraint:** Follower rejects append with mismatched previous index/term.
### 📦 Ship — `week-11/day2-append-rpc-spec.md`

