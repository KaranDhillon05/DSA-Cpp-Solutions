/*
 * Day: 166 | Date: 2024-07-15
 * Q166: K-th Smallest Prime Fraction
 * Difficulty: Medium
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto cmp = [&](const array<int,2>& a, const array<int,2>& b) {
            return (double)arr[a[0]] / arr[a[1]] > (double)arr[b[0]] / arr[b[1]];
        };
        priority_queue<array<int,2>, vector<array<int,2>>, decltype(cmp)> pq(cmp);
        for (int j = 1; j < n; ++j) pq.push({0, j});
        while (--k) {
            auto [i, j] = pq.top(); pq.pop();
            if (i + 1 < j) pq.push({i + 1, j});
        }
        auto [i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};
