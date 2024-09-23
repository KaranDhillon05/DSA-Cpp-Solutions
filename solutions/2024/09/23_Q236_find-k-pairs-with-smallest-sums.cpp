/*
 * Day: 236 | Date: 2024-09-23
 * Q236: Find K Pairs with Smallest Sums
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        if (nums1.empty() || nums2.empty()) return {};
        for (int i = 0; i < min((int)nums1.size(), k); ++i)
            pq.push({nums1[i] + nums2[0], i, 0});
        vector<vector<int>> res;
        while (!pq.empty() && (int)res.size() < k) {
            auto [s, i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) pq.push({nums1[i] + nums2[j+1], i, j+1});
        }
        return res;
    }
};
