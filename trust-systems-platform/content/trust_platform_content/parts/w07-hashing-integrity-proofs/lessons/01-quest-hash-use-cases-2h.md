---
id: w07-hashing-integrity-proofs-d01-quest-hash-use-cases-2h
part: w07-hashing-integrity-proofs
title: "Quest: Hash Use Cases  2h"
order: 1
duration_minutes: 20
prereqs: []
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Hash Use Cases  2h

## Visual Model

![Visual Model](/visuals/w07-hashing-integrity-proofs.svg)



## Lesson Content
### 📖 Learn (30 min)
**Hash fundamentals** — preimage/collision concepts, integrity use, non-secret vs secret primitives

### 🔨 Do (80 min)
Define hash-tool use cases (files, payloads, logs).
> 🆕 **New constraint:** Canonical byte representation before hashing.

### ✅ Prove (20 min)
Cross-platform hash consistency test cases.

### 📦 Ship
`week-7/day1-hash-use-cases.md`

### 💡 Why
Hashing only helps if bytes are canonical. Prevents false mismatches in signatures later.

### 🧠 Self-Check
- [ ] Why canonicalization first? · What is collision risk in practice? · Where should hash be stored?

