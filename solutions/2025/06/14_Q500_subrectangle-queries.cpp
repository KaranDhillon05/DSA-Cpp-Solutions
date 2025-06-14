/*
 * Day: 500 | Date: 2025-06-14
 * Q500: Subrectangle Queries
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class SubrectangleQueries {
    vector<vector<int>> rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rect(rectangle) {}
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int r = row1; r <= row2; ++r)
            for (int c = col1; c <= col2; ++c)
                rect[r][c] = newValue;
    }
    int getValue(int row, int col) { return rect[row][col]; }
};
