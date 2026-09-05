#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] <= nums[high]){
                // pivot is to the left - right half is sorted
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else{
                // left half is sorted and the
                // pivot is on the right half
                if(target < nums[mid] && target >= nums[low]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};