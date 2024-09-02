/*
 * Day: 215 | Date: 2024-09-02
 * Q215: Range Minimum Query
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class RMQ {
    vector<int> seg;
    int n;
    void build(const vector<int>& a, int idx, int l, int r) {
        if (l == r) { seg[idx] = a[l]; return; }
        int m = l + (r - l) / 2;
        build(a, idx * 2, l, m);
        build(a, idx * 2 + 1, m + 1, r);
        seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
    }
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) return seg[idx];
        int m = l + (r - l) / 2;
        return min(query(idx * 2, l, m, ql, qr), query(idx * 2 + 1, m + 1, r, ql, qr));
    }
public:
    RMQ(const vector<int>& a) : n(a.size()), seg(4 * n) { build(a, 1, 0, n - 1); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
