---
id: w10-wal-durability-crash-recovery-d05-quest-checkpoint-compaction-2h
part: w10-wal-durability-crash-recovery
title: "Quest: Checkpoint & Compaction  2h"
order: 5
duration_minutes: 20
prereqs: ["w10-wal-durability-crash-recovery-d04-quest-recovery-algorithm-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Checkpoint & Compaction  2h

## Visual Model

![Visual Model](/visuals/w10-wal-durability-crash-recovery.svg)



## Lesson Content
### 📖 Learn — Checkpoint and compaction: reduce replay time, consistent cut, WAL truncation safety
### 🔨 Do — Define checkpoint trigger policy and truncation rules. **Constraint:** Truncate ONLY after verified checkpoint durability.
### ✅ Prove — Checkpoint/truncate invariants checklist.
### 📦 Ship — `week-10/day5-checkpoint-compaction.md`

