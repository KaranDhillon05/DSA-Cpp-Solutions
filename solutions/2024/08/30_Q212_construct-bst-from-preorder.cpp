/*
 * Day: 212 | Date: 2024-08-30
 * Q212: Construct BST from Preorder
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
    TreeNode* build(vector<int>& pre, int& i, int bound) {
        if (i == (int)pre.size() || pre[i] > bound) return nullptr;
        TreeNode* node = new TreeNode(pre[i++]);
        node->left = build(pre, i, node->val);
        node->right = build(pre, i, bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
