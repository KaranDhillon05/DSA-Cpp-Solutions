/*
 * Day: 375 | Date: 2025-02-09
 * Q375: Stickers to Spell Word
 * Difficulty: Hard
 * Pattern: Bitmask DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        unordered_map<string,int> memo;
        function<int(string)> dfs=[&](string t){
            if (t.empty()) return 0;
            if (memo.count(t)) return memo[t];
            vector<int> cnt(26);
            for (char c:t) ++cnt[c-'a'];
            int ans=INT_MAX;
            for (auto& st:stickers){
                if (count(st.begin(), st.end(), t[0])==0) continue;
                vector<int> sc(26);
                for (char c:st) ++sc[c-'a'];
                string rem;
                for (int i=0;i<26;++i)
                    for (int k=max(0,cnt[i]-sc[i]); k; --k) rem.push_back('a'+i);
                int sub=dfs(rem);
                if (sub!=INT_MAX) ans=min(ans,1+sub);
            }
            return memo[t]=ans;
        };
        int res=dfs(target);
        return res==INT_MAX?-1:res;
    }
};
