/*
 * Day: 372 | Date: 2025-02-06
 * Q372: Partition to K Equal Sum Subsets
 * Difficulty: Medium
 * Pattern: Bitmask DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum%k) return false;
        int target=sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> buckets(k);
        function<bool(int)> dfs=[&](int i){
            if (i==nums.size()) return true;
            for (int b=0;b<k;++b){
                if (b&&buckets[b]==buckets[b-1]) continue;
                if (buckets[b]+nums[i]<=target){
                    buckets[b]+=nums[i];
                    if (dfs(i+1)) return true;
                    buckets[b]-=nums[i];
                }
            }
            return false;
        };
        return dfs(0);
    }
};
