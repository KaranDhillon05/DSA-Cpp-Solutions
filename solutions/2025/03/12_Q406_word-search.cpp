/*
 * Day: 406 | Date: 2025-03-12
 * Q406: Word Search
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if (idx == (int)word.size()) return true;
        if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size()) return false;
        if (board[i][j] != word[idx]) return false;
        char tmp = board[i][j];
        board[i][j] = '#';
        bool ok = dfs(board, word, i + 1, j, idx + 1) || dfs(board, word, i - 1, j, idx + 1)
               || dfs(board, word, i, j + 1, idx + 1) || dfs(board, word, i, j - 1, idx + 1);
        board[i][j] = tmp;
        return ok;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < (int)board.size(); ++i)
            for (int j = 0; j < (int)board[0].size(); ++j)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};
