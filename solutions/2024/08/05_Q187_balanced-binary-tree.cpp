/*
 * Day: 187 | Date: 2024-08-05
 * Q187: Balanced Binary Tree
 * Difficulty: Easy
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
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left), r = dfs(node->right);
        if (l < 0 || r < 0 || abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) { return dfs(root) >= 0; }
};
