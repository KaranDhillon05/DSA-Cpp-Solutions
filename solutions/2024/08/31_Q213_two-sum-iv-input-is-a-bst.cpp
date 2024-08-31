/*
 * Day: 213 | Date: 2024-08-31
 * Q213: Two Sum IV - Input is a BST
 * Difficulty: Easy
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
    bool find(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;
        if (seen.count(k - node->val)) return true;
        seen.insert(node->val);
        return find(node->left, k, seen) || find(node->right, k, seen);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return find(root, k, seen);
    }
};
