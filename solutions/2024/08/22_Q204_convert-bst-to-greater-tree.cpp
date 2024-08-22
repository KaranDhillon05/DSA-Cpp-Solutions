/*
 * Day: 204 | Date: 2024-08-22
 * Q204: Convert BST to Greater Tree
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
    int sum = 0;
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) { dfs(root); return root; }
};
