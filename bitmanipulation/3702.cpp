#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_ = 0;
        int zero = 0;
        for(int num : nums){
            xor_ ^= num;
            if(num == 0)
                zero++;
        }
        return (xor_ != 0 ? nums.size() : nums.size() - (zero == nums.size() ? nums.size() : 1));
    }
};