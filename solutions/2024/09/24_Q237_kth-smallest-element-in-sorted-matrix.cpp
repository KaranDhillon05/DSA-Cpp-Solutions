/*
 * Day: 237 | Date: 2024-09-24
 * Q237: Kth Smallest Element in Sorted Matrix
 * Difficulty: Medium
 * Pattern: Top-K Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) pq.push({matrix[i][0], i, 0});
        while (!pq.empty()) {
            auto [val, r, c] = pq.top(); pq.pop();
            if (--k == 0) return val;
            if (c + 1 < n) pq.push({matrix[r][c+1], r, c+1});
        }
        return -1;
    }
};
