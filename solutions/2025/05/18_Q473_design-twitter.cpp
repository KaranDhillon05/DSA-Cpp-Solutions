/*
 * Day: 473 | Date: 2025-05-18
 * Q473: Design Twitter
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Twitter {
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follow;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,pair<int,int>>> pq;
        auto pushLatest = [&](int uid) {
            if (!tweets[uid].empty()) {
                int idx = (int)tweets[uid].size() - 1;
                pq.push({tweets[uid][idx].first, {uid, idx}});
            }
        };
        pushLatest(userId);
        for (int f : follow[userId]) pushLatest(f);
        vector<int> res;
        while (!pq.empty() && (int)res.size() < 10) {
            auto top = pq.top(); pq.pop();
            int uid = top.second.first, idx = top.second.second;
            res.push_back(tweets[uid][idx].second);
            if (idx > 0) pq.push({tweets[uid][idx - 1].first, {uid, idx - 1}});
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) follow[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        follow[followerId].erase(followeeId);
    }
};
