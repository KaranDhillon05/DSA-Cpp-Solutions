/*
 * Day: 228 | Date: 2024-09-15
 * Q228: Add and Search Words
 * Difficulty: Medium
 * Pattern: Trie
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
    struct Node { array<Node*, 26> ch{}; bool end = false; };
    Node* root;
    bool dfs(const string& word, int i, Node* node) {
        if (i == (int)word.size()) return node->end;
        char c = word[i];
        if (c == '.') {
            for (Node* child : node->ch) if (child && dfs(word, i + 1, child)) return true;
            return false;
        }
        if (!node->ch[c - 'a']) return false;
        return dfs(word, i + 1, node->ch[c - 'a']);
    }
public:
    WordDictionary() { root = new Node(); }
    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->ch[c - 'a']) cur->ch[c - 'a'] = new Node();
            cur = cur->ch[c - 'a'];
        }
        cur->end = true;
    }
    bool search(string word) { return dfs(word, 0, root); }
};
