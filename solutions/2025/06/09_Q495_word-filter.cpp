/*
 * Day: 495 | Date: 2025-06-09
 * Q495: Word Filter
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class WordFilter {
    unordered_map<string, int> idx;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < (int)words.size(); ++i) {
            string w = words[i];
            for (int pre = 0; pre <= (int)w.size(); ++pre)
                for (int suf = 0; suf <= (int)w.size(); ++suf)
                    idx[w.substr(0, pre) + "#" + w.substr(w.size() - suf)] = i;
        }
    }
    int f(string pref, string suff) {
        string key = pref + "#" + suff;
        return idx.count(key) ? idx[key] : -1;
    }
};
