# 24-Week C++ Roadmap: Distributed / Decentralized Trust Systems Engineer

> Friendly reading guide: use the quick links, follow one day at a time, and treat weekly checkpoints as your pass/fail gate before moving on.

## Quick Navigation
- [How to Use This Roadmap](#how-to-use-this-roadmap)
- [Why This Roadmap Works](#1-why-this-roadmap-works)
- [Skill Map](#2-skill-map-dependencies--what-unlocks-what)
- [6-Month Calendar](#3-6-month-calendar-month---week---day)
- [Month 1](#month-1)
- [Month 2](#month-2)
- [Month 3](#month-3)
- [Month 4](#month-4)
- [Month 5](#month-5)
- [Month 6](#month-6)
- [Weekly Checkpoints](#4-weekly-checkpoints-end-of-every-week)
- [Monthly Milestone Reviews](#5-monthly-milestone-reviews)

## How to Use This Roadmap
1. Start each day at `Learn`, then `Do`, then `Prove`, then finalize `Output`.
2. Do not skip the `Why` and `Self-check` sections; they are your retention and systems-thinking loop.
3. Treat Saturday as integration day and Sunday as rest + light review.
4. Do not move to the next week unless you pass the weekly quality gate.
5. Publish the monthly artifact so progress is visible and portfolio-ready.

## Brief Summary
- Target artifact to create: `week-3/Distributed_Trust_Engineer_24_Week_Roadmap.md`
- You will build one composed system over 24 weeks, not isolated mini-projects.
- Every day adds one explicit new constraint, one proof method, and one concrete output.
- Default schedule used: Mon-Fri `2h/day`, Sat `4h`, Sun rest + light review.
- Assumptions/defaults: Linux environment, C++17/20 toolchain, local multi-process testing on one machine first, then multi-node simulation, no framework lock-in beyond standard C++ + common system APIs.

## 1) Why This Roadmap Works
This roadmap works because it removes guesswork and keeps momentum visible.  
You only use one language (C++17/20), so effort goes into systems thinking, not language switching.

Each month has one purpose that is different from the previous month:
- Month 1 teaches how bytes move and how servers stay responsive.
- Month 2 teaches how to stay correct under load and trust message integrity.
- Month 3 teaches correctness under failures with durability and replication.
- Month 4 teaches cryptographic transparency and tamper evidence at system level.
- Month 5 composes everything into one civic-grade trust system.
- Month 6 turns technical skill into employable proof: reliability, security, demos, interviews.

Each week has one theme. Each day has one new constraint.  
That prevents the “every week feels the same” problem.

The plan is practical because concepts directly unlock features:
- Stream semantics unlock robust framing.
- Event loops unlock multi-client service.
- Hashes/signatures unlock tamper detection and identity.
- WAL unlocks crash recovery.
- Replication + election unlocks fault tolerance.
- Merkle + append-only log unlocks public verifiability.

Composition is built in:
- You reuse logger/CLI in networking.
- Reuse networking in signed protocol.
- Reuse signed protocol in KV + replication.
- Reuse KV + crypto in transparency log and CivicTrust.

Proof is mandatory:
- Daily proofs: tests, logs, latency numbers, or verification receipts.
- Weekly failure drills: break it on purpose.
- Monthly milestone artifacts: README + architecture diagram + demo evidence.

The result is not “I read about distributed trust.”  
The result is “I can show running systems, failure behavior, and verification evidence.”

## 2) Skill Map (Dependencies + What Unlocks What)

### Dependency Flow
1. C++ build/test hygiene ->  
2. TCP byte-stream mindset ->  
3. Event-loop multi-client servers ->  
4. Concurrency + backpressure ->  
5. Hashing/signing/replay defense ->  
6. Durable KV (WAL + recovery) ->  
7. Replication + election + idempotent clients ->  
8. Content-addressed storage + Merkle proofs ->  
9. Transparency log + consistency proofs + signed checkpoints ->  
10. CivicTrust capstone + reliability/security narrative.

### Interface Contracts You Keep Stable
- CLI contract: every tool supports predictable command format, exit codes, stderr errors.
- Protocol envelope contract: `version`, `msg_type`, `request_id`, `timestamp`, `nonce`, `payload_hash`, `signature`, `key_id`.
- WAL record contract: `lsn`, `term`, `op`, `key`, `value_hash`, `checksum`.
- Proof bundle contract: `document_hash`, `leaf_index`, `tree_size`, `inclusion_proof`, `checkpoint_signature`, optional `consistency_proof`.
- Observability contract: structured logs with `node_id`, `request_id`, `latency_ms`, `result`, `error_code`.

## 3) 6-Month Calendar (Month -> Week -> Day)

### Month 1
- Objective: Build networking foundations and event-driven server habits.
- Systems mindset learned: “TCP is a stream, not messages; responsiveness is state management.”

#### Week 1
- Theme: CLI tooling foundation -> file logger discipline.
- Why it matters: You need repeatable tools and evidence capture before networking complexity.
- New vs reinforcement: New is command contracts + deterministic behavior. Reinforcement is C++ basics with stronger constraints.

**Mon**
- Time budget: 2h
- Learn (30 min): CLI contract design and deterministic outputs. Notes: 1) input/output is an API 2) exit codes are behavior 3) stderr for errors.
- Do (80 min): Define `log append/read/search` behavior and argument rules. New constraint: strict exit-code table for all failures.
- Prove (20 min): Build a 12-case argument matrix (valid, missing args, malformed flags).
- Output (deliverable): `week-1/day1-cli-contract.md`
- Why (2-3 sentences): This day creates your behavior spec before implementation. It prevents hidden ambiguity later when tests fail. It unlocks automated CLI regression checks.
- Self-check (5 questions max): What is a command contract? Why are exit codes part of API? Which errors must go to stderr?

**Tue**
- Time budget: 2h
- Learn (30 min): File I/O reliability basics. Notes: 1) append semantics 2) fsync tradeoff 3) permission failures are common.
- Do (80 min): Plan logger write path and file naming scheme. New constraint: atomic append requirement for each log entry.
- Prove (20 min): Simulate permission-denied and missing-directory cases in test notes.
- Output (deliverable): `week-1/day2-logger-write-path.md`
- Why (2-3 sentences): You turn vague “write logs” into a reliability contract. This sets up evidence capture for all later servers. It unlocks reproducible debugging.
- Self-check (5 questions max): Why atomic append? What failures must logger handle first-class? When would fsync be required?

**Wed**
- Time budget: 2h
- Learn (30 min): Input validation strategy. Notes: 1) reject early 2) normalize paths 3) cap line length.
- Do (80 min): Define validation rules for message size, file path, and command shape. New constraint: max log record size to prevent memory abuse.
- Prove (20 min): Create boundary test list (0 bytes, max bytes, max+1).
- Output (deliverable): `week-1/day3-validation-boundaries.md`
- Why (2-3 sentences): Systems break at boundaries, not happy paths. This day installs safety limits before networking introduces untrusted input. It unlocks safer protocol handling later.
- Self-check (5 questions max): What boundary values matter? Why set max record size now? What should happen on max+1?

**Thu**
- Time budget: 2h
- Learn (30 min): Structured errors and observability. Notes: 1) error code taxonomy 2) machine-parsable logs 3) request correlation IDs.
- Do (80 min): Define error catalog for CLI/logger operations. New constraint: every failure path maps to one stable error code.
- Prove (20 min): Produce an error-to-scenario table with expected user-facing text.
- Output (deliverable): `week-1/day4-error-catalog.md`
- Why (2-3 sentences): This gives your system a stable language for failure. Later distributed debugging depends on predictable error semantics. It unlocks cleaner monitoring and incident triage.
- Self-check (5 questions max): Why stable error codes? What is correlation context? How is human text different from machine code?

**Fri**
- Time budget: 2h
- Learn (30 min): Test harness planning. Notes: 1) golden-file tests 2) negative tests 3) deterministic timestamps via injection plan.
- Do (80 min): Design CLI/logger test plan. New constraint: deterministic output even when time is involved.
- Prove (20 min): Define pass/fail criteria for 15 tests including malformed inputs.
- Output (deliverable): `week-1/day5-test-plan.md`
- Why (2-3 sentences): You now have explicit evidence criteria, not “it seems fine.” This converts learning into measurable progress. It unlocks confidence for network-layer integration next week.
- Self-check (5 questions max): What makes a test deterministic? What is a golden file? Why include negative tests first?

**Sat**
- Time budget: 4h
- Learn (40 min): Packaging for reuse. Notes: 1) module boundaries 2) reusable utility library 3) documentation-as-interface.
- Do (180 min): Consolidate week artifacts into one reusable CLI/logger package. New constraint: module split so networking project can import logger without rewrite.
- Prove (40 min): Run full week test matrix and collect baseline execution times.
- Output (deliverable): `week-1/README.md`, `week-1/day6-baseline-report.md`
- Why (2-3 sentences): This turns week work into a component, not throwaway practice. Reuse starts here and continues all 6 months. It unlocks instrumentation in your TCP servers.
- Self-check (5 questions max): What is reused next week? Why avoid copy-paste modules? What baseline numbers did you capture?

#### Week 2
- Theme: TCP echo server/client with stream-safe framing.
- Why it matters: You shift from local file correctness to network correctness.
- New vs reinforcement: New is socket lifecycle + partial I/O. Reinforcement is validation/error discipline from Week 1.

**Mon**
- Time budget: 2h
- Learn (30 min): TCP lifecycle and stream semantics. Notes: 1) connect/listen/accept split 2) stream != message 3) close handling.
- Do (80 min): Specify single-client echo protocol behavior. New constraint: handle port-in-use startup failure explicitly.
- Prove (20 min): Startup/shutdown scenario table including bind failures.
- Output (deliverable): `week-2/day1-tcp-lifecycle-spec.md`
- Why (2-3 sentences): This day defines server behavior before coding details spread. It anchors all future protocol constraints. It unlocks deterministic network tests.
- Self-check (5 questions max): Why is TCP a byte stream? What happens when port is busy? What is accept socket vs listen socket?

**Tue**
- Time budget: 2h
- Learn (30 min): Read/write loop correctness. Notes: 1) partial reads happen 2) partial writes happen 3) loops must continue until done.
- Do (80 min): Plan server and client loops for full-buffer send/recv behavior. New constraint: never assume one recv equals one message.
- Prove (20 min): Define test where payload is intentionally fragmented.
- Output (deliverable): `week-2/day2-partial-io-plan.md`
- Why (2-3 sentences): This is the first major systems reality check. Correct stream handling prevents subtle data corruption later. It unlocks robust framing and replay-safe protocols.
- Self-check (5 questions max): What is partial read? What is partial write? Why is one recv unsafe for message parsing?

**Wed**
- Time budget: 2h
- Learn (30 min): Protocol framing basics. Notes: 1) length-prefix framing 2) frame size limits 3) malformed frame rejection.
- Do (80 min): Define frame format and parser states. New constraint: reject oversize frame before allocation.
- Prove (20 min): Build parser test table: short header, truncated payload, oversize length.
- Output (deliverable): `week-2/day3-frame-parser-spec.md`
- Why (2-3 sentences): Framing turns raw bytes into safe messages. It is required for signatures and replay defense later. It unlocks multi-client event-loop reliability.
- Self-check (5 questions max): Why length-prefix over delimiter here? What is parser state machine? When should server close connection?

**Thu**
- Time budget: 2h
- Learn (30 min): Timeouts and dead peers. Notes: 1) read timeout 2) heartbeat optional 3) idle connection cleanup.
- Do (80 min): Define idle and read timeout policy for client/server. New constraint: connection closes after idle threshold with explicit reason.
- Prove (20 min): Design slow-client timeout scenario and expected log output.
- Output (deliverable): `week-2/day4-timeout-policy.md`
- Why (2-3 sentences): Timeouts protect resource usage and keep services responsive. This prevents dead connections from draining capacity. It unlocks backpressure policy in Month 2.
- Self-check (5 questions max): Why are timeouts mandatory in servers? What is idle vs read timeout? How should timeout appear in logs?

**Fri**
- Time budget: 2h
- Learn (30 min): Client observability and retries. Notes: 1) retry budget 2) backoff basics 3) distinguish transport vs protocol errors.
- Do (80 min): Define client retry behavior for connection failures. New constraint: bounded retries to prevent retry storms.
- Prove (20 min): Simulate server-down case and record retry timeline.
- Output (deliverable): `week-2/day5-client-retry-rules.md`
- Why (2-3 sentences): Client behavior is part of system correctness. Controlled retries reduce cascading failures. It unlocks idempotent client semantics in Month 3.
- Self-check (5 questions max): Why bound retries? What should never be retried? What signal ends retry loop?

**Sat**
- Time budget: 4h
- Learn (40 min): Reuse and integration discipline. Notes: 1) shared logger reuse 2) structured network logs 3) baseline throughput measures.
- Do (180 min): Integrate logger from Week 1 into TCP tools and run echo workload plan. New constraint: each request must carry a traceable request ID in logs.
- Prove (40 min): Capture latency and success-rate baseline from 3 payload sizes.
- Output (deliverable): `week-2/day6-echo-baseline-report.md`
- Why (2-3 sentences): This day proves composition, not restart-from-zero. Measured baselines make future optimizations meaningful. It unlocks multi-client event-loop comparison next week.
- Self-check (5 questions max): What was reused? What baseline numbers matter? Why attach request IDs now?

#### Week 3
- Theme: Multi-client event loop (`select`/`poll`) without threads.
- Why it matters: Concurrency starts with I/O multiplexing before thread complexity.
- New vs reinforcement: New is non-blocking state machines. Reinforcement is framing, timeouts, and logging.

**Mon**
- Time budget: 2h
- Learn (30 min): Non-blocking I/O semantics. Notes: 1) readiness != completion 2) `EAGAIN` is normal 3) per-connection state needed.
- Do (80 min): Define connection state model for event loop. New constraint: no blocking calls allowed in loop path.
- Prove (20 min): Checklist validating all loop operations are non-blocking-safe.
- Output (deliverable): `week-3/day1-event-loop-state-model.md`
- Why (2-3 sentences): Event loops fail when state is implicit. You make state explicit before scaling connections. It unlocks predictable multi-client behavior.
- Self-check (5 questions max): Why is `EAGAIN` expected? What state must each connection track? What call can accidentally block?

**Tue**
- Time budget: 2h
- Learn (30 min): `select` mechanics and limits. Notes: 1) fd sets mutate 2) max fd caveats 3) read/write readiness sets.
- Do (80 min): Plan first multi-client loop using `select`. New constraint: support at least 50 concurrent idle clients.
- Prove (20 min): Connection matrix test plan (connect/disconnect bursts).
- Output (deliverable): `week-3/day2-select-plan.md`
- Why (2-3 sentences): This is your first true multi-client architecture step. Even simple loads expose state bugs fast. It unlocks migration to better pollers.
- Self-check (5 questions max): What are `select` limits? Why track max fd? What events need separate handling?

