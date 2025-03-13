/*
 * Day: 407 | Date: 2025-03-13
 * Q407: N-Queens
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(const vector<string>& board, int row, int col) {
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q' || board[row][i] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < (int)board.size(); --i, ++j)
            if (board[i][j] == 'Q') return false;
        return true;
    }
    void dfs(int row, int n, vector<string>& board, vector<vector<string>>& res) {
        if (row == n) { res.push_back(board); return; }
        for (int col = 0; col < n; ++col) {
            if (!valid(board, row, col)) continue;
            board[row][col] = 'Q';
            dfs(row + 1, n, board, res);
            board[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(0, n, board, res);
        return res;
    }
};
