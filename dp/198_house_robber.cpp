#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return r(nums, dp, 0);
    }
    int r(vector<int>&nums, vector<int>&dp, int index){
        if(index >= nums.size())
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int take_this = nums[index] + r(nums, dp, index + 2);
        int no_take = r(nums, dp, index + 1);
        return dp[index] = max(take_this, no_take);
    }
};
