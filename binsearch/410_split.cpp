#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// find if we can partition into k segments with max sum = sum
    bool solve(vector<int>&nums, int sum, int k){
        int ktemp = 1;
        int curSum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(curSum + nums[i] <= sum){
                curSum += nums[i];
            }else{
                curSum = nums[i];
                ktemp++;
                if(ktemp > k)
                    return false;
            }
        }
        return ktemp <= k;
        
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(solve(nums, mid, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};