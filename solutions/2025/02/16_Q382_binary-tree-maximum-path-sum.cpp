/*
 * Day: 382 | Date: 2025-02-16
 * Q382: Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Pattern: Tree/Graph DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left,*right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution {
    int best=INT_MIN;
    int dfs(TreeNode* root){
        if (!root) return 0;
        int l=max(0,dfs(root->left)), r=max(0,dfs(root->right));
        best=max(best, root->val+l+r);
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) { dfs(root); return best; }
};
