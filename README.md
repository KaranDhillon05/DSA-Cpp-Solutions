# DSA C++ Solutions — 500 Curated FAANG Problems

Interview-oriented C++ solutions covering Arrays, Strings, Trees, Graphs, DP, and 20+ core patterns.

**Schedule:** 1 problem per day from **2024-02-01** through **2025-06-14** (500 days).

## Layout

```
solutions/
  YYYY/
    MM/
      DD_QNNN_problem-slug.cpp
SCHEDULE.md          # full day → problem calendar
SOLUTIONS.md         # quick index
_gen/                # generators (rebuild with python3 _gen/build.py)
```

## Topics

| Section | Topic | Q Range | Key Patterns |
|--------:|-------|---------|--------------|
| 1 | Arrays | 1–50 | Two Pointers, Sliding Window, Prefix Sum, Kadane's |
| 2 | Strings | 51–90 | HashMap, Sliding Window, KMP, Stack |
| 3 | Linked Lists | 91–120 | Fast/Slow Pointers, Reversal, Merge |
| 4 | Stacks & Queues | 121–145 | Monotonic Stack / Deque |
| 5 | Binary Search | 146–175 | Classic BS, Parametric Search |
| 6 | Trees | 176–231 | DFS/BFS, BST, Segment Tree, Trie |
| 7 | Heaps | 232–255 | Top-K, Two-Heap Median |
| 8 | Graphs | 256–310 | BFS, DFS, Topo, DSU, Dijkstra, MST |
| 9 | Dynamic Programming | 311–390 | 1-D/2-D, Knapsack, Interval, Bitmask |
| 10 | Backtracking | 391–420 | Subsets, Permutations, Pruning |
| 11 | Greedy | 421–445 | Interval / Exchange Argument |
| 12 | Hashing & Math | 446–470 | HashMap, Number Theory, Bits |
| 13 | Design | 471–500 | LRU/LFU, Streams, Tries |

## File header

Each `.cpp` file includes day number, calendar date, problem metadata, and a LeetCode-style `Solution` class (C++17, `#include <bits/stdc++.h>`).

## Rebuild

```bash
python3 _gen/build.py
```
