/*
 * Day: 125 | Date: 2024-06-04
 * Q125: Maximal Rectangle
 * Difficulty: Hard
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), best = 0;
        vector<int> h(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;
            vector<int> copy = h; copy.push_back(0);
            stack<int> st;
            for (int k = 0; k < (int)copy.size(); ++k) {
                while (!st.empty() && copy[st.top()] > copy[k]) {
                    int ht = copy[st.top()]; st.pop();
                    int w = st.empty() ? k : k - st.top() - 1;
                    best = max(best, ht * w);
                }
                st.push(k);
            }
        }
        return best;
    }
};
