---
id: w08-signatures-replay-protection-d05-quest-verify-performance-2h
part: w08-signatures-replay-protection
title: "Quest: Verify Performance  2h"
order: 5
duration_minutes: 20
prereqs: ["w08-signatures-replay-protection-d04-quest-signed-envelope-v1-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Verify Performance  2h

## Visual Model

![Visual Model](/visuals/w08-signatures-replay-protection.svg)



## Lesson Content
### 📖 Learn (30 min)
**Verification performance and caching** — key cache, signature verify cost, rejection fast path

### 🔨 Do (80 min)
Define verification pipeline optimization plan.
> 🆕 **New constraint:** Cap verification latency while preserving fail-closed semantics.

### ✅ Prove (20 min)
Measure expected verification cost for small vs large payloads.

### 📦 Ship
`week-8/day5-verify-performance.md`

### 🧠 Self-Check
- [ ] Where is verify bottleneck? · What can be cached safely? · What must NEVER bypass verification?

