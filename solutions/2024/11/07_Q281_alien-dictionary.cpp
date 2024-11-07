/*
 * Day: 281 | Date: 2024-11-07
 * Q281: Alien Dictionary
 * Difficulty: Hard
 * Pattern: Topological Sort
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> g;
        unordered_map<char, int> indeg;
        for (auto& w : words)
            for (char c : w) indeg[c] = 0;
        for (int i = 0; i + 1 < (int)words.size(); ++i) {
            string& a = words[i], &b = words[i+1];
            if (a.size() > b.size() && a.substr(0, b.size()) == b) return "";
            int j = 0;
            while (j < (int)a.size() && j < (int)b.size() && a[j] == b[j]) ++j;
            if (j < (int)a.size() && j < (int)b.size()) {
                if (!g[a[j]].count(b[j])) { g[a[j]].insert(b[j]); ++indeg[b[j]]; }
            }
        }
        queue<char> q;
        for (auto& [c, d] : indeg) if (!d) q.push(c);
        string order;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            order.push_back(c);
            for (char nb : g[c]) if (--indeg[nb] == 0) q.push(nb);
        }
        return (int)order.size() == (int)indeg.size() ? order : "";
    }
};
