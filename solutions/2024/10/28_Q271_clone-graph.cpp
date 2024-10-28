/*
 * Day: 271 | Date: 2024-10-28
 * Q271: Clone Graph
 * Difficulty: Medium
 * Pattern: DFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        function<Node*(Node*)> dfs = [&](Node* cur) {
            if (mp.count(cur)) return mp[cur];
            Node* copy = new Node(cur->val);
            mp[cur] = copy;
            for (Node* nb : cur->neighbors) copy->neighbors.push_back(dfs(nb));
            return copy;
        };
        return dfs(node);
    }
};
