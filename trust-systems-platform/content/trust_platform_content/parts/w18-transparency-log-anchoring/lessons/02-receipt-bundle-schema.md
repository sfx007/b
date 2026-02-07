---
id: w18-transparency-log-anchoring-d02-receipt-bundle-schema
part: w18-transparency-log-anchoring
title: "Receipt Bundle Schema"
order: 2
duration_minutes: 20
prereqs: ["w18-transparency-log-anchoring-d01-anchoring-workflow"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Receipt Bundle Schema

## Visual Model

![Visual Model](/visuals/w18-transparency-log-anchoring.svg)



## Core Idea
This lesson is one step inside **Transparency Log Anchoring (Week 18)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Bundle must be self-contained for offline verification
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-18/day2-receipt-bundle-schema.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


