/*
 * Day: 246 | Date: 2024-10-03
 * Q246: Smallest Range Covering Elements from K Lists
 * Difficulty: Hard
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int mx = INT_MIN, n = nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        int bestL = 0, bestR = INT_MAX;
        while ((int)pq.size() == n) {
            auto [val, i, j] = pq.top(); pq.pop();
            if (mx - val < bestR - bestL) { bestL = val; bestR = mx; }
            if (j + 1 == (int)nums[i].size()) break;
            int nxt = nums[i][j+1];
            pq.push({nxt, i, j+1});
            mx = max(mx, nxt);
        }
        return {bestL, bestR};
    }
};
