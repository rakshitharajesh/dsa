#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }else if(nums[mid] <= nums[high]){
                // the right half is sorted
                // the mid value is lower than the highest
                // this means the pivot is indefinitely in the left
                // side
                // if we rotate an array, the highest value is just before the pivot
                // if the mid < high value -> the pivot is NOT in between
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else{
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }  
        }
        return false;
    }
};