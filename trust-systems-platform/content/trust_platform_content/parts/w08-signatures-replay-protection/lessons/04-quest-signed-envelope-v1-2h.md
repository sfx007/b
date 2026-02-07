---
id: w08-signatures-replay-protection-d04-quest-signed-envelope-v1-2h
part: w08-signatures-replay-protection
title: "Quest: Signed Envelope v1  2h"
order: 4
duration_minutes: 20
prereqs: ["w08-signatures-replay-protection-d03-quest-replay-defense-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Signed Envelope v1  2h

## Visual Model

![Visual Model](/visuals/w08-signatures-replay-protection.svg)



## Lesson Content
### 📖 Learn (30 min)
**Envelope versioning and compatibility** — signed header fields, extensibility, deprecation

### 🔨 Do (80 min)
Finalize signed protocol envelope schema.
> 🆕 **New constraint:** Include protocol version and mandatory signed metadata.

### ✅ Prove (20 min)
Version compatibility scenarios and expected outcomes.

### 📦 Ship
`week-8/day4-signed-envelope-v1.md`

### 🧠 Self-Check
- [ ] Which headers must be signed? · Why include version in signature? · How handle unknown version?

