---
id: w07-hashing-integrity-proofs-d04-quest-canonicalization-rules-2h
part: w07-hashing-integrity-proofs
title: "Quest: Canonicalization Rules  2h"
order: 4
duration_minutes: 20
prereqs: ["w07-hashing-integrity-proofs-d03-quest-protocol-hash-envelope-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Canonicalization Rules  2h

## Visual Model

![Visual Model](/visuals/w07-hashing-integrity-proofs.svg)



## Lesson Content
### 📖 Learn (30 min)
**Hash misuse pitfalls** — hashing mutable forms, ambiguous encodings, wrong digest context

### 🔨 Do (80 min)
Define canonicalization and encoding rules for all hash inputs.
> 🆕 **New constraint:** Single canonical serialization for signed/hashed data.

### ✅ Prove (20 min)
Canonicalization regression cases (field order, whitespace, line endings).

### 📦 Ship
`week-7/day4-canonicalization-rules.md`

### 💡 Why
Most signature bugs are serialization bugs. Prevents cross-node verification failures.

### 🧠 Self-Check
- [ ] What fields must be canonicalized? · Why can whitespace break trust? · How lock serialization format?

