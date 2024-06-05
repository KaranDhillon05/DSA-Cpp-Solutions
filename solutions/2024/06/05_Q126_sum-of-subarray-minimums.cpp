/*
 * Day: 126 | Date: 2024-06-05
 * Q126: Sum of Subarray Minimums
 * Difficulty: Medium
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) ans = (ans + 1LL * arr[i] * left[i] * right[i]) % MOD;
        return (int)ans;
    }
};
