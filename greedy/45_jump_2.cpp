#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        //vector<int>dp(n, -1);
        //return j(nums, dp, 0);
        int steps = 0;
        int farthest = 0;
        int currend = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            // farthest we can go
            farthest = max(farthest, i + nums[i]);
            if(currend == i){
                // current end is the farthest we can go 
                currend = farthest;
                steps++;
            }
        }
        return steps;
    }
    int j(vector<int>&nums, vector<int>&dp, int index){
        if(index >= nums.size() - 1)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int minSteps = INT_MAX;
        for(int i = 1 ; i <= nums[index] ; i++){
            int sub = j(nums, dp, index + i);
            if(sub != INT_MAX)
                minSteps = min(minSteps, 1 + sub);
        }
        return dp[index] = minSteps;
    }
};