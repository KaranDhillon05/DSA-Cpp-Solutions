/*
 * Day: 231 | Date: 2024-09-18
 * Q231: Palindrome Pairs
 * Difficulty: Hard
 * Pattern: Trie
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        array<TrieNode*, 26> ch{};
        int idx = -1;
    };
    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* cur = root;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (!cur->ch[c]) cur->ch[c] = new TrieNode();
            cur = cur->ch[c];
        }
        cur->idx = id;
    }
    bool isPal(const string& s, int lo, int hi) {
        while (lo < hi) if (s[lo++] != s[hi--]) return false;
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < (int)words.size(); ++i) insert(root, words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < (int)words.size(); ++i) {
            const string& w = words[i];
            TrieNode* cur = root;
            for (int j = 0; j <= (int)w.size(); ++j) {
                if (cur->idx >= 0 && cur->idx != i && isPal(w, j, (int)w.size() - 1))
                    ans.push_back({i, cur->idx});
                if (j == (int)w.size()) break;
                int c = w[j] - 'a';
                if (!cur->ch[c]) break;
                cur = cur->ch[c];
                if (cur->idx >= 0 && cur->idx != i && isPal(w, 0, j - 1))
                    ans.push_back({cur->idx, i});
            }
        }
        return ans;
    }
};
