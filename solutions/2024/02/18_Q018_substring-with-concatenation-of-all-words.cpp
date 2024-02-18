/*
 * Day: 18 | Date: 2024-02-18
 * Q018: Substring with Concatenation of All Words
 * Difficulty: Hard
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;
        int wordLen = (int)words[0].size();
        int totalWords = (int)words.size();
        int totalLen = wordLen * totalWords;
        if ((int)s.size() < totalLen) return res;

        unordered_map<string, int> freq;
        for (const string& w : words) ++freq[w];

        for (int offset = 0; offset < wordLen; ++offset) {
            unordered_map<string, int> seen;
            int left = offset, count = 0;
            for (int right = offset; right + wordLen <= (int)s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if (!freq.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }
                ++seen[word];
                ++count;
                while (seen[word] > freq[word]) {
                    string leftWord = s.substr(left, wordLen);
                    --seen[leftWord];
                    --count;
                    left += wordLen;
                }
                if (count == totalWords) res.push_back(left);
            }
        }
        return res;
    }
};
