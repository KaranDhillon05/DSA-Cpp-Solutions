/*
 * Day: 409 | Date: 2025-03-15
 * Q409: Sudoku Solver
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(const vector<vector<char>>& board, int r, int c, char d) {
        for (int i = 0; i < 9; ++i)
            if (board[r][i] == d || board[i][c] == d) return false;
        int br = (r / 3) * 3, bc = (c / 3) * 3;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[br + i][bc + j] == d) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r)
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') continue;
                for (char d = '1'; d <= '9'; ++d) {
                    if (!valid(board, r, c, d)) continue;
                    board[r][c] = d;
                    if (dfs(board)) return true;
                    board[r][c] = '.';
                }
                return false;
            }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) { dfs(board); }
};
