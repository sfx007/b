---
id: w07-hashing-integrity-proofs-d02-quest-streaming-hash-plan-2h
part: w07-hashing-integrity-proofs
title: "Quest: Streaming Hash Plan  2h"
order: 2
duration_minutes: 20
prereqs: ["w07-hashing-integrity-proofs-d01-quest-hash-use-cases-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Streaming Hash Plan  2h

## Visual Model

![Visual Model](/visuals/w07-hashing-integrity-proofs.svg)



## Lesson Content
### 📖 Learn (30 min)
**Streaming digest computation** — chunked updates, large-file memory safety, finalization

### 🔨 Do (80 min)
Define incremental hash workflow for large payloads.
> 🆕 **New constraint:** No full-file load into memory.

### ✅ Prove (20 min)
Large-input test plan with memory cap target.

### 📦 Ship
`week-7/day2-streaming-hash-plan.md`

### 🧠 Self-Check
- [ ] Why incremental hashing? · What memory cap is acceptable? · How verify same digest as one-shot?

