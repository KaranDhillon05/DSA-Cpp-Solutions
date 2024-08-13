/*
 * Day: 195 | Date: 2024-08-13
 * Q195: Binary Tree Maximum Path Sum
 * Difficulty: Hard
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
    int best = INT_MIN;
    int gain(TreeNode* node) {
        if (!node) return 0;
        int l = max(0, gain(node->left)), r = max(0, gain(node->right));
        best = max(best, node->val + l + r);
        return node->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) { gain(root); return best; }
};
