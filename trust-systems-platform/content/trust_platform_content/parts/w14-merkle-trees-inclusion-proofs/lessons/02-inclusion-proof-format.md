---
id: w14-merkle-trees-inclusion-proofs-d02-inclusion-proof-format
part: w14-merkle-trees-inclusion-proofs
title: "Inclusion Proof Format"
order: 2
duration_minutes: 20
prereqs: ["w14-merkle-trees-inclusion-proofs-d01-merkle-construction-rules"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Inclusion Proof Format

## Visual Model

![Visual Model](/visuals/w14-merkle-trees-inclusion-proofs.svg)



## Core Idea
This lesson is one step inside **Merkle Trees & Inclusion Proofs (Week 14)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Proof includes leaf index and tree size
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-14/day2-inclusion-proof-format.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


