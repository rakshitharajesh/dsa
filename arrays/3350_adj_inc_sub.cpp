#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums){
        int n = nums.size();
        int prev = 0;
        int curr = 1;
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i - 1])
                curr++;
            else{
                prev = curr;
                curr = 1;
            }
            ans = max(ans, max(curr / 2, min(curr, prev)));
        }
        return ans;
    }
    int maxIncreasingSubarrays_(vector<int>& nums) {
        int n = nums.size();
        vector<int>inc(n, 1);
        int ans = 0;
        // inc will store max length of a increasing subarray that starts at i
        for(int i = n - 2 ; i >=0 ; i--){
            if(nums[i] < nums[i + 1])
                inc[i] += inc[i + 1];
        }
        for(int a = 0 ; a < n ; a++){
            // the second subarray starts at second index
            int second = min(n - 1, inc[a] + a);
            // case 1 - consider splitting the max subarray starting at i 
            // case 2 - take the minimum of current max, and max starting at second
            int curr = max(inc[a] / 2, min(inc[a], inc[second]));
            ans = max(curr, ans);
        }
        return ans;
    }
};