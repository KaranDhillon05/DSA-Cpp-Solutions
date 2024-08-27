/*
 * Day: 209 | Date: 2024-08-27
 * Q209: Generate Binary Search Trees
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
    vector<TreeNode*> build(int lo, int hi) {
        if (lo > hi) return {nullptr};
        vector<TreeNode*> all;
        for (int i = lo; i <= hi; ++i) {
            auto left = build(lo, i - 1), right = build(i + 1, hi);
            for (TreeNode* l : left)
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l; root->right = r;
                    all.push_back(root);
                }
        }
        return all;
    }
public:
    vector<TreeNode*> generateTrees(int n) { return build(1, n); }
};
