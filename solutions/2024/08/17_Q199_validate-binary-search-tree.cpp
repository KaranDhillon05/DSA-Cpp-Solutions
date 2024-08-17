/*
 * Day: 199 | Date: 2024-08-17
 * Q199: Validate Binary Search Tree
 * Difficulty: Medium
 * Pattern: BST
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
    bool dfs(TreeNode* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;
        return dfs(node->left, lo, node->val) && dfs(node->right, node->val, hi);
    }
public:
    bool isValidBST(TreeNode* root) { return dfs(root, LLONG_MIN, LLONG_MAX); }
};
