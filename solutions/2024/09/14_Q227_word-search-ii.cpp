/*
 * Day: 227 | Date: 2024-09-14
 * Q227: Word Search II
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
        string* word = nullptr;
    };
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& ans) {
        char ch = board[r][c];
        if (!node->ch[ch - 'a']) return;
        node = node->ch[ch - 'a'];
        if (node->word) { ans.push_back(*node->word); node->word = nullptr; }
        board[r][c] = '#';
        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < (int)board.size() && nc >= 0 && nc < (int)board[0].size() && board[nr][nc] != '#')
                dfs(board, nr, nc, node, ans);
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* cur = root;
            for (char c : w) {
                if (!cur->ch[c - 'a']) cur->ch[c - 'a'] = new TrieNode();
                cur = cur->ch[c - 'a'];
            }
            cur->word = &w;
        }
        vector<string> ans;
        for (int i = 0; i < (int)board.size(); ++i)
            for (int j = 0; j < (int)board[0].size(); ++j)
                dfs(board, i, j, root, ans);
        return ans;
    }
};
