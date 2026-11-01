#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            minVal = min(minVal, nums[i]);
            sum += nums[i];
        }
        // once we find the minimum value -> we need to add all the differnces
        // between each element in the array and the minvalue 
        // that gives the number of moves
        return sum - minVal * n;
    }
};