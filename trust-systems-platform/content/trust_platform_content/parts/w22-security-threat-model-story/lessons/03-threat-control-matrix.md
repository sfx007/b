---
id: w22-security-threat-model-story-d03-threat-control-matrix
part: w22-security-threat-model-story
title: "Threat-Control Matrix"
order: 3
duration_minutes: 20
prereqs: ["w22-security-threat-model-story-d02-abuse-cases-top-10"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Threat-Control Matrix

## Visual Model

![Visual Model](/visuals/w22-security-threat-model-story.svg)



## Core Idea
This lesson is one step inside **Security / Threat Model Story (Week 22)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Every high-risk threat: ≥1 preventive + ≥1 detective control
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-22/day3-threat-control-matrix.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


