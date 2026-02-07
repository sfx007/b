---
id: w21-reliability-slo-story-d04-alert-rules
part: w21-reliability-slo-story
title: "Alert Rules"
order: 4
duration_minutes: 20
prereqs: ["w21-reliability-slo-story-d03-dashboard-spec"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Alert Rules

## Visual Model

![Visual Model](/visuals/w21-reliability-slo-story.svg)



## Core Idea
This lesson is one step inside **Reliability / SLO Story (Week 21)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Paging only for user-impacting or trust-critical conditions
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-21/day4-alert-rules.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


