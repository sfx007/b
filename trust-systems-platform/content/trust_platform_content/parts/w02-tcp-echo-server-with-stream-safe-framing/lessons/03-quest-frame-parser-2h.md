---
id: w02-tcp-echo-server-with-stream-safe-framing-d03-quest-frame-parser-2h
part: w02-tcp-echo-server-with-stream-safe-framing
title: "Quest: Frame Parser  2h"
order: 3
duration_minutes: 20
prereqs: ["w02-tcp-echo-server-with-stream-safe-framing-d02-quest-partial-io-mastery-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Frame Parser  2h

## Visual Model

![Visual Model](/visuals/w02-tcp-echo-server-with-stream-safe-framing.svg)



## Lesson Content
### 📖 Learn (30 min)
**Protocol framing basics**

Key takeaways:
1. Length-prefix framing
2. Frame size limits
3. Malformed frame rejection

### 🔨 Do (80 min)
Define frame format and parser states.

> 🆕 **New constraint:** Reject oversize frame before allocation.

### ✅ Prove (20 min)
Build parser test table: short header, truncated payload, oversize length.

### 📦 Ship
`week-2/day3-frame-parser-spec.md`

### 💡 Why This Matters
Framing turns raw bytes into safe messages. It is required for signatures and replay defense later. It unlocks multi-client event-loop reliability.

### 🧠 Self-Check
- [ ] Why length-prefix over delimiter here?
- [ ] What is a parser state machine?
- [ ] When should server close the connection?

