#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int subsetXORSum(vector<int>& nums) {
        this -> n = nums.size();
        return backtrack(nums,0, 0);
    }
    int backtrack(vector<int>& nums, int index, int curr){
        if(index == n)
            return curr;
        
        int left = backtrack(nums, index + 1, curr ^ nums[index]);
        int right = backtrack(nums, index + 1, curr);
        return left + right;
    }
};