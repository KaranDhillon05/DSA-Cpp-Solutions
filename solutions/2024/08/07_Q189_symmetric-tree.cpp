/*
 * Day: 189 | Date: 2024-08-07
 * Q189: Symmetric Tree
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
    bool mirror(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a == b;
        return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
    }
public:
    bool isSymmetric(TreeNode* root) { return !root || mirror(root->left, root->right); }
};
