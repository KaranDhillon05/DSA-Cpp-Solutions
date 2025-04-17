/*
 * Day: 442 | Date: 2025-04-17
 * Q442: Advantage Shuffle
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> pool(nums1.begin(), nums1.end());
        vector<pair<int,int>> order;
        for (int i = 0; i < (int)nums2.size(); ++i) order.push_back({nums2[i], i});
        sort(order.begin(), order.end());
        vector<int> res(nums2.size());
        vector<int> leftover;
        int i = 0;
        while (i < (int)order.size()) {
            int j = i;
            while (j < (int)order.size() && order[j].first == order[i].first) ++j;
            for (int k = i; k < j; ++k) {
                auto it = pool.upper_bound(order[k].first);
                if (it != pool.end()) { res[order[k].second] = *it; pool.erase(it); }
                else leftover.push_back(order[k].second);
            }
            i = j;
        }
        for (int idx : leftover) { res[idx] = *pool.begin(); pool.erase(pool.begin()); }
        return res;
    }
};
