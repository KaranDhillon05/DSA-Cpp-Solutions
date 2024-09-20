/*
 * Day: 233 | Date: 2024-09-20
 * Q233: Top K Frequent Elements
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) ++freq[x];
        vector<pair<int,int>> v(freq.begin(), freq.end());
        nth_element(v.begin(), v.begin() + k - 1, v.end(),
            [](auto& a, auto& b){ return a.second > b.second; });
        v.resize(k);
        vector<int> res;
        for (auto& p : v) res.push_back(p.first);
        return res;
    }
};
