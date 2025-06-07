/*
 * Day: 493 | Date: 2025-06-07
 * Q493: Snapshot Array
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
    vector<vector<pair<int,int>>> snaps;
    int snap = 0;
public:
    SnapshotArray(int length) : snaps(length) {}
    void set(int index, int val) { snaps[index].push_back({snap, val}); }
    int snapShot() { return snap++; }
    int get(int index, int snap_id) {
        auto& hist = snaps[index];
        int lo = 0, hi = (int)hist.size() - 1, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (hist[mid].first <= snap_id) { ans = hist[mid].second; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};
