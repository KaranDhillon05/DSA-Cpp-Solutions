/*
 * Day: 118 | Date: 2024-05-28
 * Q118: Next Greater Node in Linked List
 * Difficulty: Medium
 * Pattern: Monotonic Stack
 * Section: 3.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        for (ListNode* cur = head; cur; cur = cur->next) vals.push_back(cur->val);
        vector<int> res(vals.size(), 0);
        stack<int> st;
        for (int i = 0; i < (int)vals.size(); ++i) {
            while (!st.empty() && vals[st.top()] < vals[i]) {
                res[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
