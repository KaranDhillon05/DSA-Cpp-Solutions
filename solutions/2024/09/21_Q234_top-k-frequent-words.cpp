/*
 * Day: 234 | Date: 2024-09-21
 * Q234: Top K Frequent Words
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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (auto& w : words) ++freq[w];
        auto cmp = [&](const string& a, const string& b) {
            if (freq[a] != freq[b]) return freq[a] > freq[b];
            return a < b;
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (auto& [w, f] : freq) {
            pq.push(w);
            if ((int)pq.size() > k) pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); }
        reverse(res.begin(), res.end());
        return res;
    }
};
