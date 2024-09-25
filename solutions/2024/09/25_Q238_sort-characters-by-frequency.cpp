/*
 * Day: 238 | Date: 2024-09-25
 * Q238: Sort Characters By Frequency
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
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for (char c : s) ++freq[c];
        priority_queue<pair<int,char>> pq;
        for (auto& [c,f] : freq) pq.push({f,c});
        string res;
        while (!pq.empty()) {
            auto [f,c] = pq.top(); pq.pop();
            res.append(f, c);
        }
        return res;
    }
};
