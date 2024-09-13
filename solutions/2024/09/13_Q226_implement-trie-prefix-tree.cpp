/*
 * Day: 226 | Date: 2024-09-13
 * Q226: Implement Trie (Prefix Tree)
 * Difficulty: Medium
 * Pattern: Trie
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node { array<Node*, 26> ch{}; bool end = false; };
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->ch[i]) cur->ch[i] = new Node();
            cur = cur->ch[i];
        }
        cur->end = true;
    }
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->ch[i]) return false;
            cur = cur->ch[i];
        }
        return cur->end;
    }
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!cur->ch[i]) return false;
            cur = cur->ch[i];
        }
        return true;
    }
};
