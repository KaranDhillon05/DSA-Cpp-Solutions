/*
 * Day: 265 | Date: 2024-10-22
 * Q265: Open the Lock
 * Difficulty: Medium
 * Pattern: BFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000", 0});
        unordered_set<string> seen = {"0000"};
        while (!q.empty()) {
            auto [cur, d] = q.front(); q.pop();
            if (cur == target) return d;
            for (int i = 0; i < 4; ++i) {
                for (int delta : {1, -1}) {
                    string nxt = cur;
                    nxt[i] = '0' + (nxt[i] - '0' + delta + 10) % 10;
                    if (!seen.count(nxt) && !dead.count(nxt)) {
                        seen.insert(nxt);
                        q.push({nxt, d + 1});
                    }
                }
            }
        }
        return -1;
    }
};
