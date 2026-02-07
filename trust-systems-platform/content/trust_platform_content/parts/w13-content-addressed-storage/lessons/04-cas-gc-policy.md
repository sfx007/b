---
id: w13-content-addressed-storage-d04-cas-gc-policy
part: w13-content-addressed-storage
title: "CAS GC Policy"
order: 4
duration_minutes: 20
prereqs: ["w13-content-addressed-storage-d03-chunk-manifest-spec"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# CAS GC Policy

## Visual Model

![Visual Model](/visuals/w13-content-addressed-storage.svg)



## Core Idea
This lesson is one step inside **Content-Addressed Storage (Week 13)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Deletion only for unreachable objects after retention delay
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-13/day4-cas-gc-policy.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


### Notes from the original roadmap
Learn garbage collection (reachability roots, mark/sweep, safety window). Prove with reachability audit.


