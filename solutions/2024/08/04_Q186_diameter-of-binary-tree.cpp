/*
 * Day: 186 | Date: 2024-08-04
 * Q186: Diameter of Binary Tree
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
    int best = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left), r = dfs(node->right);
        best = max(best, l + r);
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) { dfs(root); return best; }
};
