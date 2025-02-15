/*
 * Day: 381 | Date: 2025-02-15
 * Q381: Diameter of N-Ary Tree
 * Difficulty: Hard
 * Pattern: Tree/Graph DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Node { public: int val; vector<Node*> children; Node(int v):val(v){} };
class Solution {
    int best=0;
    int dfs(Node* root){
        if (!root) return 0;
        int mx1=0,mx2=0;
        for (Node* ch:root->children){
            int d=dfs(ch);
            if (d>mx1){ mx2=mx1; mx1=d; } else if (d>mx2) mx2=d;
        }
        best=max(best, mx1+mx2);
        return mx1+1;
    }
public:
    int diameter(Node* root) { dfs(root); return best; }
};
