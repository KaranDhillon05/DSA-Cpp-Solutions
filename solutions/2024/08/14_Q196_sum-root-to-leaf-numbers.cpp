/*
 * Day: 196 | Date: 2024-08-14
 * Q196: Sum Root to Leaf Numbers
 * Difficulty: Medium
 * Pattern: Properties
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
    void dfs(TreeNode* node, int cur, int& ans) {
        if (!node) return;
        cur = cur * 10 + node->val;
        if (!node->left && !node->right) ans += cur;
        else { dfs(node->left, cur, ans); dfs(node->right, cur, ans); }
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};
