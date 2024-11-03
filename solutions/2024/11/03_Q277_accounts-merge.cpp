/*
 * Day: 277 | Date: 2024-11-03
 * Q277: Accounts Merge
 * Difficulty: Medium
 * Pattern: DFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, unordered_set<string>> graph;
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < (int)acc.size(); ++i) {
                emailToName[acc[i]] = name;
                graph[acc[i]].insert(acc[1]);
                graph[acc[1]].insert(acc[i]);
            }
        }
        unordered_set<string> seen;
        vector<vector<string>> res;
        for (auto& [email, _] : graph) {
            if (seen.count(email)) continue;
            vector<string> comp;
            stack<string> st;
            st.push(email);
            seen.insert(email);
            while (!st.empty()) {
                string cur = st.top(); st.pop();
                comp.push_back(cur);
                for (auto& nb : graph[cur])
                    if (!seen.count(nb)) { seen.insert(nb); st.push(nb); }
            }
            sort(comp.begin(), comp.end());
            comp.insert(comp.begin(), emailToName[email]);
            res.push_back(comp);
        }
        return res;
    }
};
