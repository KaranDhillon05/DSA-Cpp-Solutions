/*
 * Day: 182 | Date: 2024-07-31
 * Q182: Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Pattern: Traversals
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> cols;
        queue<pair<TreeNode*, pair<int,int>>> q;
        if (root) q.push({root, {0, 0}});
        while (!q.empty()) {
            auto [node, pos] = q.front(); q.pop();
            auto [x, y] = pos;
            cols[x][y].insert(node->val);
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> ans;
        for (auto& [x, rows] : cols) {
            vector<int> col;
            for (auto& [y, vals] : rows)
                for (int v : vals) col.push_back(v);
            ans.push_back(col);
        }
        return ans;
    }
};
