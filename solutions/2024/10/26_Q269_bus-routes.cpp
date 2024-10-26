/*
 * Day: 269 | Date: 2024-10-26
 * Q269: Bus Routes
 * Difficulty: Hard
 * Pattern: BFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int dest) {
        if (source == dest) return 0;
        unordered_map<int, vector<int>> stopToBus;
        for (int i = 0; i < (int)routes.size(); ++i)
            for (int s : routes[i]) stopToBus[s].push_back(i);
        queue<pair<int,int>> q;
        q.push({source, 0});
        unordered_set<int> seenBus, seenStop = {source};
        while (!q.empty()) {
            auto [stop, buses] = q.front(); q.pop();
            for (int b : stopToBus[stop]) {
                if (seenBus.count(b)) continue;
                seenBus.insert(b);
                for (int nxt : routes[b]) {
                    if (nxt == dest) return buses + 1;
                    if (!seenStop.count(nxt)) { seenStop.insert(nxt); q.push({nxt, buses + 1}); }
                }
            }
        }
        return -1;
    }
};