**Wed**
- Time budget: 2h
- Learn (30 min): Backpressure at socket level. Notes: 1) write buffers can fill 2) slow clients hurt everyone 3) bounded queues protect process.
- Do (80 min): Define per-client outbound buffer policy. New constraint: cap queued bytes per client and disconnect on abuse.
- Prove (20 min): Slow-reader test scenario with expected disconnect threshold.
- Output (deliverable): `week-3/day3-backpressure-policy.md`
- Why (2-3 sentences): This day prevents one slow client from destabilizing the service. It introduces fairness as a correctness property. It unlocks formal backpressure controls in Month 2.
- Self-check (5 questions max): Why cap per-client queue? What is fairness in I/O servers? When is forced disconnect correct?

**Thu**
- Time budget: 2h
- Learn (30 min): `poll` advantages over `select`. Notes: 1) dynamic fd list 2) simpler scaling 3) cleaner event iteration.
- Do (80 min): Plan migration from `select` to `poll`. New constraint: preserve exact protocol behavior while changing poller.
- Prove (20 min): Regression checklist comparing outputs before/after migration.
- Output (deliverable): `week-3/day4-poll-migration-checklist.md`
- Why (2-3 sentences): You practice changing internals without changing behavior. This is key for long-lived systems. It unlocks future epoll upgrade with confidence.
- Self-check (5 questions max): What behavior must stay identical? Why swap poller now? How do you detect regression quickly?

**Fri**
- Time budget: 2h
- Learn (30 min): Connection churn handling. Notes: 1) half-close states 2) cleanup ordering 3) fd leak detection.
- Do (80 min): Define lifecycle for open/read/write/error/close paths. New constraint: zero descriptor leaks under churn.
- Prove (20 min): Run a churn script plan with leak counter target.
- Output (deliverable): `week-3/day5-connection-lifecycle-tests.md`
- Why (2-3 sentences): Resource leaks kill long-running services quietly. This day adds operational durability, not just correctness. It unlocks safe long soak tests.
- Self-check (5 questions max): What is half-close? How do fd leaks appear? What cleanup order is safest?

**Sat**
- Time budget: 4h
- Learn (40 min): Load-testing basics. Notes: 1) throughput vs latency 2) percentile thinking 3) bottleneck classification.
- Do (180 min): Plan and run multi-client soak test design. New constraint: maintain service correctness for 30 minutes under sustained load.
- Prove (40 min): Collect p50/p95 latency and error rate over time.
- Output (deliverable): `week-3/day6-soak-report.md`
- Why (2-3 sentences): This is first endurance check. It reveals memory and lifecycle faults hidden in short tests. It unlocks confidence before adding HTTP behavior.
- Self-check (5 questions max): Which latency percentile matters most here? What failure appeared first? What metric suggests memory/resource issues?

#### Week 4
- Theme: `epoll` and simple HTTP client.
- Why it matters: You connect socket mechanics to real protocol interactions.
- New vs reinforcement: New is epoll/timers + HTTP parsing. Reinforcement is framing/timeouts/error contracts.

**Mon**
- Time budget: 2h
- Learn (30 min): `epoll` model. Notes: 1) registration lifecycle 2) edge vs level triggers 3) wakeup efficiency.
- Do (80 min): Define epoll event strategy for your server. New constraint: choose trigger mode and justify starvation prevention.
- Prove (20 min): Event-handling invariants checklist for missed-read prevention.
- Output (deliverable): `week-4/day1-epoll-strategy.md`
- Why (2-3 sentences): Efficient event notification matters as concurrency grows. This day hardens your architecture decisions before coding complexity rises. It unlocks timer-driven cleanup.
- Self-check (5 questions max): Edge vs level tradeoff? How avoid missed events? What must happen after readiness?

**Tue**
- Time budget: 2h
- Learn (30 min): Timer integration with event loops. Notes: 1) idle timeout wheel/heap 2) timer drift awareness 3) cleanup scheduling.
- Do (80 min): Define idle timeout and periodic health checks. New constraint: stale connections removed without scanning all clients each tick.
- Prove (20 min): Timeout-accuracy measurement plan.
- Output (deliverable): `week-4/day2-timer-design.md`
- Why (2-3 sentences): Timers prevent silent resource hoarding. This day adds temporal correctness to your server. It unlocks robust slow-client control.
- Self-check (5 questions max): Why avoid full scans? What timer accuracy is acceptable? How log timeout reasons?

**Wed**
- Time budget: 2h
- Learn (30 min): HTTP/1.1 essentials for clients. Notes: 1) request line + headers 2) status code families 3) content-length parsing.
- Do (80 min): Specify simple HTTP client request/response parser behavior. New constraint: reject malformed headers with explicit error class.
- Prove (20 min): Build parser test list for normal and malformed responses.
- Output (deliverable): `week-4/day3-http-parser-spec.md`
- Why (2-3 sentences): HTTP gives practical protocol parsing experience beyond echo. This day strengthens input-safety habits. It unlocks health-check integrations for later services.
- Self-check (5 questions max): What is minimal valid HTTP response? How detect malformed headers? Why parse `Content-Length` carefully?

**Thu**
- Time budget: 2h
- Learn (30 min): DNS/connect timeout behavior. Notes: 1) connection phases 2) timeout per phase 3) distinguish transient vs permanent failures.
- Do (80 min): Define HTTP client timeout and retry policy. New constraint: separate connect timeout from read timeout.
- Prove (20 min): Failure matrix for unreachable host, slow server, partial response.
- Output (deliverable): `week-4/day4-http-timeout-matrix.md`
- Why (2-3 sentences): Separate timeout classes improve diagnosis and resilience. This mirrors real production client behavior. It unlocks robust node-to-node RPC later.
- Self-check (5 questions max): Why separate connect/read timeout? Which failures are retryable? How should retry budget be set?

**Fri**
- Time budget: 2h
- Learn (30 min): Integration testing with local endpoints. Notes: 1) deterministic fixtures 2) request IDs across client/server 3) reproducible logs.
- Do (80 min): Define tests where HTTP client queries your server health endpoint. New constraint: consistent correlation ID across both tools.
- Prove (20 min): End-to-end trace from request to server response log.
- Output (deliverable): `week-4/day5-e2e-trace.md`
- Why (2-3 sentences): End-to-end visibility is a systems superpower. This day links independent components through shared observability. It unlocks easier multi-node debugging next month.
- Self-check (5 questions max): What was traced end-to-end? Why correlation ID matters? Which logs were required to debug one request?

**Sat**
- Time budget: 4h
- Learn (40 min): Month synthesis and gap analysis. Notes: 1) architecture map 2) bottleneck list 3) reliability debt backlog.
- Do (180 min): Build Month 1 integrated demo plan (CLI + echo server + event loop + HTTP client). New constraint: demo must include one induced failure and recovery behavior.
- Prove (40 min): Capture baseline metrics and demo checklist completion.
- Output (deliverable): `month-1-demo/README.md`, `month-1-demo/diagram.png`, `week-4/day6-month1-report.md`
- Why (2-3 sentences): You close Month 1 with a coherent system, not fragments. Failure demonstration proves you understand behavior under stress. It unlocks concurrency and crypto work with a stable base.
- Self-check (5 questions max): Which component is weakest now? What failure did you induce? What metric baseline carries into Month 2?

---

### Month 2
- Objective: Add concurrency control and cryptographic trust primitives.
- Systems mindset learned: “Correctness under load needs both scheduling discipline and cryptographic guarantees.”

#### Week 5
- Theme: Thread pool and safe task execution.
- Why it matters: Event loop handles I/O; thread pool handles bounded CPU work.
- New vs reinforcement: New is thread synchronization and graceful shutdown. Reinforcement is queue limits and observability.

**Mon**
- Time budget: 2h
- Learn (30 min): C++ threads and shared-state risks. Notes: 1) data races are undefined behavior 2) mutex protects invariants 3) lock scope should be small.
- Do (80 min): Define concurrency model (event loop + worker pool responsibilities). New constraint: no shared mutable state without explicit ownership rule.
- Prove (20 min): Ownership map of each shared object.
- Output (deliverable): `week-5/day1-concurrency-model.md`
- Why (2-3 sentences): This prevents ad-hoc locking as complexity grows. Clear ownership is the core of safe concurrency. It unlocks predictable task processing.
- Self-check (5 questions max): What is data race? Which state is thread-confined? Which state is shared and why?

**Tue**
- Time budget: 2h
- Learn (30 min): Producer-consumer queues. Notes: 1) condition-variable signaling 2) spurious wakeups 3) bounded capacity.
- Do (80 min): Design bounded work queue for worker pool. New constraint: hard max queue depth with explicit rejection behavior.
- Prove (20 min): Overload scenario test plan at queue full condition.
- Output (deliverable): `week-5/day2-bounded-queue-spec.md`
- Why (2-3 sentences): Unbounded queues hide overload until memory collapses. This day makes overload visible and controllable. It unlocks backpressure strategy next week.
- Self-check (5 questions max): Why bounded queue? What happens when full? What is correct wake-up condition?

**Wed**
- Time budget: 2h
- Learn (30 min): Task scheduling fairness. Notes: 1) FIFO tradeoffs 2) starvation risk 3) task timeouts.
- Do (80 min): Define task dispatch rules for CPU-bound work. New constraint: max task execution budget with cancellation path.
- Prove (20 min): Test plan for one long task among many short tasks.
- Output (deliverable): `week-5/day3-scheduling-policy.md`
- Why (2-3 sentences): Fair scheduling keeps latency stable under mixed workloads. This avoids hidden starvation bugs. It unlocks predictable signing/hash workloads.
- Self-check (5 questions max): What causes starvation? Why task budget? What should cancellation guarantee?

**Thu**
- Time budget: 2h
- Learn (30 min): Contention measurement basics. Notes: 1) lock wait time 2) queue wait time 3) throughput-latency tradeoff.
- Do (80 min): Define instrumentation points around queue and locks. New constraint: capture p95 queue wait for every task type.
- Prove (20 min): Build metric collection checklist and expected ranges.
- Output (deliverable): `week-5/day4-contention-metrics.md`
- Why (2-3 sentences): Concurrency without measurement is guesswork. This day sets concrete performance evidence. It unlocks objective tuning.
- Self-check (5 questions max): Which metric reveals contention first? Why p95 over average? What threshold means overload?

**Fri**
- Time budget: 2h
- Learn (30 min): Graceful shutdown design. Notes: 1) stop intake first 2) drain queue 3) join workers safely.
- Do (80 min): Define shutdown sequence and deadlines. New constraint: zero task loss for accepted work during graceful shutdown.
- Prove (20 min): Shutdown test checklist with in-flight tasks.
- Output (deliverable): `week-5/day5-graceful-shutdown.md`
- Why (2-3 sentences): Clean shutdown is reliability, not polish. It protects correctness during deploys and crashes. It unlocks safer failure drills.
- Self-check (5 questions max): What is shutdown order? How avoid task loss? When force-terminate?

**Sat**
- Time budget: 4h
- Learn (40 min): Comparative benchmarking. Notes: 1) single-thread baseline 2) worker-pool scaling curve 3) diminishing returns.
- Do (180 min): Plan benchmark comparing event-loop-only vs event-loop+pool workloads. New constraint: publish scaling limit and likely bottleneck.
- Prove (40 min): Capture throughput and p95 latency for 1/2/4 worker counts.
- Output (deliverable): `week-5/day6-threadpool-benchmark.md`
- Why (2-3 sentences): You need proof that concurrency helps, not just complexity. This day quantifies tradeoffs. It unlocks informed backpressure tuning.
- Self-check (5 questions max): Where did scaling flatten? What bottleneck appeared? Which worker count is best and why?

#### Week 6
- Theme: Backpressure and overload handling.
- Why it matters: Survivability under load is core distributed-systems behavior.
- New vs reinforcement: New is overload policy and slow-client defense. Reinforcement is queue limits and timeouts.

**Mon**
- Time budget: 2h
- Learn (30 min): Backpressure patterns. Notes: 1) queue bounds 2) credit/token models 3) fail-fast responses.
- Do (80 min): Define server overload policy ladder. New constraint: explicit reject mode when queue depth crosses threshold.
- Prove (20 min): Threshold table with expected client-visible behavior.
- Output (deliverable): `week-6/day1-overload-policy.md`
- Why (2-3 sentences): Backpressure turns chaos into controlled degradation. This day makes overload behavior intentional. It unlocks stable service during spikes.
- Self-check (5 questions max): Why fail fast? What thresholds define overload? How should clients respond to rejection?

**Tue**
- Time budget: 2h
- Learn (30 min): Slow-client attack patterns. Notes: 1) slowloris behavior 2) read deadline defense 3) per-connection quotas.
- Do (80 min): Define slow-client defense strategy. New constraint: minimum progress rule for active connections.
- Prove (20 min): Simulated slow-sender test plan and expected disconnect timing.
- Output (deliverable): `week-6/day2-slow-client-defense.md`
- Why (2-3 sentences): One bad peer can starve resources without this control. This day adds fairness and abuse resistance. It unlocks robust public-facing protocols.
- Self-check (5 questions max): What is minimum progress rule? Why not allow infinite slow sends? What metric signals abuse?

**Wed**
- Time budget: 2h
- Learn (30 min): Write-side pressure control. Notes: 1) socket send buffer limits 2) app-level buffer caps 3) drop/close policy.
- Do (80 min): Define outbound throttling behavior. New constraint: per-client egress rate limit with burst cap.
- Prove (20 min): High-volume client test case verifying throttling kicks in.
- Output (deliverable): `week-6/day3-egress-throttle.md`
- Why (2-3 sentences): This protects server memory and fairness. It also prepares you for replication traffic shaping. It unlocks stable multi-node messaging.
- Self-check (5 questions max): Why rate-limit writes? What is burst cap? When close vs throttle?

**Thu**
- Time budget: 2h
- Learn (30 min): Tail latency management. Notes: 1) p99 pain point 2) deadline propagation 3) timeout budget split.
- Do (80 min): Define request deadline budget across stages. New constraint: drop request when deadline is exceeded at any stage.
- Prove (20 min): Deadline violation scenario with expected logs.
- Output (deliverable): `week-6/day4-deadline-budget.md`
- Why (2-3 sentences): Deadlines prevent zombie work and long-tail collapse. This day introduces explicit latency contracts. It unlocks reliable client retries.
- Self-check (5 questions max): Why p99 matters? How split deadlines? What should happen on expired deadline?

**Fri**
- Time budget: 2h
- Learn (30 min): Failure injection basics. Notes: 1) deliberate stress 2) controlled hypotheses 3) observable outcomes.
- Do (80 min): Plan overload + slow-client failure drill matrix. New constraint: every drill must map to one quality gate metric.
- Prove (20 min): Define expected fail-safe behavior for 5 stress scenarios.
- Output (deliverable): `week-6/day5-failure-injection-matrix.md`
- Why (2-3 sentences): You build muscle for “break it on purpose.” This is how trust systems avoid surprise collapses. It unlocks disciplined resilience testing in later months.
- Self-check (5 questions max): What is a good failure drill? Which metric defines pass? Why test fail-safe behavior early?

