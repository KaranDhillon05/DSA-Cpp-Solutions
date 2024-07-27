/*
 * Day: 178 | Date: 2024-07-27
 * Q178: Binary Tree Zigzag Level Order Traversal
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool ltr = true;
        while (!dq.empty()) {
            int sz = dq.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = ltr ? dq.front() : dq.back();
                if (ltr) dq.pop_front(); else dq.pop_back();
                level[ltr ? i : sz - 1 - i] = node->val;
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            }
            ans.push_back(level);
            ltr = !ltr;
        }
        return ans;
    }
};
