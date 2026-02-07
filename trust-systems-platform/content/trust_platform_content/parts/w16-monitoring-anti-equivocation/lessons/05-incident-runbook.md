---
id: w16-monitoring-anti-equivocation-d05-incident-runbook
part: w16-monitoring-anti-equivocation
title: "Incident Runbook"
order: 5
duration_minutes: 20
prereqs: ["w16-monitoring-anti-equivocation-d04-alert-policy"]
proof:
  type: "paste_or_upload"
  status: "manual_or_regex"
review_schedule_days: [1,3,7,14]
---

# Incident Runbook

## Visual Model

![Visual Model](/visuals/w16-monitoring-anti-equivocation.svg)



## Core Idea
This lesson is one step inside **Monitoring & Anti-Equivocation (Week 16)**. Lock in one new constraint and prove it with evidence.

## The Rules
- **New constraint:** Runbook includes freeze-new-acceptance decision criteria
- Keep behavior deterministic (same input → same output).
- Fail closed on malformed input (reject early, log clearly).

## Practice
- **Warmup (5–10 min):** explain the diagram in 60 seconds.
- **Core (30–60 min):** implement the smallest thing that satisfies the new constraint.
- **Edge (15–30 min):** break it on purpose and verify clean failure behavior.
- **Mini-boss (15–30 min):** create a checklist/test that catches this bug next time.

## Prove it
Attach evidence for: `week-16/day5-incident-runbook.md`  
Examples: test output, log snippet, or a short “expected vs got” note.

## Self-check
- What is the *new constraint* added today?
- What failure mode does it prevent?
- What would “pass” look like in logs/tests?