**Sat**
- Time budget: 4h
- Learn (40 min): Performance reporting for decisions. Notes: 1) compare before/after 2) explain bottlenecks 3) justify thresholds.
- Do (180 min): Run overload experiments and finalize backpressure thresholds. New constraint: maintain defined error-rate cap under target load.
- Prove (40 min): Publish throughput/latency/error chart for normal vs overload.
- Output (deliverable): `week-6/day6-backpressure-report.md`
- Why (2-3 sentences): This day turns policy ideas into measured operating limits. Quantified thresholds become future SLO inputs. It unlocks cryptographic feature addition without blind risk.
- Self-check (5 questions max): Which threshold is most sensitive? Did error-rate cap hold? What tradeoff did you accept?

#### Week 7
- Theme: Hashing and integrity proofs at message/file level.
- Why it matters: Tamper detection starts with digest correctness.
- New vs reinforcement: New is cryptographic integrity; reinforcement is streaming and framing constraints.

**Mon**
- Time budget: 2h
- Learn (30 min): Hash fundamentals. Notes: 1) preimage/collision concepts 2) integrity use 3) non-secret vs secret primitives.
- Do (80 min): Define hash-tool use cases (files, payloads, logs). New constraint: canonical byte representation before hashing.
- Prove (20 min): Cross-platform hash consistency test cases.
- Output (deliverable): `week-7/day1-hash-use-cases.md`
- Why (2-3 sentences): Hashing only helps if bytes are canonical. This day prevents false mismatches later in signatures. It unlocks stable message authentication workflows.
- Self-check (5 questions max): Why canonicalization first? What is collision risk in practice? Where should hash be stored?

**Tue**
- Time budget: 2h
- Learn (30 min): Streaming digest computation. Notes: 1) chunked updates 2) large-file memory safety 3) finalization semantics.
- Do (80 min): Define incremental hash workflow for large payloads. New constraint: no full-file load into memory.
- Prove (20 min): Large-input test plan with memory cap target.
- Output (deliverable): `week-7/day2-streaming-hash-plan.md`
- Why (2-3 sentences): Trust systems must handle large documents safely. This day ties integrity to scalability. It unlocks content-addressed storage later.
- Self-check (5 questions max): Why incremental hashing? What memory cap is acceptable? How verify same digest as one-shot hash?

**Wed**
- Time budget: 2h
- Learn (30 min): Integrity in protocols. Notes: 1) payload hash field 2) mismatch handling 3) logging forensic context.
- Do (80 min): Add hash field to protocol envelope spec. New constraint: reject and audit any hash mismatch.
- Prove (20 min): Tampered-payload scenario with expected reject reason.
- Output (deliverable): `week-7/day3-protocol-hash-envelope.md`
- Why (2-3 sentences): This upgrades protocol from transport-only to integrity-aware. It makes tampering visible and actionable. It unlocks signature verification chain.
- Self-check (5 questions max): What does payload hash protect? What does it not protect? How should mismatch be reported?

**Thu**
- Time budget: 2h
- Learn (30 min): Hash misuse pitfalls. Notes: 1) hashing mutable forms 2) ambiguous encodings 3) comparing wrong digest context.
- Do (80 min): Define canonicalization and encoding rules for all hash inputs. New constraint: single canonical serialization for signed/hashed data.
- Prove (20 min): Canonicalization regression cases (field order, whitespace, line endings).
- Output (deliverable): `week-7/day4-canonicalization-rules.md`
- Why (2-3 sentences): Most signature bugs are serialization bugs. This day prevents future cross-node verification failures. It unlocks reliable signing in Week 8.
- Self-check (5 questions max): What fields must be canonicalized? Why can whitespace break trust? How do you lock serialization format?

**Fri**
- Time budget: 2h
- Learn (30 min): Integrity audit workflows. Notes: 1) periodic scan 2) quarantine strategy 3) audit trail.
- Do (80 min): Define hash-audit process for stored artifacts. New constraint: audit must detect silent file corruption.
- Prove (20 min): Corrupt-one-byte drill and expected detection log.
- Output (deliverable): `week-7/day5-integrity-audit-drill.md`
- Why (2-3 sentences): Integrity must be continuously checked, not assumed. This day adds operational trust. It unlocks CAS and log audits in Month 4.
- Self-check (5 questions max): How often audit? What happens on mismatch? What evidence is preserved?

**Sat**
- Time budget: 4h
- Learn (40 min): Crypto feature integration strategy. Notes: 1) avoid redesign churn 2) preserve protocol compatibility 3) version fields.
- Do (180 min): Integrate hash tool and protocol digest fields into existing stack. New constraint: protocol versioning for backward compatibility.
- Prove (40 min): Run compatibility tests between old/new message formats.
- Output (deliverable): `week-7/day6-hash-integration-report.md`
- Why (2-3 sentences): This day practices safe evolution of interfaces. Compatibility habits are crucial in distributed systems. It unlocks signed protocol rollout.
- Self-check (5 questions max): Why version protocol now? What compatibility break did you avoid? Which old clients still work?

#### Week 8
- Theme: Key generation, signatures, and replay protection.
- Why it matters: Identity and anti-replay are core trust-system primitives.
- New vs reinforcement: New is key lifecycle and signature verification. Reinforcement is canonicalization and protocol envelopes.

**Mon**
- Time budget: 2h
- Learn (30 min): Key lifecycle basics. Notes: 1) generation 2) storage permissions 3) rotation and revocation.
- Do (80 min): Define key management policy for local dev system. New constraint: key files must have restricted permissions and versioned key IDs.
- Prove (20 min): Key-file permission and key-ID mapping checklist.
- Output (deliverable): `week-8/day1-key-policy.md`
- Why (2-3 sentences): Signatures are meaningless without key hygiene. This day makes identity handling explicit. It unlocks trustworthy signing workflows.
- Self-check (5 questions max): Why key IDs? What permission model is required? When rotate keys?

**Tue**
- Time budget: 2h
- Learn (30 min): Signature verification flow. Notes: 1) sign canonical bytes 2) verify before processing 3) fail closed.
- Do (80 min): Define sign/verify CLI behavior and errors. New constraint: reject any unsigned or unverifiable message by default.
- Prove (20 min): Invalid-signature test matrix (wrong key, altered payload, altered metadata).
- Output (deliverable): `week-8/day2-sign-verify-spec.md`
- Why (2-3 sentences): This is your first identity-bound protocol enforcement. It changes trust from “maybe honest” to verifiable. It unlocks signed transport between nodes.
- Self-check (5 questions max): What exactly is signed? Why verify before processing? What is fail-closed behavior?

**Wed**
- Time budget: 2h
- Learn (30 min): Replay attacks and nonce design. Notes: 1) old valid message replay 2) nonce uniqueness 3) timestamp window.
- Do (80 min): Define replay-defense policy with nonce cache + time window. New constraint: duplicate `(key_id, nonce)` is always rejected.
- Prove (20 min): Replay test where same signed packet is resent 3 times.
- Output (deliverable): `week-8/day3-replay-policy.md`
- Why (2-3 sentences): Integrity alone does not stop replay. This day adds temporal and uniqueness constraints to trust. It unlocks safe state-changing commands.
- Self-check (5 questions max): Why signatures do not stop replay? How long keep nonce cache? What to do with clock skew?

**Thu**
- Time budget: 2h
- Learn (30 min): Envelope versioning and compatibility. Notes: 1) signed header fields 2) extensibility 3) deprecating old versions safely.
- Do (80 min): Finalize signed protocol envelope schema. New constraint: include protocol version and mandatory signed metadata.
- Prove (20 min): Version compatibility scenarios and expected outcomes.
- Output (deliverable): `week-8/day4-signed-envelope-v1.md`
- Why (2-3 sentences): Stable envelope design avoids future rewrite pain. This day defines the contract your distributed core will rely on. It unlocks safe replication messaging.
- Self-check (5 questions max): Which headers must be signed? Why include version in signature? How handle unknown version?

**Fri**
- Time budget: 2h
- Learn (30 min): Verification performance and caching. Notes: 1) key cache 2) signature verify cost 3) rejection fast path.
- Do (80 min): Define verification pipeline optimization plan. New constraint: cap verification latency while preserving fail-closed semantics.
- Prove (20 min): Measure expected verification cost for small vs large payloads.
- Output (deliverable): `week-8/day5-verify-performance.md`
- Why (2-3 sentences): Security controls must remain operable under load. This day balances correctness and latency. It unlocks production-like throughput for Month 3.
- Self-check (5 questions max): Where is verify bottleneck? What can be cached safely? What must never bypass verification?

**Sat**
- Time budget: 4h
- Learn (40 min): End-to-end trust handshake flow. Notes: 1) issue nonce 2) sign request 3) verify + replay check.
- Do (180 min): Build integrated signed protocol demo plan (client-server). New constraint: full request path enforces signature + replay + timeout.
- Prove (40 min): Capture pass/fail evidence for valid, tampered, replayed, and expired requests.
- Output (deliverable): `month-2-demo/README.md`, `week-8/day6-signed-protocol-report.md`
- Why (2-3 sentences): Month 2 closes with explicit trust controls on top of networking. You now have measurable correctness under both load and tampering. It unlocks distributed durability next month.
- Self-check (5 questions max): Which attacks are now blocked? What still is not covered? Which log proves replay defense worked?

---

### Month 3
- Objective: Build distributed core with durability, replication, and failure-tolerant clients.
- Systems mindset learned: “Correctness means surviving crashes, retries, and partial failures.”

#### Week 9
- Theme: KV store core and state model.
- Why it matters: You need deterministic state transitions before persistence/replication.
- New vs reinforcement: New is state-machine design. Reinforcement is protocol contracts and request IDs.

**Mon**
- Time budget: 2h
- Learn (30 min): KV state machine basics. Notes: 1) commands mutate state 2) reads should be deterministic 3) invalid ops must be explicit.
- Do (80 min): Define KV command spec (`put/get/delete`) and response schema. New constraint: every mutating command requires unique request ID.
- Prove (20 min): Command validity matrix including missing keys and duplicate IDs.
- Output (deliverable): `week-9/day1-kv-command-spec.md`
- Why (2-3 sentences): Deterministic command semantics are foundation for replication. This day locks behavior before persistence complexity arrives. It unlocks idempotency later.
- Self-check (5 questions max): Why request IDs on writes? How should missing keys respond? What makes command deterministic?

**Tue**
- Time budget: 2h
- Learn (30 min): In-memory indexing and versioning. Notes: 1) version counters 2) optimistic conflict awareness 3) metadata separation.
- Do (80 min): Define key metadata model including version and last-update term. New constraint: version increments on every successful write.
- Prove (20 min): Concurrent-write scenario expectations table.
- Output (deliverable): `week-9/day2-versioning-rules.md`
- Why (2-3 sentences): Versioned state helps detect stale writes and debug replication issues. This day adds explicit temporal ordering metadata. It unlocks conflict handling.
- Self-check (5 questions max): Why track version? What is stale write? Which metadata will replication need?

**Wed**
- Time budget: 2h
- Learn (30 min): Serialization design. Notes: 1) stable field ordering 2) forward compatibility 3) checksums.
- Do (80 min): Define binary/text record format for snapshot and logs. New constraint: include checksum for each persisted record.
- Prove (20 min): Corrupted-record detection test plan.
- Output (deliverable): `week-9/day3-serialization-format.md`
- Why (2-3 sentences): Persistence fails silently without checksums and stable format. This day reduces data-corruption ambiguity. It unlocks WAL safety next week.
- Self-check (5 questions max): Why checksum each record? What breaks forward compatibility? How detect decode errors safely?

**Thu**
- Time budget: 2h
- Learn (30 min): Snapshot strategy. Notes: 1) point-in-time copy 2) atomic replace 3) metadata headers.
- Do (80 min): Define snapshot creation and load rules. New constraint: snapshot apply only if checksum and schema version pass.
- Prove (20 min): Snapshot corruption scenario and expected fallback behavior.
- Output (deliverable): `week-9/day4-snapshot-rules.md`
- Why (2-3 sentences): Snapshots bound recovery time and log growth. This day sets durable-state trust rules. It unlocks WAL truncation strategy.
- Self-check (5 questions max): Why need snapshots if WAL exists? When reject snapshot? What metadata is mandatory?

**Fri**
- Time budget: 2h
- Learn (30 min): Concurrency in state machines. Notes: 1) serialize writes 2) read consistency level 3) lock granularity.
- Do (80 min): Define concurrency policy for KV operations. New constraint: single-writer discipline to preserve ordering.
- Prove (20 min): Race test design with concurrent reads/writes.
- Output (deliverable): `week-9/day5-kv-concurrency-policy.md`
- Why (2-3 sentences): Deterministic order is more important than raw speed now. This day protects correctness under parallel client load. It unlocks safe log replay semantics.
- Self-check (5 questions max): Why single-writer now? What read consistency is acceptable? Where can parallelism remain?

**Sat**
- Time budget: 4h
- Learn (40 min): Component composition. Notes: 1) signed protocol -> KV command path 2) consistent error mapping 3) tracing across layers.
- Do (180 min): Compose signed request handling with KV command execution. New constraint: reject unsigned state-changing commands.
- Prove (40 min): End-to-end signed `put/get/delete` scenario evidence.
- Output (deliverable): `week-9/day6-kv-signed-integration.md`
- Why (2-3 sentences): You now join trust and state, not just trust and echo. This is the first “real” system slice. It unlocks durability with confidence.
- Self-check (5 questions max): Which commands require signature? How is request ID propagated? What evidence proves integration works?

#### Week 10
- Theme: WAL durability and crash recovery.
- Why it matters: Trust systems must survive process/node crashes without silent data loss.
- New vs reinforcement: New is write-ahead logging + recovery discipline. Reinforcement is checksums and deterministic command model.

**Mon**
- Time budget: 2h
- Learn (30 min): WAL principles. Notes: 1) append before apply 2) durable ordering 3) fsync policy tradeoff.
- Do (80 min): Define WAL record schema and append sequence. New constraint: state apply only after WAL append success.
- Prove (20 min): Sequence-of-events checklist for each command.
- Output (deliverable): `week-10/day1-wal-schema.md`
- Why (2-3 sentences): WAL enforces recoverability of committed intent. This day creates your durability contract. It unlocks crash-safe operation.
- Self-check (5 questions max): Why append-before-apply? What if append fails? Which fields must WAL include?

