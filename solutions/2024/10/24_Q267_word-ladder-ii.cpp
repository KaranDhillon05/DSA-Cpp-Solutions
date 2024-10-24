/*
 * Day: 267 | Date: 2024-10-24
 * Q267: Word Ladder II
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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        unordered_map<string, vector<string>> parent;
        unordered_set<string> level = {beginWord};
        dict.erase(beginWord);
        bool found = false;
        while (!level.empty() && !found) {
            for (auto& w : level) dict.erase(w);
            unordered_set<string> nextLevel;
            for (auto& word : level) {
                string orig = word;
                for (int i = 0; i < (int)word.size(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (word == endWord) found = true;
                        if (dict.count(word) || word == endWord) {
                            parent[word].push_back(orig);
                            nextLevel.insert(word);
                        }
                    }
                    word = orig;
                }
            }
            level = move(nextLevel);
        }
        vector<vector<string>> res;
        if (!found) return res;
        vector<string> path = {endWord};
        function<void(const string&)> dfs = [&](const string& w) {
            if (w == beginWord) { res.push_back(path); reverse(res.back().begin(), res.back().end()); return; }
            for (auto& p : parent[w]) { path.push_back(p); dfs(p); path.pop_back(); }
        };
        dfs(endWord);
        return res;
    }
};
