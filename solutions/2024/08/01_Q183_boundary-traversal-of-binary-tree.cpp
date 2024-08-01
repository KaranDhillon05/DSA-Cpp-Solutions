/*
 * Day: 183 | Date: 2024-08-01
 * Q183: Boundary Traversal of Binary Tree
 * Difficulty: Medium
 * Pattern: Traversals
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
    void addLeaves(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        if (!node->left && !node->right) ans.push_back(node->val);
        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }
    void addLeft(TreeNode* node, vector<int>& ans) {
        if (!node || (!node->left && !node->right)) return;
        ans.push_back(node->val);
        if (node->left) addLeft(node->left, ans); else addLeft(node->right, ans);
    }
    void addRight(TreeNode* node, vector<int>& ans) {
        if (!node || (!node->left && !node->right)) return;
        if (node->right) addRight(node->right, ans); else addRight(node->left, ans);
        ans.push_back(node->val);
    }
public:
    vector<int> boundaryTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        ans.push_back(root->val);
        addLeft(root->left, ans);
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
        addRight(root->right, ans);
        return ans;
    }
};
