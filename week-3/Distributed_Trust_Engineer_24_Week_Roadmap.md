# 🏗️ Distributed Trust Engineer — 24-Week Quest Line

> **You are building a civic-grade trust system from scratch in C++.**
> Every week is a new chapter. Every day is a quest. Ship proof or don't move on.

```
╔══════════════════════════════════════════════════════════════╗
║  🎮  YOUR CHARACTER CLASS: Distributed Trust Engineer       ║
║  🛠️  Weapon of Choice:     C++17/20                         ║
║  🐧  Home Base:             Linux                           ║
║  ⏱️  Daily Training:        2h (Mon–Fri) · 4h (Sat)         ║
║  🏖️  Rest Day:              Sunday (light review only)       ║
╚══════════════════════════════════════════════════════════════╝
```

---

## 🗺️ World Map — Quick Jump

| Arc | Months | Theme | Status |
|-----|--------|-------|--------|
| [🌍 Arc 1 — Foundations](#-arc-1--foundations-month-1) | Month 1 | Networking & Event Loops | ⬜ |
| [⚔️ Arc 2 — Hardening](#-arc-2--hardening-month-2) | Month 2 | Concurrency & Crypto | ⬜ |
| [🏰 Arc 3 — Distributed Core](#-arc-3--distributed-core-month-3) | Month 3 | Durability & Replication | ⬜ |
| [🔮 Arc 4 — Trust Architecture](#-arc-4--trust-architecture-month-4) | Month 4 | CAS, Merkle, Transparency | ⬜ |
| [👑 Arc 5 — CivicTrust Capstone](#-arc-5--civictrust-capstone-month-5) | Month 5 | Full System Composition | ⬜ |
| [🚀 Arc 6 — Ship It](#-arc-6--ship-it-month-6) | Month 6 | Portfolio, Demos, Interviews | ⬜ |
| [🏆 Weekly Boss Fights](#-weekly-boss-fights-checkpoints) | All | End-of-Week Gates | ⬜ |
| [📊 Monthly Level-Ups](#-monthly-level-ups) | All | Milestone Reviews | ⬜ |

---

## 🎯 How to Play

```
  ┌──────────┐    ┌──────────┐    ┌──────────┐    ┌──────────┐
  │  📖 LEARN │───▶│  🔨 DO   │───▶│  ✅ PROVE│───▶│  📦 SHIP │
  │  30 min   │    │  80 min  │    │  20 min  │    │ artifact │
  └──────────┘    └──────────┘    └──────────┘    └──────────┘
```

**5 Rules:**
1. 📖 **Learn** → 🔨 **Do** → ✅ **Prove** → 📦 **Ship** — every single day
2. Never skip the **💡 Why** and **🧠 Self-Check** — they are your XP multiplier
3. Saturday = 🗡️ **Boss Fight** (integration day). Sunday = 🏖️ rest + light review
4. ❌ Do NOT advance to next week unless you pass the **🚩 Weekly Gate**
5. 🏆 Publish the monthly artifact — it's your portfolio proof

---

## 🌳 Skill Tree — What Unlocks What

```
 [1] Build/Test Hygiene
      │
      ▼
 [2] TCP Byte-Stream Thinking ──────────────────────┐
      │                                              │
      ▼                                              │
 [3] Event-Loop Multi-Client Servers                 │
      │                                              │
      ▼                                              │
 [4] Concurrency + Backpressure                      │
      │                                              ▼
      ▼                                    ┌─────────────────┐
 [5] Hashing / Signing / Replay Defense ◀──│ Reuse compounds │
      │                                    │ at every stage!  │
      ▼                                    └─────────────────┘
 [6] Durable KV (WAL + Recovery)
      │
      ▼
 [7] Replication + Election + Idempotent Clients
      │
      ▼
 [8] Content-Addressed Storage + Merkle Proofs
      │
      ▼
 [9] Transparency Log + Consistency Proofs + Signed Checkpoints
      │
      ▼
[10] 👑 CivicTrust Capstone + Reliability/Security Narrative
```

### 🔗 Contracts You Keep Stable (Your "API")

| Contract | Key Fields |
|----------|-----------|
| **CLI** | Predictable command format, exit codes, stderr errors |
| **Protocol Envelope** | `version`, `msg_type`, `request_id`, `timestamp`, `nonce`, `payload_hash`, `signature`, `key_id` |
| **WAL Record** | `lsn`, `term`, `op`, `key`, `value_hash`, `checksum` |
| **Proof Bundle** | `document_hash`, `leaf_index`, `tree_size`, `inclusion_proof`, `checkpoint_signature`, optional `consistency_proof` |
| **Observability** | Structured logs: `node_id`, `request_id`, `latency_ms`, `result`, `error_code` |

---

# 🌍 Arc 1 — Foundations (Month 1)

> **🎯 Mission:** Build networking foundations and event-driven server habits.
>
> **🧠 Mindset unlock:** *"TCP is a stream, not messages. Responsiveness is state management."*

```
Month 1 Progress
[░░░░░░░░░░░░░░░░░░░░░░░░] 0% — Week 1 · 2 · 3 · 4
```

---

## 📗 Chapter 1 — CLI & Logger Discipline (Week 1)

> **🎯 Theme:** Build repeatable tools and evidence capture before networking complexity.
>
> **🆕 New skill:** Command contracts + deterministic behavior
> **🔄 Reinforcement:** C++ basics with stronger constraints

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Define Your CLI Contract</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**CLI contract design and deterministic outputs**

Key takeaways:
1. Input/output is an API
2. Exit codes are behavior
3. Stderr for errors, stdout for data

### 🔨 Do (80 min)
Define `log append/read/search` behavior and argument rules.

> 🆕 **New constraint:** Strict exit-code table for all failure modes.

### ✅ Prove (20 min)
Build a **12-case argument matrix** (valid, missing args, malformed flags).

### 📦 Ship
`week-1/day1-cli-contract.md`

### 💡 Why This Matters
This day creates your behavior spec *before* implementation. It prevents hidden ambiguity later when tests fail. It unlocks automated CLI regression checks.

### 🧠 Self-Check
- [ ] What is a command contract?
- [ ] Why are exit codes part of an API?
- [ ] Which errors must go to stderr?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Logger Write Path</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**File I/O reliability basics**

Key takeaways:
1. Append semantics
2. `fsync` tradeoff
3. Permission failures are common

### 🔨 Do (80 min)
Plan logger write path and file naming scheme.

> 🆕 **New constraint:** Atomic append requirement for each log entry.

### ✅ Prove (20 min)
Simulate permission-denied and missing-directory cases in test notes.

### 📦 Ship
`week-1/day2-logger-write-path.md`

### 💡 Why This Matters
You turn vague "write logs" into a reliability contract. This sets up evidence capture for all later servers. It unlocks reproducible debugging.

### 🧠 Self-Check
- [ ] Why atomic append?
- [ ] What failures must logger handle first-class?
- [ ] When would `fsync` be required?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Validation Boundaries</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Input validation strategy**

Key takeaways:
1. Reject early
2. Normalize paths
3. Cap line length

### 🔨 Do (80 min)
Define validation rules for message size, file path, and command shape.

> 🆕 **New constraint:** Max log record size to prevent memory abuse.

### ✅ Prove (20 min)
Create boundary test list (0 bytes, max bytes, max+1).

### 📦 Ship
`week-1/day3-validation-boundaries.md`

### 💡 Why This Matters
Systems break at boundaries, not happy paths. This day installs safety limits before networking introduces untrusted input. It unlocks safer protocol handling later.

### 🧠 Self-Check
- [ ] What boundary values matter?
- [ ] Why set max record size now?
- [ ] What should happen on max+1?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Error Catalog</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Structured errors and observability**

Key takeaways:
1. Error code taxonomy
2. Machine-parsable logs
3. Request correlation IDs

### 🔨 Do (80 min)
Define error catalog for CLI/logger operations.

> 🆕 **New constraint:** Every failure path maps to one stable error code.

### ✅ Prove (20 min)
Produce an error-to-scenario table with expected user-facing text.

### 📦 Ship
`week-1/day4-error-catalog.md`

### 💡 Why This Matters
This gives your system a stable language for failure. Later distributed debugging depends on predictable error semantics. It unlocks cleaner monitoring and incident triage.

### 🧠 Self-Check
- [ ] Why stable error codes?
- [ ] What is correlation context?
- [ ] How is human text different from machine code?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Test Plan Design</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Test harness planning**

Key takeaways:
1. Golden-file tests
2. Negative tests
3. Deterministic timestamps via injection plan

### 🔨 Do (80 min)
Design CLI/logger test plan.

> 🆕 **New constraint:** Deterministic output even when time is involved.

### ✅ Prove (20 min)
Define pass/fail criteria for 15 tests including malformed inputs.

### 📦 Ship
`week-1/day5-test-plan.md`

### 💡 Why This Matters
You now have explicit evidence criteria, not "it seems fine." This converts learning into measurable progress. It unlocks confidence for network-layer integration next week.

### 🧠 Self-Check
- [ ] What makes a test deterministic?
- [ ] What is a golden file?
- [ ] Why include negative tests first?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Package for Reuse</b> ⏱️ 4h</summary>

### 📖 Learn (40 min)
**Packaging for reuse**

Key takeaways:
1. Module boundaries
2. Reusable utility library
3. Documentation-as-interface

### 🔨 Do (180 min)
Consolidate week artifacts into one reusable CLI/logger package.

> 🆕 **New constraint:** Module split so networking project can import logger without rewrite.

### ✅ Prove (40 min)
Run full week test matrix and collect baseline execution times.

### 📦 Ship
`week-1/README.md` + `week-1/day6-baseline-report.md`

### 💡 Why This Matters
This turns week work into a component, not throwaway practice. Reuse starts here and continues all 6 months. It unlocks instrumentation in your TCP servers.

### 🧠 Self-Check
- [ ] What is reused next week?
- [ ] Why avoid copy-paste modules?
- [ ] What baseline numbers did you capture?

</details>

---

## 📗 Chapter 2 — TCP Echo Server with Stream-Safe Framing (Week 2)

> **🎯 Theme:** Shift from local file correctness to network correctness.
>
> **🆕 New skill:** Socket lifecycle + partial I/O
> **🔄 Reinforcement:** Validation/error discipline from Week 1

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: TCP Lifecycle Spec</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**TCP lifecycle and stream semantics**

Key takeaways:
1. `connect`/`listen`/`accept` split
2. Stream ≠ message
3. Close handling

### 🔨 Do (80 min)
Specify single-client echo protocol behavior.

> 🆕 **New constraint:** Handle port-in-use startup failure explicitly.

### ✅ Prove (20 min)
Startup/shutdown scenario table including bind failures.

### 📦 Ship
`week-2/day1-tcp-lifecycle-spec.md`

### 💡 Why This Matters
This day defines server behavior before coding details spread. It anchors all future protocol constraints. It unlocks deterministic network tests.

### 🧠 Self-Check
- [ ] Why is TCP a byte stream?
- [ ] What happens when port is busy?
- [ ] What is accept socket vs listen socket?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Partial I/O Mastery</b> ⏱️ 2h</summary>

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

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Frame Parser</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Protocol framing basics**

Key takeaways:
1. Length-prefix framing
2. Frame size limits
3. Malformed frame rejection

### 🔨 Do (80 min)
Define frame format and parser states.

> 🆕 **New constraint:** Reject oversize frame before allocation.

### ✅ Prove (20 min)
Build parser test table: short header, truncated payload, oversize length.

### 📦 Ship
`week-2/day3-frame-parser-spec.md`

### 💡 Why This Matters
Framing turns raw bytes into safe messages. It is required for signatures and replay defense later. It unlocks multi-client event-loop reliability.

### 🧠 Self-Check
- [ ] Why length-prefix over delimiter here?
- [ ] What is a parser state machine?
- [ ] When should server close the connection?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Timeout Policy</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Timeouts and dead peers**

Key takeaways:
1. Read timeout
2. Heartbeat (optional)
3. Idle connection cleanup

### 🔨 Do (80 min)
Define idle and read timeout policy for client/server.

> 🆕 **New constraint:** Connection closes after idle threshold with explicit reason.

### ✅ Prove (20 min)
Design slow-client timeout scenario and expected log output.

### 📦 Ship
`week-2/day4-timeout-policy.md`

### 💡 Why This Matters
Timeouts protect resource usage and keep services responsive. This prevents dead connections from draining capacity. It unlocks backpressure policy in Month 2.

### 🧠 Self-Check
- [ ] Why are timeouts mandatory in servers?
- [ ] What is idle vs read timeout?
- [ ] How should timeout appear in logs?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Client Retry Rules</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Client observability and retries**

Key takeaways:
1. Retry budget
2. Backoff basics
3. Distinguish transport vs protocol errors

### 🔨 Do (80 min)
Define client retry behavior for connection failures.

> 🆕 **New constraint:** Bounded retries to prevent retry storms.

### ✅ Prove (20 min)
Simulate server-down case and record retry timeline.

### 📦 Ship
`week-2/day5-client-retry-rules.md`

### 💡 Why This Matters
Client behavior is part of system correctness. Controlled retries reduce cascading failures. It unlocks idempotent client semantics in Month 3.

### 🧠 Self-Check
- [ ] Why bound retries?
- [ ] What should never be retried?
- [ ] What signal ends the retry loop?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Integrate & Measure</b> ⏱️ 4h</summary>

### 📖 Learn (40 min)
**Reuse and integration discipline**

Key takeaways:
1. Shared logger reuse
2. Structured network logs
3. Baseline throughput measures

### 🔨 Do (180 min)
Integrate logger from Week 1 into TCP tools and run echo workload plan.

> 🆕 **New constraint:** Each request must carry a traceable request ID in logs.

### ✅ Prove (40 min)
Capture latency and success-rate baseline from 3 payload sizes.

### 📦 Ship
`week-2/day6-echo-baseline-report.md`

### 💡 Why This Matters
This day proves composition, not restart-from-zero. Measured baselines make future optimizations meaningful. It unlocks multi-client event-loop comparison next week.

### 🧠 Self-Check
- [ ] What was reused?
- [ ] What baseline numbers matter?
- [ ] Why attach request IDs now?

</details>

---

## 📗 Chapter 3 — Multi-Client Event Loop (Week 3)

> **🎯 Theme:** `select`/`poll` — concurrency without threads.
>
> **🆕 New skill:** Non-blocking state machines
> **🔄 Reinforcement:** Framing, timeouts, and logging

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Event Loop State Model</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Non-blocking I/O semantics**

Key takeaways:
1. Readiness ≠ completion
2. `EAGAIN` is normal
3. Per-connection state needed

### 🔨 Do (80 min)
Define connection state model for event loop.

> 🆕 **New constraint:** No blocking calls allowed in loop path.

### ✅ Prove (20 min)
Checklist validating all loop operations are non-blocking-safe.

### 📦 Ship
`week-3/day1-event-loop-state-model.md`

### 💡 Why This Matters
Event loops fail when state is implicit. You make state explicit before scaling connections. It unlocks predictable multi-client behavior.

### 🧠 Self-Check
- [ ] Why is `EAGAIN` expected?
- [ ] What state must each connection track?
- [ ] What call can accidentally block?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: First Multi-Client Loop</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**`select` mechanics and limits**

Key takeaways:
1. fd sets mutate
2. Max fd caveats
3. Read/write readiness sets

### 🔨 Do (80 min)
Plan first multi-client loop using `select`.

> 🆕 **New constraint:** Support at least 50 concurrent idle clients.

### ✅ Prove (20 min)
Connection matrix test plan (connect/disconnect bursts).

### 📦 Ship
`week-3/day2-select-plan.md`

### 💡 Why This Matters
This is your first true multi-client architecture step. Even simple loads expose state bugs fast. It unlocks migration to better pollers.

### 🧠 Self-Check
- [ ] What are `select` limits?
- [ ] Why track max fd?
- [ ] What events need separate handling?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Backpressure Policy</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Backpressure at socket level**

Key takeaways:
1. Write buffers can fill
2. Slow clients hurt everyone
3. Bounded queues protect process

### 🔨 Do (80 min)
Define per-client outbound buffer policy.

> 🆕 **New constraint:** Cap queued bytes per client and disconnect on abuse.

### ✅ Prove (20 min)
Slow-reader test scenario with expected disconnect threshold.

### 📦 Ship
`week-3/day3-backpressure-policy.md`

### 💡 Why This Matters
This day prevents one slow client from destabilizing the service. It introduces fairness as a correctness property. It unlocks formal backpressure controls in Month 2.

### 🧠 Self-Check
- [ ] Why cap per-client queue?
- [ ] What is fairness in I/O servers?
- [ ] When is forced disconnect correct?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Poll Migration</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**`poll` advantages over `select`**

Key takeaways:
1. Dynamic fd list
2. Simpler scaling
3. Cleaner event iteration

### 🔨 Do (80 min)
Plan migration from `select` to `poll`.

> 🆕 **New constraint:** Preserve exact protocol behavior while changing poller.

### ✅ Prove (20 min)
Regression checklist comparing outputs before/after migration.

### 📦 Ship
`week-3/day4-poll-migration-checklist.md`

### 💡 Why This Matters
You practice changing internals without changing behavior. This is key for long-lived systems. It unlocks future epoll upgrade with confidence.

### 🧠 Self-Check
- [ ] What behavior must stay identical?
- [ ] Why swap poller now?
- [ ] How do you detect regression quickly?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Connection Lifecycle Tests</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Connection churn handling**

Key takeaways:
1. Half-close states
2. Cleanup ordering
3. fd leak detection

### 🔨 Do (80 min)
Define lifecycle for open/read/write/error/close paths.

> 🆕 **New constraint:** Zero descriptor leaks under churn.

### ✅ Prove (20 min)
Run a churn script plan with leak counter target.

### 📦 Ship
`week-3/day5-connection-lifecycle-tests.md`

### 💡 Why This Matters
Resource leaks kill long-running services quietly. This day adds operational durability, not just correctness. It unlocks safe long soak tests.

### 🧠 Self-Check
- [ ] What is half-close?
- [ ] How do fd leaks appear?
- [ ] What cleanup order is safest?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: 30-Min Soak Test</b> ⏱️ 4h</summary>

### 📖 Learn (40 min)
**Load-testing basics**

Key takeaways:
1. Throughput vs latency
2. Percentile thinking
3. Bottleneck classification

### 🔨 Do (180 min)
Plan and run multi-client soak test design.

> 🆕 **New constraint:** Maintain service correctness for 30 minutes under sustained load.

### ✅ Prove (40 min)
Collect p50/p95 latency and error rate over time.

### 📦 Ship
`week-3/day6-soak-report.md`

### 💡 Why This Matters
This is first endurance check. It reveals memory and lifecycle faults hidden in short tests. It unlocks confidence before adding HTTP behavior.

### 🧠 Self-Check
- [ ] Which latency percentile matters most here?
- [ ] What failure appeared first?
- [ ] What metric suggests memory/resource issues?

</details>

---

## 📗 Chapter 4 — Epoll & HTTP Client (Week 4)

> **🎯 Theme:** Connect socket mechanics to real protocol interactions.
>
> **🆕 New skill:** `epoll`/timers + HTTP parsing
> **🔄 Reinforcement:** Framing/timeouts/error contracts

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Epoll Strategy</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**`epoll` model**

Key takeaways:
1. Registration lifecycle
2. Edge vs level triggers
3. Wakeup efficiency

### 🔨 Do (80 min)
Define epoll event strategy for your server.

> 🆕 **New constraint:** Choose trigger mode and justify starvation prevention.

### ✅ Prove (20 min)
Event-handling invariants checklist for missed-read prevention.

### 📦 Ship
`week-4/day1-epoll-strategy.md`

### 💡 Why This Matters
Efficient event notification matters as concurrency grows. This day hardens your architecture decisions before coding complexity rises. It unlocks timer-driven cleanup.

### 🧠 Self-Check
- [ ] Edge vs level tradeoff?
- [ ] How avoid missed events?
- [ ] What must happen after readiness?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Timer Design</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Timer integration with event loops**

Key takeaways:
1. Idle timeout wheel/heap
2. Timer drift awareness
3. Cleanup scheduling

### 🔨 Do (80 min)
Define idle timeout and periodic health checks.

> 🆕 **New constraint:** Stale connections removed without scanning all clients each tick.

### ✅ Prove (20 min)
Timeout-accuracy measurement plan.

### 📦 Ship
`week-4/day2-timer-design.md`

### 💡 Why This Matters
Timers prevent silent resource hoarding. This day adds temporal correctness to your server. It unlocks robust slow-client control.

### 🧠 Self-Check
- [ ] Why avoid full scans?
- [ ] What timer accuracy is acceptable?
- [ ] How log timeout reasons?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: HTTP Parser Spec</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**HTTP/1.1 essentials for clients**

Key takeaways:
1. Request line + headers
2. Status code families
3. `Content-Length` parsing

### 🔨 Do (80 min)
Specify simple HTTP client request/response parser behavior.

> 🆕 **New constraint:** Reject malformed headers with explicit error class.

### ✅ Prove (20 min)
Build parser test list for normal and malformed responses.

### 📦 Ship
`week-4/day3-http-parser-spec.md`

### 💡 Why This Matters
HTTP gives practical protocol parsing experience beyond echo. This day strengthens input-safety habits. It unlocks health-check integrations for later services.

### 🧠 Self-Check
- [ ] What is minimal valid HTTP response?
- [ ] How detect malformed headers?
- [ ] Why parse `Content-Length` carefully?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: HTTP Timeout Matrix</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**DNS/connect timeout behavior**

Key takeaways:
1. Connection phases
2. Timeout per phase
3. Distinguish transient vs permanent failures

### 🔨 Do (80 min)
Define HTTP client timeout and retry policy.

> 🆕 **New constraint:** Separate connect timeout from read timeout.

### ✅ Prove (20 min)
Failure matrix for unreachable host, slow server, partial response.

### 📦 Ship
`week-4/day4-http-timeout-matrix.md`

### 💡 Why This Matters
Separate timeout classes improve diagnosis and resilience. This mirrors real production client behavior. It unlocks robust node-to-node RPC later.

### 🧠 Self-Check
- [ ] Why separate connect/read timeout?
- [ ] Which failures are retryable?
- [ ] How should retry budget be set?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: End-to-End Trace</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Integration testing with local endpoints**

Key takeaways:
1. Deterministic fixtures
2. Request IDs across client/server
3. Reproducible logs

### 🔨 Do (80 min)
Define tests where HTTP client queries your server health endpoint.

> 🆕 **New constraint:** Consistent correlation ID across both tools.

### ✅ Prove (20 min)
End-to-end trace from request to server response log.

### 📦 Ship
`week-4/day5-e2e-trace.md`

### 💡 Why This Matters
End-to-end visibility is a systems superpower. This day links independent components through shared observability. It unlocks easier multi-node debugging next month.

### 🧠 Self-Check
- [ ] What was traced end-to-end?
- [ ] Why correlation ID matters?
- [ ] Which logs were required to debug one request?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — ARC BOSS: Month 1 Demo</b> ⏱️ 4h 🏆</summary>

### 📖 Learn (40 min)
**Month synthesis and gap analysis**

Key takeaways:
1. Architecture map
2. Bottleneck list
3. Reliability debt backlog

### 🔨 Do (180 min)
Build Month 1 integrated demo (CLI + echo server + event loop + HTTP client).

> 🆕 **New constraint:** Demo must include one induced failure and recovery behavior.

### ✅ Prove (40 min)
Capture baseline metrics and demo checklist completion.

### 📦 Ship
`month-1-demo/README.md` + `month-1-demo/diagram.png` + `week-4/day6-month1-report.md`

### 🏆 Achievement Unlocked: **Byte Wrangler**
> *You built a multi-client event-driven server with framing, timeouts, and observability from scratch.*

### 💡 Why This Matters
You close Month 1 with a coherent system, not fragments. Failure demonstration proves you understand behavior under stress. It unlocks concurrency and crypto work with a stable base.

### 🧠 Self-Check
- [ ] Which component is weakest now?
- [ ] What failure did you induce?
- [ ] What metric baseline carries into Month 2?

</details>

---

# ⚔️ Arc 2 — Hardening (Month 2)

> **🎯 Mission:** Add concurrency control and cryptographic trust primitives.
>
> **🧠 Mindset unlock:** *"Correctness under load needs both scheduling discipline and cryptographic guarantees."*

```
Month 2 Progress
[░░░░░░░░░░░░░░░░░░░░░░░░] 0% — Week 5 · 6 · 7 · 8
```

---

## 📕 Chapter 5 — Thread Pool & Safe Task Execution (Week 5)

> **🎯 Theme:** Event loop handles I/O; thread pool handles bounded CPU work.
>
> **🆕 New skill:** Thread synchronization and graceful shutdown
> **🔄 Reinforcement:** Queue limits and observability

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Concurrency Model</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**C++ threads and shared-state risks**

Key takeaways:
1. Data races are **undefined behavior**
2. Mutex protects invariants
3. Lock scope should be small

### 🔨 Do (80 min)
Define concurrency model (event loop + worker pool responsibilities).

> 🆕 **New constraint:** No shared mutable state without explicit ownership rule.

### ✅ Prove (20 min)
Ownership map of each shared object.

### 📦 Ship
`week-5/day1-concurrency-model.md`

### 💡 Why This Matters
This prevents ad-hoc locking as complexity grows. Clear ownership is the core of safe concurrency. It unlocks predictable task processing.

### 🧠 Self-Check
- [ ] What is a data race?
- [ ] Which state is thread-confined?
- [ ] Which state is shared and why?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Bounded Work Queue</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Producer-consumer queues**

Key takeaways:
1. Condition-variable signaling
2. Spurious wakeups
3. Bounded capacity

### 🔨 Do (80 min)
Design bounded work queue for worker pool.

> 🆕 **New constraint:** Hard max queue depth with explicit rejection behavior.

### ✅ Prove (20 min)
Overload scenario test plan at queue full condition.

### 📦 Ship
`week-5/day2-bounded-queue-spec.md`

### 💡 Why This Matters
Unbounded queues hide overload until memory collapses. This day makes overload visible and controllable. It unlocks backpressure strategy next week.

### 🧠 Self-Check
- [ ] Why bounded queue?
- [ ] What happens when full?
- [ ] What is correct wake-up condition?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Scheduling Policy</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Task scheduling fairness**

Key takeaways:
1. FIFO tradeoffs
2. Starvation risk
3. Task timeouts

### 🔨 Do (80 min)
Define task dispatch rules for CPU-bound work.

> 🆕 **New constraint:** Max task execution budget with cancellation path.

### ✅ Prove (20 min)
Test plan for one long task among many short tasks.

### 📦 Ship
`week-5/day3-scheduling-policy.md`

### 💡 Why This Matters
Fair scheduling keeps latency stable under mixed workloads. This avoids hidden starvation bugs. It unlocks predictable signing/hash workloads.

### 🧠 Self-Check
- [ ] What causes starvation?
- [ ] Why task budget?
- [ ] What should cancellation guarantee?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Contention Metrics</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Contention measurement basics**

Key takeaways:
1. Lock wait time
2. Queue wait time
3. Throughput-latency tradeoff

### 🔨 Do (80 min)
Define instrumentation points around queue and locks.

> 🆕 **New constraint:** Capture p95 queue wait for every task type.

### ✅ Prove (20 min)
Build metric collection checklist and expected ranges.

### 📦 Ship
`week-5/day4-contention-metrics.md`

### 💡 Why This Matters
Concurrency without measurement is guesswork. This day sets concrete performance evidence. It unlocks objective tuning.

### 🧠 Self-Check
- [ ] Which metric reveals contention first?
- [ ] Why p95 over average?
- [ ] What threshold means overload?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Graceful Shutdown</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Graceful shutdown design**

Key takeaways:
1. Stop intake first
2. Drain queue
3. Join workers safely

### 🔨 Do (80 min)
Define shutdown sequence and deadlines.

> 🆕 **New constraint:** Zero task loss for accepted work during graceful shutdown.

### ✅ Prove (20 min)
Shutdown test checklist with in-flight tasks.

### 📦 Ship
`week-5/day5-graceful-shutdown.md`

### 💡 Why This Matters
Clean shutdown is reliability, not polish. It protects correctness during deploys and crashes. It unlocks safer failure drills.

### 🧠 Self-Check
- [ ] What is shutdown order?
- [ ] How avoid task loss?
- [ ] When force-terminate?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Threadpool Benchmark</b> ⏱️ 4h</summary>

### 📖 Learn (40 min)
**Comparative benchmarking**

Key takeaways:
1. Single-thread baseline
2. Worker-pool scaling curve
3. Diminishing returns

### 🔨 Do (180 min)
Plan benchmark comparing event-loop-only vs event-loop+pool workloads.

> 🆕 **New constraint:** Publish scaling limit and likely bottleneck.

### ✅ Prove (40 min)
Capture throughput and p95 latency for 1/2/4 worker counts.

### 📦 Ship
`week-5/day6-threadpool-benchmark.md`

### 💡 Why This Matters
You need proof that concurrency helps, not just complexity. This day quantifies tradeoffs. It unlocks informed backpressure tuning.

### 🧠 Self-Check
- [ ] Where did scaling flatten?
- [ ] What bottleneck appeared?
- [ ] Which worker count is best and why?

</details>

---

## 📕 Chapter 6 — Backpressure & Overload Handling (Week 6)

> **🎯 Theme:** Survivability under load — core distributed-systems behavior.
>
> **🆕 New skill:** Overload policy and slow-client defense
> **🔄 Reinforcement:** Queue limits and timeouts

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Overload Policy Ladder</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Backpressure patterns**
1. Queue bounds → 2. Credit/token models → 3. Fail-fast responses

### 🔨 Do (80 min)
Define server overload policy ladder.
> 🆕 **New constraint:** Explicit reject mode when queue depth crosses threshold.

### ✅ Prove (20 min)
Threshold table with expected client-visible behavior.

### 📦 Ship
`week-6/day1-overload-policy.md`

### 💡 Why
Backpressure turns chaos into controlled degradation.

### 🧠 Self-Check
- [ ] Why fail fast? · What thresholds define overload? · How should clients respond to rejection?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Slow-Client Defense</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Slow-client attack patterns** — slowloris, read deadlines, per-connection quotas

### 🔨 Do (80 min)
Define slow-client defense strategy.
> 🆕 **New constraint:** Minimum progress rule for active connections.

### ✅ Prove (20 min)
Simulated slow-sender test plan and expected disconnect timing.

### 📦 Ship
`week-6/day2-slow-client-defense.md`

### 💡 Why
One bad peer can starve resources without this control.

### 🧠 Self-Check
- [ ] What is minimum progress rule? · Why not allow infinite slow sends? · What metric signals abuse?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Egress Throttle</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Write-side pressure control** — socket send buffer limits, app-level buffer caps, drop/close policy

### 🔨 Do (80 min)
Define outbound throttling behavior.
> 🆕 **New constraint:** Per-client egress rate limit with burst cap.

### ✅ Prove (20 min)
High-volume client test case verifying throttling kicks in.

### 📦 Ship
`week-6/day3-egress-throttle.md`

### 💡 Why
Protects server memory and fairness. Prepares you for replication traffic shaping.

### 🧠 Self-Check
- [ ] Why rate-limit writes? · What is burst cap? · When close vs throttle?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Deadline Budget</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Tail latency management** — p99 pain point, deadline propagation, timeout budget split

### 🔨 Do (80 min)
Define request deadline budget across stages.
> 🆕 **New constraint:** Drop request when deadline is exceeded at any stage.

### ✅ Prove (20 min)
Deadline violation scenario with expected logs.

### 📦 Ship
`week-6/day4-deadline-budget.md`

### 💡 Why
Deadlines prevent zombie work and long-tail collapse.

### 🧠 Self-Check
- [ ] Why p99 matters? · How split deadlines? · What should happen on expired deadline?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Failure Injection Matrix</b> ⏱️ 2h</summary>

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

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Backpressure Report</b> ⏱️ 4h</summary>

### 🔨 Do (180 min)
Run overload experiments and finalize backpressure thresholds.
> 🆕 **New constraint:** Maintain defined error-rate cap under target load.

### ✅ Prove (40 min)
Publish throughput/latency/error chart for normal vs overload.

### 📦 Ship
`week-6/day6-backpressure-report.md`

### 🧠 Self-Check
- [ ] Which threshold is most sensitive? · Did error-rate cap hold? · What tradeoff did you accept?

</details>

---

## 📕 Chapter 7 — Hashing & Integrity Proofs (Week 7)

> **🎯 Theme:** Tamper detection starts with digest correctness.
>
> **🆕 New skill:** Cryptographic integrity
> **🔄 Reinforcement:** Streaming and framing constraints

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Hash Use Cases</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Hash fundamentals** — preimage/collision concepts, integrity use, non-secret vs secret primitives

### 🔨 Do (80 min)
Define hash-tool use cases (files, payloads, logs).
> 🆕 **New constraint:** Canonical byte representation before hashing.

### ✅ Prove (20 min)
Cross-platform hash consistency test cases.

### 📦 Ship
`week-7/day1-hash-use-cases.md`

### 💡 Why
Hashing only helps if bytes are canonical. Prevents false mismatches in signatures later.

### 🧠 Self-Check
- [ ] Why canonicalization first? · What is collision risk in practice? · Where should hash be stored?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Streaming Hash Plan</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Streaming digest computation** — chunked updates, large-file memory safety, finalization

### 🔨 Do (80 min)
Define incremental hash workflow for large payloads.
> 🆕 **New constraint:** No full-file load into memory.

### ✅ Prove (20 min)
Large-input test plan with memory cap target.

### 📦 Ship
`week-7/day2-streaming-hash-plan.md`

### 🧠 Self-Check
- [ ] Why incremental hashing? · What memory cap is acceptable? · How verify same digest as one-shot?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Protocol Hash Envelope</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Integrity in protocols** — payload hash field, mismatch handling, logging forensic context

### 🔨 Do (80 min)
Add hash field to protocol envelope spec.
> 🆕 **New constraint:** Reject and audit any hash mismatch.

### ✅ Prove (20 min)
Tampered-payload scenario with expected reject reason.

### 📦 Ship
`week-7/day3-protocol-hash-envelope.md`

### 💡 Why
Upgrades protocol from transport-only to integrity-aware. Makes tampering visible.

### 🧠 Self-Check
- [ ] What does payload hash protect? · What does it NOT protect? · How should mismatch be reported?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Canonicalization Rules</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Hash misuse pitfalls** — hashing mutable forms, ambiguous encodings, wrong digest context

### 🔨 Do (80 min)
Define canonicalization and encoding rules for all hash inputs.
> 🆕 **New constraint:** Single canonical serialization for signed/hashed data.

### ✅ Prove (20 min)
Canonicalization regression cases (field order, whitespace, line endings).

### 📦 Ship
`week-7/day4-canonicalization-rules.md`

### 💡 Why
Most signature bugs are serialization bugs. Prevents cross-node verification failures.

### 🧠 Self-Check
- [ ] What fields must be canonicalized? · Why can whitespace break trust? · How lock serialization format?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Integrity Audit Drill</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Integrity audit workflows** — periodic scan, quarantine strategy, audit trail

### 🔨 Do (80 min)
Define hash-audit process for stored artifacts.
> 🆕 **New constraint:** Audit must detect silent file corruption.

### ✅ Prove (20 min)
Corrupt-one-byte drill and expected detection log.

### 📦 Ship
`week-7/day5-integrity-audit-drill.md`

### 🧠 Self-Check
- [ ] How often audit? · What happens on mismatch? · What evidence is preserved?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Hash Integration</b> ⏱️ 4h</summary>

### 🔨 Do (180 min)
Integrate hash tool and protocol digest fields into existing stack.
> 🆕 **New constraint:** Protocol versioning for backward compatibility.

### ✅ Prove (40 min)
Run compatibility tests between old/new message formats.

### 📦 Ship
`week-7/day6-hash-integration-report.md`

### 🧠 Self-Check
- [ ] Why version protocol now? · What compatibility break did you avoid? · Which old clients still work?

</details>

---

## 📕 Chapter 8 — Signatures & Replay Protection (Week 8)

> **🎯 Theme:** Identity and anti-replay are core trust-system primitives.
>
> **🆕 New skill:** Key lifecycle and signature verification
> **🔄 Reinforcement:** Canonicalization and protocol envelopes

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Key Policy</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Key lifecycle basics** — generation, storage permissions, rotation and revocation

### 🔨 Do (80 min)
Define key management policy for local dev system.
> 🆕 **New constraint:** Key files must have restricted permissions and versioned key IDs.

### ✅ Prove (20 min)
Key-file permission and key-ID mapping checklist.

### 📦 Ship
`week-8/day1-key-policy.md`

### 🧠 Self-Check
- [ ] Why key IDs? · What permission model is required? · When rotate keys?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Sign/Verify Spec</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Signature verification flow** — sign canonical bytes, verify before processing, fail closed

### 🔨 Do (80 min)
Define sign/verify CLI behavior and errors.
> 🆕 **New constraint:** Reject any unsigned or unverifiable message by default.

### ✅ Prove (20 min)
Invalid-signature test matrix (wrong key, altered payload, altered metadata).

### 📦 Ship
`week-8/day2-sign-verify-spec.md`

### 💡 Why
This is your first identity-bound protocol enforcement. Changes trust from "maybe honest" to **verifiable**.

### 🧠 Self-Check
- [ ] What exactly is signed? · Why verify before processing? · What is fail-closed behavior?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Replay Defense</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Replay attacks and nonce design** — old valid message replay, nonce uniqueness, timestamp window

### 🔨 Do (80 min)
Define replay-defense policy with nonce cache + time window.
> 🆕 **New constraint:** Duplicate `(key_id, nonce)` is ALWAYS rejected.

### ✅ Prove (20 min)
Replay test where same signed packet is resent 3 times.

### 📦 Ship
`week-8/day3-replay-policy.md`

### 💡 Why
Integrity alone does NOT stop replay. You need temporal + uniqueness constraints.

### 🧠 Self-Check
- [ ] Why signatures don't stop replay? · How long keep nonce cache? · What about clock skew?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Signed Envelope v1</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Envelope versioning and compatibility** — signed header fields, extensibility, deprecation

### 🔨 Do (80 min)
Finalize signed protocol envelope schema.
> 🆕 **New constraint:** Include protocol version and mandatory signed metadata.

### ✅ Prove (20 min)
Version compatibility scenarios and expected outcomes.

### 📦 Ship
`week-8/day4-signed-envelope-v1.md`

### 🧠 Self-Check
- [ ] Which headers must be signed? · Why include version in signature? · How handle unknown version?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Verify Performance</b> ⏱️ 2h</summary>

### 📖 Learn (30 min)
**Verification performance and caching** — key cache, signature verify cost, rejection fast path

### 🔨 Do (80 min)
Define verification pipeline optimization plan.
> 🆕 **New constraint:** Cap verification latency while preserving fail-closed semantics.

### ✅ Prove (20 min)
Measure expected verification cost for small vs large payloads.

### 📦 Ship
`week-8/day5-verify-performance.md`

### 🧠 Self-Check
- [ ] Where is verify bottleneck? · What can be cached safely? · What must NEVER bypass verification?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — ARC BOSS: Signed Protocol Demo</b> ⏱️ 4h 🏆</summary>

### 🔨 Do (180 min)
Build integrated signed protocol demo (client-server).
> 🆕 **New constraint:** Full request path enforces signature + replay + timeout.

### ✅ Prove (40 min)
Capture pass/fail evidence for valid, tampered, replayed, and expired requests.

### 📦 Ship
`month-2-demo/README.md` + `week-8/day6-signed-protocol-report.md`

### 🏆 Achievement Unlocked: **Trust Forger**
> *You built a signed, replay-protected network protocol with overload controls.*

### 🧠 Self-Check
- [ ] Which attacks are now blocked? · What still is NOT covered? · Which log proves replay defense worked?

</details>

---

# 🏰 Arc 3 — Distributed Core (Month 3)

> **🎯 Mission:** Build distributed core with durability, replication, and failure-tolerant clients.
>
> **🧠 Mindset unlock:** *"Correctness means surviving crashes, retries, and partial failures."*

```
Month 3 Progress
[░░░░░░░░░░░░░░░░░░░░░░░░] 0% — Week 9 · 10 · 11 · 12
```

---

## 📙 Chapter 9 — KV Store Core & State Model (Week 9)

> **🆕 New skill:** State-machine design
> **🔄 Reinforcement:** Protocol contracts and request IDs

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: KV Command Spec</b> ⏱️ 2h</summary>

### 📖 Learn — KV state machine basics: commands mutate state, reads are deterministic, invalid ops are explicit
### 🔨 Do — Define `put/get/delete` + response schema. **Constraint:** Every mutating command requires unique request ID.
### ✅ Prove — Command validity matrix including missing keys and duplicate IDs.
### 📦 Ship — `week-9/day1-kv-command-spec.md`
### 🧠 Self-Check
- [ ] Why request IDs on writes? · How should missing keys respond? · What makes command deterministic?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Versioning Rules</b> ⏱️ 2h</summary>

### 📖 Learn — In-memory indexing and versioning: version counters, optimistic conflict awareness, metadata separation
### 🔨 Do — Define key metadata model including version and last-update term. **Constraint:** Version increments on every successful write.
### ✅ Prove — Concurrent-write scenario expectations table.
### 📦 Ship — `week-9/day2-versioning-rules.md`
### 🧠 Self-Check
- [ ] Why track version? · What is stale write? · Which metadata will replication need?

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Serialization Format</b> ⏱️ 2h</summary>

### 📖 Learn — Serialization design: stable field ordering, forward compatibility, checksums
### 🔨 Do — Define binary/text record format for snapshot and logs. **Constraint:** Include checksum for each persisted record.
### ✅ Prove — Corrupted-record detection test plan.
### 📦 Ship — `week-9/day3-serialization-format.md`
### 🧠 Self-Check
- [ ] Why checksum each record? · What breaks forward compatibility? · How detect decode errors safely?

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Snapshot Rules</b> ⏱️ 2h</summary>

### 📖 Learn — Snapshot strategy: point-in-time copy, atomic replace, metadata headers
### 🔨 Do — Define snapshot creation and load rules. **Constraint:** Snapshot apply only if checksum and schema version pass.
### ✅ Prove — Snapshot corruption scenario and expected fallback behavior.
### 📦 Ship — `week-9/day4-snapshot-rules.md`
### 🧠 Self-Check
- [ ] Why need snapshots if WAL exists? · When reject snapshot? · What metadata is mandatory?

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: KV Concurrency Policy</b> ⏱️ 2h</summary>

### 📖 Learn — Concurrency in state machines: serialize writes, read consistency, lock granularity
### 🔨 Do — Define concurrency policy for KV operations. **Constraint:** Single-writer discipline to preserve ordering.
### ✅ Prove — Race test design with concurrent reads/writes.
### 📦 Ship — `week-9/day5-kv-concurrency-policy.md`
### 🧠 Self-Check
- [ ] Why single-writer now? · What read consistency is acceptable? · Where can parallelism remain?

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: KV + Signed Integration</b> ⏱️ 4h</summary>

### 🔨 Do — Compose signed request handling with KV command execution. **Constraint:** Reject unsigned state-changing commands.
### ✅ Prove — End-to-end signed `put/get/delete` scenario evidence.
### 📦 Ship — `week-9/day6-kv-signed-integration.md`
### 🧠 Self-Check
- [ ] Which commands require signature? · How is request ID propagated? · What evidence proves integration works?

</details>

---

## 📙 Chapter 10 — WAL Durability & Crash Recovery (Week 10)

> **🆕 New skill:** Write-ahead logging + recovery discipline
> **🔄 Reinforcement:** Checksums and deterministic command model

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: WAL Schema</b> ⏱️ 2h</summary>

### 📖 Learn — WAL principles: append before apply, durable ordering, fsync policy tradeoff
### 🔨 Do — Define WAL record schema and append sequence. **Constraint:** State apply ONLY after WAL append success.
### ✅ Prove — Sequence-of-events checklist for each command.
### 📦 Ship — `week-10/day1-wal-schema.md`
### 🧠 Self-Check
- [ ] Why append-before-apply? · What if append fails? · Which fields must WAL include?

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Fsync Policy</b> ⏱️ 2h</summary>

### 📖 Learn — Durability levels: sync every write, batch sync, risk/performance tradeoff
### 🔨 Do — Define fsync policy by command class. **Constraint:** Critical writes require immediate sync mode.
### ✅ Prove — Durability policy table with expected latency impact.
### 📦 Ship — `week-10/day2-fsync-policy.md`

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Crash Drill Procedure</b> ⏱️ 2h</summary>

### 📖 Learn — Crash simulation: abrupt termination, partial write risks, restart verification
### 🔨 Do — Define crash-drill procedure around write operations. **Constraint:** Must detect and ignore torn/corrupt WAL tail.
### ✅ Prove — Crash case matrix: before append, after append, after apply.
### 📦 Ship — `week-10/day3-crash-drill-procedure.md`

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Recovery Algorithm</b> ⏱️ 2h</summary>

### 📖 Learn — Recovery replay: idempotent replay, checksum validation, replay cutoff rules
### 🔨 Do — Define startup replay algorithm and validation gates. **Constraint:** Stop replay at first invalid record and quarantine remainder.
### ✅ Prove — Recovery scenario walkthrough with expected final state.
### 📦 Ship — `week-10/day4-recovery-algorithm.md`

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Checkpoint & Compaction</b> ⏱️ 2h</summary>

### 📖 Learn — Checkpoint and compaction: reduce replay time, consistent cut, WAL truncation safety
### 🔨 Do — Define checkpoint trigger policy and truncation rules. **Constraint:** Truncate ONLY after verified checkpoint durability.
### ✅ Prove — Checkpoint/truncate invariants checklist.
### 📦 Ship — `week-10/day5-checkpoint-compaction.md`

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Durability Report</b> ⏱️ 4h</summary>

### 🔨 Do — Run crash/restart benchmark scenarios for WAL modes. **Constraint:** Define and meet target RTO for restart.
### ✅ Prove — Publish durability vs latency table and recovery timings.
### 📦 Ship — `week-10/day6-durability-report.md`
### 🧠 Self-Check
- [ ] What RTO did you meet? · Which mode has best balance? · Did any committed write get lost?

</details>

---

## 📙 Chapter 11 — Replicated KV (2–3 Nodes) (Week 11)

> **🆕 New skill:** Replication protocol and quorum logic
> **🔄 Reinforcement:** WAL ordering and signed envelopes

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Failure Model</b> ⏱️ 2h</summary>

### 📖 Learn — Failure models: crash-stop, message delay/loss, no Byzantine assumption yet
### 🔨 Do — Define replication assumptions and node roles. **Constraint:** Explicit model excludes Byzantine peers for this phase.
### 📦 Ship — `week-11/day1-failure-model.md`

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Append RPC Spec</b> ⏱️ 2h</summary>

### 📖 Learn — Leader-to-follower log shipping: append entries RPC, prev-index consistency check, ack semantics
### 🔨 Do — Define append RPC fields and follower validation. **Constraint:** Follower rejects append with mismatched previous index/term.
### 📦 Ship — `week-11/day2-append-rpc-spec.md`

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Quorum Commit Rules</b> ⏱️ 2h</summary>

### 📖 Learn — Quorum commit: majority acknowledgment, commit index advancement, stale acks
### 🔨 Do — Define commit criteria for 3-node cluster. **Constraint:** Leader applies entry ONLY after majority acks.
### 📦 Ship — `week-11/day3-quorum-commit-rules.md`

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Follower Catch-Up</b> ⏱️ 2h</summary>

### 📖 Learn — Retry from lower index, conflict resolution, snapshot install fallback
### 🔨 Do — Define catch-up sequence for lagging follower. **Constraint:** Bounded retry steps before snapshot fallback.
### 📦 Ship — `week-11/day4-follower-catchup.md`

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Partition Policy</b> ⏱️ 2h</summary>

### 📖 Learn — Partition behavior: split-brain risk, minority isolation, recovery sequencing
### 🔨 Do — Define partition behavior policy. **Constraint:** Minority side CANNOT accept committed writes.
### 📦 Ship — `week-11/day5-partition-policy.md`

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — BOSS FIGHT: Replication Validation</b> ⏱️ 4h</summary>

### 🔨 Do — Run replicated KV validation plan across 2–3 nodes. **Constraint:** Identical committed state after node restart and catch-up.
### ✅ Prove — Publish state-hash comparison across nodes after drills.
### 📦 Ship — `week-11/day6-replication-validation.md`

</details>

---

## 📙 Chapter 12 — Leader Election + Client Idempotency (Week 12)

> **🆕 New skill:** Term-based leader election and idempotent retries
> **🔄 Reinforcement:** Request IDs and quorum semantics

<details>
<summary>🗓️ <b>Day 1 (Mon) — Quest: Election Timeouts</b> ⏱️ 2h</summary>

### 📖 Learn — Randomized timeout reduces split votes, heartbeat cadence, term monotonicity
### 🔨 Do — Define election timeout/heartbeat ranges. **Constraint:** Randomized election timeout per node.
### 📦 Ship — `week-12/day1-election-timeouts.md`

</details>

<details>
<summary>🗓️ <b>Day 2 (Tue) — Quest: Vote Rules</b> ⏱️ 2h</summary>

### 📖 Learn — One vote per term, up-to-date log requirement, term update on newer term seen
### 🔨 Do — Define candidate/voter state transitions. **Constraint:** Reject vote if candidate log is stale.
### 📦 Ship — `week-12/day2-vote-rules.md`

</details>

<details>
<summary>🗓️ <b>Day 3 (Wed) — Quest: Client Retry + Idempotency</b> ⏱️ 2h</summary>

### 📖 Learn — Retry under leader changes, same request ID, redirect hints
### 🔨 Do — Define client retry policy for `not_leader` and timeout errors. **Constraint:** All retries reuse original request ID.
### 📦 Ship — `week-12/day3-client-retry-idempotency.md`

</details>

<details>
<summary>🗓️ <b>Day 4 (Thu) — Quest: Dedupe Store Rules</b> ⏱️ 2h</summary>

### 📖 Learn — Store recent request IDs, response replay, expiration policy
### 🔨 Do — Define dedupe store rules and TTL. **Constraint:** Duplicate request returns original response, NOT re-execution.
### 📦 Ship — `week-12/day4-dedupe-store-rules.md`

</details>

<details>
<summary>🗓️ <b>Day 5 (Fri) — Quest: Stale-Leader Fencing</b> ⏱️ 2h</summary>

### 📖 Learn — Term-based fencing, stale write rejection, role transition logging
### 🔨 Do — Define stale-leader handling path. **Constraint:** Any request carrying old term is rejected.
### 📦 Ship — `week-12/day5-stale-leader-fencing.md`

</details>

<details>
<summary>🗡️ <b>Day 6 (Sat) — ARC BOSS: Month 3 Demo</b> ⏱️ 4h 🏆</summary>

### 🔨 Do — Build Month 3 integrated demo (durable replicated KV + retries). **Constraint:** Include crash + failover + retry scenario in one scripted flow.
### ✅ Prove — No lost committed writes, no duplicate effects.
### 📦 Ship — `month-3-demo/README.md` + `week-12/day6-month3-report.md`

### 🏆 Achievement Unlocked: **Fault Tamer**
> *You built a replicated KV store that survives crashes, leader failures, and retries safely.*

</details>

---

# 🔮 Arc 4 — Trust Architecture (Month 4)

> **🎯 Mission:** Build tamper-evident trust architecture (CAS + Merkle + transparency log + monitor).
>
> **🧠 Mindset unlock:** *"Trust is not hidden internals; it is publicly verifiable evidence."*

```
Month 4 Progress
[░░░░░░░░░░░░░░░░░░░░░░░░] 0% — Week 13 · 14 · 15 · 16
```

---

## 📘 Chapter 13 — Content-Addressed Storage (Week 13)

> **🆕 New skill:** Hash-addressed object lifecycle
> **🔄 Reinforcement:** Canonical hashing and persistence safety

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | CAS Object Model | Object ID = canonical-hash of normalized bytes | `week-13/day1-cas-object-model.md` |
| Tue | CAS Write Lifecycle | Incomplete writes never appear as valid objects | `week-13/day2-cas-write-lifecycle.md` |
| Wed | Chunk Manifest Spec | Manifest hash commits to chunk order and sizes | `week-13/day3-chunk-manifest-spec.md` |
| Thu | CAS GC Policy | Deletion only for unreachable objects after retention delay | `week-13/day4-cas-gc-policy.md` |
| Fri | CAS Audit Drill | Audit produces machine-parseable discrepancy report | `week-13/day5-cas-audit-drill.md` |
| **Sat** 🗡️ | **BOSS: CAS + KV Integration** | State mutation rejected if referenced CAS object missing | `week-13/day6-cas-kv-integration.md` |

<details>
<summary>📋 Expand full daily details...</summary>

**Mon — CAS Object Model:** Learn CAS principles (address = hash, immutability by design, dedup by identity). Prove with same-content-same-ID test cases.

**Tue — CAS Write Lifecycle:** Learn blob persistence (object path mapping, atomic write-then-rename, checksum at rest). Prove with interrupted-write scenario.

**Wed — Chunk Manifest Spec:** Learn chunking (fixed vs rolling, manifest object, reassembly). Prove with chunk-reorder tamper detection.

**Thu — CAS GC Policy:** Learn garbage collection (reachability roots, mark/sweep, safety window). Prove with reachability audit.

**Fri — CAS Audit Drill:** Learn store-level integrity (recalc hash, compare object ID, quarantine). Prove with intentional one-byte corruption.

**Sat — Integration:** Define integration path where KV stores document references via CAS IDs. Prove with end-to-end reference validation.

</details>

---

## 📘 Chapter 14 — Merkle Trees & Inclusion Proofs (Week 14)

> **🆕 New skill:** Proof algorithms
> **🔄 Reinforcement:** Canonical hashing and CAS identities

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Merkle Construction Rules | Deterministic leaf ordering across nodes | `week-14/day1-merkle-construction-rules.md` |
| Tue | Inclusion Proof Format | Proof includes leaf index and tree size | `week-14/day2-inclusion-proof-format.md` |
| Wed | Proof Verifier Rules | Fail-closed on any malformed proof element | `week-14/day3-proof-verifier-rules.md` |
| Thu | Incremental Merkle Plan | Append update must not recompute entire tree | `week-14/day4-incremental-merkle-plan.md` |
| Fri | Adversarial Proof Tests | Stale root proofs explicitly marked unverifiable | `week-14/day5-adversarial-proof-tests.md` |
| **Sat** 🗡️ | **BOSS: Merkle Performance** | Publish max acceptable proof verification latency | `week-14/day6-merkle-performance-report.md` |

---

## 📘 Chapter 15 — Transparency Log (Week 15)

> **🆕 New skill:** Consistency proofs and checkpoint signing
> **🔄 Reinforcement:** Merkle proofs and key management

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Log Append Contract | No deletion or in-place mutation of historical entries | `week-15/day1-log-append-contract.md` |
| Tue | Inclusion API Bundle | Every proof response references signed checkpoint | `week-15/day2-inclusion-api-bundle.md` |
| Wed | Consistency Proof Rules | Any new checkpoint must be consistency-provable from previous | `week-15/day3-consistency-proof-rules.md` |
| Thu | Checkpoint Signature Schema | Checkpoint includes monotonic sequence + signing key ID | `week-15/day4-checkpoint-signature-schema.md` |
| Fri | Verifier Workflow | Reject proof lacking checkpoint continuity from cached state | `week-15/day5-verifier-workflow.md` |
| **Sat** 🗡️ | **BOSS: Auditor Design** | Auditor detects and reports checkpoint inconsistencies | `week-15/day6-auditor-design.md` |

---

## 📘 Chapter 16 — Monitoring & Anti-Equivocation (Week 16)

> **🆕 New skill:** Monitor gossip and incident response
> **🔄 Reinforcement:** Checkpoints/proofs/signature verification

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Monitor Architecture | Monitor stores immutable observation log | `week-16/day1-monitor-architecture.md` |
| Tue | Monitor Gossip Schema | Gossip includes signed checkpoint + source metadata | `week-16/day2-monitor-gossip-schema.md` |
| Wed | Equivocation Detection | Any conflict generates signed incident record | `week-16/day3-equivocation-detection.md` |
| Thu | Alert Policy | Critical alerts require cryptographic evidence attachment | `week-16/day4-alert-policy.md` |
| Fri | Incident Runbook | Runbook includes freeze-new-acceptance decision criteria | `week-16/day5-incident-runbook.md` |
| **Sat** 🗡️ | **ARC BOSS: Month 4 Trust Demo** 🏆 | Include simulated equivocation + monitor response | `month-4-demo/README.md` + `week-16/day6-month4-report.md` |

> ### 🏆 Achievement Unlocked: **Trust Architect**
> *You built a tamper-evident transparency system with proofs, monitors, and incident detection.*

---

# 👑 Arc 5 — CivicTrust Capstone (Month 5)

> **🎯 Mission:** Compose identity, transparency, verification, and failure handling into one workflow.
>
> **🧠 Mindset unlock:** *"Real systems combine everything into one workflow."*

```
Month 5 Progress
[░░░░░░░░░░░░░░░░░░░░░░░░] 0% — Week 17 · 18 · 19 · 20
```

---

## 📓 Chapter 17 — Issue Signed Civic Documents (Week 17)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Document Schema | Schema includes issuer ID, issue time, expiration, canonical hash | `week-17/day1-document-schema.md` |
| Tue | Issuer Key Policy | Verification supports prior active keys within overlap window | `week-17/day2-issuer-key-policy.md` |
| Wed | Issue Workflow | Issued document content is immutable after signature | `week-17/day3-issue-workflow.md` |
| Thu | Verify & Revocation Rules | Revoked issuer/doc fails verification even with valid signature | `week-17/day4-verify-revocation-rules.md` |
| Fri | Policy Gates | Policy validation occurs before signing | `week-17/day5-policy-gates.md` |
| **Sat** 🗡️ | **BOSS: Issuance Demo** | Full traceability from request ID to signed document hash | `week-17/day6-issuance-demo.md` |

---

## 📓 Chapter 18 — Transparency Log Anchoring (Week 18)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Anchoring Workflow | Issuance not "final" until anchoring receipt obtained | `week-18/day1-anchoring-workflow.md` |
| Tue | Receipt Bundle Schema | Bundle must be self-contained for offline verification | `week-18/day2-receipt-bundle-schema.md` |
| Wed | Anchor Verifier Sequence | Any missing step yields `unverified`, never soft-pass | `week-18/day3-anchor-verifier-sequence.md` |
| Thu | Receipt Freshness Policy | Reject receipts older than freshness window | `week-18/day4-receipt-freshness-policy.md` |
| Fri | Anchoring Attack Matrix | System distinguishes `not_anchored`, `tampered`, `stale` | `week-18/day5-anchoring-attack-matrix.md` |
| **Sat** 🗡️ | **BOSS: Pipeline Integration** | Failed anchoring triggers compensating status, not silent success | `week-18/day6-pipeline-integration.md` |

---

## 📓 Chapter 19 — Offline Verification Package (Week 19)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Verifier UX Contract | One-line machine status + human explanation block | `week-19/day1-verifier-ux-contract.md` |
| Tue | Offline Bundle Format | Bundle verifies completeness before cryptographic checks | `week-19/day2-offline-bundle-format.md` |
| Wed | Air-Gap Verification Flow | No remote calls allowed in offline mode | `week-19/day3-airgap-verification-flow.md` |
| Thu | Time Policy Modes | Verifier output includes policy mode used (`strict`/`grace`/`archival`) | `week-19/day4-time-policy-modes.md` |
| Fri | Batch Verifier Rules | Per-document verdicts even if one bundle fails | `week-19/day5-batch-verifier-rules.md` |
| **Sat** 🗡️ | **BOSS: Offline Verifier Guide** | Guide includes ≥5 common failure interpretations | `week-19/day6-offline-verifier-guide.md` |

---

## 📓 Chapter 20 — Failure Survival Hardening (Week 20)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Chaos Matrix | Each test specifies expected degraded mode + recovery trigger | `week-20/day1-chaos-matrix.md` |
| Tue | Node Crash Drill | No duplicate document issuance after leader crash | `week-20/day2-node-crash-drill.md` |
| Wed | Partition Drill | Minority partition cannot produce final anchored documents | `week-20/day3-partition-drill.md` |
| Thu | Key Compromise Runbook | Compromised key cannot sign new checkpoints after cutoff | `week-20/day4-key-compromise-runbook.md` |
| Fri | Restore Validation | Restored system proves continuity from last valid checkpoint | `week-20/day5-restore-validation.md` |
| **Sat** 🗡️ | **ARC BOSS: Hardening Report** 🏆 | Each unresolved risk has mitigation owner + timeline | `month-5-demo/hardening-report.md` + `week-20/day6-month5-report.md` |

> ### 🏆 Achievement Unlocked: **Chaos Survivor**
> *You composed a full civic trust system and proved it survives crashes, partitions, and key compromise.*

---

# 🚀 Arc 6 — Ship It (Month 6)

> **🎯 Mission:** Package technical depth into employable proof.
>
> **🧠 Mindset unlock:** *"Great engineering includes clear evidence, clear stories, and clear tradeoffs."*

```
Month 6 Progress
[░░░░░░░░░░░░░░░░░░░░░░░░] 0% — Week 21 · 22 · 23 · 24
```

---

## 📒 Chapter 21 — Reliability / SLO Story (Week 21)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | SLI/SLO Table | Each SLO maps to one user-visible outcome | `week-21/day1-sli-slo-table.md` |
| Tue | Metrics Design | Avoid high-cardinality labels that break observability | `week-21/day2-metrics-design.md` |
| Wed | Dashboard Spec | Dashboard shows SLO status + recent error-budget burn | `week-21/day3-dashboard-spec.md` |
| Thu | Alert Rules | Paging only for user-impacting or trust-critical conditions | `week-21/day4-alert-rules.md` |
| Fri | Capacity Plan | Include 2x surge headroom target | `week-21/day5-capacity-plan.md` |
| **Sat** 🗡️ | **BOSS: Reliability Story** | Every guarantee statement references concrete evidence | `week-21/day6-reliability-story.md` |

---

## 📒 Chapter 22 — Security / Threat Model Story (Week 22)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Threat Model Map (STRIDE) | Every component has explicit trust boundary + threat owner | `week-22/day1-threat-model-map.md` |
| Tue | Abuse Cases (Top 10) | Each includes detection signal + response action | `week-22/day2-abuse-cases.md` |
| Wed | Threat-Control Matrix | Every high-risk threat: ≥1 preventive + ≥1 detective control | `week-22/day3-threat-control-matrix.md` |
| Thu | Supply Chain & Secrets | No hardcoded secrets + documented rotation cadence | `week-22/day4-supplychain-secrets-policy.md` |
| Fri | Security Test Plan | Include one cross-component attack path test | `week-22/day5-security-test-plan.md` |
| **Sat** 🗡️ | **BOSS: Security Story** | Explicitly list "not solved yet" risks | `week-22/day6-security-story.md` |

---

## 📒 Chapter 23 — Docs, Demos & Interview Narratives (Week 23)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Architecture Diagram Plan | Every trust guarantee maps to one diagram element | `week-23/day1-architecture-diagram-plan.md` |
| Tue | README Outline | Quickstart reaches 1 successful verify in <15 min | `week-23/day2-readme-outline.md` |
| Wed | Demo Script | Include one planned failure + recovery segment | `week-23/day3-demo-script.md` |
| Thu | Video Storyboard | Each claim shown with on-screen evidence | `week-23/day4-video-storyboard.md` |
| Fri | Interview Story Bank (STAR) | 8 stories, each with one metric + one tradeoff | `week-23/day5-interview-story-bank.md` |
| **Sat** 🗡️ | **BOSS: Portfolio Index** | Every major claim links to one artifact | `week-23/day6-portfolio-index.md` |

---

## 📒 Chapter 24 — Final Interview Prep & Publication (Week 24)

| Day | Quest | Key Constraint | Ship |
|-----|-------|----------------|------|
| Mon | Distributed Systems Q&A | Each answer includes one concrete project example | `week-24/day1-dist-sys-qa.md` |
| Tue | Trust Architecture Q&A | Include one "limitation" answer per security claim | `week-24/day2-trust-qa.md` |
| Wed | Debug Drills | Each drill ends with measurable confirmation step | `week-24/day3-debug-drills.md` |
| Thu | System Design Walkthrough | Separate MVP and hardening phases | `week-24/day4-system-design-walkthrough.md` |
| Fri | Final Demo Rehearsal | Complete in target time with one intentional failure drill | `week-24/day5-final-demo-scorecard.md` |
| **Sat** 🗡️ | **FINAL BOSS: Publish & Retrospective** 🏆 | Retrospective includes measurable before/after capability table | `month-6-final/README.md` + `month-6-final/retrospective.md` + `month-6-final/demo-script.md` |

> ### 🏆 Achievement Unlocked: **Distributed Trust Engineer**
> *You shipped a civic-grade trust system with verified failure behavior, documented guarantees, and interview-ready proof.*

---

# 🚩 Weekly Boss Fights (Checkpoints)

> **Rule:** Do NOT advance to the next chapter unless you pass the gate. No exceptions.

| Week | Demo Must Show | 💥 Failure Drill | ✅ Pass If... |
|------|---------------|-----------------|--------------|
| **1** | CLI commands + logger + error catalog | Permission denied on log path | All exit codes match contract |
| **2** | Echo works + framing + timeout logs | Client disconnect mid-frame | No crash + clear error classification |
| **3** | 50+ clients + bounded buffers + churn | Slow reader with growing buffer | No fd leaks + stable under churn |
| **4** | Epoll + HTTP parser + e2e trace IDs | Malformed HTTP response header | Parser rejects safely + logs reason |
| **5** | Bounded queue + shutdown + metrics | Queue saturation | Deterministic overload + no task loss |
| **6** | Overload thresholds + slow-client defense | Slowloris-like sender | Predictable degradation, no memory runaway |
| **7** | Hash tool + protocol digest + corruption drill | One-byte payload tamper | Tamper always detected and rejected |
| **8** | Key policy + signed envelope + replay rules | Replay previously valid request | Replayed request rejected with reason |
| **9** | KV contract + versioning + signed commands | Duplicate request ID on mutation | Duplicate does not reapply |
| **10** | WAL schema + crash drill matrix | Crash after WAL append | Committed write survives, corrupt tail handled |
| **11** | Append RPC + quorum + partition policy | Follower lag then rejoin | Nodes converge to identical state hash |
| **12** | Election + retry/idempotency + fencing | Leader fails during client write | No lost commits + no duplicate effects |
| **13** | CAS model + chunks + GC + audit | Interrupted CAS write | Incomplete object never appears valid |
| **14** | Merkle rules + proofs + verifier + perf | Malformed inclusion proof | Verifier fails closed on all bad inputs |
| **15** | Log contract + inclusion/consistency + checkpoints | Inconsistent checkpoint continuity | Discontinuous chain rejected |
| **16** | Monitor + gossip + equivocation + runbook | Conflicting checkpoints same size | Conflict → signed incident + critical alert |
| **17** | Doc schema + issuer + verify + revocation | Policy-violating issuance attempt | Policy violation blocks signing + logs |
| **18** | Anchoring + receipt bundle + freshness | Issue succeeds but anchoring fails | Document stays non-final, status explicit |
| **19** | Offline bundle + air-gap verifier + batch | Bundle missing one proof artifact | Deterministic `unverified` reason returned |
| **20** | Chaos matrix + crash/partition/key drills | Combined partition + leader crash | No duplicate issuance + recovery documented |
| **21** | SLI/SLO + metrics + dashboard + alerts | Synthetic SLO breach | Breach detected, alerted, explained |
| **22** | Threat map + abuse cases + controls | Replay + stale checkpoint attack | Detection + response steps documented |
| **23** | Diagram + README + demo + stories + index | Teammate follows quickstart with mistake | User recovers via docs without help |
| **24** | Q&A + drills + design + demo scorecard | Live demo component outage | Fallback preserves trust narrative in time |

### 🔄 Weekly Reflection Prompts

After each weekly gate, answer these three questions in your notes:
1. **What surprised you?** — the unexpected behavior or bug
2. **What's the weakest link?** — the component you trust least
3. **What carries forward?** — what artifact or insight feeds next week

---

# 📊 Monthly Level-Ups

### 🌍 Month 1 — Level Up: **Byte Wrangler**
| | |
|---|---|
| **Can build now** | Event-loop TCP service with framing/timeouts, reusable CLI/logger, HTTP client |
| **Biggest risk** | Uncontrolled load + no crypto trust |
| **Next month fixes** | Thread pool, backpressure, hashes, signatures, replay defense |
| **📦 Publish** | `month-1-demo/README.md` + architecture diagram + latency table |

### ⚔️ Month 2 — Level Up: **Trust Forger**
| | |
|---|---|
| **Can build now** | Signed, replay-protected network protocol with overload controls |
| **Biggest risk** | Single-node state loss + no replication |
| **Next month fixes** | WAL recovery, quorum replication, election, idempotent retries |
| **📦 Publish** | `month-2-demo/README.md` + signed envelope diagram + tamper demo |

### 🏰 Month 3 — Level Up: **Fault Tamer**
| | |
|---|---|
| **Can build now** | Durable replicated KV cluster surviving crashes/failovers with safe retries |
| **Biggest risk** | No external transparency evidence |
| **Next month fixes** | CAS, Merkle proofs, transparency log, monitors |
| **📦 Publish** | `month-3-demo/README.md` + replication diagram + failover demo |

### 🔮 Month 4 — Level Up: **Trust Architect**
| | |
|---|---|
| **Can build now** | Tamper-evident transparency subsystem with proofs + signed checkpoints + monitoring |
| **Biggest risk** | Missing product workflow integration |
| **Next month fixes** | Issuance, anchoring, offline verification, failure survival |
| **📦 Publish** | `month-4-demo/README.md` + trust architecture diagram + equivocation demo |

### 👑 Month 5 — Level Up: **Chaos Survivor**
| | |
|---|---|
| **Can build now** | CivicTrust system: signed docs, transparency anchoring, offline verify, failure survival |
| **Biggest risk** | Weak employability packaging |
| **Next month fixes** | SLO narrative, threat model, polished docs/demos/interview prep |
| **📦 Publish** | `month-5-demo/README.md` + end-to-end dataflow diagram + failure drill reel |

### 🚀 Month 6 — Level Up: **Distributed Trust Engineer**
| | |
|---|---|
| **Can build now** | End-to-end distributed trust platform with verified guarantees + interview narratives |
| **Next challenge** | Byzantine tolerance, formal verification, or production deployment |
| **📦 Publish** | `month-6-final/README.md` + final diagram + demo video + Q&A pack |

---

## 🎓 You Beat the Game. Now What?

```
╔══════════════════════════════════════════════════════════════════════╗
║                                                                      ║
║   6 months ago: "I want to learn distributed systems"                ║
║                                                                      ║
║   Now: "I can show running systems, failure behavior,                ║
║         and verification evidence."                                  ║
║                                                                      ║
║   Your proof is not a certificate. It's a portfolio of               ║
║   systems that break on purpose and recover on command.              ║
║                                                                      ║
╚══════════════════════════════════════════════════════════════════════╝
```

**Next 90-day paths:**
- 🔴 **Hard mode:** Add Byzantine fault tolerance
- 🟡 **Research mode:** Formal verification with TLA+
- 🟢 **Ship mode:** Deploy to real infrastructure

---

> *Original backup: `Distributed_Trust_Engineer_24_Week_Roadmap_BACKUP.md`*
