# 🏋️ Distributed Trust Engineer — GYM EDITION
## 24-Week Progressive Training System

> **You're not just learning. You're training.**
> Every session has warm-up, working sets, and cooldown.
> Every week tracks performance metrics. Every month tests max capacity.
> Ship proof. Track progress. Level up systematically.

```
╔══════════════════════════════════════════════════════════════════════════╗
║  🎮  YOUR CHARACTER:        Distributed Trust Engineer                   ║
║  🛠️  PRIMARY WEAPON:        C++17/20                                     ║
║  🐧  TRAINING GROUND:       Linux                                        ║
║  ⏱️  DAILY SESSIONS:        Mon-Fri: 2h · Sat: 4h · Sun: Active Rest    ║
║  📊  PERFORMANCE TRACKING:  Daily metrics · Weekly benchmarks · Monthly  ║
║  🎯  FAILURE BUDGET:        Expected 30% initial failure rate = growth   ║
╚══════════════════════════════════════════════════════════════════════════╝
```

---

## 📋 Table of Contents

- [🏋️ The Gym Philosophy](#-the-gym-philosophy)
- [📊 Your Training Log System](#-your-training-log-system)
- [🎯 Daily Training Protocol](#-daily-training-protocol)
- [📈 Progressive Overload Schedule](#-progressive-overload-schedule)
- [🗺️ 6-Month Training Arcs](#-6-month-training-arcs)
- [🏆 Performance Benchmarks](#-performance-benchmarks)
- [Arc 1-6: Detailed Training Programs](#arc-1--foundations-month-1)
- [📊 Appendix: Metrics & Templates](#-appendix-metrics--templates)

---

## 🏋️ The Gym Philosophy

### Why This Isn't Just Another Roadmap

```
TRADITIONAL LEARNING          vs          GYM TRAINING
─────────────────────────────────────────────────────────
"Read chapter 5"              →   "Warmup: Review Week 2 code (10min)"
"Build a server"              →   "Working set: 3 progressively harder servers"
"Make it work"                →   "Hit target: <100ms p99 latency with 50 clients"
"Move to next topic"          →   "Deload week: Refactor with fresh patterns"
No feedback                   →   "Daily metrics: 12 tracked KPIs"
Hope you remember             →   "Spaced repetition: Scheduled review every 3-7-21 days"
```

### The Core Training Principles

**1. PROGRESSIVE OVERLOAD**
- Week 1: Handle 10 clients, 1KB messages
- Week 3: Handle 50 clients, 10KB messages  
- Week 5: Handle 100 clients, variable sizes, with failure injection

**2. PERIODIZATION**
- Weeks 1-3: Accumulation (build new skills)
- Week 4: Intensification (stress test limits)
- Week 5: Realization (demonstrate mastery)
- Week 6: Deload (consolidate & document)

**3. MEASURABLE PROGRESS**
Every day you track:
- Time to first passing test
- Debug cycles needed
- Lines of code written vs. deleted
- Latency/throughput metrics
- Bugs caught before running

**4. FAILURE AS DATA**
- 30% initial failure rate is expected and healthy
- Every bug gets logged with: trigger, root cause, fix time
- Saturday "Boss Fights" are designed to expose weaknesses
- Monthly "Stress Tests" find your absolute limits

**5. ACTIVE RECOVERY**
- Sunday = Review mode (reading, diagramming, no new code)
- Every 4th week = Deload (50% volume, focus on quality)
- Built-in review cycles prevent knowledge decay

---

## 📊 Your Training Log System

### The Daily Training Log (10min/day to maintain)

Create a simple markdown file for each week: `training-logs/week-01.md`

```markdown
# Week 1 Training Log

## Day 1 (Mon) - CLI Contract Quest

### Pre-Session (Warmup)
- [ ] Review: Yesterday's key concepts (5min)
- [ ] Scan: Today's learning objectives (2min)
- [ ] Prime: Open previous week's code (if exists) (3min)

### Session Metrics
- Session start time: 19:00
- Session end time: 21:00
- Actual time coding: 85min
- Time debugging: 25min
- Time reading: 30min

### Performance Data
- Tests written: 12
- Tests passing first run: 7 (58%)
- Debug cycles: 3
- Compilation errors: 8
- Logic bugs found: 2
- LOC written: 156
- LOC deleted: 23

### Failure Log
1. **Bug**: Forgot to check argc before accessing argv[1]
   - Root cause: Skipped input validation step
   - Time to find: 8min
   - Fix: Added early bounds check
   - Lesson: Always validate contract boundaries first

2. **Bug**: Exit codes hardcoded instead of constants
   - Root cause: Rushed implementation
   - Time to find: 4min
   - Fix: Created EXIT_CODE enum
   - Lesson: Constants prevent magic numbers

### Learning Breakthroughs
- ✨ Realized exit codes are API contract, not just debugging
- ✨ Understanding: CLI is a protocol, same rules as network

### Energy & Focus
- Mental energy: 8/10 (fresh)
- Difficulty rating: 6/10 (moderate challenge)
- Flow state achieved: Yes, during test writing (30min)

### Tomorrow's Priming
- [ ] Review: File I/O error handling patterns
- [ ] Prep: Create test file structure
```

### The Weekly Benchmark (Saturday, 30min)

Every Saturday, run the **Weekly Benchmark Suite**:

```markdown
# Week 1 Benchmark Results

## Technical Metrics
- Total LOC this week: 847
- Test coverage: 78%
- Average compilation time: 3.2s
- P99 test execution time: 45ms

## Performance Targets
✅ CLI commands execute <10ms
✅ Logger handles 1000 entries/sec
⚠️ Error catalog missing 3 edge cases
❌ Permission denial test flaky

## Capability Assessment
NEW: Can build CLI with deterministic behavior
NEW: Can implement structured logging
IMPROVED: Error handling (30% → 75% coverage)
WEAK: File permission edge cases

## This Week's PR (Personal Records)
🏆 First time: All exit codes documented before coding
🏆 Fastest debug: 90 seconds (malformed flag issue)
🏆 Best test: Argument matrix caught 4 bugs before runtime

## Carry Forward to Next Week
- Reuse CLI framework for network tools
- Apply error classification to socket failures
- Use logging patterns for network events
```

### The Monthly Stress Test

End of each month: **MAX EFFORT CHALLENGE**

Push your system to absolute failure and measure limits:

```markdown
# Month 1 Stress Test - Max Capacity Assessment

## Load Test Results
- Max concurrent clients: 127 (crashed at 128)
- Max throughput: 8.3K req/sec
- Memory at saturation: 456MB
- First timeout at: 95 clients

## Failure Modes Discovered
1. FD exhaustion at 1024 limit
2. Memory leak in framing buffer
3. Epoll starvation under write pressure

## Recovery Procedures
✅ Graceful shutdown works
⚠️ Takes 3.2s to drain connections
❌ No automatic restart on crash

## Comparison to Last Month
- N/A (first month)

## Next Month Goals
- Target: 500 concurrent clients
- Target: 20K req/sec with backpressure
- Target: <5s graceful shutdown
```

---

## 🎯 Daily Training Protocol

### Standard 2-Hour Session Structure

```
┌─────────────────────────────────────────────────────────────┐
│                    DAILY TRAINING SESSION                    │
└─────────────────────────────────────────────────────────────┘

[00:00 - 00:10]  🔥 WARMUP (10min)
├─ Review yesterday's code (5min)
├─ Scan today's objectives (2min)
└─ Mental model activation (3min)
    └─ "What patterns from last week apply today?"

[00:10 - 00:40]  📖 LEARN (30min)
├─ Read targeted material (15min)
├─ Take concept notes (10min)
└─ Write self-check questions (5min)

[00:40 - 02:00]  🔨 WORK (80min)
├─ Set 1: Implement core path (25min)
│   └─ Timer buzzes → commit even if incomplete
├─ Quick break (5min)
├─ Set 2: Add error handling (25min)
│   └─ Timer buzzes → commit even if incomplete
├─ Quick break (5min)
├─ Set 3: Write tests (25min)
│   └─ Timer buzzes → commit even if complete

[02:00 - 02:10]  ✅ PROVE (10min)
├─ Run full test suite (3min)
├─ Log metrics to training log (4min)
└─ Update failure log if applicable (3min)

[02:10 - 02:15]  📦 SHIP (5min)
├─ Commit with descriptive message (2min)
├─ Create artifact/proof file (2min)
└─ Update progress tracker (1min)

[02:15 - 02:20]  🧠 COOLDOWN (5min)
├─ Answer self-check questions (3min)
└─ Prime tomorrow's focus (2min)
```

### Saturday Boss Fight Structure (4 hours)

```
[00:00 - 00:30]  📋 INTEGRATION PLANNING
└─ Map all week's components + integration points

[00:30 - 02:30]  🔨 BUILD INTEGRATED SYSTEM
├─ Hour 1: Wire components together
└─ Hour 2: End-to-end happy path

[02:30 - 03:30]  💥 FAILURE INJECTION
├─ Run the planned failure drill (30min)
└─ Debug & fix (30min)

[03:30 - 04:00]  📊 WEEKLY BENCHMARK
├─ Run benchmark suite (15min)
├─ Complete training log (10min)
└─ Publish weekly artifact (5min)
```

### Sunday Active Recovery (Optional 1 hour)

```
[No new code allowed]

Choose ONE:
A) 📖 Read ahead for next week (30min) + Diagram architecture (30min)
B) 🎨 Refactor one messy component (60min)
C) 📝 Write technical blog post about this week's learning (60min)
D) 🎥 Record short demo/explanation video (60min)
E) 🔄 Spaced repetition review (see schedule below)
```

---

## 📈 Progressive Overload Schedule

### How Difficulty Scales Over 24 Weeks

Each concept appears 3 times at increasing difficulty:

```
WEEK  CONCEPT                    DIFFICULTY LEVEL
────────────────────────────────────────────────────────
1     CLI basics                 Light (10 test cases)
2     Network framing            Light (simple protocol)
3     Multi-client               Medium (50 clients, no failures)
4     HTTP client                Medium (error handling required)
────────────────────────────────────────────────────────
6     Backpressure               Light (basic queue)
7     Hash/Sign                  Light (single algorithm)
8     Replay defense             Medium (nonce + timestamp)
────────────────────────────────────────────────────────
10    WAL recovery               Medium (3 failure scenarios)
11    Replication                Medium (2 nodes, network partition)
12    Leader election            Heavy (3+ nodes, failure cascade)
────────────────────────────────────────────────────────
```

### Volume Progression (Weekly Coding Hours)

```
Month 1: 10-12h/week   (building base capacity)
Month 2: 12-14h/week   (handling complexity)
Month 3: 14h/week      (peak volume)
Month 4: 12-14h/week   (maintain + new concepts)
Month 5: 14-16h/week   (integration intensity)
Month 6: 10-12h/week   (polish + presentation)
```

### Deload Weeks (Reduced Volume for Recovery)

- Week 5 (after Month 1)
- Week 9 (after Month 2)  
- Week 13 (after Month 3)
- Week 17 (after Month 4)
- Week 21 (after Month 5)

**Deload Protocol:**
- 50% code volume (focus on quality)
- No new concepts (consolidate existing)
- Refactoring & documentation focus
- Update mental models & diagrams

---

## 🗺️ 6-Month Training Arcs

```
╔════════════════════════════════════════════════════════════════════╗
║                         PERIODIZATION MAP                          ║
╚════════════════════════════════════════════════════════════════════╝

MONTH 1: FOUNDATIONS BLOCK
├─ Weeks 1-4: Accumulation (build networking base)
└─ Week 5: Deload (consolidate CLI/Logger/Networking)

MONTH 2: HARDENING BLOCK
├─ Weeks 6-8: Accumulation (concurrency + crypto)
└─ Week 9: Deload (consolidate trust primitives)

MONTH 3: DISTRIBUTED CORE BLOCK
├─ Weeks 10-12: Accumulation (durability + replication)
└─ Week 13: Deload (consolidate fault tolerance)

MONTH 4: TRUST ARCHITECTURE BLOCK
├─ Weeks 14-16: Accumulation (CAS + Merkle + Transparency)
└─ Week 17: Deload (consolidate cryptographic proofs)

MONTH 5: INTEGRATION BLOCK
├─ Weeks 18-20: Accumulation (CivicTrust system build)
└─ Week 21: Deload (consolidate end-to-end system)

MONTH 6: PERFORMANCE BLOCK
├─ Weeks 22-23: Polish (reliability + security narrative)
└─ Week 24: Peak (final demo + interviews)
```

### Monthly Training Focus

| Month | Primary Focus | Secondary Focus | Tertiary Focus |
|-------|--------------|-----------------|----------------|
| **1** | Networking foundations | Event loops | CLI discipline |
| **2** | Concurrency control | Cryptography | Protocol design |
| **3** | Durability & WAL | Replication | Consensus |
| **4** | Merkle trees | Transparency logs | Content addressing |
| **5** | System integration | Failure modes | Policy enforcement |
| **6** | Observability | Documentation | Interview prep |

---

## 🏆 Performance Benchmarks

### Weekly Performance Targets

Track these metrics every Saturday:

#### Month 1 Benchmarks

| Week | Metric | Target | Stretch Goal |
|------|--------|--------|--------------|
| 1 | CLI test coverage | 80% | 95% |
| 1 | Logger throughput | 1K entries/s | 5K entries/s |
| 2 | Frame parse time | <1ms avg | <500μs p99 |
| 2 | Connection setup | <5ms | <2ms |
| 3 | Concurrent clients | 50 | 100 |
| 3 | Memory per client | <100KB | <50KB |
| 4 | HTTP parse errors caught | 10/10 | + 5 edge cases |
| 4 | Request latency | <10ms p99 | <5ms p99 |

#### Month 2 Benchmarks

| Week | Metric | Target | Stretch Goal |
|------|--------|--------|--------------|
| 6 | Queue saturation time | 30s stable | 60s stable |
| 6 | Backpressure kicks in | At 80% | At 90% |
| 7 | Hash computation | 1M hashes/s | 5M hashes/s |
| 7 | Signature verify | 1K sigs/s | 5K sigs/s |
| 8 | Replay attack detection | 100% | + timing attacks |

#### Month 3 Benchmarks

| Week | Metric | Target | Stretch Goal |
|------|--------|--------|--------------|
| 10 | WAL write latency | <1ms p99 | <500μs p99 |
| 10 | Crash recovery time | <5s | <2s |
| 11 | Replication lag | <100ms p99 | <50ms p99 |
| 11 | Partition detection | <1s | <500ms |
| 12 | Election time | <3s | <1s |
| 12 | Zero data loss | 100% | + Byzantine |

### Personal Records (PR) to Track

Like tracking your max bench press, track these PRs:

```markdown
🏆 PERSONAL RECORDS

CODE QUALITY
├─ Fastest bug fix: _____ (minutes)
├─ Longest stretch without bug: _____ (hours)
├─ Highest test coverage: _____%
└─ Most edge cases in one test: _____

PERFORMANCE  
├─ Max concurrent clients: _____
├─ Best throughput: _____ req/s
├─ Lowest latency: _____ ms (p99)
└─ Smallest memory footprint: _____ KB/client

LEARNING VELOCITY
├─ Fastest concept → working code: _____ (minutes)
├─ Most LOC in one session: _____
├─ Best refactor ratio (deleted/added): _____
└─ Longest flow state: _____ (minutes)

SYSTEM COMPLEXITY
├─ Most components integrated: _____
├─ Most failure modes handled: _____
├─ Deepest call stack debugged: _____
└─ Largest codebase managed: _____ LOC
```

---

## 🔄 Spaced Repetition Schedule

### Active Recall System

Don't let early knowledge decay. Schedule review sessions:

```
AFTER LEARNING A CONCEPT:

Day 1:   Learn + Practice (primary session)
Day 3:   Review + Quick exercise (15min)
Day 7:   Review + Build variant (30min)
Day 21:  Review + Teach someone/write blog (45min)
Day 60:  Review + Apply to new context (30min)
```

### Weekly Review Rotation

Every week, spend 20 minutes reviewing old code:

```
Week 1: N/A (first week)
Week 2: Review Week 1 code
Week 3: Review Week 1 code (spaced rep)
Week 4: Review Week 2 code
Week 5: Review Week 3 code
Week 6: Review Week 1 code (long-term retention)
Week 7: Review Week 4 code
...
```

### Monthly "Teaching Test"

End of each month: Explain 3 concepts without looking at notes

```markdown
# Month 1 Teaching Test

Can I explain these WITHOUT notes? (Record yourself)

1. Why is TCP a byte stream, not a message protocol?
   - [ ] Explained clearly
   - [ ] Used diagram/example
   - [ ] Answered "why does this matter?"

2. How does epoll scale better than select?
   - [ ] Explained mechanism
   - [ ] Gave complexity comparison
   - [ ] Showed when it matters

3. What makes a good CLI contract?
   - [ ] Listed 3+ key properties
   - [ ] Gave counter-examples
   - [ ] Explained downstream impact
```

---

# 🌍 Arc 1 — Foundations (Month 1)

> **🎯 Training Goal:** Build event-driven networking muscle memory
>
> **💪 Strength Target:** Handle 50+ concurrent clients with deterministic behavior
>
> **🧠 Skill Unlock:** TCP stream thinking + Event loop patterns + Error contracts

```
Month 1 Progress & Performance Tracking
────────────────────────────────────────────────────
Week 1: [████░░░░░░] 40% │ Metrics: ✅ CLI ✅ Logger ⬜ Network
Week 2: [░░░░░░░░░░]  0% │ Metrics: ⬜ Frame ⬜ Timeout ⬜ Multi
Week 3: [░░░░░░░░░░]  0% │ Metrics: ⬜ Epoll ⬜ Load ⬜ Churn
Week 4: [░░░░░░░░░░]  0% │ Metrics: ⬜ HTTP ⬜ Parse ⬜ E2E
────────────────────────────────────────────────────
Current PR: Max clients: ___ │ Best latency: ___ │ LOC: ___
```

## 📊 Month 1 Training Metrics Dashboard

Track these weekly:

| Week | LOC Written | Test Coverage | Bugs Found | Debug Time | Flow Hours |
|------|-------------|---------------|------------|------------|------------|
| 1 | | | | | |
| 2 | | | | | |
| 3 | | | | | |
| 4 | | | | | |
| **Total** | | **Avg:** | **Total:** | **Total:** | **Total:** |

---

## 📗 Week 1 — CLI & Logger Discipline

> **🎯 Weekly Goal:** Build disciplined tooling habits before complexity
>
> **🏋️ Training Focus:** Command contracts + deterministic outputs + structured logging
>
> **📊 Key Metrics:** 12 test cases, 80% coverage, <10ms CLI execution
>
> **💪 Progression:** Light week (learning good habits)

### Week 1 Performance Targets

| Metric | Target | Your Result |
|--------|--------|-------------|
| CLI test coverage | 80% | ___ % |
| Logger throughput | 1K entries/s | ___ entries/s |
| Command execution time | <10ms | ___ ms |
| Error cases handled | 12 | ___ |
| Compilation warnings | 0 | ___ |

### 🗓️ Day 1 (Mon) — CLI Contract Definition

**Session Type:** Foundation Building (Light)

#### 🔥 Warmup (10min)
```markdown
- [ ] Review C++ command-line argument handling (argc/argv)
- [ ] Scan today's learning objectives
- [ ] Mental model: "CLI is a protocol with a spec"
```

#### 📖 Learn (30min)
**Topics:**
1. Command contract design principles
2. Exit codes as API surface
3. Stderr vs stdout conventions
4. Argument validation patterns

**Learning Questions:**
- What makes a CLI "testable"?
- Why separate data output from error messages?
- How do exit codes enable automation?

#### 🔨 Work (80min)

**Set 1 (25min):** Define command structure
- Spec out 3 commands: `append`, `read`, `search`
- Define argument syntax for each
- Create exit code table (0=success, 1=usage, 2=io, 3=invalid)

**Set 2 (25min):** Document failure modes
- List all possible error conditions
- Map each to appropriate exit code
- Write stderr message for each error

**Set 3 (25min):** Build argument matrix
- Create 12-case test matrix (3 commands × 4 scenarios)
- Scenarios: valid, missing arg, extra arg, malformed
- Expected behavior for each

#### ✅ Prove (10min)
- Argument matrix covers all commands: ☐
- Each error has distinct exit code: ☐
- Stdout/stderr separation documented: ☐

#### 📦 Ship
`week-1/day1-cli-contract.md`

#### 📊 Daily Metrics
```markdown
- Session duration: ___ min
- Documentation quality: ___/10
- Confidence in contract: ___/10
```

#### 💡 Why This Matters
CLI contracts prevent ambiguity hell later. When Week 12's replication test fails, you'll know if it's the protocol or the tool. This day builds "spec before code" muscle memory.

#### 🧠 Self-Check
- [ ] Can I explain why exit codes matter for shell scripts?
- [ ] Do I know when to use stderr vs stdout?
- [ ] Can I predict all failure modes before coding?

#### 🔄 Carry Forward
- This CLI framework will be reused for: network tools, log parsers, test harnesses
- Exit code discipline applies to: RPC status codes, HTTP responses
- Argument validation patterns apply to: protocol message validation

---

### 🗓️ Day 2 (Tue) — Logger Write Path

**Session Type:** Foundation Building (Light)

#### 🔥 Warmup (10min)
```markdown
- [ ] Review yesterday's CLI contract
- [ ] Refresh: POSIX file I/O basics (open, write, fsync)
- [ ] Mental model: "Logging is an append-only protocol"
```

#### 📖 Learn (30min)
**Topics:**
1. Append-only file semantics
2. fsync durability tradeoffs
3. File permission failure modes
4. Atomic write requirements

**Learning Questions:**
- What happens if fsync fails?
- How to detect partial writes?
- When is buffering safe vs. dangerous?

#### 🔨 Work (80min)

**Set 1 (25min):** Design write path flow
- Sketch data flow: caller → buffer → file → fsync
- Define error handling for each stage
- Choose file naming scheme (timestamp? sequence?)

**Set 2 (25min):** Implement basic appender
```cpp
// Pseudo-structure
class Logger {
  int append(const std::string& entry);
  // Returns: 0=success, -1=io_error, -2=permission
};
```

**Set 3 (25min):** Add error handling
- Permission denied on log path
- Disk full scenarios
- Partial write detection

#### ✅ Prove (10min)
- Can detect permission errors: ☐
- Handles disk full gracefully: ☐
- No partial writes on success: ☐

#### 📦 Ship
`week-1/day2-logger-impl.cpp` + `day2-error-handling.md`

#### 📊 Daily Metrics
```markdown
- LOC written: ___
- Compilation errors: ___
- Tests passing: ___/___
- Time debugging: ___ min
```

#### 💡 Breakthrough Insight
> "Append is atomic OR failed — never partial in my abstraction"

#### 🧠 Self-Check
- [ ] What's the difference between write() and fsync()?
- [ ] Why do I check permissions before attempting write?
- [ ] How do I test disk full without filling my disk?

---

### 🗓️ Day 3 (Wed) — Logger Read Path

**Session Type:** Foundation Building (Light)

#### 🔥 Warmup (10min)
```markdown
- [ ] Review yesterday's write path code
- [ ] Mental model: "Reading is parsing with failure modes"
```

#### 📖 Learn (30min)
**Topics:**
1. Line-based vs. record-based reading
2. Buffer sizing tradeoffs
3. Corrupt record handling
4. Pagination for large logs

#### 🔨 Work (80min)

**Set 1:** Implement basic reader
**Set 2:** Add filtering/search
**Set 3:** Handle corruption cases

#### 📦 Ship
`week-1/day3-logger-reader.cpp`

#### 🧠 Self-Check
- [ ] How do I detect a corrupted log entry?
- [ ] What's my memory footprint for a 1GB log?

---

### 🗓️ Day 4 (Thu) — Error Taxonomy

**Session Type:** Foundation Building (Medium)

#### 🔥 Warmup (10min)
```markdown
- [ ] Review all errors from Days 1-3
- [ ] Mental model: "Errors are data, not exceptions"
```

#### 📖 Learn (30min)
**Topics:**
1. Transient vs. permanent errors
2. Recoverable vs. fatal distinctions
3. Error propagation patterns
4. Client-facing vs. internal errors

#### 🔨 Work (80min)

**Set 1:** Create error classification
```markdown
ERROR TAXONOMY:

PERMANENT (don't retry):
- INVALID_ARGUMENT
- PERMISSION_DENIED
- NOT_FOUND

TRANSIENT (retry possible):
- RESOURCE_EXHAUSTED
- UNAVAILABLE
- TIMEOUT

FATAL (abort process):
- CORRUPTION_DETECTED
- INVARIANT_VIOLATED
```

**Set 2:** Map existing errors to taxonomy
**Set 3:** Write error handling guide

#### 📦 Ship
`week-1/day4-error-catalog.md`

#### 💡 Why This Matters
Week 8's replay defense will need error codes that clients can distinguish. Week 12's election needs transient vs. fatal distinction.

---

### 🗓️ Day 5 (Fri) — Testing & Integration

**Session Type:** Integration (Medium)

#### 🔥 Warmup (10min)
```markdown
- [ ] Review all week's components
- [ ] Mental model: "Tests are specifications that execute"
```

#### 📖 Learn (30min)
**Topics:**
1. Test structure: Arrange-Act-Assert
2. Fixture patterns for C++
3. Mocking file I/O
4. Property-based testing intro

#### 🔨 Work (80min)

**Set 1:** Write CLI integration tests
- Test all 12 argument cases
- Verify exit codes
- Check stdout/stderr separation

**Set 2:** Write logger tests
- Append → Read roundtrip
- Permission failure
- Concurrent appends (if multi-threaded)

**Set 3:** Write error handling tests
- Each error code reachable
- Error messages descriptive

#### 📦 Ship
`week-1/day5-test-suite/` + `test-report.md`

#### 📊 Daily Metrics
```markdown
- Total tests: ___
- Test coverage: ___%
- Tests passing: ___/___
- Bugs found by tests: ___
```

---

### 🗡️ Day 6 (Sat) — Week 1 Boss Fight

**Session Type:** Integration Challenge (4 hours)

#### 📋 Integration Planning (30min)
```markdown
Components to wire:
1. CLI parser
2. Logger (write + read)
3. Error handler
4. Test suite

Integration points:
- CLI → Logger calls
- Error codes → Exit codes
- Logs → CLI output
```

#### 🔨 Build Integrated System (2h)

**Hour 1:** Wire components
- Create main.cpp that uses all pieces
- Implement `log append <msg>`
- Implement `log read`
- Implement `log search <term>`

**Hour 2:** End-to-end testing
- Full workflow: append → read → verify
- Test all error paths
- Verify deterministic behavior

#### 💥 Failure Injection (1h)

**Planned Failure:** Permission denied on log path

Run these drills:
1. Remove write permission on log directory
2. Run `log append "test"`
3. **Expected:** Exit code 2, stderr message, no crash

**Debug if failed:**
- Is error detected at right layer?
- Is exit code correct?
- Is error message helpful?

#### 📊 Weekly Benchmark (30min)

Run and record:

```markdown
# Week 1 Benchmark Results

## Performance Metrics
- CLI execution time: ___ ms (target: <10ms)
- Logger throughput: ___ entries/s (target: 1K/s)
- Test coverage: ___% (target: 80%)

## Capability Assessment
✅ Can build CLI with clean contract
✅ Can implement structured logging
✅ Can classify errors systematically
⚠️ Performance: [note any misses]

## Personal Records
🏆 New PR: [list any achievements]
🏆 Best moment: [what went really well]
🐛 Hardest bug: [what was trickiest]

## Bugs & Lessons
1. Bug: ___
   Lesson: ___
2. Bug: ___
   Lesson: ___

## Carry Forward
- CLI framework pattern applies to: network tools, parsers
- Error taxonomy applies to: all future error handling
- Test discipline applies to: everything

## Week 2 Priming
- [ ] Read: TCP basics (stevens or beej)
- [ ] Understand: byte stream vs. messages
- [ ] Prep: socket programming environment
```

#### 📦 Ship
`week-1/boss-fight/` (all integrated code)
`week-1/benchmark-results.md`
`week-1/weekly-retrospective.md`

#### 🎯 Gate Check

**DO NOT advance to Week 2 unless:**
- [ ] All 12 CLI test cases pass
- [ ] Exit codes match contract
- [ ] Permission failure drill works
- [ ] No crashes on any input
- [ ] Error messages are clear

---

### 🏖️ Day 7 (Sun) — Active Recovery

**Choose ONE (1 hour max, no new code):**

**Option A: Read Ahead**
- Read about TCP sockets (30min)
- Diagram client-server interaction (30min)

**Option B: Refactor**
- Clean up Week 1 code (60min)
- Focus on readability, not features

**Option C: Content Creation**
- Write blog: "What I learned building a CLI framework" (60min)
- Or record 5min video explaining error taxonomy

**Option D: Spaced Repetition**
- Review: C++ basics from before Week 1 started
- Quick coding exercise: build tiny grep clone (30min)

---

## 📗 Week 2 — TCP Basics & Framing

> **🎯 Weekly Goal:** Build byte-stream thinking and message framing
>
> **🏋️ Training Focus:** Socket programming + Protocol framing + Timeout handling
>
> **📊 Key Metrics:** <1ms frame parse, zero crashes on disconnect
>
> **💪 Progression:** Light → Medium (building complexity)

### Week 2 Performance Targets

| Metric | Target | Your Result |
|--------|--------|-------------|
| Frame parse time | <1ms | ___ ms |
| Connection setup time | <5ms | ___ ms |
| Zero crashes on disconnect | 100% | Pass/Fail: ___ |
| Timeout detection | <1s | ___ s |
| Protocol errors caught | 10/10 | ___ /10 |

### Daily Quest Structure

| Day | Quest | Difficulty | Warmup Focus |
|-----|-------|------------|--------------|
| Mon | TCP echo server | Light | Review: CLI + logging from Week 1 |
| Tue | Length-prefix framing | Light→Med | Review: Yesterday's socket code |
| Wed | Connection timeout | Medium | Review: Error taxonomy |
| Thu | Multi-client support | Medium | Review: Event loop patterns |
| Fri | Integration tests | Medium | Review: All week's components |
| Sat 🗡️ | **BOSS: Disconnect drill** | Hard | Plan failure injection |

**Week 2 Detailed Daily Plans:**
[Similar structure to Week 1, I'll provide the pattern for Mon-Tue, then summarize rest]

---

### 🗓️ Day 8 (Mon) — TCP Echo Server

#### 🔥 Warmup (10min)
```markdown
- [ ] Review: Last week's logger code (how you handled errors)
- [ ] Today's pattern: "Socket is just a file descriptor"
- [ ] Prime: Open socket man pages (socket, bind, listen, accept)
```

#### 📖 Learn (30min)
- TCP vs UDP fundamentals
- Socket lifecycle: socket → bind → listen → accept
- Blocking vs non-blocking I/O
- How read/write work on sockets

#### 🔨 Work (80min)

**Set 1:** Create basic echo server
```cpp
// Goal: Accept one connection, echo bytes back
// No error handling yet, just the happy path
```

**Set 2:** Add error handling
- Connection refused
- Peer disconnect
- Read/write failures

**Set 3:** Test with netcat
- Start server
- `nc localhost 8080`
- Send data, verify echo
- Test disconnect scenarios

#### 📦 Ship
`week-2/day1-tcp-echo.cpp` + `day1-notes.md`

#### 📊 Metrics
- Time to first successful echo: ___ min
- Number of segfaults during dev: ___
- Clean disconnect handling: Pass/Fail

#### 🧠 Self-Check
- [ ] Why is TCP a byte stream, not a message protocol?
- [ ] What happens when client disconnects while I'm reading?
- [ ] How do I know when read() is "done"?

---

### 🗓️ Day 9 (Tue) — Length-Prefix Framing

#### 🔥 Warmup (10min)
```markdown
- [ ] Review: Yesterday's echo server
- [ ] Challenge question: "How do I know where one message ends?"
- [ ] Mental model: "I must frame the stream"
```

#### 📖 Learn (30min)
- Why TCP doesn't preserve message boundaries
- Framing schemes: length-prefix, delimiter, fixed-size
- Partial read handling
- Reassembly buffers

#### 🔨 Work (80min)

**Set 1:** Implement frame parser
```
Frame format: [4-byte length][payload]
- Length in network byte order (big-endian)
- Max payload size: 64KB
```

**Set 2:** Handle partial frames
- Read might give partial length header
- Read might give partial payload
- Maintain reassembly buffer

**Set 3:** Write frame tests
- Single frame
- Multiple frames in one read
- Frame split across multiple reads

#### 📦 Ship
`week-2/day2-framing.cpp` + `day2-frame-tests.cpp`

#### 💡 Breakthrough Moment
> "TCP is a pipe. I control the structure."

---

[Days 10-12 follow similar structure]

---

### 🗡️ Day 13 (Sat) — Week 2 Boss Fight

**Challenge:** Client disconnect mid-frame

**Setup:**
1. Server expects 1KB frame
2. Client sends 4-byte length header
3. Client sends 512 bytes of payload
4. **Client forcibly disconnects**

**Requirements:**
- Server must NOT crash
- Server must clean up connection
- Server must log disconnect reason
- Server must be ready for next client

**Success Criteria:**
- [ ] No segfault
- [ ] Error logged with context
- [ ] FD closed properly
- [ ] Next connection works fine

---

## 📗 Week 3 — Event Loops & Multi-Client

> **🎯 Weekly Goal:** Handle 50+ concurrent clients efficiently
>
> **💪 Progression:** Medium difficulty (scaling complexity)

### Week 3 Performance Targets

| Metric | Target | Your Result |
|--------|--------|-------------|
| Max concurrent clients | 50 | ___ |
| Memory per client | <100KB | ___ KB |
| P99 latency | <10ms | ___ ms |
| Zero FD leaks | 100% | Pass/Fail: ___ |
| Handles client churn | 100% | Pass/Fail: ___ |

[Similar daily structure to Weeks 1-2]

**Key Topics:**
- Day 15: epoll/kqueue intro
- Day 16: Accept loop + client tracking
- Day 17: Bounded buffers
- Day 18: Client churn testing
- Day 19: Integration + stress test
- Day 20 🗡️: Slow reader attack (buffer growth)

---

## 📗 Week 4 — HTTP Client & E2E Tracing

> **🎯 Weekly Goal:** Build production-quality HTTP client with full observability

### Week 4 Performance Targets

| Metric | Target | Your Result |
|--------|--------|-------------|
| HTTP parse time | <500μs | ___ μs |
| Request success rate | 99%+ | ___% |
| Malformed header handling | 10/10 | ___ /10 |
| Trace ID propagation | 100% | ___% |

[Daily structure continues...]

---

## 📗 Week 5 — Deload & Consolidation

> **🎯 Weekly Goal:** Reduce volume 50%, focus on quality
>
> **💪 Focus:** Refactoring, documentation, mental models

**Deload Activities:**
- Refactor messiest component from Weeks 1-4
- Create architecture diagram of all Month 1 systems
- Write technical deep-dive on one concept
- Peer review simulation (review your own code critically)
- Update all READMEs

**No New Features This Week**

---

# ⚔️ Arc 2 — Hardening (Month 2)

[Similar structure to Month 1, but now with:]

- Week 6: Thread pools & backpressure
- Week 7: Cryptographic hashing
- Week 8: Signatures & replay defense
- Week 9: Deload week

**Performance Progression:**
- Target: 100+ clients (up from 50)
- Target: <5ms p99 latency (down from <10ms)
- Target: 100% replay attack detection

---

# 🏰 Arc 3 — Distributed Core (Month 3)

**Weeks 10-13:**
- WAL & crash recovery
- Quorum replication
- Leader election
- Deload

**New Metrics:**
- Zero data loss guarantee
- Election time <3s
- Replication lag <100ms

---

# 🔮 Arc 4 — Trust Architecture (Month 4)

**Weeks 14-17:**
- Content-addressed storage
- Merkle tree proofs
- Transparency logs
- Deload

---

# 👑 Arc 5 — CivicTrust Integration (Month 5)

**Weeks 18-21:**
- Document issuance
- Anchoring workflows
- Offline verification
- Chaos testing
- Deload

---

# 🚀 Arc 6 — Polish & Ship (Month 6)

**Weeks 22-24:**
- SLI/SLO narratives
- Security model
- Documentation
- Demo preparation
- Final boss fight

---

## 📊 Appendix: Metrics & Templates

### A1: Daily Training Log Template

```markdown
# Week X - Day Y Training Log

## Pre-Session Warmup
- [ ] Reviewed: ___
- [ ] Primed: ___
- Mental energy: ___/10

## Session Metrics
Start: ___ End: ___
Coding time: ___ min
Debug time: ___ min

## Performance
- Tests written: ___
- First-run pass rate: ___%
- Bugs found: ___
- LOC: +___ -___

## Failure Log
[List each bug with: trigger, cause, fix time, lesson]

## Breakthroughs
[Any "aha!" moments]

## Tomorrow's Prep
[What to review before next session]
```

### A2: Weekly Benchmark Template

```markdown
# Week X Benchmark

## Technical Metrics
- LOC: ___
- Coverage: ___%
- Performance: [list key metrics vs targets]

## Capability Assessment
NEW: [what can you build now that you couldn't before]
IMPROVED: [what got better]
WEAK: [what needs more work]

## Personal Records
[List any PRs this week]

## Carry Forward
[Reusable patterns/insights for future weeks]
```

### A3: Monthly Stress Test Template

```markdown
# Month X Stress Test

## Max Load Test
- Clients: ___ (crashed at ___)
- Throughput: ___ req/s
- Memory: ___ MB at saturation
- First failure at: ___

## Failure Modes Found
[List each failure mode discovered]

## Recovery Procedures
[How system recovers from each]

## Next Month Targets
[Improved goals based on this month's limits]
```

### A4: Failure Drill Scorecard

```markdown
# Failure Drill: [Name]

## Setup
[How to reproduce]

## Expected Behavior
[What should happen]

## Actual Behavior
[What did happen]

## Pass Criteria
- [ ] Criterion 1
- [ ] Criterion 2
- [ ] Criterion 3

## Debug Log
[If failed, what did you learn]

## Fix Applied
[Changes made to pass]
```

### A5: Monthly Teaching Test

```markdown
# Month X Teaching Test

Without looking at notes, explain:

## Concept 1: ___
- Core mechanism: ___
- Why it matters: ___
- When to use: ___
- Common mistakes: ___

[Repeat for 3 concepts]

## Self-Grade
Understanding: ___/10
Clarity: ___/10
Completeness: ___/10

## Gaps Identified
[What did you struggle to explain?]
[Schedule remedial review]
```

---

## 🎯 Your Training Contract

Sign this with yourself:

```
I, _____________, commit to the following training principles:

1. I will track metrics honestly, including failures
2. I will not skip deload weeks (recovery is growth)
3. I will not advance past weekly gates without passing
4. I will maintain my training log daily (10min)
5. I will treat bugs as data, not shame
6. I will do spaced repetition reviews
7. I will publish monthly artifacts as proof
8. I will complete all 24 weeks, even when it's hard

Signed: _____________ Date: _____________

Start Date: _____________
Target Completion: _____________ (168 days from start)
```

---

## 🏆 Final Note: You're Training, Not Just Learning

```
╔══════════════════════════════════════════════════════════════╗
║                                                              ║
║  The difference between this and other roadmaps:             ║
║                                                              ║
║  OTHERS: "Read → Move on"                                    ║
║  THIS:   "Warmup → Work → Prove → Track → Recover → Repeat" ║
║                                                              ║
║  You're building CAPACITY, not just knowledge.               ║
║  You're tracking PERFORMANCE, not just completion.           ║
║  You're proving MASTERY, not just understanding.             ║
║                                                              ║
║  Ship proof. Track progress. Level up systematically.        ║
║                                                              ║
╚══════════════════════════════════════════════════════════════╝
```

**Now go build your gym. Track your reps. Chase your PRs.**

🏋️ **START WEEK 1 TOMORROW** 🏋️
