/*
 * Day: 476 | Date: 2025-05-21
 * Q476: Design Search Autocomplete System
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> next;
    string sentence;
    int times = 0;
};

class AutocompleteSystem {
    TrieNode* root = new TrieNode();
    TrieNode* cur = root;
    string prefix;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < (int)sentences.size(); ++i) insert(sentences[i], times[i]);
    }
    vector<string> input(char c) {
        if (c == '#') {
            insert(prefix, 1);
            prefix.clear();
            cur = root;
            return {};
        }
        prefix.push_back(c);
        if (!cur->next.count(c)) cur = nullptr;
        else cur = cur->next[c];
        if (!cur) return {"-"};
        vector<TrieNode*> nodes;
        collect(cur, nodes);
        sort(nodes.begin(), nodes.end(), [](TrieNode* a, TrieNode* b) {
            if (a->times != b->times) return a->times > b->times;
            return a->sentence < b->sentence;
        });
        vector<string> res;
        for (int i = 0; i < min(3, (int)nodes.size()); ++i) res.push_back(nodes[i]->sentence);
        return res;
    }
private:
    void insert(const string& s, int t) {
        TrieNode* node = root;
        for (char c : s) {
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->sentence = s;
        node->times += t;
    }
    void collect(TrieNode* node, vector<TrieNode*>& out) {
        if (!node) return;
        if (!node->sentence.empty()) out.push_back(node);
        for (auto& [c, ch] : node->next) collect(ch, out);
    }
};
