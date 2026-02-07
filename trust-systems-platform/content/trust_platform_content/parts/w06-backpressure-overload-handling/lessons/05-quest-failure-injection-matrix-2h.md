---
id: w06-backpressure-overload-handling-d05-quest-failure-injection-matrix-2h
part: w06-backpressure-overload-handling
title: "Quest: Failure Injection Matrix  2h"
order: 5
duration_minutes: 20
prereqs: ["w06-backpressure-overload-handling-d04-quest-deadline-budget-2h"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Quest: Failure Injection Matrix  2h

## Visual Model

![Visual Model](/visuals/w06-backpressure-overload-handling.svg)



## Lesson Content
### 📖 Learn (30 min)
**Failure injection basics** — deliberate stress, controlled hypotheses, observable outcomes

### 🔨 Do (80 min)
Plan overload + slow-client failure drill matrix.
> 🆕 **New constraint:** Every drill must map to one quality gate metric.

### ✅ Prove (20 min)
Define expected fail-safe behavior for 5 stress scenarios.

### 📦 Ship
`week-6/day5-failure-injection-matrix.md`

### 💡 Why
You build muscle for "break it on purpose." Trust systems avoid surprise collapses.

### 🧠 Self-Check
- [ ] What is a good failure drill? · Which metric defines pass? · Why test fail-safe behavior early?