**Tue**
- Time budget: 2h
- Learn (30 min): Durability levels. Notes: 1) sync every write 2) batch sync 3) risk/performance tradeoff.
- Do (80 min): Define fsync policy by command class. New constraint: critical writes require immediate sync mode.
- Prove (20 min): Durability policy table with expected latency impact.
- Output (deliverable): `week-10/day2-fsync-policy.md`
- Why (2-3 sentences): Not all writes need same durability level. This day makes tradeoffs explicit and measurable. It unlocks SLO-aware durability later.
- Self-check (5 questions max): Which writes are critical? What risk does batch sync add? How to communicate durability mode to clients?

**Wed**
- Time budget: 2h
- Learn (30 min): Crash simulation method. Notes: 1) abrupt termination 2) partial write risks 3) restart verification steps.
- Do (80 min): Define crash-drill procedure around write operations. New constraint: must detect and ignore torn/corrupt WAL tail.
- Prove (20 min): Crash case matrix: before append, after append, after apply.
- Output (deliverable): `week-10/day3-crash-drill-procedure.md`
- Why (2-3 sentences): Recovery quality is only proven by deliberate crashes. This day adds real-world failure confidence. It unlocks replication safety assumptions.
- Self-check (5 questions max): What is torn write? How detect corrupt tail? Which crash point is hardest to recover correctly?

**Thu**
- Time budget: 2h
- Learn (30 min): Recovery replay design. Notes: 1) idempotent replay 2) checksum validation 3) replay cutoff rules.
- Do (80 min): Define startup replay algorithm and validation gates. New constraint: stop replay at first invalid record and quarantine remainder.
- Prove (20 min): Recovery scenario walkthrough with expected final state.
- Output (deliverable): `week-10/day4-recovery-algorithm.md`
- Why (2-3 sentences): Recovery is where hidden assumptions fail. This day formalizes safe startup behavior. It unlocks trustworthy restart under fault.
- Self-check (5 questions max): Why idempotent replay? When stop replay? What evidence shows recovery succeeded?

**Fri**
- Time budget: 2h
- Learn (30 min): Checkpoint and compaction concepts. Notes: 1) reduce replay time 2) consistent cut 3) WAL truncation safety.
- Do (80 min): Define checkpoint trigger policy and truncation rules. New constraint: truncate only after verified checkpoint durability.
- Prove (20 min): Checkpoint/truncate invariants checklist.
- Output (deliverable): `week-10/day5-checkpoint-compaction.md`
- Why (2-3 sentences): Without compaction, durability becomes operationally expensive. This day balances safety with maintainability. It unlocks longer-running replicated tests.
- Self-check (5 questions max): When checkpoint? What proves it is safe to truncate? What replay time target do you want?

**Sat**
- Time budget: 4h
- Learn (40 min): Durability benchmarking. Notes: 1) write latency distribution 2) recovery time objective 3) data-loss criteria.
- Do (180 min): Run crash/restart benchmark scenarios for WAL modes. New constraint: define and meet target RTO for restart.
- Prove (40 min): Publish durability vs latency table and recovery timings.
- Output (deliverable): `week-10/day6-durability-report.md`
- Why (2-3 sentences): This day translates durability design into measurable operational behavior. It gives you recovery confidence under stress. It unlocks safe replication layering.
- Self-check (5 questions max): What RTO did you meet? Which mode has best balance? Did any committed write get lost?

#### Week 11
- Theme: Replicated KV (2-3 nodes).
- Why it matters: Single-node durability is insufficient for availability and fault tolerance.
- New vs reinforcement: New is replication protocol and quorum logic. Reinforcement is WAL ordering and signed envelopes.

**Mon**
- Time budget: 2h
- Learn (30 min): Failure models. Notes: 1) crash-stop 2) message delay/loss 3) no Byzantine assumption yet.
- Do (80 min): Define replication assumptions and node roles. New constraint: explicit model excludes Byzantine peers for this phase.
- Prove (20 min): Assumption-to-risk table.
- Output (deliverable): `week-11/day1-failure-model.md`
- Why (2-3 sentences): Clear assumptions prevent design confusion. This day scopes correctness claims honestly. It unlocks focused replication implementation.
- Self-check (5 questions max): What failures are in scope? What failures are out of scope? Why is scope declaration important?

**Tue**
- Time budget: 2h
- Learn (30 min): Leader-to-follower log shipping. Notes: 1) append entries RPC 2) prev-index consistency check 3) ack semantics.
- Do (80 min): Define append RPC fields and follower validation. New constraint: follower rejects append with mismatched previous index/term.
- Prove (20 min): Divergence scenario table and expected follower response.
- Output (deliverable): `week-11/day2-append-rpc-spec.md`
- Why (2-3 sentences): Consistency checks prevent silent log divergence. This day gives replication structural safety. It unlocks quorum commit logic.
- Self-check (5 questions max): Why prev-index/term check? What does follower do on mismatch? Which fields must be signed?

**Wed**
- Time budget: 2h
- Learn (30 min): Quorum commit rules. Notes: 1) majority acknowledgment 2) commit index advancement 3) stale acknowledgments.
- Do (80 min): Define commit criteria for 3-node cluster. New constraint: leader applies entry only after majority acks.
- Prove (20 min): Commit decision examples for 1/2/3 follower acks.
- Output (deliverable): `week-11/day3-quorum-commit-rules.md`
- Why (2-3 sentences): Majority commit is the correctness core of replicated state. This day clarifies exactly when data is “committed.” It unlocks client consistency guarantees.
- Self-check (5 questions max): When is write committed? Why majority? Can leader apply before majority?

**Thu**
- Time budget: 2h
- Learn (30 min): Follower catch-up. Notes: 1) retry from lower index 2) conflict resolution 3) snapshot install fallback.
- Do (80 min): Define catch-up sequence for lagging follower. New constraint: bounded retry steps before snapshot fallback.
- Prove (20 min): Lagging-follower recovery scenario with expected time bounds.
- Output (deliverable): `week-11/day4-follower-catchup.md`
- Why (2-3 sentences): Lag is normal; recovery must be routine. This day prevents prolonged inconsistency after outages. It unlocks stable cluster operation under churn.
- Self-check (5 questions max): How does follower catch up? When snapshot fallback? What metric tracks replication lag?

**Fri**
- Time budget: 2h
- Learn (30 min): Partition behavior basics. Notes: 1) split-brain risk 2) minority isolation 3) recovery sequencing.
- Do (80 min): Define partition behavior policy. New constraint: minority side cannot accept committed writes.
- Prove (20 min): Partition scenario matrix and expected client errors.
- Output (deliverable): `week-11/day5-partition-policy.md`
- Why (2-3 sentences): Availability and consistency tradeoffs become concrete here. This day protects correctness during network splits. It unlocks leader election hardening next week.
- Self-check (5 questions max): Why block writes on minority side? What is split-brain? How should clients detect leader loss?

**Sat**
- Time budget: 4h
- Learn (40 min): Replication validation strategy. Notes: 1) linear history check 2) node-state comparison 3) faulted-run audits.
- Do (180 min): Run replicated KV validation plan across 2-3 nodes. New constraint: identical committed state after node restart and catch-up.
- Prove (40 min): Publish state-hash comparison across nodes after drills.
- Output (deliverable): `week-11/day6-replication-validation.md`
- Why (2-3 sentences): This day proves replication correctness beyond happy path. Cross-node state equality is concrete trust evidence. It unlocks client retry/idempotency integration.
- Self-check (5 questions max): Did states converge? Which drill caused divergence first? How was divergence resolved?

#### Week 12
- Theme: Leader election + client retry/idempotency.
- Why it matters: Correct client behavior and stable leadership are essential under failures.
- New vs reinforcement: New is term-based leader election and idempotent retries. Reinforcement is request IDs and quorum semantics.

**Mon**
- Time budget: 2h
- Learn (30 min): Election timeout design. Notes: 1) randomized timeout reduces split votes 2) heartbeat cadence 3) term monotonicity.
- Do (80 min): Define election timeout/heartbeat ranges. New constraint: randomized election timeout per node.
- Prove (20 min): Split-vote probability thought experiment with chosen ranges.
- Output (deliverable): `week-12/day1-election-timeouts.md`
- Why (2-3 sentences): Timeout tuning controls stability and failover speed. This day sets the foundation of leadership correctness. It unlocks robust vote flow.
- Self-check (5 questions max): Why randomize election timeout? What makes term monotonic? How often send heartbeats?

**Tue**
- Time budget: 2h
- Learn (30 min): Vote granting rules. Notes: 1) one vote per term 2) up-to-date log requirement 3) term update on newer term seen.
- Do (80 min): Define candidate/voter state transitions. New constraint: reject vote if candidate log is stale.
- Prove (20 min): Vote decision table for stale/fresh candidate logs.
- Output (deliverable): `week-12/day2-vote-rules.md`
- Why (2-3 sentences): Election without log freshness can lose committed data. This day protects safety during leadership change. It unlocks safe failover.
- Self-check (5 questions max): Why check log freshness? Can a stale leader be elected? When does node step down?

**Wed**
- Time budget: 2h
- Learn (30 min): Retry semantics under leader changes. Notes: 1) transient errors 2) retry with same request ID 3) redirect hints.
- Do (80 min): Define client retry policy for `not_leader` and timeout errors. New constraint: all retries reuse original request ID.
- Prove (20 min): Leader-failover write scenario proving no duplicate apply.
- Output (deliverable): `week-12/day3-client-retry-idempotency.md`
- Why (2-3 sentences): Retries are inevitable and dangerous without idempotency. This day makes retries safe under failover. It unlocks robust client UX.
- Self-check (5 questions max): Why same request ID on retry? Which errors are retryable? How avoid duplicate side effects?

**Thu**
- Time budget: 2h
- Learn (30 min): Idempotency table design. Notes: 1) store recent request IDs 2) response replay 3) expiration policy.
- Do (80 min): Define dedupe store rules and TTL. New constraint: duplicate request returns original success response, not re-execution.
- Prove (20 min): Duplicate-request test with delayed network ack scenario.
- Output (deliverable): `week-12/day4-dedupe-store-rules.md`
- Why (2-3 sentences): This closes the loop between retries and correctness. It prevents “at-least-once causes duplicate write” failures. It unlocks dependable client contracts.
- Self-check (5 questions max): What is dedupe key? Why replay same response? When can dedupe entries expire?

**Fri**
- Time budget: 2h
- Learn (30 min): Leader fencing and stale leader rejection. Notes: 1) term-based fencing 2) stale write rejection 3) role transition logging.
- Do (80 min): Define stale-leader handling path. New constraint: any request carrying old term is rejected.
- Prove (20 min): Simulated stale-leader write attempt with expected rejection evidence.
- Output (deliverable): `week-12/day5-stale-leader-fencing.md`
- Why (2-3 sentences): Split-brain risk is reduced by hard fencing rules. This day adds explicit anti-stale protection. It unlocks safer trust-layer integration.
- Self-check (5 questions max): What is fencing? How detect stale leader? Why must stale leader reject writes immediately?

**Sat**
- Time budget: 4h
- Learn (40 min): Month-level integration readiness. Notes: 1) map guarantees 2) map known gaps 3) prioritize fixes.
- Do (180 min): Build Month 3 integrated demo plan (durable replicated KV + retries). New constraint: include crash + failover + retry scenario in one scripted flow.
- Prove (40 min): Collect correctness evidence: no lost committed writes, no duplicate effects.
- Output (deliverable): `month-3-demo/README.md`, `week-12/day6-month3-report.md`
- Why (2-3 sentences): You now own a failure-tolerant distributed core, not just components. Scripted failure flow proves system-level reasoning. It unlocks trust architecture layering.
- Self-check (5 questions max): Which guarantee is strongest now? Which gap remains? What evidence proves retry safety?

---

### Month 4
- Objective: Build tamper-evident trust architecture (CAS + Merkle + transparency log + monitor).
- Systems mindset learned: “Trust is not hidden internals; it is publicly verifiable evidence.”

#### Week 13
- Theme: Content-addressed storage (CAS).
- Why it matters: Identity by content hash makes tampering and duplication visible.
- New vs reinforcement: New is hash-addressed object lifecycle. Reinforcement is canonical hashing and persistence safety.

**Mon**
- Time budget: 2h
- Learn (30 min): CAS principles. Notes: 1) address = hash 2) immutability by design 3) dedup by identity.
- Do (80 min): Define CAS object model and metadata fields. New constraint: object ID must be canonical-hash of normalized bytes.
- Prove (20 min): Same-content-same-ID test cases.
- Output (deliverable): `week-13/day1-cas-object-model.md`
- Why (2-3 sentences): CAS is foundational for transparent trust stores. This day shifts identity from mutable names to immutable content. It unlocks Merkle tree leaves.
- Self-check (5 questions max): Why content identity? What metadata is mutable? How detect duplicate object?

**Tue**
- Time budget: 2h
- Learn (30 min): Blob persistence strategy. Notes: 1) object path mapping 2) atomic write then rename 3) checksum at rest.
- Do (80 min): Define storage layout and write lifecycle for CAS blobs. New constraint: incomplete writes must never appear as valid objects.
- Prove (20 min): Interrupted-write scenario and expected cleanup behavior.
- Output (deliverable): `week-13/day2-cas-write-lifecycle.md`
- Why (2-3 sentences): Trust storage must resist partial-write corruption. This day extends durability discipline into CAS. It unlocks reliable proof generation.
- Self-check (5 questions max): Why atomic rename? How detect incomplete object? What checksum is stored?

**Wed**
- Time budget: 2h
- Learn (30 min): Chunking large documents. Notes: 1) fixed vs rolling chunks 2) manifest object 3) reassembly checks.
- Do (80 min): Define chunk manifest schema for large files. New constraint: manifest hash must commit to chunk order and sizes.
- Prove (20 min): Chunk reorder tamper scenario and expected detection.
- Output (deliverable): `week-13/day3-chunk-manifest-spec.md`
- Why (2-3 sentences): Large documents must remain verifiable and efficient. This day introduces compositional integrity. It unlocks scalable proof bundles.
- Self-check (5 questions max): Why hash manifest? What if chunk order changes? How reassemble safely?

**Thu**
- Time budget: 2h
- Learn (30 min): Garbage collection in immutable stores. Notes: 1) reachability roots 2) mark/sweep idea 3) safety window before delete.
- Do (80 min): Define CAS retention and GC policy. New constraint: deletion only for unreachable objects after retention delay.
- Prove (20 min): Reachability audit test plan.
- Output (deliverable): `week-13/day4-cas-gc-policy.md`
- Why (2-3 sentences): CAS can grow forever without lifecycle policy. This day adds operational sustainability without breaking verifiability. It unlocks production-like storage planning.
- Self-check (5 questions max): What is a root? Why retention delay? How avoid deleting referenced data?

