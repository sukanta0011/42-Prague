# 42-Prague
All the projects of 42next Core Curriculum

---

## Rank 0

| Project | Description | Tech | Status |
|:--------|:------------|:-----|:-------|
| [libft](libft/) | Reimplement a subset of the C standard library functions from scratch | C | Completed |

---

## Rank 1

| Project | Description | Tech | Status |
|:--------|:------------|:-----|:-------|
| [get_next_line](get_next_line/) | Read a file descriptor line by line — each call returns the next line, mimicking streaming text reading | C | Completed |
| [ft_printf](ft_printf/) | Reimplement `printf` with support for format specifiers and conversion flags | C | Completed |
| [Born2BeRoot](Born2BeRoot/) | Configure a Debian VM from scratch: encrypted LVM partitions, SSH on port 4242, UFW firewall, sudo policies, password hardening, cron-based monitoring script. Bonus: hosted a static WordPress site with fail2ban for SSH brute-force protection | Linux, Debian, SSH, UFW, fail2ban | Completed |

---

## Rank 2

| Project | Description | Tech | Status |
|:--------|:------------|:-----|:-------|
| [push_swap](push_swap/) | Sort a list of integers using only two stacks and a fixed set of swap/push/rotate operations. Uses index-based chunk sort (chunk size 35 for 500 numbers, 20 for 100) to stay under the operation limit. Bonus: checker program that validates the output | C | Completed |
| [python_intro](python_intro/) | 10 Python modules covering: basic syntax with linting, OOP and classes, exception handling and resilient data pipelines, virtual environment, pydantic, python function tool | Python, Pydantic, uv, poetry, mypy, flake8 | Completed |
| [A-Maze-Ing](A-Maze-Ing/) | Collaborative project: generates and solves mazes using iterative DFS, then renders them in real time with MiniLibX. The generation engine is packaged as a reusable `mazegen` pip-installable Python package. Keys: regenerate, show/hide solution, rotate colours, quit | Python, MiniLibX, uv | Completed |

---

## Rank 3

| Project | Description | Tech | Status |
|:--------|:------------|:-----|:-------|
| [flyin](flyin/) | Discrete-event simulation optimizing drone swarm throughput across a constraint-heavy directed graph. Uses DFS to enumerate routes, a weighted-cost multi-level priority queue for routing, and a three-phase atomic movement algorithm (look-ahead, pessimistic reservation, commit) to avoid capacity overflows. Custom double-buffered MiniLibX visualizer with LERP animations and real-time HUD | Python, MiniLibX, uv | Completed |
| [call_me_maybe](call_me_maybe/) | Constrained decoding pipeline for the Qwen3-0.6B LLM that guarantees 100% structurally valid JSON function calls. Uses trie-based hard masking for function name selection and soft logit biasing for argument extraction. Extras: custom BPE tokenizer built from scratch, Streamlit web UI, deployed on HuggingFace Spaces | Python, Pydantic, Streamlit | Completed |
| [codexion](codexion/) | Philosophers-variant concurrency project: N coders (POSIX threads) compete for N USB dongles, each needing two simultaneously to compile. Implements deadlock-free, starvation-free scheduling via per-dongle min-heap schedulers with FIFO and EDF policies, a backoff mechanism to break circular waits, cooldown handling with `pthread_cond_timedwait`, and a dedicated monitor thread for burnout detection within 10 ms | C, POSIX threads | Completed |
