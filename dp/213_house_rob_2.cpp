#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int>dp(n, -1);
        // rob starting from the first house - cannot consider the last house
        int first = rob(0, nums, dp, n - 1);
        fill(dp.begin(), dp.end(), -1);
        // rob starting from the second house - consider the last house as well
        int last = rob(1, nums, dp, n);
        return max(first, last);
    }
    int rob(int index, vector<int>&nums, vector<int>&dp, int n){
        if(index >= n)
            return 0;
        if(dp[index] != -1)
            return dp[index];
            
        int skip = rob(index + 1, nums, dp, n);
        int take = nums[index] + rob(index + 2, nums, dp, n);
        return dp[index] = max(skip, take);
    }
};