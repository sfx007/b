---
id: w08-signatures-replay-protection-d02-quest-signverify-spec-2h
part: w08-signatures-replay-protection
title: "Quest: Sign/Verify Spec  2h"
order: 2
duration_minutes: 20
prereqs: ["w08-signatures-replay-protection-d01-quest-key-policy-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Sign/Verify Spec  2h

## Visual Model

![Visual Model](/visuals/w08-signatures-replay-protection.svg)



## Lesson Content
### 📖 Learn (30 min)
**Signature verification flow** — sign canonical bytes, verify before processing, fail closed

### 🔨 Do (80 min)
Define sign/verify CLI behavior and errors.
> 🆕 **New constraint:** Reject any unsigned or unverifiable message by default.

### ✅ Prove (20 min)
Invalid-signature test matrix (wrong key, altered payload, altered metadata).

### 📦 Ship
`week-8/day2-sign-verify-spec.md`

### 💡 Why
This is your first identity-bound protocol enforcement. Changes trust from "maybe honest" to **verifiable**.

### 🧠 Self-Check
- [ ] What exactly is signed? · Why verify before processing? · What is fail-closed behavior?

