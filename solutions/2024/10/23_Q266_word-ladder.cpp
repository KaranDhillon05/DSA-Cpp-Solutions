/*
 * Day: 266 | Date: 2024-10-23
 * Q266: Word Ladder
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);
        while (!q.empty()) {
            auto [word, len] = q.front(); q.pop();
            if (word == endWord) return len;
            for (int i = 0; i < (int)word.size(); ++i) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (dict.count(word)) {
                        dict.erase(word);
                        q.push({word, len + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};
