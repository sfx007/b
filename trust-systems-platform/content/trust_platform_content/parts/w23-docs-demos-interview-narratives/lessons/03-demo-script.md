---
id: w23-docs-demos-interview-narratives-d03-demo-script
part: w23-docs-demos-interview-narratives
title: "Demo Script"
order: 3
duration_minutes: 20
prereqs: ["w23-docs-demos-interview-narratives-d02-readme-outline"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Demo Script

## Visual Model

![Visual Model](/visuals/w23-docs-demos-interview-narratives.svg)



## Core Idea
This lesson is one step inside **Docs, Demos & Interview Narratives (Week 23)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Include one planned failure + recovery segment
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-23/day3-demo-script.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


