/*
 * Day: 143 | Date: 2024-06-22
 * Q143: Dota2 Senate
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
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();
        for (int i = 0; i < n; ++i) (senate[i] == 'R' ? r : d).push(i);
        while (!r.empty() && !d.empty()) {
            int ri = r.front(); r.pop();
            int di = d.front(); d.pop();
            if (ri < di) r.push(ri + n); else d.push(di + n);
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};
