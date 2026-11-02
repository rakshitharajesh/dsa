#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int unlocks = 0;
        int swaps = 0;
        // number of unlocks
        // for each value in the array -> swaps go from i to the expected location
        // so we check from [i.. final_index] or [final_index...i]
        for(int i = 0 ; i < n ; i++){
            int target = nums[i] - 1;
            int lo = min(i, target);
            int hi = max(i, target);
            if(lo == hi)continue; // case where i == target > already sorted
            for(int j = lo ; j <= hi ; j++){
                if(locked[j] == 1){
                    locked[j] = 0;
                    unlocks++;
                }
            }
        }
        if(unlocks > k)
            return -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(nums[j] < nums[i]){
                    swaps++;
                }
            }
        }
        return swaps + unlocks;
    }
};