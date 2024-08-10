/*
 * Day: 192 | Date: 2024-08-10
 * Q192: Sum of Left Leaves
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
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right) return isLeft ? node->val : 0;
        return dfs(node->left, true) + dfs(node->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) { return dfs(root, false); }
};
