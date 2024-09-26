/*
 * Day: 239 | Date: 2024-09-26
 * Q239: Reorganize String
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
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for (char c : s) ++freq[c];
        priority_queue<pair<int,char>> pq;
        for (auto& [c,f] : freq) pq.push({f,c});
        string res;
        while (!pq.empty()) {
            auto [f,c] = pq.top(); pq.pop();
            if (!res.empty() && res.back() == c) {
                if (pq.empty()) return "";
                auto [f2,c2] = pq.top(); pq.pop();
                res.push_back(c2);
                if (--f2 > 0) pq.push({f2,c2});
                pq.push({f,c});
            } else {
                res.push_back(c);
                if (--f > 0) pq.push({f,c});
            }
        }
        return res;
    }
};