**Fri**
- Time budget: 2h
- Learn (30 min): Integrity audit at store level. Notes: 1) recalc hash 2) compare object ID 3) quarantine corrupted objects.
- Do (80 min): Define periodic CAS audit routine. New constraint: audit must produce machine-parseable discrepancy report.
- Prove (20 min): Intentional one-byte corruption detection drill.
- Output (deliverable): `week-13/day5-cas-audit-drill.md`
- Why (2-3 sentences): Immutable design still needs verification in practice. This day adds continual trust evidence. It unlocks reliable Merkle leaves.
- Self-check (5 questions max): How often audit CAS? What happens on mismatch? Which report fields are mandatory?

**Sat**
- Time budget: 4h
- Learn (40 min): Integrating CAS with existing KV metadata. Notes: 1) pointer indirection 2) metadata consistency 3) object existence checks.
- Do (180 min): Define integration path where KV stores document references via CAS IDs. New constraint: state mutation rejected if referenced CAS object missing.
- Prove (40 min): End-to-end reference validation scenarios.
- Output (deliverable): `week-13/day6-cas-kv-integration.md`
- Why (2-3 sentences): This day composes storage trust with state trust. It keeps references verifiable and durable. It unlocks Merkle inclusion over stored objects.
- Self-check (5 questions max): Why store references not blobs in KV? How validate references? What failure mode is prevented?

#### Week 14
- Theme: Merkle trees and inclusion proofs.
- Why it matters: You need compact cryptographic evidence that data is included and untampered.
- New vs reinforcement: New is proof algorithms. Reinforcement is canonical hashing and CAS identities.

**Mon**
- Time budget: 2h
- Learn (30 min): Merkle tree fundamentals. Notes: 1) leaf hashes 2) parent = hash(left||right) 3) root commits to all leaves.
- Do (80 min): Define tree construction rules (ordering, odd leaf handling). New constraint: deterministic leaf ordering across nodes.
- Prove (20 min): Same-input-same-root test cases across reorder attempts.
- Output (deliverable): `week-14/day1-merkle-construction-rules.md`
- Why (2-3 sentences): Determinism is non-negotiable for shared proofs. This day sets the root correctness contract. It unlocks cross-node proof verification.
- Self-check (5 questions max): Why root is commitment? How handle odd leaves? Why ordering rule matters?

**Tue**
- Time budget: 2h
- Learn (30 min): Inclusion proof structure. Notes: 1) sibling path 2) leaf index role 3) root recomputation.
- Do (80 min): Define inclusion proof format fields. New constraint: proof must include leaf index and tree size.
- Prove (20 min): Proof validation examples for first, middle, last leaf.
- Output (deliverable): `week-14/day2-inclusion-proof-format.md`
- Why (2-3 sentences): Proof format is a public interface. This day ensures verifiers can reconstruct root unambiguously. It unlocks transparency receipts.
- Self-check (5 questions max): What data must proof include? Why include tree size? How verify inclusion step-by-step?

**Wed**
- Time budget: 2h
- Learn (30 min): Verifier robustness. Notes: 1) malformed path lengths 2) index out-of-range 3) hash mismatch behavior.
- Do (80 min): Define strict proof verifier rejection rules. New constraint: fail-closed on any malformed proof element.
- Prove (20 min): Malformed proof matrix with expected reject codes.
- Output (deliverable): `week-14/day3-proof-verifier-rules.md`
- Why (2-3 sentences): Attackers target verifiers, not just producers. This day hardens verification path against ambiguous input. It unlocks safer public verification tooling.
- Self-check (5 questions max): What is fail-closed here? Which malformed inputs are critical? How report proof errors clearly?

**Thu**
- Time budget: 2h
- Learn (30 min): Incremental Merkle updates. Notes: 1) append-only efficiency 2) cached subtree hashes 3) root update complexity.
- Do (80 min): Define append update strategy for growing tree. New constraint: append update must not recompute entire tree.
- Prove (20 min): Complexity comparison checklist (full rebuild vs incremental).
- Output (deliverable): `week-14/day4-incremental-merkle-plan.md`
- Why (2-3 sentences): Performance matters once logs grow. This day keeps proof generation scalable. It unlocks practical transparency log throughput.
- Self-check (5 questions max): Why incremental updates? Which nodes recompute on append? What complexity target is acceptable?

**Fri**
- Time budget: 2h
- Learn (30 min): Adversarial proof cases. Notes: 1) swapped siblings 2) wrong index 3) stale root.
- Do (80 min): Define adversarial test suite for proof verification. New constraint: stale root proofs must be explicitly marked unverifiable.
- Prove (20 min): Run red-team proof scenario checklist.
- Output (deliverable): `week-14/day5-adversarial-proof-tests.md`
- Why (2-3 sentences): Trust systems must expect malicious inputs. This day builds verifier confidence under attack. It unlocks transparency monitor correctness.
- Self-check (5 questions max): Why stale root matters? How catch sibling-order tampering? What evidence proves verifier is strict enough?

**Sat**
- Time budget: 4h
- Learn (40 min): Proof-size and latency tradeoffs. Notes: 1) log2(N) path growth 2) serialization overhead 3) batching possibilities.
- Do (180 min): Define and measure proof generation/verification performance goals. New constraint: publish maximum acceptable proof verification latency.
- Prove (40 min): Benchmark proof verification at multiple tree sizes.
- Output (deliverable): `week-14/day6-merkle-performance-report.md`
- Why (2-3 sentences): Measured proof cost is required for system planning. This day links crypto correctness with operability. It unlocks transparency API commitments.
- Self-check (5 questions max): How does proof size scale? Which tree size hits latency target edge? What optimization gives best gain?

#### Week 15
- Theme: Append-only transparency log with inclusion + consistency proofs and signed checkpoints.
- Why it matters: This is the core anti-equivocation trust service.
- New vs reinforcement: New is consistency proofs and checkpoint signing. Reinforcement is Merkle proofs and key management.

**Mon**
- Time budget: 2h
- Learn (30 min): Transparency log model. Notes: 1) append-only sequence 2) signed tree heads/checkpoints 3) external verification.
- Do (80 min): Define log append API and sequence-number semantics. New constraint: no deletion or in-place mutation of historical entries.
- Prove (20 min): Append-only invariant checklist.
- Output (deliverable): `week-15/day1-log-append-contract.md`
- Why (2-3 sentences): Append-only behavior is the trust anchor. This day creates non-rewrite guarantees for your log. It unlocks public auditability.
- Self-check (5 questions max): Why append-only? What invariant proves no rewrite? How should clients reference entries?

**Tue**
- Time budget: 2h
- Learn (30 min): Inclusion proof service patterns. Notes: 1) query by leaf hash/index 2) include tree size 3) signature binding.
- Do (80 min): Define inclusion-proof API response bundle. New constraint: every proof response references signed checkpoint hash.
- Prove (20 min): Response consistency tests between proof and checkpoint.
- Output (deliverable): `week-15/day2-inclusion-api-bundle.md`
- Why (2-3 sentences): Proofs without checkpoint binding are ambiguous. This day ties proofs to a signed trust state. It unlocks offline verification bundles.
- Self-check (5 questions max): Why bind proof to checkpoint? What fields are mandatory? How detect mismatched bundle parts?

**Wed**
- Time budget: 2h
- Learn (30 min): Consistency proofs. Notes: 1) prove tree growth without rewrite 2) old root to new root relationship 3) append-only guarantee.
- Do (80 min): Define consistency proof generation/verification rules. New constraint: any new checkpoint must be consistency-provable from previous checkpoint.
- Prove (20 min): Consistency validation scenarios across tree sizes.
- Output (deliverable): `week-15/day3-consistency-proof-rules.md`
- Why (2-3 sentences): Inclusion proves presence; consistency proves no history rewrite. This day closes a critical trust gap. It unlocks monitor-based equivocation detection.
- Self-check (5 questions max): What question does consistency proof answer? Why inclusion alone is insufficient? How verify growth correctness?

**Thu**
- Time budget: 2h
- Learn (30 min): Checkpoint signing policy. Notes: 1) signed tree size/root/time 2) key rotation 3) signature verification chain.
- Do (80 min): Define checkpoint schema and signature requirements. New constraint: checkpoint includes monotonic sequence and signing key ID.
- Prove (20 min): Checkpoint signature validation matrix with rotated keys.
- Output (deliverable): `week-15/day4-checkpoint-signature-schema.md`
- Why (2-3 sentences): Signed checkpoints are the externally verifiable trust anchor. This day formalizes what is attested and by whom. It unlocks monitor gossip workflows.
- Self-check (5 questions max): Which fields must be signed? Why include key ID? How verify checkpoint after key rotation?

**Fri**
- Time budget: 2h
- Learn (30 min): Client verifier responsibilities. Notes: 1) verify signature 2) verify inclusion/consistency 3) cache prior checkpoints.
- Do (80 min): Define verifier client workflow. New constraint: reject any proof lacking checkpoint continuity from cached state.
- Prove (20 min): Verifier behavior table for valid, missing, and inconsistent proofs.
- Output (deliverable): `week-15/day5-verifier-workflow.md`
- Why (2-3 sentences): Trust architecture fails if clients do not verify correctly. This day makes verifier behavior explicit and strict. It unlocks monitoring and alerting.
- Self-check (5 questions max): What does verifier cache? Why continuity check? What triggers hard failure?

**Sat**
- Time budget: 4h
- Learn (40 min): Auditor design patterns. Notes: 1) independent fetch 2) checkpoint comparison 3) divergence reporting.
- Do (180 min): Define independent auditor flow for log validation. New constraint: auditor must detect and report checkpoint inconsistencies.
- Prove (40 min): Simulated inconsistent checkpoint drill with expected alert output.
- Output (deliverable): `week-15/day6-auditor-design.md`
- Why (2-3 sentences): Independent auditing is essential for real trust claims. This day turns cryptographic theory into operational guardrails. It unlocks monitor network design.
- Self-check (5 questions max): What does auditor verify independently? How detect equivocation signs? What report proves an inconsistency?

#### Week 16
- Theme: Monitoring and anti-equivocation operations.
- Why it matters: Trust systems need continuous external observation, not one-time verification.
- New vs reinforcement: New is monitor gossip and incident response. Reinforcement is checkpoints/proofs/signature verification.

**Mon**
- Time budget: 2h
- Learn (30 min): Monitor architecture. Notes: 1) pull checkpoints periodically 2) track monotonic growth 3) persist observations.
- Do (80 min): Define monitor polling cadence and storage schema. New constraint: monitor stores immutable observation log.
- Prove (20 min): Observation record integrity checklist.
- Output (deliverable): `week-16/day1-monitor-architecture.md`
- Why (2-3 sentences): Monitors make trust continuous and evidence-backed. This day defines your external watchtower. It unlocks cross-monitor comparison.
- Self-check (5 questions max): What does monitor persist? Why immutable observation log? What growth anomalies matter?

**Tue**
- Time budget: 2h
- Learn (30 min): Gossip checkpoint exchange. Notes: 1) peer monitor sync 2) compare signed tree heads 3) conflict evidence packaging.
- Do (80 min): Define monitor gossip message schema. New constraint: each gossip exchange includes signed checkpoint and source metadata.
- Prove (20 min): Gossip consistency test cases between two monitors.
- Output (deliverable): `week-16/day2-monitor-gossip-schema.md`
- Why (2-3 sentences): Multiple monitors reduce single-observer blind spots. This day adds distributed scrutiny. It unlocks split-view detection.
- Self-check (5 questions max): Why gossip? What fields prove source authenticity? How compare checkpoints safely?

**Wed**
- Time budget: 2h
- Learn (30 min): Split-view/equivocation detection. Notes: 1) conflicting checkpoints same size 2) inconsistent growth path 3) evidence bundles.
- Do (80 min): Define equivocation detection rules and evidence format. New constraint: any conflict generates signed incident record.
- Prove (20 min): Simulate conflicting checkpoints and verify incident generation.
- Output (deliverable): `week-16/day3-equivocation-detection.md`
- Why (2-3 sentences): This day is central to decentralized trust claims. You operationalize detection of dishonest log behavior. It unlocks incident workflows.
- Self-check (5 questions max): What defines equivocation? What evidence must be preserved? Who can verify the incident record?

**Thu**
- Time budget: 2h
- Learn (30 min): Alerting policy design. Notes: 1) severity levels 2) paging thresholds 3) duplicate suppression.
- Do (80 min): Define monitor alert policy. New constraint: critical alerts require cryptographic evidence attachment.
- Prove (20 min): Alert scenario matrix for warning vs critical events.
- Output (deliverable): `week-16/day4-alert-policy.md`
- Why (2-3 sentences): Good alerts focus attention on verified risk. This day keeps operational noise manageable. It unlocks actionable incident response.
- Self-check (5 questions max): What separates warning from critical? Why attach evidence? How avoid alert storms?

**Fri**
- Time budget: 2h
- Learn (30 min): Incident response for trust failures. Notes: 1) containment 2) verification by independent parties 3) communication timeline.
- Do (80 min): Define runbook for checkpoint inconsistency incident. New constraint: runbook includes freeze-new-acceptance decision criteria.
- Prove (20 min): Tabletop incident drill with timestamps and actions.
- Output (deliverable): `week-16/day5-incident-runbook.md`
- Why (2-3 sentences): Detection without response is incomplete. This day builds operational maturity around trust events. It unlocks capstone failure-survival drills.
- Self-check (5 questions max): What is first action on critical trust alert? Who verifies evidence? When resume normal operations?

**Sat**
- Time budget: 4h
- Learn (40 min): Month-level trust integration. Notes: 1) CAS + Merkle + log + monitor flow 2) trust boundaries 3) unresolved risks.
- Do (180 min): Create Month 4 integrated trust architecture walkthrough. New constraint: include one simulated equivocation and monitor response.
- Prove (40 min): Provide evidence chain from conflict detection to incident record.
- Output (deliverable): `month-4-demo/README.md`, `week-16/day6-month4-report.md`
- Why (2-3 sentences): Month 4 ends with verifiable trust architecture, not isolated crypto parts. Incident simulation proves operational readiness. It unlocks CivicTrust composition.
- Self-check (5 questions max): Which trust guarantee is now strongest? What risk still remains? What evidence chain is complete?

---

### Month 5
- Objective: Build CivicTrust capstone from all prior components.
- Systems mindset learned: “Real systems combine identity, transparency, verification, and failure handling into one workflow.”

#### Week 17
- Theme: Issue signed civic documents.
- Why it matters: This creates business-level value on top of your trust infrastructure.
- New vs reinforcement: New is domain document lifecycle and policy. Reinforcement is signatures, replay, storage, and logging.

**Mon**
- Time budget: 2h
- Learn (30 min): Document schema and canonicalization. Notes: 1) stable field ordering 2) required metadata 3) schema versioning.
- Do (80 min): Define CivicTrust document schema. New constraint: schema includes issuer ID, issue time, expiration, and canonical hash.
- Prove (20 min): Schema validation cases for missing/extra fields.
- Output (deliverable): `week-17/day1-document-schema.md`
- Why (2-3 sentences): Domain schema is the product contract. This day grounds the capstone in precise data shape. It unlocks signing and verification flows.
- Self-check (5 questions max): Which fields are mandatory? Why version schema now? What breaks canonicalization?

