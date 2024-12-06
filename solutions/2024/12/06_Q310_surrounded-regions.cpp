/*
 * Day: 310 | Date: 2024-12-06
 * Q310: Surrounded Regions
 * Difficulty: Medium
 * Pattern: BFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        function<void(int,int)> dfs=[&](int r,int c){
            if(r<0||c<0||r>=m||c>=n||board[r][c]!='O') return;
            board[r][c]='#'; dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1);
        };
        for (int i=0;i<m;++i){ dfs(i,0); dfs(i,n-1); }
        for (int j=0;j<n;++j){ dfs(0,j); dfs(m-1,j); }
        for (int i=0;i<m;++i) for(int j=0;j<n;++j){
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='#') board[i][j]='O';
        }
    }
};
