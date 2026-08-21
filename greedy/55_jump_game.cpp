#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[n - 1] = true;
        // return solve(nums, dp, 0);
        int maxReachable = 0;
        for(int i = 0 ; i < n ; i++){
            if(i > maxReachable)
                return false;
            maxReachable = max(maxReachable, nums[i] + i);
        }
        return true;

    }
    int solve(vector<int>& nums, vector<int>& dp, int i){
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        for(int step = 1 ; step <= nums[i] ; step++){
            if(solve(nums, dp, i + step))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }
};