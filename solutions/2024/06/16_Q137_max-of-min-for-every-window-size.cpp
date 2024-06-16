/*
 * Day: 137 | Date: 2024-06-16
 * Q137: Max of Min for Every Window Size
 * Difficulty: Hard
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            int len = left[i] + right[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; --i) ans[i] = max(ans[i], ans[i + 1]);
        ans.erase(ans.begin());
        return ans;
    }
};
