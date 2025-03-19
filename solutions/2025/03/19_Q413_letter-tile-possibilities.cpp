/*
 * Day: 413 | Date: 2025-03-19
 * Q413: Letter Tile Possibilities
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(string& tiles, vector<bool>& used, string& path, unordered_set<string>& seen) {
        if (!path.empty()) seen.insert(path);
        for (int i = 0; i < (int)tiles.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(tiles[i]);
            dfs(tiles, used, path, seen);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        unordered_set<string> seen;
        string path;
        dfs(tiles, used, path, seen);
        return (int)seen.size();
    }
};
