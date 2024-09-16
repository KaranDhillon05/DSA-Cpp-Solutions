/*
 * Day: 229 | Date: 2024-09-16
 * Q229: Replace Words
 * Difficulty: Medium
 * Pattern: Trie
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode { array<TrieNode*, 26> ch{}; bool end = false; };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (string& w : dictionary) {
            TrieNode* cur = root;
            for (char c : w) {
                if (!cur->ch[c - 'a']) cur->ch[c - 'a'] = new TrieNode();
                cur = cur->ch[c - 'a'];
            }
            cur->end = true;
        }
        string ans, word;
        auto flush = [&]() {
            if (!word.empty()) {
                TrieNode* cur = root;
                string pref;
                for (char c : word) {
                    if (!cur->ch[c - 'a']) break;
                    cur = cur->ch[c - 'a'];
                    pref.push_back(c);
                    if (cur->end) { word = pref; break; }
                }
                if (!ans.empty()) ans.push_back(' ');
                ans += word;
                word.clear();
            }
        };
        for (char c : sentence) {
            if (c == ' ') flush(); else word.push_back(c);
        }
        flush();
        return ans;
    }
};
