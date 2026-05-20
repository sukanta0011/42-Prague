# codexion
*This project has been created as part of the 42 curriculum by sudas*

## Description

Codexion simulates a shared co-working hub where N coders compete for N USB dongles to compile their quantum code. Each coder needs **two dongles simultaneously** to compile, then releases them to debug and refactor, before trying to compile again. If a coder does not start compiling within `time_to_burnout` milliseconds since their last compile (or the start of the simulation), they burn out and the simulation stops.

Each coder runs as an independent POSIX thread. The central challenge is coordinating fair, deadlock-free, starvation-free access to the shared dongles under time pressure.

**Scheduling policies supported:**
| Policy | Description |
|:-------|:------------|
| `fifo` | First In, First Out — the dongle is granted to the coder whose request arrived first |
| `edf`  | Earliest Deadline First — the dongle is granted to the coder whose burnout deadline (`last_compile_start + time_to_burnout`) is nearest |

**Arguments**
| Argument | Type | Description |
|:---------|:-----|:------------|
| `number_of_coders` | int | Number of coders and also the number of dongles |
| `time_to_burnout` (ms) | long int | If a coder did not start compiling within this time since their last compile or simulation start, they burn out |
| `time_to_compile` (ms) | long int | Time a coder spends compiling while holding two dongles |
| `time_to_debug` (ms) | long int | Time a coder spends debugging after compiling |
| `time_to_refactor` (ms) | long int | Time a coder spends refactoring; immediately attempts to compile again after this |
| `number_of_compiles_required` | int | Simulation stops when all coders have compiled at least this many times |
| `dongle_cooldown` (ms) | long int | After being released, a dongle is unavailable until its cooldown has passed |
| `scheduler` | string | Arbitration policy: must be exactly `fifo` or `edf` |

## Instructions

To compile the binary `codexion`:
```bash
make
```

To run the simulation:
```bash
./codexion 3 1000 200 200 200 5 50 "edf"
```

Other Makefile rules:
```bash
make clean    # Remove object (.o) files
make fclean   # Remove object files and the binary
make re       # Clean everything and recompile
make leak     # Check for memory leaks (modify ARGS to change arguments)
```

## Blocking cases handled

### Deadlock prevention

Each coder needs two dongles to compile. With naive locking (each coder grabs the left dongle and waits for the right), all coders can hold one dongle and wait forever — a circular deadlock. This satisfies all four of **Coffman's conditions**:

- **Mutual exclusion** — a dongle can only be held by one coder at a time
- **Hold and wait** — a coder holds one dongle while waiting for the second
- **No preemption** — a dongle cannot be forcibly taken from a coder
- **Circular wait** — coder 1 waits for coder 2's dongle, coder 2 waits for coder 3's, and so on

Our solution breaks the **hold and wait** and **circular wait** conditions by never handing a dongle directly to a coder. Instead, coders submit requests to a per-dongle scheduler (a min-heap). A coder is only granted both dongles simultaneously when it sits at the top of both heaps. This way no coder ever holds one dongle while waiting for the other.

A **backoff mechanism** handles the residual case: if coder A has requested dongles 1 and 2, and coder B has requested dongles 2 and 3, neither may be the top of both heaps simultaneously. If a coder detects it is not the priority requester on both its dongles, it withdraws its earlier request and resubmits — breaking any potential cycle. For EDF scheduling, the same check is performed using deadline priority.

### Starvation prevention

Because all requests are registered in the scheduler before any dongle is granted, the arbitration is fair by construction. Under `fifo`, requests are served in strict arrival order. Under `edf`, the coder closest to burning out is always served first, which also prevents starvation since every coder's deadline is finite and approaches zero over time.

### Cooldown handling

After a coder releases a dongle, a cooldown timestamp is set on that dongle. Any coder that reaches the top of the dongle's heap while the cooldown is still active waits using `pthread_cond_timedwait`, which blocks the thread efficiently without busy-waiting. Once the cooldown expires, the dongle signals the waiting coder via `pthread_cond_signal`.

### Precise burnout detection

A dedicated monitor thread runs independently of all coder threads. It continuously checks the current time against each coder's registered deadline (`last_compile_start + time_to_burnout`). The moment a deadline is crossed, the monitor sets a shared `stop_simulation` flag under mutex lock and prints the burnout log. The burnout message is guaranteed to appear within 10 ms of the actual burnout time.

### Log serialization

All log output is protected by a dedicated print mutex. Any thread (coder or monitor) must acquire this mutex before writing to stdout and releases it immediately after. This ensures that no two log lines ever interleave.

## Thread synchronization mechanisms

### Primitives used

- **`pthread_mutex_t`** — used in three roles: protecting each dongle's state (heap + cooldown timestamp), protecting the shared `stop_simulation` flag, and serializing all log output.
- **`pthread_cond_t`** — used per dongle to implement efficient waiting during cooldown. Used `pthread_cond_timedwait` for waiting without blocking the source, `pthread_cond_broadcast` to wake up sleeping threads.

### Coordination between coders and the monitor

The monitor thread shares two pieces of data with coder threads: the `stop_simulation` flag and each coder's `deadline` field. Both are protected by mutex locks:

- When a coder starts compiling, it updates its own `deadline` under mutex lock so the monitor cannot read a partially updated value
- When the monitor detects a burnout, it sets `stop_simulation` to true under mutex lock; all coder threads poll this variable (also under lock) at safe points in their loop and exit cleanly when it is set

### Race condition prevention

Without the dongle mutex, two coders could both read a dongle as "available" and both proceed to take it — a classic TOCTOU (time-of-check to time-of-use) race. By acquiring the dongle mutex before reading or modifying dongle state, only one thread can evaluate and update the dongle at a time. The heap operations (insert request, remove top) are also performed inside this critical section.

## Resources

- [POSIX Threads](https://www.geeksforgeeks.org/c/thread-functions-in-c-c/)
- [Mutex lock for Linux thread synchronization](https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/)
- [Priority Queue using Binary Heap](https://www.geeksforgeeks.org/dsa/priority-queue-using-binary-heap/)

### AI Usage

Used Gemini and Claude for:
- Discussing strategies for heap management and how resource scheduling works in real operating systems
- Debugging memory leaks
- Polishing this README file

Project structure and core algorithm were designed and implemented independently.