**Tue**
- Time budget: 2h
- Learn (30 min): Issuer identity and key rotation policy. Notes: 1) issuer registry 2) active/inactive key states 3) overlap window for rotation.
- Do (80 min): Define issuer-key policy for CivicTrust. New constraint: verification must support prior active keys within overlap window.
- Prove (20 min): Key-rotation verification scenario table.
- Output (deliverable): `week-17/day2-issuer-key-policy.md`
- Why (2-3 sentences): Long-lived systems require key rotation without trust breakage. This day makes issuer trust lifecycle realistic. It unlocks resilient verification.
- Self-check (5 questions max): Why overlap window? How map issuer to key ID? What invalidates an issuer key?

**Wed**
- Time budget: 2h
- Learn (30 min): Issue workflow states. Notes: 1) draft->issued transition 2) immutable issued payload 3) issuance audit log.
- Do (80 min): Define issue command flow and audit fields. New constraint: issued document content is immutable after signature.
- Prove (20 min): Attempted post-issue edit scenario with expected rejection.
- Output (deliverable): `week-17/day3-issue-workflow.md`
- Why (2-3 sentences): Issuance must be auditable and immutable to preserve trust. This day cements lifecycle semantics. It unlocks anchoring and proof receipts.
- Self-check (5 questions max): Why immutable post-issue? What audit fields are mandatory? How identify issued version uniquely?

**Thu**
- Time budget: 2h
- Learn (30 min): Verification and revocation basics. Notes: 1) signature validity 2) expiration checks 3) revocation source.
- Do (80 min): Define verify command and revocation check path. New constraint: revoked issuer/doc fails verification even with valid signature.
- Prove (20 min): Revocation scenario tests.
- Output (deliverable): `week-17/day4-verify-revocation-rules.md`
- Why (2-3 sentences): Trust must include dynamic invalidation, not static signatures only. This day adds operational control. It unlocks safer public verification.
- Self-check (5 questions max): Why can valid signature still fail? How is revocation sourced? What is verification output contract?

**Fri**
- Time budget: 2h
- Learn (30 min): Policy enforcement model. Notes: 1) role-based issuer permissions 2) document-type constraints 3) expiration max limits.
- Do (80 min): Define issuance policy checks. New constraint: policy validation occurs before signing.
- Prove (20 min): Policy-violation test matrix.
- Output (deliverable): `week-17/day5-policy-gates.md`
- Why (2-3 sentences): Policy is where governance meets cryptography. This day ensures only authorized issuance occurs. It unlocks trustworthy capstone demonstrations.
- Self-check (5 questions max): Why policy-before-signing? What policy is hardest to enforce? How report policy failures clearly?

**Sat**
- Time budget: 4h
- Learn (40 min): Product-flow demonstration design. Notes: 1) issuer onboarding 2) issuance 3) verification UX.
- Do (180 min): Build CivicTrust issuance workflow demo plan. New constraint: full traceability from request ID to signed document hash.
- Prove (40 min): Demonstrate 3 document types with successful verify and one policy rejection.
- Output (deliverable): `week-17/day6-issuance-demo.md`
- Why (2-3 sentences): This turns infrastructure into visible product behavior. It proves end-user value of your trust stack. It unlocks transparency anchoring integration.
- Self-check (5 questions max): Can you show full issuance trace? Which rejection path is clearest? What remains manual today?

#### Week 18
- Theme: Transparency log anchoring for issued documents.
- Why it matters: Publicly verifiable inclusion prevents silent omission/tampering.
- New vs reinforcement: New is receipt bundling and freshness checks. Reinforcement is Merkle proofs and signed checkpoints.

**Mon**
- Time budget: 2h
- Learn (30 min): Anchoring pattern. Notes: 1) hash document 2) append hash to log 3) receive inclusion evidence.
- Do (80 min): Define anchoring workflow for each issued document. New constraint: issuance not “final” until anchoring receipt is obtained.
- Prove (20 min): State transition test (issued->anchored).
- Output (deliverable): `week-18/day1-anchoring-workflow.md`
- Why (2-3 sentences): Anchoring adds external accountability. This day upgrades issuance from private claim to public evidence. It unlocks offline trust bundles.
- Self-check (5 questions max): Why delay final state until anchor receipt? Which hash is anchored? What if anchoring fails?

**Tue**
- Time budget: 2h
- Learn (30 min): Receipt bundle composition. Notes: 1) inclusion proof 2) checkpoint signature 3) metadata binding to document hash.
- Do (80 min): Define receipt bundle schema. New constraint: bundle must be self-contained for offline verification.
- Prove (20 min): Bundle completeness checklist.
- Output (deliverable): `week-18/day2-receipt-bundle-schema.md`
- Why (2-3 sentences): A trust receipt must travel with the document. This day makes verification portable. It unlocks no-network validation.
- Self-check (5 questions max): What fields make bundle self-contained? Why include checkpoint signature? How bind bundle to one document?

**Wed**
- Time budget: 2h
- Learn (30 min): Inclusion verification workflow. Notes: 1) verify checkpoint signature 2) verify inclusion path 3) verify document-hash match.
- Do (80 min): Define strict verifier sequence for anchored docs. New constraint: any missing step yields `unverified` status, never soft-pass.
- Prove (20 min): End-to-end verification scenario table.
- Output (deliverable): `week-18/day3-anchor-verifier-sequence.md`
- Why (2-3 sentences): Verification order matters for security and debugging clarity. This day removes ambiguity in trust decisions. It unlocks automated verification tooling.
- Self-check (5 questions max): Why verify checkpoint first? What status on partial evidence? Which mismatch is most dangerous?

**Thu**
- Time budget: 2h
- Learn (30 min): Freshness and consistency checks. Notes: 1) stale checkpoint risk 2) consistency proof chain 3) freshness threshold.
- Do (80 min): Define freshness policy for accepted receipts. New constraint: reject receipts older than freshness window unless explicitly offline-exempt.
- Prove (20 min): Stale receipt scenarios and expected statuses.
- Output (deliverable): `week-18/day4-receipt-freshness-policy.md`
- Why (2-3 sentences): Old but valid proofs can still be risky operationally. This day adds temporal trust constraints. It unlocks safer monitoring SLAs.
- Self-check (5 questions max): Why freshness check? What is offline exemption? How detect checkpoint continuity gaps?

**Fri**
- Time budget: 2h
- Learn (30 min): Omission/tamper attack tests. Notes: 1) missing anchor 2) altered proof path 3) mismatched checkpoint.
- Do (80 min): Define adversarial tests for anchored docs. New constraint: system must distinguish `not_anchored`, `tampered`, `stale`.
- Prove (20 min): Attack matrix with expected error codes.
- Output (deliverable): `week-18/day5-anchoring-attack-matrix.md`
- Why (2-3 sentences): Distinct failure reasons improve trust and operations. This day hardens verification semantics. It unlocks strong demo credibility.
- Self-check (5 questions max): Why separate failure classes? Which tamper is easiest to detect? Which omission is hardest?

**Sat**
- Time budget: 4h
- Learn (40 min): End-to-end pipeline orchestration. Notes: 1) issue->sign->anchor->bundle 2) error rollback states 3) audit logging.
- Do (180 min): Define full CivicTrust pipeline with rollback handling. New constraint: failed anchoring triggers compensating status, not silent success.
- Prove (40 min): Run pipeline scenario set including forced anchoring failure.
- Output (deliverable): `week-18/day6-pipeline-integration.md`
- Why (2-3 sentences): This day unifies document lifecycle with transparency guarantees. It prevents false trust claims on partial success. It unlocks offline verification packaging.
- Self-check (5 questions max): Which rollback state is used on anchor failure? How is audit trail preserved? Can user see proof status clearly?

#### Week 19
- Theme: Offline verification package and UX.
- Why it matters: Verifiability without central server is a decentralization/trust requirement.
- New vs reinforcement: New is air-gapped verification UX. Reinforcement is proofs, signatures, and policy checks.

**Mon**
- Time budget: 2h
- Learn (30 min): Verifier UX design for trust decisions. Notes: 1) clear status categories 2) evidence summary 3) actionable failure output.
- Do (80 min): Define CLI output contract for verifier. New constraint: one-line machine status + human explanation block.
- Prove (20 min): Output clarity review with 6 verification outcomes.
- Output (deliverable): `week-19/day1-verifier-ux-contract.md`
- Why (2-3 sentences): Trust output must be understandable and machine-usable. This day improves operability and adoption. It unlocks real-world demo quality.
- Self-check (5 questions max): Which statuses are required? Why machine+human output split? What should never be ambiguous?

**Tue**
- Time budget: 2h
- Learn (30 min): Portable bundle packaging. Notes: 1) manifest + signatures 2) integrity checksum 3) size constraints.
- Do (80 min): Define offline package format containing doc + proofs + keys/checkpoint chain. New constraint: bundle must verify completeness before cryptographic checks.
- Prove (20 min): Bundle tamper/missing-file tests.
- Output (deliverable): `week-19/day2-offline-bundle-format.md`
- Why (2-3 sentences): Packaging errors can masquerade as trust failures. This day separates transport integrity from trust validation. It unlocks reliable air-gapped workflows.
- Self-check (5 questions max): What files are mandatory? Why verify completeness first? How detect bundle tampering quickly?

**Wed**
- Time budget: 2h
- Learn (30 min): Air-gapped verification flow. Notes: 1) no network assumptions 2) trusted key roots 3) local time handling.
- Do (80 min): Define strict offline verification sequence. New constraint: no remote calls allowed in offline mode.
- Prove (20 min): Dry-run checklist ensuring all data comes from bundle/local trust store.
- Output (deliverable): `week-19/day3-airgap-verification-flow.md`
- Why (2-3 sentences): Offline verification is core to decentralized trust claims. This day proves trust can be checked independently. It unlocks stronger CivicTrust narrative.
- Self-check (5 questions max): What trust roots are needed offline? How handle no network time source? Which checks remain fully local?

**Thu**
- Time budget: 2h
- Learn (30 min): Expiration and trust-window policy. Notes: 1) expired doc vs expired checkpoint 2) grace windows 3) explicit policy modes.
- Do (80 min): Define time-policy modes (`strict`, `grace`, `archival`). New constraint: verifier output must include policy mode used.
- Prove (20 min): Time-based verification scenario matrix.
- Output (deliverable): `week-19/day4-time-policy-modes.md`
- Why (2-3 sentences): Time semantics vary by use case; policy must be explicit. This day prevents hidden assumptions in trust decisions. It unlocks auditable governance behavior.
- Self-check (5 questions max): Why multiple policy modes? What is archival mode for? How avoid silent time-policy drift?

**Fri**
- Time budget: 2h
- Learn (30 min): Batch verification performance. Notes: 1) shared checkpoint reuse 2) parallel verification limits 3) failure aggregation.
- Do (80 min): Define batch verifier behavior for many documents. New constraint: per-document verdicts even if one bundle fails.
- Prove (20 min): Batch scenario with mixed valid/invalid bundles.
- Output (deliverable): `week-19/day5-batch-verifier-rules.md`
- Why (2-3 sentences): Real workflows verify many documents at once. This day scales trust checks while preserving per-item clarity. It unlocks operational adoption.
- Self-check (5 questions max): Why avoid all-or-nothing batch result? What can be shared across batch items? How report mixed outcomes?

**Sat**
- Time budget: 4h
- Learn (40 min): User documentation for trust tooling. Notes: 1) quickstart path 2) error cookbook 3) verification evidence examples.
- Do (180 min): Draft user-facing offline verification guide. New constraint: guide must include at least 5 common failure interpretations.
- Prove (40 min): Validate guide by running through each failure scenario and matching docs.
- Output (deliverable): `week-19/day6-offline-verifier-guide.md`
- Why (2-3 sentences): Good trust systems fail if users cannot operate them. This day turns technical capability into usable practice. It unlocks capstone hardening and demo readiness.
- Self-check (5 questions max): Can a new user verify offline unaided? Which error explanation is weakest? What scenario needs clearer docs?

#### Week 20
- Theme: Failure survival hardening.
- Why it matters: Capstone credibility depends on behavior under real failure drills.
- New vs reinforcement: New is cross-component chaos testing. Reinforcement is all prior reliability/security controls.

**Mon**
- Time budget: 2h
- Learn (30 min): Chaos testing principles. Notes: 1) hypothesis-driven faults 2) one variable at a time 3) measurable recovery.
- Do (80 min): Define capstone chaos test matrix. New constraint: each test specifies expected degraded mode and recovery trigger.
- Prove (20 min): Chaos matrix review against architecture components.
- Output (deliverable): `week-20/day1-chaos-matrix.md`
- Why (2-3 sentences): Hardening starts with explicit failure hypotheses. This day organizes testing into actionable experiments. It unlocks rigorous resilience claims.
- Self-check (5 questions max): What makes chaos test useful? What is degraded mode vs failure mode? Which component is highest risk?

**Tue**
- Time budget: 2h
- Learn (30 min): Crash fault handling in distributed services. Notes: 1) leader crash failover 2) follower crash catch-up 3) client retry impact.
- Do (80 min): Define node-crash drill steps and expected outcomes. New constraint: no duplicate document issuance after leader crash.
- Prove (20 min): Crash drill evidence checklist.
- Output (deliverable): `week-20/day2-node-crash-drill.md`
- Why (2-3 sentences): Crash handling is non-optional in distributed trust systems. This day validates failover integrity and idempotency together. It unlocks production-style confidence.
- Self-check (5 questions max): What must remain true after crash? How detect duplicate issuance risk? What metric confirms healthy failover?

**Wed**
- Time budget: 2h
- Learn (30 min): Partition testing. Notes: 1) minority behavior 2) healing sequence 3) stale state reconciliation.
- Do (80 min): Define partition scenarios for issuance and verification services. New constraint: minority partition cannot produce final anchored documents.
- Prove (20 min): Partition-heal scenario and state convergence check.
- Output (deliverable): `week-20/day3-partition-drill.md`
- Why (2-3 sentences): Partition behavior defines trust correctness boundaries. This day protects against split-brain style bad outcomes. It unlocks stronger operational runbooks.
- Self-check (5 questions max): Why block finalization on minority? How verify convergence after heal? What user-facing status appears during partition?

**Thu**
- Time budget: 2h
- Learn (30 min): Key compromise response. Notes: 1) revoke compromised key 2) rotate signer 3) communicate trust impact.
- Do (80 min): Define emergency key-compromise runbook. New constraint: compromised key cannot sign new checkpoints after cutoff time.
- Prove (20 min): Simulate compromised-key incident timeline.
- Output (deliverable): `week-20/day4-key-compromise-runbook.md`
- Why (2-3 sentences): Trust systems must survive key incidents clearly and quickly. This day operationalizes identity recovery. It unlocks credible security story for employers.
- Self-check (5 questions max): What is immediate first action on compromise? How is cutoff enforced? How inform verifiers?

