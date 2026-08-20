#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // find the maximum subarray
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxCurr = nums[0];
        int maxSub = maxCurr;
        for(int i = 1 ; i < n ; i++){
            maxCurr = max(maxCurr + nums[i], nums[i]);
            maxSub = max(maxSub, maxCurr);
        }
        // find the minimum subarray
        int minCurr = nums[0];
        int minSub = minCurr;
        for(int i = 1 ; i < n ; i++){
            minCurr = min(minCurr + nums[i], nums[i]);
            minSub = min(minSub, minCurr);
        }
        // in case all the elements in the array are negative
        if(maxSub < 0)
            return maxSub;
        return max(sum - minSub, maxSub);
    }
};