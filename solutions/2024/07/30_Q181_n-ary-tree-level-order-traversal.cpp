/*
 * Day: 181 | Date: 2024-07-30
 * Q181: N-ary Tree Level Order Traversal
 * Difficulty: Medium
 * Pattern: Traversals
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            while (sz--) {
                Node* node = q.front(); q.pop();
                level.push_back(node->val);
                for (Node* ch : node->children) q.push(ch);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
