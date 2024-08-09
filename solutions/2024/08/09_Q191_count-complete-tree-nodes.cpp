/*
 * Day: 191 | Date: 2024-08-09
 * Q191: Count Complete Tree Nodes
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
    int depthLeft(TreeNode* node) {
        int d = 0; while (node) { ++d; node = node->left; } return d;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int ld = depthLeft(root->left), rd = depthLeft(root->right);
        if (ld == rd) return (1 << ld) + countNodes(root->right);
        return (1 << rd) + countNodes(root->left);
    }
};