**Fri**
- Time budget: 2h
- Learn (30 min): Backup/restore trust guarantees. Notes: 1) backup integrity checks 2) restore validation 3) replay from checkpoint.
- Do (80 min): Define backup and restore verification procedure. New constraint: restored system must prove continuity from last valid checkpoint.
- Prove (20 min): Restore drill checklist with continuity proof.
- Output (deliverable): `week-20/day5-restore-validation.md`
- Why (2-3 sentences): Backup without verifiable restore is false safety. This day adds disaster-recovery confidence. It unlocks production-readiness narrative.
- Self-check (5 questions max): What proves restore integrity? How verify checkpoint continuity? Which backup artifact is most critical?

**Sat**
- Time budget: 4h
- Learn (40 min): Hardening report writing. Notes: 1) summarize drills 2) map gaps to actions 3) quantify residual risk.
- Do (180 min): Produce capstone hardening report from all failure drills. New constraint: each unresolved risk has mitigation owner and timeline.
- Prove (40 min): Cross-check report claims against collected drill evidence.
- Output (deliverable): `month-5-demo/hardening-report.md`, `week-20/day6-month5-report.md`
- Why (2-3 sentences): This day converts testing into decision-quality engineering evidence. It makes strengths and weaknesses explicit. It unlocks final month employability packaging.
- Self-check (5 questions max): What is top residual risk? Which mitigation is highest priority? What evidence is strongest in your report?

---

### Month 6
- Objective: Package technical depth into employable proof (reliability, security, communication, interviews).
- Systems mindset learned: “Great engineering includes clear evidence, clear stories, and clear tradeoffs.”

#### Week 21
- Theme: Reliability/SLO story.
- Why it matters: Employers and teams need measurable service objectives, not vague claims.
- New vs reinforcement: New is SLO framing and capacity thinking. Reinforcement is metrics and failure evidence.

**Mon**
- Time budget: 2h
- Learn (30 min): SLI/SLO basics. Notes: 1) user-centric indicators 2) objective thresholds 3) measurement windows.
- Do (80 min): Define top CivicTrust SLIs and SLOs. New constraint: each SLO must map to one user-visible outcome.
- Prove (20 min): SLO table review for measurability and ownership.
- Output (deliverable): `week-21/day1-sli-slo-table.md`
- Why (2-3 sentences): SLOs convert engineering into service commitments. This day creates reliability language for your portfolio. It unlocks alert and capacity planning.
- Self-check (5 questions max): Which SLI best reflects user trust? What SLO target is realistic? What window is used?

**Tue**
- Time budget: 2h
- Learn (30 min): Metrics instrumentation strategy. Notes: 1) cardinality control 2) latency histograms 3) error code dimensions.
- Do (80 min): Define metric set and labels for key flows. New constraint: avoid high-cardinality labels that break observability.
- Prove (20 min): Metrics design review with cardinality estimate.
- Output (deliverable): `week-21/day2-metrics-design.md`
- Why (2-3 sentences): Metrics can fail operationally if designed poorly. This day keeps observability usable at scale. It unlocks dashboard clarity.
- Self-check (5 questions max): Why cardinality matters? Which labels are safe? Which metric catches trust failures fastest?

**Wed**
- Time budget: 2h
- Learn (30 min): Dashboard communication. Notes: 1) top-level health first 2) drill-down paths 3) annotate incidents.
- Do (80 min): Define reliability dashboard layout. New constraint: dashboard must show SLO status and recent error-budget burn.
- Prove (20 min): Walkthrough script validating dashboard answers common incident questions.
- Output (deliverable): `week-21/day3-dashboard-spec.md`
- Why (2-3 sentences): Dashboards are decision tools, not decoration. This day improves operational response speed. It unlocks alert tuning grounded in context.
- Self-check (5 questions max): Can dashboard answer “are users impacted now”? Where is root-cause drill-down? How show error budget burn?

**Thu**
- Time budget: 2h
- Learn (30 min): Alerting and error budgets. Notes: 1) symptom vs cause alerts 2) paging thresholds 3) budget-based prioritization.
- Do (80 min): Define alert rules tied to SLO error budgets. New constraint: paging only for user-impacting or trust-critical conditions.
- Prove (20 min): Alert simulation scenarios with expected severity.
- Output (deliverable): `week-21/day4-alert-rules.md`
- Why (2-3 sentences): Alerts should protect attention and reliability at once. This day aligns operations with business impact. It unlocks credible reliability discussion.
- Self-check (5 questions max): What pages immediately? What can wait? How does error budget affect roadmap decisions?

**Fri**
- Time budget: 2h
- Learn (30 min): Capacity planning basics. Notes: 1) traffic model 2) bottleneck resources 3) headroom policy.
- Do (80 min): Define load profile and capacity assumptions. New constraint: include 2x surge headroom target.
- Prove (20 min): Capacity worksheet with projected saturation points.
- Output (deliverable): `week-21/day5-capacity-plan.md`
- Why (2-3 sentences): Reliability claims need capacity context. This day makes scaling assumptions explicit. It unlocks realistic deployment planning.
- Self-check (5 questions max): Which resource saturates first? What headroom target is set? What data quality limits this estimate?

**Sat**
- Time budget: 4h
- Learn (40 min): Reliability narrative writing. Notes: 1) guarantees 2) failure behavior 3) measured outcomes.
- Do (180 min): Draft reliability chapter for capstone docs. New constraint: every guarantee statement references concrete evidence.
- Prove (40 min): Evidence traceability check from claim -> test/report artifact.
- Output (deliverable): `week-21/day6-reliability-story.md`
- Why (2-3 sentences): This turns raw tests into employer-readable proof. Reliability story is a key interview differentiator. It unlocks final security narrative integration.
- Self-check (5 questions max): Which claim lacks evidence? What failure mode is best covered? What reliability gap remains?

#### Week 22
- Theme: Security/threat-model story.
- Why it matters: Trust systems must explain what attacks are mitigated and what assumptions remain.
- New vs reinforcement: New is structured threat modeling. Reinforcement is replay/signature/proof/incident controls.

**Mon**
- Time budget: 2h
- Learn (30 min): STRIDE threat modeling. Notes: 1) spoofing/tampering/replay 2) trust boundaries 3) asset classification.
- Do (80 min): Build CivicTrust threat model map. New constraint: every component has explicit trust boundary and threat owner.
- Prove (20 min): Threat coverage table by component.
- Output (deliverable): `week-22/day1-threat-model-map.md`
- Why (2-3 sentences): Threat models organize security thinking and communication. This day moves from ad-hoc concerns to systematic coverage. It unlocks mitigation prioritization.
- Self-check (5 questions max): What are top assets? Where are trust boundaries? Which threat is highest impact?

**Tue**
- Time budget: 2h
- Learn (30 min): Abuse-case design. Notes: 1) attacker goals 2) preconditions 3) detection and response.
- Do (80 min): Define top 10 abuse scenarios. New constraint: each abuse case includes detection signal and response action.
- Prove (20 min): Review abuse list for coverage gaps.
- Output (deliverable): `week-22/day2-abuse-cases.md`
- Why (2-3 sentences): Abuse cases connect abstract threats to real behavior. This day improves practical security readiness. It unlocks meaningful security testing.
- Self-check (5 questions max): Which abuse case is hardest to detect? Which has weakest mitigation? What signal indicates early compromise?

**Wed**
- Time budget: 2h
- Learn (30 min): Mitigation mapping. Notes: 1) preventive vs detective controls 2) residual risk 3) compensating controls.
- Do (80 min): Map existing controls to threats and identify gaps. New constraint: every high-risk threat needs at least one preventive and one detective control.
- Prove (20 min): Gap list with priority and mitigation owner.
- Output (deliverable): `week-22/day3-threat-control-matrix.md`
- Why (2-3 sentences): Security maturity requires explicit control mapping. This day exposes weak spots before interviews or demos. It unlocks clear improvement plans.
- Self-check (5 questions max): Which high-risk threat lacks preventive control? Which lacks detection? What is residual risk language?

**Thu**
- Time budget: 2h
- Learn (30 min): Supply chain and secret management. Notes: 1) dependency trust 2) key storage hygiene 3) rotation practices.
- Do (80 min): Define secure dependency and secret-handling policy. New constraint: no hardcoded secrets and documented rotation cadence.
- Prove (20 min): Secret exposure and dependency-risk checklist.
- Output (deliverable): `week-22/day4-supplychain-secrets-policy.md`
- Why (2-3 sentences): Many breaches come from basics, not advanced crypto failures. This day strengthens real-world posture. It unlocks credible security discussion.
- Self-check (5 questions max): What secret controls are mandatory? How review dependencies? What rotation cadence is set?

**Fri**
- Time budget: 2h
- Learn (30 min): Security testing strategy. Notes: 1) negative test suites 2) replay/tamper drills 3) privilege misuse tests.
- Do (80 min): Define penetration-style test scenarios for capstone. New constraint: include one cross-component attack path test.
- Prove (20 min): Test-case-to-threat mapping verification.
- Output (deliverable): `week-22/day5-security-test-plan.md`
- Why (2-3 sentences): Security tests must mirror attacker paths. This day validates defense-in-depth across components. It unlocks strong final security report.
- Self-check (5 questions max): Which test exercises multiple layers? What attack path is most realistic? Which detection signal confirms success/failure?

**Sat**
- Time budget: 4h
- Learn (40 min): Security storytelling for interviews. Notes: 1) assumptions 2) mitigations 3) known limits.
- Do (180 min): Draft capstone security chapter and executive summary. New constraint: explicitly list “not solved yet” risks.
- Prove (40 min): Cross-check summary claims against threat/control matrix.
- Output (deliverable): `week-22/day6-security-story.md`
- Why (2-3 sentences): Honest scope and clear mitigations show engineering maturity. This day turns technical detail into leadership-ready communication. It unlocks final portfolio polish.
- Self-check (5 questions max): What is your clearest security claim? What unresolved risk is most important? How do you justify current tradeoffs?

#### Week 23
- Theme: Documentation, demos, and interview narratives.
- Why it matters: You need artifacts others can run, inspect, and trust.
- New vs reinforcement: New is communication packaging. Reinforcement is technical rigor and evidence traceability.

**Mon**
- Time budget: 2h
- Learn (30 min): Architecture communication patterns. Notes: 1) context/container/component diagrams 2) trust boundaries 3) data flow annotations.
- Do (80 min): Define final architecture diagram content. New constraint: every trust guarantee maps to one diagram element.
- Prove (20 min): Diagram review checklist for completeness and readability.
- Output (deliverable): `week-23/day1-architecture-diagram-plan.md`
- Why (2-3 sentences): Strong diagrams speed understanding and credibility. This day translates complexity into clear structure. It unlocks better demos and interviews.
- Self-check (5 questions max): Can someone trace one document end-to-end from diagram? Where are trust boundaries shown? Which guarantee is visually unclear?

**Tue**
- Time budget: 2h
- Learn (30 min): README as product interface. Notes: 1) quickstart path 2) verification steps 3) failure drill instructions.
- Do (80 min): Define final README outline. New constraint: quickstart must reach one successful issuance+verification in under 15 minutes.
- Prove (20 min): Dry-run quickstart timing test.
- Output (deliverable): `week-23/day2-readme-outline.md`
- Why (2-3 sentences): README quality often decides whether your work is explored seriously. This day optimizes first-run experience. It unlocks portfolio adoption.
- Self-check (5 questions max): Is quickstart short enough? What prerequisite confusion remains? Can users run a failure drill quickly?

**Wed**
- Time budget: 2h
- Learn (30 min): Demo scripting. Notes: 1) narrative arc 2) deterministic steps 3) fallback plans.
- Do (80 min): Define live demo script with timing and checkpoints. New constraint: include one planned failure + recovery segment.
- Prove (20 min): Script dry-run and timing validation.
- Output (deliverable): `week-23/day3-demo-script.md`
- Why (2-3 sentences): Great demos are engineered, not improvised. This day ensures your strongest capabilities are visible quickly. It unlocks confident presentation.
- Self-check (5 questions max): What is demo opening hook? Which failure drill is included? What is fallback if one step fails live?

**Thu**
- Time budget: 2h
- Learn (30 min): Technical video structure. Notes: 1) problem->architecture->demo->lessons 2) pacing 3) visual evidence.
- Do (80 min): Define demo video shot list and narration beats. New constraint: each claim shown with on-screen evidence.
- Prove (20 min): Storyboard-to-evidence consistency check.
- Output (deliverable): `week-23/day4-video-storyboard.md`
- Why (2-3 sentences): Video makes your work portable to recruiters and peers. This day creates scalable communication. It unlocks broader reach for your portfolio.
- Self-check (5 questions max): Which claims need visual proof? Is pacing under target length? What segment is least clear?

**Fri**
- Time budget: 2h
- Learn (30 min): Interview story framing (STAR). Notes: 1) challenge 2) tradeoff decision 3) measured result.
- Do (80 min): Draft 8 project stories (failure, debugging, security, scaling). New constraint: each story includes one metric and one tradeoff.
- Prove (20 min): Story quality rubric self-review.
- Output (deliverable): `week-23/day5-interview-story-bank.md`
- Why (2-3 sentences): Interviews evaluate thinking process, not just final code. This day prepares concise, evidence-backed narratives. It unlocks stronger interview performance.
- Self-check (5 questions max): Can you explain one hard tradeoff clearly? Which story has strongest evidence? Which story needs tighter structure?

**Sat**
- Time budget: 4h
- Learn (40 min): Portfolio packaging strategy. Notes: 1) artifact indexing 2) reproducibility 3) signal-to-noise control.
- Do (180 min): Build final portfolio index linking docs, diagrams, tests, demos. New constraint: every major claim links to one artifact.
- Prove (40 min): Third-party navigation test using only portfolio index.
- Output (deliverable): `week-23/day6-portfolio-index.md`
- Why (2-3 sentences): Packaging converts work into discoverable proof. This day makes your six-month effort easy to evaluate. It unlocks final showcase week.
- Self-check (5 questions max): Can a reviewer find proof in under 2 clicks? What artifact is missing? Which link chain is confusing?

#### Week 24
- Theme: Final interview prep and publication.
- Why it matters: You consolidate learning into repeatable communication and public proof.
- New vs reinforcement: New is mock interview iteration. Reinforcement is full-system understanding and evidence mapping.

**Mon**
- Time budget: 2h
- Learn (30 min): Distributed systems interview patterns. Notes: 1) consistency/availability tradeoffs 2) failure modes 3) recovery strategies.
- Do (80 min): Create Q&A set for replication/election/WAL topics. New constraint: each answer includes one concrete example from your project.
- Prove (20 min): Self-record 5 answers and score clarity.
- Output (deliverable): `week-24/day1-dist-sys-qa.md`
- Why (2-3 sentences): Knowledge must be recallable under pressure. This day strengthens fast explanation of core architecture decisions. It unlocks confident technical interviews.
- Self-check (5 questions max): Can you explain quorum commit clearly? Why WAL before apply? How does idempotency prevent duplicate effects?

