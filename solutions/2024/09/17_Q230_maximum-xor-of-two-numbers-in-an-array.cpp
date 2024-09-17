/*
 * Day: 230 | Date: 2024-09-17
 * Q230: Maximum XOR of Two Numbers in an Array
 * Difficulty: Medium
 * Pattern: Trie
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode { array<TrieNode*, 2> ch{}; };
    void insert(TrieNode* root, int num) {
        TrieNode* cur = root;
        for (int b = 31; b >= 0; --b) {
            int bit = (num >> b) & 1;
            if (!cur->ch[bit]) cur->ch[bit] = new TrieNode();
            cur = cur->ch[bit];
        }
    }
    int query(TrieNode* root, int num) {
        TrieNode* cur = root;
        int ans = 0;
        for (int b = 31; b >= 0; --b) {
            int bit = (num >> b) & 1;
            int want = bit ^ 1;
            if (cur->ch[want]) { ans |= 1 << b; cur = cur->ch[want]; }
            else cur = cur->ch[bit];
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int best = 0;
        for (int x : nums) {
            best = max(best, query(root, x));
            insert(root, x);
        }
        return best;
    }
};
