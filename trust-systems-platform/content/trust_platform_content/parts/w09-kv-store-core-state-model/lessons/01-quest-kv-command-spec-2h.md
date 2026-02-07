---
id: w09-kv-store-core-state-model-d01-quest-kv-command-spec-2h
part: w09-kv-store-core-state-model
title: "Quest: KV Command Spec  2h"
order: 1
duration_minutes: 20
prereqs: []
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: KV Command Spec  2h

## Visual Model

![Visual Model](/visuals/w09-kv-store-core-state-model.svg)



## Lesson Content
### 📖 Learn — KV state machine basics: commands mutate state, reads are deterministic, invalid ops are explicit
### 🔨 Do — Define `put/get/delete` + response schema. **Constraint:** Every mutating command requires unique request ID.
### ✅ Prove — Command validity matrix including missing keys and duplicate IDs.
### 📦 Ship — `week-9/day1-kv-command-spec.md`
### 🧠 Self-Check
- [ ] Why request IDs on writes? · How should missing keys respond? · What makes command deterministic?

