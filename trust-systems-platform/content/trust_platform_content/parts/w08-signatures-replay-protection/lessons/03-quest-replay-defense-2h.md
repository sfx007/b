---
id: w08-signatures-replay-protection-d03-quest-replay-defense-2h
part: w08-signatures-replay-protection
title: "Quest: Replay Defense  2h"
order: 3
duration_minutes: 20
prereqs: ["w08-signatures-replay-protection-d02-quest-signverify-spec-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Replay Defense  2h

## Visual Model

![Visual Model](/visuals/w08-signatures-replay-protection.svg)



## Lesson Content
### 📖 Learn (30 min)
**Replay attacks and nonce design** — old valid message replay, nonce uniqueness, timestamp window

### 🔨 Do (80 min)
Define replay-defense policy with nonce cache + time window.
> 🆕 **New constraint:** Duplicate `(key_id, nonce)` is ALWAYS rejected.

### ✅ Prove (20 min)
Replay test where same signed packet is resent 3 times.

### 📦 Ship
`week-8/day3-replay-policy.md`

### 💡 Why
Integrity alone does NOT stop replay. You need temporal + uniqueness constraints.

### 🧠 Self-Check
- [ ] Why signatures don't stop replay? · How long keep nonce cache? · What about clock skew?

