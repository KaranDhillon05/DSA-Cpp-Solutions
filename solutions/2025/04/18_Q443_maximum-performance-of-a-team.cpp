/*
 * Day: 443 | Date: 2025-04-18
 * Q443: Maximum Performance of a Team
 * Difficulty: Hard
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> eng;
        for (int i = 0; i < n; ++i) eng.push_back({efficiency[i], speed[i]});
        sort(eng.begin(), eng.end(), greater<pair<int,int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, best = 0;
        const int MOD = 1e9 + 7;
        for (auto& [e, s] : eng) {
            sum += s;
            pq.push(s);
            if ((int)pq.size() > k) { sum -= pq.top(); pq.pop(); }
            best = max(best, sum * e);
        }
        return (int)(best % MOD);
    }
};
