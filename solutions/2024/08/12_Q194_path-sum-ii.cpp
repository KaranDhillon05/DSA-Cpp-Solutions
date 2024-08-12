/*
 * Day: 194 | Date: 2024-08-12
 * Q194: Path Sum II
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
    void dfs(TreeNode* node, int rem, vector<int>& path, vector<vector<int>>& ans) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && rem == node->val) ans.push_back(path);
        else { dfs(node->left, rem - node->val, path, ans); dfs(node->right, rem - node->val, path, ans); }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};
