/*
 * Day: 355 | Date: 2025-01-20
 * Q355: Zuma Game
 * Difficulty: Hard
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, unordered_map<string,int>> memo;
        sort(hand.begin(), hand.end());
        function<int(string,string)> dfs=[&](string b, string h){
            if (b.empty()) return 0;
            string key=b+"#"+h;
            if (memo.count(b)&&memo[b].count(h)) return memo[b][h];
            int ans=INT_MAX;
            for (int i=0;i<(int)b.size();++i){
                if (i&&b[i]==b[i-1]) continue;
                for (int j=0;j<(int)h.size();++j){
                    if (h[j]!=b[i]) continue;
                    string nh=h; nh.erase(j,1);
                    string nb=b; nb.insert(i,1,h[j]);
                    string cleaned;
                    for (int k=0;k<(int)nb.size();){
                        int l=k;
                        while (l<(int)nb.size()&&nb[l]==nb[k]) ++l;
                        if (l-k<3) cleaned+=nb.substr(k,l-k);
                        k=l;
                    }
                    int sub=dfs(cleaned,nh);
                    if (sub!=INT_MAX) ans=min(ans,1+sub);
                }
            }
            return memo[b][h]=ans;
        };
        int res=dfs(board,hand);
        return res==INT_MAX?-1:res;
    }
};
