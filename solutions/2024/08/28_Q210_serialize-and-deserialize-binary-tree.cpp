/*
 * Day: 210 | Date: 2024-08-28
 * Q210: Serialize and Deserialize Binary Tree
 * Difficulty: Hard
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

class Codec {
    void pre(TreeNode* node, string& s) {
        if (!node) { s += "#,"; return; }
        s += to_string(node->val) + ",";
        pre(node->left, s);
        pre(node->right, s);
    }
    TreeNode* build(queue<string>& q) {
        string tok = q.front(); q.pop();
        if (tok == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(tok));
        node->left = build(q);
        node->right = build(q);
        return node;
    }
public:
    string serialize(TreeNode* root) { string s; pre(root, s); return s; }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string cur;
        for (char c : data) {
            if (c == ',') { q.push(cur); cur.clear(); }
            else cur.push_back(c);
        }
        if (!cur.empty()) q.push(cur);
        return build(q);
    }
};