**Tue**
- Time budget: 2h
- Learn (30 min): Applied crypto/trust interview themes. Notes: 1) signature workflows 2) replay prevention 3) transparency proofs.
- Do (80 min): Build Q&A set for trust architecture topics. New constraint: include one “limitation” answer for each major security claim.
- Prove (20 min): Practice 5 trust questions with concise 2-minute responses.
- Output (deliverable): `week-24/day2-trust-qa.md`
- Why (2-3 sentences): Strong candidates explain both strengths and limits. This day prepares honest, high-signal trust discussions. It unlocks credible senior-style communication.
- Self-check (5 questions max): How do you explain inclusion vs consistency proofs? What replay defense did you use? What limitation do you openly state?

**Wed**
- Time budget: 2h
- Learn (30 min): Debugging interview approach. Notes: 1) form hypothesis 2) isolate signal 3) validate fix with proof.
- Do (80 min): Create debugging drill set from real failures you hit. New constraint: each drill ends with measurable confirmation step.
- Prove (20 min): Run one timed debugging simulation.
- Output (deliverable): `week-24/day3-debug-drills.md`
- Why (2-3 sentences): Debugging stories often differentiate strong engineers. This day ties troubleshooting to disciplined evidence. It unlocks stronger practical interview performance.
- Self-check (5 questions max): What was your hardest bug? How did you isolate root cause? What evidence confirmed resolution?

**Thu**
- Time budget: 2h
- Learn (30 min): System design interview framing. Notes: 1) requirements first 2) constraints/tradeoffs 3) phased rollout.
- Do (80 min): Draft one system-design walkthrough of CivicTrust evolution. New constraint: explicitly separate MVP and hardening phases.
- Prove (20 min): Mock design session with checklist scoring.
- Output (deliverable): `week-24/day4-system-design-walkthrough.md`
- Why (2-3 sentences): Employers look for structured design thinking. This day demonstrates planning discipline and tradeoff awareness. It unlocks high-quality design interviews.
- Self-check (5 questions max): Did you state assumptions first? Which tradeoff did you choose and why? What phase handles highest risk?

**Fri**
- Time budget: 2h
- Learn (30 min): Final demo rehearsal strategy. Notes: 1) deterministic environment 2) preflight checks 3) failure fallback path.
- Do (80 min): Run full capstone rehearsal with timeboxing. New constraint: complete demo in target time with one intentional failure drill.
- Prove (20 min): Rehearsal scorecard (timing, clarity, evidence completeness).
- Output (deliverable): `week-24/day5-final-demo-scorecard.md`
- Why (2-3 sentences): Rehearsal converts capability into reliable presentation. This day ensures smooth final showcase. It unlocks confident publication.
- Self-check (5 questions max): Did demo stay within target time? Was failure drill clear? Which section needs tighter explanation?

**Sat**
- Time budget: 4h
- Learn (40 min): Retrospective and growth planning. Notes: 1) strengths 2) gaps 3) next-90-days plan.
- Do (180 min): Publish final portfolio package and write retrospective. New constraint: retrospective must include measurable before/after capability table.
- Prove (40 min): Verify all portfolio links, artifacts, and demo assets work.
- Output (deliverable): `month-6-final/README.md`, `month-6-final/retrospective.md`, `month-6-final/demo-script.md`
- Why (2-3 sentences): This day closes the loop with public, verifiable proof of skill. Reflection keeps improvement compounding after the roadmap. It unlocks your next specialization step.
- Self-check (5 questions max): What can you build now that you could not 6 months ago? Which gap is next priority? What artifact best proves your new capability?

---

## 4) Weekly Checkpoints (End of Every Week)

### Week 1 Checkpoint
- Demo checklist: CLI commands run with valid/invalid args; logger records structured entries; error catalog shown.
- Failure drill: permission denied on log path.
- Quality gate: pass if all command contract cases match expected exit codes.
- Reflection prompt: What ambiguity did contract remove? Which failure surprised you? What will you reuse next week?

### Week 2 Checkpoint
- Demo checklist: single-client echo works; framing handles fragmented input; timeout behavior visible in logs.
- Failure drill: client disconnect mid-frame.
- Quality gate: pass if no crash and clear error classification for all failure cases.
- Reflection prompt: Where did stream semantics differ from your intuition? Which parser state is riskiest? What baseline metric matters most?

### Week 3 Checkpoint
- Demo checklist: multi-client event loop serves 50+ clients; bounded per-client buffers; churn test summary.
- Failure drill: slow reader with growing outbound buffer.
- Quality gate: pass if no fd leaks and stable behavior under churn.
- Reflection prompt: What state bug was hardest? Which event path is most fragile? What metric indicates fairness?

### Week 4 Checkpoint
- Demo checklist: epoll strategy documented; HTTP client parses responses; end-to-end trace IDs correlate.
- Failure drill: malformed HTTP response header.
- Quality gate: pass if parser rejects malformed responses safely and logs reason.
- Reflection prompt: What changed from select/poll to epoll thinking? Which timeout is hardest to tune? What did month baseline show?

### Week 5 Checkpoint
- Demo checklist: bounded task queue spec; worker shutdown sequence; contention metrics defined.
- Failure drill: queue saturation.
- Quality gate: pass if overload path is deterministic and no task lost in graceful shutdown.
- Reflection prompt: What ownership rule prevented races? Where is contention highest? What worker count is best now?

### Week 6 Checkpoint
- Demo checklist: overload thresholds defined; slow-client defense rules; deadline budget policy.
- Failure drill: slowloris-like sender.
- Quality gate: pass if service degrades predictably without memory growth runaway.
- Reflection prompt: Which threshold is too strict/loose? What latency tail behavior changed? What rejection semantics need refinement?

### Week 7 Checkpoint
- Demo checklist: hash tool specs complete; protocol digest field defined; corruption detection drill done.
- Failure drill: one-byte payload tamper.
- Quality gate: pass if tampered payload always detected and rejected.
- Reflection prompt: Where can canonicalization fail? Which hash use case is most valuable? What compatibility concern appeared?

### Week 8 Checkpoint
- Demo checklist: key policy documented; signed envelope v1 defined; replay rules tested.
- Failure drill: replay previously valid signed request.
- Quality gate: pass if replayed request is rejected with explicit reason.
- Reflection prompt: Which key lifecycle step is weakest? How clear is verify failure output? What’s still missing for distributed use?

### Week 9 Checkpoint
- Demo checklist: KV command contract + versioning + snapshot rules complete; signed command path defined.
- Failure drill: duplicate request ID on mutating command.
- Quality gate: pass if duplicate request does not reapply mutation.
- Reflection prompt: Which state invariant is most critical? Where can determinism break? What metadata proved most useful?

### Week 10 Checkpoint
- Demo checklist: WAL schema and replay rules documented; crash drill matrix complete.
- Failure drill: crash immediately after WAL append.
- Quality gate: pass if committed write survives and corrupt tail is safely handled.
- Reflection prompt: Which crash point is hardest? How does fsync policy affect latency? What RTO did you achieve?

### Week 11 Checkpoint
- Demo checklist: append RPC, quorum rules, catch-up strategy, partition policy documented.
- Failure drill: follower lag then rejoin.
- Quality gate: pass if nodes converge to identical committed state hash.
- Reflection prompt: Where can divergence sneak in? Which partition behavior is surprising? What lag metric matters most?

### Week 12 Checkpoint
- Demo checklist: election and voting rules, retry/idempotency, stale-leader fencing documented.
- Failure drill: leader fails during client write.
- Quality gate: pass if no lost committed write and no duplicate effect.
- Reflection prompt: Which election parameter needs tuning? What retry rule is most important? What evidence convinced you?

### Week 13 Checkpoint
- Demo checklist: CAS object model, chunk manifest, GC policy, integrity audit routine.
- Failure drill: interrupted CAS write.
- Quality gate: pass if incomplete object never appears valid.
- Reflection prompt: What CAS invariant is hardest to enforce? How does GC risk trust? Which audit signal is strongest?

### Week 14 Checkpoint
- Demo checklist: deterministic Merkle rules; proof format; verifier rejection rules; performance targets.
- Failure drill: malformed inclusion proof.
- Quality gate: pass if verifier fails closed on all malformed inputs.
- Reflection prompt: Which proof error is easiest to miss? How does tree size impact latency? What optimization helped most?

### Week 15 Checkpoint
- Demo checklist: transparency append contract; inclusion+consistency bundles; signed checkpoint schema.
- Failure drill: inconsistent checkpoint continuity.
- Quality gate: pass if verifier rejects discontinuous checkpoint chain.
- Reflection prompt: Why inclusion is insufficient alone? Which checkpoint field is most critical? What audit gap remains?

### Week 16 Checkpoint
- Demo checklist: monitor architecture, gossip schema, equivocation detection, incident runbook.
- Failure drill: conflicting signed checkpoints at same tree size.
- Quality gate: pass if conflict triggers signed incident record and critical alert.
- Reflection prompt: Which alert would page immediately? What evidence quality is needed? How fast can incident triage start?

### Week 17 Checkpoint
- Demo checklist: document schema, issuer policy, issuance/verification/revocation flows.
- Failure drill: policy-violating issuance attempt.
- Quality gate: pass if policy violation blocks signing and logs reason.
- Reflection prompt: Which policy is hardest to explain? What schema field is most fragile? What user-facing message needs improvement?

### Week 18 Checkpoint
- Demo checklist: anchoring flow, receipt bundle schema, freshness policy, tamper matrix.
- Failure drill: issue succeeds but anchoring fails.
- Quality gate: pass if document remains non-final and status is explicit.
- Reflection prompt: Which anchoring dependency is weakest? How clear is receipt status? What rollback rule is best?

### Week 19 Checkpoint
- Demo checklist: offline bundle format, air-gapped verifier flow, time-policy modes, batch rules.
- Failure drill: bundle missing one proof artifact.
- Quality gate: pass if verifier returns deterministic `unverified` reason.
- Reflection prompt: Which offline assumption is risky? What output message is ambiguous? How to improve first-time UX?

### Week 20 Checkpoint
- Demo checklist: chaos matrix, crash/partition/key-compromise/restore drills, hardening report.
- Failure drill: combined partition + leader crash scenario.
- Quality gate: pass if no duplicate issuance and recovery path remains documented/executable.
- Reflection prompt: What residual risk is highest? Which drill produced most learning? What mitigation is next?

### Week 21 Checkpoint
- Demo checklist: SLI/SLO table, metrics design, dashboard spec, alert rules, capacity plan.
- Failure drill: synthetic SLO breach.
- Quality gate: pass if breach is detected, alerted, and explained via dashboard.
- Reflection prompt: Which SLO is unrealistic? Which metric is noisy? What capacity assumption is weakest?

### Week 22 Checkpoint
- Demo checklist: threat map, abuse cases, threat-control matrix, supply-chain policy, security test plan.
- Failure drill: replay + stale checkpoint attack path.
- Quality gate: pass if detection and response steps are documented and testable.
- Reflection prompt: Which threat remains under-mitigated? Which control is preventive vs detective? What assumption is most fragile?

### Week 23 Checkpoint
- Demo checklist: architecture diagram, README outline, demo script, video storyboard, story bank, portfolio index.
- Failure drill: teammate follows quickstart with one deliberate mistake.
- Quality gate: pass if user can recover via docs without direct help.
- Reflection prompt: Which document caused confusion? Which demo step is brittle? Which story lacks hard evidence?

### Week 24 Checkpoint
- Demo checklist: final Q&A sets, debugging drills, design walkthrough, demo scorecard, retrospective.
- Failure drill: live demo component outage simulation.
- Quality gate: pass if fallback path preserves core trust narrative in target time.
- Reflection prompt: What is your strongest demonstration now? What answer still feels weak? What is your next 90-day focus?

---

## 5) Monthly Milestone Reviews

### Month 1 Milestone Review
- What I can build now (specific): Event-loop TCP service with framing/timeouts, reusable CLI/logger tools, simple HTTP client for health checks.
- Biggest risks and how next month fixes them: Risk is uncontrolled load behavior and no cryptographic trust; Month 2 adds thread pool, backpressure, hashes, signatures, replay defense.
- Portfolio artifact to publish (README + diagram + demo): `month-1-demo/README.md`, networking architecture diagram, short run-through with baseline latency table.

### Month 2 Milestone Review
- What I can build now (specific): Signed, replay-protected network protocol with overload controls and measured concurrency behavior.
- Biggest risks and how next month fixes them: Risk is single-node state loss and no replication; Month 3 adds WAL recovery, quorum replication, election, idempotent retries.
- Portfolio artifact to publish (README + diagram + demo): `month-2-demo/README.md`, signed envelope + replay defense diagram, demo with tamper/replay rejection evidence.

### Month 3 Milestone Review
- What I can build now (specific): Durable replicated KV cluster that survives crashes/failovers and handles retries safely.
- Biggest risks and how next month fixes them: Risk is lack of external transparency evidence; Month 4 adds CAS, Merkle proofs, transparency log, and monitors.
- Portfolio artifact to publish (README + diagram + demo): `month-3-demo/README.md`, replication/election sequence diagram, failover drill demo with no duplicate writes.

### Month 4 Milestone Review
- What I can build now (specific): Tamper-evident transparency subsystem with inclusion/consistency proofs and signed checkpoints plus monitoring.
- Biggest risks and how next month fixes them: Risk is missing product workflow integration; Month 5 composes issuance, anchoring, offline verification, and failure survival.
- Portfolio artifact to publish (README + diagram + demo): `month-4-demo/README.md`, trust architecture diagram, equivocation detection demo.

### Month 5 Milestone Review
- What I can build now (specific): CivicTrust system issuing signed documents, anchoring to transparency log, verifying offline, and surviving key/system failures.
- Biggest risks and how next month fixes them: Risk is weak employability packaging and unclear reliability/security story; Month 6 creates SLO narrative, threat model, polished docs/demos/interview prep.
- Portfolio artifact to publish (README + diagram + demo): `month-5-demo/README.md`, CivicTrust end-to-end dataflow diagram, failure drill highlight reel.

### Month 6 Milestone Review
- What I can build now (specific): End-to-end distributed trust platform with verified failure behavior, documented guarantees, and interview-ready technical narratives.
- Biggest risks and how next month fixes them: Main risk after month 6 is stagnation; next 90 days should target one advanced path (Byzantine tolerance, formal verification, or production deployment).
- Portfolio artifact to publish (README + diagram + demo): `month-6-final/README.md`, final architecture + trust boundary diagram, polished demo video + interview Q&A pack.
