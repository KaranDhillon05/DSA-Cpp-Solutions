/*
 * Day: 141 | Date: 2024-06-20
 * Q141: Task Scheduler
 * Difficulty: Medium
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        for (char c : tasks) ++cnt[c - 'A'];
        int mx = *max_element(cnt.begin(), cnt.end());
        int slots = (mx - 1) * (n + 1);
        for (int c : cnt) if (c == mx) --slots;
        return max((int)tasks.size(), slots + (mx - count(cnt.begin(), cnt.end(), mx - 1)));
    }
};
