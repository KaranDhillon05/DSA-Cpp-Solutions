/*
 * Day: 314 | Date: 2024-12-10
 * Q314: House Robber III
 * Difficulty: Medium
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution {
    unordered_map<TreeNode*, pair<long long,long long>> mp;
    pair<long long,long long> dfs(TreeNode* root){
        if(!root) return {0,0};
        if(mp.count(root)) return mp[root];
        auto L=dfs(root->left), R=dfs(root->right);
        long long robNow=root->val+L.second+R.second;
        long long skip=max(L.first,L.second)+max(R.first,R.second);
        return mp[root]={robNow,skip};
    }
public:
    int rob(TreeNode* root) {
        auto p=dfs(root); return (int)max(p.first,p.second);
    }
};
