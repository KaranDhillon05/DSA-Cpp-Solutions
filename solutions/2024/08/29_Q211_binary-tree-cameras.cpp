/*
 * Day: 211 | Date: 2024-08-29
 * Q211: Binary Tree Cameras
 * Difficulty: Hard
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
    int cameras = 0;
    int dfs(TreeNode* node) {
        if (!node) return 2;
        int l = dfs(node->left), r = dfs(node->right);
        if (l == 0 || r == 0) { ++cameras; return 1; }
        if (l == 1 || r == 1) return 2;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int state = dfs(root);
        return cameras + (state == 0);
    }
};
