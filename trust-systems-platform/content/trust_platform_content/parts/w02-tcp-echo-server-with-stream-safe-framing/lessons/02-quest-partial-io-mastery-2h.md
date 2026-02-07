---
id: w02-tcp-echo-server-with-stream-safe-framing-d02-quest-partial-io-mastery-2h
part: w02-tcp-echo-server-with-stream-safe-framing
title: "Quest: Partial I/O Mastery  2h"
order: 2
duration_minutes: 20
prereqs: ["w02-tcp-echo-server-with-stream-safe-framing-d01-quest-tcp-lifecycle-spec-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Partial I/O Mastery  2h

## Visual Model

![Visual Model](/visuals/w02-tcp-echo-server-with-stream-safe-framing.svg)



## Lesson Content
### 📖 Learn (30 min)
**Read/write loop correctness**

Key takeaways:
1. Partial reads happen
2. Partial writes happen
3. Loops must continue until done

### 🔨 Do (80 min)
Plan server and client loops for full-buffer send/recv behavior.

> 🆕 **New constraint:** Never assume one `recv` equals one message.

### ✅ Prove (20 min)
Define test where payload is intentionally fragmented.

### 📦 Ship
`week-2/day2-partial-io-plan.md`

### 💡 Why This Matters
This is the first major systems reality check. Correct stream handling prevents subtle data corruption later. It unlocks robust framing and replay-safe protocols.

### 🧠 Self-Check
- [ ] What is partial read?
- [ ] What is partial write?
- [ ] Why is one `recv` unsafe for message parsing?

