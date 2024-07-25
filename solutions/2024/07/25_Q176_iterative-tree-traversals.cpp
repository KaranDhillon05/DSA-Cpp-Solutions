/*
 * Day: 176 | Date: 2024-07-25
 * Q176: Iterative Tree Traversals
 * Difficulty: Easy
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;
        if (root) st.push({root, false});
        while (!st.empty()) {
            auto [node, visited] = st.top(); st.pop();
            if (!node) continue;
            if (visited) ans.push_back(node->val);
            else { st.push({node, true}); st.push({node->right, false}); st.push({node->left, false}); }
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            ans.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;
        if (root) st.push({root, false});
        while (!st.empty()) {
            auto [node, visited] = st.top(); st.pop();
            if (!node) continue;
            if (visited) ans.push_back(node->val);
            else { st.push({node, true}); st.push({node->right, false}); st.push({node->left, false}); }
        }
        return ans;
    }
};
